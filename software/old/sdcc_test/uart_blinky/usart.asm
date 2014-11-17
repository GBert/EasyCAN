;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.4.1 #9092 (Nov  3 2014) (Linux)
; This file was generated Thu Nov  6 11:40:32 2014
;--------------------------------------------------------
; PIC16 port for the Microchip 16-bit core micros
;--------------------------------------------------------
	list	p=18f26k80
	radix	dec


;--------------------------------------------------------
; public variables in this module
;--------------------------------------------------------
	global	_init_usart
	global	_putchar
	global	_putchar_wait
	global	_print_hex_wait
	global	_puts_rom
	global	_print_debug_value
	global	_print_debug_fifo
	global	_putchar_fifo
	global	_fifo_getchar
	global	_fifo_putchar
	global	_puts_rom_fifo
	global	_copy_char_fifo
	global	_sData

;--------------------------------------------------------
; extern variables in this module
;--------------------------------------------------------
	extern	__gptrget1
	extern	__gptrput1
	extern	_RXERRCNTbits
	extern	_TXERRCNTbits
	extern	_BRGCON1bits
	extern	_BRGCON2bits
	extern	_BRGCON3bits
	extern	_RXFCON0bits
	extern	_RXFCON1bits
	extern	_RXF6SIDHbits
	extern	_RXF6SIDLbits
	extern	_RXF6EIDHbits
	extern	_RXF6EIDLbits
	extern	_RXF7SIDHbits
	extern	_RXF7SIDLbits
	extern	_RXF7EIDHbits
	extern	_RXF7EIDLbits
	extern	_RXF8SIDHbits
	extern	_RXF8SIDLbits
	extern	_RXF8EIDHbits
	extern	_RXF8EIDLbits
	extern	_RXF9SIDHbits
	extern	_RXF9SIDLbits
	extern	_RXF9EIDHbits
	extern	_RXF9EIDLbits
	extern	_RXF10SIDHbits
	extern	_RXF10SIDLbits
	extern	_RXF10EIDHbits
	extern	_RXF10EIDLbits
	extern	_RXF11SIDHbits
	extern	_RXF11SIDLbits
	extern	_RXF11EIDHbits
	extern	_RXF11EIDLbits
	extern	_RXF12SIDHbits
	extern	_RXF12SIDLbits
	extern	_RXF12EIDHbits
	extern	_RXF12EIDLbits
	extern	_RXF13SIDHbits
	extern	_RXF13SIDLbits
	extern	_RXF13EIDHbits
	extern	_RXF13EIDLbits
	extern	_RXF14SIDHbits
	extern	_RXF14SIDLbits
	extern	_RXF14EIDHbits
	extern	_RXF14EIDLbits
	extern	_RXF15SIDHbits
	extern	_RXF15SIDLbits
	extern	_RXF15EIDHbits
	extern	_RXF15EIDLbits
	extern	_SDFLCbits
	extern	_RXFBCON0bits
	extern	_RXFBCON1bits
	extern	_RXFBCON2bits
	extern	_RXFBCON3bits
	extern	_RXFBCON4bits
	extern	_RXFBCON5bits
	extern	_RXFBCON6bits
	extern	_RXFBCON7bits
	extern	_MSEL0bits
	extern	_MSEL1bits
	extern	_MSEL2bits
	extern	_MSEL3bits
	extern	_BSEL0bits
	extern	_BIE0bits
	extern	_TXBIEbits
	extern	_B0CONbits
	extern	_B0SIDHbits
	extern	_B0SIDLbits
	extern	_B0EIDHbits
	extern	_B0EIDLbits
	extern	_B0DLCbits
	extern	_B0D0bits
	extern	_B0D1bits
	extern	_B0D2bits
	extern	_B0D3bits
	extern	_B0D4bits
	extern	_B0D5bits
	extern	_B0D6bits
	extern	_B0D7bits
	extern	_CANSTAT_RO9bits
	extern	_CANCON_RO9bits
	extern	_B1CONbits
	extern	_B1SIDHbits
	extern	_B1SIDLbits
	extern	_B1EIDHbits
	extern	_B1EIDLbits
	extern	_B1DLCbits
	extern	_B1D0bits
	extern	_B1D1bits
	extern	_B1D2bits
	extern	_B1D3bits
	extern	_B1D4bits
	extern	_B1D5bits
	extern	_B1D6bits
	extern	_B1D7bits
	extern	_CANSTAT_RO8bits
	extern	_CANCON_RO8bits
	extern	_B2CONbits
	extern	_B2SIDHbits
	extern	_B2SIDLbits
	extern	_B2EIDHbits
	extern	_B2EIDLbits
	extern	_B2DLCbits
	extern	_B2D0bits
	extern	_B2D1bits
	extern	_B2D2bits
	extern	_B2D3bits
	extern	_B2D4bits
	extern	_B2D5bits
	extern	_B2D6bits
	extern	_B2D7bits
	extern	_CANSTAT_RO7bits
	extern	_CANCON_RO7bits
	extern	_B3CONbits
	extern	_B3SIDHbits
	extern	_B3SIDLbits
	extern	_B3EIDHbits
	extern	_B3EIDLbits
	extern	_B3DLCbits
	extern	_B3D0bits
	extern	_B3D1bits
	extern	_B3D2bits
	extern	_B3D3bits
	extern	_B3D4bits
	extern	_B3D5bits
	extern	_B3D6bits
	extern	_B3D7bits
	extern	_CANSTAT_RO6bits
	extern	_CANCON_RO6bits
	extern	_B4CONbits
	extern	_B4SIDHbits
	extern	_B4SIDLbits
	extern	_B4EIDHbits
	extern	_B4EIDLbits
	extern	_B4DLCbits
	extern	_B4D0bits
	extern	_B4D1bits
	extern	_B4D2bits
	extern	_B4D3bits
	extern	_B4D4bits
	extern	_B4D5bits
	extern	_B4D6bits
	extern	_B4D7bits
	extern	_CANSTAT_RO5bits
	extern	_CANCON_RO5bits
	extern	_B5CONbits
	extern	_B5SIDHbits
	extern	_B5SIDLbits
	extern	_B5EIDHbits
	extern	_B5EIDLbits
	extern	_B5DLCbits
	extern	_B5D0bits
	extern	_B5D1bits
	extern	_B5D2bits
	extern	_B5D3bits
	extern	_B5D4bits
	extern	_B5D5bits
	extern	_B5D6bits
	extern	_B5D7bits
	extern	_CANSTAT_RO4bits
	extern	_CANCON_RO4bits
	extern	_RXF0SIDHbits
	extern	_RXF0SIDLbits
	extern	_RXF0EIDHbits
	extern	_RXF0EIDLbits
	extern	_RXF1SIDHbits
	extern	_RXF1SIDLbits
	extern	_RXF1EIDHbits
	extern	_RXF1EIDLbits
	extern	_RXF2SIDHbits
	extern	_RXF2SIDLbits
	extern	_RXF2EIDHbits
	extern	_RXF2EIDLbits
	extern	_RXF3SIDHbits
	extern	_RXF3SIDLbits
	extern	_RXF3EIDHbits
	extern	_RXF3EIDLbits
	extern	_RXF4SIDHbits
	extern	_RXF4SIDLbits
	extern	_RXF4EIDHbits
	extern	_RXF4EIDLbits
	extern	_RXF5SIDHbits
	extern	_RXF5SIDLbits
	extern	_RXF5EIDHbits
	extern	_RXF5EIDLbits
	extern	_RXM0SIDHbits
	extern	_RXM0SIDLbits
	extern	_RXM0EIDHbits
	extern	_RXM0EIDLbits
	extern	_RXM1SIDHbits
	extern	_RXM1SIDLbits
	extern	_RXM1EIDHbits
	extern	_RXM1EIDLbits
	extern	_TXB2CONbits
	extern	_TXB2SIDHbits
	extern	_TXB2SIDLbits
	extern	_TXB2EIDHbits
	extern	_TXB2EIDLbits
	extern	_TXB2DLCbits
	extern	_TXB2D0bits
	extern	_TXB2D1bits
	extern	_TXB2D2bits
	extern	_TXB2D3bits
	extern	_TXB2D4bits
	extern	_TXB2D5bits
	extern	_TXB2D6bits
	extern	_TXB2D7bits
	extern	_CANSTAT_RO3bits
	extern	_CANCON_RO3bits
	extern	_TXB1CONbits
	extern	_TXB1SIDHbits
	extern	_TXB1SIDLbits
	extern	_TXB1EIDHbits
	extern	_TXB1EIDLbits
	extern	_TXB1DLCbits
	extern	_TXB1D0bits
	extern	_TXB1D1bits
	extern	_TXB1D2bits
	extern	_TXB1D3bits
	extern	_TXB1D4bits
	extern	_TXB1D5bits
	extern	_TXB1D6bits
	extern	_TXB1D7bits
	extern	_CANSTAT_RO2bits
	extern	_CANCON_RO2bits
	extern	_TXB0CONbits
	extern	_TXB0SIDHbits
	extern	_TXB0SIDLbits
	extern	_TXB0EIDHbits
	extern	_TXB0EIDLbits
	extern	_TXB0DLCbits
	extern	_TXB0D0bits
	extern	_TXB0D1bits
	extern	_TXB0D2bits
	extern	_TXB0D3bits
	extern	_TXB0D4bits
	extern	_TXB0D5bits
	extern	_TXB0D6bits
	extern	_TXB0D7bits
	extern	_CANSTAT_RO1bits
	extern	_CANCON_RO1bits
	extern	_RXB1CONbits
	extern	_RXB1SIDHbits
	extern	_RXB1SIDLbits
	extern	_RXB1EIDHbits
	extern	_RXB1EIDLbits
	extern	_RXB1DLCbits
	extern	_RXB1D0bits
	extern	_RXB1D1bits
	extern	_RXB1D2bits
	extern	_RXB1D3bits
	extern	_RXB1D4bits
	extern	_RXB1D5bits
	extern	_RXB1D6bits
	extern	_RXB1D7bits
	extern	_CANSTAT_RO0bits
	extern	_CANCON_RO0bits
	extern	_CCP5CONbits
	extern	_CCP4CONbits
	extern	_CCP3CONbits
	extern	_CCP2CONbits
	extern	_ECCP2CONbits
	extern	_CTMUICONbits
	extern	_CTMUCONLbits
	extern	_CTMUCONHbits
	extern	_PADCFG1bits
	extern	_PMD2bits
	extern	_PMD1bits
	extern	_PMD0bits
	extern	_IOCBbits
	extern	_WPUBbits
	extern	_ANCON1bits
	extern	_ANCON0bits
	extern	_CM2CONbits
	extern	_CM2CON1bits
	extern	_CM1CONbits
	extern	_CM1CON1bits
	extern	_RXB0CONbits
	extern	_RXB0SIDHbits
	extern	_RXB0SIDLbits
	extern	_RXB0EIDHbits
	extern	_RXB0EIDLbits
	extern	_RXB0DLCbits
	extern	_RXB0D0bits
	extern	_RXB0D1bits
	extern	_RXB0D2bits
	extern	_RXB0D3bits
	extern	_RXB0D4bits
	extern	_RXB0D5bits
	extern	_RXB0D6bits
	extern	_RXB0D7bits
	extern	_CANSTATbits
	extern	_CANCONbits
	extern	_CIOCONbits
	extern	_COMSTATbits
	extern	_ECANCONbits
	extern	_PIE5bits
	extern	_PIR5bits
	extern	_IPR5bits
	extern	_EECON1bits
	extern	_PORTAbits
	extern	_PORTBbits
	extern	_PORTCbits
	extern	_PORTEbits
	extern	_T4CONbits
	extern	_LATAbits
	extern	_LATBbits
	extern	_LATCbits
	extern	_SLRCONbits
	extern	_ODCONbits
	extern	_TRISAbits
	extern	_TRISBbits
	extern	_TRISCbits
	extern	_CCPTMRSbits
	extern	_REFOCONbits
	extern	_OSCTUNEbits
	extern	_PSTR1CONbits
	extern	_PIE1bits
	extern	_PIR1bits
	extern	_IPR1bits
	extern	_PIE2bits
	extern	_PIR2bits
	extern	_IPR2bits
	extern	_PIE3bits
	extern	_PIR3bits
	extern	_IPR3bits
	extern	_RCSTA2bits
	extern	_BAUDCON1bits
	extern	_HLVDCONbits
	extern	_T1GCONbits
	extern	_RCSTAbits
	extern	_RCSTA1bits
	extern	_TXSTAbits
	extern	_TXSTA1bits
	extern	_T3GCONbits
	extern	_T3CONbits
	extern	_CMSTATbits
	extern	_CMSTATUSbits
	extern	_CVRCONbits
	extern	_PIE4bits
	extern	_PIR4bits
	extern	_IPR4bits
	extern	_BAUDCON2bits
	extern	_TXSTA2bits
	extern	_CCP1CONbits
	extern	_ECCP1CONbits
	extern	_ECCP1DELbits
	extern	_PWM1CONbits
	extern	_ECCP1ASbits
	extern	_ADCON2bits
	extern	_ADCON1bits
	extern	_ADCON0bits
	extern	_SSPCON2bits
	extern	_SSPCON1bits
	extern	_SSPSTATbits
	extern	_SSPADDbits
	extern	_T2CONbits
	extern	_T1CONbits
	extern	_RCONbits
	extern	_WDTCONbits
	extern	_OSCCON2bits
	extern	_OSCCONbits
	extern	_T0CONbits
	extern	_STATUSbits
	extern	_INTCON3bits
	extern	_INTCON2bits
	extern	_INTCONbits
	extern	_INTCON1bits
	extern	_STKPTRbits
	extern	_RXERRCNT
	extern	_TXERRCNT
	extern	_BRGCON1
	extern	_BRGCON2
	extern	_BRGCON3
	extern	_RXFCON0
	extern	_RXFCON1
	extern	_RXF6SIDH
	extern	_RXF6SIDL
	extern	_RXF6EIDH
	extern	_RXF6EIDL
	extern	_RXF7SIDH
	extern	_RXF7SIDL
	extern	_RXF7EIDH
	extern	_RXF7EIDL
	extern	_RXF8SIDH
	extern	_RXF8SIDL
	extern	_RXF8EIDH
	extern	_RXF8EIDL
	extern	_RXF9SIDH
	extern	_RXF9SIDL
	extern	_RXF9EIDH
	extern	_RXF9EIDL
	extern	_RXF10SIDH
	extern	_RXF10SIDL
	extern	_RXF10EIDH
	extern	_RXF10EIDL
	extern	_RXF11SIDH
	extern	_RXF11SIDL
	extern	_RXF11EIDH
	extern	_RXF11EIDL
	extern	_RXF12SIDH
	extern	_RXF12SIDL
	extern	_RXF12EIDH
	extern	_RXF12EIDL
	extern	_RXF13SIDH
	extern	_RXF13SIDL
	extern	_RXF13EIDH
	extern	_RXF13EIDL
	extern	_RXF14SIDH
	extern	_RXF14SIDL
	extern	_RXF14EIDH
	extern	_RXF14EIDL
	extern	_RXF15SIDH
	extern	_RXF15SIDL
	extern	_RXF15EIDH
	extern	_RXF15EIDL
	extern	_SDFLC
	extern	_RXFBCON0
	extern	_RXFBCON1
	extern	_RXFBCON2
	extern	_RXFBCON3
	extern	_RXFBCON4
	extern	_RXFBCON5
	extern	_RXFBCON6
	extern	_RXFBCON7
	extern	_MSEL0
	extern	_MSEL1
	extern	_MSEL2
	extern	_MSEL3
	extern	_BSEL0
	extern	_BIE0
	extern	_TXBIE
	extern	_B0CON
	extern	_B0SIDH
	extern	_B0SIDL
	extern	_B0EIDH
	extern	_B0EIDL
	extern	_B0DLC
	extern	_B0D0
	extern	_B0D1
	extern	_B0D2
	extern	_B0D3
	extern	_B0D4
	extern	_B0D5
	extern	_B0D6
	extern	_B0D7
	extern	_CANSTAT_RO9
	extern	_CANCON_RO9
	extern	_B1CON
	extern	_B1SIDH
	extern	_B1SIDL
	extern	_B1EIDH
	extern	_B1EIDL
	extern	_B1DLC
	extern	_B1D0
	extern	_B1D1
	extern	_B1D2
	extern	_B1D3
	extern	_B1D4
	extern	_B1D5
	extern	_B1D6
	extern	_B1D7
	extern	_CANSTAT_RO8
	extern	_CANCON_RO8
	extern	_B2CON
	extern	_B2SIDH
	extern	_B2SIDL
	extern	_B2EIDH
	extern	_B2EIDL
	extern	_B2DLC
	extern	_B2D0
	extern	_B2D1
	extern	_B2D2
	extern	_B2D3
	extern	_B2D4
	extern	_B2D5
	extern	_B2D6
	extern	_B2D7
	extern	_CANSTAT_RO7
	extern	_CANCON_RO7
	extern	_B3CON
	extern	_B3SIDH
	extern	_B3SIDL
	extern	_B3EIDH
	extern	_B3EIDL
	extern	_B3DLC
	extern	_B3D0
	extern	_B3D1
	extern	_B3D2
	extern	_B3D3
	extern	_B3D4
	extern	_B3D5
	extern	_B3D6
	extern	_B3D7
	extern	_CANSTAT_RO6
	extern	_CANCON_RO6
	extern	_B4CON
	extern	_B4SIDH
	extern	_B4SIDL
	extern	_B4EIDH
	extern	_B4EIDL
	extern	_B4DLC
	extern	_B4D0
	extern	_B4D1
	extern	_B4D2
	extern	_B4D3
	extern	_B4D4
	extern	_B4D5
	extern	_B4D6
	extern	_B4D7
	extern	_CANSTAT_RO5
	extern	_CANCON_RO5
	extern	_B5CON
	extern	_B5SIDH
	extern	_B5SIDL
	extern	_B5EIDH
	extern	_B5EIDL
	extern	_B5DLC
	extern	_B5D0
	extern	_B5D1
	extern	_B5D2
	extern	_B5D3
	extern	_B5D4
	extern	_B5D5
	extern	_B5D6
	extern	_B5D7
	extern	_CANSTAT_RO4
	extern	_CANCON_RO4
	extern	_RXF0SIDH
	extern	_RXF0SIDL
	extern	_RXF0EIDH
	extern	_RXF0EIDL
	extern	_RXF1SIDH
	extern	_RXF1SIDL
	extern	_RXF1EIDH
	extern	_RXF1EIDL
	extern	_RXF2SIDH
	extern	_RXF2SIDL
	extern	_RXF2EIDH
	extern	_RXF2EIDL
	extern	_RXF3SIDH
	extern	_RXF3SIDL
	extern	_RXF3EIDH
	extern	_RXF3EIDL
	extern	_RXF4SIDH
	extern	_RXF4SIDL
	extern	_RXF4EIDH
	extern	_RXF4EIDL
	extern	_RXF5SIDH
	extern	_RXF5SIDL
	extern	_RXF5EIDH
	extern	_RXF5EIDL
	extern	_RXM0SIDH
	extern	_RXM0SIDL
	extern	_RXM0EIDH
	extern	_RXM0EIDL
	extern	_RXM1SIDH
	extern	_RXM1SIDL
	extern	_RXM1EIDH
	extern	_RXM1EIDL
	extern	_TXB2CON
	extern	_TXB2SIDH
	extern	_TXB2SIDL
	extern	_TXB2EIDH
	extern	_TXB2EIDL
	extern	_TXB2DLC
	extern	_TXB2D0
	extern	_TXB2D1
	extern	_TXB2D2
	extern	_TXB2D3
	extern	_TXB2D4
	extern	_TXB2D5
	extern	_TXB2D6
	extern	_TXB2D7
	extern	_CANSTAT_RO3
	extern	_CANCON_RO3
	extern	_TXB1CON
	extern	_TXB1SIDH
	extern	_TXB1SIDL
	extern	_TXB1EIDH
	extern	_TXB1EIDL
	extern	_TXB1DLC
	extern	_TXB1D0
	extern	_TXB1D1
	extern	_TXB1D2
	extern	_TXB1D3
	extern	_TXB1D4
	extern	_TXB1D5
	extern	_TXB1D6
	extern	_TXB1D7
	extern	_CANSTAT_RO2
	extern	_CANCON_RO2
	extern	_TXB0CON
	extern	_TXB0SIDH
	extern	_TXB0SIDL
	extern	_TXB0EIDH
	extern	_TXB0EIDL
	extern	_TXB0DLC
	extern	_TXB0D0
	extern	_TXB0D1
	extern	_TXB0D2
	extern	_TXB0D3
	extern	_TXB0D4
	extern	_TXB0D5
	extern	_TXB0D6
	extern	_TXB0D7
	extern	_CANSTAT_RO1
	extern	_CANCON_RO1
	extern	_RXB1CON
	extern	_RXB1SIDH
	extern	_RXB1SIDL
	extern	_RXB1EIDH
	extern	_RXB1EIDL
	extern	_RXB1DLC
	extern	_RXB1D0
	extern	_RXB1D1
	extern	_RXB1D2
	extern	_RXB1D3
	extern	_RXB1D4
	extern	_RXB1D5
	extern	_RXB1D6
	extern	_RXB1D7
	extern	_CANSTAT_RO0
	extern	_CANCON_RO0
	extern	_CCP5CON
	extern	_CCPR5
	extern	_CCPR5L
	extern	_CCPR5H
	extern	_CCP4CON
	extern	_CCPR4
	extern	_CCPR4L
	extern	_CCPR4H
	extern	_CCP3CON
	extern	_CCPR3
	extern	_CCPR3L
	extern	_CCPR3H
	extern	_CCP2CON
	extern	_ECCP2CON
	extern	_CCPR2
	extern	_CCPR2L
	extern	_CCPR2H
	extern	_CTMUICON
	extern	_CTMUCONL
	extern	_CTMUCONH
	extern	_PADCFG1
	extern	_PMD2
	extern	_PMD1
	extern	_PMD0
	extern	_IOCB
	extern	_WPUB
	extern	_ANCON1
	extern	_ANCON0
	extern	_CM2CON
	extern	_CM2CON1
	extern	_CM1CON
	extern	_CM1CON1
	extern	_RXB0CON
	extern	_RXB0SIDH
	extern	_RXB0SIDL
	extern	_RXB0EIDH
	extern	_RXB0EIDL
	extern	_RXB0DLC
	extern	_RXB0D0
	extern	_RXB0D1
	extern	_RXB0D2
	extern	_RXB0D3
	extern	_RXB0D4
	extern	_RXB0D5
	extern	_RXB0D6
	extern	_RXB0D7
	extern	_CANSTAT
	extern	_CANCON
	extern	_CIOCON
	extern	_COMSTAT
	extern	_ECANCON
	extern	_EEDATA
	extern	_EEADR
	extern	_EEADRH
	extern	_PIE5
	extern	_PIR5
	extern	_IPR5
	extern	_TXREG2
	extern	_RCREG2
	extern	_SPBRG2
	extern	_SPBRGH2
	extern	_SPBRGH1
	extern	_EECON2
	extern	_EECON1
	extern	_PORTA
	extern	_PORTB
	extern	_PORTC
	extern	_PORTE
	extern	_TMR4
	extern	_T4CON
	extern	_LATA
	extern	_LATB
	extern	_LATC
	extern	_SLRCON
	extern	_ODCON
	extern	_TRISA
	extern	_TRISB
	extern	_TRISC
	extern	_CCPTMRS
	extern	_REFOCON
	extern	_OSCTUNE
	extern	_PSTR1CON
	extern	_PIE1
	extern	_PIR1
	extern	_IPR1
	extern	_PIE2
	extern	_PIR2
	extern	_IPR2
	extern	_PIE3
	extern	_PIR3
	extern	_IPR3
	extern	_RCSTA2
	extern	_BAUDCON1
	extern	_HLVDCON
	extern	_PR4
	extern	_T1GCON
	extern	_RCSTA
	extern	_RCSTA1
	extern	_TXSTA
	extern	_TXSTA1
	extern	_TXREG
	extern	_TXREG1
	extern	_RCREG
	extern	_RCREG1
	extern	_SPBRG
	extern	_SPBRG1
	extern	_T3GCON
	extern	_T3CON
	extern	_TMR3
	extern	_TMR3L
	extern	_TMR3H
	extern	_CMSTAT
	extern	_CMSTATUS
	extern	_CVRCON
	extern	_PIE4
	extern	_PIR4
	extern	_IPR4
	extern	_BAUDCON2
	extern	_TXSTA2
	extern	_CCP1CON
	extern	_ECCP1CON
	extern	_CCPR1
	extern	_CCPR1L
	extern	_CCPR1H
	extern	_ECCP1DEL
	extern	_PWM1CON
	extern	_ECCP1AS
	extern	_ADCON2
	extern	_ADCON1
	extern	_ADCON0
	extern	_ADRES
	extern	_ADRESL
	extern	_ADRESH
	extern	_SSPCON2
	extern	_SSPCON1
	extern	_SSPSTAT
	extern	_SSPADD
	extern	_SSPBUF
	extern	_T2CON
	extern	_PR2
	extern	_TMR2
	extern	_T1CON
	extern	_TMR1
	extern	_TMR1L
	extern	_TMR1H
	extern	_RCON
	extern	_WDTCON
	extern	_OSCCON2
	extern	_OSCCON
	extern	_T0CON
	extern	_TMR0
	extern	_TMR0L
	extern	_TMR0H
	extern	_STATUS
	extern	_FSR2L
	extern	_FSR2H
	extern	_PLUSW2
	extern	_PREINC2
	extern	_POSTDEC2
	extern	_POSTINC2
	extern	_INDF2
	extern	_BSR
	extern	_FSR1L
	extern	_FSR1H
	extern	_PLUSW1
	extern	_PREINC1
	extern	_POSTDEC1
	extern	_POSTINC1
	extern	_INDF1
	extern	_WREG
	extern	_FSR0L
	extern	_FSR0H
	extern	_PLUSW0
	extern	_PREINC0
	extern	_POSTDEC0
	extern	_POSTINC0
	extern	_INDF0
	extern	_INTCON3
	extern	_INTCON2
	extern	_INTCON
	extern	_INTCON1
	extern	_PROD
	extern	_PRODL
	extern	_PRODH
	extern	_TABLAT
	extern	_TBLPTR
	extern	_TBLPTRL
	extern	_TBLPTRH
	extern	_TBLPTRU
	extern	_PC
	extern	_PCL
	extern	_PCLATH
	extern	_PCLATU
	extern	_STKPTR
	extern	_TOS
	extern	_TOSL
	extern	_TOSH
	extern	_TOSU

