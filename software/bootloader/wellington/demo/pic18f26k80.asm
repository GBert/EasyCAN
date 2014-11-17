;------------------------------------------------------------------------------
;
; Title:        LED demo for The Wellington Boot Loader for PIC18
;
; Copyright:    Copyright (c) 2014 The Duke of Welling Town
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
;
;------------------------------------------------------------------------------

                RADIX   DEC

;------------------------------------------------------------------------------
;
; LED demonstration for The Wellington Boot Loader.
;
;------------------------------------------------------------------------------
;
                LIST    P=PIC18F26K80
ERRORLEVEL      -302
INCLUDE         "p18f26k80.inc"
;
;------------------------------------------------------------------------------
;
; Data EEPROM
;
                ORG     0xF00000
                DE      "PIC18F26K80",0,0xFF
;
;------------------------------------------------------------------------------
;
; Variables
;
CBLOCK          0
                Delay1 : 1
                Delay2 : 1
                Delay3 : 1
ENDC
;
;------------------------------------------------------------------------------
;
; Reset
;
                ORG     0
                GOTO    INIT
;
;------------------------------------------------------------------------------
;
; Init.
;
INIT            SETF    LATA
                BCF     TRISA,0             ;RA0 O/P
;
;------------------------------------------------------------------------------
;
; Toggle LED
;
LOOP            BTG     LATA,0

                MOVLW   4
                MOVWF   Delay1
                CLRF    Delay2
                CLRF    Delay3

DELAY           DECFSZ  Delay3
                BRA     DELAY 
                DECFSZ  Delay2
                BRA     DELAY
                DECFSZ  Delay1
                BRA     DELAY

                BRA     LOOP
;
;------------------------------------------------------------------------------
                END
;------------------------------------------------------------------------------
;
; vim: shiftwidth=4 tabstop=4 softtabstop=4 expandtab
;
