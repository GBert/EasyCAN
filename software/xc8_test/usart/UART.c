#include "UART.h"

/* UARTServeInt()
 *
 * Serves UART interrupt putting every
 * byte received in a FIFO buffer
 */
void UARTServeInt(void) {
	// Clear interrupt flag
	PIR1bits.RCIF = 0;

	// Get one byte from UART
	BYTE byteReceived = UARTGet();

	// Put the character into the FIFO buffer
	FIFOPut(UART_FIFO, byteReceived);
}

/*
 * UART1Open(WORD baudrate)
 * [baudrate]: specifies the baudrate used to
 * communicate using the serial port
 *
 * Opens the UART1 port for serial communication
 */
void UARTOpen(BYTE spbrg) {
	// Configure RX
	RCSTAbits.SPEN = 1;	// Enable serial port
	RCSTAbits.RX9 = 0;	// 8-bit reception
	RCSTAbits.ADDEN = 0;	// Disable address detection
	RCSTAbits.FERR = 0;	// No framing error
	RCSTAbits.OERR = 0;	// No overrun error
	
	// Configure TX
	TXSTAbits.TX9 = 0;	// 8-bit transmision
	TXSTAbits.SYNC = 0;	// Asynchronous mode
	TXSTAbits.BRGH = 0;	// High speed baud rate

	// Pin directions
	RXD_TRIS = INPUT_PIN;
	TXD_TRIS = OUTPUT_PIN;

	// Calculate baud rate (9600 bps)
	SPBRG = spbrg;

	RCSTAbits.CREN = 1;	// Enable receiver
	TXSTAbits.TXEN = 1;	// Enable transmitter
	PIE1bits.RCIE = 1;	// Enable receive interrupt
}

BOOL UARTBusy(void) {
	if (!TXSTAbits.TRMT)
	    return TRUE;

	return FALSE;
}

BOOL UARTDataReady(void) {
	if (PIR1bits.RCIF)
    	return TRUE;

	return FALSE;
}

/*
 * UARTPut(BYTE b)
 * [b]: the byte or character willing to send
 *
 * Sends a data byte through the serial port
 */
void UARTPut(BYTE b) {
	// Wait while the UART module is busy
	while (UARTBusy());
	
	// Send the specified byte or character
	TXREG = b;
}

BYTE UARTGet(void) {
	BYTE data;
  	data = RCREG;

	return (data);
}

/*
 * UARTReadLine(BYTE *lineBuffer, WORD timeout)
 * [*lineBuffer]: a pointer to the buffer where to save the read line
 * [timeout]: timeout in milliseconds
 *
 * Reads a line from the input buffer and saves it to the specified buffer.
 * Returns the quantity of bytes read.
 */
WORD UARTReadLine(BYTE *lineBuffer, void (*callback)()) {
	WORD usedSpace;
	WORD bytesRead = 0;
	BYTE b;

	*lineBuffer = '\0';

	while (TRUE)
	{
		callback();

		usedSpace = FIFOUsedSpace(UART_FIFO);

		if (usedSpace > 0)
		{
			b = FIFOGet(UART_FIFO);
			UARTPut(b);

			switch (b)
			{
				case '\r':
					*lineBuffer++ = '\0';
					return bytesRead;
				default:
					*lineBuffer++ = b;
					bytesRead++;
					break;
			}
		}
	}

	return 0;
}

/* UARTWriteLine(BYTE *pBuffer)
 * [*pBuffer]: a pointer to the buffer containing the line to send or write
 * 
 * Sends a line through the serial port
 */
void UARTWriteLine(BYTE *pBuffer) {
	// Wait while the UART module is busy
	while (UARTBusy());

	do
  	{
		// Transmit a byte
    	while (UARTBusy());
    	UARTPut(*pBuffer);
  	} while (*pBuffer++);
}

void UARTSendBytes(BYTE *pBuffer, WORD len) {
	WORD i;
	BYTE b;

	for (i = 0; i < len; i++)
	{
		b = *pBuffer++;
		UARTPut(b);
	}
}

/* UARTClose(void)
 *
 * Closes the UART serial port
 */
void UARTClose(void) {
	RCSTAbits.CREN = 0;		// Disable receiver
	TXSTAbits.TXEN = 0;		// Disable transmitter
}
