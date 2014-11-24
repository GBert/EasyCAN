;------------------------------------------------------------------------------
;
; Can-Can UART
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
; UART settings
;------------------------------------------------------------------------------

; UART Baud Rate
#DEFINE         BAUDRATE    (460800)

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

; UART Baud Rate Generator
#DEFINE         UBAUD       ((((CLOCK / BAUDRATE) / 2) - 1) / 2)

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
; Reset UART Conditionally
;------------------------------------------------------------------------------
RESETUART
                BTFSC   URCSTA,OERR         ; Detect UART Overrun Error
                BRA     INITUARTAGAIN

                BTFSC   URCSTA,FERR         ; Detect UART Framing Error
                BRA     INITUARTAGAIN

                RETURN

;------------------------------------------------------------------------------
;
; vim: shiftwidth=4 tabstop=4 softtabstop=4 expandtab
;
