;------------------------------------------------------------------------------
;
; Title:            The Wellington Boot Loader for PIC18
;
; File description: Boot Loader Project
;
; Copyright:        Copyright (c) 2009-2012 Mikael Gustafsson
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

                RADIX       DEC

;------------------------------------------------------------------------------
; Device
;------------------------------------------------------------------------------

                PROCESSOR   18fXXX      ;XXX MCU

;------------------------------------------------------------------------------
; Device Constants
;------------------------------------------------------------------------------

#INCLUDE        "devices.inc"

;------------------------------------------------------------------------------
; MCU Settings
;------------------------------------------------------------------------------

#DEFINE         OSCF        4000000     ;XXX oscillator frequency (inc. pll)

;#DEFINE        KICK_WD     1           ;XXX uncomment to kick the wd during
                                        ;    busy loops; only enable this when
                                        ;    the watchdog timer is enabled

;------------------------------------------------------------------------------
; UART comms.
;------------------------------------------------------------------------------

#DEFINE         USE_UART1   1           ;XXX uncomment to use uart1
;#DEFINE        USE_UART2   1           ;XXX uncomment to use uart2
#DEFINE         BAUDRATE    115200      ;XXX baudrate

;#DEFINE        USE_TXENABLE 1          ;XXX uncomment to use a tx enable pin
#IFDEF USE_TXENABLE
    #DEFINE     TXE_DELAY   10          ;XXX delay time to wait before transmitting
                                        ;    after pulling the tx enable pin high
    #DEFINE     TRISR_TXE   TRISD       ;XXX tris register containing tx enable
    #DEFINE     LATR_TXE    LATD        ;XXX port register containing tx enable
    #DEFINE     TRISB_TXE   TRISD0      ;XXX tris bit for tx enable
    #DEFINE     LATB_TXE    RD0         ;XXX port bit for tx enable
#ENDIF

;------------------------------------------------------------------------------
; CAN comms.
;------------------------------------------------------------------------------         

;#define USE_CAN                        ;xxx uncomment to use CAN instead of UART
#define         ID_PIC      1           ;xxx node number for this device
#define         ID_LOADER   0x7ff       ;xxx node number of the easy Loader

;------------------------------------------------------------------------------
; MCU Configuration
;------------------------------------------------------------------------------

#ERROR          "You need to configure the MCU"

; Eg.

; Oscillator Selection:
                CONFIG    OSC=XT
; Osc. Switch Enable:
                CONFIG    OSCS=OFF
; Power-up Timer:
                CONFIG    PWRT=OFF
; Brown-out Reset:
                CONFIG    BOR=OFF
; Brown-out Voltage:
                CONFIG    BORV=27
; Watchdog Timer:
                CONFIG    WDT=OFF
; Watchdog Postscaler:
                CONFIG    WDTPS=128
; CCP2 MUX:
                CONFIG    CCP2MUX=OFF
; Stack Full/Overflow Reset:
                CONFIG    STVR=ON
; Low Voltage ICSP:
                CONFIG    LVP=OFF
; Background Debugger Enable:
                CONFIG    DEBUG=OFF

;------------------------------------------------------------------------------
; Init. Macro. This is Executed Before The Boot Loader.
;------------------------------------------------------------------------------

PROCINIT        MACRO

#ERROR          "You need to configure the oscilllator"

#IFDEF ADCON1                           ; Make uart pins digital
    #ERROR      "You need to configure the uart"
#ENDIF

#IFDEF HAS_PPS                          ; UART/CAN pps config
    #IFDEF USE_UART2
        #ERROR  "You need to configure PPS"
                ; This template maps U2Rx to RP4
                BCF     RPINR16,RX2DT2R0
                BCF     RPINR16,RX2DT2R1
                BSF     RPINR16,RX2DT2R2
                BCF     RPINR16,RX2DT2R3
                BCF     RPINR16,RX2DT2R4
                ; This template maps RP3 to U2Tx
                BSF     RPOR3,RP3R0
                BCF     RPOR3,RP3R1
                BSF     RPOR3,RP3R2
                BCF     RPOR3,RP3R3
                BCF     RPOR3,RP3R4
    #ENDIF
#ENDIF
                ENDM

;------------------------------------------------------------------------------
; The Wellington Boot Loader
;------------------------------------------------------------------------------

ERRORLEVEL      -302
#INCLUDE        "boot.inc"

;------------------------------------------------------------------------------    
THE
                END
;------------------------------------------------------------------------------    
;
; vim: ft=asm shiftwidth=4 tabstop=4 softtabstop=4 expandtab
;
