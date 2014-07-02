/* ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <info@gerhard-bertelsmann.de> wrote this file. As long as you retain this
 * notice you can do whatever you want with this stuff. If we meet some day,
 * and you think this stuff is worth it, you can buy me a beer in return
 * Gerhard Bertelsmann
 * ----------------------------------------------------------------------------
 */

#include "usart.h"

void init_usart (void) {
    // USART configuration
    TRISCbits.TRISC6 = 0;	// make the TX pin a digital output
    TRISCbits.TRISC7 = 1;	// make the RX pin a digital input
    TXSTAbits.BRGH = 1;		// high speed
    BAUDCON1bits.BRG16 = USE_BRG16; // 8-bit baud rate generator
    SPBRG = SBRG_VAL;		// calculated by defines
    
    TXSTAbits.SYNC = 0;		// asynchronous mode
    RCSTAbits.RX9  = 0;		// 8-bit reception
    RCSTAbits.CREN = 1;		// enable receiver

    TXSTAbits.TX9  = 0;		// 8-bit transmission
    TXSTAbits.TXEN = 1;		// transmit enabled
    RCSTAbits.SPEN = 1;		// enable serial port (configures RX/DT and TX/CK pins as serial port pins)

    /* don' use interrupts at the moment 
    // interrupts / USART interrupts configuration
    RCONbits.IPEN   = 0; // disable interrupt priority
    INTCONbits.GIE  = 1; // enable interrupts
    INTCONbits.PEIE = 1; // enable peripheral interrupts.
    PIE1bits.RCIE   = 1; // enable USART receive interrupt
    PIE1bits.TXIE   = 0; // disable USART TX interrupt
    PIR1bits.RCIF = 0;
    */
}

char putchar(unsigned char c) {
    if ( !TRMT1 ) {
	TXREG = c;
        return 1;
    }
    return 0;
}

void puts(unsigned char *s) {
    char c;
    while ( ( c = *s++ ) ) {
	putchar( c );
    }
}

/* put next char onto USART */
char fifo_putchar(struct serial_buffer *fifo) {
    unsigned char tail=fifo->tail;
    if (fifo->head != tail) {
	tail++;
	tail&=SERIAL_BUFFER_SIZE_MASK;	/* wrap around if neededd */
	if (putchar(fifo->data[tail])) {
	    fifo->tail=tail;
	    return 1;
	}
    }
    return 0;
}

/* print into circular buffer */
char print_fifo(const unsigned char *s, struct serial_buffer *fifo) {
    unsigned char head=fifo->head;
    char c;
    while ( ( c = *s++ ) ) {
	head++;
	head&=SERIAL_BUFFER_SIZE_MASK;		/* wrap around if neededd */
	if (head != fifo->tail) {		/* space left ? */ 
	    fifo->data[head]=c;
	} else {
	    return -1;
	}
    }
    fifo->head=head;				/* only store new pointer if all is OK */
    return 1;
}

