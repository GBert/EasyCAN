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
    TXSTA1bits.BRGH = USE_BRGH;		// high speed
    BAUDCON1bits.BRG16 = USE_BRG16; 	// 8-bit baud rate generator
    SPBRG = SBRG_VAL;		// calculated by defines
 
    PIE1bits.RC1IE = 0;		// disbale RX interrupt
    PIE1bits.TX1IE = 0;		// disbale TX interrupt
 
    RCSTA1bits.RX9  = 0;	// 8-bit reception
    RCSTA1bits.SPEN = 1;	// enable serial port (configures RX/DT and TX/CK pins as serial port pins)
    RCSTA1bits.CREN = 1;	// enable receiver

    TXSTA1bits.TX9  = 0;	// 8-bit transmission
    TXSTA1bits.SYNC = 0;	// asynchronous mode
    TXSTA1bits.TXEN = 1;	// transmit enabled

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

/* prints char on USART if pssible */
char putchar(unsigned char c) {
    if ( TXSTA1bits.TRMT1 ) {
	TXREG1 = c;
        return 1;
    }
    return 0;
}

/* prints char on USART */
void putchar_wait(unsigned char c) {
   while (!TXSTA1bits.TRMT1);
   TXREG1 = c;
}

void puts_rom(const char *s) {
    char c;
    while ( ( c = *s++ ) ) {
	putchar_wait( c );
    }
}

void print_hex_wait(unsigned char c) {
    putchar_wait(((c & 0xf0) >> 8) + '0');
    putchar_wait(( c & 0x0f)       + '0');
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

