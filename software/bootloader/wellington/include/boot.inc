;------------------------------------------------------------------------------
;
; Title:            The Wellington Boot Loader for PIC18
;
; File description: The Boot Loader
;
; Copyright:        Copyright (c) 2003-2008 Claudiu Chiculita
;                   Copyright (c) 2009-2012 Mikael Gustafsson
;                   Copyright (c) 2014 The Duke of Welling Town
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
;------------------------------------------------------------------------------

                LIST
                RADIX       DEC

;------------------------------------------------------------------------------
; Boot Loader Origin
;------------------------------------------------------------------------------

#IF BOOTSIZE % ERASESIZE
ERASEROWS       EQU         (BOOTSIZE / ERASESIZE) + 1
#ELSE
ERASEROWS       EQU         (BOOTSIZE / ERASESIZE)
#ENDIF
                ; Boot Loader Placement is N Erase Rows from The End
STARTADDR       EQU         MAX_FLASH - (ERASEROWS * ERASESIZE)

;------------------------------------------------------------------------------
; Boot Loader Protocol
;------------------------------------------------------------------------------

#DEFINE         HELLO       0xC1

#DEFINE         OK          'K'
#DEFINE         ERRCHECKSUM 'N'
#DEFINE         ERRCOMMAND  'U'     ;Command Unsupported

#DEFINE         FLASH_ERASE 0       ;1
#DEFINE         FLASH_WRITE 1       ;2
#DEFINE         FLASH_READ  2       ;4
#DEFINE         EE_WRITE    3       ;8
#DEFINE         EE_READ     4       ;16

;------------------------------------------------------------------------------
; Macros
;------------------------------------------------------------------------------

#INCLUDE        "macro.inc"

;------------------------------------------------------------------------------
; Variables
;------------------------------------------------------------------------------

CBLOCK 0
    buffer      : (ROWSIZE + 1) ;One Row + Checksum
    blen        : 1             ;Buffer Length
    csum        : 1             ;Receive Checksum
    cmd         : 1             ;Command
    cnt         : 1             ;Counter
    temp1       : 1             ;Temporary
    temp2       : 1             ;   "
    temp3       : 1             ;   "
    temp4       : 1             ;   "
ENDC

;------------------------------------------------------------------------------
; Reset Vector
;------------------------------------------------------------------------------

                ORG     0

                GOTO    STARTADDR

;------------------------------------------------------------------------------
; GOTO Application
;------------------------------------------------------------------------------

                ORG     STARTADDR - 4

                ; Space to Deposit GOTO Instruction
                NOP
                NOP

;------------------------------------------------------------------------------
; Start of Boot Loader
;------------------------------------------------------------------------------

                ORG     STARTADDR

                PROCINIT            ;Initialise MCU

;------------------------------------------------------------------------------
; Init Comms.
;------------------------------------------------------------------------------

                RCALL   COMMINIT

;------------------------------------------------------------------------------
; Wait for Computer
;------------------------------------------------------------------------------

                RCALL   Receive
                SUBLW   HELLO
                BNZ     TIMEDOUT

;------------------------------------------------------------------------------
; Send Device and Boot Loader Params.
;------------------------------------------------------------------------------

                MOVLW   ROWSIZE
                RCALL   Send

                MOVLW   HIGH  ERASESIZE
                RCALL   Send
                MOVLW   LOW   ERASESIZE
                RCALL   Send

                MOVLW   UPPER STARTADDR
                RCALL   Send
                MOVLW   HIGH  STARTADDR
                RCALL   Send
                MOVLW   LOW   STARTADDR
                RCALL   Send
#IFDEF MAX_EE
                MOVLW   HIGH  MAX_EE
                RCALL   Send
                MOVLW   LOW   MAX_EE
                RCALL   Send
#ELSE
                CLRW
                RCALL   Send
                CLRW
                RCALL   Send
#ENDIF

;------------------------------------------------------------------------------
; Main Loop
;------------------------------------------------------------------------------

MainOK          MOVLW   OK          ;Send OK
MainError       RCALL   Send

                CLRF    csum

;------------------------------------------------------------------------------
; Receive Address
;------------------------------------------------------------------------------

                ; Upper Byte
                RCALL   Receive
                MOVWF   TBLPTRU

                ; High Byte
                RCALL   Receive
                MOVWF   TBLPTRH
#IFDEF EEADRH 
                MOVWF   EEADRH      ;For EEProm
#ENDIF
                ; Low Byte
                RCALL   Receive
                MOVWF   TBLPTRL
#IFDEF EEADR
                MOVWF   EEADR       ;For EEProm
#ENDIF

