#ifndef _UART_H_
#define _UART_H_

#include "HardwareProfile.h"
#include "Timer.h"
#include "FIFO.h"
#include <stdio.h>
#include <string.h>

#define USE_OR_MASKS
#define UART_FIFO	0	// FIFO buffer ID (see FIFO.h)
#define UART_TIMEOUT	5	// seconds

extern void UARTServeInt(void);
extern void UARTOpen(BYTE spbrg);
extern BOOL UARTBusy(void);
extern BOOL UARTDataReady(void);
extern void UARTPut(BYTE b);
extern BYTE UARTGet(void);
extern WORD UARTReadLine(BYTE *lineBuffer, void (*callback)());
extern void UARTWriteLine(BYTE *pBuffer);
extern void UARTSendBytes(BYTE *pBuffer, WORD len);
extern void UARTClose(void);

#endif
