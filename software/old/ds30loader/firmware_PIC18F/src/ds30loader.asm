;------------------------------------------------------------------------------
;
; Title:			ds30 Loader for PIC18F
;
; File description:	Main firmwarefile
;
; Copyright: 		Copyright 2009-2012 Mikael Gustafsson
;
; Version:			3.0.2 March 2012
;
; Webpage: 			http://mrmackey.no-ip.org/elektronik/ds30loader/
;
; Thanks to:		Claudio Chiculita, this code is based on the Tiny PIC bootloader
;
; History:			3.0.2 Improvement: added delay for tx enable pin
;					3.0.1 -
;					3.0.0 New feature: compatible with ds30 Secure Loader
;						  New feature: auto baud rate detection
;					      Bugifx: bootloader protection was calculated wrong on PIC18F devices with 64 byte pagesize					      
;					      Bugfix: receiving non hello command on start-up caused long delay
;					      Improvement: merged PIC18FJ firmware
;		 				  Improvement: increased range of timeout values
;					2.0.5 Bugfix: devices with pagesize != 32 words
;					2.0.4 Bugfix: uart 1 rx interupt flag was checked also for uart 2
;					      New feature: 16-bit brg
;					2.0.3 Bugfix: In some case, CAN engine won't start (bad state on RB2)
;						  Bugfix: goto protection not working for some devices
;						  Improvement: renamed fosc to oscf for compatibility with some devices
;					2.0.2 Change: node ID configuration moved in settings.inc
;						  New feature: goto protection
;						  New feature: bl protection
;						  Change: size is 7 pages
;						  Bugfix: compatible with devices that has no eeprom (2450, 4450 and more)
;					2.0.1 New feature: adjustable non hello discard, HELLORETRIES setting					  
;					      Improvement: compatible with include files containing both TXSTA and TXSTA1 definitions
;						  Improvement: 5 or 7 (see section Init) more instructions free to use (CAN)
;					2.0.0 CAN support
;					1.0.2 Replaced old baudrate calculator	
;					1.0.1 Erase is now made just before write to increase reliability
;					1.0.0 Separated boot timeout and receive timeout
;						  Added range check of times and brg
;					0.9.2 Changed bootloader size to 5 pages (to make room for more user init code)
;						  Added tx enable support
;					0.9.1 1 more instruction free to use
;						  Added watchdog clear
;						  Fixed baudrate error check
;					 	  Correct buffer size
;					0.9.0 Initial release                                                                            
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
;    along with ds30 Loader. If not, see <http://www.gnu.org/licenses/>.
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
; Includes
;------------------------------------------------------------------------------ 
		#include "settings.inc"
		#include "user_code.inc"
		
		
;------------------------------------------------------------------------------
; Defines
;------------------------------------------------------------------------------	
		#define	VERMAJ				3			;firmware version major
		#define	VERMIN				0			;firmware version minor
		#define	VERREV				2			;firmware version revision
		
		#define HELLO 				0xC1
		#define OK 					'K'			;erase/write ok
		#define CHECKSUMERR			'N'			;checksum error
		#define	VERFAIL				'V'			;verification failed
		#define	BLPROT				'P'         ;bl protection tripped
		#define	UCMD     			'U'         ;unknown command		
		
		#define	PWOK				0xFE	

		
		if BLINIT < 2500
        	#define	TMRBASE	10
        else
        	#define	TMRBASE 30
        endif
        #define	DELBASE		( (TMRBASE * OSCF) / (3+(4000 * 255 * 6)) )				;delay
        #define	BLSTART		( BLINIT / TMRBASE )								;count for boot receive delay
        #define	BLDELAY		( BLTIME / TMRBASE )								;count for receive delay
        
        ifndef USE_BRG16
        	#define	UBRG	( (((OSCF / BAUDRATE) / 8) - 1) / 2 )				;baudrate
        else
        	#define	UBRG	( (((OSCF / BAUDRATE) / 2) - 1) / 2 )				;baudrate
        endif
		
		#define	PAGESIZER	(PAGESIZEW/ROWSIZEW)								;pagesize [rows]
		#define	ROWSIZEB	(ROWSIZEW*2)										;rowsize [bytes]
		#define STARTADDR	( MAX_FLASH - BLPLP * PAGESIZER * ROWSIZEW * 2 )	;bootloader placement
		
		ifdef	IS_PIC18F
			#define	ERASE_CODE	b'10010100'
			#define	WRITE_CODE	b'10000100'
		else
			#define	ERASE_CODE	b'00010100'
			#define	WRITE_CODE	b'00000100'
		endif
		
		; Debug output
		;messg	STARTADDR_IS 	#v(STARTADDR)
		;messg	UBRG_IS			#v(UBRG)
		;messg	delbaesis 		#v(DELBASE)	
		;messg	blstartis 		#v(BLSTART)	
		;messg	bldelayis 		#v(BLDELAY)	

				
