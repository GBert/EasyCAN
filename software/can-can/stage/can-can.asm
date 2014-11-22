;------------------------------------------------------------------------------
;
; Title:        Do the Can-can
;
; Copyright:    Copyright (c) 2014 Darron M Broad
;
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
;   This file is part of Can-can.
;
;   Can-can is free software: you can redistribute it and/or
;   modify it under the terms of the GNU General Public License as published
;   by the Free Software Foundation.
;
;   Can-can is distributed in the hope that it will be
;   useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
;   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
;   GNU General Public License for more details.
;
;   You should have received a copy of the GNU General Public License along
;   with Can-can. If not, see http://www.gnu.org/licenses/
;------------------------------------------------------------------------------

                RADIX   DEC

;------------------------------------------------------------------------------
; Device
;------------------------------------------------------------------------------

                PROCESSOR  18f26k80

;------------------------------------------------------------------------------
; Device Constants
;------------------------------------------------------------------------------

#INCLUDE        "devices.inc"                   ; Wellington Boot Loader
                ERRORLEVEL  -302
                LIST

;------------------------------------------------------------------------------
; MCU Settings
;------------------------------------------------------------------------------

; Clock Rates
#DEFINE         CLOCK       64000000
#DEFINE         TCY         (CLOCK / 4)
#DEFINE         BAUDRATE    (460800)

; TMR2 Interval. 1:1 Postscale, Prescaler 16.
;
; PR = (TCY / (BAUDRATE / 10) / SCALER) - 1
;
#DEFINE         TMR2_PR     (TCY / (BAUDRATE / 10) / 16) - 1

; Advanced LED Diags.
#DEFINE         LLED        LATA
#DEFINE         LTRIS       TRISA

; UART
#DEFINE         UPIR        PIR1                ; 1 or 3
#DEFINE         UPIE        PIE1                ; Unused
#DEFINE         URCIF       RCIF
#DEFINE         UTXIF       TXIF
#DEFINE         UTXSTA      TXSTA
#DEFINE         URCSTA      RCSTA
#DEFINE         UTXREG      TXREG
#DEFINE         URCREG      RCREG
#DEFINE         UBAUDCON    BAUDCON1
#DEFINE         USPBRGH     SPBRGH1
#DEFINE         USPBRG      SPBRG

; UART Baud Rate
#DEFINE         UBAUD       ((((CLOCK / BAUDRATE) / 2) - 1) / 2)

; SLCAND Protocol
#DEFINE         EOLNCHAR    0x0D                ; CR

;------------------------------------------------------------------------------
; Variables
;------------------------------------------------------------------------------

                CBLOCK  0x0000
                RXGET   : 1                     ; Rx Ring
                RXPUT   : 1
                TXGET   : 1                     ; Tx Ring
                TXPUT   : 1

                EOLNCNT : 1                     ; EOLN Counter

                TEMP1   : 1
                TEMP2   : 1
                ENDC

