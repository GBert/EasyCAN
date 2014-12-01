;------------------------------------------------------------------------------
;
; Title:            The Wellington Boot Loader for PIC18
;
; File description: UART functions
;
; Copyright:        Copyright (c) 2003-2008 Claudiu Chiculita
;                   Copyright (c) 2009-2012 Mikael Gustafsson
;                   Copyright (c) 2014 The Duke of Welling Town
;
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
;   This file is part of The Wellington Boot Loader.
;
;   The Wellington Boot Loader is free software: you can redistribute it and/or
;   modify it under the terms of the GNU General Public License as published
;   by the Free Software Foundation.
;
;   The Wellington Boot Loader is distributed in the hope that it will be
;   useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
;   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
;   GNU General Public License for more details.
;
;   You should have received a copy of the GNU General Public License along
;   with The Wellington Boot Loader. If not, see http://www.gnu.org/licenses/
;------------------------------------------------------------------------------

                LIST
                RADIX       DEC

;------------------------------------------------------------------------------
; UART
;------------------------------------------------------------------------------

#IFDEF USE_UART1
    #IFDEF USE_UART2
        ERROR           "Both uarts are specified"
    #ENDIF

    #DEFINE PIR_        PIR1        ;uart interrupt status register
    #DEFINE RCIF_       RCIF        ;uart rx isr

    #IFNDEF TXSTA1
        #DEFINE         TXIF_       TXIF    ;uart tx isr
        #DEFINE         TXSTA_      TXSTA   ;uart status
        #DEFINE         RCSTA_      RCSTA   ;uart status
        #DEFINE         SPBRG_      SPBRG   ;uart baudrate
        #DEFINE         TXREG_      TXREG   ;uart transmit
        #DEFINE         RCREG_      RCREG   ;uart receive
    #ELSE
        #DEFINE         TXIF_       TX1IF   ;uart tx isr
        #DEFINE         TXSTA_      TXSTA1  ;uart status
        #DEFINE         RCSTA_      RCSTA1  ;uart status
        #DEFINE         SPBRG_      SPBRG1  ;uart baudrate
        #DEFINE         TXREG_      TXREG1  ;uart transmit
        #DEFINE         RCREG_      RCREG1  ;uart receive
    #ENDIF
    #IFDEF BAUDCON
        #DEFINE         BAUDCON_    BAUDCON ;uart receive
    #ELSE
        #DEFINE         BAUDCON_    BAUDCON1;uart receive
    #ENDIF
    #IFDEF SPBRGH
        #DEFINE         SPBRGH_     SPBRGH  ;uart baudrate
    #ELSE
        #DEFINE         SPBRGH_     SPBRGH1 ;uart baudrate
    #ENDIF
#ENDIF

#IFDEF USE_UART2
    #IFDEF USE_UART1
        ERROR           "Both uarts are specified"
    #ENDIF        
    #IFNDEF HAS_UART2
        ERROR           "UART2 specified for a device that only has uart1"
    #ENDIF

    #DEFINE             PIR_        PIR3    ;uart interrupt status register
    #DEFINE             RCIF_       RC2IF   ;uart rx isr
    #DEFINE             TXIF_       TX2IF   ;uart tx isr

    #DEFINE             TXSTA_      TXSTA2  ;uart status
    #DEFINE             RCSTA_      RCSTA2  ;uart status
    #DEFINE             SPBRG_      SPBRG2  ;uart baudrate
    #DEFINE             TXREG_      TXREG2  ;uart transmit
    #DEFINE             RCREG_      RCREG2  ;uart receive
    #DEFINE             BAUDCON_    BAUDCON2;uart receive
    #DEFINE             SPBRGH_     SPBRGH2 ;uart baudrate
#ENDIF

;------------------------------------------------------------------------------
; Baud Rate Config
;------------------------------------------------------------------------------

#DEFINE UBRG ((((CLOCK / BAUDRATE) / 2) - 1) / 2)

#IF UBRG > 65535
    ERROR       "SPBRG is too large"
#ENDIF
#IF UBRG == 0
    ERROR       "SPBRG is too small"
#ENDIF

;------------------------------------------------------------------------------
; COMMINIT()
; Init. UART registers.
;------------------------------------------------------------------------------

COMMINIT
#IFDEF USE_TXENABLE
                ; Configure tx enable pin and reset
                BCF     LATR_TXE,LATB_TXE
                BCF     TRISR_TXE,TRISB_TXE
#ENDIF
                BANKSEL TXSTA_

                MOVLW   (1 << BRG16)
                MOVWF   BAUDCON_

                MOVLW   HIGH UBRG
                MOVWF   SPBRGH_
                MOVLW   LOW  UBRG
                MOVWF   SPBRG_

                ; Enable transmit + high speed mode
                MOVLW   (1 << TXEN) + (1 << BRGH)
                MOVWF   TXSTA_

                ; Enable serial port + receiver
                MOVLW   (1 << SPEN) + (1 << CREN)
                MOVWF   RCSTA_

                MOVF    RCREG_,W            ;Clear Receiver
                MOVF    RCREG_,W
                MOVF    RCREG_,W

                MOVLB   0
                RETURN

;------------------------------------------------------------------------------
; COMMEXIT()
; Reset UART registers.
;------------------------------------------------------------------------------

COMMEXIT        BANKSEL RCSTA_

                CLRF    RCSTA_              ;Disable Serial Port

                MOVLB   0
                RETURN

;------------------------------------------------------------------------------
; Receive()
;------------------------------------------------------------------------------

Receive
                BEGINTO TO1
RecvLoop        BTFSC   PIR_,RCIF_
                BRA     Received
                LOOPTO  RecvLoop
                BRA     TIMEDOUT
Received
                BANKSEL RCREG_
                MOVF    RCREG_,W            ;RETURN read data in W
                MOVLB   0
                ADDWF   csum,F              ;compute checksum
                RETURN

;------------------------------------------------------------------------------
; Send()
;------------------------------------------------------------------------------

Send
                BANKSEL TXSTA_
#IFDEF USE_TXENABLE
                BCF     RCSTA_,CREN         ;disable serial receiver
                BSF     LATR_TXE,LATB_TXE   ;enable external transceiver
#IFDEF TXE_DELAY
                MOVWF   temp1               ;save data byte
                MOVLW   TXE_DELAY           ;Wait a While
                MOVWF   temp2
txe_del_lo      DECFSZ  temp2
                BRA     txe_del_lo
                MOVF    temp1,W             ;restore data byte
#IFDEF KICK_WD
                CLRWDT
#ENDIF
#ENDIF
                ; Send data byte
                MOVWF   TXREG_

                ; Wait for transmit shift register to get empty
txwait          BTFSS   TXSTA_,TRMT
                BRA     txwait

                BCF     LATR_TXE,LATB_TXE   ;disable external transceiver
                BSF     RCSTA_,CREN         ;enable serial receiver
#ELSE
                ; Send data byte
                MOVWF   TXREG_

                ; Wait for transmit shift register to get empty
txwait          BTFSS   TXSTA_,TRMT
                BRA     txwait
#ENDIF
                ; Send complete
                MOVLB   0
                RETURN

;------------------------------------------------------------------------------
;
; vim: ft=asm shiftwidth=4 tabstop=4 softtabstop=4 expandtab
;
