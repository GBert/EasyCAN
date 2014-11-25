;------------------------------------------------------------------------------
;
; Can-Can Rx/Tx ring
;
; Copyright (c) 2014 Darron M Broad
;
;------------------------------------------------------------------------------
;
; This file is part of the Can-Can CAN bus interface project.
;
; Can-Can is licensed under the CC BY-NC-SA 4.0.
;
; See file /LICENSE for details.
; 
;------------------------------------------------------------------------------

                RADIX   DEC

;------------------------------------------------------------------------------
; Rx/Tx ring settings
;------------------------------------------------------------------------------

; End of Line Character
#DEFINE         EOLNCHAR    0x0D            ; CR

;------------------------------------------------------------------------------
; Rx/Tx ring variables
;------------------------------------------------------------------------------

                CBLOCK
                RXGET   : 1                 ; Rx ring
                RXPUT   : 1
                TXGET   : 1                 ; Tx ring
                TXPUT   : 1
                EOLNCNT : 1                 ; EOLN/Packet Counter
                TXTEMP  : 1
                ENDC

;------------------------------------------------------------------------------
; Rx/Tx ring
;------------------------------------------------------------------------------

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

RXBUF           EQU     0x0100              ; Rx ring
TXBUF           EQU     0x0180              ; Tx ring

;------------------------------------------------------------------------------
; Rx/Tx ring macros
;------------------------------------------------------------------------------

GETC            MACRO
                MOVF    RXGET,W
                MOVF    PLUSW2,W

                INCF    RXGET,F             ; RXGET++
                BSF     RXGET,7
                ENDM

PUTC            MACRO
                MOVWF   TXTEMP
                MOVF    TXPUT,W
                MOVFF   TXTEMP,PLUSW2

                INCF    TXPUT,F             ; TXPUT++
                BCF     TXPUT,7
                ENDM

;------------------------------------------------------------------------------
; Rx/Tx ring ISR
; 
;  Affects RXPUT, TXGET & uses FSR2; do not use these elsewhere.
;------------------------------------------------------------------------------
ISR
                BTG     LLED,0              ; LED1
                MOVLB   0x0F                ; Default to Bank 15
#IF 0
                MOVFF   FSR2H,FSR2H_SAVE
                MOVFF   FSR2L,FSR2L_SAVE
                LFSR    FSR2,TXBUF
#ENDIF
                MOVF    TXGET,W             ; Data?
                XORWF   TXPUT,W
                BZ      ISRRX
#IFDEF __18F4685
                BTFSS   UPIR,UTXIF          ; Poll TXIF; Tx?
                BRA     ISRRX
#ENDIF
#IFDEF __18F26K80
                BTFSS   UTXSTA,TRMT         ; Poll TRMT; Tx?
                BRA     ISRRX
#ENDIF
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
#IF 0
                MOVFF   FSR2H_SAVE,FSR2H
                MOVFF   FSR2L_SAVE,FSR2L
#ENDIF
                BCF     PIR1,TMR2IF         ; Reset TMR2 Rx/Tx ring IRQ
                RETFIE  FAST

;------------------------------------------------------------------------------
; Init. Rx/Tx ring
;------------------------------------------------------------------------------
INITRING
#IF 1
                LFSR    FSR2,TXBUF          ; FSR2 H/L Reserved for Ring
#ENDIF
                MOVLW   0x80                ; Rx Index 0
                MOVWF   RXGET
                MOVWF   RXPUT

                CLRF    TXGET               ; Tx Index 0
                CLRF    TXPUT

                CLRF    EOLNCNT             ; Reset EOLN/Packet Counter

                RETURN

;------------------------------------------------------------------------------
;
; vim: shiftwidth=4 tabstop=4 softtabstop=4 expandtab
;
