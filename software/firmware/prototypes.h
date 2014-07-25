#ifndef _PROTOTYPES_H_
#define _PROTOTYPES_H_

void init_usart(void);
char putchar(unsigned char c);
void putchar_wait(unsigned char c);
void puts_rom(const char * c);
char puts_rom_fifo(const char * s, struct serial_buffer * fifo);
void print_hex_wait(unsigned char c);
void print_sfr_n(const char * s, __sfr * sfr, unsigned char length);
void print_sfr(const char * s, unsigned char c);
char putchar_fifo(char c, struct serial_buffer * fifo);
char fifo_getchar(struct serial_buffer * fifo);
char fifo_putchar(struct serial_buffer * fifo);
void print_debug_value(char c, unsigned char value);
void print_debug_fifo(struct serial_buffer * fifo);
char copy_char_fifo(struct serial_buffer * source_fifo, struct serial_buffer * destination_fifo);

/* TIMER specific */
void init_timer(void);

/* CAN specific */
void init_can(const char brgcon1, unsigned char brgcon2, unsigned char brgcon3);
char can_readmsg(void);
char can_writemsg(void);
#endif /* _PROTOTYPES_H_ */
