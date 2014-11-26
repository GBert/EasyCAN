;------------------------------------------------------------------------------
;
; Can-Can CAN standard TX
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
; Receive standard message on UART and send on CAN bus
;------------------------------------------------------------------------------
TXCAN
                MOVF    RXCNT,W             ; If Rx packet counter > 0
                BNZ     TXCAN1
                RETURN
TXCAN1
                MOVLW   CAN_WIN_TXB0        ; Find a Tx slot
                MOVWF   CANCON
                BTFSS   RXB0CON,TXREQ
                BRA     TXCAN2

                MOVLW   CAN_WIN_TXB1
                MOVWF   CANCON
                BTFSS   RXB0CON,TXREQ
                BRA     TXCAN2

                MOVLW   CAN_WIN_TXB2
                MOVWF   CANCON
                BTFSC   RXB0CON,TXREQ
                RETURN
TXCAN2
                GETC                        ; W = <RXBUF>,RXGET++
                MOVWF   CANCMD
                XORLW   STDDATA             ; t?
                BZ      TXCANSTD
                MOVF    CANCMD,W            ; r?
                XORLW   STDRTR
                BNZ     TXCANEND
TXCANSTD
                RCALL   ASC2NIB             ; GETC
                TXSID_10_8                  ; Set SID10..8
                LFSR    FSR0,CANID
                RCALL   ASC2BIN             ; GETC, GETC
                MOVF    CANID,W
                TXSID_7_3                   ; Set SID7..3
                MOVF    CANID,W
                TXSID_2_0                   ; Set SID2..0

                CLRF    RXB0DLC             ; Set RTR
                BTFSC   CANCMD,1            ; r?
                BSF     RXB0DLC,RXRTR

                RCALL   ASC2NIB             ; GETC
                BZ      TXCANSTD2
                MOVWF   CANCNT
                IORWF   RXB0DLC,F           ; Set DLC

                LFSR    FSR0,RXB0D0
TXCANSTD1
                RCALL   ASC2BIN             ; Set data
                DJNZ    CANCNT,TXCANSTD1
TXCANSTD2
                BSF     RXB0CON,TXREQ       ; Tx
TXCANEND
                GETC                        ; W = <RXBUF>,RXGET++
                XORLW   EOLNCHAR
                BNZ     TXCANEND

                DECF    RXCNT,F             ; Rx packet counter--
                RETURN

;------------------------------------------------------------------------------
;
; vim: shiftwidth=4 tabstop=4 softtabstop=4 expandtab
;
