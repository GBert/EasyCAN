;------------------------------------------------------------------------------
;
; Title:            The Wellington Boot Loader for PIC18
;
; File description: CAN Bus functions
;
; Copyright:        Copyright (c) 2014 The Duke of Welling Town
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

                ; Bits missing for PIC18FXXK80
#IFNDEF REQOP0
REQOP0          EQU     H'0005'
REQOP1          EQU     H'0006'
REQOP2          EQU     H'0007'
RXB0DBEN        EQU     H'0002'
#ENDIF

#IFNDEF CAN_SPEED
    ERROR       "CAN Bus speed not defined"
#ENDIF

#IF CLOCK != 40000000
    #IF CLOCK != 64000000
        ERROR   "CAN Bus speed not calculated"
    #ENDIF
#ENDIF

#IF CLOCK == 40000000
    ; http://www.port.de/en/bit-timing.html
    ;
    ; CAN Rate 20, Sample Point is 87.5%
    ; Fcan = 0.5 * Fosc, SEG2PHTS = 1, SAM = 0
    ;
    ; 500   5   8   6   1   87.5    0x04    0x84    0x00
    ; 250   5   16  13  2   87.5    0x04    0xbc    0x01
    ; 125   10  16  13  2   87.5    0x09    0xbc    0x01
    ; 100   25  8   6   1   87.5    0x18    0x84    0x00
    ; 50    25  16  13  2   87.5    0x18    0xbc    0x01
    #IF CAN_SPEED == 500
        #DEFINE BRG1 0x04
        #DEFINE BRG2 0x84
        #DEFINE BRG3 0x00
    #ENDIF
    #IF CAN_SPEED == 250
        #DEFINE BRG1 0x04
        #DEFINE BRG2 0xBC
        #DEFINE BRG3 0x01
    #ENDIF
    #IF CAN_SPEED == 125
        #DEFINE BRG1 0x09
        #DEFINE BRG2 0xBC
        #DEFINE BRG3 0x01
    #ENDIF
    #IF CAN_SPEED == 100
        #DEFINE BRG1 0x18
        #DEFINE BRG2 0x84
        #DEFINE BRG3 0x00
    #ENDIF
    #IF CAN_SPEED == 50
        #DEFINE BRG1 0x18
        #DEFINE BRG2 0xBC
        #DEFINE BRG3 0x01
    #ENDIF
#ENDIF

#IF CLOCK == 64000000
    ; http://www.port.de/en/bit-timing.html
    ;
    ; CAN Rate 32, Sample Point is 87.5%
    ; Fcan = 0.5 * Fosc, SEG2PHTS = 1, SAM = 0
    ;
    ; 1000  2   16  13  2   87.5    0x01    0xbc    0x01
    ; 500   4   16  13  2   87.5    0x03    0xbc    0x01
    ; 250   8   16  13  2   87.5    0x07    0xbc    0x01
    ; 125   16  16  13  2   87.5    0x0f    0xbc    0x01
    ; 100   20  16  13  2   87.5    0x13    0xbc    0x01
    ; 50    40  16  13  2   87.5    0x27    0xbc    0x01
    #IF CAN_SPEED == 1000
        #DEFINE BRG1 0x01
        #DEFINE BRG2 0xBC
        #DEFINE BRG3 0x01
    #ENDIF
    #IF CAN_SPEED == 500
        #DEFINE BRG1 0x03
        #DEFINE BRG2 0xBC
        #DEFINE BRG3 0x01
    #ENDIF
    #IF CAN_SPEED == 250
        #DEFINE BRG1 0x07
        #DEFINE BRG2 0xBC
        #DEFINE BRG3 0x01
    #ENDIF
    #IF CAN_SPEED == 125
        #DEFINE BRG1 0x0F
        #DEFINE BRG2 0xBC
        #DEFINE BRG3 0x01
    #ENDIF
    #IF CAN_SPEED == 100
        #DEFINE BRG1 0x13
        #DEFINE BRG2 0xBC
        #DEFINE BRG3 0x01
    #ENDIF
    #IF CAN_SPEED == 50
        #DEFINE BRG1 0x27
        #DEFINE BRG2 0xBC
        #DEFINE BRG3 0x01
    #ENDIF
#ENDIF

;------------------------------------------------------------------------------
; COMMINIT()
;------------------------------------------------------------------------------

COMMINIT
                ; The CAN module uses the RB2/CANTX and RB3/CANRX pins to
                ; interface with the CAN bus. In normal mode, the CAN module
                ; automatically overrides TRISB<2>. The user must ensure that
                ; TRISB<3> is set.
#IFDEF CAN_PORTC
                CLRF    TRISC           ;CANTX O/P
                BSF     TRISC,7         ;CANRX I/P
#ELSE
                CLRF    TRISB           ;CANTX O/P
                BSF     TRISB,3         ;CANRX I/P
