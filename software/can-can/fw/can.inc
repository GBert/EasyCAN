;------------------------------------------------------------------------------
;
; Can-Can CAN
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
; CAN variables
;------------------------------------------------------------------------------
    
                CBLOCK
                TEMP1   : 1
                TEMP2   : 1
                CANCNT  : 1
                ENDC

;------------------------------------------------------------------------------
; CAN Settings
;------------------------------------------------------------------------------

#IFNDEF REQOP0
REQOP0          EQU     H'0005'
REQOP1          EQU     H'0006'
REQOP2          EQU     H'0007'
#ENDIF

#IFNDEF RXB0DBEN
RXB0DBEN        EQU     H'0002'
#ENDIF

#INCLUDE        "canrates.inc"
#INCLUDE        "canid.inc"

;------------------------------------------------------------------------------
; Init. CAN bus
;------------------------------------------------------------------------------
INITCAN
                CLRF    TRISB
                BSF     TRISB,RB3           ; Enable CANRX

                MOVLW   (1 << REQOP2)       ; Set configuration mode
                MOVWF   CANCON
INITCAN1
                MOVF    CANSTAT,W
                ANDLW   (1 << OPMODE2)
                BZ      INITCAN1

                BANKSEL RXM0SIDH            ; Set standard receive masks
                CLRF    RXM0SIDH
                CLRF    RXM1SIDH
                CLRF    RXM0SIDL
                CLRF    RXM1SIDL

                CLRF    RXM0EIDH            ; Set extended receive masks
                CLRF    RXM1EIDH
                CLRF    RXM0EIDL
                CLRF    RXM1EIDL

                BANKSEL BRGCON1             ; Set bit rate
                MOVLW   BRG1
                MOVWF   BRGCON1
                MOVLW   BRG2
                MOVWF   BRGCON2
                MOVLW   BRG3
                MOVWF   BRGCON3

                BANKSEL CIOCON              ; Enable CANTX
                BSF     CIOCON,ENDRHI

                BSF     RXB0CON,RXB0DBEN    ; Double buffer

                BCF     RXB0CON,RXFUL       ; Reset
                BCF     RXB1CON,RXFUL       ; Reset

                CLRF    CANCON              ; Set normal mode
INITCAN2
                MOVF    CANSTAT,W
                ANDLW   (1 << OPMODE2) + (1 << OPMODE1)
                BNZ     INITCAN2

                RETURN

;------------------------------------------------------------------------------
; Serial Line CAN (SLCAN) Protocol 
;------------------------------------------------------------------------------

; TSSSEEEEEX1122334455667788\r
; |   |    |       |        |
; |   ID   DLC     DATA     EOLN
; |
; t--data frame with 11-bit ID
; r--RTR  frame with 11-bit ID
; T--data frame with 29-bit ID
; R--RTR  frame with 29-bit ID

#DEFINE         STDDATA     't'
#DEFINE         STDRTR      'r'
#DEFINE         EXTDATA     'T'
#DEFINE         EXTRTR      'r'

; C\r
; |
; O | C | F

#DEFINE         OPENCMD     'O'
#DEFINE         CLOSECMD    'C'
#DEFINE         READSTATUS  'F'

;------------------------------------------------------------------------------
; CAN bus functions
;------------------------------------------------------------------------------

; CAN ACCESS Bank Window
;
#DEFINE         CAN_WIN_RXB0 0x00           ; 000X
#DEFINE         CAN_WIN_RXB1 0x0A           ; 101X

#DEFINE         CAN_WIN_TXB0 0x08           ; 100X
#DEFINE         CAN_WIN_TXB1 0x06           ; 011X
#DEFINE         CAN_WIN_TXB2 0x04           ; 010X

#INCLUDE        "canrx.inc"
#INCLUDE        "cantx.inc"

;------------------------------------------------------------------------------
;
; vim: shiftwidth=4 tabstop=4 softtabstop=4 expandtab
;
