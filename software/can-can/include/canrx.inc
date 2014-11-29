;------------------------------------------------------------------------------
;
; Can-Can CAN RX
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
; Receive message on CAN bus and send on UART
;------------------------------------------------------------------------------
RXCAN
                ; Find an Rx slot
                CLRF    CANCON              ; Window mode off
                BTFSC   RXB0CON,RXFUL
                BRA     RXCAN1

                MOVLW   CAN_WIN_RXB1        ; Window mode on RXB1
                MOVWF   CANCON
                BTFSS   RXB1CON,RXFUL
                RETURN

;------------------------------------------------------------------------------
RXCAN1
                ; If Tx packet counter = trigger Then Drop Packet
                MOVF    TXCNT,W
                XORLW   TXTRIG
                BNZ     RXTST
                BSF     LLED,0              ; LED1 Overflow
                BRA     RXCANCLR            ; Drop Packet

;------------------------------------------------------------------------------
RXTST
                BCF     LLED,0              ; LED1 Okay
                BTFSC   RXB0SIDL,EXID
                BRA     RXEXT

;------------------------------------------------------------------------------

                MOVLW   STDDATA             ; Standard data
                BTFSC   RXB0DLC,RXRTR
                MOVLW   STDRTR              ; Standard rtr
                PUTC                        ; Tx
 
                RXSID_10_8                  ; Get SID10..8
                CALL    NIB2ASC             ; Tx

                RXSID_7_0                   ; Get SID7..0
                CALL    BIN2ASC             ; Tx

                BRA     RXCAN2

;------------------------------------------------------------------------------
RXEXT
                MOVLW   EXTDATA             ; Extended data
                BTFSC   RXB0DLC,RXRTR
                MOVLW   EXTRTR              ; Extended rtr
                PUTC                        ; Tx
 
                RXEXT_28_24                 ; Get EID28..EID24
                CALL    BIN2ASC             ; Tx

                RXEXT_23_16                 ; Get EID23..EID16
                CALL    BIN2ASC             ; Tx

                MOVF    RXB0EIDH,W          ; Get EID15..EID8
                CALL    BIN2ASC             ; Tx

                MOVF    RXB0EIDL,W          ; Get EID7..EID0
                CALL    BIN2ASC             ; Tx

;------------------------------------------------------------------------------
RXCAN2
                MOVF    RXB0DLC,W           ; Get DLC
                ANDLW   0x0F
                MOVWF   CANCNT
                IORLW   0x30
                PUTC                        ; Tx

;------------------------------------------------------------------------------

                MOVF    CANCNT,W            ; Get message
                BZ      RXCAN4

                LFSR    FSR0,RXB0D0
RXCAN3
                MOVF    POSTINC0,W
                RCALL   BIN2ASC             ; Tx
                DJNZ    CANCNT,RXCAN3
RXCAN4
                MOVLW   EOLNCHAR
                PUTC                        ; Tx

                INCF    TXCNT,F             ; Tx packet counter++
                BSF     UPIE,UTXIE          ; Enable Tx ring ISR

;------------------------------------------------------------------------------
RXCANCLR
#IF 0
                MOVF    CANCON,W            ; Clear RXFUL as per MCHP demo
                BNZ     RXCANCLR1
                BCF     RXB0CON,RXFUL
                RETURN
RXCANCLR1       BCF     RXB1CON,RXFUL
                RETURN
#ENDIF
                BCF     RXB0CON,RXFUL       ; Clear RXFUL in window
                RETURN

;------------------------------------------------------------------------------
;
; vim: shiftwidth=4 tabstop=4 softtabstop=4 expandtab
;
