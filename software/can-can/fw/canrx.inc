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
; MCHP CAN
;------------------------------------------------------------------------------

; RXB0DLC
; -------
; X RXRTR 0 0 DLC3 DLC2 DLC2 DLC0

;------------------------------------------------------------------------------
; CAN RX variables
;------------------------------------------------------------------------------

;               CBLOCK
;               ENDC

;------------------------------------------------------------------------------
; Receive message on CAN bus and send on UART
;------------------------------------------------------------------------------
RXCAN
                MOVLW   CAN_WIN_RXB0
                MOVWF   CANCON
                BTFSC   RXB0CON,RXFUL
                BRA     RXCANRECV           ; RXB0 full...

                MOVLW   CAN_WIN_RXB1
                MOVWF   CANCON
                BTFSC   RXB0CON,RXFUL
                BRA     RXCANRECV           ; RXB1 full...

                RETURN

;------------------------------------------------------------------------------

RXCANRECV

RXSTDDATA
                MOVLW   STDDATA             ; Standard data message
                PUTC
 
                RXSID_10_8                  ; Get SID10..8

                LFSR    FSR0,TEMP1               
                CALL    NIB2ASC             ; Tx

                RXSID_7_3                   ; Get SID7..3
                RXSID_2_0                   ; Get SID2..0

                LFSR    FSR0,TEMP1               
                CALL    BIN2ASC             ; Tx

                MOVF    RXB0DLC,W
                ANDLW   0x0F
                MOVWF   CANCNT              ; Number of bytes

                IORLW   0x30                ; Convert to ASCII
                PUTC                        ; Tx

                MOVF    CANCNT,W
                BZ      RXSTDDATAEND        ; Empty message...

                LFSR    FSR0,RXB0D0         ; Get message
RXSTDDATA1
                RCALL   BIN2ASC             ; Tx
                DJNZ    CANCNT,RXSTDDATA1
RXSTDDATAEND
                MOVLW   EOLNCHAR            ; \r
                PUTC

                BCF     RXB0CON,RXFUL
                RETURN

;------------------------------------------------------------------------------
;
; vim: shiftwidth=4 tabstop=4 softtabstop=4 expandtab
;
