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

                LIST
                RADIX   DEC

;------------------------------------------------------------------------------
; Macros
;------------------------------------------------------------------------------

; Decrement REG, goto LOC if result not ZERO
DJNZ            MACRO   REG,LOC
                DECFSZ  REG,F
                BRA     LOC
                ENDM

CANOVFL         MACRO
                BSF     LLED,0              ; LED1 CAN Packet dropped
                ENDM

CANRECV         MACRO
                BCF     LLED,0              ; LED1 CAN Packet received
                ENDM

UARTOVFL        MACRO
                BSF     LLED,1              ; LED2 UART Packet dropped
                ENDM

UARTRECV        MACRO
                BCF     LLED,1              ; LED2 UART Packet received
                ENDM

;------------------------------------------------------------------------------
; Variables
;------------------------------------------------------------------------------

                CBLOCK  0x0000              ; ACCESS RAM 0x00..0x5F
                B_SAVE  : 1                 ; ISR BANK SELECT REGISTER
                S_SAVE  : 1                 ; ISR STATUS REGISTER
                W_SAVE  : 1                 ; ISR WORKING REGISTER
                ENDC

;------------------------------------------------------------------------------
; Reset/ISR
;------------------------------------------------------------------------------

                ORG     0x0000
                GOTO    INIT
                ORG     0x0008
                GOTO    ISRHIGH             ; When IPEN = 0 or 1
                ORG     0x0018
                GOTO    ISRLOW              ; When IPEN = 1

;------------------------------------------------------------------------------
; Init.
;------------------------------------------------------------------------------
INIT
                MOVLB   0x0F                ; Default to Bank 15

#IFDEF __18F26K80
                ; disbale all analog
                CLRF    ANCON0
                CLRF    ANCON1
                CLRF    ADCON0              ; disable ADCs
                CLRF    ADCON1
                CLRF    ADCON2
                CLRF    CM1CON              ; disable comperators
                CLRF    CM2CON
#ENDIF
                CLRF    INTCON              ; Reset ISR
                CLRF    PIE1
                CLRF    PIR1

                CLRF    LLED                ; Init. Diag. LEDs
                CLRF    LTRIS

                RCALL   INITUART            ; Init. UART
                RCALL   INITRING            ; Init. Rx/Tx Ring
                RCALL   INITCAN             ; Init. CAN Bus

                BSF     RCON,IPEN           ; Enable priority interrupts
                BSF     INTCON,PEIE         ; Init. ISR
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
#INCLUDE        "ring.inc"                  ; Rx/Tx Ring
#INCLUDE        "can.inc"                   ; CAN
#INCLUDE        "ascii.inc"                 ; ASCII I/O

;------------------------------------------------------------------------------
;
; vim: shiftwidth=4 tabstop=4 softtabstop=4 expandtab
;
