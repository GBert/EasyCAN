;------------------------------------------------------------------------------
;
; Can-Can CAN standard RX
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
; Receive standard message on CAN bus and send on UART
;------------------------------------------------------------------------------
RXCAN
                MOVLW   CAN_WIN_RXB0        ; Find an Rx slot
                MOVWF   CANCON
                BTFSC   RXB0CON,RXFUL
                BRA     RXCAN1

                MOVLW   CAN_WIN_RXB1
                MOVWF   CANCON
                BTFSS   RXB0CON,RXFUL
                RETURN
RXCAN1
                MOVLW   STDDATA             ; Standard data
                BTFSC   RXB0DLC,RXRTR
                MOVLW   STDRTR              ; Standard rtr
                PUTC                        ; Tx
 
                RXSID_10_8                  ; Get SID10..8
                CALL    NIB2ASC             ; Tx

                RXSID_7_0                   ; Get SID7..0
                CALL    BIN2ASC             ; Tx

                MOVF    RXB0DLC,W           ; Get DLC
                ANDLW   0x0F
                MOVWF   CANCNT
                IORLW   0x30
                PUTC                        ; Tx

                MOVF    CANCNT,W            ; Get message
                BZ      RXSTD2
                LFSR    FSR0,RXB0D0
RXSTD1
                MOVF    POSTINC0,W
                RCALL   BIN2ASC             ; Tx
                DJNZ    CANCNT,RXSTD1
RXSTD2
                MOVLW   EOLNCHAR
                PUTC                        ; Tx

                BCF     RXB0CON,RXFUL

                INCF    TXCNT,F             ; Tx packet counter++
                BSF     UPIE,UTXIE          ; Enable Tx ring ISR

                RETURN

;------------------------------------------------------------------------------
;
; vim: shiftwidth=4 tabstop=4 softtabstop=4 expandtab
;
