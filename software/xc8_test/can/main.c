/********************************************************************
 File: main.c

 Description:
 This file contains the main logic of the USBtin project.
 USBtin is a simple USB to CAN interface. It uses the USB class CDC
 to connect to the host. Configuration and bus communication is
 handled over this CDC virtual comport.

 Authors and Copyright:
 (c) 2012, Thomas Fischl <tfischl@gmx.de>

 Device: PIC18F14K50
 Compiler: HI-TECH C PRO for the PIC18 MCU Family (Lite)  V9.65

 License:
 This file is open source. You can use it or parts of it in own
 open source projects. For closed or commercial projects you have to
 contact the authors listed above to get the permission for using
 this source code.

 Change History:
  Rev   Date        Description
  1.0   2011-12-18  Initial release
  1.1   2012-03-09  Minor fixes, code cleanup
  1.2   2013-01-11  Added filter function (command 'm' and 'M')
                    Added write register function (command 'W')

 ********************************************************************/

#include <htc.h>
#include <stdio.h>
#include <string.h>
#include "usb_cdc.h"
#include "clock.h"
#include "mcp2515.h"

#define hardware_setLED(value) LATBbits.LATB5 = value
#define hardware_getBLSwitch() !PORTAbits.RA3
#define hardware_getMCP2515Int() !PORTCbits.RC2

#define LINE_MAXLEN 100
#define BELL 7
#define CR 13
#define LR 10

#define STATE_CONFIG 0
#define STATE_OPEN 1
#define STATE_LISTEN 2

#define VERSION_HARDWARE 1
#define VERSION_FIRMWARE_MAJOR 1
#define VERSION_FIRMWARE_MINOR 2


volatile unsigned char state = STATE_CONFIG;
unsigned char timestamping = 0;

/**
 * Parse hex value of given string
 *
 * @param line Input string
 * @param len Count of characters to interpret
 * @param value Pointer to variable for the resulting decoded value
 * @return 0 on error, 1 on success
 */
unsigned char parseHex(char * line, unsigned char len, unsigned long * value) {
    *value = 0;
    while (len--) {
        if (*line == 0) return 0;
        *value <<= 4;
        if ((*line >= '0') && (*line <= '9')) {
           *value += *line - '0';
        } else if ((*line >= 'A') && (*line <= 'F')) {
           *value += *line - 'A' + 10;
        } else if ((*line >= 'a') && (*line <= 'f')) {
           *value += *line - 'a' + 10;
        } else return 0;
        line++;
    }
    return 1;
}

/**
 * Send given value as hexadecimal string
 *
 * @param value Value to send as hex over the UART
 * @param len Count of characters to produce
 */
void sendHex(unsigned long value, unsigned char len) {

    char s[20];
    s[len] = 0;

    while (len--) {

        unsigned char hex = value & 0x0f;
        if (hex > 9) hex = hex - 10 + 'A';
        else hex = hex + '0';
        s[len] = hex;

        value = value >> 4;
    }

    usb_putstr(s);

}

/**
 * Send given byte value as hexadecimal string
 *
 * @param value Byte value to send over UART
 */
void sendByteHex(unsigned char value) {

    sendHex(value, 2);
}

/**
 * Interprets given line and transmit can message
 *
 * @param line Line string which contains the transmit command
 */
unsigned char transmitStd(char *line) {
    canmsg_t canmsg;
    unsigned long temp;
    unsigned char idlen;

    canmsg.flags.rtr = ((line[0] == 'r') || (line[0] == 'R'));

    // upper case -> extended identifier
    if (line[0] < 'Z') {
        canmsg.flags.extended = 1;
        idlen = 8;
    } else {
        canmsg.flags.extended = 0;
        idlen = 3;
    }

    if (!parseHex(&line[1], idlen, &temp)) return 0;
    canmsg.id = temp;

    if (!parseHex(&line[1 + idlen], 1, &temp)) return 0;
    canmsg.length = temp;

    if (!canmsg.flags.rtr) {
        unsigned char i;
        for (i = 0; i < canmsg.length; i++) {
            if (!parseHex(&line[idlen + 2 + i*2], 2, &temp)) return 0;
            canmsg.data[i] = temp;
        }
    }

    return mcp2515_send_message(&canmsg);
}