;------------------------------------------------------------------------------
; Receive Command
;------------------------------------------------------------------------------

                RCALL   Receive
                MOVWF   cmd

;------------------------------------------------------------------------------
; Receive # of Data Bytes
;------------------------------------------------------------------------------

                RCALL   Receive
                MOVWF   blen

;------------------------------------------------------------------------------
; Receive Data Bytes
;------------------------------------------------------------------------------

                ; Load Buffer Pointer to fsr0
                LFSR    FSR0,buffer

                ; Receive Byte Counter
                MOVWF   cnt

ReceiveLoop     RCALL   Receive
                MOVWF   POSTINC0
                DECFSZ  cnt
                BRA     ReceiveLoop

;------------------------------------------------------------------------------
; Validate Checksum
;------------------------------------------------------------------------------

                MOVF    csum,F
                BZ      Command

                MOVLW   ERRCHECKSUM
                BRA     MainError

;------------------------------------------------------------------------------
; Validate Command
;------------------------------------------------------------------------------

Command
                ; Load Buffer Pointer to fsr0
                LFSR    FSR0,buffer

                ; Erase Flash Row
                BTFSC   cmd,FLASH_ERASE
                BRA     EraseFlash

                ; Write Flash Row
                BTFSC   cmd,FLASH_WRITE
                BRA     WriteFlash

                ; Read Flash Byte
                BTFSC   cmd,FLASH_READ
                BRA     ReadFlash

                ; Write EEPROM Byte
                BTFSC   cmd,EE_WRITE
                BRA     WriteEEPROM

                ; Read EEPROM Byte
                BTFSC   cmd,EE_READ
                BRA     ReadEEPROM

                ; Unsupported Command
                MOVLW   ERRCOMMAND
                BRA     MainError

;------------------------------------------------------------------------------
; Erase Flash Row, then Write Flash Row?
;------------------------------------------------------------------------------

EraseFlash      ; Erase
                MOVLW   ERASE_FLASH
                RCALL   Write

;------------------------------------------------------------------------------
; Write Flash Row
;------------------------------------------------------------------------------

WriteFlash      DECF    blen            ;Skip Checksum
                BZ      WriteEmpty      ;No Data

                ; Load Latches
WriteFlashLoop  MOVFF   POSTINC0,TABLAT
                TBLWT   *+
                DECFSZ  blen
                BRA     WriteFlashLoop

                TBLRD   *-              ;Point Back into Row

                ; Write
                MOVLW   WRITE_FLASH
                RCALL   Write
WriteEmpty
                BRA     MainOK

;------------------------------------------------------------------------------
; Read Flash Row
;------------------------------------------------------------------------------

ReadFlash       MOVLW   ROWSIZE
                MOVWF   cnt

ReadFlashLoop   TBLRD   *+
                MOVF    TABLAT,W
                RCALL   Send
                DECFSZ  cnt
                BRA     ReadFlashLoop

                BRA     MainOK

;------------------------------------------------------------------------------
; Write EEPROM Byte
;------------------------------------------------------------------------------

WriteEEPROM     MOVFF   buffer,EEDATA
                ; Write
                MOVLW   (1 << WREN)
                RCALL   Write
                BRA     MainOK

;------------------------------------------------------------------------------
; Read EEPROM Byte
;------------------------------------------------------------------------------

ReadEEPROM      MOVLW   (1 << RD)
                MOVWF   EECON1
                NOP
                MOVF    EEDATA,W
                RCALL   Send
                BRA     MainOK

;------------------------------------------------------------------------------
; Write(W) W = EECON1
;------------------------------------------------------------------------------
Write
                MOVWF   EECON1

                ; Unlock
                MOVLW   0x55
                MOVWF   EECON2
                MOVLW   0xAA
                MOVWF   EECON2

                BSF     EECON1,WR

WriteWait       BTFSC   EECON1,WR
                BRA     WriteWait

                BCF     EECON1,WREN
                RETURN

;------------------------------------------------------------------------------
; End of Boot Loader
;------------------------------------------------------------------------------

TIMEDOUT

;------------------------------------------------------------------------------
; Shutdown Comms.
;------------------------------------------------------------------------------

                RCALL   COMMEXIT

;------------------------------------------------------------------------------
; Run App.
;------------------------------------------------------------------------------

                BRA     STARTADDR - 4

;------------------------------------------------------------------------------
; Comms.
;------------------------------------------------------------------------------

#IFDEF USE_CAN
    #INCLUDE    "can.inc"
#ELSE
    #INCLUDE    "uart.inc"
#ENDIF

;------------------------------------------------------------------------------
;
; vim: ft=asm shiftwidth=4 tabstop=4 softtabstop=4 expandtab
;