#ENDIF
                ; Set configuration mode
                BANKSEL CANCON
                MOVLW   1 << REQOP2
                MOVWF   CANCON
COMMINITLOOP1
                MOVF    CANSTAT,W
                ANDLW   (1 << OPMODE2)
                BZ      COMMINITLOOP1

                ; Set mask/filter
                ;
                ; Mask  Filter  Message
                ; 0     x       x       accept
                ; 1     0       0       accept
                ; 1     0       1       reject
                ; 1     1       0       reject
                ; 1     1       1       accept

                ; Set standard receive masks
                BANKSEL RXM0SIDH
                MOVLW   0xFF
                MOVWF   RXM0SIDH    ;For RXB0 with filters 0/1
                MOVWF   RXM1SIDH    ;For RXB1 with filters 2/3/4/5 
                MOVLW   0xE0
                MOVWF   RXM0SIDL
                MOVWF   RXM1SIDL

                ; Set standard receive filters for RXB0
                BANKSEL RXF0SIDH
                MOVLW   CAN_ID >> 3
                MOVWF   RXF0SIDH
                MOVWF   RXF1SIDH
                MOVLW   LOW (CAN_ID << 5)
                MOVWF   RXF0SIDL
                MOVWF   RXF1SIDL

                ; Set standard receive filters for RXB1
                CLRF    RXF2SIDH
                CLRF    RXF2SIDL
                CLRF    RXF3SIDH
                CLRF    RXF3SIDL
                CLRF    RXF4SIDH
                CLRF    RXF4SIDL
                CLRF    RXF5SIDH
                CLRF    RXF5SIDL

                ; Set bit rate
                BANKSEL BRGCON1
                MOVLW   BRG1
                MOVWF   BRGCON1
                MOVLW   BRG2
                MOVWF   BRGCON2
                MOVLW   BRG3
                MOVWF   BRGCON3

                ; Enable CANTX
                BANKSEL CIOCON
                BSF     CIOCON,ENDRHI

                ; Set normal mode
                BANKSEL CANCON
                CLRF    CANCON
COMMINITLOOP2
                MOVF    CANSTAT,W
                ANDLW   (1 << OPMODE2) + (1 << OPMODE1)
                BNZ     COMMINITLOOP2

                MOVLB   0
                RETURN

;------------------------------------------------------------------------------
; COMMEXIT()
;------------------------------------------------------------------------------

COMMEXIT        ;TODO

                RETURN

;------------------------------------------------------------------------------
; Receive()
;------------------------------------------------------------------------------

Receive
                BEGINTO TO3
RecvLoop        BANKSEL RXB0CON
                BTFSC   RXB0CON,RXFUL
                BRA     Recv0
                MOVLB   0
                LOOPTO  RecvLoop
                BRA     TIMEDOUT
Recv0
                MOVF    RXB0D0,W
                BCF     RXB0CON,RXFUL
                MOVLB   0
                RETURN

;------------------------------------------------------------------------------
; Send()
;------------------------------------------------------------------------------

Send
                MOVWF   temp4

                BEGINTO TO3
SendLoop        BANKSEL TXB0CON
                BTFSS   TXB0CON,TXREQ
                BRA     SendData
                MOVLB   0
                LOOPTO  SendLoop
                BRA     TIMEDOUT

SendData        MOVLB   0
                MOVF    temp4,W

                ; Store output data
                BANKSEL TXB0D0
                MOVWF   TXB0D0

                ; Set standard transmit id
                BANKSEL TXB0SIDH
                MOVLW   CAN_ID >> 3
                MOVWF   TXB0SIDH
                MOVLW   LOW (CAN_ID << 5)
                MOVWF   TXB0SIDL

                ; Set data length code to 1 byte
                BANKSEL TXB0DLC
                MOVLW   1
                MOVWF   TXB0DLC

                ; Mark for transmission
                BANKSEL TXB0CON
                MOVLW   1 << TXREQ
                MOVWF   TXB0CON

                MOVLB   0
#IFDEF CAN_DELAYL
                MOVLW   CAN_DELAYL  ;Long delay
                MOVWF   temp1
                CLRF    temp2
SendDelay       DECFSZ  temp2
                BRA     SendDelay
#IFDEF KICK_WD
                CLRWDT
#ENDIF
                DECFSZ  temp1
                BRA     SendDelay
#ENDIF
#IFDEF CAN_DELAYS
                MOVLW   CAN_DELAYS  ;Short delay
                MOVWF   temp1
SendDelay       DECFSZ  temp1
                BRA     SendDelay
#IFDEF KICK_WD
                CLRWDT
#ENDIF
#ENDIF
                RETURN

;------------------------------------------------------------------------------    
;
; vim: ft=asm shiftwidth=4 tabstop=4 softtabstop=4 expandtab
;
