#define _XTAL_FREQ 64000000	/* required for __delay_ms, __delay_us macros */
#define FCYC (_XTAL_FREQ/4L)		/* target device instruction clock freqency */

#include <xc.h>
#include "HardwareProfile.h"
#include "Timer.h"
#include "FIFO.h"
#include "UART.h"

#pragma config XINST = OFF
#pragma config FOSC = HS2 
#pragma config PLLCFG = ON
#pragma config MCLRE = ON
#pragma config WDTEN = OFF 
#pragma config CANMX = PORTB
#pragma config PWRTEN = ON
#pragma config CP0 = OFF
#pragma config CPD = OFF
// #pragma config LVP = ON


#define LINE_TIMEOUT    5000

static BYTE line[128];
BOOL onTimer = FALSE;
DWORD startSeconds = 0;
DWORD triggerSeconds = 0;
DWORD lastSeconds = 0;
BYTE timerTriggerState = 'T';

void executeTasks(void);
void timerTask(void);

// Default Interrupt Service Routine
void interrupt isr(void) {
        if (RCIE && RCIF) {
                UARTServeInt();
        }

        if (TMR0IE && TMR0IF) {
                TMRServeInt();
        }
}

int main(void) {
        WORD num;

        BoardInit();
        TMRInit();
        FIFOInit();
	// Fosc/64
	// 64MHz ->
        UARTOpen(34);

	UARTWriteLine("\r\nUUUUUUUUUUUUUUUUUUUUUUUUUUU\r\n");       
	UARTWriteLine("\r\nQuark calling !\r\n");       
	UARTWriteLine("\r\nfffffffffffffffffffffffffff\r\n");       
        while (TRUE)
	if (UARTReadLine(line, &executeTasks)) {
		// AT command
		if (strcmp(line, "AT") == 0) {
			UARTWriteLine("\r\nOK\r\n");
			continue;
		}
	}
}
void executeTasks(void) {
        timerTask();
}

void timerTask(void) {
        DWORD cs;

        if (onTimer) {
                if (TMRSecondsElapsed(startSeconds) >= triggerSeconds) {
                        switch (timerTriggerState) {
                                case '1':
                                        break;
                                case '0':
                                        break;
                                default:
                                        break;
                        }
                        onTimer = FALSE;
                } else {
                        cs = TMRGetSecondsCount();
                        if (cs != lastSeconds) {
                                lastSeconds = cs;
                                LED = !LED;
                        }
                }
        }
}

