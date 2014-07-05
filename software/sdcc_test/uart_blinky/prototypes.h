char putchar(unsigned char c);
void putchar_wait(unsigned char c);
void puts_rom(const char * c);
void init_usart(void);
char fifo_putchar(struct serial_buffer * fifo);
char print_rom_fifo(const unsigned char * s, struct serial_buffer * fifo);
void print_debug_value(char c, unsigned char value);
void print_debug_fifo(struct serial_buffer * fifo);
