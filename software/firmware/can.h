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

/* % can-calc-bit-timing -c 64000000 mcp251x
 *
 * Bit timing parameters for mcp251x with 64.000000 MHz ref clock
 * nominal                                 real Bitrt   nom  real SampP
 * Bitrate TQ[ns] PrS PhS1 PhS2 SJW BRP Bitrate Error SampP SampP Error CNF1 CNF2 CNF3
 * 1000000     62   5    6    4   1   4 1000000  0.0% 75.0% 75.0%  0.0% 0x03 0xac 0x03
 *  800000     62   7    8    4   1   4  800000  0.0% 80.0% 80.0%  0.0% 0x03 0xbe 0x03
 *  500000    125   6    7    2   1   8  500000  0.0% 87.5% 87.5%  0.0% 0x07 0xb5 0x01
 *  250000    250   6    7    2   1  16  250000  0.0% 87.5% 87.5%  0.0% 0x0f 0xb5 0x01
 *  125000    500   6    7    2   1  32  125000  0.0% 87.5% 87.5%  0.0% 0x1f 0xb5 0x01
 *  100000    625   6    7    2   1  40  100000  0.0% 87.5% 87.5%  0.0% 0x27 0xb5 0x01
 *   50000   1000   8    8    3   1  64   50000  0.0% 87.5% 85.0%  2.9% 0x3f 0xbf 0x02
 *   20000 ***bitrate not possible***
 *   10000 ***bitrate not possible***
 *
 *   where BRGCONx is CNFx
 */

const char BRGCON_64MHZ [][3] = {
    {0x3f,0xbf,0x02},	/*   10k not possible -> 50k */
    {0x3f,0xbf,0x02},	/*   20k not possible -> 50k */
    {0x3f,0xbf,0x02},	/*   50k  */
    {0x27,0xb5,0x01},	/*  100k */
    {0x1f,0xb5,0x01},	/*  125k */
    {0x0f,0xb5,0x01},	/*  250k */
    {0x07,0xb5,0x01},	/*  500k */
    {0x03,0xbe,0x03},   /*  800k */
    {0x03,0xac,0x03},	/* 1000k */
};

/* % can-calc-bit-timing -c 16000000 mcp251x
 * Bit timing parameters for mcp251x with 16.000000 MHz ref clock
 * nominal                                 real Bitrt   nom  real SampP
 * Bitrate TQ[ns] PrS PhS1 PhS2 SJW BRP Bitrate Error SampP SampP Error CNF1 CNF2 CNF3
 * 1000000     62   5    6    4   1   1 1000000  0.0% 75.0% 75.0%  0.0% 0x00 0xac 0x03
 *  800000     62   7    8    4   1   1  800000  0.0% 80.0% 80.0%  0.0% 0x00 0xbe 0x03
 *  500000    125   6    7    2   1   2  500000  0.0% 87.5% 87.5%  0.0% 0x01 0xb5 0x01
 *  250000    250   6    7    2   1   4  250000  0.0% 87.5% 87.5%  0.0% 0x03 0xb5 0x01
 *  125000    500   6    7    2   1   8  125000  0.0% 87.5% 87.5%  0.0% 0x07 0xb5 0x01
 *  100000    625   6    7    2   1  10  100000  0.0% 87.5% 87.5%  0.0% 0x09 0xb5 0x01
 *   50000   1250   6    7    2   1  20   50000  0.0% 87.5% 87.5%  0.0% 0x13 0xb5 0x01
 *   20000   3125   6    7    2   1  50   20000  0.0% 87.5% 87.5%  0.0% 0x31 0xb5 0x01
 *   10000   4000   8    8    8   1  64   10000  0.0% 87.5% 68.0% 22.3% 0x3f 0xbf 0x07
 *
 *   where BRGCONx is CNFx
 */

const char BRGCON_16MHZ [][3] = {
    {0x3f,0xbf,0x07},
    {0x31,0xb5,0x01},
    {0x13,0xb5,0x01},
    {0x09,0xb5,0x01},
    {0x07,0xb5,0x01},
    {0x03,0xb5,0x01},
    {0x01,0xb5,0x01},
    {0x00,0xbe,0x03},
    {0x00,0xac,0x03},
};

#endif		/* _CAN_H_ */

