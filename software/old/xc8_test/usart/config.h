#include <p18f26k80.h>

#define FOSC = HS2
#define PLLCFG = ON
#define PWRT   = ON
#define BOR    = OFF         // BrownOutReset: off
#define WDT    = OFF         // Watchdog Timer: off
#define MCLRE  = ON          // MCLR Enable
#define PBADEN = OFF         // PORTB<4:0> pins are configured as digital I/O on Reset
#define LVP    = ON         // Low Voltage ICSP: off
#define CANMX = PORTB 
