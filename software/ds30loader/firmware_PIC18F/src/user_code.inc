;------------------------------------------------------------------------------
;
; Title:			ds30 Loader for PIC18
;
; File description:	user init and exit code
;
; Copyright: 		Copyright © 2011, Mikael Gustafsson
;                                                                             
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
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
;    along with ds30 Loader. If not, see <http://www.gnu.org/licenses/>.
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
; UserInit()
; Description: this is executed immediately on start-up before the boot loader code
;------------------------------------------------------------------------------
UserInit macro
			
			; Make uart pins digital
			ifdef	ADCON1
				error Do you need to configura uart pins to be digital? If not, remove this line
			endif
			;movlw 	b'01100000'		;xxx disable 
			;movwf 	ADCON1			;xxx analog on tx/rx 			
			
			; UART/CAN pps config
			ifdef	HAS_PPS
				ifdef USE_UART2
					error You need to configure PPS	;xxx remove this line when PPS is configured
					
					; This template maps U2Rx to RP4
					bcf		RPINR16, RX2DT2R0		;xxx
					bcf		RPINR16, RX2DT2R1		;xxx
					bsf		RPINR16, RX2DT2R2		;xxx
					bcf		RPINR16, RX2DT2R3		;xxx
					bcf		RPINR16, RX2DT2R4		;xxx
					
					; This template maps RP3 to U2Tx
					bsf		RPOR3,	RP3R0			;xxx
					bcf		RPOR3,	RP3R1			;xxx
					bsf		RPOR3,	RP3R2			;xxx
					bcf		RPOR3,	RP3R3			;xxx
					bcf		RPOR3,	RP3R4			;xxx
				endif
			endif
		endm
		
		
;------------------------------------------------------------------------------
; UserExit()
; Description: this is executed right before the user application is loadaed
;------------------------------------------------------------------------------
UserExit macro 

		endm
		

;------------------------------------------------------------------------------
; End of file
;------------------------------------------------------------------------------	
