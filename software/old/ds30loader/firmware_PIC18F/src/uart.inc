;------------------------------------------------------------------------------
;
; Title:			ds30 Loader for PIC18
;
; File description:	UART functions
;
; Copyright: 		Copyright © 2011, Mikael Gustafsson
;
; Webpage: 			http://mrmackey.no-ip.org/elektronik/ds30loader/
;
; History:			3.0.0 first version of this file
;                                                                             
;------------------------------------------------------------------------------

;-----------------------------------------------------------------------------
;    This file is part of ds30 Loader.
;
;    ds30 Loader is free software: you can redistribute it and/or modify
;    it under the terms of the GNU General Public License as published by
;    the Free Software Foundation.
;
;    ds30 Loader is distributed in the hope that it will be useful,
;    but WITHOUT ANY WARRANTY; without even the implied warranty of
;    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;    GNU General Public License for more details.
;
;    You should have received a copy of the GNU General Public License
;    along with ds30 Loader. If not, see <http:;www.gnu.org/licenses/>.
;------------------------------------------------------------------------------ 
		

;------------------------------------------------------------------------------
; UARTs
;------------------------------------------------------------------------------ 
		ifdef USE_UART1
			ifdef USE_UART2
				error "Both uarts are specified"
			endif
			
			#define PIRRCIF_		PIR1				;uart interupt status register
			#define RCIF_			RCIF
			
			ifndef TXSTA1
			   	#define TXSTA_		TXSTA				;uart status
			   	#define	RCSTA_		RCSTA				;uart status
			   	#define	SPBRG_		SPBRG				;uart baudrate
			   	#define	TXREG_		TXREG				;uart transmit
			   	#define	RCREG_		RCREG				;uart receive
			else
			   	#define	TXSTA_		TXSTA1				;uart status
			   	#define	RCSTA_		RCSTA1				;uart status
			   	#define	SPBRG_		SPBRG1				;uart baudrate
			   	#define	TXREG_		TXREG1				;uart transmit
			   	#define	RCREG_		RCREG1				;uart receive
			endif
			
			ifdef BAUDCON
			   	#define	BAUDCON_	BAUDCON				;uart receive
			else
			   	#define	BAUDCON_	BAUDCON1			;uart receive
			endif
			
			ifdef SPBRGH
			   	#define	SPBRGH_		SPBRGH				;uart receive
			else
			   	#define	SPBRGH_		SPBRGH1				;uart receive
			endif
		endif

		ifdef USE_UART2
			ifdef USE_UART1
				error "Both uarts are specified"
			endif		
			ifndef HAS_UART2
				error "UART2 specified for a device that only has uart1"
			endif
			
			
			#define PIRRCIF_	PIR3					;uart interupt status register
			#define RCIF_		RC2IF

		   	#define	TXSTA_		TXSTA2					;uart status
		   	#define	RCSTA_		RCSTA2					;uart status
		   	#define	SPBRG_		SPBRG2					;uart baudrate
			#define	SPBRGH_		SPBRGH2					;uart baudrate
		   	#define	TXREG_		TXREG2					;uart transmit
		   	#define	RCREG_		RCREG2					;uart receive
			#define	BAUDCON_	BAUDCON2				;uart receive
		endif
		
		;
		ifdef USE_TXENABLE
			#define	TXE_DELAY_CNT	( (TXE_DELAY * OSCF) / (4000000 * 3) )
		endif

				
;------------------------------------------------------------------------------
; Range check
;------------------------------------------------------------------------------
		ifndef USE_BRG16
			if UBRG > 255
				error spbrg_value_ is out of range
			endif
		else
			if UBRG > 65535
				error spbrg_value_ is out of range
			endif
		endif
		
		if UBRG == 0
			error spbrg_value_ might be out of range
		endif
		

