;------------------------------------------------------------------------------
;
; Title:			ds30 Loader for PIC18F
;
; File description:	user settings and configuration bits
;
; Copyright: 		Copyright 2009-2012 Mikael Gustafsson
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
; Device
;------------------------------------------------------------------------------
		processor	18F66K80					;xxx


;------------------------------------------------------------------------------
; Includes
;------------------------------------------------------------------------------
        #include "devices.inc"


;------------------------------------------------------------------------------
; User preferences
;------------------------------------------------------------------------------
		radix DEC
		
		#define		OSCF			10000000	;xxx oscillator frequency (including pll)
		#define		BLINIT			2000		;xxx hello receive timeout [ms]
		#define		HELLOTRIES		2			;xxx number of non hello characters received before branching to the user application
		#define		BLTIME			2000		;xxx data receive timeout [ms]


;------------------------------------------------------------------------------
; UART settings
;------------------------------------------------------------------------------			
		#define		USE_UART1		1			;xxx uncomment to use uart1
		;#define	USE_UART2		1			;xxx uncomment to use uart2
		#define		BAUDRATE	 	9600		;xxx baudrate
        ;#define	USE_ABAUD		1			;xxx uncomment to use auto baud rate detection, READ ERRATA FIRST        
		;#define	USE_BRG16		1			;xxx uncomment to use 16-bit brg

		;#define	USE_TXENABLE	1			;xxx uncomment to use a tx enable pin		
		ifdef USE_TXENABLE
			#define	TXE_DELAY 		10			;xxx time in us to wait before transmitting after pulling the tx enable pin high
			#define	TRISR_TXE		TRISD		;xxx tris register containing tx enable
			#define	LATR_TXE		LATD		;xxx port register containing tx enable
			#define	TRISB_TXE		TRISD0		;xxx tris bit for tx enable
			#define LATB_TXE		RD0			;xxx port bit for tx enable
		endif


;------------------------------------------------------------------------------
; Advanced settings
;------------------------------------------------------------------------------		
		;#define	KICK_WD			1			;xxx uncomment to kick the wd in the rx loop, only enable if the watchdog is enabled
		#define		PROT_GOTO		1			;xxx protect goto at 0x00
		#define		PROT_BL 		1			;xxx protect bootloader
		#define		WRITE_VER		1			;do flash write verification
		#define		EWRITE_VER		1			;do eeprom write verification
		
		ifdef IS_PIC18F
			#define		BLPLP		9			;bootloader placement, pages from end
			#define		BLSIZEP		9			;bootloader size [pages], used by bootloader protection	
		endif
		
		ifdef IS_PIC18FJ		
			#define		BLPLP		2			;bootloader placement, pages from end
			#define		BLSIZEP		1			;bootloader size [pages], used by bootloader protection	
		endif
		

;------------------------------------------------------------------------------
; Configuration bits, these macros can be found at the end of the inc-files located in 
; C:\Program Files\Microchip\MPASM Suite\
;
; These can also be set in MPLAB IDE instead, they are found in Configure->Configuration bits...
;------------------------------------------------------------------------------
		
		; xxx
		config	RETEN 			= OFF       	;Ultra low-power regulator is Disabled (Controlled by REGSLP bit)
		config	INTOSCSEL 		= LOW			;LF-INTOSC in Low-power mode during Sleep
		config	SOSCSEL 		= LOW      	 	;Low Power SOSC circuit selected
		config	XINST 			= OFF      	 	;Disabled
		config	FOSC 			= HS1       	;XT oscillator
		config	PLLCFG 			= OFF       	;Enabled
		config	FCMEN 			= OFF       	;Disabled
		config	IESO 			= OFF       	;Disabled
		config	PWRTEN 			= OFF       	;Disabled
		config  BOREN 			= OFF			;Brown Out Detect
		config	BORV 			= 3         	;1.8V
		config	BORPWR			= MEDIUM    	;BORMV set to medium power level
		config	WDTEN 			= OFF      		;WDT disabled in hardware; SWDTEN bit disabled
 		config	WDTPS 			= 32768     	;1:32768
		config	CANMX 			= PORTE     	;ECAN TX and RX pins are located on RE5 and RE4, respectively
		config	T0CKMX 			= PORTG    	 	;Timer0 gets its clock input from the RG4/T0CKI pin on 64-pin packages
		config	T3CKMX 			= PORTB     	;Timer3 gets its clock input from the RB5/T3CKI pin on 64-pin packages
		config	MSSPMSK 		= MSK7      	;7 Bit address masking mode
		config	MCLRE 			= ON        	;MCLR Enabled, RG5 Disabled
		config	STVREN 			= ON        	;Stack Overflow Reset			
		
		config	BBSIZ 			= BB2K			;Boot Block Size
		config	CP0 			= OFF			;Code Protect 00800-03FFF
		config	CP1 			= OFF			;Code Protect 04000-07FFF
		config	CP2			 	= OFF			;Code Protect 08000-0BFFF
		config	CP3 			= OFF			;Code Protect 0C000-0FFFF
		config	CPB 			= OFF			;Code Protect Boot
		config	CPD 			= OFF			;Data EE Read Protect
		config	WRT0 			= OFF			;Table Write Protect 00800-03FFF
		config	WRT1 			= OFF			;Table Write Protect 04000-07FFF
		config	WRT2 			= OFF			;Table Write Protect 08000-0BFFF
		config	WRT3 			= OFF			;Table Write Protect 0C000-0FFFF
		config	WRTC 			= OFF			;Config. Write Protect
		config	WRTB 			= OFF			;Table Write Protect Boot
		config	WRTD 			= OFF			;Data EE Write Protect
		config	EBTR0 			= OFF			;Table Read Protect 00800-03FFF		
		config	EBTR1 			= OFF			;Table Read Protect 04000-07FFF
		config	EBTR2 			= OFF			;Table Read Protect 08000-0BFFF
		config	EBTR3			= OFF			;Table Read Protect 0C000-0FFFF
		config	EBTRB 			= OFF       	;Table Read Protect Boot
		

;------------------------------------------------------------------------------
; ds30 Loader commercial version
;------------------------------------------------------------------------------
;-Supports read of flash and EEPROM
;-Supports software UART
;-Supports CAN
;-Available with encryption
;-Read more at www.ds30loader.com


;------------------------------------------------------------------------------
; End of file
;------------------------------------------------------------------------------	
