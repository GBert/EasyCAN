/*------------------------------------------------------------------------------
;
; Title:	Proton MKII MEGA DEMO for The Wellington Boot Loader
;
; Copyright:	Copyright (c) 2014 The Duke of Welling Town
;
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
;   This file is part of The Wellington Boot Loader.
;
;   The Wellington Boot Loader is free software: you can redistribute it and/or
;   modify it under the terms of the GNU General Public License as published
;   by the Free Software Foundation.
;
;   The Wellington Boot Loader is distributed in the hope that it will be
;   useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
;   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
;   GNU General Public License for more details.
;
;   You should have received a copy of the GNU General Public License along
;   with The Wellington Boot Loader. If not, see http://www.gnu.org/licenses/
;-----------------------------------------------------------------------------*/

#include "easy-can.h"

/*****************************************************************************/

/*
 * Tx buffer
 */

#pragma udata bank3 tx_buf
static uint8_t tx_buf[256];

static uint8_t tx_put = 0, tx_get = 0;
#define TX_EOF()   (tx_put == tx_get)
#define TX_PUTC(X) (tx_buf[tx_put++] = (X))
#define TX_GETC()  (tx_buf[tx_get++])

/*****************************************************************************/

/*
 * 7-bit ASCII to Binary Lookup Tables
 *
 *  Usage:
 *  	bin = hasc2bin['7'] | lasc2bin['F']; // ASCII "7F"
 */

static const uint8_t hasc2bin[] = {
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0x00,0x10,0x20,0x30,0x40,0x50,0x60,0x70,0x80,0x90,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xA0,0xB0,0xC0,0xD0,0xE0,0xF0,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xA0,0xB0,0xC0,0xD0,0xE0,0xF0,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
};

static const uint8_t lasc2bin[] = {
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
};

/*
 * 8-bit Binary to ASCII Lookup Table
 *
 *  Usage:
 *  	hasc = bin2asc[bin & 0xF0];	// High nibble
 *  	lasc = bin2asc[bin & 0x0F];	// Low  nibble
 */

static const uint8_t bin2asc[] = {
0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x41,0x42,0x43,0x44,0x45,0x46,
0x31,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0x32,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0x33,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0x34,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0x35,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0x36,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0x37,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0x38,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0x39,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0x41,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0x42,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0x43,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0x44,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0x45,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0x46,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
};

/*****************************************************************************/

/*
 * ISR
 *
 *  000008 high priority
 *  000018 low  priority
 */

void
isrHighPriority(void) __shadowregs __interrupt 1
{
	__asm
	NOP
	__endasm ;
}

void
isrLowPriority(void) __interrupt 2
{
	__asm
	NOP
	__endasm ;
}

/*****************************************************************************/

/*
 * Delay
 *
 *  WREG x 4TCY + CALL(2TCY) + RETURN(2TCY) + SDCC(9TCY)
 *
 *  Eg. For 50us with FCY = 16,000,000, WREG = 197
 *
 *  .000050 / (1 / 16000000) = 800 INSTRUCTIONS
 *  800 - 13 = 787		SUBTRACT CALL OVERHEAD
 *  787 / 4  = 196.75		DETERMINE LOOP COUNT
 */
void
delay_tcy(int wreg) __wparam
{
__asm
loop:
	ADDLW	-1		;1TCY
	BTFSS	_STATUS,_Z	;1TCY | 2TCY skip
	GOTO	loop		;2TCY
	NOP			;1TCY
__endasm ;
}

/*
 * Delay > 10us . t
 */
void
delay_10us(uint16_t t)
{
	uint8_t i;

	while (t--) {
		delay_tcy(DELAY10U);
	}
}

/*
 * Delay > t ms
 */
void
delay_ms(uint16_t t)
{
	uint8_t i;

	while (t--) {
		for (i = 0; i < 20; ++i) {
			delay_tcy(DELAY50U);
		}
	}
}

/*****************************************************************************/

/*
 * Init UART
 */
