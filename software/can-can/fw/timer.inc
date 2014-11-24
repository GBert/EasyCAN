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

; 1 count period
;
#DEFINE         TCY         (CLOCK / 4)

; TMR2 Interval. 1:1 Postscale, Prescaler 16.
;
; PR = (TCY / (BAUDRATE / 10) / SCALER) - 1
;
#DEFINE         TMR2_PR     (TCY / (BAUDRATE / 10) / 16) - 1

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
