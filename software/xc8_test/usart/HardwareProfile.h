#ifndef _HARDWARE_PROFILE_H_
#define _HARDWARE_PROFILE_H_

#include <xc.h>
#include <stdlib.h>

// Boolean states
#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE !FALSE
#endif

// Pin Directions
#define OUTPUT_PIN	0
#define INPUT_PIN	1

// Type definitions
typedef unsigned char	BYTE;
typedef unsigned int	WORD;
typedef unsigned long	DWORD;

// Board definitions
#define RELAY_TRIS		(TRISBbits.TRISB0)
#define LED_TRIS		(TRISBbits.TRISB1)
#define BTN_TRIS		(TRISAbits.TRISA0)
#define RXD_TRIS		(TRISCbits.TRISC7)
#define TXD_TRIS		(TRISCbits.TRISC6)
#define RELAY			(LATBbits.LATB0)
#define LED				(LATBbits.LATB1)
#define BTN				(PORTAbits.RA0)
#define TXD				(LATCbits.LATC6)

// Function definitions
extern void BoardInit(void);
extern void EnableInterrupts(void);

#endif