void
init_uart(void)
{
	TRISCbits.TRISC6 = 0;	/* RC6 I/P Tx */
	TRISCbits.TRISC7 = 1;	/* RC7 I/P Rx */

	BAUDCON1 = _BRG16;	/* 16-bit Baudrate */

	SPBRGH1 = BRG >> 8;	/* Baudrate */
	SPBRG1  = BRG & 0xFF;

	/* Enable Transmit + High Speed Mode */
	TXSTA = _TXEN + _BRGH;

	/* Enable Serial Port + Receiver */
	RCSTA = _SPEN + _CREN;

#if USE_STDIO == 1
	stdout = STREAM_USART;	/* Assign STDOUT to UART */
#endif
}

/*****************************************************************************/

/*
 * Init CAN Bus
 */
void
init_canbus(void)
{
	/* Enable CANRX */
	TRISBbits.TRISB2 = 0;
	TRISBbits.TRISB3 = 1;

	/* Enter configuration mode */
	/* TODO CANCONbits.REQOP2 = 1; */
	CANCON = 0x80;
	while (!(CANSTAT & _OPMODE2))
		;
#if CAN_ID_ALL == 1
	/* Set standard receive masks */
	RXM0SIDH = 0;        	/* For RXB0 with filters 0/1     */
	RXM0SIDL = 0;        
	RXM1SIDH = 0;		/* For RXB1 with filters 2/3/4/5 */
	RXM1SIDL = 0;

	/* Set standard receive filters for RXB0 */
	RXF0SIDH = 0;
	RXF0SIDL = 0;
	RXF1SIDH = 0;
	RXF1SIDL = 0;

	/* Set standard receive filters for RXB1 */
	RXF2SIDH = 0;
	RXF2SIDL = 0;
	RXF3SIDH = 0;
	RXF3SIDL = 0;
	RXF4SIDH = 0;
	RXF4SIDL = 0;
	RXF5SIDH = 0;
	RXF5SIDL = 0;
#else
	/* Set standard receive masks */
	RXM0SIDH = 0xFF;	/* For RXB0 with filters 0/1     */
	RXM0SIDL = 0xE0;
	RXM1SIDH = 0xFF;	/* For RXB1 with filters 2/3/4/5 */
	RXM1SIDL = 0xE0;

	/* Set standard receive filters for RXB0 */
	RXF0SIDH = CAN_ID >> 3;
	RXF0SIDL = CAN_ID << 5;
	RXF1SIDH = CAN_ID >> 3;
	RXF1SIDL = CAN_ID << 5;

	/* Set standard receive filters for RXB1 */
	RXF2SIDH = CAN_ID >> 3;
	RXF2SIDL = CAN_ID << 5;
	RXF3SIDH = CAN_ID >> 3;
	RXF3SIDL = CAN_ID << 5;
	RXF4SIDH = CAN_ID >> 3;
	RXF4SIDL = CAN_ID << 5;
	RXF5SIDH = CAN_ID >> 3;
	RXF5SIDL = CAN_ID << 5;
#endif
	/* Reset receivers */
	RXB0CONbits.RB0DBEN = CAN_DOUBLE_BUFFER_RX;
	RXB0CONbits.RXFUL = 0;
	RXB1CONbits.RXFUL = 0;

	/* Set bit rate */
	BRGCON1 = CAN_BRG1;
	BRGCON2 = CAN_BRG2;
	BRGCON3 = CAN_BRG3;

	/* Enable CANTX */
	CIOCONbits.ENDRHI = 1;

	/* Enter normal mode */
	CANCON = 0;
	while (CANSTAT & (_OPMODE2 | _OPMODE1))
		;
}

/*
 * Can gets() from bufer n
 */
int8_t
can_gets_rxn(uint8_t *buffer, uint16_t *message_id, uint8_t rxn)
{
	uint8_t *rxb = (uint8_t *)&RXB0D0;
	uint8_t i = 0,  blen;

	/* Set window */
	if (rxn == 0)
		CANCON = CAN_WIN_RXB0;
	else if (rxn == 1)
		CANCON = CAN_WIN_RXB1;
	else
		return -1;

	/* Receive data? */
	if (!(RXB0CON & _RXFUL))
		return -1;	/* RX NOT READY */
#if 0
	/* Get filter hit */
#if CAN_DOUBLE_BUFFER_RX == 0
	if (rxn == 0)
		i = RXB0CON & _RXB0CON_FILHIT0;
	else
		i = RXB1CON & (_RXB1CON_FILHIT0 | _RXB1CON_FILHIT1 | _RXB1CON_FILHIT2);
#else
	i = RXB1CON & (_RXB1CON_FILHIT0 | _RXB1CON_FILHIT1 | _RXB1CON_FILHIT2);
#endif
#endif
	/* Get message id */
	(*message_id) = RXB0SIDH << 3;
	(*message_id) |= RXB0SIDL >> 5;

	/* Get data length code */
	blen = RXB0DLC & 0x0F;

	/* Receive input data */
	while (i < blen) {
		buffer[i] = rxb[i];
		++i;
	}

	/* Reset receiver */
	RXB0CONbits.RXFUL = 0;

	return blen;
}

