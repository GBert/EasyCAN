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

                PROCESSOR   18f26K80    ;XXX MCU

;------------------------------------------------------------------------------
; PIC18F26K80 Device Pinout
;------------------------------------------------------------------------------
;
; !MCLR        1-----28 RB7 PGD RX2
; RA0          2     27 RB6 PGC TX2
; RA1          3     26 RB5
; RA2          4     25 RB4
; RA3          5     24 RB3
; VDDCORE/VCAP 6     23 RB2
; RA5          7     22 RB1
; VSS GND      8     21 RB0
; RA7 CLKIN    9     20 VDD VCC
; RA6 CLKOUT   10    19 VSS GND
; RC0          11    18 RC7 RX1
; RC1          12    17 RC6 TX1
; RC2          13    16 RC5
; RC3          14----15 RC4
;
;------------------------------------------------------------------------------
; Device Constants
;------------------------------------------------------------------------------

#INCLUDE        "devices.inc"

;------------------------------------------------------------------------------
; MCU Settings
;------------------------------------------------------------------------------

#DEFINE         OSCF        64000000    ;XXX oscillator frequency (inc. pll)

;#DEFINE        KICK_WD     1           ;XXX uncomment to kick the wd during
                                        ;    busy loops; only enable this when
                                        ;    the watchdog timer is enabled

;------------------------------------------------------------------------------
; UART comms.
;------------------------------------------------------------------------------

#DEFINE         USE_UART1   1           ;XXX uncomment to use uart1
;#DEFINE        USE_UART2   1           ;XXX uncomment to use uart2
#DEFINE         BAUDRATE    115200      ;XXX baudrate

;------------------------------------------------------------------------------
; CAN comms.
;------------------------------------------------------------------------------         

;#define USE_CAN                        ;xxx uncomment to use CAN instead of UART
#define         ID_PIC      1           ;xxx node number for this device
#define         ID_LOADER   0x7ff       ;xxx node number of the easy Loader

;------------------------------------------------------------------------------
; MCU Configuration
;------------------------------------------------------------------------------

; VREG Sleep Enable bit:
                CONFIG    RETEN=ON
; LF-INTOSC Low-power Enable bit:
;               CONFIG    INTOSCSEL=LOW
; SOSC Power Selection and mode Configuration bits:
                CONFIG    SOSCSEL=DIG
; Extended Instruction Set:
                CONFIG    XINST=OFF
; Oscillator:
                CONFIG    FOSC=HS2 ;CLKOUT on OSC2
; PLL x4 Enable bit:
                CONFIG    PLLCFG=ON
; Fail-Safe Clock Monitor:
                CONFIG    FCMEN=OFF
; Internal External Oscillator Switch Over Mode:
                CONFIG    IESO=OFF
; Power-up Timer:
                CONFIG    PWRTEN=OFF
; Brown-out Detect:
                CONFIG    BOREN=OFF
; Brown-out Reset Voltage bits:
                CONFIG    BORV=1
; BORMV Power level:
;               CONFIG    BORPWR=LOW
; Watchdog Timer:
                CONFIG    WDTEN=ON
; Watchdog Postscaler:
                CONFIG    WDTPS=1024
; ECAN Mux bit:
                CONFIG    CANMX=PORTB
; MSSP address masking:
                CONFIG    MSSPMSK=MSK5
; Master Clear Enable:
                CONFIG    MCLRE=ON
; Stack Overflow Reset:
                CONFIG    STVREN=ON
; Boot Block Size:
                CONFIG    BBSIZ=BB1K
; Code Protect 00800-03FFF:
                CONFIG    CP0=OFF
; Code Protect 04000-07FFF:
                CONFIG    CP1=OFF
; Code Protect 08000-0BFFF:
                CONFIG    CP2=OFF
; Code Protect 0C000-0FFFF:
                CONFIG    CP3=OFF
; Code Protect Boot:
                CONFIG    CPB=OFF
; Data EE Read Protect:
                CONFIG    CPD=OFF
; Table Write Protect 00800-03FFF:
                CONFIG    WRT0=OFF
; Table Write Protect 04000-07FFF:
                CONFIG    WRT1=OFF
; Table Write Protect 08000-0BFFF:
                CONFIG    WRT2=OFF
; Table Write Protect 0C000-0FFFF:
                CONFIG    WRT3=OFF
; Config. Write Protect:
                CONFIG    WRTC=OFF
; Table Write Protect Boot:
                CONFIG    WRTB=OFF
; Data EE Write Protect:
                CONFIG    WRTD=OFF
; Table Read Protect 00800-03FFF:
                CONFIG    EBTR0=OFF
; Table Read Protect 04000-07FFF:
                CONFIG    EBTR1=OFF
; Table Read Protect 08000-0BFFF:
                CONFIG    EBTR2=OFF
; Table Read Protect 0C000-0FFFF:
                CONFIG    EBTR3=OFF
; Table Read Protect Boot:
                CONFIG    EBTRB=OFF

;------------------------------------------------------------------------------
; Init. Macro. This is Executed Before The Boot Loader.
;------------------------------------------------------------------------------

PROCINIT        MACRO

                MOVLB   0x0F
                BCF     RCON,IPEN

                BSF     OSCTUNE,PLLEN

#DEFINE         _16MHZ  b'01110000'     ;64MHZ PLLx4
#DEFINE         _8MHZ   b'01100000'     ;32MHZ PLLx4
#DEFINE         _4MHZ   b'01010000'
#DEFINE         _2MHZ   b'01000000'
#DEFINE         _1MHZ   b'00110000'
#DEFINE         _HS2    b'00100000'	;ext crystal

                MOVLW   _HS2
                MOVWF   OSCCON

;INITHFIOFS      BTFSS   OSCCON,HFIOFS
;                GOTO    INITHFIOFS

                CLRF    ADCON0
                CLRF    ANCON1
                MOVLB   0

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
