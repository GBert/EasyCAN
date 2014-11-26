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

; UART
#IFDEF UART1
    #IFNDEF TXSTA1
        #DEFINE UPIR        PIR1
        #DEFINE UPIE        PIE1
        #DEFINE URCIF       RCIF
        #DEFINE UTXIF       TXIF
        #DEFINE UTXSTA      TXSTA
        #DEFINE URCSTA      RCSTA
        #DEFINE UTXREG      TXREG
        #DEFINE URCREG      RCREG
        #DEFINE UBAUDCON    BAUDCON
        #DEFINE USPBRGH     SPBRGH
        #DEFINE USPBRG      SPBRG
    #ELSE
        #DEFINE UPIR        PIR1
        #DEFINE UPIE        PIE1
        #DEFINE URCIF       RC1IF
        #DEFINE UTXIF       TX1IF
        #DEFINE UTXSTA      TXSTA1
        #DEFINE URCSTA      RCSTA1
        #DEFINE UTXREG      TXREG1
        #DEFINE URCREG      RCREG1
        #DEFINE UBAUDCON    BAUDCON1
        #DEFINE USPBRGH     SPBRGH1
        #DEFINE USPBRG      SPBRG1
    #ENDIF
#ENDIF
#IFDEF UART2
        #DEFINE UPIR        PIR3
        #DEFINE UPIE        PIE3
        #DEFINE URCIF       RC2IF
        #DEFINE UTXIF       TX2IF
        #DEFINE UTXSTA      TXSTA2
        #DEFINE URCSTA      RCSTA2
        #DEFINE UTXREG      TXREG2
        #DEFINE URCREG      RCREG2
        #DEFINE UBAUDCON    BAUDCON2
        #DEFINE USPBRGH     SPBRGH2
        #DEFINE USPBRG      SPBRG2
#ENDIF

; UART Baud Rate Generator
#DEFINE         UBAUD       ((((CLOCK / BAUDRATE) / 2) - 1) / 2)

;------------------------------------------------------------------------------
; Init. UART
;------------------------------------------------------------------------------
INITUART
                BCF     TRISC,6
                BSF     TRISC,7
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
