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
     RXM0SIDH = 0;
     RXM0SIDL = 0;
     RXM1SIDH = 0;
     RXM1SIDL = 0;
}

void init_can(const char brgcon1, unsigned char brgcon2, unsigned char brgcon3) {
    /* enter CAN config mode */
    //CANCONbits.REQOP2 = 1;
    //CANSTATbits.OPMODE = 0x04
    CANCON = 0x80;
    while(!(CANSTATbits.OPMODE == 0x04));

    /* using ECAN 0 mode aka legacy mode */
    ECANCON = 0x00;

    /* set timing parameters */
    BRGCON1 = brgcon1;
    BRGCON2 = brgcon2;
    BRGCON3 = brgcon3;

    init_can_filter();

    // CANTX will drive VDD when recessive TODO
    CIOCON = 0x20;

    /* leaving CAN config mode */
    //CANCONbits.REQOP2 = 0;
    CANCON = 0x00;
    // TODO do we need to wait ?
    while(CANSTATbits.OPMODE == 0 );

    // Set Receive Mode for buffers
    RXB0CON = 0x00;
    RXB1CON = 0x00;
}

char can_readmsg(struct CAN_MSG * can_msg) {
    // clear flags
    char buffer0_flag = 0;
    char i;
    __sfr * ptr;
 
    can_msg->flags = 0;
    if (RXB0CONbits.RXFUL) {
        // buffer0 contains a message.
        CANCON &= 0b11110001;
        buffer0_flag = 1;
        // clear RXB0 receive flag
        PIR5bits.RXB0IF = 0;
	if (COMSTATbits.RXB0OVFL) {
            can_msg->flags |= CAN_RX_OVERFLOW;
        }
        if (RXB0CONbits.RB0DBEN) {
            can_msg->flags |= RXB0CON & 0b00000111;
            can_msg->flags &= 0x01;
        }
    } else if (RXB1CONbits.RXFUL) {
        // RXBuffer1 is full
        CANCON &= 0b11110001;
        CANCON |= 0b00001010;

        buffer0_flag = 0;

        // Clear the received flag.
        PIR5bits.RXB1IF = 0;
        // record and forget any previous overflow
        if (COMSTATbits.RXB0OVFL) {
           can_msg->flags |= CAN_RX_OVERFLOW;
           COMSTATbits.RXB1OVFL = 0;
        }
        can_msg->flags |= RXB1CON & 0b00000111;
        if (can_msg->flags < 0x02) {
            can_msg->flags |= CAN_RX_DBL_BUFFERED;
        }
    } else {
        return -1;
    }
    // get message length
    can_msg->dlc = RXB0DLC & 0x0f;
    // rtr message ?
    if ((RXB0DLC & 0x40)) {
        can_msg->flags |= CAN_RX_RTR_FRAME;
    }
    // extended message ?
    if (RXB0SIDLbits.EXID) {
        can_msg->flags |= CAN_RX_XTD_FRAME;
        // TODO : read extended ID
    } else {
        // TODO : read short ID
    }
    // save data
    ptr = &(RXB0D0);
    for (i = 0; i < can_msg->dlc; i++) {
        can_msg->data[ i ] = ptr[ i ];
    }
    // Restore default RXB0 mapping.
    CANCON &= 0b11110001;

    // Record and Clear any previous invalid message bit flag.
    if (PIR5bits.IRXIF) {
        can_msg->flags |= CAN_RX_INVALID_MSG;
        PIR5bits.IRXIF = 0;
    }
    if (buffer0_flag) {
        RXB0CONbits.RXFUL = 0;
    } else {
        RXB1CONbits.RXFUL = 0;
    }
    return 1;
}

char can_sendmsg(struct CAN_MSG * can_msg) {
    char i;
    char * ptr;
    /* TODO: check if TXB2 does have the highest prio */
    if (TXB0CONbits.TXREQ == 0) {
	// TxBuffer0 is available. Set WIN bits to point to TXB0
        CANCON &= 0b11110001;
        CANCON |= 0b00001000;
    } else if (TXB1CONbits.TXREQ == 0) {
        // TxBuffer1 is available. Set WIN bits to point to TXB1
        CANCON &= 0b11110001;
        CANCON |= 0b00000110;
    } else if (TXB2CONbits.TXREQ == 0) {
        // TxBuffer2 is available. Set WIN bits to point to TXB2
        CANCON &= 0b11110001;
        CANCON |= 0b00000100;
    } else {
	return -1;
    }
    // Set transmit priority.
    RXB0CON = can_msg->flags & 0b00000011;

    // Populate Extended identifier information only if it is
    // desired.
    /* if (can_msg->flags & CAN_TX_XTD_FRAME) {
        can_writeRegs((uint8_t*) & RXB0SIDH, id, TRUE);
    } else {
        can_writeRegs((uint8_t*) & RXB0SIDH, id, FALSE);
    }
    */

    RXB0DLC = can_msg->dlc;

    // RTR
    if (can_msg->flags & CAN_TX_RTR_FRAME) {
        RXB0DLC |= 0b01000000;
    }

    // Populate data values.
    ptr = (__sfr *) &(RXB0D0);
    for (i = 0; i < can_msg->dlc; i++) {
        ptr[ i ] = can_msg->data[ i ];
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

