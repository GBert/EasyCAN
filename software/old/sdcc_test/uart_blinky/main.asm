;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.4.1 #9092 (Nov  3 2014) (Linux)
; This file was generated Thu Nov  6 11:40:32 2014
;--------------------------------------------------------
; PIC16 port for the Microchip 16-bit core micros
;--------------------------------------------------------
	list	p=18f26k80
	radix	dec
	CONFIG	XINST=OFF


;--------------------------------------------------------
; public variables in this module
;--------------------------------------------------------
	global	_timer_ticks
	global	_tx_fifo
	global	_rx_fifo
	global	_init_port
	global	_init_timer
	global	_main
	global	_isr
	global	_s1
	global	_s2

;--------------------------------------------------------
; extern variables in this module
;--------------------------------------------------------
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
	extern	_init_usart
	extern	_puts_rom
	extern	_puts_rom_fifo
	extern	_putchar_fifo
	extern	_fifo_getchar
	extern	_fifo_putchar
	extern	_copy_char_fifo

;--------------------------------------------------------
;	Equates to used internal registers
;--------------------------------------------------------
STATUS	equ	0xfd8
PCLATH	equ	0xffa
PCLATU	equ	0xffb
BSR	equ	0xfe0
FSR0L	equ	0xfe9
FSR0H	equ	0xfea
FSR1L	equ	0xfe1
FSR2L	equ	0xfd9
POSTDEC1	equ	0xfe5
PREINC1	equ	0xfe4
PRODL	equ	0xff3
PRODH	equ	0xff4


	idata
_timer_ticks	db	0x00


; Internal registers
.registers	udata_ovr	0x0000
r0x00	res	1
r0x01	res	1
r0x02	res	1
r0x03	res	1
r0x04	res	1
r0x05	res	1
r0x06	res	1

udata_main_0	udata
_tx_fifo	res	66

udata_main_1	udata
_rx_fifo	res	66

;--------------------------------------------------------
; interrupt vector
;--------------------------------------------------------

;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
; ; Starting pCode block for absolute section
; ;-----------------------------------------
S_main_ivec_0x1_isr	code	0X000008
ivec_0x1_isr:
	GOTO	_isr

; I code from now on!
; ; Starting pCode block
S_main__main	code
_main:
;	.line	48; main.c	unsigned char do_print=0;
	CLRF	r0x00
;	.line	53; main.c	init_port();
	CALL	_init_port
;	.line	54; main.c	init_timer();
	CALL	_init_timer
;	.line	55; main.c	init_usart();
	CALL	_init_usart
	BANKSEL	_tx_fifo
;	.line	58; main.c	tx_fifo.head=0;
	CLRF	_tx_fifo, B
	BANKSEL	(_tx_fifo + 1)
;	.line	59; main.c	tx_fifo.tail=0;
	CLRF	(_tx_fifo + 1), B
	BANKSEL	_rx_fifo
;	.line	60; main.c	rx_fifo.head=0;
	CLRF	_rx_fifo, B
	BANKSEL	(_rx_fifo + 1)
;	.line	61; main.c	rx_fifo.tail=0;
	CLRF	(_rx_fifo + 1), B
