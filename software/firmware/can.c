/* ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <info@gerhard-bertelsmann.de> wrote this file. As long as you retain this
 * notice you can do whatever you want with this stuff. If we meet some day,
 * and you think this stuff is worth it, you can buy me a beer in return
 * Gerhard Bertelsmann
 * ----------------------------------------------------------------------------
 */

#include "can.h"

/* TODO: until now we all clear all filters */
void init_can_filter(void) {
     // Initialize Acceptance Filters and Masks to 0x00:
     RXF0SIDH = 0; // SID10 to SID3
     RXF0SIDL = 0; // SID2 to SID0; Standard frame
     RXF1SIDH = 0;
     RXF1SIDL = 0;
     RXF2SIDH = 0;
     RXF2SIDL = 0;
     RXF3SIDH = 0;
     RXF3SIDL = 0;
     RXF4SIDH = 0;
     RXF4SIDL = 0;
     RXF5SIDH = 0;
     RXF5SIDL = 0;
     RXM0SIDH = 0xFF;
     RXM0SIDL = 0xFF;
     RXM1SIDH = 0xFF;
     RXM1SIDL = 0xFF;
}

void init_can(const char brgcon1, unsigned char brgcon2, unsigned char brgcon3) {
    /* enter CAN config mode */
    //CANCONbits.REQOP2 = 1;
    CANCON = 0x80;
    while(!(CANSTATbits.OPMODE == 0x04));
    
    /* using ECAN 0 mode aka legacy mode */
    ECANCONbits.MDSEL = 0b00;

    /* set timing parameters */
    BRGCON1 = brgcon1;
    BRGCON2 = brgcon2;
    BRGCON3 = brgcon3;

    init_can_filter();

    // CANTX will drive VDD when recessive TODO
    // CIOCON = 0x20;

    /* leaving CAN config mode */
    //CANCONbits.REQOP2 = 0;
    CANCON = 0x00;
    // TODO do we need to wait ?
    while(CANSTATbits.OPMODE==0x00);

    // Set Receive Mode for buffers
    RXB0CON = 0x00;
    RXB1CON = 0x00;

}

char can_sendmsg(unsigned long id, char * data, char dlc, char flags) {
    char i;
    char * ptr;
    /* TODO: check if TXB2 does have the highest prio */
    if (TXB2CONbits.TXREQ == 0) {
	// TxBuffer2 is available.. Set WIN bits to point to TXB2
        CANCON &= 0b11110001;
        CANCON |= 0b00000100;
    } else if (TXB1CONbits.TXREQ == 0) {
        // TxBuffer1 is available. Set WIN bits to point to TXB1
        CANCON &= 0b11110001;
        CANCON |= 0b00000110;
    } else if (TXB0CONbits.TXREQ == 0) {
        // TxBuffer0 is available. Set WIN bits to point to TXB0
        CANCON &= 0b11110001;
        CANCON |= 0b00001000;
    } else {
	return -1;
    }
    // Set transmit priority.
    RXB0CON = flags & 0b00000011;

    // Populate Extended identifier information only if it is
    // desired.
    /* if (flags & CAN_TX_XTD_FRAME) {
        can_writeRegs((uint8_t*) & RXB0SIDH, id, TRUE);
    } else {
        can_writeRegs((uint8_t*) & RXB0SIDH, id, FALSE);
    }
    */

    RXB0DLC = dlc;

    // RTR
    if (flags & CAN_TX_RTR_FRAME) {
        RXB0DLC |= 0b01000000;
    }

    // Populate data values.
    ptr = (__sfr *) &(RXB0D0);
    for (i = 0; i < dlc; i++) {
        ptr[ i ] = data[ i ];
    }
    /* remapped TX0 buffer */
    /*
     __asm
     bsf RXB0CON, 3, 0
     __endasm
    */
    RXB0CON |= 0x08;

   /* Restore CAN buffer mapping so that subsequent access to RXB0
    * buffers are to the real RXB0 buffer. */
   CANCON &= 0b11110001;
   return 1;
}

