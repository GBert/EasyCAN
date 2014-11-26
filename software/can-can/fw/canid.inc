;------------------------------------------------------------------------------
;
; Can-Can CAN ID
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
; MCHP CAN ID
;------------------------------------------------------------------------------
;
; RXB0SIDH
; --------
; SID10 SID9  SID8  SID7  SID6  SID5  SID4  SID3
;
; EID28 EID27 EID26 EID25 EID24 EID23 EID22 EID21
;
; RXB0SIDL
; --------
; SID2  SID1  SID0  SRR   EXID  X     X     X
;
; EID20 EID19 EID18 SRR   EXID  X     EID17 EID16
;
; RXB0EIDH
; --------
; EID15 EID14 EID13 EID12 EID11 EID10 EID9  EID8
;
; RXB0EIDL
; --------
; EID7  EID6  EID5  EID4  EID3  EID2  EID1  EID0

;------------------------------------------------------------------------------
; MCHP CAN ID macros
;------------------------------------------------------------------------------

; Take lower 3-bits in W and store in SID10..SID8, SID7..SID3 are RESET
TXSID_10_8      MACRO   
                ANDLW   b'00000111'
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

;------------------------------------------------------------------------------

; Take SID10..SID8 and store in lower 3-bits of W
RXSID_10_8      MACRO
                MOVF    RXB0SIDH,W
                ANDLW   b'11100000'
                RLNCF   WREG,F
                RLNCF   WREG,F
                RLNCF   WREG,F
                ENDM

; Take SID7..SID3 and store in upper 5-bits of CANID
RXSID_7_0       MACRO
                MOVF    RXB0SIDH,W
                ANDLW   b'00011111'
                RLNCF   WREG,F
                RLNCF   WREG,F
                RLNCF   WREG,F
                MOVWF   CANID

; Take SID2..SID0 and store in upper 3-bits of W, take lower 5-bits from CANID
                MOVF    RXB0SIDL,W
                ANDLW   b'11100000'
                RLNCF   WREG,F
                RLNCF   WREG,F
                RLNCF   WREG,F
                IORWF   CANID,W
                ENDM

;------------------------------------------------------------------------------
;
; vim: shiftwidth=4 tabstop=4 softtabstop=4 expandtab
;
