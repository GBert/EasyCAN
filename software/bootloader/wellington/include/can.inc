;------------------------------------------------------------------------------
;
; Title:            The Wellington Boot Loader for PIC18
;
; File description: CAN bus functions
;
; Copyright:        Copyright (c) 2009-2012 Mikael Gustafsson
;                   Copyright (c) Fabien Pieraldi
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
; CAN Bus
;------------------------------------------------------------------------------

#IFNDEF HAS_CAN
    ERROR       "CAN Bus not available on this device"
#ENDIF

ERROR           "CAN Bus not implemented"

;------------------------------------------------------------------------------
; COMMINIT() NOT IMPLEMENTED
;------------------------------------------------------------------------------

COMMINIT
                BSF     PORTB, RB2
                BCF     TRISB, RB2

                MOVLB   15
                MOVLW   b'00000001'
                MOVWF   TXB0DLC,BANKED

                ;xxx If transmit ID & receive ID are the same then comment lines marked with * (free 2 instructions)

                MOVLW   (ID_LOADER<<5)&0xE0 ;Load SID2:SID0, EXIDE = 0 / User configure transmit ID     
                MOVWF   TXB0SIDL,BANKED
                MOVLW   (ID_PIC<<5)&0xE0    ;Load SID2:SID0, EXIDE = 0 / User configure receive ID *
                MOVWF   RXF0SIDL, BANKED

                MOVLW   ID_LOADER>>3        ;Load SID10:SID3 / User configure transmit ID
                MOVWF   TXB0SIDH,BANKED
                MOVLW   ID_PIC>>3           ;Load SID10:SID3 / User configure receive ID *
                MOVWF   RXF0SIDH, BANKED

                MOVLW   b'11111111'         ;Prevent filter 1 from causing a receive event
                MOVWF   RXF1SIDL
                MOVWF   RXM0SIDH            ;Set mask
                MOVLW   b'11100000'
                MOVWF   RXM0SIDL
                MOVLB   0                   ;Set bit rate

                MOVLW   b'00000001'         ;xxx User configure Baudrate (Default 500kBd with HSPLL and 10MHz crystal)
                MOVWF   BRGCON1
                MOVLW   b'11111010'         ;xxx User configure Baudrate
                MOVWF   BRGCON2
                MOVLW   b'00000111'         ;xxx User configure Baudrate
                MOVWF   BRGCON3
                BSF     CIOCON, ENDRHI
                CLRF    CANCON              ;Enter Normal mode

                MOVLB   0
                RETURN

;------------------------------------------------------------------------------
; COMMEXIT() NOT IMPLEMENTED
;------------------------------------------------------------------------------

COMMEXIT
                BANKSEL CANCON
                ;reset receive status and control register
                BSF     CANCON,REQOP2

                MOVLB   0
                RETURN

;------------------------------------------------------------------------------
; Receive() NOT IMPLEMENTED
;------------------------------------------------------------------------------

Receive
                BEGINTO
RecvLoop        BTFSC   RXB0CON,RXFUL       ;Does RXB0 contain a message?
                BRA     Received
                LOOPTO  RecvLoop
                BRA     Exit                ;timed-out
Received
                MOVF    RXB0D0,W            ;RETURN read data in W
                ADDWF   csum,F              ;compute checksum
                BCF     RXB0CON,RXFUL
                RETURN

;------------------------------------------------------------------------------
; Send() NOT IMPLEMENTED
;------------------------------------------------------------------------------

Send
                MOVLB   15                  ;One BANKSEL
                MOVWF   TXB0D0,BANKED
                BSF     TXB0CON,TXREQ       ;Normal priority
                                            ;Request transmission
                ;If required, wait for message to get transmitted
txwait          BTFSC   TXB0CON,TXREQ,BANKED;Is it transmitted?
                BRA     txwait              ;No.  Continue to wait...

                ; Send complete
                MOVLB   0
                RETURN

;------------------------------------------------------------------------------    
;
; vim: ft=asm shiftwidth=4 tabstop=4 softtabstop=4 expandtab
;
