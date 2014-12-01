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
                CANCMD  : 1
                CANID   : 1
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

#DEFINE         CAN_WIN_OFF  0x00           ; 000X
#DEFINE         CAN_WIN_RXB0 0x0C           ; 110X
#DEFINE         CAN_WIN_RXB1 0x0A           ; 101X
#DEFINE         CAN_WIN_TXB0 0x08           ; 100X
#DEFINE         CAN_WIN_TXB1 0x06           ; 011X
#DEFINE         CAN_WIN_TXB2 0x04           ; 010X

#INCLUDE        "canrates.inc"
#INCLUDE        "canid.inc"

;------------------------------------------------------------------------------
; Init. CAN bus
;------------------------------------------------------------------------------
INITCAN
                BCF     TRISB,RB2           ; set CANTX input
                BSF     TRISB,RB3           ; Enable CANRX

                MOVLW   (1 << REQOP2)       ; Set configuration mode
                MOVWF   CANCON
INITCAN1
                MOVF    CANSTAT,W
                ANDLW   (1 << OPMODE2)
                BZ      INITCAN1

                BANKSEL RXM0SIDH            ; Set standard receive masks for RXB0/1
                CLRF    RXM0SIDH
                CLRF    RXM1SIDH
                CLRF    RXM0SIDL
                CLRF    RXM1SIDL

                BANKSEL RXM0EIDH            ; Set extended receive masks for RXB0/1
                CLRF    RXM0EIDH
                CLRF    RXM1EIDH
                CLRF    RXM0EIDL
                CLRF    RXM1EIDL

                BANKSEL RXF0SIDH            ; Set standard receive filters for RXB0
                CLRF    RXF0SIDH
                CLRF    RXF1SIDH
                MOVLW   (1 << EXIDEN)
                MOVWF   RXF0SIDL
                MOVWF   RXF1SIDL

                BANKSEL RXF2SIDH            ; Set standard receive filters for RXB1
                CLRF    RXF2SIDH
                CLRF    RXF3SIDH
                CLRF    RXF4SIDH
                CLRF    RXF5SIDH
                MOVLW   0
                MOVWF   RXF2SIDL
                MOVWF   RXF3SIDL
                MOVWF   RXF4SIDL
                MOVWF   RXF5SIDL

                BANKSEL BRGCON1             ; Set bit rate
                MOVLW   BRG1
                MOVWF   BRGCON1
                MOVLW   BRG2
                MOVWF   BRGCON2
                MOVLW   BRG3
                MOVWF   BRGCON3

                BANKSEL CIOCON              ; Enable CANTX
                BSF     CIOCON,ENDRHI

                CLRF    RXB0CON             ; Reset receiver
                CLRF    RXB1CON             ; Reset receiver
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

#DEFINE         STDDATA     't'             ; 0x74 0111 0100
#DEFINE         STDRTR      'r'             ; 0x72 0111 0010
#DEFINE         EXTDATA     'T'             ; 0x54 0101 0100
#DEFINE         EXTRTR      'R'             ; 0x52 0101 0010

; C\r
; |
; O | C | F

#DEFINE         OPENCMD     'O'
#DEFINE         CLOSECMD    'C'
#DEFINE         READSTATUS  'F'

;------------------------------------------------------------------------------
; CAN bus functions
;------------------------------------------------------------------------------

#INCLUDE        "canrx.inc"
#INCLUDE        "cantx.inc"

;------------------------------------------------------------------------------
;
; vim: shiftwidth=4 tabstop=4 softtabstop=4 expandtab
;