;------------------------------------------------------------------------------
; Range check
;------------------------------------------------------------------------------
		if DELBASE > 255
			error overflow in delay calculation
		endif
		if BLSTART > 255
			error BLSTART_ is out of range
		endif
		if BLSTART == 0
			error BLSTART might be out of range
		endif			
		
		if BLDELAY > 255
			error BLDELAY_ is out of range
		endif			
		if BLDELAY == 0
			error BLDELAY_ might be out of range
		endif
		
		
;------------------------------------------------------------------------------
; Variables
;------------------------------------------------------------------------------		
			#define BUFFERSIZE (ROWSIZEB + 1 ) ;row + checksum
			cblock 0x0
				buffer 		: 	BUFFERSIZE
				crc			: 	1	;receive checksum
				dcnt		: 	1	;datacount
				dcnt2		: 	1	;datacount
				cnt1		: 	1	;receive timeout timer
				cnt2		: 	1	;receive timeout timer
				cnt3		: 	1	;receive timeout timer
				cntHello	: 	1	;
				rowcnt		: 	1	;row iterator
				rowcnt2		: 	1	;
				cmd			: 	1	;command
				doerase		: 	1	;do erase before next write
				ttblptru	: 	1
				ttblptrh	: 	1
				ttblptrl	: 	1	
                Delay1      :   1
                Delay2      :   1
                serbuf      :   1
                TEMP        :   1			
			endc
				
		
;------------------------------------------------------------------------------
; Globals & externals
;------------------------------------------------------------------------------
		
		
;------------------------------------------------------------------------------
; Macros
;------------------------------------------------------------------------------ 	
SendL 	macro sbyte
			movlw 	sbyte
			rcall	Send
		endm
		

	
;------------------------------------------------------------------------------
; Reset vector
;------------------------------------------------------------------------------ 
		org     0x0000
		goto    blstart


;------------------------------------------------------------------------------
; GOTO user application
;------------------------------------------------------------------------------ 	
		org 	STARTADDR - 4	;space to deposit goto to user application
loadusr	nop
		nop
	
	
;------------------------------------------------------------------------------
; Start of bootloader code
;------------------------------------------------------------------------------ 	
		org 	STARTADDR
blstart

		
;------------------------------------------------------------------------------
; Trouble shooting tools
;------------------------------------------------------------------------------				
		; Toggle pin, frequency on pin = PIC frequency / 16
		if 0
			bcf	TRISx, TRISxx
tsfloop		bsf LATx, LATxx
			bcf LATx, LATxx
			bra tsfloop
		endif
		
		
;------------------------------------------------------------------------------
; Init
;------------------------------------------------------------------------------	
		UserInit				;macro in user_code.inc
		clrf	doerase
		rcall	CommInit
		
		
;----------------------------------------------------------------------
; Wait for computer
;----------------------------------------------------------------------
		clrf	cntHello
rhello	movlw	BLSTART
		rcall 	RcvIni
		sublw 	HELLO
		bz 	    rhellook		
		; Not hello received
		incf	cntHello
		movf	cntHello, w
		sublw	HELLOTRIES
		bz		exit
		bra		rhello		
rhellook

		
;----------------------------------------------------------------------
; Send device id and firmware version
;----------------------------------------------------------------------		
sendid	SendL 	( DEVICEID & 0xff )
		SendL	( ((DEVICEID&0x100)>>1) + VERMAJ )
		SendL	( ((DEVICEID&0x200)>>2) + (VERMIN<<4) + VERREV )
		
		
;----------------------------------------------------------------------
; Main loop
;----------------------------------------------------------------------			
Main	SendL 	OK				;last command was successfull, waiting for next
mainl	clrf 	crc
		

		;----------------------------------------------------------------------
		; Receive address
		;----------------------------------------------------------------------			
		;Upper byte
		rcall 	Receive			
		movwf 	TBLPTRU
		; High byte
		rcall 	Receive
		movwf 	TBLPTRH
		ifdef	BIGEE
			movwf	EEADRH		;for eeprom
		endif		
		; Low byte
		rcall 	Receive
		movwf 	TBLPTRL
		ifdef	EEADR
			movwf 	EEADR		;for eeprom
		endif

					
		;----------------------------------------------------------------------
		; Receive command
		;----------------------------------------------------------------------			
		rcall 	Receive	
		movwf 	cmd	
		
		
		;----------------------------------------------------------------------
		; Receive nr of data bytes that will follow
		;----------------------------------------------------------------------			
		rcall 	Receive	
		movwf 	dcnt	
		movwf	dcnt2	


		
		
		;----------------------------------------------------------------------
		; Receive data
		;----------------------------------------------------------------------	
		lfsr 	FSR0, buffer	;load buffer pointer to fsr0
