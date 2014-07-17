/* ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <info@gerhard-bertelsmann.de> wrote this file. As long as you retain this
 * notice you can do whatever you want with this stuff. If we meet some day,
 * and you think this stuff is worth it, you can buy me a beer in return
 * Gerhard Bertelsmann
 * ----------------------------------------------------------------------------
 */

#include "usart.h"

const char sData[] = " Data: ";

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

void print_hex_wait(unsigned char c) {
    unsigned char nibble;
    nibble=((c & 0xf0) >> 4 ) + '0';
    if (nibble>=0x3a) nibble+=7;
    putchar_wait(nibble);

    nibble=(c & 0x0f) + '0';
    if (nibble>=0x3a) nibble+=7;
    putchar_wait(nibble);
}


void puts_rom(const char * s) {
    char c;
    while ( ( c = *s++ ) ) {
	putchar_wait( c );
    }
}

void print_sfr(const char * s, unsigned char c) {
    puts_rom(s);
    putchar_wait(' ');
    print_hex_wait(c);
    putchar_wait('\r');
    putchar_wait('\n');
}

void print_sfr_n(const char * s, __sfr * sfr, unsigned char length) {
    unsigned char i;
    puts_rom(s);
    for (i=0 ; i<length ; i++ ) {
	print_hex_wait(*(sfr+i));
    	putchar_wait(' ');
    }
    putchar_wait('\r');
    putchar_wait('\n');
}

void print_debug_value(char c, unsigned char value) {
    putchar_wait(c);
    putchar_wait(':');
    print_hex_wait(value);
}

void print_debug_fifo(struct serial_buffer * fifo) {
    unsigned char i;
    putchar_wait('\r');
    putchar_wait('\n');
    print_debug_value('S',SERIAL_BUFFER_SIZE);
    putchar_wait(' ');
    print_debug_value('M',SERIAL_BUFFER_SIZE_MASK);
    putchar_wait(' ');
    print_debug_value('H',fifo->head);
    putchar_wait(' ');
    print_debug_value('T',fifo->tail);
    putchar_wait(' ');
    putchar_wait(' ');
    putchar_wait(' ');
    puts_rom(sData);
    for (i=0; i<SERIAL_BUFFER_SIZE; i++) {
        print_hex_wait(fifo->data[i]);
        putchar_wait(' ');
    }
    putchar_wait('\r');
    putchar_wait('\n');
}

/* place char into fifo */
char putchar_fifo(char c, struct serial_buffer * fifo) {
    unsigned char head;
    head=fifo->head;
    head++;
    head &= SERIAL_BUFFER_SIZE_MASK;		/* wrap around if needed */
    if (head != fifo->tail) {
	fifo->head = head;
	fifo->data[head] = c;
        return 1;
    };
    return 0;
}


/* get next char from USART put into fifo*/
char fifo_getchar(struct serial_buffer * fifo) {
    unsigned char head;
    char c;

    if (PIR1bits.RCIF) {
	head=fifo->head;
        head++;
	head &= SERIAL_BUFFER_SIZE_MASK;	/* wrap around if neededd */
	if (head != fifo->tail) {
            c=RCREG1;
            fifo->data[head]=c;
            fifo->head=head;
	    return c;
	}
    }
    return 0;
}

/* put next char onto USART */
char fifo_putchar(struct serial_buffer * fifo) {
    unsigned char tail;
    tail=fifo->tail;
    if (fifo->head != tail) {
	tail++;
	tail &= SERIAL_BUFFER_SIZE_MASK;	/* wrap around if neededd */
	if (putchar(fifo->data[tail])) {
	    fifo->tail=tail;
	    return 1;
	}
    }
    return 0;
}

/* print into circular buffer */
char puts_rom_fifo(const char * s, struct serial_buffer * fifo) {
    unsigned char head=fifo->head;
    char c;
    while ( ( c = *s++ ) ) {
	head++;
	head &= SERIAL_BUFFER_SIZE_MASK;	/* wrap around if neededd */
	if (head != fifo->tail) {		/* space left ? */ 
	    fifo->data[head]=c;
	} else {
	    return -1;
	}
    }
    fifo->head=head;				/* only store new pointer if all is OK */
    return 1;
}

char copy_char_fifo(struct serial_buffer * source_fifo, struct serial_buffer * destination_fifo) {
    unsigned char source_tail;
    unsigned char destination_head;
    source_tail=source_fifo->tail;
    /* check if there is nothing todo first
     * because this will happen most of the time */
    if ( source_tail == source_fifo->head) {
        return 0;
    } else {
	destination_head = destination_fifo->head;
	destination_head++;
	destination_head &= SERIAL_BUFFER_SIZE_MASK;
        while ((destination_head !=  destination_fifo->tail) && (source_tail != source_fifo->head)) {
	    source_tail++;
            source_tail &= SERIAL_BUFFER_SIZE_MASK;
            destination_fifo->data[destination_head] = source_fifo->data[source_tail];
	    destination_fifo->head = destination_head;		/* store new pointer destination head before increment*/
            destination_head++;
            destination_head &= SERIAL_BUFFER_SIZE_MASK;
        }
	source_fifo->tail      = source_tail;			/* store new pointer source tail */
	return source_fifo->data[source_tail];
    }
}

