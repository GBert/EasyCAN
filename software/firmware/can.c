/* ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <info@gerhard-bertelsmann.de> wrote this file. As long as you retain this
 * notice you can do whatever you want with this stuff. If we meet some day,
 * and you think this stuff is worth it, you can buy me a beer in return
 * Gerhard Bertelsmann
 * ----------------------------------------------------------------------------
 */

#include "can.h"
#include "easycan.h"

void init_can(void) {
    // Enter CAN config mode
    CANCON = 0x80;    //REQOP<2:0>=100
    // wait to complete
    while(!(CANSTATbits.OPMODE ==0x04));

    // Enter CAN module into Mode 0
    ECANCON = 0x00;
    /* TODO */
}

unsigned char read_can_message(struct canmsg_t *can_message) {
    unsigned char RXMsgFlag = 0;

    /* TODO */
    can_message->data[0] = RXB0EIDH;
    can_message->data[0] = RXB0EIDL;
    can_message->data[0] = RXB0SIDH;
    can_message->data[0] = RXB0SIDL;
    can_message->length  = RXB0DLC;
    can_message->data[0] = RXB0D0;
    can_message->data[1] = RXB0D1;
    can_message->data[2] = RXB0D2;
    can_message->data[3] = RXB0D3;
    can_message->data[4] = RXB0D4;
    can_message->data[5] = RXB0D5;
    can_message->data[6] = RXB0D6;
    can_message->data[7] = RXB0D7;
    RXB0CONbits.RXFUL = 0;
    RXMsgFlag = 0x01;

    return 0;
}

unsigned char write_can_message(struct canmsg_t *can_message) {
    return 0;
}