/**
 * Parse given command line
 *
 * @param line Line string to parse
 */
void parseLine(char * line) {

    unsigned char result = BELL;

    switch (line[0]) {
        case 'S': // Setup with standard CAN bitrates
            if (state == STATE_CONFIG)
            {
                switch (line[1]) {
                    case '0': mcp2515_set_bittiming(MCP2515_TIMINGS_10K);  result = CR; break;
                    case '1': mcp2515_set_bittiming(MCP2515_TIMINGS_20K);  result = CR; break;
                    case '2': mcp2515_set_bittiming(MCP2515_TIMINGS_50K);  result = CR; break;
                    case '3': mcp2515_set_bittiming(MCP2515_TIMINGS_100K); result = CR; break;
                    case '4': mcp2515_set_bittiming(MCP2515_TIMINGS_125K); result = CR; break;
                    case '5': mcp2515_set_bittiming(MCP2515_TIMINGS_250K); result = CR; break;
                    case '6': mcp2515_set_bittiming(MCP2515_TIMINGS_500K); result = CR; break;
                    case '7': mcp2515_set_bittiming(MCP2515_TIMINGS_800K); result = CR; break;
                    case '8': mcp2515_set_bittiming(MCP2515_TIMINGS_1M);   result = CR; break;
                }

            }
            break;
        case 's': // Setup with user defined timing settings for CNF1/CNF2/CNF3
            if (state == STATE_CONFIG)
            {
                unsigned long cnf1, cnf2, cnf3;
                if (parseHex(&line[1], 2, &cnf1) && parseHex(&line[3], 2, &cnf2) && parseHex(&line[5], 2, &cnf3)) {
                    mcp2515_set_bittiming(cnf1, cnf2, cnf3);
                    result = CR;
                }
            } 
            break;
        case 'G': // Read given MCP2515 register
            {
                unsigned long address;
                if (parseHex(&line[1], 2, &address)) {
                    unsigned char value = mcp2515_read_register(address);
		    sendByteHex(value);
                    result = CR;
                }
            }
            break;
        case 'W': // Write given MCP2515 register
            {
                unsigned long address, data;
                if (parseHex(&line[1], 2, &address) && parseHex(&line[3], 2, &data)) {
                    mcp2515_write_register(address, data);
                    result = CR;
                }

            }
            break;
        case 'V': // Get versions
            {
                usb_putch('V');
                sendByteHex(VERSION_HARDWARE);
                sendByteHex(VERSION_FIRMWARE_MAJOR);
                result = CR;
            }
            break;
        case 'v': // Get firmware version
            {
                usb_putch('v');
                sendByteHex(VERSION_FIRMWARE_MAJOR);
                sendByteHex(VERSION_FIRMWARE_MINOR);
                result = CR;
            }
            break;
        case 'N': // Get serial number
            {
                usb_putch('N');
                sendHex(0xFFFF, 4);
                result = CR;
            }
            break;     
        case 'O': // Open CAN channel
            if (state == STATE_CONFIG)
            {
		mcp2515_bit_modify(MCP2515_REG_CANCTRL, 0xE0, 0x00); // set normal operating mode

                clock_reset();

                state = STATE_OPEN;
                result = CR;
            }
            break; 
        case 'l': // Loop-back mode
            if (state == STATE_CONFIG)
            {
		mcp2515_bit_modify(MCP2515_REG_CANCTRL, 0xE0, 0x40); // set loop-back

                state = STATE_OPEN;
                result = CR;
            }
            break; 
        case 'L': // Open CAN channel in listen-only mode
            if (state == STATE_CONFIG)
            {
		mcp2515_bit_modify(MCP2515_REG_CANCTRL, 0xE0, 0x60); // set listen-only mode

                state = STATE_LISTEN;
                result = CR;
            }
            break; 
        case 'C': // Close CAN channel
            if (state != STATE_CONFIG)
            {
		mcp2515_bit_modify(MCP2515_REG_CANCTRL, 0xE0, 0x80); // set configuration mode

                state = STATE_CONFIG;
                result = CR;
            }
            break; 
        case 'r': // Transmit standard RTR (11 bit) frame
        case 'R': // Transmit extended RTR (29 bit) frame
        case 't': // Transmit standard (11 bit) frame
        case 'T': // Transmit extended (29 bit) frame
            if (state == STATE_OPEN)
            {
                if (transmitStd(line)) {
                    if (line[0] < 'Z') usb_putch('Z');
                    else usb_putch('z');
                    result = CR;
                }

            }
            break;        
        case 'F': // Read status flags
            {
                unsigned char flags = mcp2515_read_register(MCP2515_REG_EFLG);
                unsigned char status = 0;

                if (flags & 0x01) status |= 0x04; // error warning
                if (flags & 0xC0) status |= 0x08; // data overrun
                if (flags & 0x18) status |= 0x20; // passive error
                if (flags & 0x20) status |= 0x80; // bus error

                usb_putch('F');
                sendByteHex(status);
                result = CR;
            }
            break;
         case 'Z': // Set time stamping
            {
                unsigned long stamping;
                if (parseHex(&line[1], 1, &stamping)) {
                    timestamping = (stamping != 0);
                    result = CR;
                }
            }
            break;
         case 'm': // Set accpetance filter mask
            if (state == STATE_CONFIG)
            {
                unsigned long am0, am1, am2, am3;
                if (parseHex(&line[1], 2, &am0) && parseHex(&line[3], 2, &am1) && parseHex(&line[5], 2, &am2) && parseHex(&line[7], 2, &am3)) {
                    mcp2515_set_SJA1000_filter_mask(am0, am1, am2, am3);
                    result = CR;
                }
            } 
            break;
         case 'M': // Set accpetance filter code
            if (state == STATE_CONFIG)
            {
                unsigned long ac0, ac1, ac2, ac3;
                if (parseHex(&line[1], 2, &ac0) && parseHex(&line[3], 2, &ac1) && parseHex(&line[5], 2, &ac2) && parseHex(&line[7], 2, &ac3)) {
                    mcp2515_set_SJA1000_filter_code(ac0, ac1, ac2, ac3);
                    result = CR;
                }
            } 
            break;
         
    }

   usb_putch(result);
}