rcvoct	rcall 	Receive
		movwf 	POSTINC0
		decfsz 	dcnt
		bra 	rcvoct
				
		
		;----------------------------------------------------------------------
		; Check checksum
		;----------------------------------------------------------------------			
		tstfsz 	crc				
		bra 	crcfail			
chksumok
		
		
	

					
				
		;----------------------------------------------------------------------
		; 0x00 goto protection
		;----------------------------------------------------------------------	
		ifdef	PROT_GOTO
			; Only for write row command
			btfss 	cmd, 1			
			bra 	protgotook		
			; Check for row 0
			tstfsz	TBLPTRU
			bra		protgotook
			tstfsz	TBLPTRH
			bra		protgotook
			tstfsz	TBLPTRL
			bra		protgotook						
			; Init buffer pointer
			lfsr 	FSR0, buffer	;load buffer pointer to fsr0
			; 1st word low byte = low address byte 
			movlw 	((STARTADDR>>1)&0xff)
			movwf	POSTINC0
			; 1st word high byte = goto instruction
			movlw	0xef
			movwf	POSTINC0
			; 2nd word low byte = upper address byte
			movlw 	(((STARTADDR>>1)&0xff00)>>8)
			movwf	POSTINC0
			; 2nd word high byte = uppder address nibble + goto instruction			
			movlw 	(0xf0 + (((STARTADDR>>1)&0xf0000)>>16))
			movwf	POSTINC0
protgotook
		endif
		
		
		;----------------------------------------------------------------------
		; Init buffer pointer
		;----------------------------------------------------------------------			
		lfsr 	FSR0, buffer	;load buffer pointer to fsr0
		
		
		;----------------------------------------------------------------------
		; Check command
		;----------------------------------------------------------------------
		
		; Erase page, set do erase status flag
		btfss	cmd, 0
		bra		cmdrow
		setf	doerase
		bra		Main
		; Write row
cmdrow	btfsc 	cmd, 1			
		bra 	blprot
		; Write eeprom word
		ifdef	HAS_EE			
			btfsc 	cmd, 2			
			bra 	eeprom
		endif
		; Write config
		btfsc 	cmd, 3
		bra 	cfg	
		; Else, unknown command
		SendL   UCMD		
		bra     mainl				
		
				
		;------------------------------------------------------------------------------
		; Exit, placed here so it can be branched to from all code, max +-127
		;------------------------------------------------------------------------------				
exit
		rcall	CommExit
		UserExit						;macro in user_code.inc
		bra 	loadusr		
		
							
		;----------------------------------------------------------------------
		; Bootloader protection
		;----------------------------------------------------------------------
blprot	nop
		ifdef PROT_BL
			if PAGESIZEW == 16
				#define	ROTROUNDS	5
			endif
			if PAGESIZEW == 32			;most PIC18F
				#define	ROTROUNDS	6
			endif
			if PAGESIZEW == 64			;some PIC18F
				#define	ROTROUNDS	7
			endif
			if PAGESIZEW == 128
				#define	ROTROUNDS	8
			endif
			if PAGESIZEW == 256
				#define	ROTROUNDS	9
			endif
			if PAGESIZEW == 512			;PIC18FJ
				#define	ROTROUNDS	10
			endif
			; Make a copy of address
			movff	TBLPTRU, ttblptru
			movff	TBLPTRH, ttblptrh
			movff	TBLPTRL, ttblptrl
			; Calculate page number of received address
			movlw	ROTROUNDS		;2^6=64=pagesize[bytes]
			#undefine	ROTROUNDS
			movwf	cnt1
			bcf		STATUS, C	;clear carry bit
