/* ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <info@gerhard-bertelsmann.de> wrote this file. As long as you retain this
 * notice you can do whatever you want with this stuff. If we meet some day,
 * and you think this stuff is worth it, you can buy me a beer in return
 * Gerhard Bertelsmann
 * ----------------------------------------------------------------------------
 */

#ifndef _USART_H_
#define _USART_H_

#include <xc.h>
#include "main.h"

/* BUFFER_SIZE must be power of two (16,32,64...) */
#define SERIAL_BUFFER_SIZE	64
#define SERIAL_BUFFER_SIZE_MASK	(SERIAL_BUFFER_SIZE -1)

#ifndef BAUDRATE
#define BAUDRATE	500000
#endif
#define USE_BRG16	0
#define USE_BRGH	1

/* USART calculating Baud Rate Generator
 * if BRGH = 0 => FOSC/[64 (n + 1)]
 * if BRGH = 1 => FOSC/[16 (n + 1)]
 * avoid rounding errors
 */

#if USE_BRGH == 0
#define	SBRG_VAL	( (((_XTAL_FREQ / BAUDRATE) / 32) - 1) / 2 )
#else
#define	SBRG_VAL	( (((_XTAL_FREQ / BAUDRATE) / 8) - 1) / 2 )
#endif


/* circular buffer */
typedef struct serial_buffer {
    unsigned char head;
    unsigned char tail;
    unsigned char data[SERIAL_BUFFER_SIZE];
};

#endif		/* _USART_H_ */
