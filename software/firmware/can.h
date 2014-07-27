/* ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <info@gerhard-bertelsmann.de> wrote this file. As long as you retain this
 * notice you can do whatever you want with this stuff. If we meet some day,
 * and you think this stuff is worth it, you can buy me a beer in return
 * Gerhard Bertelsmann
 * ----------------------------------------------------------------------------
 */

#ifndef _CAN_H_
#define _CAN_H_

#include "main.h"

#define CAN_TX_XTD_FRAME	0b00001000
#define CAN_TX_RTR_FRAME	0b01000000

#define CAN_RX_OVERFLOW		0b00001000
#define CAN_RX_INVALID_MSG	0b00010000
#define CAN_RX_XTD_FRAME	0b00100000
#define CAN_RX_RTR_FRAME	0b01000000
#define CAN_RX_DBL_BUFFERED	0b10000000

typedef struct CAN_MSG {
    unsigned char EIDH;
    unsigned char EIDL;
    unsigned char SIDH;
    unsigned char SIDL;
    unsigned char DLC;
    unsigned char Data[8];
    unsigned char Priority;
};

/* http://www.port.de/cgi-scripts/tq_v1_0.cgi?ctype=pic18&CLK=32&sample_point=87.5
 * there seems to be a BUG in the script (as of 26/7/2014 -> clock must be devided by 2 */

const char BRGCON_64MHZ [][3] = {
    {0x3f,0xbf,0x02},	/*   10k not possible -> 20k */
    {0x3f,0xbf,0x07},	/*   20k */
    {0x27,0xbc,0x02},	/*   50k */
    {0x13,0xbc,0x01},	/*  100k */
    {0x0f,0xbc,0x01},	/*  125k */
    {0x07,0xbc,0x01},	/*  250k */
    {0x03,0xbc,0x01},	/*  500k */
    {0x04,0x84,0x00},   /*  800k */
    {0x01,0xbc,0x01},	/* 1000k */
};

/* http://www.port.de/cgi-scripts/tq_v1_0.cgi?ctype=pic18&CLK=8&sample_point=87.5
 * there seems to be a BUG in the script (as of 26/7/2014 -> clock must be devided by 2 */

const char BRGCON_16MHZ [][3] = {
    {0x31,0xbf,0x07},	/*   10k */
    {0x18,0xbc,0x01},	/*   20k */
    {0x09,0xbc,0x01},	/*   50k */
    {0x04,0xbc,0x01},	/*  100k */
    {0x03,0xbc,0x01},	/*  125k */
    {0x01,0xbc,0x01},	/*  250k */
    {0x00,0xbc,0x01},	/*  500k */
    {0x00,0x86,0x00},	/*  800k */
    {0x00,0x84,0x00},	/* 1000k */
};

#endif		/* _CAN_H_ */

