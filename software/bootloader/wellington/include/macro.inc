;------------------------------------------------------------------------------
;
; Title:            The Wellington Boot Loader for PIC18
;
; File description: Macros
;
; Copyright:        Copyright (c) 2014 The Duke of Welling Town
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
                RADIX   DEC

;------------------------------------------------------------------------------
; Timeouts
;------------------------------------------------------------------------------

; For CLOCK =  1MHz, N =  1, TIMEOUT ~= 800ms
; For CLOCK = 64MHz, N = 64, TIMEOUT ~= 800ms

#IF CLOCK < 1000000
    ERROR       "CLOCK Too Low"
#ENDIF

#DEFINE         TO1     1 * (CLOCK / 1000000)   ;~= 800ms
#DEFINE         TO2     2 * (CLOCK / 1000000)   ;~= 1600ms
#DEFINE         TO3     3 * (CLOCK / 1000000)   ;~= 2400ms
#DEFINE         TO4     4 * (CLOCK / 1000000)   ;~= 3200ms

;------------------------------------------------------------------------------
; Timeout Macros
;------------------------------------------------------------------------------

BEGINTO         MACRO   TO

                MOVLW   TO
                MOVWF   temp1
                CLRF    temp2
                CLRF    temp3

                ENDM

LOOPTO          MACRO   TO
                DECFSZ  temp3
                BRA     TO
#IFDEF KICK_WD
                CLRWDT
#ENDIF
                DECFSZ  temp2
                BRA     TO
                DECFSZ  temp1
                BRA     TO

                ; Timed-out If We Got Here
                ENDM

;------------------------------------------------------------------------------
; Trouble Shooting
;------------------------------------------------------------------------------

TOGGLEQUICK     MACRO

                ; Toggle Pin Quickly
                BCF     TRISA,0
TSLOOP          BTG     LATA,0
                BRA     TSLOOP

                ENDM

TOGGLESLOW      MACRO

                ; Toggle Pin Slowly
                BCF     TRISA,0
TSLOOP0         BTG     LATA,0

                BEGINTO TO1
TSLOOP1         LOOPTO  TSLOOP1

                BRA     TSLOOP0

                ENDM

;------------------------------------------------------------------------------
;
; vim: ft=asm shiftwidth=4 tabstop=4 softtabstop=4 expandtab
;