;------------------------------------------------------------------------------
; CommInit()
;------------------------------------------------------------------------------	
CommInit
		banksel	TXSTA_
		ifdef USE_BRG16
			bsf		BAUDCON_, BRG16
			movlw	(UBRG>>8)
			movwf	SPBRGH_
		endif

		movlw 	b'00100100'		;enable transmit and 
		movwf 	TXSTA_			; high speed mode
		movlw 	(UBRG&0xff)
		movwf 	SPBRG_
		movlw 	b'10010000'		;enable serial port
		movwf 	RCSTA_			; and receive
			
		ifdef USE_ABAUD
			; Activate auto baud rate detection
			bsf		BAUDCON_, ABDEN			
			; Wait for auto baudrate detection to finish with timeout control
			movlw 	BLSTART
			movwf	cnt1			; 
abd_rpt2	movlw	DELBASE			; 
			movwf	cnt2			;		
abd_rpt3	clrf 	cnt3		
abd_rptc	clrwdt
			btfss 	BAUDCON_, ABDEN
			bra 	abd_ok		
abd_notrcv	decfsz 	cnt3
			bra 	abd_rptc
			decfsz 	cnt2
			bra 	abd_rpt3
			decfsz 	cnt1
			bra 	abd_rpt2
			; abd timed out if we get here
			bra		exit			
			; abd finished
abd_ok		movf	RCREG_, w		;clear rcif
			SendL	OK	
	
		endif
		
		; Make tx enable pin output and set to 0
		ifdef USE_TXENABLE
			bcf	TRISR_TXE, TRISB_TXE
			bcf	LATR_TXE, LATB_TXE
		endif
		

		movlb 0x0
		return	
		

;------------------------------------------------------------------------------
; CommExit()
;------------------------------------------------------------------------------	
CommExit
		banksel	RCSTA_
		clrf	RCSTA_			;reset receive status and control register
		clrf	TXSTA_			;reset transmit status and control register
		ifdef USE_BRG16
			clrf BAUDCON_
			clrf SPBRGH_
		endif
		
		movlb 0x0		
		return	

;------------------------------------------------------------------------------
; Receive()
;------------------------------------------------------------------------------	
Receive	movlw 	BLDELAY
RcvIni	movwf	cnt1			; 
rpt2	movlw	DELBASE			; 
		movwf	cnt2			;		
rpt3	clrf 	cnt3		
rptc	
		ifdef KICK_WD
			clrwdt
		endif
		btfss 	PIRRCIF_, RCIF_
		bra 	notrcv
		banksel	RCREG_
		movf 	RCREG_, w		;return read data in W
		movlb 	0x0
		addwf 	crc, f			;compute crc
		return		
notrcv	decfsz 	cnt3
		bra 	rptc
		decfsz 	cnt2
		bra 	rpt3
		decfsz 	cnt1
		bra 	rpt2
		; Receive timed out if we get here
		bra		exit		
		
		
;------------------------------------------------------------------------------
; Send()
;------------------------------------------------------------------------------		
Send	; Enable tx
		banksel	TXSTA_
		ifdef USE_TXENABLE
			bcf		RCSTA_, CREN			;disable serial receiver
			movwf	cnt2
			bsf	LATR_TXE, LATB_TXE
			movlw	TXE_DELAY_CNT
			movwf	cnt1
txe_del_lo	decfsz	cnt1
			bra		txe_del_lo
			movf	cnt2, w
		else		
			; Wait for transmit shift register to get empty
txwait		btfss	TXSTA_, TRMT
			bra		txwait
		endif		
		;Send byte
		movwf 	TXREG_
		; Disable tx 
		ifdef USE_TXENABLE
			; Wait for transmit shift register to get empty
txwait		btfss	TXSTA_, TRMT
			bra		txwait
			bcf		LATR_TXE, LATB_TXE
			bsf		RCSTA_, CREN			;enable serial receiver
		endif
		; Send complete
		movlb 0x0
		return
	
	
;------------------------------------------------------------------------------	
; End of file
;------------------------------------------------------------------------------	
