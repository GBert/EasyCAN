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

                PROCESSOR   18f4685     ;XXX MCU

                ; Estimate of the Boot Loader Project's Size in Bytes
BOOTSIZE        EQU         (320)       ;5 x 64

;------------------------------------------------------------------------------
; PIC18F4685 Device Pinout
;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
; Device Constants
;------------------------------------------------------------------------------

#INCLUDE        "devices.inc"

;------------------------------------------------------------------------------
; MCU Settings
;------------------------------------------------------------------------------

#DEFINE         CLOCK       40000000    ;XXX oscillator frequency (inc. pll)

;#DEFINE        KICK_WD     1           ;XXX uncomment to kick the wd during
                                        ;    busy loops; only enable this when
                                        ;    the watchdog timer is enabled

;------------------------------------------------------------------------------
; UART comms.
;------------------------------------------------------------------------------

#DEFINE         USE_UART1   1           ;XXX uncomment to use uart1
#DEFINE         BAUDRATE    115200      ;XXX baudrate

;------------------------------------------------------------------------------
; CAN comms.
;------------------------------------------------------------------------------         

;#DEFINE        USE_CAN                 ;XXX uncomment to use CAN instead of UART
#DEFINE         CAN_ID      0x666       ;XXX boot loader message id
#DEFINE         CAN_SPEED   125         ;XXX bus speed
;#DEFINE        CAN_DELAYS  100         ;XXX uncomment for short tx delay
;#DEFINE        CAN_DELAYL  100         ;XXX uncomment for long tx delay
;#DEFINE        CAN_PORTC   1           ;XXX uncomment for TX/RX on PORTC

;------------------------------------------------------------------------------
; MCU Configuration
;------------------------------------------------------------------------------

; Oscillator Selection:
                CONFIG    OSC=HSPLL
; Fail-Safe Clock Monitor:
                CONFIG    FCMEN=OFF
; Internal External Switch Over mode:
                CONFIG    IESO=OFF
; Power-up Timer:
                CONFIG    PWRT=OFF
; Brown-out Reset:
                CONFIG    BOREN=OFF
; Brown-out Voltage:
                CONFIG    BORV=0
; Watchdog Timer:
                CONFIG    WDT=OFF
; Watchdog Postscaler:
                CONFIG    WDTPS=1024
; PORTB A/D Enable:
                CONFIG    PBADEN=OFF
; Low-Power Timer 1 Oscillator Enable bit:
                CONFIG    LPT1OSC=ON
; MCLR Enable:
                CONFIG    MCLRE=ON
; Stack Full/Overflow Reset:
                CONFIG    STVREN=ON
; Low Voltage ICSP:
                CONFIG    LVP=OFF
; Boot Block Size Select bits:
                CONFIG    BBSIZ=1024 
; XINST Enable:
                CONFIG    XINST=OFF
; Background Debugger Enable:
                CONFIG    DEBUG=OFF
; Code Protection Block 0:
                CONFIG    CP0=OFF
; Code Protection Block 1:
                CONFIG    CP1=OFF
; Code Protection Block 2:
                CONFIG    CP2=OFF
; Code Protection Block 3:
                CONFIG    CP3=OFF
; Boot Block Code Protection:
                CONFIG    CPB=OFF
; Data EEPROM Code Protection:
                CONFIG    CPD=OFF
; Write Protection Block 0:
                CONFIG    WRT0=OFF
; Write Protection Block 1:
                CONFIG    WRT1=OFF
; Write Protection Block 2:
                CONFIG    WRT2=OFF
; Write Protection Block 3:
                CONFIG    WRT3=OFF
; Boot Block Write Protection:
                CONFIG    WRTB=OFF
; Configuration Register Write Protection:
                CONFIG    WRTC=OFF
; Data EEPROM Write Protection:
                CONFIG    WRTD=OFF
; Table Read Protection Block 0:
                CONFIG    EBTR0=OFF
; Table Read Protection Block 1:
                CONFIG    EBTR1=OFF
; Table Read Protection Block 2:
                CONFIG    EBTR2=OFF
; Table Read Protection Block 3:
                CONFIG    EBTR3=OFF
; Boot Block Table Read Protection:
                CONFIG    EBTRB=OFF

;------------------------------------------------------------------------------
; Init. Macro. This is Executed Before The Boot Loader.
;------------------------------------------------------------------------------

PROCINIT        MACRO
                BCF     RCON,IPEN

                MOVLW   b'00000111'
                MOVWF   CMCON
                MOVLW   b'00000000'
                MOVWF   ADCON0
                MOVLW   b'00001111'
                MOVWF   ADCON1

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
