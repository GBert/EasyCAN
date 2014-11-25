;------------------------------------------------------------------------------
;
; Can-Can TMR2
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
; TMR2 Settings
;------------------------------------------------------------------------------

#DEFINE         TCY         (CLOCK / 4)

; TMR2 Interval. 1:1 Postscale, Prescaler 16.

; For the 18F4685 we poll TXIF.
#IFDEF __18F4685
#DEFINE         TMR2_PR     (TCY / (BAUDRATE / 10) / 16) - 1
#ENDIF

; For the 18F26K80 we poll TRMT. This must be done more often than TXIF.
#IFDEF __18F26K80
#DEFINE         TMR2_PR     (TCY / (BAUDRATE / 10) / 20)
#ENDIF

;------------------------------------------------------------------------------
; Init. TMR2. 1:1 Postscale, Prescaler 16.
;------------------------------------------------------------------------------
INITTMR2
                CLRF    TMR2               
                MOVLW   TMR2_PR
                MOVWF   PR2

                MOVLW   (1 << TMR2ON) + (1 << T2CKPS1)
                MOVWF   T2CON

                BSF     PIR1,TMR2IF
                BSF     PIE1,TMR2IE

                RETURN

;------------------------------------------------------------------------------
;
; vim: shiftwidth=4 tabstop=4 softtabstop=4 expandtab
;
