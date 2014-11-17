/* ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <info@gerhard-bertelsmann.de> wrote this file. As long as you retain this
 * notice you can do whatever you want with this stuff. If we meet some day,
 * and you think this stuff is worth it, you can buy me a beer in return
 * Gerhard Bertelsmann
 * ----------------------------------------------------------------------------
 */

#include "main.h"
#include "usart.h"
#include "prototypes.h"

#pragma config XINST=OFF

const char s1[] = "circular buffer is working!\r\n";
const char s2[] = "USART is working!\r\n";

extern const char BRGCON_64MHZ[][3];

volatile unsigned char timer_ticks=0;
struct serial_buffer tx_fifo, rx_fifo;
volatile struct CAN_MSG TX_CANMessage;
volatile struct CAN_MSG RX_CANMessage;


void init_ports(void) {
    ANCON0 = 0;			// analog off
    ANCON1 = 0;			// analog off
    ADCON0 = 0;			// disable ADC
    ADCON1 = 0;			// disable ADC
    ADCON2 = 0;			// disable ADC
    CM1CON = 0;			// disable comperator
    CM2CON = 0;			// disable comperator
    LED_TRIS = 0;
    TRISBbits.TRISB2 = 0;	// make the CAN TX pin a digital output
    TRISBbits.TRISB3 = 1;	// make the CAN RX pin a digital input
}

void main(void) {
    unsigned char do_print=0;
    unsigned char ret=0;
    unsigned char TaskB='A';
    char c;

    init_ports();
    init_timer();
    init_usart();
    init_can(BRGCON_64MHZ[5][0],BRGCON_64MHZ[5][1],BRGCON_64MHZ[5][2]);
    print_sfr_n("BRGCON:",&(BRGCON1),3);

    /* empty circular buffers */
    tx_fifo.head=0;
    tx_fifo.tail=0;
    rx_fifo.head=0;
    rx_fifo.tail=0;
    
    //infinite loop
    while(1) {
	if ((do_print == 0) && (timer_ticks == 10)) {
	    do_print = 1;
	}
	if ((do_print == 1) && (timer_ticks == 100)) {
	    do_print = 0;
//	    puts_rom(s2);
	    ret=puts_rom_fifo(s1,&tx_fifo);
//            print_sfr_n("PIR5:",&(PIR5),1);
//            print_sfr_n("RXB0CON:",&(RXB0CON),16);
//            print_sfr_n("RXB1CON:",&(RXB1CON),16);
	}
        ret=can_readmsg();
        if (ret&1) {
            print_sfr_n("PIR5:",&(PIR5),1);
            print_sfr_n("RXB0CON:",&(RXB0CON),16);
        }
        if (ret&2) {
            print_sfr_n("PIR5:",&(PIR5),1);
            print_sfr_n("RXB1CON:",&(RXB1CON),16);
        }

        //ret=can_writemsg();
	ret=fifo_putchar(&tx_fifo);
        if (c=fifo_getchar(&rx_fifo)) {
	    if (c=='\r') {
	        copy_char_fifo(&rx_fifo,&tx_fifo);
		putchar_fifo(0x0a,&tx_fifo);
                can_send_test_frame();
                print_sfr_n("TXB0CON:",&(TXB0CON),16);
                print_sfr_n("TXB1CON:",&(TXB1CON),16);
                print_sfr_n("TXB2CON:",&(TXB2CON),16);
	    }
	}
    }
}

void isr() __interrupt 1 {
    if (INTCONbits.TMR0IE && INTCONbits.TMR0IF) {
        // overflow every 4.096ms
        timer_ticks++;
        if (timer_ticks==20) {  // 80 ms
            LED = 0;		// LED OFF
        }
        if (timer_ticks==40) {  // 80 ms
            LED = 1;		// LED ON
        }
        if (timer_ticks==60) {  // 80 ms
            LED = 0;		// LED OFF
        }
        if (timer_ticks==250) { // 720 ms
            LED = 1;		// LED OFF
            timer_ticks=0;
        }
        INTCONbits.TMR0IF = 0;
    }
}
