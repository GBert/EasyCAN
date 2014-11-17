#include <stdio.h>

#define SERIAL_BUFFER_SIZE      16
#define SERIAL_BUFFER_SIZE_MASK (SERIAL_BUFFER_SIZE -1)

struct serial_buffer {
    unsigned char head;
    unsigned char tail;
    unsigned char data[SERIAL_BUFFER_SIZE];
};

void debug_print_fifo( struct serial_buffer *fifo) {
    unsigned char i;
    printf("\nhead: %2d tail %2d Data:",fifo->head,fifo->tail);
    for (i=0 ; i < SERIAL_BUFFER_SIZE ; i++) {
       printf(" %02x", fifo->data[i]);
    }
    printf("\n");
}

char fifo_putchar(struct serial_buffer *fifo) {
    unsigned char tail=fifo->tail;
    printf("printing chars\n");
    if (fifo->head != tail) {
	tail++;
	tail&=SERIAL_BUFFER_SIZE_MASK;
        if (putchar(fifo->data[tail])) {
            tail&=SERIAL_BUFFER_SIZE_MASK;      /* wrap around if neededd */
            fifo->tail=tail;
    	    debug_print_fifo(fifo);
            return 1;
        }
    }
    return 0;
}

/* print into circular buffer */
/* TODO: check if local var head speed up function */

char print_fifo(const unsigned char *s, struct serial_buffer *fifo) {
    unsigned char head=fifo->head;
    char c;
    while ( ( c = *s++ ) ) {
        head++;
        head&=SERIAL_BUFFER_SIZE_MASK;          /* wrap around if neededd */
        printf("pf head: %2d tail %2d\n",head,fifo->tail);
        if (head != fifo->tail) {               /* space left ? */
            fifo->data[head]=c;
        } else {
            return -1;
        }
    }
    fifo->head=head;                            /* only store new pointer if all is OK */
    return 1;
}

int main( int argc,const char* argv[]) {
    struct serial_buffer fifo;
    char ret;
    fifo.head=0;
    fifo.tail=0;
    debug_print_fifo(&fifo);
    ret=print_fifo("Hello world !\n",&fifo);
    debug_print_fifo(&fifo);
    ret=fifo_putchar(&fifo);
    ret=fifo_putchar(&fifo);
    ret=fifo_putchar(&fifo);
    ret=fifo_putchar(&fifo);
    ret=fifo_putchar(&fifo);
    ret=fifo_putchar(&fifo);
    ret=fifo_putchar(&fifo);
    ret=fifo_putchar(&fifo);
    ret=fifo_putchar(&fifo);
    ret=fifo_putchar(&fifo);
    ret=fifo_putchar(&fifo);
    ret=fifo_putchar(&fifo);
    ret=print_fifo("Der Hund.\n",&fifo);
    // debug_print_fifo(&fifo);
    ret=fifo_putchar(&fifo);
    ret=fifo_putchar(&fifo);
    ret=fifo_putchar(&fifo);
    ret=fifo_putchar(&fifo);
    ret=fifo_putchar(&fifo);
    ret=fifo_putchar(&fifo);
    ret=fifo_putchar(&fifo);
    ret=fifo_putchar(&fifo);
    ret=fifo_putchar(&fifo);
    ret=fifo_putchar(&fifo);
    ret=fifo_putchar(&fifo);
    ret=fifo_putchar(&fifo);
    printf("ret: %d\n",ret);
    return 0;
}