;0100:  80 81 82 83 84 85 86 87 88 89 8a 8b 8c 8d 8e 8f    ................
;0110:  90 91 92 93 94 95 96 97 98 99 9a 9b 9c 9d 9e 9f    ................
;0120:  a0 a1 a2 a3 a4 a5 a6 a7 a8 a9 aa ab ac ad ae af    ................
;0130:  b0 b1 b2 b3 b4 b5 b6 b7 b8 b9 ba bb bc bd be bf    ................
;0140:  c0 c1 c2 c3 c4 c5 c6 c7 c8 c9 ca cb cc cd ce cf    ................
;0150:  d0 d1 d2 d3 d4 d5 d6 d7 d8 d9 da db dc dd de df    ................
;0160:  e0 e1 e2 e3 e4 e5 e6 e7 e8 e9 ea eb ec ed ee ef    ................
;0170:  f0 f1 f2 f3 f4 f5 f6 f7 f8 f9 fa fb fc fd fe ff    ................
;0180:  00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f    ................
;0190:  10 11 12 13 14 15 16 17 18 19 1a 1b 1c 1d 1e 1f    ................
;01a0:  20 21 22 23 24 25 26 27 28 29 2a 2b 2c 2d 2e 2f     !"#$%&'()*+,-./
;01b0:  30 31 32 33 34 35 36 37 38 39 3a 3b 3c 3d 3e 3f    0123456789:;<=>?
;01c0:  40 41 42 43 44 45 46 47 48 49 4a 4b 4c 4d 4e 4f    @ABCDEFGHIJKLMNO
;01d0:  50 51 52 53 54 55 56 57 58 59 5a 5b 5c 5d 5e 5f    PQRSTUVWXYZ[\]^_
;01e0:  60 61 62 63 64 65 66 67 68 69 6a 6b 6c 6d 6e 6f    `abcdefghijklmno
;01f0:  70 71 72 73 74 75 76 77 78 79 7a 7b 7c 7d 7e 7f    pqrstuvwxyz.....

                CBLOCK  0x0100
                RXBUF   : 128               ; Rx Ring
                TXBUF   : 128               ; Tx Ring
                ENDC

;------------------------------------------------------------------------------
; Reset
;------------------------------------------------------------------------------

                ORG     0x0000
                GOTO    INIT
                ORG     0x0008
                GOTO    ISR
                ORG     0x0018

;------------------------------------------------------------------------------
; ISR
; 
;  Affects RXPUT, TXGET & uses FSR2; do not use these elsewhere.
;------------------------------------------------------------------------------
ISR
                BTG     LLED,0              ; Blink LED 1!

                MOVF    TXGET,W             ; Data?
                XORWF   TXPUT,W
                BZ      ISRRX

                BTFSS   UPIR,UTXIF          ; Tx?
                BRA     ISRRX

                MOVF    TXGET,W
                MOVFF   PLUSW2,UTXREG
                INCF    TXGET,F
                BCF     TXGET,7
ISRRX
                BTFSS   UPIR,URCIF          ; Rx?
                BRA     ISREND

                MOVF    RXPUT,W
                MOVFF   URCREG,PLUSW2
                INCF    RXPUT,F
                BSF     RXPUT,7

                MOVF    PLUSW2,W            ; EOLN?
                XORLW   EOLNCHAR
                BNZ     ISREND
                INCF    EOLNCNT
ISREND
                BCF     PIR1,TMR2IF         ; Reset TMR2 ISR
                RETFIE  FAST

;------------------------------------------------------------------------------
; Init. UART
;------------------------------------------------------------------------------
INITUART
                MOVLW   (1 << BRG16)
                MOVWF   UBAUDCON

                MOVLW   HIGH (UBAUD)
                MOVWF   USPBRGH
                MOVLW   LOW  (UBAUD)
                MOVWF   USPBRG

                ; Enable Transmit + High Speed Mode
                MOVLW   (1 << TXEN) + (1 << BRGH)
                MOVWF   UTXSTA
INITUARTAGAIN
                ; Enable Serial Port
                MOVLW   (1 << SPEN)
                MOVWF   URCSTA

                ; Enable Receiver
                BSF     URCSTA,CREN

                MOVF    URCREG,W
                MOVF    URCREG,W
                MOVF    URCREG,W

                RETURN

;------------------------------------------------------------------------------
; Init. TMR2. 1:1 Postscale, Prescaler 16.
;------------------------------------------------------------------------------
INITTMR2
                CLRF    TMR2               
                MOVLW   TMR2_PR
                MOVWF   PR2

                MOVLW   (1 << TMR2ON) + (1 << T2CKPS1)
                MOVWF   T2CON

                BSF     PIR1,TMR2IF
                BSF     PIE1,TMR2IE

                RETURN

;------------------------------------------------------------------------------
; Init. Rx/Tx Ring
;------------------------------------------------------------------------------
INITRING
                CLRF    EOLNCNT             ; Reset EOLN Counter

                LFSR    2,TXBUF             ; FSR2 H/L Reserved for Ring

                MOVLW   0x80                ; Rx Index 0
                MOVWF   RXGET
                MOVWF   RXPUT

                CLRF    TXGET               ; Tx Index 0
                CLRF    TXPUT

                RETURN

;------------------------------------------------------------------------------
; Init.
;------------------------------------------------------------------------------
INIT
                MOVLB   15

                BCF     RCON,IPEN           ; Reset ISR
                CLRF    INTCON
                CLRF    PIE1
                CLRF    PIR1

                CLRF    LLED                ; Init. LEDs
                CLRF    LTRIS

                RCALL   INITUART            ; Init. UART
                RCALL   INITTMR2            ; Init. Timer2
                RCALL   INITRING            ; Init. Rx/Tx Ring

                BSF     INTCON,PEIE         ; Init. ISR
                BSF     INTCON,GIE
               
;------------------------------------------------------------------------------
; Main
;------------------------------------------------------------------------------
MAIN
                BTG     LLED,1              ; Blink LED 2!

                BTFSC   URCSTA,OERR
                BRA     RXERR

                BTFSC   URCSTA,FERR
                BRA     RXERR
HELLOWORLD
                MOVF    EOLNCNT,W
                BZ      MAIN

                BTG     LLED,2              ; Blink LED 3!

                RCALL   RXGETW
                BZ      MAIN
 
                RCALL   TXPUTW

                XORLW   EOLNCHAR
                BNZ     HELLOWORLD

                DECF    EOLNCNT
                BRA     MAIN

RXERR
                BTG     LLED,3              ; Blink LED 4!

                RCALL   INITUARTAGAIN
                BRA     MAIN

;------------------------------------------------------------------------------
; Rx Get
;------------------------------------------------------------------------------
RXGETW
                MOVF    RXGET,W
                XORWF   RXPUT,W
                BZ      RXNONE

                MOVF    RXGET,W
                MOVF    PLUSW2,W

                INCF    RXGET,F
                BSF     RXGET,7

                BCF     STATUS,Z
RXNONE
                RETURN

;------------------------------------------------------------------------------
; Tx Put
;------------------------------------------------------------------------------
TXPUTW
                MOVWF   TEMP1
                
                MOVF    TXPUT,W
                MOVFF   TEMP1,PLUSW2

                INCF    TXPUT,F
                BCF     TXPUT,7

                MOVF    TEMP1,W
                RETURN

;------------------------------------------------------------------------------
; ASCII hexadecimal to binary, by Peter F.
;
; Convert 2 hex ASCII characters to an 8-bit value.
;
; ASCII stored in TEMP1/2, result returned in W, TEMP1/2 are unchanged.
;------------------------------------------------------------------------------
ASCII2BYTE
                SWAPF   TEMP1,W             ; swap hi nibble into result
                BTFSC   TEMP1,6             ; check if in range 'A'-'F'
                ADDLW   0x8F                ; add correction SWAPF ('1'-'A'+1)
                ADDWF   TEMP2,W             ; add lo nibble
                BTFSC   TEMP2,6             ; check if in range 'A'-'F'
                ADDLW   0xF9                ; add correction '9'-'A'+1
                ADDLW   0xCD                ; adjust final result -0x33
                RETURN

;------------------------------------------------------------------------------
; 8 Bit Binary to 2 ASCII digits, by Scott Dattalo.
;
; Take a number in the range of 0x00 to 0xFF in W and output two ASCII
; characters, the most significant character into CHAR_HI and the least
; significant into W. No other registers can be used.
;------------------------------------------------------------------------------
BYTE2ASCII
                MOVWF   TEMP1
                SWAPF   TEMP1,W

                ANDLW   0x0f
                ADDLW   6
                BTFSC   STATUS,DC
                ADDLW   'A'-('9'+1)
                ADDLW   '0'-6

                XORWF   TEMP1,W
                XORWF   TEMP1,F
                XORWF   TEMP1,W

                ANDLW   0x0f
                ADDLW   6
                BTFSC   STATUS,DC
                ADDLW   'A'-('9'+1)
                ADDLW   '0'-6

                MOVWF   TEMP2
                RETURN

;------------------------------------------------------------------------------
                END
;------------------------------------------------------------------------------
;
; vim: shiftwidth=4 tabstop=4 softtabstop=4 expandtab
;
