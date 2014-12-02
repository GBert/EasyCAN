;------------------------------------------------------------------------------
;
; Can-Can CAN rates
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

#IFNDEF CANRATE
    ERROR       "CAN Bus rate not defined"
#ENDIF

#IF CLOCK != 40000000
    #IF CLOCK != 64000000
        ERROR   "CAN Bus rate not calculated"
    #ENDIF
#ENDIF

#IF CLOCK == 40000000
    #IF CANRATE == 500
        #DEFINE BRG1 0x04
        #DEFINE BRG2 0x84
        #DEFINE BRG3 0x00
    #ENDIF
    #IF CANRATE == 250
        #DEFINE BRG1 0x04
        #DEFINE BRG2 0xBC
        #DEFINE BRG3 0x01
    #ENDIF
    #IF CANRATE == 125
        #DEFINE BRG1 0x09
        #DEFINE BRG2 0xBC
        #DEFINE BRG3 0x01
    #ENDIF
    #IF CANRATE == 100
        #DEFINE BRG1 0x18
        #DEFINE BRG2 0x84
        #DEFINE BRG3 0x00
    #ENDIF
    #IF CANRATE == 50
        #DEFINE BRG1 0x18
        #DEFINE BRG2 0xBC
        #DEFINE BRG3 0x01
    #ENDIF
#ENDIF

#IF CLOCK == 64000000
    #IF CANRATE == 1000
        #DEFINE BRG1 0x01
        #DEFINE BRG2 0xBC
        #DEFINE BRG3 0x01
    #ENDIF
    #IF CANRATE == 500
        #DEFINE BRG1 0x03
        #DEFINE BRG2 0xBC
        #DEFINE BRG3 0x01
    #ENDIF
    #IF CANRATE == 250
        #DEFINE BRG1 0x07
        #DEFINE BRG2 0xBC
        #DEFINE BRG3 0x01
    #ENDIF
    #IF CANRATE == 125
        #DEFINE BRG1 0x0F
        #DEFINE BRG2 0xBC
        #DEFINE BRG3 0x01
    #ENDIF
    #IF CANRATE == 100
        #DEFINE BRG1 0x13
        #DEFINE BRG2 0xBC
        #DEFINE BRG3 0x01
    #ENDIF
    #IF CANRATE == 50
        #DEFINE BRG1 0x27
        #DEFINE BRG2 0xBC
        #DEFINE BRG3 0x01
    #ENDIF
#ENDIF

;------------------------------------------------------------------------------
;
; vim: shiftwidth=4 tabstop=4 softtabstop=4 expandtab
;