;--------------------------------------------------------
;	Equates to used internal registers
;--------------------------------------------------------
STATUS	equ	0xfd8
WREG	equ	0xfe8
FSR0L	equ	0xfe9
FSR1L	equ	0xfe1
FSR2L	equ	0xfd9
POSTINC1	equ	0xfe6
POSTDEC1	equ	0xfe5
PREINC1	equ	0xfe4
PLUSW2	equ	0xfdb
PRODL	equ	0xff3


; Internal registers
.registers	udata_ovr	0x0000
r0x00	res	1
r0x01	res	1
r0x02	res	1
r0x03	res	1
r0x04	res	1
r0x05	res	1
r0x06	res	1
r0x07	res	1
r0x08	res	1
r0x09	res	1
r0x0a	res	1
r0x0b	res	1
r0x0c	res	1
r0x0d	res	1
r0x0e	res	1
r0x0f	res	1
r0x10	res	1
r0x11	res	1
r0x12	res	1
r0x13	res	1
r0x14	res	1
r0x15	res	1
r0x16	res	1
r0x17	res	1
r0x18	res	1
r0x19	res	1

;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
; I code from now on!
; ; Starting pCode block
S_usart__copy_char_fifo	code
_copy_char_fifo:
;	.line	172; usart.c	char copy_char_fifo(struct serial_buffer * source_fifo, struct serial_buffer * destination_fifo) {
	MOVFF	FSR2L, POSTDEC1
	MOVFF	FSR1L, FSR2L
	MOVFF	r0x00, POSTDEC1
	MOVFF	r0x01, POSTDEC1
	MOVFF	r0x02, POSTDEC1
	MOVFF	r0x03, POSTDEC1
	MOVFF	r0x04, POSTDEC1
	MOVFF	r0x05, POSTDEC1
	MOVFF	r0x06, POSTDEC1
	MOVFF	r0x07, POSTDEC1
	MOVFF	r0x08, POSTDEC1
	MOVFF	r0x09, POSTDEC1
	MOVFF	r0x0a, POSTDEC1
	MOVFF	r0x0b, POSTDEC1
	MOVFF	r0x0c, POSTDEC1
	MOVFF	r0x0d, POSTDEC1
	MOVFF	r0x0e, POSTDEC1
	MOVFF	r0x0f, POSTDEC1
	MOVFF	r0x10, POSTDEC1
	MOVFF	r0x11, POSTDEC1
	MOVFF	r0x12, POSTDEC1
	MOVFF	r0x13, POSTDEC1
	MOVFF	r0x14, POSTDEC1
	MOVFF	r0x15, POSTDEC1
	MOVFF	r0x16, POSTDEC1
	MOVFF	r0x17, POSTDEC1
	MOVFF	r0x18, POSTDEC1
	MOVFF	r0x19, POSTDEC1
	MOVLW	0x02
	MOVFF	PLUSW2, r0x00
	MOVLW	0x03
	MOVFF	PLUSW2, r0x01
	MOVLW	0x04
	MOVFF	PLUSW2, r0x02
	MOVLW	0x05
	MOVFF	PLUSW2, r0x03
	MOVLW	0x06
	MOVFF	PLUSW2, r0x04
	MOVLW	0x07
	MOVFF	PLUSW2, r0x05
;	.line	175; usart.c	source_tail=source_fifo->tail;
	MOVF	r0x00, W
	ADDLW	0x01
	MOVWF	r0x06
	MOVLW	0x00
	ADDWFC	r0x01, W
	MOVWF	r0x07
	MOVLW	0x00
	ADDWFC	r0x02, W
	MOVWF	r0x08
	MOVFF	r0x06, FSR0L
	MOVFF	r0x07, PRODL
	MOVF	r0x08, W
	CALL	__gptrget1
	MOVWF	r0x09
;	.line	178; usart.c	if ( source_tail == source_fifo->head) {
	MOVFF	r0x00, FSR0L
	MOVFF	r0x01, PRODL
	MOVF	r0x02, W
	CALL	__gptrget1
	MOVWF	r0x0a
	MOVF	r0x09, W
	XORWF	r0x0a, W
	BNZ	_00265_DS_
;	.line	179; usart.c	return 0;
	CLRF	WREG
	BRA	_00267_DS_
_00265_DS_:
;	.line	181; usart.c	destination_head = destination_fifo->head;
	MOVFF	r0x03, FSR0L
	MOVFF	r0x04, PRODL
	MOVF	r0x05, W
	CALL	__gptrget1
	MOVWF	r0x0a
;	.line	182; usart.c	destination_head++;
	INCF	r0x0a, F
;	.line	183; usart.c	destination_head &= SERIAL_BUFFER_SIZE_MASK;
	MOVLW	0x3f
	ANDWF	r0x0a, F
;	.line	184; usart.c	while ((destination_head !=  destination_fifo->tail) && (source_tail != source_fifo->head)) {
	MOVF	r0x03, W
	ADDLW	0x02
	MOVWF	r0x0b
	MOVLW	0x00
	ADDWFC	r0x04, W
	MOVWF	r0x0c
	MOVLW	0x00
	ADDWFC	r0x05, W
	MOVWF	r0x0d
	MOVF	r0x00, W
	ADDLW	0x02
	MOVWF	r0x0e
	MOVLW	0x00
	ADDWFC	r0x01, W
	MOVWF	r0x0f
	MOVLW	0x00
	ADDWFC	r0x02, W
	MOVWF	r0x10
	MOVF	r0x03, W
	ADDLW	0x01
	MOVWF	r0x11
	MOVLW	0x00
	ADDWFC	r0x04, W
	MOVWF	r0x12
	MOVLW	0x00
	ADDWFC	r0x05, W
	MOVWF	r0x13
_00261_DS_:
	MOVFF	r0x11, FSR0L
	MOVFF	r0x12, PRODL
	MOVF	r0x13, W
	CALL	__gptrget1
	MOVWF	r0x14
	MOVF	r0x0a, W
	XORWF	r0x14, W
	BNZ	_00285_DS_
	BRA	_00263_DS_
_00285_DS_:
	MOVFF	r0x00, FSR0L
	MOVFF	r0x01, PRODL
	MOVF	r0x02, W
	CALL	__gptrget1
	MOVWF	r0x14
	MOVF	r0x09, W
	XORWF	r0x14, W
	BZ	_00263_DS_
;	.line	185; usart.c	source_tail++;
	INCF	r0x09, F
;	.line	186; usart.c	source_tail &= SERIAL_BUFFER_SIZE_MASK;
	MOVLW	0x3f
	ANDWF	r0x09, F
;	.line	187; usart.c	destination_fifo->data[destination_head] = source_fifo->data[source_tail];
	MOVF	r0x0a, W
	ADDWF	r0x0b, W
	MOVWF	r0x14
	CLRF	WREG
	ADDWFC	r0x0c, W
	MOVWF	r0x15
	CLRF	WREG
	ADDWFC	r0x0d, W
	MOVWF	r0x16
	MOVF	r0x09, W
	ADDWF	r0x0e, W
	MOVWF	r0x17
	CLRF	WREG
	ADDWFC	r0x0f, W
	MOVWF	r0x18
	CLRF	WREG
	ADDWFC	r0x10, W
	MOVWF	r0x19
	MOVFF	r0x17, FSR0L
	MOVFF	r0x18, PRODL
	MOVF	r0x19, W
	CALL	__gptrget1
	MOVWF	r0x17
	MOVFF	r0x17, POSTDEC1
	MOVFF	r0x14, FSR0L
	MOVFF	r0x15, PRODL
	MOVF	r0x16, W
	CALL	__gptrput1
;	.line	188; usart.c	destination_fifo->head = destination_head;		/* store new pointer destination head before increment*/
	MOVFF	r0x0a, POSTDEC1
	MOVFF	r0x03, FSR0L
	MOVFF	r0x04, PRODL
	MOVF	r0x05, W
	CALL	__gptrput1
;	.line	189; usart.c	destination_head++;
	INCF	r0x0a, F
;	.line	190; usart.c	destination_head &= SERIAL_BUFFER_SIZE_MASK;
	MOVLW	0x3f
	ANDWF	r0x0a, F
	BRA	_00261_DS_
_00263_DS_:
;	.line	192; usart.c	source_fifo->tail      = source_tail;			/* store new pointer source tail */
	MOVFF	r0x09, POSTDEC1
	MOVFF	r0x06, FSR0L
	MOVFF	r0x07, PRODL
	MOVF	r0x08, W
	CALL	__gptrput1
;	.line	193; usart.c	return source_fifo->data[source_tail];
	CLRF	r0x00
	CLRF	r0x01
	MOVF	r0x0e, W
	ADDWF	r0x09, F
	MOVF	r0x0f, W
	ADDWFC	r0x00, F
	MOVF	r0x10, W
	ADDWFC	r0x01, F
	MOVFF	r0x09, FSR0L
	MOVFF	r0x00, PRODL
	MOVF	r0x01, W
	CALL	__gptrget1
	MOVWF	r0x09
	MOVF	r0x09, W
_00267_DS_:
	MOVFF	PREINC1, r0x19
	MOVFF	PREINC1, r0x18
	MOVFF	PREINC1, r0x17
	MOVFF	PREINC1, r0x16
	MOVFF	PREINC1, r0x15
	MOVFF	PREINC1, r0x14
	MOVFF	PREINC1, r0x13
	MOVFF	PREINC1, r0x12
	MOVFF	PREINC1, r0x11
	MOVFF	PREINC1, r0x10
	MOVFF	PREINC1, r0x0f
	MOVFF	PREINC1, r0x0e
	MOVFF	PREINC1, r0x0d
	MOVFF	PREINC1, r0x0c
	MOVFF	PREINC1, r0x0b
	MOVFF	PREINC1, r0x0a
	MOVFF	PREINC1, r0x09
	MOVFF	PREINC1, r0x08
	MOVFF	PREINC1, r0x07
	MOVFF	PREINC1, r0x06
	MOVFF	PREINC1, r0x05
	MOVFF	PREINC1, r0x04
	MOVFF	PREINC1, r0x03
	MOVFF	PREINC1, r0x02
	MOVFF	PREINC1, r0x01
	MOVFF	PREINC1, r0x00
	MOVFF	PREINC1, FSR2L
	RETURN	

; ; Starting pCode block
S_usart__puts_rom_fifo	code
_puts_rom_fifo:
;	.line	156; usart.c	char puts_rom_fifo(const char * s, struct serial_buffer * fifo) {
	MOVFF	FSR2L, POSTDEC1
	MOVFF	FSR1L, FSR2L
	MOVFF	r0x00, POSTDEC1
	MOVFF	r0x01, POSTDEC1
	MOVFF	r0x02, POSTDEC1
	MOVFF	r0x03, POSTDEC1
	MOVFF	r0x04, POSTDEC1
	MOVFF	r0x05, POSTDEC1
	MOVFF	r0x06, POSTDEC1
	MOVFF	r0x07, POSTDEC1
	MOVFF	r0x08, POSTDEC1
	MOVFF	r0x09, POSTDEC1
	MOVFF	r0x0a, POSTDEC1
	MOVFF	r0x0b, POSTDEC1
	MOVFF	r0x0c, POSTDEC1
	MOVFF	r0x0d, POSTDEC1
	MOVFF	r0x0e, POSTDEC1
	MOVFF	r0x0f, POSTDEC1
	MOVFF	r0x10, POSTDEC1
	MOVLW	0x02
	MOVFF	PLUSW2, r0x00
	MOVLW	0x03
	MOVFF	PLUSW2, r0x01
	MOVLW	0x04
	MOVFF	PLUSW2, r0x02
	MOVLW	0x05
	MOVFF	PLUSW2, r0x03
	MOVLW	0x06
	MOVFF	PLUSW2, r0x04
	MOVLW	0x07
	MOVFF	PLUSW2, r0x05
;	.line	157; usart.c	unsigned char head=fifo->head;
	MOVFF	r0x03, FSR0L
	MOVFF	r0x04, PRODL
	MOVF	r0x05, W
	CALL	__gptrget1
	MOVWF	r0x06
;	.line	159; usart.c	while ( ( c = *s++ ) ) {
	MOVF	r0x03, W
	ADDLW	0x01
	MOVWF	r0x07
	MOVLW	0x00
	ADDWFC	r0x04, W
	MOVWF	r0x08
	MOVLW	0x00
	ADDWFC	r0x05, W
	MOVWF	r0x09
	MOVF	r0x03, W
	ADDLW	0x02
	MOVWF	r0x0a
	MOVLW	0x00
	ADDWFC	r0x04, W
	MOVWF	r0x0b
	MOVLW	0x00
	ADDWFC	r0x05, W
	MOVWF	r0x0c
_00238_DS_:
	MOVFF	r0x00, FSR0L
	MOVFF	r0x01, PRODL
	MOVF	r0x02, W
	CALL	__gptrget1
	MOVWF	r0x0d
	INCF	r0x00, F
	BNC	_00252_DS_
	INFSNZ	r0x01, F
	INCF	r0x02, F
_00252_DS_:
	MOVFF	r0x0d, r0x0e
	MOVF	r0x0d, W
	BZ	_00240_DS_
;	.line	160; usart.c	head++;
	INCF	r0x06, F
;	.line	161; usart.c	head &= SERIAL_BUFFER_SIZE_MASK;	/* wrap around if neededd */
	MOVLW	0x3f
	ANDWF	r0x06, F
;	.line	162; usart.c	if (head != fifo->tail) {		/* space left ? */ 
	MOVFF	r0x07, FSR0L
	MOVFF	r0x08, PRODL
	MOVF	r0x09, W
	CALL	__gptrget1
	MOVWF	r0x0d
	MOVF	r0x06, W
	XORWF	r0x0d, W
	BZ	_00236_DS_
;	.line	163; usart.c	fifo->data[head]=c;
	MOVF	r0x06, W
	ADDWF	r0x0a, W
	MOVWF	r0x0d
	CLRF	WREG
	ADDWFC	r0x0b, W
	MOVWF	r0x0f
	CLRF	WREG
	ADDWFC	r0x0c, W
	MOVWF	r0x10
	MOVFF	r0x0e, POSTDEC1
	MOVFF	r0x0d, FSR0L
	MOVFF	r0x0f, PRODL
	MOVF	r0x10, W
	CALL	__gptrput1
	BRA	_00238_DS_
_00236_DS_:
;	.line	165; usart.c	return -1;
	SETF	WREG
	BRA	_00241_DS_
_00240_DS_:
;	.line	168; usart.c	fifo->head=head;				/* only store new pointer if all is OK */
	MOVFF	r0x06, POSTDEC1
	MOVFF	r0x03, FSR0L
	MOVFF	r0x04, PRODL
	MOVF	r0x05, W
	CALL	__gptrput1
;	.line	169; usart.c	return 1;
	MOVLW	0x01
_00241_DS_:
	MOVFF	PREINC1, r0x10
	MOVFF	PREINC1, r0x0f
	MOVFF	PREINC1, r0x0e
	MOVFF	PREINC1, r0x0d
	MOVFF	PREINC1, r0x0c
	MOVFF	PREINC1, r0x0b
	MOVFF	PREINC1, r0x0a
	MOVFF	PREINC1, r0x09
	MOVFF	PREINC1, r0x08
	MOVFF	PREINC1, r0x07
	MOVFF	PREINC1, r0x06
	MOVFF	PREINC1, r0x05
	MOVFF	PREINC1, r0x04
	MOVFF	PREINC1, r0x03
	MOVFF	PREINC1, r0x02
	MOVFF	PREINC1, r0x01
	MOVFF	PREINC1, r0x00
	MOVFF	PREINC1, FSR2L
	RETURN	

; ; Starting pCode block
S_usart__fifo_putchar	code
_fifo_putchar:
;	.line	141; usart.c	char fifo_putchar(struct serial_buffer * fifo) {
	MOVFF	FSR2L, POSTDEC1
	MOVFF	FSR1L, FSR2L
	MOVFF	r0x00, POSTDEC1
	MOVFF	r0x01, POSTDEC1
	MOVFF	r0x02, POSTDEC1
	MOVFF	r0x03, POSTDEC1
	MOVFF	r0x04, POSTDEC1
	MOVFF	r0x05, POSTDEC1
	MOVFF	r0x06, POSTDEC1
	MOVFF	r0x07, POSTDEC1
	MOVLW	0x02
	MOVFF	PLUSW2, r0x00
	MOVLW	0x03
	MOVFF	PLUSW2, r0x01
	MOVLW	0x04
	MOVFF	PLUSW2, r0x02
;	.line	143; usart.c	tail=fifo->tail;
	MOVF	r0x00, W
	ADDLW	0x01
	MOVWF	r0x03
	MOVLW	0x00
	ADDWFC	r0x01, W
	MOVWF	r0x04
	MOVLW	0x00
	ADDWFC	r0x02, W
	MOVWF	r0x05
	MOVFF	r0x03, FSR0L
	MOVFF	r0x04, PRODL
	MOVF	r0x05, W
	CALL	__gptrget1
	MOVWF	r0x06
;	.line	144; usart.c	if (fifo->head != tail) {
	MOVFF	r0x00, FSR0L
	MOVFF	r0x01, PRODL
	MOVF	r0x02, W
	CALL	__gptrget1
	MOVWF	r0x07
	MOVF	r0x07, W
	XORWF	r0x06, W
	BZ	_00220_DS_
;	.line	145; usart.c	tail++;
	INCF	r0x06, F
;	.line	146; usart.c	tail &= SERIAL_BUFFER_SIZE_MASK;	/* wrap around if neededd */
	MOVLW	0x3f
	ANDWF	r0x06, F
;	.line	147; usart.c	if (putchar(fifo->data[tail])) {
	MOVLW	0x02
	ADDWF	r0x00, F
	MOVLW	0x00
	ADDWFC	r0x01, F
	ADDWFC	r0x02, F
	MOVF	r0x06, W
	ADDWF	r0x00, F
	CLRF	WREG
	ADDWFC	r0x01, F
	CLRF	WREG
	ADDWFC	r0x02, F
	MOVFF	r0x00, FSR0L
	MOVFF	r0x01, PRODL
	MOVF	r0x02, W
	CALL	__gptrget1
	MOVWF	r0x00
	MOVF	r0x00, W
	MOVWF	POSTDEC1
	CALL	_putchar
	MOVWF	r0x00
	MOVF	POSTINC1, F
	MOVF	r0x00, W
	BZ	_00220_DS_
;	.line	148; usart.c	fifo->tail=tail;
	MOVFF	r0x06, POSTDEC1
	MOVFF	r0x03, FSR0L
	MOVFF	r0x04, PRODL
	MOVF	r0x05, W
	CALL	__gptrput1
;	.line	149; usart.c	return 1;
	MOVLW	0x01
	BRA	_00221_DS_
_00220_DS_:
;	.line	152; usart.c	return 0;
	CLRF	WREG
_00221_DS_:
	MOVFF	PREINC1, r0x07
	MOVFF	PREINC1, r0x06
	MOVFF	PREINC1, r0x05
	MOVFF	PREINC1, r0x04
	MOVFF	PREINC1, r0x03
	MOVFF	PREINC1, r0x02
	MOVFF	PREINC1, r0x01
	MOVFF	PREINC1, r0x00
	MOVFF	PREINC1, FSR2L
	RETURN	

; ; Starting pCode block
S_usart__fifo_getchar	code
_fifo_getchar:
;	.line	122; usart.c	char fifo_getchar(struct serial_buffer * fifo) {
	MOVFF	FSR2L, POSTDEC1
	MOVFF	FSR1L, FSR2L
	MOVFF	r0x00, POSTDEC1
	MOVFF	r0x01, POSTDEC1
	MOVFF	r0x02, POSTDEC1
	MOVFF	r0x03, POSTDEC1
	MOVFF	r0x04, POSTDEC1
	MOVFF	r0x05, POSTDEC1
	MOVFF	r0x06, POSTDEC1
	MOVFF	r0x07, POSTDEC1
	MOVLW	0x02
	MOVFF	PLUSW2, r0x00
	MOVLW	0x03
	MOVFF	PLUSW2, r0x01
	MOVLW	0x04
	MOVFF	PLUSW2, r0x02
;	.line	126; usart.c	if (PIR1bits.RCIF) {
	BTFSS	_PIR1bits, 5
	BRA	_00201_DS_
;	.line	127; usart.c	head=fifo->head;
	MOVFF	r0x00, FSR0L
	MOVFF	r0x01, PRODL
	MOVF	r0x02, W
	CALL	__gptrget1
	MOVWF	r0x03
;	.line	128; usart.c	head++;
	INCF	r0x03, F
;	.line	129; usart.c	head &= SERIAL_BUFFER_SIZE_MASK;	/* wrap around if neededd */
	MOVLW	0x3f
	ANDWF	r0x03, F
;	.line	130; usart.c	if (head != fifo->tail) {
	MOVF	r0x00, W
	ADDLW	0x01
	MOVWF	r0x04
	MOVLW	0x00
	ADDWFC	r0x01, W
	MOVWF	r0x05
	MOVLW	0x00
	ADDWFC	r0x02, W
	MOVWF	r0x06
	MOVFF	r0x04, FSR0L
	MOVFF	r0x05, PRODL
	MOVF	r0x06, W
	CALL	__gptrget1
	MOVWF	r0x04
	MOVF	r0x03, W
	XORWF	r0x04, W
	BZ	_00201_DS_
;	.line	131; usart.c	c=RCREG1;
	MOVFF	_RCREG1, r0x04
;	.line	132; usart.c	fifo->data[head]=c;
	MOVF	r0x00, W
	ADDLW	0x02
	MOVWF	r0x05
	MOVLW	0x00
	ADDWFC	r0x01, W
	MOVWF	r0x06
	MOVLW	0x00
	ADDWFC	r0x02, W
	MOVWF	r0x07
	MOVF	r0x03, W
	ADDWF	r0x05, F
	CLRF	WREG
	ADDWFC	r0x06, F
	CLRF	WREG
	ADDWFC	r0x07, F
	MOVFF	r0x04, POSTDEC1
	MOVFF	r0x05, FSR0L
	MOVFF	r0x06, PRODL
	MOVF	r0x07, W
	CALL	__gptrput1
;	.line	133; usart.c	fifo->head=head;
	MOVFF	r0x03, POSTDEC1
	MOVFF	r0x00, FSR0L
	MOVFF	r0x01, PRODL
	MOVF	r0x02, W
	CALL	__gptrput1
;	.line	134; usart.c	return c;
	MOVF	r0x04, W
	BRA	_00202_DS_
_00201_DS_:
;	.line	137; usart.c	return 0;
	CLRF	WREG
_00202_DS_:
	MOVFF	PREINC1, r0x07
	MOVFF	PREINC1, r0x06
	MOVFF	PREINC1, r0x05
	MOVFF	PREINC1, r0x04
	MOVFF	PREINC1, r0x03
	MOVFF	PREINC1, r0x02
	MOVFF	PREINC1, r0x01
	MOVFF	PREINC1, r0x00
	MOVFF	PREINC1, FSR2L
	RETURN	

; ; Starting pCode block
S_usart__putchar_fifo	code
_putchar_fifo:
;	.line	107; usart.c	char putchar_fifo(char c, struct serial_buffer * fifo) {
	MOVFF	FSR2L, POSTDEC1
	MOVFF	FSR1L, FSR2L
	MOVFF	r0x00, POSTDEC1
	MOVFF	r0x01, POSTDEC1
	MOVFF	r0x02, POSTDEC1
	MOVFF	r0x03, POSTDEC1
	MOVFF	r0x04, POSTDEC1
	MOVFF	r0x05, POSTDEC1
	MOVFF	r0x06, POSTDEC1
	MOVFF	r0x07, POSTDEC1
	MOVLW	0x02
	MOVFF	PLUSW2, r0x00
	MOVLW	0x03
	MOVFF	PLUSW2, r0x01
	MOVLW	0x04
	MOVFF	PLUSW2, r0x02
	MOVLW	0x05
	MOVFF	PLUSW2, r0x03
;	.line	109; usart.c	head=fifo->head;
	MOVFF	r0x01, FSR0L
	MOVFF	r0x02, PRODL
	MOVF	r0x03, W
	CALL	__gptrget1
	MOVWF	r0x04
;	.line	110; usart.c	head++;
	INCF	r0x04, F
;	.line	111; usart.c	head &= SERIAL_BUFFER_SIZE_MASK;		/* wrap around if needed */
	MOVLW	0x3f
	ANDWF	r0x04, F
;	.line	112; usart.c	if (head != fifo->tail) {
	MOVF	r0x01, W
	ADDLW	0x01
	MOVWF	r0x05
	MOVLW	0x00
	ADDWFC	r0x02, W
	MOVWF	r0x06
	MOVLW	0x00
	ADDWFC	r0x03, W
	MOVWF	r0x07
	MOVFF	r0x05, FSR0L
	MOVFF	r0x06, PRODL
	MOVF	r0x07, W
	CALL	__gptrget1
	MOVWF	r0x05
	MOVF	r0x04, W
	XORWF	r0x05, W
	BZ	_00185_DS_
;	.line	113; usart.c	fifo->head = head;
	MOVFF	r0x04, POSTDEC1
	MOVFF	r0x01, FSR0L
	MOVFF	r0x02, PRODL
	MOVF	r0x03, W
	CALL	__gptrput1
;	.line	114; usart.c	fifo->data[head] = c;
	MOVLW	0x02
	ADDWF	r0x01, F
	MOVLW	0x00
	ADDWFC	r0x02, F
	ADDWFC	r0x03, F
	CLRF	r0x05
	CLRF	r0x06
	MOVF	r0x01, W
	ADDWF	r0x04, F
	MOVF	r0x02, W
	ADDWFC	r0x05, F
	MOVF	r0x03, W
	ADDWFC	r0x06, F
	MOVFF	r0x00, POSTDEC1
	MOVFF	r0x04, FSR0L
	MOVFF	r0x05, PRODL
	MOVF	r0x06, W
	CALL	__gptrput1
;	.line	115; usart.c	return 1;
	MOVLW	0x01
	BRA	_00186_DS_
_00185_DS_:
;	.line	117; usart.c	return 0;
	CLRF	WREG
_00186_DS_:
	MOVFF	PREINC1, r0x07
	MOVFF	PREINC1, r0x06
	MOVFF	PREINC1, r0x05
	MOVFF	PREINC1, r0x04
	MOVFF	PREINC1, r0x03
	MOVFF	PREINC1, r0x02
	MOVFF	PREINC1, r0x01
	MOVFF	PREINC1, r0x00
	MOVFF	PREINC1, FSR2L
	RETURN	

; ; Starting pCode block
S_usart__print_debug_fifo	code
_print_debug_fifo:
;	.line	83; usart.c	void print_debug_fifo(struct serial_buffer * fifo) {
	MOVFF	FSR2L, POSTDEC1
	MOVFF	FSR1L, FSR2L
	MOVFF	r0x00, POSTDEC1
	MOVFF	r0x01, POSTDEC1
	MOVFF	r0x02, POSTDEC1
	MOVFF	r0x03, POSTDEC1
	MOVFF	r0x04, POSTDEC1
	MOVFF	r0x05, POSTDEC1
	MOVFF	r0x06, POSTDEC1
	MOVLW	0x02
	MOVFF	PLUSW2, r0x00
	MOVLW	0x03
	MOVFF	PLUSW2, r0x01
	MOVLW	0x04
	MOVFF	PLUSW2, r0x02
;	.line	85; usart.c	putchar_wait('\r');
	MOVLW	0x0d
	MOVWF	POSTDEC1
	CALL	_putchar_wait
	MOVF	POSTINC1, F
;	.line	86; usart.c	putchar_wait('\n');
	MOVLW	0x0a
	MOVWF	POSTDEC1
	CALL	_putchar_wait
	MOVF	POSTINC1, F
;	.line	87; usart.c	print_debug_value('S',SERIAL_BUFFER_SIZE);
	MOVLW	0x40
	MOVWF	POSTDEC1
	MOVLW	0x53
	MOVWF	POSTDEC1
	CALL	_print_debug_value
	MOVF	POSTINC1, F
	MOVF	POSTINC1, F
;	.line	88; usart.c	putchar_wait(' ');
	MOVLW	0x20
	MOVWF	POSTDEC1
	CALL	_putchar_wait
	MOVF	POSTINC1, F
;	.line	89; usart.c	print_debug_value('M',SERIAL_BUFFER_SIZE_MASK);
	MOVLW	0x3f
	MOVWF	POSTDEC1
	MOVLW	0x4d
	MOVWF	POSTDEC1
	CALL	_print_debug_value
	MOVF	POSTINC1, F
	MOVF	POSTINC1, F
;	.line	90; usart.c	putchar_wait(' ');
	MOVLW	0x20
	MOVWF	POSTDEC1
	CALL	_putchar_wait
	MOVF	POSTINC1, F
;	.line	91; usart.c	print_debug_value('H',fifo->head);
	MOVFF	r0x00, FSR0L
	MOVFF	r0x01, PRODL
	MOVF	r0x02, W
	CALL	__gptrget1
	MOVWF	r0x03
	MOVF	r0x03, W
	MOVWF	POSTDEC1
	MOVLW	0x48
	MOVWF	POSTDEC1
	CALL	_print_debug_value
	MOVF	POSTINC1, F
	MOVF	POSTINC1, F
;	.line	92; usart.c	putchar_wait(' ');
	MOVLW	0x20
	MOVWF	POSTDEC1
	CALL	_putchar_wait
	MOVF	POSTINC1, F
;	.line	93; usart.c	print_debug_value('T',fifo->tail);
	MOVF	r0x00, W
	ADDLW	0x01
	MOVWF	r0x03
	MOVLW	0x00
	ADDWFC	r0x01, W
	MOVWF	r0x04
	MOVLW	0x00
	ADDWFC	r0x02, W
	MOVWF	r0x05
	MOVFF	r0x03, FSR0L
	MOVFF	r0x04, PRODL
	MOVF	r0x05, W
	CALL	__gptrget1
	MOVWF	r0x03
	MOVF	r0x03, W
	MOVWF	POSTDEC1
	MOVLW	0x54
	MOVWF	POSTDEC1
	CALL	_print_debug_value
	MOVF	POSTINC1, F
	MOVF	POSTINC1, F
;	.line	94; usart.c	putchar_wait(' ');
	MOVLW	0x20
	MOVWF	POSTDEC1
	CALL	_putchar_wait
	MOVF	POSTINC1, F
;	.line	95; usart.c	putchar_wait(' ');
	MOVLW	0x20
	MOVWF	POSTDEC1
	CALL	_putchar_wait
	MOVF	POSTINC1, F
;	.line	96; usart.c	putchar_wait(' ');
	MOVLW	0x20
	MOVWF	POSTDEC1
	CALL	_putchar_wait
	MOVF	POSTINC1, F
;	.line	97; usart.c	puts_rom(sData);
	MOVLW	UPPER(_sData)
	MOVWF	r0x05
	MOVLW	HIGH(_sData)
	MOVWF	r0x04
	MOVLW	LOW(_sData)
	MOVWF	r0x03
	MOVF	r0x05, W
	MOVWF	POSTDEC1
	MOVF	r0x04, W
	MOVWF	POSTDEC1
	MOVF	r0x03, W
	MOVWF	POSTDEC1
	CALL	_puts_rom
	MOVLW	0x03
	ADDWF	FSR1L, F
;	.line	98; usart.c	for (i=0; i<SERIAL_BUFFER_SIZE; i++) {
	MOVLW	0x02
	ADDWF	r0x00, F
	MOVLW	0x00
	ADDWFC	r0x01, F
	ADDWFC	r0x02, F
	CLRF	r0x03
_00168_DS_:
;	.line	99; usart.c	print_hex_wait(fifo->data[i]);
	MOVF	r0x03, W
	ADDWF	r0x00, W
	MOVWF	r0x04
	CLRF	WREG
	ADDWFC	r0x01, W
	MOVWF	r0x05
	CLRF	WREG
	ADDWFC	r0x02, W
	MOVWF	r0x06
	MOVFF	r0x04, FSR0L
	MOVFF	r0x05, PRODL
	MOVF	r0x06, W
	CALL	__gptrget1
	MOVWF	r0x04
	MOVF	r0x04, W
	MOVWF	POSTDEC1
	CALL	_print_hex_wait
	MOVF	POSTINC1, F
;	.line	100; usart.c	putchar_wait(' ');
	MOVLW	0x20
	MOVWF	POSTDEC1
	CALL	_putchar_wait
	MOVF	POSTINC1, F
;	.line	98; usart.c	for (i=0; i<SERIAL_BUFFER_SIZE; i++) {
	INCF	r0x03, F
	MOVLW	0x40
	SUBWF	r0x03, W
	BNC	_00168_DS_
;	.line	102; usart.c	putchar_wait('\r');
	MOVLW	0x0d
	MOVWF	POSTDEC1
	CALL	_putchar_wait
	MOVF	POSTINC1, F
;	.line	103; usart.c	putchar_wait('\n');
	MOVLW	0x0a
	MOVWF	POSTDEC1
	CALL	_putchar_wait
	MOVF	POSTINC1, F
	MOVFF	PREINC1, r0x06
	MOVFF	PREINC1, r0x05
	MOVFF	PREINC1, r0x04
	MOVFF	PREINC1, r0x03
	MOVFF	PREINC1, r0x02
	MOVFF	PREINC1, r0x01
	MOVFF	PREINC1, r0x00
	MOVFF	PREINC1, FSR2L
	RETURN	

; ; Starting pCode block
S_usart__print_debug_value	code
_print_debug_value:
;	.line	77; usart.c	void print_debug_value(char c, unsigned char value) {
	MOVFF	FSR2L, POSTDEC1
	MOVFF	FSR1L, FSR2L
	MOVFF	r0x00, POSTDEC1
	MOVFF	r0x01, POSTDEC1
	MOVLW	0x02
	MOVFF	PLUSW2, r0x00
	MOVLW	0x03
	MOVFF	PLUSW2, r0x01
;	.line	78; usart.c	putchar_wait(c);
	MOVF	r0x00, W
	MOVWF	POSTDEC1
	CALL	_putchar_wait
	MOVF	POSTINC1, F
;	.line	79; usart.c	putchar_wait(':');
	MOVLW	0x3a
	MOVWF	POSTDEC1
	CALL	_putchar_wait
	MOVF	POSTINC1, F
;	.line	80; usart.c	print_hex_wait(value);
	MOVF	r0x01, W
	MOVWF	POSTDEC1
	CALL	_print_hex_wait
	MOVF	POSTINC1, F
	MOVFF	PREINC1, r0x01
	MOVFF	PREINC1, r0x00
	MOVFF	PREINC1, FSR2L
	RETURN	

; ; Starting pCode block
S_usart__puts_rom	code
_puts_rom:
;	.line	70; usart.c	void puts_rom(const char * s) {
	MOVFF	FSR2L, POSTDEC1
	MOVFF	FSR1L, FSR2L
	MOVFF	r0x00, POSTDEC1
	MOVFF	r0x01, POSTDEC1
	MOVFF	r0x02, POSTDEC1
	MOVFF	r0x03, POSTDEC1
	MOVFF	r0x04, POSTDEC1
	MOVLW	0x02
	MOVFF	PLUSW2, r0x00
	MOVLW	0x03
	MOVFF	PLUSW2, r0x01
	MOVLW	0x04
	MOVFF	PLUSW2, r0x02
_00145_DS_:
;	.line	72; usart.c	while ( ( c = *s++ ) ) {
	MOVFF	r0x00, FSR0L
	MOVFF	r0x01, PRODL
	MOVF	r0x02, W
	CALL	__gptrget1
	MOVWF	r0x03
	INCF	r0x00, F
	BNC	_00157_DS_
	INFSNZ	r0x01, F
	INCF	r0x02, F
_00157_DS_:
	MOVFF	r0x03, r0x04
	MOVF	r0x03, W
	BZ	_00148_DS_
;	.line	73; usart.c	putchar_wait( c );
	MOVF	r0x04, W
	MOVWF	POSTDEC1
	CALL	_putchar_wait
	MOVF	POSTINC1, F
	BRA	_00145_DS_
_00148_DS_:
	MOVFF	PREINC1, r0x04
	MOVFF	PREINC1, r0x03
	MOVFF	PREINC1, r0x02
	MOVFF	PREINC1, r0x01
	MOVFF	PREINC1, r0x00
	MOVFF	PREINC1, FSR2L
	RETURN	

; ; Starting pCode block
S_usart__print_hex_wait	code
_print_hex_wait:
;	.line	59; usart.c	void print_hex_wait(unsigned char c) {
	MOVFF	FSR2L, POSTDEC1
	MOVFF	FSR1L, FSR2L
	MOVFF	r0x00, POSTDEC1
	MOVFF	r0x01, POSTDEC1
	MOVLW	0x02
	MOVFF	PLUSW2, r0x00
;	.line	61; usart.c	nibble=((c & 0xf0) >> 4 ) + '0';
	MOVLW	0xf0
	ANDWF	r0x00, W
	MOVWF	r0x01
	SWAPF	r0x01, W
	ANDLW	0x0f
	MOVWF	r0x01
	MOVLW	0x30
	ADDWF	r0x01, F
;	.line	62; usart.c	if (nibble>=0x3a) nibble+=7;
	MOVLW	0x3a
	SUBWF	r0x01, W
	BNC	_00126_DS_
	MOVLW	0x07
	ADDWF	r0x01, F
_00126_DS_:
;	.line	63; usart.c	putchar_wait(nibble);
	MOVF	r0x01, W
	MOVWF	POSTDEC1
	CALL	_putchar_wait
	MOVF	POSTINC1, F
;	.line	65; usart.c	nibble=(c & 0x0f) + '0';
	MOVLW	0x0f
	ANDWF	r0x00, F
	MOVLW	0x30
	ADDWF	r0x00, W
	MOVWF	r0x01
;	.line	66; usart.c	if (nibble>=0x3a) nibble+=7;
	MOVLW	0x3a
	SUBWF	r0x01, W
	BNC	_00128_DS_
	MOVLW	0x07
	ADDWF	r0x01, F
_00128_DS_:
;	.line	67; usart.c	putchar_wait(nibble);
	MOVF	r0x01, W
	MOVWF	POSTDEC1
	CALL	_putchar_wait
	MOVF	POSTINC1, F
	MOVFF	PREINC1, r0x01
	MOVFF	PREINC1, r0x00
	MOVFF	PREINC1, FSR2L
	RETURN	

; ; Starting pCode block
S_usart__putchar_wait	code
_putchar_wait:
;	.line	54; usart.c	void putchar_wait(unsigned char c) {
	MOVFF	FSR2L, POSTDEC1
	MOVFF	FSR1L, FSR2L
	MOVFF	r0x00, POSTDEC1
	MOVLW	0x02
	MOVFF	PLUSW2, r0x00
_00117_DS_:
;	.line	55; usart.c	while (!TXSTA1bits.TRMT1);
	BTFSS	_TXSTA1bits, 1
	BRA	_00117_DS_
;	.line	56; usart.c	TXREG1 = c;
	MOVFF	r0x00, _TXREG1
	MOVFF	PREINC1, r0x00
	MOVFF	PREINC1, FSR2L
	RETURN	

; ; Starting pCode block
S_usart__putchar	code
_putchar:
;	.line	45; usart.c	char putchar(unsigned char c) {
	MOVFF	FSR2L, POSTDEC1
	MOVFF	FSR1L, FSR2L
	MOVFF	r0x00, POSTDEC1
	MOVLW	0x02
	MOVFF	PLUSW2, r0x00
;	.line	46; usart.c	if ( TXSTA1bits.TRMT1 ) {
	BTFSS	_TXSTA1bits, 1
	BRA	_00111_DS_
;	.line	47; usart.c	TXREG1 = c;
	MOVFF	r0x00, _TXREG1
;	.line	48; usart.c	return 1;
	MOVLW	0x01
	BRA	_00112_DS_
_00111_DS_:
;	.line	50; usart.c	return 0;
	CLRF	WREG
_00112_DS_:
	MOVFF	PREINC1, r0x00
	MOVFF	PREINC1, FSR2L
	RETURN	

; ; Starting pCode block
S_usart__init_usart	code
_init_usart:
;	.line	14; usart.c	void init_usart (void) {
	MOVFF	FSR2L, POSTDEC1
	MOVFF	FSR1L, FSR2L
;	.line	16; usart.c	TRISCbits.TRISC6 = 0;	// make the TX pin a digital output
	BCF	_TRISCbits, 6
;	.line	17; usart.c	TRISCbits.TRISC7 = 1;	// make the RX pin a digital input
	BSF	_TRISCbits, 7
;	.line	18; usart.c	TXSTA1bits.BRGH = USE_BRGH;		// high speed
	BSF	_TXSTA1bits, 2
;	.line	19; usart.c	BAUDCON1bits.BRG16 = USE_BRG16; 	// 8-bit baud rate generator
	BCF	_BAUDCON1bits, 3
;	.line	20; usart.c	SPBRG = SBRG_VAL;		// calculated by defines
	MOVLW	0x07
	MOVWF	_SPBRG
;	.line	22; usart.c	PIE1bits.RC1IE = 0;		// disbale RX interrupt
	BCF	_PIE1bits, 5
;	.line	23; usart.c	PIE1bits.TX1IE = 0;		// disbale TX interrupt
	BCF	_PIE1bits, 4
;	.line	25; usart.c	RCSTA1bits.RX9  = 0;	// 8-bit reception
	BCF	_RCSTA1bits, 6
;	.line	26; usart.c	RCSTA1bits.SPEN = 1;	// enable serial port (configures RX/DT and TX/CK pins as serial port pins)
	BSF	_RCSTA1bits, 7
;	.line	27; usart.c	RCSTA1bits.CREN = 1;	// enable receiver
	BSF	_RCSTA1bits, 4
;	.line	29; usart.c	TXSTA1bits.TX9  = 0;	// 8-bit transmission
	BCF	_TXSTA1bits, 6
;	.line	30; usart.c	TXSTA1bits.SYNC = 0;	// asynchronous mode
	BCF	_TXSTA1bits, 4
;	.line	31; usart.c	TXSTA1bits.TXEN = 1;	// transmit enabled
	BSF	_TXSTA1bits, 5
	MOVFF	PREINC1, FSR2L
	RETURN	

; ; Starting pCode block for Ival
	code
_sData:
	DB	0x20, 0x44, 0x61, 0x74, 0x61, 0x3a, 0x20, 0x00


; Statistics:
; code size:	 2482 (0x09b2) bytes ( 1.89%)
;           	 1241 (0x04d9) words
; udata size:	    0 (0x0000) bytes ( 0.00%)
; access size:	   26 (0x001a) bytes


	end