_00126_DS_:
;	.line	65; main.c	if ((do_print == 0) && (timer_ticks == 10)) {
	MOVF	r0x00, W
	BNZ	_00116_DS_
	BANKSEL	_timer_ticks
	MOVF	_timer_ticks, W, B
	XORLW	0x0a
	BNZ	_00116_DS_
;	.line	66; main.c	do_print = 1;
	MOVLW	0x01
	MOVWF	r0x00
_00116_DS_:
;	.line	68; main.c	if ((do_print == 1) && (timer_ticks == 100)) {
	MOVF	r0x00, W
	XORLW	0x01
	BNZ	_00119_DS_
_00154_DS_:
	BANKSEL	_timer_ticks
	MOVF	_timer_ticks, W, B
	XORLW	0x64
	BNZ	_00119_DS_
;	.line	69; main.c	do_print = 0;
	CLRF	r0x00
;	.line	70; main.c	puts_rom(s2);
	MOVLW	UPPER(_s2)
	MOVWF	r0x03
	MOVLW	HIGH(_s2)
	MOVWF	r0x02
	MOVLW	LOW(_s2)
	MOVWF	r0x01
	MOVF	r0x03, W
	MOVWF	POSTDEC1
	MOVF	r0x02, W
	MOVWF	POSTDEC1
	MOVF	r0x01, W
	MOVWF	POSTDEC1
	CALL	_puts_rom
	MOVLW	0x03
	ADDWF	FSR1L, F
;	.line	71; main.c	ret=puts_rom_fifo(s1,&tx_fifo);
	MOVLW	UPPER(_s1)
	MOVWF	r0x03
	MOVLW	HIGH(_s1)
	MOVWF	r0x02
	MOVLW	LOW(_s1)
	MOVWF	r0x01
	MOVLW	HIGH(_tx_fifo)
	MOVWF	r0x05
	MOVLW	LOW(_tx_fifo)
	MOVWF	r0x04
	MOVLW	0x80
	MOVWF	r0x06
	MOVF	r0x06, W
	MOVWF	POSTDEC1
	MOVF	r0x05, W
	MOVWF	POSTDEC1
	MOVF	r0x04, W
	MOVWF	POSTDEC1
	MOVF	r0x03, W
	MOVWF	POSTDEC1
	MOVF	r0x02, W
	MOVWF	POSTDEC1
	MOVF	r0x01, W
	MOVWF	POSTDEC1
	CALL	_puts_rom_fifo
	MOVLW	0x06
	ADDWF	FSR1L, F
_00119_DS_:
;	.line	73; main.c	ret=fifo_putchar(&tx_fifo);
	MOVLW	HIGH(_tx_fifo)
	MOVWF	r0x02
	MOVLW	LOW(_tx_fifo)
	MOVWF	r0x01
	MOVLW	0x80
	MOVWF	r0x03
	MOVF	r0x03, W
	MOVWF	POSTDEC1
	MOVF	r0x02, W
	MOVWF	POSTDEC1
	MOVF	r0x01, W
	MOVWF	POSTDEC1
	CALL	_fifo_putchar
	MOVLW	0x03
	ADDWF	FSR1L, F
;	.line	74; main.c	if (c=fifo_getchar(&rx_fifo)) {
	MOVLW	HIGH(_rx_fifo)
	MOVWF	r0x02
	MOVLW	LOW(_rx_fifo)
	MOVWF	r0x01
	MOVLW	0x80
	MOVWF	r0x03
	MOVF	r0x03, W
	MOVWF	POSTDEC1
	MOVF	r0x02, W
	MOVWF	POSTDEC1
	MOVF	r0x01, W
	MOVWF	POSTDEC1
	CALL	_fifo_getchar
	MOVWF	r0x01
	MOVLW	0x03
	ADDWF	FSR1L, F
	MOVFF	r0x01, r0x02
	MOVF	r0x01, W
	BTFSC	STATUS, 2
	BRA	_00126_DS_
;	.line	75; main.c	if (c==0x0d) {
	MOVF	r0x02, W
	XORLW	0x0d
	BZ	_00158_DS_
	BRA	_00126_DS_
_00158_DS_:
;	.line	76; main.c	copy_char_fifo(&rx_fifo,&tx_fifo);
	MOVLW	HIGH(_rx_fifo)
	MOVWF	r0x02
	MOVLW	LOW(_rx_fifo)
	MOVWF	r0x01
	MOVLW	0x80
	MOVWF	r0x03
	MOVLW	HIGH(_tx_fifo)
	MOVWF	r0x05
	MOVLW	LOW(_tx_fifo)
	MOVWF	r0x04
	MOVLW	0x80
	MOVWF	r0x06
	MOVF	r0x06, W
	MOVWF	POSTDEC1
	MOVF	r0x05, W
	MOVWF	POSTDEC1
	MOVF	r0x04, W
	MOVWF	POSTDEC1
	MOVF	r0x03, W
	MOVWF	POSTDEC1
	MOVF	r0x02, W
	MOVWF	POSTDEC1
	MOVF	r0x01, W
	MOVWF	POSTDEC1
	CALL	_copy_char_fifo
	MOVLW	0x06
	ADDWF	FSR1L, F
;	.line	77; main.c	putchar_fifo(0x0a,&tx_fifo);
	MOVLW	HIGH(_tx_fifo)
	MOVWF	r0x02
	MOVLW	LOW(_tx_fifo)
	MOVWF	r0x01
	MOVLW	0x80
	MOVWF	r0x03
	MOVF	r0x03, W
	MOVWF	POSTDEC1
	MOVF	r0x02, W
	MOVWF	POSTDEC1
	MOVF	r0x01, W
	MOVWF	POSTDEC1
	MOVLW	0x0a
	MOVWF	POSTDEC1
	CALL	_putchar_fifo
	MOVLW	0x04
	ADDWF	FSR1L, F
	BRA	_00126_DS_
	RETURN	

; ; Starting pCode block
S_main__isr	code
_isr:
;	.line	83; main.c	void isr() __interrupt 1 {
	MOVFF	STATUS, POSTDEC1
	MOVFF	BSR, POSTDEC1
	MOVWF	POSTDEC1
	MOVFF	PRODL, POSTDEC1
	MOVFF	PRODH, POSTDEC1
	MOVFF	FSR0L, POSTDEC1
	MOVFF	FSR0H, POSTDEC1
	MOVFF	PCLATH, POSTDEC1
	MOVFF	PCLATU, POSTDEC1
	MOVFF	FSR2L, POSTDEC1
	MOVFF	FSR1L, FSR2L
;	.line	84; main.c	if (INTCONbits.TMR0IE && INTCONbits.TMR0IF) {
	BTFSS	_INTCONbits, 5
	BRA	_00174_DS_
	BTFSS	_INTCONbits, 2
	BRA	_00174_DS_
	BANKSEL	_timer_ticks
;	.line	86; main.c	timer_ticks++;
	INCF	_timer_ticks, F, B
	BANKSEL	_timer_ticks
;	.line	87; main.c	if (timer_ticks==20) {  // 80 ms
	MOVF	_timer_ticks, W, B
	XORLW	0x14
	BNZ	_00164_DS_
;	.line	88; main.c	LED = 0;		// LED OFF
	BCF	_LATAbits, 0
_00164_DS_:
	BANKSEL	_timer_ticks
;	.line	90; main.c	if (timer_ticks==40) {  // 80 ms
	MOVF	_timer_ticks, W, B
	XORLW	0x28
	BNZ	_00166_DS_
;	.line	91; main.c	LED = 1;		// LED ON
	BSF	_LATAbits, 0
_00166_DS_:
	BANKSEL	_timer_ticks
;	.line	93; main.c	if (timer_ticks==60) {  // 80 ms
	MOVF	_timer_ticks, W, B
	XORLW	0x3c
	BNZ	_00168_DS_
;	.line	94; main.c	LED = 0;		// LED OFF
	BCF	_LATAbits, 0
_00168_DS_:
	BANKSEL	_timer_ticks
;	.line	96; main.c	if (timer_ticks==250) { // 720 ms
	MOVF	_timer_ticks, W, B
	XORLW	0xfa
	BNZ	_00170_DS_
;	.line	97; main.c	LED = 1;		// LED OFF
	BSF	_LATAbits, 0
	BANKSEL	_timer_ticks
;	.line	98; main.c	timer_ticks=0;
	CLRF	_timer_ticks, B
_00170_DS_:
;	.line	100; main.c	INTCONbits.TMR0IF = 0;
	BCF	_INTCONbits, 2
_00174_DS_:
	MOVFF	PREINC1, FSR2L
	MOVFF	PREINC1, PCLATU
	MOVFF	PREINC1, PCLATH
	MOVFF	PREINC1, FSR0H
	MOVFF	PREINC1, FSR0L
	MOVFF	PREINC1, PRODH
	MOVFF	PREINC1, PRODL
	MOVF	PREINC1, W
	MOVFF	PREINC1, BSR
	MOVFF	PREINC1, STATUS
	RETFIE	

; ; Starting pCode block
S_main__init_timer	code
_init_timer:
;	.line	27; main.c	void init_timer(void) {
	MOVFF	FSR2L, POSTDEC1
	MOVFF	FSR1L, FSR2L
;	.line	31; main.c	T0CONbits.T0PS0=1;    //Prescaler is divide by 256
	BSF	_T0CONbits, 0
;	.line	32; main.c	T0CONbits.T0PS1=1;
	BSF	_T0CONbits, 1
;	.line	33; main.c	T0CONbits.T0PS2=1;
	BSF	_T0CONbits, 2
;	.line	35; main.c	T0CONbits.PSA=0;      //Timer Clock Source is from Prescaler
	BCF	_T0CONbits, 3
;	.line	36; main.c	T0CONbits.T0CS=0;     //Prescaler gets clock from FCPU (16MHz)
	BCF	_T0CONbits, 5
;	.line	38; main.c	T0CONbits.T08BIT=1;   //8 BIT MODE
	BSF	_T0CONbits, 6
;	.line	40; main.c	INTCONbits.TMR0IE=1;   //Enable TIMER0 Interrupt
	BSF	_INTCONbits, 5
;	.line	41; main.c	INTCONbits.PEIE=1;     //Enable Peripheral Interrupt
	BSF	_INTCONbits, 6
;	.line	42; main.c	INTCONbits.GIE=1;      //Enable INTs globally
	BSF	_INTCONbits, 7
;	.line	44; main.c	T0CONbits.TMR0ON=1;   //Now start the timer!
	BSF	_T0CONbits, 7
	MOVFF	PREINC1, FSR2L
	RETURN	

; ; Starting pCode block
S_main__init_port	code
_init_port:
;	.line	22; main.c	void init_port(void) {
	MOVFF	FSR2L, POSTDEC1
	MOVFF	FSR1L, FSR2L
;	.line	23; main.c	ADCON1 = 0x0F;		// Default all pins to digital
	MOVLW	0x0f
	MOVWF	_ADCON1
;	.line	24; main.c	LED_TRIS = 0;
	BCF	_TRISAbits, 0
	MOVFF	PREINC1, FSR2L
	RETURN	

; ; Starting pCode block for Ival
	code
_s1:
	DB	0x63, 0x69, 0x72, 0x63, 0x75, 0x6c, 0x61, 0x72, 0x20, 0x62, 0x75, 0x66
	DB	0x66, 0x65, 0x72, 0x20, 0x69, 0x73, 0x20, 0x77, 0x6f, 0x72, 0x6b, 0x69
	DB	0x6e, 0x67, 0x21, 0x0d, 0x0a, 0x00
; ; Starting pCode block for Ival
_s2:
	DB	0x55, 0x53, 0x41, 0x52, 0x54, 0x20, 0x69, 0x73, 0x20, 0x77, 0x6f, 0x72
	DB	0x6b, 0x69, 0x6e, 0x67, 0x21, 0x0d, 0x0a, 0x00


; Statistics:
; code size:	  538 (0x021a) bytes ( 0.41%)
;           	  269 (0x010d) words
; udata size:	  132 (0x0084) bytes ( 3.89%)
; access size:	    7 (0x0007) bytes


	end
