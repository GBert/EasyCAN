;------------------------------------------------------------------------------
;
; Can-Can Firmware
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
; Macros
;------------------------------------------------------------------------------

; Decrement REG, goto LOC if result not ZERO
DJNZ            MACRO   REG,LOC
                DECFSZ  REG,F
                BRA     LOC
                ENDM

;------------------------------------------------------------------------------
; Variables
;------------------------------------------------------------------------------

                CBLOCK  0x0000              ; ACCESS RAM 0x00..0x5F
                ENDC

;------------------------------------------------------------------------------
; Reset/ISR
;------------------------------------------------------------------------------

                ORG     0x0000
                GOTO    INIT
                ORG     0x0008
                GOTO    ISR
                ORG     0x0018
                GOTO    ISR

;------------------------------------------------------------------------------
; Init.
;------------------------------------------------------------------------------
INIT
                MOVLB   0x0F                ; Default to Bank 15

                BCF     RCON,IPEN           ; Reset ISR
                CLRF    INTCON
                CLRF    PIE1
                CLRF    PIR1

                CLRF    LLED                ; Init. Diag. LEDs
                CLRF    LTRIS

                RCALL   INITUART            ; Init. UART
                RCALL   INITTMR2            ; Init. Timer2
                RCALL   INITRING            ; Init. Rx/Tx Ring
                RCALL   INITCAN             ; Init. CAN Bus

                BSF     INTCON,PEIE         ; Init. TMR2 Rx/Tx Ring ISR
                BSF     INTCON,GIE
               
;------------------------------------------------------------------------------
; Main
;------------------------------------------------------------------------------
MAIN
                RCALL   RESETUART           ; UART RESET
                RCALL   RXCAN               ; RECEIVE CAN
                RCALL   TXCAN               ; SEND CAN
                BRA     MAIN

;------------------------------------------------------------------------------
; Includes
;------------------------------------------------------------------------------

#INCLUDE        "uart.inc"                  ; UART
#INCLUDE        "timer.inc"                 ; TMR2
#INCLUDE        "ring.inc"                  ; Rx/Tx Ring
#INCLUDE        "can.inc"                   ; CAN
#INCLUDE        "ascii.inc"                 ; ASCII conversions

;------------------------------------------------------------------------------
;
; vim: shiftwidth=4 tabstop=4 softtabstop=4 expandtab
;
