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
                TEMP3   : 1
                ENDC

;------------------------------------------------------------------------------
; CAN Settings
;------------------------------------------------------------------------------

; Serial Line CAN (SLCAN) Protocol 
;
; TSSSEEEEEX1122334455667788\r
; |   |    |       |        |
; |   ID   DLC     DATA     EOLN
; |
; t--data frame with 11-bit ID
; r--RTR  frame with 11-bit ID
; T--data frame with 29-bit ID
; R--RTR  frame with 29-bit ID
;
#DEFINE         STDDATA     't'
#DEFINE         STDRTR      'r'
#DEFINE         EXTDATA     'T'
#DEFINE         EXTRTR      'r'

; CANCON bits missing for PIC18FXXK80
;
#IFNDEF REQOP0
REQOP0          EQU     H'0005'
REQOP1          EQU     H'0006'
REQOP2          EQU     H'0007'
#ENDIF

#IFNDEF RXB0DBEN
RXB0DBEN        EQU     H'0002'
#ENDIF

; CAN ACCESS Bank Window
;
#DEFINE         CAN_WIN_RXB0 0x00           ; 000X
#DEFINE         CAN_WIN_RXB1 0x0A           ; 101X

#DEFINE         CAN_WIN_TXB0 0x08           ; 100X
#DEFINE         CAN_WIN_TXB1 0x06           ; 011X
#DEFINE         CAN_WIN_TXB2 0x04           ; 010X

; 125kbaud @ 40MHz
;
;#DEFINE         BRG1    0x09
;#DEFINE         BRG2    0xBC
;#DEFINE         BRG3    0x01

; 250kbaud @ 40MHz
;
;#DEFINE BRG1 0x04
;#DEFINE BRG2 0xBC
;#DEFINE BRG3 0x01

; X kbaud @ 64MHz
;
;#DEFINE BRG1 0x01          ; 1000 kbaud
;#DEFINE BRG1 0x03          ;  500 kbaud
#DEFINE BRG1 0x07          ;  250 kbaud
;#DEFINE BRG1 0x0f          ;  125 kbaud
;#DEFINE BRG1 0x13          ;  100 kbaud
;#DEFINE BRG1 0x27          ;   50 kbaud
#DEFINE BRG2 0xBC
#DEFINE BRG3 0x01

; MCHP CAN ID
;
; RXB0SIDH
; SID10 SID9  SID8  SID7  SID6  SID5  SID4  SID3
; EID28 EID27 EID26 EID25 EID24 EID23 EID22 EID21
;
; RXB0SIDL
; SID2  SID1  SID0  SRR   EXID  X     X     X
; EID20 EID19 EID18 SRR   EXID  X     EID17 EID16
;
; RXB0EIDH
; EID15 EID14 EID13 EID12 EID11 EID10 EID9  EID8
;
; RXB0EIDL
; EID7  EID6  EID5  EID4  EID3  EID2  EID1  EID0

; MCHP CAN DLC
;
; RXB0DLC
; X RXRTR 0 0 DLC3 DLC2 DLC2 DLC0

;------------------------------------------------------------------------------
; CAN macros
;------------------------------------------------------------------------------

; Take lower 3-bits in W and store in SID10..SID8, SID7..SID3 are RESET
TXSID_10_8      MACRO   
;               ANDLW   b'00000111'
                RRNCF   WREG,F
                RRNCF   WREG,F
                RRNCF   WREG,F
                MOVWF   RXB0SIDH
                ENDM

; Take upper 5-bits in W and store in SID7..SID3, SID10..SID8 are UNAFFECTED
TXSID_7_3       MACRO   
                ANDLW   b'11111000'
                RRNCF   WREG,F
                RRNCF   WREG,F
                RRNCF   WREG,F
                IORWF   RXB0SIDH,F               
                ENDM

; Take lower 3-bits in W and store in SID2..SID0, SRR & EXID are RESET
TXSID_2_0       MACRO
                ANDLW   b'00000111'
                RRNCF   WREG,F
                RRNCF   WREG,F
                RRNCF   WREG,F
                MOVWF   RXB0SIDL
                ENDM

; Take SID10..SID8 and store in lower 3-bits of TEMP1
RXSID_10_8      MACRO
                MOVF    RXB0SIDH,W
                ANDLW   b'11100000'
                RLNCF   WREG,F
                RLNCF   WREG,F
                RLNCF   WREG,F
                MOVWF   TEMP1
                ENDM

; Take SID7..SID3 and store in upper 5-bits of TEMP1
RXSID_7_3       MACRO
                MOVF    RXB0SIDH,W
                ANDLW   b'00011111'
                RLNCF   WREG,F
                RLNCF   WREG,F
                RLNCF   WREG,F
                MOVWF   TEMP1
                ENDM

; Take SID2..SID0 and store in upper 3-bits of TEMP1
RXSID_2_0       MACRO
                MOVF    RXB0SIDL,W
                ANDLW   b'11100000'
                RLNCF   WREG,F
                RLNCF   WREG,F
                RLNCF   WREG,F
                IORWF   TEMP1,F
                ENDM
                
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
; Receive CAN Message
;------------------------------------------------------------------------------
RXCAN
                MOVLW   CAN_WIN_RXB0
                MOVWF   CANCON
                BTFSC   RXB0CON,RXFUL
                BRA     RXCANRECV

                MOVLW   CAN_WIN_RXB1
                MOVWF   CANCON
                BTFSC   RXB0CON,RXFUL
                BRA     RXCANRECV

                RETURN

RXCANRECV
                MOVLW   STDDATA             ; FIXME
                PUTC
 
                RXSID_10_8
                LFSR    FSR0,TEMP1               
                CALL    NIB2ASC

                RXSID_7_3
                RXSID_2_0
                LFSR    FSR0,TEMP1               
                CALL    BIN2ASC

                MOVF    RXB0DLC,W
                ANDLW   0x0F
                MOVWF   TEMP3

                IORLW   0x30
                PUTC

                MOVF    TEMP3,W
                BZ      RXCANEND
;
; Set buffer
;
                LFSR    FSR0,RXB0D0
RXSTDDATA1
                RCALL   BIN2ASC
                DJNZ    TEMP3,RXSTDDATA1

RXCANEND        MOVLW   EOLNCHAR
                PUTC

                BCF     RXB0CON,RXFUL
                RETURN

;------------------------------------------------------------------------------
; Send CAN Message
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
                MOVWF   TEMP3
                LFSR    FSR0,RXB0D0
TXSTDDATA1
                RCALL   ASC2BIN
                DJNZ    TEMP3,TXSTDDATA1
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
