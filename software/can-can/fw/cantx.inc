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
; Receive message on UART and send on CAN bus
;------------------------------------------------------------------------------
TXCAN
                MOVF    EOLNCNT,W           ; Message Received?
                BNZ     TXCANSEND1
                RETURN

TXCANSEND1
                MOVLW   CAN_WIN_TXB0
                MOVWF   CANCON
                BTFSS   RXB0CON,TXREQ
                BRA     TXCANSEND2

                MOVLW   CAN_WIN_TXB1
                MOVWF   CANCON
                BTFSS   RXB0CON,TXREQ
                BRA     TXCANSEND2

                MOVLW   CAN_WIN_TXB2
                MOVWF   CANCON
                BTFSS   RXB0CON,TXREQ
                BRA     TXCANSEND2

                RETURN                      ; No buffer space

TXCANSEND2
                GETC                        ; W = <RXBUF>,RXGET++

                MOVWF   TEMP1
                XORLW   STDDATA             ; t
                BZ      TXSTDDATA

                MOVF    TEMP1,W
                XORLW   STDRTR              ; r
                BZ      TXSTDRTR

                MOVF    TEMP1,W
                XORLW   EXTDATA             ; T
                BZ      TXEXTDATA

                MOVF    TEMP1,W
                XORLW   EXTRTR              ; R
                BZ      TXEXTRTR

TXSTDRTR                                    ; UNSUPPORTED
TXEXTDATA                                   ; UNSUPPORTED
TXEXTRTR                                    ; UNSUPPORTED

TXCANEND
                GETC                        ; W = <RXBUF>,RXGET++
                XORLW   EOLNCHAR
                BNZ     TXCANEND

                DECF    EOLNCNT,F

                RETURN                      ; Message processed.

;------------------------------------------------------------------------------
; Send Standard CAN Data Message
;------------------------------------------------------------------------------

TXSTDDATA
;
; Set standard transmit id
;
                LFSR    FSR0,TEMP2
                RCALL   ASC2NIB
 
                MOVF    TEMP2,W
                TXSID_10_8

                LFSR    FSR0,TEMP2
                RCALL   ASC2BIN
 
                MOVF    TEMP2,W
                TXSID_7_3

                MOVF    TEMP2,W
                TXSID_2_0
;
; Set data length code
;
                LFSR    FSR0,TEMP2
                RCALL   ASC2NIB
 
                MOVF    TEMP2,W
                MOVWF   RXB0DLC
                BZ      TXSTDDATA2
;
; Set buffer
;
                MOVWF   CANCNT
                LFSR    FSR0,RXB0D0
TXSTDDATA1
                RCALL   ASC2BIN
                DJNZ    CANCNT,TXSTDDATA1
;
; Mark for transmission
;
TXSTDDATA2
                BSF     RXB0CON,TXREQ
                BRA     TXCANEND

;------------------------------------------------------------------------------
;
; vim: shiftwidth=4 tabstop=4 softtabstop=4 expandtab
;
