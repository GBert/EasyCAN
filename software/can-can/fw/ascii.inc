;------------------------------------------------------------------------------
;
; Can-Can ASCII conversions
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
; ASCII conversion variables
;------------------------------------------------------------------------------

                CBLOCK
                ASCTEMP : 1
                ENDC

;------------------------------------------------------------------------------
; 0x30 0    0011 0000                           0 0000
; 0x31 1    0011 0001                           1 0001
; 0x32 2    0011 0010                           2 0010
; 0x33 3    0011 0011                           3 0011
; 0x34 4    0011 0100                           4 0100
; 0x35 5    0011 0101                           5 0101
; 0x36 6    0011 0110                           6 0110
; 0x37 7    0011 0111                           7 0111
; 0x38 8    0011 1000                           8 1000
; 0x39 9    0011 1001                           9 1001
; 0x41 A    0100 0001   0x61 a  0110 0001       A 1010
; 0x42 B    0100 0010   0x62 b  0110 0010       B 1011
; 0x43 C    0100 0011   0x63 c  0110 0011       C 1100
; 0x44 D    0100 0100   0x64 d  0110 0100       D 1101
; 0x45 E    0100 0101   0x65 e  0110 0101       E 1110
; 0x46 F    0100 0110   0x66 f  0110 0110       F 1111
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
; Convert ASCII Hex Nibble in <RXBUF> to Binary, Store In <FSR0>
;
; RXGET += 1, FSR0 += 1
;------------------------------------------------------------------------------
ASC2NIB
                RCALL   ASC2BIN1
                MOVWF   POSTINC0
                RETURN               

;------------------------------------------------------------------------------
; Convert ASCII Hex Byte in <RXBUF> to Binary, Store In <FSR0>
;
; RXGET += 2, FSR0 += 1
;------------------------------------------------------------------------------
ASC2BIN
                RCALL   ASC2BIN1
                MOVWF   INDF0
                SWAPF   INDF0,F

                RCALL   ASC2BIN1
                IORWF   POSTINC0
                RETURN               
ASC2BIN1
                GETC                        ; W = <RXBUF>,RXGET++

                MOVWF   ASCTEMP
                ANDLW   0x0F
                BTFSS   ASCTEMP,6
                RETURN

                ADDLW   9
                RETURN

;------------------------------------------------------------------------------
; Convert Binary in <FSR0> to ASCII Hex Nibble or Byte, Store in <TXBUF>
;
; TXPUT += 1 or 2, FSR0 += 1
;------------------------------------------------------------------------------
BIN2ASC                                     ; Byte
                SWAPF   INDF0,W
                RCALL   BIN2ASC1
NIB2ASC                                     ; Nibble
                MOVF    POSTINC0,W
BIN2ASC1
                ANDLW   0x0F                ; W += 48 or W += 55
                ADDLW   6
                BTFSC   STATUS,DC
                ADDLW   7

                ADDLW   42
                PUTC                        ; <TXBUF> = W,TXPUT++
                RETURN

;------------------------------------------------------------------------------
;
; vim: shiftwidth=4 tabstop=4 softtabstop=4 expandtab
;
