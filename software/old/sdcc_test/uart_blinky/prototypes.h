#ifndef _PROTOTYPES_H_
#define _PROTOTYPES_H_

void init_usart(void);
char putchar(unsigned char c);
void putchar_wait(unsigned char c);
void puts_rom(const char * c);
char puts_rom_fifo(const char * s, struct serial_buffer * fifo);
void print_hex_wait(unsigned char c);
char putchar_fifo(char c, struct serial_buffer * fifo);
char fifo_getchar(struct serial_buffer * fifo);
char fifo_putchar(struct serial_buffer * fifo);
void print_debug_value(char c, unsigned char value);
void print_debug_fifo(struct serial_buffer * fifo);
char copy_char_fifo(struct serial_buffer * source_fifo, struct serial_buffer * destination_fifo);

#endif /* _PROTOTYPES_H_ */
