/* ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <info@gerhard-bertelsmann.de> wrote this file. As long as you retain this
 * notice you can do whatever you want with this stuff. If we meet some day,
 * and you think this stuff is worth it, you can buy me a beer in return
 * Gerhard Bertelsmann
 * ----------------------------------------------------------------------------
 */

#include "slcan.h"

volatile char slcan_buffer[30];
extern volatile struct CAN_MSG TX_CANMessage;
extern volatile struct CAN_MSG RX_CANMessage;

volatile unsigned char id_buffer[4];

const char hex_string[] = "0123456789ABCDEF";

/* access global CAN_MSG RX_CANMessage */
char rx_buffer_to_slcan (void) {
    unsigned char i, dlc;
    unsigned char *ptr;

    /* test if receiver remote transmission request
     * RXBnDLCbits.RXRTR */
    if (RX_CANMessage.DLC & 40 ) {
        slcan_buffer[0]='r';
    } else {
        slcan_buffer[0]='t';
    }
    /* extended ?
     *  RXFnSIDLbits.EXID */
    if (RX_CANMessage.SIDL & 0x08) {
        /* 29 bit id - change type to upper char */
        slcan_buffer[0] -= 0x20;
        /* bits 29 - 25 */
        id_buffer[0] = RX_CANMessage.SIDH  >> 3;
	slcan_buffer[1]= hex_string[id_buffer[0] & 0xf0] >> 4;
	slcan_buffer[2]= hex_string[id_buffer[0] & 0x0f];
        /* bits 24 - 17 are spread over 3 registers - wow */
        id_buffer[1] =(RX_CANMessage.SIDL & 0x03) + ((RX_CANMessage.SIDL & 0xe0) >> 3)  + ((RX_CANMessage.SIDH & 0x07) << 5)   ;
	slcan_buffer[3]= hex_string[id_buffer[1] & 0xf0] >> 4;
	slcan_buffer[4]= hex_string[id_buffer[1] & 0x0f];
        /* bits 16 - 9 */
        id_buffer[2] = RX_CANMessage.EIDH;
	slcan_buffer[5]= hex_string[id_buffer[2] & 0xf0] >> 4;
	slcan_buffer[6]= hex_string[id_buffer[2] & 0x0f];
        /* bits  8 - 1 */
        id_buffer[3] = RX_CANMessage.EIDL;
	slcan_buffer[7]= hex_string[id_buffer[3] & 0xf0] >> 4;
	slcan_buffer[8]= hex_string[id_buffer[3] & 0x0f];
        /* ... */
        ptr = &slcan_buffer[9];
    } else {
        /* bits 11 - 9 */
        id_buffer[0] = (RX_CANMessage.SIDH >> 5);
	slcan_buffer[1]= hex_string[id_buffer[0] & 0x0f];
        /* bits  8 - 1 */
        id_buffer[1] = ((RX_CANMessage.SIDL & 0xc0 ) >> 5) + (RX_CANMessage.SIDH << 3);
	slcan_buffer[2]= hex_string[id_buffer[1] & 0xf0] >> 4;
	slcan_buffer[3]= hex_string[id_buffer[2] & 0x0f];
        /* 11 bit standard frame */
        ptr = &slcan_buffer[4];
    }
    dlc = RX_CANMessage.DLC & 0x0f;
    *ptr++ = hex_string[dlc];
    for (i=0 ; i< dlc ; i++) {
       *ptr++=hex_string[(RX_CANMessage.Data[i] & 0xf0) >> 4 ];
       *ptr++=hex_string[RX_CANMessage.Data[i] & 0x0f ];
    }
    /* terminate string */
    *ptr=0;
    return 0;
}
 
