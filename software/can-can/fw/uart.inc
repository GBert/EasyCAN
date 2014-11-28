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
        #DEFINE URCIF       RCIF
        #DEFINE UTXIF       TXIF

        #DEFINE UPIE        PIE1
        #DEFINE URCIE       RCIE
        #DEFINE UTXIE       TXIE

        #DEFINE UIPR        IPR1
        #DEFINE URCIP       RCIP
        #DEFINE UTXIP       TXIP

        #DEFINE UTXSTA      TXSTA
        #DEFINE URCSTA      RCSTA
        #DEFINE UTXREG      TXREG
        #DEFINE URCREG      RCREG

        #DEFINE UBAUDCON    BAUDCON
        #DEFINE USPBRGH     SPBRGH
        #DEFINE USPBRG      SPBRG
    #ELSE
        #DEFINE UPIR        PIR1
        #DEFINE URCIF       RC1IF
        #DEFINE UTXIF       TX1IF

        #DEFINE UPIE        PIE1
        #DEFINE URCIE       RC1IE
        #DEFINE UTXIE       TX1IE

        #DEFINE UIPR        IPR1
        #DEFINE URCIP       RC1IP
        #DEFINE UTXIP       TX1IP

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
        #DEFINE URCIF       RC2IF
        #DEFINE UTXIF       TX2IF

        #DEFINE UPIE        PIE3
        #DEFINE URCIE       RC2IE
        #DEFINE UTXIE       TX2IE

        #DEFINE UIPR        IPR3
        #DEFINE URCIP       RC2IP
        #DEFINE UTXIP       TX2IP

        #DEFINE UTXSTA      TXSTA2
        #DEFINE URCSTA      RCSTA2
        #DEFINE UTXREG      TXREG2
        #DEFINE URCREG      RCREG2

        #DEFINE UBAUDCON    BAUDCON2
        #DEFINE USPBRGH     SPBRGH2
        #DEFINE USPBRG      SPBRG2
#ENDIF

; UART Baud Rate Generator (FOSC / BAUDRATE / 4 - 1)
#DEFINE         UBAUD       ((((CLOCK / BAUDRATE) / 2) - 1) / 2)

;------------------------------------------------------------------------------
; Init. UART
;------------------------------------------------------------------------------
INITUART
                BCF     TRISC,6             ; set UART ports accordingly
                BSF     TRISC,7

                BSF     UIPR,URCIP          ; Rx high priority
                BCF     UIPR,UTXIP          ; Tx low priority

                MOVLW   (1 << BRG16)
                MOVWF   UBAUDCON

                MOVLW   HIGH (UBAUD)
                MOVWF   USPBRGH
                MOVLW   LOW  (UBAUD)
                MOVWF   USPBRG

                ; Enable 9-bit Mode + Enable Transmit + High Speed Mode + BIT9 = 1
                MOVLW   (1 << TX9) + (1 << TXEN) + (1 << BRGH) + (1 << TX9D)
                MOVWF   UTXSTA
INITUARTAGAIN
                ; Disable Rx ISR
                BCF     UPIE,URCIE

                ; Enable Serial Port + Disable Receiver
                MOVLW   (1 << SPEN)
                MOVWF   URCSTA

                ; Enable Receiver
                BSF     URCSTA,CREN

                ; Flush Receiver
                MOVF    URCREG,W
                MOVF    URCREG,W
                MOVF    URCREG,W
                
                ; Enable Rx ring ISR
                BSF     UPIE,URCIE

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
