/* ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <info@gerhard-bertelsmann.de> wrote this file. As long as you retain this
 * notice you can do whatever you want with this stuff. If we meet some day,
 * and you think this stuff is worth it, you can buy me a beer in return
 * Gerhard Bertelsmann
 * ----------------------------------------------------------------------------
 */

#include "main.h"
#include "usart.h"

const char * s1 = "circular buffer is working!\r\n";
const char * s2 = "USART is working!\r\n";

volatile unsigned char timer_ticks=0;
struct serial_buffer_t tx_fifo, rx_fifo;

void init_port(void) {
    ADCON1 = 0x0F;		// Default all pins to digital
    LED_TRIS = 0;
}

void init_timer(void) {
    // time period = 1/16MHz = 0.0625 us
    // prescaler period = .0625us * 256 = 16us
    // overflow period  = 16us * 256 = 4.096ms
    T0PS0=1;    //Prescaler is divide by 256
    T0PS1=1;
    T0PS2=1;

    PSA=0;      //Timer Clock Source is from Prescaler
    T0CS=0;     //Prescaler gets clock from FCPU (16MHz)

    T08BIT=1;   //8 BIT MODE

    TMR0IE=1;   //Enable TIMER0 Interrupt
    PEIE=1;     //Enable Peripheral Interrupt
    GIE=1;      //Enable INTs globally

    TMR0ON=1;   //Now start the timer!
}

void main(void) {
    char do_print=0;
    char ret=0;
    init_port();
    init_timer();
    init_usart();

    /* empty circular buffers */
    tx_fifo.head=0;
    tx_fifo.tail=0;
    rx_fifo.head=0;
    rx_fifo.tail=0;
    
    //print_debug_fifo(&tx_fifo);
    //infinite loop
    while(1) {
	if ((do_print == 0) && (timer_ticks == 10)) {
	    puts_rom(s1);
	    do_print = 1;
	}
	if ((do_print == 1) && (timer_ticks == 100)) {
	    //ret=print_rom_fifo(s1,&tx_fifo);
	    puts_rom(s2);
	    ret++;
            print_debug_value('r',ret);
            putchar_wait('\n');
            putchar_wait('\r');
	    do_print = 0;
            
    	    //print_debug_fifo(&tx_fifo);
	}
	//ret=fifo_putchar(&tx_fifo);
    }
}

void interrupt ISRCode() {
    if (TMR0IE && TMR0IF) {
        // overflow every 4.096ms
        timer_ticks++;
        // 80ms
        if (timer_ticks==20) {
            LED = 0;		//LED OFF
        }
        // 80ms
        if (timer_ticks==40) {
            LED = 1;		//LED ON
        }
        // 80ms
        if (timer_ticks==60) {
            LED = 0;		//LED OFF
        }
        // 800ms
        if (timer_ticks==250) {
            LED = 1;		//LED ON
            timer_ticks=0;
        }
        TMR0IF = 0;
    }
}