/*
 * Can gets()
 */
int8_t
can_gets(uint8_t *buffer, uint16_t *message_id)
{
	static uint8_t r = 0;
	int8_t blen, i;

	/* Receive message... */
	for (i = 0; i < CAN_RING_RX; ++i) {
		blen = can_gets_rxn(buffer, message_id, r++);
		r %= CAN_RING_RX;
		if (blen != -1)
			return blen;
	}
	return -1;
}

/*
 * Can puts() to buffer n
 */
int8_t
can_puts_txn(uint8_t *buffer, uint8_t blen, uint16_t message_id, uint8_t txn)
{
	uint8_t *txb = (uint8_t *)&RXB0D0;
	int i = 0;

	/* Set window */
	if (txn == 0)
		CANCON = CAN_WIN_TXB0;
	else if (txn == 1)
		CANCON = CAN_WIN_TXB1;
	else if (txn == 2)
		CANCON = CAN_WIN_TXB2;
	else
		return -1;

	/* Write data? */
	if (RXB0CON & _TXREQ)
		return -1;	/* TX IN USE */

	/* Set standard transmit message id */
	RXB0SIDH = message_id >> 3;
	RXB0SIDL = message_id << 5;

	/* Set data length code */
	RXB0DLC = blen & 0x0F;

	/* Store output data */
	while (i < blen) {
		txb[i] = buffer[i];
		++i;
	}

	/* Mark for transmission */
	RXB0CON |= _TXREQ;

	return blen;
}

/*
 * Can puts()
 */
int8_t
can_puts(uint8_t *buffer, int8_t blen, uint16_t message_id)
{
	static uint8_t r = 0;
	int8_t slen;

	while (1) {
		slen = can_puts_txn(buffer, blen, message_id, r++);
		r %= CAN_RING_TX;
		if (slen != -1)
			break;
	}

	/* >1ms message delay for PICAN */
	delay_ms(2);
	
	return slen;
}

void
init_ports(void)
{
    ANCON0 = 0;                 // analog off
    ANCON1 = 0;                 // analog off
    ADCON0 = 0;                 // disable ADC
    ADCON1 = 0;                 // disable ADC
    ADCON2 = 0;                 // disable ADC
    CM1CON = 0;                 // disable comperator
    CM2CON = 0;                 // disable comperator
    LED_TRIS = 0;
}


/*****************************************************************************/

/*
 * Hello world! This is the MEGA DEMO 8-)
 */
void
main(void)
{
	uint8_t buffer[CAN_LEN] = {0};
	uint16_t message_id = 0;
	int8_t i = 0, j = 0;

	init_ports();

	init_uart();
	init_canbus();

	while (1) {
		/* Transmit Tx Buffer? */
		if (!TX_EOF() && (TXSTA & _TRMT)) {
			TXREG = TX_GETC();
		}

		i = can_gets(buffer, &message_id);
		if (i >= 0) {
			/*
			 * Create message for slcand
			 */

			TX_PUTC('t');

			j = message_id >> 8;
			TX_PUTC(bin2asc[j & 0x0F]);
			j = message_id & 0xFF;
			TX_PUTC(bin2asc[j & 0xF0]);
			TX_PUTC(bin2asc[j & 0x0F]);

			TX_PUTC(bin2asc[i]);

#if 0
			/* Transmit Tx Buffer? */
			if (TXSTA & _TRMT) {
				TXREG = TX_GETC();
			}
#endif 

			for (j = 0; j < i; ++j) {
				TX_PUTC(bin2asc[buffer[j] & 0xF0]);
				TX_PUTC(bin2asc[buffer[j] & 0x0F]);
			}

			TX_PUTC('\r');
		}
		LED = COMSTAT;
	}
}

/*****************************************************************************/