/**
 * Main function. Entry point for USBtin application.
 * Handles initialization and the the main processing loop.
 */
void main(void) {

    // initialize MCP2515 (reset and clock setup)
    mcp2515_init();   
   
    // switch (back) to external clock (if fail-safe-monitor switched to internal)
    OSCCON = 0x30;

    // disable all analog pin functions, set led pin to output
    ANSEL = 0;
    ANSELH = 0;
    TRISBbits.TRISB5 = 0;
    hardware_setLED(0);

    // initialize modules
    clock_init();
    usb_init();
    
    char line[LINE_MAXLEN];
    unsigned char linepos = 0;
    unsigned short lastclock = 0;

    while (1) {

        // do module processing
        usb_process();
        clock_process();

        // receive characters from UART and collect the data until end of line is indicated
        if (usb_chReceived()) {
            unsigned char ch = usb_getch();

            if (ch == CR) {
                line[linepos] = 0;
                parseLine(line);
                linepos = 0;
            } else if (ch != LR) {
                line[linepos] = ch;
                if (linepos < LINE_MAXLEN - 1) linepos++;
            }

        }
            
	// handles interrupt requests of MCP2515 controller: receive message and print it out.
        if ((state != STATE_CONFIG) && (hardware_getMCP2515Int())) {

            canmsg_t canmsg;
            mcp2515_receive_message(&canmsg);
            char type;
            unsigned char idlen;
            unsigned short timestamp = clock_getMS();

            if (canmsg.flags.rtr) type = 'r';
            else type = 't';

            if (canmsg.flags.extended) {
                type -= 'a' - 'A';
                idlen = 8;
            } else {
                idlen = 3;
            }

            usb_putch(type);
            sendHex(canmsg.id, idlen);

            sendHex(canmsg.length, 1);

            if (!canmsg.flags.rtr) {
                unsigned char i;
                for (i = 0; i < canmsg.length; i++) {
                   sendHex(canmsg.data[i], 2);
                }
            }

            if (timestamping) {
                sendHex(timestamp, 4);
            }

            usb_putch(CR);
        }        

        // led signaling
        hardware_setLED(state != STATE_CONFIG);

        // jump into bootloader, if jumper is closed
        if (hardware_getBLSwitch()) {
            UCON = 0;
            _delay(1000);
            RESET();
        }
    }
}