calcpage	rrcf	ttblptru, 1
			rrcf	ttblptrh, 1
			rrcf	ttblptrl, 1
			decfsz	cnt1
			bra		calcpage			
			; Received page high < bl start page = OK
			movlw	((STARTADDR/(PAGESIZEW*2))>>8)
			subwf	ttblptrh, 0
			bn		blprotok
			; Received page = bl start page
			movlw	((STARTADDR/(PAGESIZEW*2))>>8)
			subwf	ttblptrh, 0
			bnz		chkgt	
			; Received page low < bl start page low = OK		
			movlw	((STARTADDR/(PAGESIZEW*2))&0xff)
			subwf	ttblptrl, 0
			bn		blprotok
			; Received page high > bl end page = OK
chkgt		movlw	(((STARTADDR/(PAGESIZEW*2))+BLSIZEP-1)>>8)
			subwf	ttblptrh, 0
			bz		chkgt2
			bn		chkgt2
			bra		blprotok
			; Received page = bl end page
chkgt2		movlw	(((STARTADDR/(PAGESIZEW*2))+BLSIZEP-1)>>8)
			subwf	ttblptrh, 0
			bnz		proterr	
			; Received page low > bl end page low = OK		
			movlw	(((STARTADDR/(PAGESIZEW*2))+BLSIZEP-1)&0xff)
			subwf	ttblptrl, 0
			bz		proterr
			bn		proterr
			bra		blprotok
			; Protection tripped
proterr		SendL   BLPROT		
		    bra     mainl
		endif
		
		
		;----------------------------------------------------------------------
		; Erase page
		;----------------------------------------------------------------------					
blprotok
erase	btfss 	doerase, 0
        bra     wrloop
		movlw	ERASE_CODE		;setup erase
		rcall 	Write
		clrf	doerase
		
		
		;----------------------------------------------------------------------
		; Write row
		;----------------------------------------------------------------------			
wrloop	movlw 	ROWSIZEB
		movwf 	rowcnt	
		movwf	rowcnt2	
		; Load latches
wrbyte	movff 	POSTINC0, TABLAT
		tblwt	*+
		decfsz 	rowcnt
		bra 	wrbyte		
		; Write
		tblrd	*-				;point back into row
		movlw	WRITE_CODE		
		rcall 	Write
		
		
		;----------------------------------------------------------------------
		; Verify row
		;----------------------------------------------------------------------	
		ifdef WRITE_VER
			lfsr 	FSR0, (buffer+(ROWSIZEB-1))	;load buffer pointer to fsr0
			; Read
verbyte		tblrd	*-		
			movf 	POSTDEC0, w
			; Compare
			cpfseq	TABLAT
			bra		verfail
			; Loop?
			decfsz 	rowcnt2
			bra 	verbyte		
			; Verify succesfull
		endif
		bra 	Main
			
		
		;----------------------------------------------------------------------
		; Erase, write & verify eeprom word
		;----------------------------------------------------------------------			
		ifdef	EEADR
			; Load latch
eeprom		movff	INDF0, EEDATA
			; Write
			movlw 	b'00000100'
			rcall 	Write
			ifdef EWRITE_VER
				; Verify, read byte
				movlw 	b'00000001'
				bsf		EECON1, RD
				movf	INDF0, w
				; Compare
				cpfseq	EEDATA
				bra		verfail
				; Verify succesfull
			endif
			bra 	Main
		endif
		
				
		;----------------------------------------------------------------------
		; Write config byte
		;----------------------------------------------------------------------					
		; Load latch
cfg		movff 	INDF0, TABLAT
		tblwt	*
		; Write
		movlw 	b'11000100'
		rcall 	Write
		; Write finished
		bra		Main
		
				
		;----------------------------------------------------------------------
		; Verify fail
		;----------------------------------------------------------------------
verfail	SendL 	VERFAIL
		bra 	mainl
		
				
		;----------------------------------------------------------------------
		; Checksum error
		;----------------------------------------------------------------------
crcfail	SendL 	CHECKSUMERR
		bra 	mainl
		
		
;------------------------------------------------------------------------------
; Write()
;------------------------------------------------------------------------------		
Write	movwf 	EECON1
		movlw 	0x55
		movwf 	EECON2
		movlw 	0xAA
		movwf 	EECON2
		bsf 	EECON1, WR
		; Wait for write to finish, only needed for eeprom
waitwre	btfsc 	EECON1, WR
		bra 	waitwre
		bcf 	EECON1,WREN		;disable writes
		return		
		

;------------------------------------------------------------------------------
; Functions
;------------------------------------------------------------------------------	
		#include "uart.inc"


;------------------------------------------------------------------------------
; End of code
;
; After reset
; Do not expect the memory to be zero,
; Do not expect registers to be initialised as described in datasheet.
;------------------------------------------------------------------------------			
		end
