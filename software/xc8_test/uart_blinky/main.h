/* ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <info@gerhard-bertelsmann.de> wrote this file. As long as you retain this
 * notice you can do whatever you want with this stuff. If we meet some day,
 * and you think this stuff is worth it, you can buy me a beer in return
 * Gerhard Bertelsmann
 * ----------------------------------------------------------------------------
 */

#ifndef _MAIN_H_
#define _MAIN_H_

#include <xc.h>

#define _XTAL_FREQ 64000000	// This is the speed your controller is running at
#define FCYC (_XTAL_FREQ/4L)	// target device instruction clock freqency

#define LED_TRIS        (TRISAbits.TRISA0)
#define LED             (LATAbits.LATA0)

extern void interrupt ISRCode(void);
extern char putchar(unsigned char c);
extern void putchar_wait(unsigned char c);
extern void puts_rom(const char *c);
extern void init_usart(void);
extern char fifo_putchar(struct serial_buffer *fifo);
extern char print_rom_fifo(const unsigned char *s, struct serial_buffer *fifo);
extern void print_debug_value(char c, unsigned char value);
extern void print_debug_fifo(struct serial_buffer *fifo);
#endif /* _MAIN_H_ */

