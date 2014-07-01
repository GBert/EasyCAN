opt subtitle "Microchip Technology Omniscient Code Generator (Lite mode) build 55553"

opt pagewidth 120

	opt lm

	processor	18F26K80
porta	equ	0F80h
portb	equ	0F81h
portc	equ	0F82h
portd	equ	0F83h
porte	equ	0F84h
lata	equ	0F89h
latb	equ	0F8Ah
latc	equ	0F8Bh
latd	equ	0F8Ch
late	equ	0F8Dh
trisa	equ	0F92h
trisb	equ	0F93h
trisc	equ	0F94h
trisd	equ	0F95h
trise	equ	0F96h
pie1	equ	0F9Dh
pir1	equ	0F9Eh
ipr1	equ	0F9Fh
pie2	equ	0FA0h
pir2	equ	0FA1h
ipr2	equ	0FA2h
t3con	equ	0FB1h
tmr3l	equ	0FB2h
tmr3h	equ	0FB3h
ccp1con	equ	0FBDh
ccpr1l	equ	0FBEh
ccpr1h	equ	0FBFh
adcon1	equ	0FC1h
adcon0	equ	0FC2h
adresl	equ	0FC3h
adresh	equ	0FC4h
sspcon2	equ	0FC5h
sspcon1	equ	0FC6h
sspstat	equ	0FC7h
sspadd	equ	0FC8h
sspbuf	equ	0FC9h
t2con	equ	0FCAh
pr2	equ	0FCBh
tmr2	equ	0FCCh
t1con	equ	0FCDh
tmr1l	equ	0FCEh
tmr1h	equ	0FCFh
rcon	equ	0FD0h
wdtcon	equ	0FD1h
lvdcon	equ	0FD2h
osccon	equ	0FD3h
t0con	equ	0FD5h
tmr0l	equ	0FD6h
tmr0h	equ	0FD7h
status	equ	0FD8h
fsr2	equ	0FD9h
fsr2l	equ	0FD9h
fsr2h	equ	0FDAh
plusw2	equ	0FDBh
preinc2	equ	0FDCh
postdec2	equ	0FDDh
postinc2	equ	0FDEh
indf2	equ	0FDFh
bsr	equ	0FE0h
fsr1	equ	0FE1h
fsr1l	equ	0FE1h
fsr1h	equ	0FE2h
plusw1	equ	0FE3h
preinc1	equ	0FE4h
postdec1	equ	0FE5h
postinc1	equ	0FE6h
indf1	equ	0FE7h
wreg	equ	0FE8h
fsr0	equ	0FE9h
fsr0l	equ	0FE9h
fsr0h	equ	0FEAh
plusw0	equ	0FEBh
preinc0	equ	0FECh
postdec0	equ	0FEDh
postinc0	equ	0FEEh
indf0	equ	0FEFh
intcon3	equ	0FF0h
intcon2	equ	0FF1h
intcon	equ	0FF2h
prod	equ	0FF3h
prodl	equ	0FF3h
prodh	equ	0FF4h
tablat	equ	0FF5h
tblptr	equ	0FF6h
tblptrl	equ	0FF6h
tblptrh	equ	0FF7h
tblptru	equ	0FF8h
pcl	equ	0FF9h
pclat	equ	0FFAh
pclath	equ	0FFAh
pclatu	equ	0FFBh
stkptr	equ	0FFCh
tosl	equ	0FFDh
tosh	equ	0FFEh
tosu	equ	0FFFh
clrc   macro
	bcf	status,0
endm
setc   macro
	bsf	status,0
endm
clrz   macro
	bcf	status,2
endm
setz   macro
	bsf	status,2
endm
skipnz macro
	btfsc	status,2
endm
skipz  macro
	btfss	status,2
endm
skipnc macro
	btfsc	status,0
endm
skipc  macro
	btfss	status,0
endm
pushw macro
	movwf postinc1
endm
pushf macro arg1
	movff arg1, postinc1
endm
popw macro
	movf postdec1,w
	movf indf1,w
endm
popf macro arg1
	movf postdec1,w
	movff indf1,arg1
endm
popfc macro arg1
	movff plusw1,arg1
	decfsz fsr1,f
endm
	global	__ramtop
	global	__accesstop
# 46 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXERRCNT equ 0E41h ;# 
# 115 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXERRCNT equ 0E42h ;# 
# 184 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
BRGCON1 equ 0E43h ;# 
# 259 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
BRGCON2 equ 0E44h ;# 
# 343 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
BRGCON3 equ 0E45h ;# 
# 395 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXFCON0 equ 0E46h ;# 
# 456 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXFCON1 equ 0E47h ;# 
# 517 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF6SIDH equ 0E48h ;# 
# 657 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF6SIDL equ 0E49h ;# 
# 776 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF6EIDH equ 0E4Ah ;# 
# 916 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF6EIDL equ 0E4Bh ;# 
# 1056 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF7SIDH equ 0E4Ch ;# 
# 1196 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF7SIDL equ 0E4Dh ;# 
# 1315 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF7EIDH equ 0E4Eh ;# 
# 1455 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF7EIDL equ 0E4Fh ;# 
# 1595 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF8SIDH equ 0E50h ;# 
# 1735 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF8SIDL equ 0E51h ;# 
# 1854 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF8EIDH equ 0E52h ;# 
# 1994 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF8EIDL equ 0E53h ;# 
# 2134 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF9SIDH equ 0E54h ;# 
# 2274 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF9SIDL equ 0E55h ;# 
# 2393 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF9EIDH equ 0E56h ;# 
# 2533 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF9EIDL equ 0E57h ;# 
# 2673 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF10SIDH equ 0E58h ;# 
# 2813 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF10SIDL equ 0E59h ;# 
# 2932 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF10EIDH equ 0E5Ah ;# 
# 3072 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF10EIDL equ 0E5Bh ;# 
# 3212 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF11SIDH equ 0E5Ch ;# 
# 3352 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF11SIDL equ 0E5Dh ;# 
# 3471 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF11EIDH equ 0E5Eh ;# 
# 3611 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF11EIDL equ 0E5Fh ;# 
# 3751 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF12SIDH equ 0E60h ;# 
# 3891 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF12SIDL equ 0E61h ;# 
# 4010 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF12EIDH equ 0E62h ;# 
# 4150 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF12EIDL equ 0E63h ;# 
# 4290 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF13SIDH equ 0E64h ;# 
# 4430 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF13SIDL equ 0E65h ;# 
# 4549 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF13EIDH equ 0E66h ;# 
# 4689 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF13EIDL equ 0E67h ;# 
# 4829 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF14SIDH equ 0E68h ;# 
# 4969 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF14SIDL equ 0E69h ;# 
# 5088 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF14EIDH equ 0E6Ah ;# 
# 5228 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF14EIDL equ 0E6Bh ;# 
# 5368 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF15SIDH equ 0E6Ch ;# 
# 5508 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF15SIDL equ 0E6Dh ;# 
# 5627 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF15EIDH equ 0E6Eh ;# 
# 5767 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF15EIDL equ 0E6Fh ;# 
# 5907 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
SDFLC equ 0E70h ;# 
# 5958 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXFBCON0 equ 0E71h ;# 
# 6041 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXFBCON1 equ 0E72h ;# 
# 6124 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXFBCON2 equ 0E73h ;# 
# 6207 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXFBCON3 equ 0E74h ;# 
# 6290 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXFBCON4 equ 0E75h ;# 
# 6373 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXFBCON5 equ 0E76h ;# 
# 6456 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXFBCON6 equ 0E77h ;# 
# 6539 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXFBCON7 equ 0E78h ;# 
# 6622 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
MSEL0 equ 0E79h ;# 
# 6709 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
MSEL1 equ 0E7Ah ;# 
# 6796 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
MSEL2 equ 0E7Bh ;# 
# 6883 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
MSEL3 equ 0E7Ch ;# 
# 6970 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
BSEL0 equ 0E7Dh ;# 
# 7020 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
BIE0 equ 0E7Eh ;# 
# 7098 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXBIE equ 0E7Fh ;# 
# 7157 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0CON equ 0E80h ;# 
# 7460 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0SIDH equ 0E81h ;# 
# 7600 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0SIDL equ 0E82h ;# 
# 7733 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0EIDH equ 0E83h ;# 
# 7873 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0EIDL equ 0E84h ;# 
# 8013 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0DLC equ 0E85h ;# 
# 8159 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0D0 equ 0E86h ;# 
# 8228 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0D1 equ 0E87h ;# 
# 8297 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0D2 equ 0E88h ;# 
# 8366 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0D3 equ 0E89h ;# 
# 8435 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0D4 equ 0E8Ah ;# 
# 8504 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0D5 equ 0E8Bh ;# 
# 8573 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0D6 equ 0E8Ch ;# 
# 8642 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0D7 equ 0E8Dh ;# 
# 8711 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANSTAT_RO9 equ 0E8Eh ;# 
# 8821 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANCON_RO9 equ 0E8Fh ;# 
# 8912 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1CON equ 0E90h ;# 
# 9215 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1SIDH equ 0E91h ;# 
# 9355 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1SIDL equ 0E92h ;# 
# 9488 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1EIDH equ 0E93h ;# 
# 9628 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1EIDL equ 0E94h ;# 
# 9768 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1DLC equ 0E95h ;# 
# 9914 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1D0 equ 0E96h ;# 
# 9983 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1D1 equ 0E97h ;# 
# 10052 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1D2 equ 0E98h ;# 
# 10121 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1D3 equ 0E99h ;# 
# 10190 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1D4 equ 0E9Ah ;# 
# 10259 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1D5 equ 0E9Bh ;# 
# 10328 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1D6 equ 0E9Ch ;# 
# 10397 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1D7 equ 0E9Dh ;# 
# 10466 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANSTAT_RO8 equ 0E9Eh ;# 
# 10576 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANCON_RO8 equ 0E9Fh ;# 
# 10667 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2CON equ 0EA0h ;# 
# 10970 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2SIDH equ 0EA1h ;# 
# 11110 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2SIDL equ 0EA2h ;# 
# 11252 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2EIDH equ 0EA3h ;# 
# 11392 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2EIDL equ 0EA4h ;# 
# 11532 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2DLC equ 0EA5h ;# 
# 11678 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2D0 equ 0EA6h ;# 
# 11747 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2D1 equ 0EA7h ;# 
# 11816 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2D2 equ 0EA8h ;# 
# 11885 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2D3 equ 0EA9h ;# 
# 11954 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2D4 equ 0EAAh ;# 
# 12023 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2D5 equ 0EABh ;# 
# 12092 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2D6 equ 0EACh ;# 
# 12161 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2D7 equ 0EADh ;# 
# 12230 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANSTAT_RO7 equ 0EAEh ;# 
# 12340 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANCON_RO7 equ 0EAFh ;# 
# 12431 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3CON equ 0EB0h ;# 
# 12734 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3SIDH equ 0EB1h ;# 
# 12874 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3SIDL equ 0EB2h ;# 
# 13016 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3EIDH equ 0EB3h ;# 
# 13156 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3EIDL equ 0EB4h ;# 
# 13296 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3DLC equ 0EB5h ;# 
# 13442 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3D0 equ 0EB6h ;# 
# 13511 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3D1 equ 0EB7h ;# 
# 13580 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3D2 equ 0EB8h ;# 
# 13649 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3D3 equ 0EB9h ;# 
# 13718 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3D4 equ 0EBAh ;# 
# 13787 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3D5 equ 0EBBh ;# 
# 13856 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3D6 equ 0EBCh ;# 
# 13925 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3D7 equ 0EBDh ;# 
# 13994 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANSTAT_RO6 equ 0EBEh ;# 
# 14104 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANCON_RO6 equ 0EBFh ;# 
# 14195 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4CON equ 0EC0h ;# 
# 14498 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4SIDH equ 0EC1h ;# 
# 14638 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4SIDL equ 0EC2h ;# 
# 14780 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4EIDH equ 0EC3h ;# 
# 14920 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4EIDL equ 0EC4h ;# 
# 15060 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4DLC equ 0EC5h ;# 
# 15206 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4D0 equ 0EC6h ;# 
# 15275 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4D1 equ 0EC7h ;# 
# 15344 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4D2 equ 0EC8h ;# 
# 15413 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4D3 equ 0EC9h ;# 
# 15482 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4D4 equ 0ECAh ;# 
# 15551 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4D5 equ 0ECBh ;# 
# 15620 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4D6 equ 0ECCh ;# 
# 15689 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4D7 equ 0ECDh ;# 
# 15758 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANSTAT_RO5 equ 0ECEh ;# 
# 15868 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANCON_RO5 equ 0ECFh ;# 
# 15959 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5CON equ 0ED0h ;# 
# 16262 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5SIDH equ 0ED1h ;# 
# 16402 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5SIDL equ 0ED2h ;# 
# 16544 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5EIDH equ 0ED3h ;# 
# 16684 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5EIDL equ 0ED4h ;# 
# 16824 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5DLC equ 0ED5h ;# 
# 16970 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5D0 equ 0ED6h ;# 
# 17039 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5D1 equ 0ED7h ;# 
# 17108 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5D2 equ 0ED8h ;# 
# 17177 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5D3 equ 0ED9h ;# 
# 17246 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5D4 equ 0EDAh ;# 
# 17315 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5D5 equ 0EDBh ;# 
# 17384 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5D6 equ 0EDCh ;# 
# 17453 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5D7 equ 0EDDh ;# 
# 17522 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANSTAT_RO4 equ 0EDEh ;# 
# 17632 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANCON_RO4 equ 0EDFh ;# 
# 17723 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF0SIDH equ 0EE0h ;# 
# 17863 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF0SIDL equ 0EE1h ;# 
# 17982 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF0EIDH equ 0EE2h ;# 
# 18122 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF0EIDL equ 0EE3h ;# 
# 18262 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF1SIDH equ 0EE4h ;# 
# 18402 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF1SIDL equ 0EE5h ;# 
# 18521 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF1EIDH equ 0EE6h ;# 
# 18661 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF1EIDL equ 0EE7h ;# 
# 18801 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF2SIDH equ 0EE8h ;# 
# 18941 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF2SIDL equ 0EE9h ;# 
# 19060 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF2EIDH equ 0EEAh ;# 
# 19200 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF2EIDL equ 0EEBh ;# 
# 19340 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF3SIDH equ 0EECh ;# 
# 19480 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF3SIDL equ 0EEDh ;# 
# 19599 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF3EIDH equ 0EEEh ;# 
# 19739 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF3EIDL equ 0EEFh ;# 
# 19879 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF4SIDH equ 0EF0h ;# 
# 20019 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF4SIDL equ 0EF1h ;# 
# 20138 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF4EIDH equ 0EF2h ;# 
# 20278 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF4EIDL equ 0EF3h ;# 
# 20418 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF5SIDH equ 0EF4h ;# 
# 20558 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF5SIDL equ 0EF5h ;# 
# 20677 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF5EIDH equ 0EF6h ;# 
# 20817 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF5EIDL equ 0EF7h ;# 
# 20957 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXM0SIDH equ 0EF8h ;# 
# 21097 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXM0SIDL equ 0EF9h ;# 
# 21216 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXM0EIDH equ 0EFAh ;# 
# 21356 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXM0EIDL equ 0EFBh ;# 
# 21496 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXM1SIDH equ 0EFCh ;# 
# 21636 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXM1SIDL equ 0EFDh ;# 
# 21755 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXM1EIDH equ 0EFEh ;# 
# 21895 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXM1EIDL equ 0EFFh ;# 
# 22035 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2CON equ 0F00h ;# 
# 22161 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2SIDH equ 0F01h ;# 
# 22301 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2SIDL equ 0F02h ;# 
# 22425 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2EIDH equ 0F03h ;# 
# 22565 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2EIDL equ 0F04h ;# 
# 22705 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2DLC equ 0F05h ;# 
# 22801 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2D0 equ 0F06h ;# 
# 22870 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2D1 equ 0F07h ;# 
# 22939 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2D2 equ 0F08h ;# 
# 23008 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2D3 equ 0F09h ;# 
# 23077 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2D4 equ 0F0Ah ;# 
# 23146 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2D5 equ 0F0Bh ;# 
# 23215 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2D6 equ 0F0Ch ;# 
# 23284 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2D7 equ 0F0Dh ;# 
# 23353 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANSTAT_RO3 equ 0F0Eh ;# 
# 23463 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANCON_RO3 equ 0F0Fh ;# 
# 23554 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1CON equ 0F10h ;# 
# 23680 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1SIDH equ 0F11h ;# 
# 23820 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1SIDL equ 0F12h ;# 
# 23944 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1EIDH equ 0F13h ;# 
# 24084 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1EIDL equ 0F14h ;# 
# 24224 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1DLC equ 0F15h ;# 
# 24320 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1D0 equ 0F16h ;# 
# 24389 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1D1 equ 0F17h ;# 
# 24458 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1D2 equ 0F18h ;# 
# 24527 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1D3 equ 0F19h ;# 
# 24596 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1D4 equ 0F1Ah ;# 
# 24665 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1D5 equ 0F1Bh ;# 
# 24734 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1D6 equ 0F1Ch ;# 
# 24803 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1D7 equ 0F1Dh ;# 
# 24872 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANSTAT_RO2 equ 0F1Eh ;# 
# 24982 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANCON_RO2 equ 0F1Fh ;# 
# 25073 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0CON equ 0F20h ;# 
# 25199 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0SIDH equ 0F21h ;# 
# 25339 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0SIDL equ 0F22h ;# 
# 25463 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0EIDH equ 0F23h ;# 
# 25603 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0EIDL equ 0F24h ;# 
# 25743 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0DLC equ 0F25h ;# 
# 25839 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0D0 equ 0F26h ;# 
# 25908 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0D1 equ 0F27h ;# 
# 25977 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0D2 equ 0F28h ;# 
# 26046 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0D3 equ 0F29h ;# 
# 26115 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0D4 equ 0F2Ah ;# 
# 26184 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0D5 equ 0F2Bh ;# 
# 26253 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0D6 equ 0F2Ch ;# 
# 26322 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0D7 equ 0F2Dh ;# 
# 26391 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANSTAT_RO1 equ 0F2Eh ;# 
# 26501 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANCON_RO1 equ 0F2Fh ;# 
# 26592 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1CON equ 0F30h ;# 
# 26774 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1SIDH equ 0F31h ;# 
# 26914 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1SIDL equ 0F32h ;# 
# 27047 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1EIDH equ 0F33h ;# 
# 27187 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1EIDL equ 0F34h ;# 
# 27327 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1DLC equ 0F35h ;# 
# 27458 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1D0 equ 0F36h ;# 
# 27527 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1D1 equ 0F37h ;# 
# 27596 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1D2 equ 0F38h ;# 
# 27665 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1D3 equ 0F39h ;# 
# 27734 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1D4 equ 0F3Ah ;# 
# 27803 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1D5 equ 0F3Bh ;# 
# 27872 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1D6 equ 0F3Ch ;# 
# 27941 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1D7 equ 0F3Dh ;# 
# 28010 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANSTAT_RO0 equ 0F3Eh ;# 
# 28120 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANCON_RO0 equ 0F3Fh ;# 
# 28211 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCP5CON equ 0F47h ;# 
# 28289 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR5 equ 0F48h ;# 
# 28295 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR5L equ 0F48h ;# 
# 28314 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR5H equ 0F49h ;# 
# 28333 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCP4CON equ 0F4Ah ;# 
# 28411 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR4 equ 0F4Bh ;# 
# 28417 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR4L equ 0F4Bh ;# 
# 28436 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR4H equ 0F4Ch ;# 
# 28455 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCP3CON equ 0F4Dh ;# 
# 28533 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR3 equ 0F4Eh ;# 
# 28539 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR3L equ 0F4Eh ;# 
# 28558 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR3H equ 0F4Fh ;# 
# 28577 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCP2CON equ 0F50h ;# 
# 28582 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ECCP2CON equ 0F50h ;# 
# 28732 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR2 equ 0F51h ;# 
# 28738 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR2L equ 0F51h ;# 
# 28757 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR2H equ 0F52h ;# 
# 28776 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CTMUICON equ 0F53h ;# 
# 28851 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CTMUCONL equ 0F54h ;# 
# 28928 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CTMUCONH equ 0F55h ;# 
# 28984 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PADCFG1 equ 0F56h ;# 
# 29011 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PMD2 equ 0F57h ;# 
# 29042 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PMD1 equ 0F58h ;# 
# 29111 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PMD0 equ 0F59h ;# 
# 29190 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
IOCB equ 0F5Ah ;# 
# 29228 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
WPUB equ 0F5Bh ;# 
# 29289 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ANCON1 equ 0F5Ch ;# 
# 29346 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ANCON0 equ 0F5Dh ;# 
# 29433 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CM2CON equ 0F5Eh ;# 
# 29438 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CM2CON1 equ 0F5Eh ;# 
# 29726 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CM1CON equ 0F5Fh ;# 
# 29731 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CM1CON1 equ 0F5Fh ;# 
# 30053 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0CON equ 0F60h ;# 
# 30259 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0SIDH equ 0F61h ;# 
# 30399 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0SIDL equ 0F62h ;# 
# 30532 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0EIDH equ 0F63h ;# 
# 30672 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0EIDL equ 0F64h ;# 
# 30812 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0DLC equ 0F65h ;# 
# 30943 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0D0 equ 0F66h ;# 
# 31012 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0D1 equ 0F67h ;# 
# 31081 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0D2 equ 0F68h ;# 
# 31150 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0D3 equ 0F69h ;# 
# 31219 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0D4 equ 0F6Ah ;# 
# 31288 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0D5 equ 0F6Bh ;# 
# 31357 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0D6 equ 0F6Ch ;# 
# 31426 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0D7 equ 0F6Dh ;# 
# 31495 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANSTAT equ 0F6Eh ;# 
# 31605 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANCON equ 0F6Fh ;# 
# 31696 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CIOCON equ 0F70h ;# 
# 31740 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
COMSTAT equ 0F71h ;# 
# 31846 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ECANCON equ 0F72h ;# 
# 31922 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
EEDATA equ 0F73h ;# 
# 31941 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
EEADR equ 0F74h ;# 
# 31960 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
EEADRH equ 0F75h ;# 
# 31979 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PIE5 equ 0F76h ;# 
# 32061 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PIR5 equ 0F77h ;# 
# 32143 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
IPR5 equ 0F78h ;# 
# 32260 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXREG2 equ 0F79h ;# 
# 32279 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RCREG2 equ 0F7Ah ;# 
# 32298 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
SPBRG2 equ 0F7Bh ;# 
# 32317 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
SPBRGH2 equ 0F7Ch ;# 
# 32336 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
SPBRGH1 equ 0F7Dh ;# 
# 32355 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
EECON2 equ 0F7Eh ;# 
# 32374 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
EECON1 equ 0F7Fh ;# 
# 32439 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PORTA equ 0F80h ;# 
# 32530 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PORTB equ 0F81h ;# 
# 32600 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PORTC equ 0F82h ;# 
# 32688 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PORTE equ 0F84h ;# 
# 32921 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TMR4 equ 0F87h ;# 
# 32940 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
T4CON equ 0F88h ;# 
# 33010 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
LATA equ 0F89h ;# 
# 33137 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
LATB equ 0F8Ah ;# 
# 33269 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
LATC equ 0F8Bh ;# 
# 33401 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
SLRCON equ 0F90h ;# 
# 33432 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ODCON equ 0F91h ;# 
# 33493 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TRISA equ 0F92h ;# 
# 33549 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TRISB equ 0F93h ;# 
# 33610 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TRISC equ 0F94h ;# 
# 33671 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPTMRS equ 0F99h ;# 
# 33714 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
REFOCON equ 0F9Ah ;# 
# 33778 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
OSCTUNE equ 0F9Bh ;# 
# 33847 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PSTR1CON equ 0F9Ch ;# 
# 33912 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PIE1 equ 0F9Dh ;# 
# 33982 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PIR1 equ 0F9Eh ;# 
# 34052 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
IPR1 equ 0F9Fh ;# 
# 34122 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PIE2 equ 0FA0h ;# 
# 34175 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PIR2 equ 0FA1h ;# 
# 34228 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
IPR2 equ 0FA2h ;# 
# 34281 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PIE3 equ 0FA3h ;# 
# 34379 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PIR3 equ 0FA4h ;# 
# 34441 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
IPR3 equ 0FA5h ;# 
# 34503 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RCSTA2 equ 0FA6h ;# 
# 34640 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
BAUDCON1 equ 0FA7h ;# 
# 34821 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
HLVDCON equ 0FA8h ;# 
# 34890 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PR4 equ 0FA9h ;# 
# 34909 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
T1GCON equ 0FAAh ;# 
# 35012 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RCSTA1 equ 0FABh ;# 
# 35017 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RCSTA equ 0FABh ;# 
# 35349 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXSTA1 equ 0FACh ;# 
# 35354 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXSTA equ 0FACh ;# 
# 35636 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXREG1 equ 0FADh ;# 
# 35641 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXREG equ 0FADh ;# 
# 35673 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RCREG1 equ 0FAEh ;# 
# 35678 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RCREG equ 0FAEh ;# 
# 35710 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
SPBRG1 equ 0FAFh ;# 
# 35715 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
SPBRG equ 0FAFh ;# 
# 35747 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
T3GCON equ 0FB0h ;# 
# 35850 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
T3CON equ 0FB1h ;# 
# 35962 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TMR3 equ 0FB2h ;# 
# 35968 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TMR3L equ 0FB2h ;# 
# 35987 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TMR3H equ 0FB3h ;# 
# 36006 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CMSTAT equ 0FB4h ;# 
# 36011 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CMSTATUS equ 0FB4h ;# 
# 36093 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CVRCON equ 0FB5h ;# 
# 36180 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PIE4 equ 0FB6h ;# 
# 36236 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PIR4 equ 0FB7h ;# 
# 36292 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
IPR4 equ 0FB8h ;# 
# 36356 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
BAUDCON2 equ 0FB9h ;# 
# 36510 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXSTA2 equ 0FBAh ;# 
# 36638 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCP1CON equ 0FBBh ;# 
# 36643 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ECCP1CON equ 0FBBh ;# 
# 36829 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR1 equ 0FBCh ;# 
# 36835 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR1L equ 0FBCh ;# 
# 36854 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR1H equ 0FBDh ;# 
# 36873 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ECCP1DEL equ 0FBEh ;# 
# 36878 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PWM1CON equ 0FBEh ;# 
# 37010 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ECCP1AS equ 0FBFh ;# 
# 37091 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ADCON2 equ 0FC0h ;# 
# 37161 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ADCON1 equ 0FC1h ;# 
# 37270 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ADCON0 equ 0FC2h ;# 
# 37394 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ADRES equ 0FC3h ;# 
# 37400 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ADRESL equ 0FC3h ;# 
# 37419 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ADRESH equ 0FC4h ;# 
# 37438 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
SSPCON2 equ 0FC5h ;# 
# 37532 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
SSPCON1 equ 0FC6h ;# 
# 37601 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
SSPSTAT equ 0FC7h ;# 
# 37843 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
SSPADD equ 0FC8h ;# 
# 37912 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
SSPBUF equ 0FC9h ;# 
# 37931 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
T2CON equ 0FCAh ;# 
# 38001 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PR2 equ 0FCBh ;# 
# 38006 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
MEMCON equ 0FCBh ;# 
# 38126 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TMR2 equ 0FCCh ;# 
# 38145 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
T1CON equ 0FCDh ;# 
# 38248 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TMR1 equ 0FCEh ;# 
# 38254 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TMR1L equ 0FCEh ;# 
# 38273 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TMR1H equ 0FCFh ;# 
# 38292 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RCON equ 0FD0h ;# 
# 38444 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
WDTCON equ 0FD1h ;# 
# 38503 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
OSCCON2 equ 0FD2h ;# 
# 38574 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
OSCCON equ 0FD3h ;# 
# 38650 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
T0CON equ 0FD5h ;# 
# 38719 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TMR0 equ 0FD6h ;# 
# 38725 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TMR0L equ 0FD6h ;# 
# 38744 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TMR0H equ 0FD7h ;# 
# 38763 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
STATUS equ 0FD8h ;# 
# 38841 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
FSR2 equ 0FD9h ;# 
# 38847 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
FSR2L equ 0FD9h ;# 
# 38866 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
FSR2H equ 0FDAh ;# 
# 38885 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PLUSW2 equ 0FDBh ;# 
# 38904 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PREINC2 equ 0FDCh ;# 
# 38923 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
POSTDEC2 equ 0FDDh ;# 
# 38942 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
POSTINC2 equ 0FDEh ;# 
# 38961 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
INDF2 equ 0FDFh ;# 
# 38980 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
BSR equ 0FE0h ;# 
# 38999 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
FSR1 equ 0FE1h ;# 
# 39005 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
FSR1L equ 0FE1h ;# 
# 39024 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
FSR1H equ 0FE2h ;# 
# 39043 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PLUSW1 equ 0FE3h ;# 
# 39062 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PREINC1 equ 0FE4h ;# 
# 39081 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
POSTDEC1 equ 0FE5h ;# 
# 39100 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
POSTINC1 equ 0FE6h ;# 
# 39119 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
INDF1 equ 0FE7h ;# 
# 39138 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
WREG equ 0FE8h ;# 
# 39157 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
FSR0 equ 0FE9h ;# 
# 39163 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
FSR0L equ 0FE9h ;# 
# 39182 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
FSR0H equ 0FEAh ;# 
# 39201 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PLUSW0 equ 0FEBh ;# 
# 39220 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PREINC0 equ 0FECh ;# 
# 39239 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
POSTDEC0 equ 0FEDh ;# 
# 39258 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
POSTINC0 equ 0FEEh ;# 
# 39277 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
INDF0 equ 0FEFh ;# 
# 39296 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
INTCON3 equ 0FF0h ;# 
# 39407 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
INTCON2 equ 0FF1h ;# 
# 39499 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
INTCON equ 0FF2h ;# 
# 39504 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
INTCON1 equ 0FF2h ;# 
# 39760 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PROD equ 0FF3h ;# 
# 39766 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PRODL equ 0FF3h ;# 
# 39785 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PRODH equ 0FF4h ;# 
# 39804 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TABLAT equ 0FF5h ;# 
# 39825 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TBLPTR equ 0FF6h ;# 
# 39831 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TBLPTRL equ 0FF6h ;# 
# 39850 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TBLPTRH equ 0FF7h ;# 
# 39869 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TBLPTRU equ 0FF8h ;# 
# 39890 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PCLAT equ 0FF9h ;# 
# 39897 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PC equ 0FF9h ;# 
# 39903 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PCL equ 0FF9h ;# 
# 39922 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PCLATH equ 0FFAh ;# 
# 39941 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PCLATU equ 0FFBh ;# 
# 39960 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
STKPTR equ 0FFCh ;# 
# 40033 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TOS equ 0FFDh ;# 
# 40039 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TOSL equ 0FFDh ;# 
# 40058 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TOSH equ 0FFEh ;# 
# 40077 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TOSU equ 0FFFh ;# 
# 46 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXERRCNT equ 0E41h ;# 
# 115 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXERRCNT equ 0E42h ;# 
# 184 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
BRGCON1 equ 0E43h ;# 
# 259 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
BRGCON2 equ 0E44h ;# 
# 343 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
BRGCON3 equ 0E45h ;# 
# 395 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXFCON0 equ 0E46h ;# 
# 456 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXFCON1 equ 0E47h ;# 
# 517 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF6SIDH equ 0E48h ;# 
# 657 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF6SIDL equ 0E49h ;# 
# 776 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF6EIDH equ 0E4Ah ;# 
# 916 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF6EIDL equ 0E4Bh ;# 
# 1056 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF7SIDH equ 0E4Ch ;# 
# 1196 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF7SIDL equ 0E4Dh ;# 
# 1315 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF7EIDH equ 0E4Eh ;# 
# 1455 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF7EIDL equ 0E4Fh ;# 
# 1595 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF8SIDH equ 0E50h ;# 
# 1735 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF8SIDL equ 0E51h ;# 
# 1854 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF8EIDH equ 0E52h ;# 
# 1994 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF8EIDL equ 0E53h ;# 
# 2134 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF9SIDH equ 0E54h ;# 
# 2274 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF9SIDL equ 0E55h ;# 
# 2393 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF9EIDH equ 0E56h ;# 
# 2533 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF9EIDL equ 0E57h ;# 
# 2673 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF10SIDH equ 0E58h ;# 
# 2813 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF10SIDL equ 0E59h ;# 
# 2932 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF10EIDH equ 0E5Ah ;# 
# 3072 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF10EIDL equ 0E5Bh ;# 
# 3212 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF11SIDH equ 0E5Ch ;# 
# 3352 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF11SIDL equ 0E5Dh ;# 
# 3471 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF11EIDH equ 0E5Eh ;# 
# 3611 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF11EIDL equ 0E5Fh ;# 
# 3751 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF12SIDH equ 0E60h ;# 
# 3891 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF12SIDL equ 0E61h ;# 
# 4010 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF12EIDH equ 0E62h ;# 
# 4150 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF12EIDL equ 0E63h ;# 
# 4290 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF13SIDH equ 0E64h ;# 
# 4430 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF13SIDL equ 0E65h ;# 
# 4549 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF13EIDH equ 0E66h ;# 
# 4689 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF13EIDL equ 0E67h ;# 
# 4829 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF14SIDH equ 0E68h ;# 
# 4969 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF14SIDL equ 0E69h ;# 
# 5088 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF14EIDH equ 0E6Ah ;# 
# 5228 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF14EIDL equ 0E6Bh ;# 
# 5368 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF15SIDH equ 0E6Ch ;# 
# 5508 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF15SIDL equ 0E6Dh ;# 
# 5627 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF15EIDH equ 0E6Eh ;# 
# 5767 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF15EIDL equ 0E6Fh ;# 
# 5907 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
SDFLC equ 0E70h ;# 
# 5958 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXFBCON0 equ 0E71h ;# 
# 6041 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXFBCON1 equ 0E72h ;# 
# 6124 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXFBCON2 equ 0E73h ;# 
# 6207 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXFBCON3 equ 0E74h ;# 
# 6290 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXFBCON4 equ 0E75h ;# 
# 6373 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXFBCON5 equ 0E76h ;# 
# 6456 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXFBCON6 equ 0E77h ;# 
# 6539 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXFBCON7 equ 0E78h ;# 
# 6622 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
MSEL0 equ 0E79h ;# 
# 6709 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
MSEL1 equ 0E7Ah ;# 
# 6796 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
MSEL2 equ 0E7Bh ;# 
# 6883 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
MSEL3 equ 0E7Ch ;# 
# 6970 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
BSEL0 equ 0E7Dh ;# 
# 7020 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
BIE0 equ 0E7Eh ;# 
# 7098 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXBIE equ 0E7Fh ;# 
# 7157 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0CON equ 0E80h ;# 
# 7460 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0SIDH equ 0E81h ;# 
# 7600 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0SIDL equ 0E82h ;# 
# 7733 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0EIDH equ 0E83h ;# 
# 7873 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0EIDL equ 0E84h ;# 
# 8013 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0DLC equ 0E85h ;# 
# 8159 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0D0 equ 0E86h ;# 
# 8228 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0D1 equ 0E87h ;# 
# 8297 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0D2 equ 0E88h ;# 
# 8366 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0D3 equ 0E89h ;# 
# 8435 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0D4 equ 0E8Ah ;# 
# 8504 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0D5 equ 0E8Bh ;# 
# 8573 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0D6 equ 0E8Ch ;# 
# 8642 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0D7 equ 0E8Dh ;# 
# 8711 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANSTAT_RO9 equ 0E8Eh ;# 
# 8821 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANCON_RO9 equ 0E8Fh ;# 
# 8912 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1CON equ 0E90h ;# 
# 9215 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1SIDH equ 0E91h ;# 
# 9355 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1SIDL equ 0E92h ;# 
# 9488 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1EIDH equ 0E93h ;# 
# 9628 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1EIDL equ 0E94h ;# 
# 9768 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1DLC equ 0E95h ;# 
# 9914 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1D0 equ 0E96h ;# 
# 9983 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1D1 equ 0E97h ;# 
# 10052 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1D2 equ 0E98h ;# 
# 10121 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1D3 equ 0E99h ;# 
# 10190 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1D4 equ 0E9Ah ;# 
# 10259 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1D5 equ 0E9Bh ;# 
# 10328 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1D6 equ 0E9Ch ;# 
# 10397 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1D7 equ 0E9Dh ;# 
# 10466 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANSTAT_RO8 equ 0E9Eh ;# 
# 10576 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANCON_RO8 equ 0E9Fh ;# 
# 10667 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2CON equ 0EA0h ;# 
# 10970 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2SIDH equ 0EA1h ;# 
# 11110 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2SIDL equ 0EA2h ;# 
# 11252 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2EIDH equ 0EA3h ;# 
# 11392 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2EIDL equ 0EA4h ;# 
# 11532 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2DLC equ 0EA5h ;# 
# 11678 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2D0 equ 0EA6h ;# 
# 11747 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2D1 equ 0EA7h ;# 
# 11816 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2D2 equ 0EA8h ;# 
# 11885 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2D3 equ 0EA9h ;# 
# 11954 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2D4 equ 0EAAh ;# 
# 12023 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2D5 equ 0EABh ;# 
# 12092 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2D6 equ 0EACh ;# 
# 12161 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2D7 equ 0EADh ;# 
# 12230 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANSTAT_RO7 equ 0EAEh ;# 
# 12340 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANCON_RO7 equ 0EAFh ;# 
# 12431 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3CON equ 0EB0h ;# 
# 12734 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3SIDH equ 0EB1h ;# 
# 12874 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3SIDL equ 0EB2h ;# 
# 13016 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3EIDH equ 0EB3h ;# 
# 13156 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3EIDL equ 0EB4h ;# 
# 13296 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3DLC equ 0EB5h ;# 
# 13442 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3D0 equ 0EB6h ;# 
# 13511 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3D1 equ 0EB7h ;# 
# 13580 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3D2 equ 0EB8h ;# 
# 13649 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3D3 equ 0EB9h ;# 
# 13718 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3D4 equ 0EBAh ;# 
# 13787 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3D5 equ 0EBBh ;# 
# 13856 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3D6 equ 0EBCh ;# 
# 13925 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3D7 equ 0EBDh ;# 
# 13994 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANSTAT_RO6 equ 0EBEh ;# 
# 14104 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANCON_RO6 equ 0EBFh ;# 
# 14195 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4CON equ 0EC0h ;# 
# 14498 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4SIDH equ 0EC1h ;# 
# 14638 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4SIDL equ 0EC2h ;# 
# 14780 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4EIDH equ 0EC3h ;# 
# 14920 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4EIDL equ 0EC4h ;# 
# 15060 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4DLC equ 0EC5h ;# 
# 15206 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4D0 equ 0EC6h ;# 
# 15275 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4D1 equ 0EC7h ;# 
# 15344 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4D2 equ 0EC8h ;# 
# 15413 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4D3 equ 0EC9h ;# 
# 15482 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4D4 equ 0ECAh ;# 
# 15551 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4D5 equ 0ECBh ;# 
# 15620 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4D6 equ 0ECCh ;# 
# 15689 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4D7 equ 0ECDh ;# 
# 15758 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANSTAT_RO5 equ 0ECEh ;# 
# 15868 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANCON_RO5 equ 0ECFh ;# 
# 15959 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5CON equ 0ED0h ;# 
# 16262 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5SIDH equ 0ED1h ;# 
# 16402 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5SIDL equ 0ED2h ;# 
# 16544 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5EIDH equ 0ED3h ;# 
# 16684 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5EIDL equ 0ED4h ;# 
# 16824 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5DLC equ 0ED5h ;# 
# 16970 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5D0 equ 0ED6h ;# 
# 17039 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5D1 equ 0ED7h ;# 
# 17108 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5D2 equ 0ED8h ;# 
# 17177 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5D3 equ 0ED9h ;# 
# 17246 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5D4 equ 0EDAh ;# 
# 17315 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5D5 equ 0EDBh ;# 
# 17384 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5D6 equ 0EDCh ;# 
# 17453 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5D7 equ 0EDDh ;# 
# 17522 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANSTAT_RO4 equ 0EDEh ;# 
# 17632 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANCON_RO4 equ 0EDFh ;# 
# 17723 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF0SIDH equ 0EE0h ;# 
# 17863 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF0SIDL equ 0EE1h ;# 
# 17982 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF0EIDH equ 0EE2h ;# 
# 18122 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF0EIDL equ 0EE3h ;# 
# 18262 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF1SIDH equ 0EE4h ;# 
# 18402 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF1SIDL equ 0EE5h ;# 
# 18521 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF1EIDH equ 0EE6h ;# 
# 18661 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF1EIDL equ 0EE7h ;# 
# 18801 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF2SIDH equ 0EE8h ;# 
# 18941 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF2SIDL equ 0EE9h ;# 
# 19060 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF2EIDH equ 0EEAh ;# 
# 19200 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF2EIDL equ 0EEBh ;# 
# 19340 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF3SIDH equ 0EECh ;# 
# 19480 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF3SIDL equ 0EEDh ;# 
# 19599 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF3EIDH equ 0EEEh ;# 
# 19739 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF3EIDL equ 0EEFh ;# 
# 19879 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF4SIDH equ 0EF0h ;# 
# 20019 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF4SIDL equ 0EF1h ;# 
# 20138 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF4EIDH equ 0EF2h ;# 
# 20278 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF4EIDL equ 0EF3h ;# 
# 20418 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF5SIDH equ 0EF4h ;# 
# 20558 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF5SIDL equ 0EF5h ;# 
# 20677 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF5EIDH equ 0EF6h ;# 
# 20817 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF5EIDL equ 0EF7h ;# 
# 20957 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXM0SIDH equ 0EF8h ;# 
# 21097 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXM0SIDL equ 0EF9h ;# 
# 21216 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXM0EIDH equ 0EFAh ;# 
# 21356 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXM0EIDL equ 0EFBh ;# 
# 21496 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXM1SIDH equ 0EFCh ;# 
# 21636 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXM1SIDL equ 0EFDh ;# 
# 21755 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXM1EIDH equ 0EFEh ;# 
# 21895 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXM1EIDL equ 0EFFh ;# 
# 22035 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2CON equ 0F00h ;# 
# 22161 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2SIDH equ 0F01h ;# 
# 22301 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2SIDL equ 0F02h ;# 
# 22425 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2EIDH equ 0F03h ;# 
# 22565 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2EIDL equ 0F04h ;# 
# 22705 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2DLC equ 0F05h ;# 
# 22801 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2D0 equ 0F06h ;# 
# 22870 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2D1 equ 0F07h ;# 
# 22939 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2D2 equ 0F08h ;# 
# 23008 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2D3 equ 0F09h ;# 
# 23077 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2D4 equ 0F0Ah ;# 
# 23146 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2D5 equ 0F0Bh ;# 
# 23215 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2D6 equ 0F0Ch ;# 
# 23284 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2D7 equ 0F0Dh ;# 
# 23353 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANSTAT_RO3 equ 0F0Eh ;# 
# 23463 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANCON_RO3 equ 0F0Fh ;# 
# 23554 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1CON equ 0F10h ;# 
# 23680 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1SIDH equ 0F11h ;# 
# 23820 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1SIDL equ 0F12h ;# 
# 23944 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1EIDH equ 0F13h ;# 
# 24084 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1EIDL equ 0F14h ;# 
# 24224 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1DLC equ 0F15h ;# 
# 24320 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1D0 equ 0F16h ;# 
# 24389 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1D1 equ 0F17h ;# 
# 24458 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1D2 equ 0F18h ;# 
# 24527 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1D3 equ 0F19h ;# 
# 24596 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1D4 equ 0F1Ah ;# 
# 24665 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1D5 equ 0F1Bh ;# 
# 24734 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1D6 equ 0F1Ch ;# 
# 24803 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1D7 equ 0F1Dh ;# 
# 24872 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANSTAT_RO2 equ 0F1Eh ;# 
# 24982 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANCON_RO2 equ 0F1Fh ;# 
# 25073 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0CON equ 0F20h ;# 
# 25199 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0SIDH equ 0F21h ;# 
# 25339 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0SIDL equ 0F22h ;# 
# 25463 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0EIDH equ 0F23h ;# 
# 25603 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0EIDL equ 0F24h ;# 
# 25743 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0DLC equ 0F25h ;# 
# 25839 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0D0 equ 0F26h ;# 
# 25908 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0D1 equ 0F27h ;# 
# 25977 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0D2 equ 0F28h ;# 
# 26046 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0D3 equ 0F29h ;# 
# 26115 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0D4 equ 0F2Ah ;# 
# 26184 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0D5 equ 0F2Bh ;# 
# 26253 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0D6 equ 0F2Ch ;# 
# 26322 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0D7 equ 0F2Dh ;# 
# 26391 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANSTAT_RO1 equ 0F2Eh ;# 
# 26501 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANCON_RO1 equ 0F2Fh ;# 
# 26592 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1CON equ 0F30h ;# 
# 26774 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1SIDH equ 0F31h ;# 
# 26914 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1SIDL equ 0F32h ;# 
# 27047 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1EIDH equ 0F33h ;# 
# 27187 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1EIDL equ 0F34h ;# 
# 27327 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1DLC equ 0F35h ;# 
# 27458 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1D0 equ 0F36h ;# 
# 27527 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1D1 equ 0F37h ;# 
# 27596 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1D2 equ 0F38h ;# 
# 27665 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1D3 equ 0F39h ;# 
# 27734 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1D4 equ 0F3Ah ;# 
# 27803 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1D5 equ 0F3Bh ;# 
# 27872 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1D6 equ 0F3Ch ;# 
# 27941 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1D7 equ 0F3Dh ;# 
# 28010 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANSTAT_RO0 equ 0F3Eh ;# 
# 28120 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANCON_RO0 equ 0F3Fh ;# 
# 28211 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCP5CON equ 0F47h ;# 
# 28289 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR5 equ 0F48h ;# 
# 28295 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR5L equ 0F48h ;# 
# 28314 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR5H equ 0F49h ;# 
# 28333 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCP4CON equ 0F4Ah ;# 
# 28411 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR4 equ 0F4Bh ;# 
# 28417 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR4L equ 0F4Bh ;# 
# 28436 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR4H equ 0F4Ch ;# 
# 28455 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCP3CON equ 0F4Dh ;# 
# 28533 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR3 equ 0F4Eh ;# 
# 28539 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR3L equ 0F4Eh ;# 
# 28558 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR3H equ 0F4Fh ;# 
# 28577 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCP2CON equ 0F50h ;# 
# 28582 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ECCP2CON equ 0F50h ;# 
# 28732 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR2 equ 0F51h ;# 
# 28738 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR2L equ 0F51h ;# 
# 28757 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR2H equ 0F52h ;# 
# 28776 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CTMUICON equ 0F53h ;# 
# 28851 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CTMUCONL equ 0F54h ;# 
# 28928 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CTMUCONH equ 0F55h ;# 
# 28984 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PADCFG1 equ 0F56h ;# 
# 29011 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PMD2 equ 0F57h ;# 
# 29042 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PMD1 equ 0F58h ;# 
# 29111 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PMD0 equ 0F59h ;# 
# 29190 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
IOCB equ 0F5Ah ;# 
# 29228 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
WPUB equ 0F5Bh ;# 
# 29289 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ANCON1 equ 0F5Ch ;# 
# 29346 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ANCON0 equ 0F5Dh ;# 
# 29433 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CM2CON equ 0F5Eh ;# 
# 29438 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CM2CON1 equ 0F5Eh ;# 
# 29726 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CM1CON equ 0F5Fh ;# 
# 29731 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CM1CON1 equ 0F5Fh ;# 
# 30053 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0CON equ 0F60h ;# 
# 30259 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0SIDH equ 0F61h ;# 
# 30399 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0SIDL equ 0F62h ;# 
# 30532 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0EIDH equ 0F63h ;# 
# 30672 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0EIDL equ 0F64h ;# 
# 30812 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0DLC equ 0F65h ;# 
# 30943 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0D0 equ 0F66h ;# 
# 31012 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0D1 equ 0F67h ;# 
# 31081 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0D2 equ 0F68h ;# 
# 31150 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0D3 equ 0F69h ;# 
# 31219 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0D4 equ 0F6Ah ;# 
# 31288 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0D5 equ 0F6Bh ;# 
# 31357 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0D6 equ 0F6Ch ;# 
# 31426 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0D7 equ 0F6Dh ;# 
# 31495 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANSTAT equ 0F6Eh ;# 
# 31605 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANCON equ 0F6Fh ;# 
# 31696 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CIOCON equ 0F70h ;# 
# 31740 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
COMSTAT equ 0F71h ;# 
# 31846 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ECANCON equ 0F72h ;# 
# 31922 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
EEDATA equ 0F73h ;# 
# 31941 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
EEADR equ 0F74h ;# 
# 31960 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
EEADRH equ 0F75h ;# 
# 31979 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PIE5 equ 0F76h ;# 
# 32061 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PIR5 equ 0F77h ;# 
# 32143 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
IPR5 equ 0F78h ;# 
# 32260 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXREG2 equ 0F79h ;# 
# 32279 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RCREG2 equ 0F7Ah ;# 
# 32298 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
SPBRG2 equ 0F7Bh ;# 
# 32317 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
SPBRGH2 equ 0F7Ch ;# 
# 32336 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
SPBRGH1 equ 0F7Dh ;# 
# 32355 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
EECON2 equ 0F7Eh ;# 
# 32374 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
EECON1 equ 0F7Fh ;# 
# 32439 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PORTA equ 0F80h ;# 
# 32530 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PORTB equ 0F81h ;# 
# 32600 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PORTC equ 0F82h ;# 
# 32688 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PORTE equ 0F84h ;# 
# 32921 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TMR4 equ 0F87h ;# 
# 32940 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
T4CON equ 0F88h ;# 
# 33010 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
LATA equ 0F89h ;# 
# 33137 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
LATB equ 0F8Ah ;# 
# 33269 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
LATC equ 0F8Bh ;# 
# 33401 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
SLRCON equ 0F90h ;# 
# 33432 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ODCON equ 0F91h ;# 
# 33493 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TRISA equ 0F92h ;# 
# 33549 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TRISB equ 0F93h ;# 
# 33610 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TRISC equ 0F94h ;# 
# 33671 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPTMRS equ 0F99h ;# 
# 33714 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
REFOCON equ 0F9Ah ;# 
# 33778 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
OSCTUNE equ 0F9Bh ;# 
# 33847 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PSTR1CON equ 0F9Ch ;# 
# 33912 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PIE1 equ 0F9Dh ;# 
# 33982 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PIR1 equ 0F9Eh ;# 
# 34052 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
IPR1 equ 0F9Fh ;# 
# 34122 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PIE2 equ 0FA0h ;# 
# 34175 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PIR2 equ 0FA1h ;# 
# 34228 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
IPR2 equ 0FA2h ;# 
# 34281 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PIE3 equ 0FA3h ;# 
# 34379 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PIR3 equ 0FA4h ;# 
# 34441 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
IPR3 equ 0FA5h ;# 
# 34503 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RCSTA2 equ 0FA6h ;# 
# 34640 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
BAUDCON1 equ 0FA7h ;# 
# 34821 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
HLVDCON equ 0FA8h ;# 
# 34890 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PR4 equ 0FA9h ;# 
# 34909 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
T1GCON equ 0FAAh ;# 
# 35012 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RCSTA1 equ 0FABh ;# 
# 35017 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RCSTA equ 0FABh ;# 
# 35349 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXSTA1 equ 0FACh ;# 
# 35354 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXSTA equ 0FACh ;# 
# 35636 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXREG1 equ 0FADh ;# 
# 35641 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXREG equ 0FADh ;# 
# 35673 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RCREG1 equ 0FAEh ;# 
# 35678 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RCREG equ 0FAEh ;# 
# 35710 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
SPBRG1 equ 0FAFh ;# 
# 35715 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
SPBRG equ 0FAFh ;# 
# 35747 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
T3GCON equ 0FB0h ;# 
# 35850 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
T3CON equ 0FB1h ;# 
# 35962 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TMR3 equ 0FB2h ;# 
# 35968 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TMR3L equ 0FB2h ;# 
# 35987 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TMR3H equ 0FB3h ;# 
# 36006 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CMSTAT equ 0FB4h ;# 
# 36011 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CMSTATUS equ 0FB4h ;# 
# 36093 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CVRCON equ 0FB5h ;# 
# 36180 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PIE4 equ 0FB6h ;# 
# 36236 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PIR4 equ 0FB7h ;# 
# 36292 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
IPR4 equ 0FB8h ;# 
# 36356 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
BAUDCON2 equ 0FB9h ;# 
# 36510 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXSTA2 equ 0FBAh ;# 
# 36638 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCP1CON equ 0FBBh ;# 
# 36643 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ECCP1CON equ 0FBBh ;# 
# 36829 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR1 equ 0FBCh ;# 
# 36835 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR1L equ 0FBCh ;# 
# 36854 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR1H equ 0FBDh ;# 
# 36873 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ECCP1DEL equ 0FBEh ;# 
# 36878 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PWM1CON equ 0FBEh ;# 
# 37010 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ECCP1AS equ 0FBFh ;# 
# 37091 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ADCON2 equ 0FC0h ;# 
# 37161 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ADCON1 equ 0FC1h ;# 
# 37270 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ADCON0 equ 0FC2h ;# 
# 37394 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ADRES equ 0FC3h ;# 
# 37400 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ADRESL equ 0FC3h ;# 
# 37419 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ADRESH equ 0FC4h ;# 
# 37438 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
SSPCON2 equ 0FC5h ;# 
# 37532 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
SSPCON1 equ 0FC6h ;# 
# 37601 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
SSPSTAT equ 0FC7h ;# 
# 37843 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
SSPADD equ 0FC8h ;# 
# 37912 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
SSPBUF equ 0FC9h ;# 
# 37931 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
T2CON equ 0FCAh ;# 
# 38001 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PR2 equ 0FCBh ;# 
# 38006 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
MEMCON equ 0FCBh ;# 
# 38126 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TMR2 equ 0FCCh ;# 
# 38145 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
T1CON equ 0FCDh ;# 
# 38248 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TMR1 equ 0FCEh ;# 
# 38254 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TMR1L equ 0FCEh ;# 
# 38273 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TMR1H equ 0FCFh ;# 
# 38292 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RCON equ 0FD0h ;# 
# 38444 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
WDTCON equ 0FD1h ;# 
# 38503 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
OSCCON2 equ 0FD2h ;# 
# 38574 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
OSCCON equ 0FD3h ;# 
# 38650 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
T0CON equ 0FD5h ;# 
# 38719 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TMR0 equ 0FD6h ;# 
# 38725 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TMR0L equ 0FD6h ;# 
# 38744 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TMR0H equ 0FD7h ;# 
# 38763 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
STATUS equ 0FD8h ;# 
# 38841 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
FSR2 equ 0FD9h ;# 
# 38847 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
FSR2L equ 0FD9h ;# 
# 38866 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
FSR2H equ 0FDAh ;# 
# 38885 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PLUSW2 equ 0FDBh ;# 
# 38904 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PREINC2 equ 0FDCh ;# 
# 38923 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
POSTDEC2 equ 0FDDh ;# 
# 38942 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
POSTINC2 equ 0FDEh ;# 
# 38961 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
INDF2 equ 0FDFh ;# 
# 38980 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
BSR equ 0FE0h ;# 
# 38999 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
FSR1 equ 0FE1h ;# 
# 39005 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
FSR1L equ 0FE1h ;# 
# 39024 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
FSR1H equ 0FE2h ;# 
# 39043 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PLUSW1 equ 0FE3h ;# 
# 39062 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PREINC1 equ 0FE4h ;# 
# 39081 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
POSTDEC1 equ 0FE5h ;# 
# 39100 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
POSTINC1 equ 0FE6h ;# 
# 39119 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
INDF1 equ 0FE7h ;# 
# 39138 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
WREG equ 0FE8h ;# 
# 39157 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
FSR0 equ 0FE9h ;# 
# 39163 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
FSR0L equ 0FE9h ;# 
# 39182 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
FSR0H equ 0FEAh ;# 
# 39201 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PLUSW0 equ 0FEBh ;# 
# 39220 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PREINC0 equ 0FECh ;# 
# 39239 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
POSTDEC0 equ 0FEDh ;# 
# 39258 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
POSTINC0 equ 0FEEh ;# 
# 39277 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
INDF0 equ 0FEFh ;# 
# 39296 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
INTCON3 equ 0FF0h ;# 
# 39407 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
INTCON2 equ 0FF1h ;# 
# 39499 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
INTCON equ 0FF2h ;# 
# 39504 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
INTCON1 equ 0FF2h ;# 
# 39760 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PROD equ 0FF3h ;# 
# 39766 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PRODL equ 0FF3h ;# 
# 39785 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PRODH equ 0FF4h ;# 
# 39804 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TABLAT equ 0FF5h ;# 
# 39825 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TBLPTR equ 0FF6h ;# 
# 39831 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TBLPTRL equ 0FF6h ;# 
# 39850 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TBLPTRH equ 0FF7h ;# 
# 39869 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TBLPTRU equ 0FF8h ;# 
# 39890 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PCLAT equ 0FF9h ;# 
# 39897 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PC equ 0FF9h ;# 
# 39903 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PCL equ 0FF9h ;# 
# 39922 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PCLATH equ 0FFAh ;# 
# 39941 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PCLATU equ 0FFBh ;# 
# 39960 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
STKPTR equ 0FFCh ;# 
# 40033 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TOS equ 0FFDh ;# 
# 40039 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TOSL equ 0FFDh ;# 
# 40058 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TOSH equ 0FFEh ;# 
# 40077 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TOSU equ 0FFFh ;# 
# 46 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXERRCNT equ 0E41h ;# 
# 115 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXERRCNT equ 0E42h ;# 
# 184 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
BRGCON1 equ 0E43h ;# 
# 259 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
BRGCON2 equ 0E44h ;# 
# 343 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
BRGCON3 equ 0E45h ;# 
# 395 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXFCON0 equ 0E46h ;# 
# 456 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXFCON1 equ 0E47h ;# 
# 517 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF6SIDH equ 0E48h ;# 
# 657 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF6SIDL equ 0E49h ;# 
# 776 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF6EIDH equ 0E4Ah ;# 
# 916 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF6EIDL equ 0E4Bh ;# 
# 1056 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF7SIDH equ 0E4Ch ;# 
# 1196 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF7SIDL equ 0E4Dh ;# 
# 1315 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF7EIDH equ 0E4Eh ;# 
# 1455 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF7EIDL equ 0E4Fh ;# 
# 1595 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF8SIDH equ 0E50h ;# 
# 1735 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF8SIDL equ 0E51h ;# 
# 1854 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF8EIDH equ 0E52h ;# 
# 1994 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF8EIDL equ 0E53h ;# 
# 2134 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF9SIDH equ 0E54h ;# 
# 2274 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF9SIDL equ 0E55h ;# 
# 2393 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF9EIDH equ 0E56h ;# 
# 2533 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF9EIDL equ 0E57h ;# 
# 2673 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF10SIDH equ 0E58h ;# 
# 2813 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF10SIDL equ 0E59h ;# 
# 2932 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF10EIDH equ 0E5Ah ;# 
# 3072 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF10EIDL equ 0E5Bh ;# 
# 3212 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF11SIDH equ 0E5Ch ;# 
# 3352 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF11SIDL equ 0E5Dh ;# 
# 3471 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF11EIDH equ 0E5Eh ;# 
# 3611 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF11EIDL equ 0E5Fh ;# 
# 3751 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF12SIDH equ 0E60h ;# 
# 3891 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF12SIDL equ 0E61h ;# 
# 4010 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF12EIDH equ 0E62h ;# 
# 4150 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF12EIDL equ 0E63h ;# 
# 4290 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF13SIDH equ 0E64h ;# 
# 4430 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF13SIDL equ 0E65h ;# 
# 4549 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF13EIDH equ 0E66h ;# 
# 4689 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF13EIDL equ 0E67h ;# 
# 4829 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF14SIDH equ 0E68h ;# 
# 4969 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF14SIDL equ 0E69h ;# 
# 5088 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF14EIDH equ 0E6Ah ;# 
# 5228 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF14EIDL equ 0E6Bh ;# 
# 5368 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF15SIDH equ 0E6Ch ;# 
# 5508 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF15SIDL equ 0E6Dh ;# 
# 5627 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF15EIDH equ 0E6Eh ;# 
# 5767 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF15EIDL equ 0E6Fh ;# 
# 5907 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
SDFLC equ 0E70h ;# 
# 5958 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXFBCON0 equ 0E71h ;# 
# 6041 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXFBCON1 equ 0E72h ;# 
# 6124 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXFBCON2 equ 0E73h ;# 
# 6207 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXFBCON3 equ 0E74h ;# 
# 6290 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXFBCON4 equ 0E75h ;# 
# 6373 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXFBCON5 equ 0E76h ;# 
# 6456 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXFBCON6 equ 0E77h ;# 
# 6539 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXFBCON7 equ 0E78h ;# 
# 6622 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
MSEL0 equ 0E79h ;# 
# 6709 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
MSEL1 equ 0E7Ah ;# 
# 6796 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
MSEL2 equ 0E7Bh ;# 
# 6883 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
MSEL3 equ 0E7Ch ;# 
# 6970 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
BSEL0 equ 0E7Dh ;# 
# 7020 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
BIE0 equ 0E7Eh ;# 
# 7098 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXBIE equ 0E7Fh ;# 
# 7157 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0CON equ 0E80h ;# 
# 7460 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0SIDH equ 0E81h ;# 
# 7600 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0SIDL equ 0E82h ;# 
# 7733 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0EIDH equ 0E83h ;# 
# 7873 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0EIDL equ 0E84h ;# 
# 8013 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0DLC equ 0E85h ;# 
# 8159 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0D0 equ 0E86h ;# 
# 8228 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0D1 equ 0E87h ;# 
# 8297 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0D2 equ 0E88h ;# 
# 8366 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0D3 equ 0E89h ;# 
# 8435 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0D4 equ 0E8Ah ;# 
# 8504 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0D5 equ 0E8Bh ;# 
# 8573 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0D6 equ 0E8Ch ;# 
# 8642 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B0D7 equ 0E8Dh ;# 
# 8711 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANSTAT_RO9 equ 0E8Eh ;# 
# 8821 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANCON_RO9 equ 0E8Fh ;# 
# 8912 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1CON equ 0E90h ;# 
# 9215 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1SIDH equ 0E91h ;# 
# 9355 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1SIDL equ 0E92h ;# 
# 9488 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1EIDH equ 0E93h ;# 
# 9628 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1EIDL equ 0E94h ;# 
# 9768 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1DLC equ 0E95h ;# 
# 9914 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1D0 equ 0E96h ;# 
# 9983 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1D1 equ 0E97h ;# 
# 10052 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1D2 equ 0E98h ;# 
# 10121 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1D3 equ 0E99h ;# 
# 10190 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1D4 equ 0E9Ah ;# 
# 10259 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1D5 equ 0E9Bh ;# 
# 10328 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1D6 equ 0E9Ch ;# 
# 10397 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B1D7 equ 0E9Dh ;# 
# 10466 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANSTAT_RO8 equ 0E9Eh ;# 
# 10576 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANCON_RO8 equ 0E9Fh ;# 
# 10667 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2CON equ 0EA0h ;# 
# 10970 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2SIDH equ 0EA1h ;# 
# 11110 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2SIDL equ 0EA2h ;# 
# 11252 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2EIDH equ 0EA3h ;# 
# 11392 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2EIDL equ 0EA4h ;# 
# 11532 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2DLC equ 0EA5h ;# 
# 11678 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2D0 equ 0EA6h ;# 
# 11747 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2D1 equ 0EA7h ;# 
# 11816 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2D2 equ 0EA8h ;# 
# 11885 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2D3 equ 0EA9h ;# 
# 11954 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2D4 equ 0EAAh ;# 
# 12023 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2D5 equ 0EABh ;# 
# 12092 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2D6 equ 0EACh ;# 
# 12161 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B2D7 equ 0EADh ;# 
# 12230 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANSTAT_RO7 equ 0EAEh ;# 
# 12340 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANCON_RO7 equ 0EAFh ;# 
# 12431 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3CON equ 0EB0h ;# 
# 12734 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3SIDH equ 0EB1h ;# 
# 12874 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3SIDL equ 0EB2h ;# 
# 13016 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3EIDH equ 0EB3h ;# 
# 13156 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3EIDL equ 0EB4h ;# 
# 13296 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3DLC equ 0EB5h ;# 
# 13442 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3D0 equ 0EB6h ;# 
# 13511 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3D1 equ 0EB7h ;# 
# 13580 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3D2 equ 0EB8h ;# 
# 13649 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3D3 equ 0EB9h ;# 
# 13718 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3D4 equ 0EBAh ;# 
# 13787 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3D5 equ 0EBBh ;# 
# 13856 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3D6 equ 0EBCh ;# 
# 13925 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B3D7 equ 0EBDh ;# 
# 13994 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANSTAT_RO6 equ 0EBEh ;# 
# 14104 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANCON_RO6 equ 0EBFh ;# 
# 14195 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4CON equ 0EC0h ;# 
# 14498 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4SIDH equ 0EC1h ;# 
# 14638 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4SIDL equ 0EC2h ;# 
# 14780 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4EIDH equ 0EC3h ;# 
# 14920 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4EIDL equ 0EC4h ;# 
# 15060 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4DLC equ 0EC5h ;# 
# 15206 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4D0 equ 0EC6h ;# 
# 15275 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4D1 equ 0EC7h ;# 
# 15344 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4D2 equ 0EC8h ;# 
# 15413 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4D3 equ 0EC9h ;# 
# 15482 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4D4 equ 0ECAh ;# 
# 15551 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4D5 equ 0ECBh ;# 
# 15620 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4D6 equ 0ECCh ;# 
# 15689 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B4D7 equ 0ECDh ;# 
# 15758 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANSTAT_RO5 equ 0ECEh ;# 
# 15868 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANCON_RO5 equ 0ECFh ;# 
# 15959 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5CON equ 0ED0h ;# 
# 16262 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5SIDH equ 0ED1h ;# 
# 16402 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5SIDL equ 0ED2h ;# 
# 16544 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5EIDH equ 0ED3h ;# 
# 16684 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5EIDL equ 0ED4h ;# 
# 16824 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5DLC equ 0ED5h ;# 
# 16970 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5D0 equ 0ED6h ;# 
# 17039 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5D1 equ 0ED7h ;# 
# 17108 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5D2 equ 0ED8h ;# 
# 17177 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5D3 equ 0ED9h ;# 
# 17246 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5D4 equ 0EDAh ;# 
# 17315 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5D5 equ 0EDBh ;# 
# 17384 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5D6 equ 0EDCh ;# 
# 17453 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
B5D7 equ 0EDDh ;# 
# 17522 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANSTAT_RO4 equ 0EDEh ;# 
# 17632 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANCON_RO4 equ 0EDFh ;# 
# 17723 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF0SIDH equ 0EE0h ;# 
# 17863 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF0SIDL equ 0EE1h ;# 
# 17982 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF0EIDH equ 0EE2h ;# 
# 18122 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF0EIDL equ 0EE3h ;# 
# 18262 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF1SIDH equ 0EE4h ;# 
# 18402 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF1SIDL equ 0EE5h ;# 
# 18521 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF1EIDH equ 0EE6h ;# 
# 18661 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF1EIDL equ 0EE7h ;# 
# 18801 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF2SIDH equ 0EE8h ;# 
# 18941 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF2SIDL equ 0EE9h ;# 
# 19060 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF2EIDH equ 0EEAh ;# 
# 19200 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF2EIDL equ 0EEBh ;# 
# 19340 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF3SIDH equ 0EECh ;# 
# 19480 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF3SIDL equ 0EEDh ;# 
# 19599 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF3EIDH equ 0EEEh ;# 
# 19739 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF3EIDL equ 0EEFh ;# 
# 19879 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF4SIDH equ 0EF0h ;# 
# 20019 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF4SIDL equ 0EF1h ;# 
# 20138 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF4EIDH equ 0EF2h ;# 
# 20278 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF4EIDL equ 0EF3h ;# 
# 20418 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF5SIDH equ 0EF4h ;# 
# 20558 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF5SIDL equ 0EF5h ;# 
# 20677 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF5EIDH equ 0EF6h ;# 
# 20817 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXF5EIDL equ 0EF7h ;# 
# 20957 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXM0SIDH equ 0EF8h ;# 
# 21097 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXM0SIDL equ 0EF9h ;# 
# 21216 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXM0EIDH equ 0EFAh ;# 
# 21356 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXM0EIDL equ 0EFBh ;# 
# 21496 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXM1SIDH equ 0EFCh ;# 
# 21636 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXM1SIDL equ 0EFDh ;# 
# 21755 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXM1EIDH equ 0EFEh ;# 
# 21895 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXM1EIDL equ 0EFFh ;# 
# 22035 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2CON equ 0F00h ;# 
# 22161 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2SIDH equ 0F01h ;# 
# 22301 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2SIDL equ 0F02h ;# 
# 22425 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2EIDH equ 0F03h ;# 
# 22565 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2EIDL equ 0F04h ;# 
# 22705 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2DLC equ 0F05h ;# 
# 22801 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2D0 equ 0F06h ;# 
# 22870 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2D1 equ 0F07h ;# 
# 22939 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2D2 equ 0F08h ;# 
# 23008 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2D3 equ 0F09h ;# 
# 23077 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2D4 equ 0F0Ah ;# 
# 23146 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2D5 equ 0F0Bh ;# 
# 23215 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2D6 equ 0F0Ch ;# 
# 23284 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB2D7 equ 0F0Dh ;# 
# 23353 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANSTAT_RO3 equ 0F0Eh ;# 
# 23463 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANCON_RO3 equ 0F0Fh ;# 
# 23554 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1CON equ 0F10h ;# 
# 23680 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1SIDH equ 0F11h ;# 
# 23820 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1SIDL equ 0F12h ;# 
# 23944 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1EIDH equ 0F13h ;# 
# 24084 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1EIDL equ 0F14h ;# 
# 24224 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1DLC equ 0F15h ;# 
# 24320 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1D0 equ 0F16h ;# 
# 24389 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1D1 equ 0F17h ;# 
# 24458 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1D2 equ 0F18h ;# 
# 24527 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1D3 equ 0F19h ;# 
# 24596 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1D4 equ 0F1Ah ;# 
# 24665 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1D5 equ 0F1Bh ;# 
# 24734 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1D6 equ 0F1Ch ;# 
# 24803 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB1D7 equ 0F1Dh ;# 
# 24872 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANSTAT_RO2 equ 0F1Eh ;# 
# 24982 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANCON_RO2 equ 0F1Fh ;# 
# 25073 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0CON equ 0F20h ;# 
# 25199 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0SIDH equ 0F21h ;# 
# 25339 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0SIDL equ 0F22h ;# 
# 25463 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0EIDH equ 0F23h ;# 
# 25603 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0EIDL equ 0F24h ;# 
# 25743 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0DLC equ 0F25h ;# 
# 25839 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0D0 equ 0F26h ;# 
# 25908 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0D1 equ 0F27h ;# 
# 25977 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0D2 equ 0F28h ;# 
# 26046 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0D3 equ 0F29h ;# 
# 26115 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0D4 equ 0F2Ah ;# 
# 26184 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0D5 equ 0F2Bh ;# 
# 26253 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0D6 equ 0F2Ch ;# 
# 26322 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXB0D7 equ 0F2Dh ;# 
# 26391 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANSTAT_RO1 equ 0F2Eh ;# 
# 26501 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANCON_RO1 equ 0F2Fh ;# 
# 26592 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1CON equ 0F30h ;# 
# 26774 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1SIDH equ 0F31h ;# 
# 26914 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1SIDL equ 0F32h ;# 
# 27047 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1EIDH equ 0F33h ;# 
# 27187 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1EIDL equ 0F34h ;# 
# 27327 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1DLC equ 0F35h ;# 
# 27458 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1D0 equ 0F36h ;# 
# 27527 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1D1 equ 0F37h ;# 
# 27596 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1D2 equ 0F38h ;# 
# 27665 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1D3 equ 0F39h ;# 
# 27734 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1D4 equ 0F3Ah ;# 
# 27803 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1D5 equ 0F3Bh ;# 
# 27872 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1D6 equ 0F3Ch ;# 
# 27941 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB1D7 equ 0F3Dh ;# 
# 28010 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANSTAT_RO0 equ 0F3Eh ;# 
# 28120 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANCON_RO0 equ 0F3Fh ;# 
# 28211 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCP5CON equ 0F47h ;# 
# 28289 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR5 equ 0F48h ;# 
# 28295 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR5L equ 0F48h ;# 
# 28314 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR5H equ 0F49h ;# 
# 28333 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCP4CON equ 0F4Ah ;# 
# 28411 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR4 equ 0F4Bh ;# 
# 28417 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR4L equ 0F4Bh ;# 
# 28436 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR4H equ 0F4Ch ;# 
# 28455 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCP3CON equ 0F4Dh ;# 
# 28533 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR3 equ 0F4Eh ;# 
# 28539 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR3L equ 0F4Eh ;# 
# 28558 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR3H equ 0F4Fh ;# 
# 28577 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCP2CON equ 0F50h ;# 
# 28582 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ECCP2CON equ 0F50h ;# 
# 28732 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR2 equ 0F51h ;# 
# 28738 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR2L equ 0F51h ;# 
# 28757 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR2H equ 0F52h ;# 
# 28776 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CTMUICON equ 0F53h ;# 
# 28851 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CTMUCONL equ 0F54h ;# 
# 28928 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CTMUCONH equ 0F55h ;# 
# 28984 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PADCFG1 equ 0F56h ;# 
# 29011 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PMD2 equ 0F57h ;# 
# 29042 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PMD1 equ 0F58h ;# 
# 29111 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PMD0 equ 0F59h ;# 
# 29190 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
IOCB equ 0F5Ah ;# 
# 29228 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
WPUB equ 0F5Bh ;# 
# 29289 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ANCON1 equ 0F5Ch ;# 
# 29346 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ANCON0 equ 0F5Dh ;# 
# 29433 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CM2CON equ 0F5Eh ;# 
# 29438 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CM2CON1 equ 0F5Eh ;# 
# 29726 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CM1CON equ 0F5Fh ;# 
# 29731 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CM1CON1 equ 0F5Fh ;# 
# 30053 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0CON equ 0F60h ;# 
# 30259 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0SIDH equ 0F61h ;# 
# 30399 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0SIDL equ 0F62h ;# 
# 30532 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0EIDH equ 0F63h ;# 
# 30672 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0EIDL equ 0F64h ;# 
# 30812 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0DLC equ 0F65h ;# 
# 30943 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0D0 equ 0F66h ;# 
# 31012 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0D1 equ 0F67h ;# 
# 31081 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0D2 equ 0F68h ;# 
# 31150 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0D3 equ 0F69h ;# 
# 31219 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0D4 equ 0F6Ah ;# 
# 31288 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0D5 equ 0F6Bh ;# 
# 31357 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0D6 equ 0F6Ch ;# 
# 31426 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RXB0D7 equ 0F6Dh ;# 
# 31495 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANSTAT equ 0F6Eh ;# 
# 31605 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CANCON equ 0F6Fh ;# 
# 31696 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CIOCON equ 0F70h ;# 
# 31740 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
COMSTAT equ 0F71h ;# 
# 31846 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ECANCON equ 0F72h ;# 
# 31922 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
EEDATA equ 0F73h ;# 
# 31941 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
EEADR equ 0F74h ;# 
# 31960 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
EEADRH equ 0F75h ;# 
# 31979 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PIE5 equ 0F76h ;# 
# 32061 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PIR5 equ 0F77h ;# 
# 32143 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
IPR5 equ 0F78h ;# 
# 32260 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXREG2 equ 0F79h ;# 
# 32279 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RCREG2 equ 0F7Ah ;# 
# 32298 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
SPBRG2 equ 0F7Bh ;# 
# 32317 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
SPBRGH2 equ 0F7Ch ;# 
# 32336 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
SPBRGH1 equ 0F7Dh ;# 
# 32355 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
EECON2 equ 0F7Eh ;# 
# 32374 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
EECON1 equ 0F7Fh ;# 
# 32439 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PORTA equ 0F80h ;# 
# 32530 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PORTB equ 0F81h ;# 
# 32600 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PORTC equ 0F82h ;# 
# 32688 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PORTE equ 0F84h ;# 
# 32921 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TMR4 equ 0F87h ;# 
# 32940 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
T4CON equ 0F88h ;# 
# 33010 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
LATA equ 0F89h ;# 
# 33137 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
LATB equ 0F8Ah ;# 
# 33269 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
LATC equ 0F8Bh ;# 
# 33401 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
SLRCON equ 0F90h ;# 
# 33432 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ODCON equ 0F91h ;# 
# 33493 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TRISA equ 0F92h ;# 
# 33549 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TRISB equ 0F93h ;# 
# 33610 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TRISC equ 0F94h ;# 
# 33671 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPTMRS equ 0F99h ;# 
# 33714 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
REFOCON equ 0F9Ah ;# 
# 33778 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
OSCTUNE equ 0F9Bh ;# 
# 33847 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PSTR1CON equ 0F9Ch ;# 
# 33912 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PIE1 equ 0F9Dh ;# 
# 33982 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PIR1 equ 0F9Eh ;# 
# 34052 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
IPR1 equ 0F9Fh ;# 
# 34122 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PIE2 equ 0FA0h ;# 
# 34175 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PIR2 equ 0FA1h ;# 
# 34228 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
IPR2 equ 0FA2h ;# 
# 34281 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PIE3 equ 0FA3h ;# 
# 34379 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PIR3 equ 0FA4h ;# 
# 34441 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
IPR3 equ 0FA5h ;# 
# 34503 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RCSTA2 equ 0FA6h ;# 
# 34640 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
BAUDCON1 equ 0FA7h ;# 
# 34821 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
HLVDCON equ 0FA8h ;# 
# 34890 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PR4 equ 0FA9h ;# 
# 34909 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
T1GCON equ 0FAAh ;# 
# 35012 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RCSTA1 equ 0FABh ;# 
# 35017 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RCSTA equ 0FABh ;# 
# 35349 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXSTA1 equ 0FACh ;# 
# 35354 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXSTA equ 0FACh ;# 
# 35636 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXREG1 equ 0FADh ;# 
# 35641 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXREG equ 0FADh ;# 
# 35673 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RCREG1 equ 0FAEh ;# 
# 35678 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RCREG equ 0FAEh ;# 
# 35710 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
SPBRG1 equ 0FAFh ;# 
# 35715 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
SPBRG equ 0FAFh ;# 
# 35747 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
T3GCON equ 0FB0h ;# 
# 35850 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
T3CON equ 0FB1h ;# 
# 35962 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TMR3 equ 0FB2h ;# 
# 35968 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TMR3L equ 0FB2h ;# 
# 35987 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TMR3H equ 0FB3h ;# 
# 36006 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CMSTAT equ 0FB4h ;# 
# 36011 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CMSTATUS equ 0FB4h ;# 
# 36093 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CVRCON equ 0FB5h ;# 
# 36180 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PIE4 equ 0FB6h ;# 
# 36236 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PIR4 equ 0FB7h ;# 
# 36292 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
IPR4 equ 0FB8h ;# 
# 36356 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
BAUDCON2 equ 0FB9h ;# 
# 36510 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TXSTA2 equ 0FBAh ;# 
# 36638 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCP1CON equ 0FBBh ;# 
# 36643 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ECCP1CON equ 0FBBh ;# 
# 36829 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR1 equ 0FBCh ;# 
# 36835 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR1L equ 0FBCh ;# 
# 36854 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
CCPR1H equ 0FBDh ;# 
# 36873 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ECCP1DEL equ 0FBEh ;# 
# 36878 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PWM1CON equ 0FBEh ;# 
# 37010 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ECCP1AS equ 0FBFh ;# 
# 37091 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ADCON2 equ 0FC0h ;# 
# 37161 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ADCON1 equ 0FC1h ;# 
# 37270 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ADCON0 equ 0FC2h ;# 
# 37394 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ADRES equ 0FC3h ;# 
# 37400 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ADRESL equ 0FC3h ;# 
# 37419 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
ADRESH equ 0FC4h ;# 
# 37438 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
SSPCON2 equ 0FC5h ;# 
# 37532 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
SSPCON1 equ 0FC6h ;# 
# 37601 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
SSPSTAT equ 0FC7h ;# 
# 37843 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
SSPADD equ 0FC8h ;# 
# 37912 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
SSPBUF equ 0FC9h ;# 
# 37931 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
T2CON equ 0FCAh ;# 
# 38001 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PR2 equ 0FCBh ;# 
# 38006 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
MEMCON equ 0FCBh ;# 
# 38126 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TMR2 equ 0FCCh ;# 
# 38145 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
T1CON equ 0FCDh ;# 
# 38248 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TMR1 equ 0FCEh ;# 
# 38254 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TMR1L equ 0FCEh ;# 
# 38273 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TMR1H equ 0FCFh ;# 
# 38292 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
RCON equ 0FD0h ;# 
# 38444 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
WDTCON equ 0FD1h ;# 
# 38503 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
OSCCON2 equ 0FD2h ;# 
# 38574 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
OSCCON equ 0FD3h ;# 
# 38650 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
T0CON equ 0FD5h ;# 
# 38719 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TMR0 equ 0FD6h ;# 
# 38725 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TMR0L equ 0FD6h ;# 
# 38744 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TMR0H equ 0FD7h ;# 
# 38763 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
STATUS equ 0FD8h ;# 
# 38841 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
FSR2 equ 0FD9h ;# 
# 38847 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
FSR2L equ 0FD9h ;# 
# 38866 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
FSR2H equ 0FDAh ;# 
# 38885 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PLUSW2 equ 0FDBh ;# 
# 38904 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PREINC2 equ 0FDCh ;# 
# 38923 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
POSTDEC2 equ 0FDDh ;# 
# 38942 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
POSTINC2 equ 0FDEh ;# 
# 38961 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
INDF2 equ 0FDFh ;# 
# 38980 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
BSR equ 0FE0h ;# 
# 38999 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
FSR1 equ 0FE1h ;# 
# 39005 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
FSR1L equ 0FE1h ;# 
# 39024 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
FSR1H equ 0FE2h ;# 
# 39043 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PLUSW1 equ 0FE3h ;# 
# 39062 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PREINC1 equ 0FE4h ;# 
# 39081 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
POSTDEC1 equ 0FE5h ;# 
# 39100 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
POSTINC1 equ 0FE6h ;# 
# 39119 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
INDF1 equ 0FE7h ;# 
# 39138 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
WREG equ 0FE8h ;# 
# 39157 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
FSR0 equ 0FE9h ;# 
# 39163 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
FSR0L equ 0FE9h ;# 
# 39182 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
FSR0H equ 0FEAh ;# 
# 39201 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PLUSW0 equ 0FEBh ;# 
# 39220 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PREINC0 equ 0FECh ;# 
# 39239 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
POSTDEC0 equ 0FEDh ;# 
# 39258 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
POSTINC0 equ 0FEEh ;# 
# 39277 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
INDF0 equ 0FEFh ;# 
# 39296 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
INTCON3 equ 0FF0h ;# 
# 39407 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
INTCON2 equ 0FF1h ;# 
# 39499 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
INTCON equ 0FF2h ;# 
# 39504 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
INTCON1 equ 0FF2h ;# 
# 39760 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PROD equ 0FF3h ;# 
# 39766 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PRODL equ 0FF3h ;# 
# 39785 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PRODH equ 0FF4h ;# 
# 39804 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TABLAT equ 0FF5h ;# 
# 39825 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TBLPTR equ 0FF6h ;# 
# 39831 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TBLPTRL equ 0FF6h ;# 
# 39850 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TBLPTRH equ 0FF7h ;# 
# 39869 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TBLPTRU equ 0FF8h ;# 
# 39890 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PCLAT equ 0FF9h ;# 
# 39897 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PC equ 0FF9h ;# 
# 39903 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PCL equ 0FF9h ;# 
# 39922 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PCLATH equ 0FFAh ;# 
# 39941 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
PCLATU equ 0FFBh ;# 
# 39960 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
STKPTR equ 0FFCh ;# 
# 40033 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TOS equ 0FFDh ;# 
# 40039 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TOSL equ 0FFDh ;# 
# 40058 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TOSH equ 0FFEh ;# 
# 40077 "/opt/microchip/xc8/v1.30/include/pic18f26k80.h"
TOSU equ 0FFFh ;# 
	FNCALL	_main,_init_port
	FNCALL	_main,_init_timer
	FNCALL	_main,_init_usart
	FNROOT	_main
	FNCALL	intlevel2,_ISRCode
	global	intlevel2
	FNROOT	intlevel2
	global	_i
	global	_timer_ticks
	global	_ADCON1
_ADCON1	set	0xFC1
	global	_BAUDCON1bits
_BAUDCON1bits	set	0xFA7
	global	_CANCON
_CANCON	set	0xF6F
	global	_CANSTATbits
_CANSTATbits	set	0xF6E
	global	_ECANCON
_ECANCON	set	0xF72
	global	_LATAbits
_LATAbits	set	0xF89
	global	_PIR1bits
_PIR1bits	set	0xF9E
	global	_RCSTAbits
_RCSTAbits	set	0xFAB
	global	_RXB0CONbits
_RXB0CONbits	set	0xF60
	global	_RXB0D0
_RXB0D0	set	0xF66
	global	_RXB0D1
_RXB0D1	set	0xF67
	global	_RXB0D2
_RXB0D2	set	0xF68
	global	_RXB0D3
_RXB0D3	set	0xF69
	global	_RXB0D4
_RXB0D4	set	0xF6A
	global	_RXB0D5
_RXB0D5	set	0xF6B
	global	_RXB0D6
_RXB0D6	set	0xF6C
	global	_RXB0D7
_RXB0D7	set	0xF6D
	global	_RXB0DLC
_RXB0DLC	set	0xF65
	global	_RXB0EIDH
_RXB0EIDH	set	0xF63
	global	_RXB0EIDL
_RXB0EIDL	set	0xF64
	global	_RXB0SIDH
_RXB0SIDH	set	0xF61
	global	_RXB0SIDL
_RXB0SIDL	set	0xF62
	global	_SPBRG
_SPBRG	set	0xFAF
	global	_TRISAbits
_TRISAbits	set	0xF92
	global	_TRISCbits
_TRISCbits	set	0xF94
	global	_TXSTAbits
_TXSTAbits	set	0xFAC
	global	_GIE
_GIE	set	0x7F97
	global	_PEIE
_PEIE	set	0x7F96
	global	_PSA
_PSA	set	0x7EAB
	global	_T08BIT
_T08BIT	set	0x7EAE
	global	_T0CS
_T0CS	set	0x7EAD
	global	_T0PS0
_T0PS0	set	0x7EA8
	global	_T0PS1
_T0PS1	set	0x7EA9
	global	_T0PS2
_T0PS2	set	0x7EAA
	global	_TMR0IE
_TMR0IE	set	0x7F95
	global	_TMR0IF
_TMR0IF	set	0x7F92
	global	_TMR0ON
_TMR0ON	set	0x7EAF
psect	intcode,class=CODE,space=0,reloc=2
global __pintcode
__pintcode:
; #config settings
	file	"easycan.as"
	line	#
psect	cinit,class=CODE,delta=1,reloc=2
global __pcinit
__pcinit:
global start_initialization
start_initialization:

global __initialization
__initialization:
psect	bssCOMRAM,class=COMRAM,space=1,noexec
global __pbssCOMRAM
__pbssCOMRAM:
	global	_i
	global	_i
_i:
       ds      2
	global	_timer_ticks
_timer_ticks:
       ds      1
	line	#
psect	cinit
; Clear objects allocated to COMRAM (3 bytes)
	global __pbssCOMRAM
clrf	(__pbssCOMRAM+2)&0xffh,c
clrf	(__pbssCOMRAM+1)&0xffh,c
clrf	(__pbssCOMRAM+0)&0xffh,c
psect cinit,class=CODE,delta=1
global end_of_initialization,__end_of__initialization

;End of C runtime variable initialization code

end_of_initialization:
__end_of__initialization:movlb 0
goto _main	;jump to C main() function
psect	cstackCOMRAM,class=COMRAM,space=1,noexec
global __pcstackCOMRAM
__pcstackCOMRAM:
?_init_usart:	; 0 bytes @ 0x0
?_init_port:	; 0 bytes @ 0x0
?_init_timer:	; 0 bytes @ 0x0
?_ISRCode:	; 0 bytes @ 0x0
??_ISRCode:	; 0 bytes @ 0x0
	ds   14
??_init_usart:	; 0 bytes @ 0xE
??_init_port:	; 0 bytes @ 0xE
??_init_timer:	; 0 bytes @ 0xE
?_main:	; 0 bytes @ 0xE
main@argc:	; 2 bytes @ 0xE
	ds   2
main@argv:	; 3 bytes @ 0x10
	ds   3
??_main:	; 0 bytes @ 0x13
;!
;!Data Sizes:
;!    Strings     0
;!    Constant    0
;!    Data        0
;!    BSS         3
;!    Persistent  0
;!    Stack       0
;!
;!Auto Spaces:
;!    Space          Size  Autos    Used
;!    COMRAM           95     19      22
;!    BANK0           160      0       0
;!    BANK1           256      0       0
;!    BANK2           256      0       0
;!    BANK3           256      0       0
;!    BANK4           256      0       0
;!    BANK5           256      0       0
;!    BANK6           256      0       0
;!    BANK7           256      0       0
;!    BANK8           256      0       0
;!    BANK9           256      0       0
;!    BANK10          256      0       0
;!    BANK11          256      0       0
;!    BANK12          256      0       0
;!    BANK13          256      0       0
;!    BANK14           65      0       0

;!
;!Pointer List with Targets:
;!
;!    None.


;!
;!Critical Paths under _main in COMRAM
;!
;!    None.
;!
;!Critical Paths under _ISRCode in COMRAM
;!
;!    None.
;!
;!Critical Paths under _main in BANK0
;!
;!    None.
;!
;!Critical Paths under _ISRCode in BANK0
;!
;!    None.
;!
;!Critical Paths under _main in BANK1
;!
;!    None.
;!
;!Critical Paths under _ISRCode in BANK1
;!
;!    None.
;!
;!Critical Paths under _main in BANK2
;!
;!    None.
;!
;!Critical Paths under _ISRCode in BANK2
;!
;!    None.
;!
;!Critical Paths under _main in BANK3
;!
;!    None.
;!
;!Critical Paths under _ISRCode in BANK3
;!
;!    None.
;!
;!Critical Paths under _main in BANK4
;!
;!    None.
;!
;!Critical Paths under _ISRCode in BANK4
;!
;!    None.
;!
;!Critical Paths under _main in BANK5
;!
;!    None.
;!
;!Critical Paths under _ISRCode in BANK5
;!
;!    None.
;!
;!Critical Paths under _main in BANK6
;!
;!    None.
;!
;!Critical Paths under _ISRCode in BANK6
;!
;!    None.
;!
;!Critical Paths under _main in BANK7
;!
;!    None.
;!
;!Critical Paths under _ISRCode in BANK7
;!
;!    None.
;!
;!Critical Paths under _main in BANK8
;!
;!    None.
;!
;!Critical Paths under _ISRCode in BANK8
;!
;!    None.
;!
;!Critical Paths under _main in BANK9
;!
;!    None.
;!
;!Critical Paths under _ISRCode in BANK9
;!
;!    None.
;!
;!Critical Paths under _main in BANK10
;!
;!    None.
;!
;!Critical Paths under _ISRCode in BANK10
;!
;!    None.
;!
;!Critical Paths under _main in BANK11
;!
;!    None.
;!
;!Critical Paths under _ISRCode in BANK11
;!
;!    None.
;!
;!Critical Paths under _main in BANK12
;!
;!    None.
;!
;!Critical Paths under _ISRCode in BANK12
;!
;!    None.
;!
;!Critical Paths under _main in BANK13
;!
;!    None.
;!
;!Critical Paths under _ISRCode in BANK13
;!
;!    None.
;!
;!Critical Paths under _main in BANK14
;!
;!    None.
;!
;!Critical Paths under _ISRCode in BANK14
;!
;!    None.

;;
;;Main: autosize = 0, tempsize = 0, incstack = 0, save=0
;;

;!
;!Call Graph Tables:
;!
;! ---------------------------------------------------------------------------------
;! (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;! ---------------------------------------------------------------------------------
;! (0) _main                                                 5     0      5       0
;!                                             14 COMRAM     5     0      5
;!                          _init_port
;!                         _init_timer
;!                         _init_usart
;! ---------------------------------------------------------------------------------
;! (1) _init_usart                                           0     0      0       0
;! ---------------------------------------------------------------------------------
;! (1) _init_timer                                           0     0      0       0
;! ---------------------------------------------------------------------------------
;! (1) _init_port                                            0     0      0       0
;! ---------------------------------------------------------------------------------
;! Estimated maximum stack depth 1
;! ---------------------------------------------------------------------------------
;! (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;! ---------------------------------------------------------------------------------
;! (2) _ISRCode                                             14    14      0       0
;!                                              0 COMRAM    14    14      0
;! ---------------------------------------------------------------------------------
;! Estimated maximum stack depth 2
;! ---------------------------------------------------------------------------------
;!
;! Call Graph Graphs:
;!
;! _main (ROOT)
;!   _init_port
;!   _init_timer
;!   _init_usart
;!
;! _ISRCode (ROOT)
;!

;! Address spaces:

;!Name               Size   Autos  Total    Cost      Usage
;!BIGRAM             E40      0       0      35        0.0%
;!EEDATA             400      0       0       0        0.0%
;!BITBANK13          100      0       0      31        0.0%
;!BANK13             100      0       0      32        0.0%
;!BITBANK12          100      0       0      29        0.0%
;!BANK12             100      0       0      30        0.0%
;!BITBANK11          100      0       0      27        0.0%
;!BANK11             100      0       0      28        0.0%
;!BITBANK10          100      0       0      25        0.0%
;!BANK10             100      0       0      26        0.0%
;!BITBANK9           100      0       0      23        0.0%
;!BANK9              100      0       0      24        0.0%
;!BITBANK8           100      0       0      21        0.0%
;!BANK8              100      0       0      22        0.0%
;!BITBANK7           100      0       0      19        0.0%
;!BANK7              100      0       0      20        0.0%
;!BITBANK6           100      0       0      17        0.0%
;!BANK6              100      0       0      18        0.0%
;!BITBANK5           100      0       0      15        0.0%
;!BANK5              100      0       0      16        0.0%
;!BITBANK4           100      0       0      13        0.0%
;!BANK4              100      0       0      14        0.0%
;!BITBANK3           100      0       0      11        0.0%
;!BANK3              100      0       0      12        0.0%
;!BITBANK2           100      0       0       9        0.0%
;!BANK2              100      0       0      10        0.0%
;!BITBANK1           100      0       0       7        0.0%
;!BANK1              100      0       0       8        0.0%
;!BITBANK0            A0      0       0       4        0.0%
;!BANK0               A0      0       0       5        0.0%
;!BITCOMRAM           5F      0       0       0        0.0%
;!COMRAM              5F     13      16       1       23.2%
;!BITBANK14           41      0       0      33        0.0%
;!BANK14              41      0       0      34        0.0%
;!BITSFR_2             0      0       0      40        0.0%
;!SFR_2                0      0       0      40        0.0%
;!BITSFR_1             0      0       0      40        0.0%
;!SFR_1                0      0       0      40        0.0%
;!BITSFR               0      0       0      40        0.0%
;!SFR                  0      0       0      40        0.0%
;!STACK                0      0       0       2        0.0%
;!NULL                 0      0       0       0        0.0%
;!ABS                  0      0      16       6        0.0%
;!DATA                 0      0      16       3        0.0%
;!CODE                 0      0       0       0        0.0%

	global	_main

;; *************** function _main *****************
;; Defined at:
;;		line 41 in file "easycan.c"
;; Parameters:    Size  Location     Type
;;  argc            2   14[COMRAM] int 
;;  argv            3   16[COMRAM] PTR PTR unsigned char 
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, fsr0l, fsr0h, fsr1l, fsr1h, fsr1l, fsr1h, fsr2l, fsr2h, status,2, status,0, pclat, btemp, btemp+1, btemp+2, btemp+3, btemp+4, btemp+5, btemp+6, btemp+7, btemp+8, btemp+9, btemp+10, btemp+11, tosl, structret, tblptrl, tblptrh, tblptru, prodl, prodh, bsr, cstack
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMRAM   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6   BANK7   BANK8   BANK9  BANK10  BANK11  BANK12  BANK13  BANK14
;;      Params:         5       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0
;;      Locals:         0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0
;;      Totals:         5       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0
;;Total ram usage:        5 bytes
;; Hardware stack levels required when called:    2
;; This function calls:
;;		_init_port
;;		_init_timer
;;		_init_usart
;; This function is called by:
;;		Startup code after reset
;; This function uses a non-reentrant model
;;
psect	text0,class=CODE,space=0,reloc=2
	file	"easycan.c"
	line	41
global __ptext0
__ptext0:
psect	text0
	file	"easycan.c"
	line	41
	global	__size_of_main
	__size_of_main	equ	__end_of_main-_main
	
_main:
;incstack = 0
	opt	stack 29
	line	42
	
l697:
;easycan.c: 42: init_port();
	call	_init_port	;wreg free
	line	43
	
l699:
;easycan.c: 43: init_timer();
	call	_init_timer	;wreg free
	line	44
	
l701:
;easycan.c: 44: init_usart();
	call	_init_usart	;wreg free
	line	47
;easycan.c: 47: while(1) {
	
l43:
	line	48
	
l44:
	line	47
	goto	l43
	
l45:
	line	49
	
l46:
	global	start
	goto	start
	opt stack 0
GLOBAL	__end_of_main
	__end_of_main:
	signat	_main,8312
	global	_init_usart

;; *************** function _init_usart *****************
;; Defined at:
;;		line 13 in file "usart.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMRAM   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6   BANK7   BANK8   BANK9  BANK10  BANK11  BANK12  BANK13  BANK14
;;      Params:         0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0
;;      Locals:         0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0
;;      Totals:         0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text1,class=CODE,space=0,reloc=2
	file	"usart.c"
	line	13
global __ptext1
__ptext1:
psect	text1
	file	"usart.c"
	line	13
	global	__size_of_init_usart
	__size_of_init_usart	equ	__end_of_init_usart-_init_usart
	
_init_usart:
;incstack = 0
	opt	stack 29
	line	15
	
l703:
;usart.c: 15: TXSTAbits.TX9 = 0;
	bcf	((c:4012)),c,6	;volatile
	line	16
;usart.c: 16: TXSTAbits.TXEN = 1;
	bsf	((c:4012)),c,5	;volatile
	line	17
;usart.c: 17: TXSTAbits.SYNC = 0;
	bcf	((c:4012)),c,4	;volatile
	line	18
;usart.c: 18: TXSTAbits.BRGH = 1;
	bsf	((c:4012)),c,2	;volatile
	line	19
;usart.c: 19: RCSTAbits.SPEN = 1;
	bsf	((c:4011)),c,7	;volatile
	line	20
;usart.c: 20: RCSTAbits.RX9 = 0;
	bcf	((c:4011)),c,6	;volatile
	line	21
;usart.c: 21: RCSTAbits.CREN = 1;
	bsf	((c:4011)),c,4	;volatile
	line	22
;usart.c: 22: BAUDCON1bits.BRG16 = 0;
	bcf	((c:4007)),c,3	;volatile
	line	24
	
l705:
;usart.c: 24: SPBRG = ( (((64000000 / 500000) / 8) - 1) / 2 );
	movlw	low(07h)
	movwf	((c:4015)),c	;volatile
	line	26
	
l707:
;usart.c: 26: TRISCbits.TRISC6 = 0;
	bcf	((c:3988)),c,6	;volatile
	line	27
	
l709:
;usart.c: 27: TRISCbits.TRISC7 = 1;
	bsf	((c:3988)),c,7	;volatile
	line	37
	
l711:
;usart.c: 37: PIR1bits.RCIF = 0;
	bcf	((c:3998)),c,5	;volatile
	line	38
	
l115:
	return
	opt stack 0
GLOBAL	__end_of_init_usart
	__end_of_init_usart:
	signat	_init_usart,88
	global	_init_timer

;; *************** function _init_timer *****************
;; Defined at:
;;		line 21 in file "easycan.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		None
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMRAM   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6   BANK7   BANK8   BANK9  BANK10  BANK11  BANK12  BANK13  BANK14
;;      Params:         0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0
;;      Locals:         0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0
;;      Totals:         0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text2,class=CODE,space=0,reloc=2
	file	"easycan.c"
	line	21
global __ptext2
__ptext2:
psect	text2
	file	"easycan.c"
	line	21
	global	__size_of_init_timer
	__size_of_init_timer	equ	__end_of_init_timer-_init_timer
	
_init_timer:
;incstack = 0
	opt	stack 29
	line	25
	
l695:
;easycan.c: 25: T0PS0=1;
	bsf	c:(32424/8),(32424)&7	;volatile
	line	26
;easycan.c: 26: T0PS1=1;
	bsf	c:(32425/8),(32425)&7	;volatile
	line	27
;easycan.c: 27: T0PS2=1;
	bsf	c:(32426/8),(32426)&7	;volatile
	line	29
;easycan.c: 29: PSA=0;
	bcf	c:(32427/8),(32427)&7	;volatile
	line	30
;easycan.c: 30: T0CS=0;
	bcf	c:(32429/8),(32429)&7	;volatile
	line	32
;easycan.c: 32: T08BIT=1;
	bsf	c:(32430/8),(32430)&7	;volatile
	line	34
;easycan.c: 34: TMR0IE=1;
	bsf	c:(32661/8),(32661)&7	;volatile
	line	35
;easycan.c: 35: PEIE=1;
	bsf	c:(32662/8),(32662)&7	;volatile
	line	36
;easycan.c: 36: GIE=1;
	bsf	c:(32663/8),(32663)&7	;volatile
	line	38
;easycan.c: 38: TMR0ON=1;
	bsf	c:(32431/8),(32431)&7	;volatile
	line	39
	
l40:
	return
	opt stack 0
GLOBAL	__end_of_init_timer
	__end_of_init_timer:
	signat	_init_timer,88
	global	_init_port

;; *************** function _init_port *****************
;; Defined at:
;;		line 16 in file "easycan.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMRAM   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6   BANK7   BANK8   BANK9  BANK10  BANK11  BANK12  BANK13  BANK14
;;      Params:         0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0
;;      Locals:         0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0
;;      Totals:         0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text3,class=CODE,space=0,reloc=2
	line	16
global __ptext3
__ptext3:
psect	text3
	file	"easycan.c"
	line	16
	global	__size_of_init_port
	__size_of_init_port	equ	__end_of_init_port-_init_port
	
_init_port:
;incstack = 0
	opt	stack 29
	line	17
	
l691:
;easycan.c: 17: ADCON1 = 0x0F;
	movlw	low(0Fh)
	movwf	((c:4033)),c	;volatile
	line	18
	
l693:
;easycan.c: 18: (TRISAbits.TRISA0) = 0;
	bcf	((c:3986)),c,0	;volatile
	line	19
	
l37:
	return
	opt stack 0
GLOBAL	__end_of_init_port
	__end_of_init_port:
	signat	_init_port,88
	global	_ISRCode

;; *************** function _ISRCode *****************
;; Defined at:
;;		line 51 in file "easycan.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMRAM   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6   BANK7   BANK8   BANK9  BANK10  BANK11  BANK12  BANK13  BANK14
;;      Params:         0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0
;;      Locals:         0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0
;;      Temps:         14       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0
;;      Totals:        14       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0
;;Total ram usage:       14 bytes
;; Hardware stack levels used:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		Interrupt level 2
;; This function uses a non-reentrant model
;;
psect	intcode
psect	intcode
	file	"easycan.c"
	line	51
	global	__size_of_ISRCode
	__size_of_ISRCode	equ	__end_of_ISRCode-_ISRCode
	
_ISRCode:
;incstack = 0
	opt	stack 29
	movff	pclat+0,??_ISRCode+0
	movff	pclat+1,??_ISRCode+1
	movff	fsr0l+0,??_ISRCode+2
	movff	fsr0h+0,??_ISRCode+3
	movff	fsr1l+0,??_ISRCode+4
	movff	fsr1h+0,??_ISRCode+5
	movff	fsr2l+0,??_ISRCode+6
	movff	fsr2h+0,??_ISRCode+7
	movff	prodl+0,??_ISRCode+8
	movff	prodh+0,??_ISRCode+9
	movff	tblptrl+0,??_ISRCode+10
	movff	tblptrh+0,??_ISRCode+11
	movff	tblptru+0,??_ISRCode+12
	movff	tablat+0,??_ISRCode+13
	line	52
	
i2l713:
;easycan.c: 52: if (TMR0IE && TMR0IF) {
	btfss	c:(32661/8),(32661)&7	;volatile
	goto	i2u1_41
	goto	i2u1_40
i2u1_41:
	goto	i2l54
i2u1_40:
	
i2l715:
	btfss	c:(32658/8),(32658)&7	;volatile
	goto	i2u2_41
	goto	i2u2_40
i2u2_41:
	goto	i2l54
i2u2_40:
	line	54
	
i2l717:
;easycan.c: 54: timer_ticks++;
	incf	((c:_timer_ticks)),c	;volatile
	line	56
	
i2l719:
;easycan.c: 56: if (timer_ticks==20) {
	movf	((c:_timer_ticks)),c,w	;volatile
	xorlw	20

	btfss	status,2
	goto	i2u3_41
	goto	i2u3_40
i2u3_41:
	goto	i2l723
i2u3_40:
	line	57
	
i2l721:
;easycan.c: 57: (LATAbits.LATA0) = 0;
	bcf	((c:3977)),c,0	;volatile
	goto	i2l723
	line	58
	
i2l50:
	line	60
	
i2l723:
;easycan.c: 58: }
;easycan.c: 60: if (timer_ticks==40) {
	movf	((c:_timer_ticks)),c,w	;volatile
	xorlw	40

	btfss	status,2
	goto	i2u4_41
	goto	i2u4_40
i2u4_41:
	goto	i2l727
i2u4_40:
	line	61
	
i2l725:
;easycan.c: 61: (LATAbits.LATA0) = 1;
	bsf	((c:3977)),c,0	;volatile
	goto	i2l727
	line	62
	
i2l51:
	line	64
	
i2l727:
;easycan.c: 62: }
;easycan.c: 64: if (timer_ticks==60) {
	movf	((c:_timer_ticks)),c,w	;volatile
	xorlw	60

	btfss	status,2
	goto	i2u5_41
	goto	i2u5_40
i2u5_41:
	goto	i2l731
i2u5_40:
	line	65
	
i2l729:
;easycan.c: 65: (LATAbits.LATA0) = 0;
	bcf	((c:3977)),c,0	;volatile
	goto	i2l731
	line	66
	
i2l52:
	line	68
	
i2l731:
;easycan.c: 66: }
;easycan.c: 68: if (timer_ticks==250) {
	movf	((c:_timer_ticks)),c,w	;volatile
	xorlw	250

	btfss	status,2
	goto	i2u6_41
	goto	i2u6_40
i2u6_41:
	goto	i2l737
i2u6_40:
	line	69
	
i2l733:
;easycan.c: 69: (LATAbits.LATA0) = 1;
	bsf	((c:3977)),c,0	;volatile
	line	70
	
i2l735:
;easycan.c: 70: timer_ticks=0;
	movlw	low(0)
	movwf	((c:_timer_ticks)),c	;volatile
	goto	i2l737
	line	71
	
i2l53:
	line	72
	
i2l737:
;easycan.c: 71: }
;easycan.c: 72: TMR0IF = 0;
	bcf	c:(32658/8),(32658)&7	;volatile
	goto	i2l54
	line	73
	
i2l49:
	line	74
	
i2l54:
	movff	??_ISRCode+13,tablat+0
	movff	??_ISRCode+12,tblptru+0
	movff	??_ISRCode+11,tblptrh+0
	movff	??_ISRCode+10,tblptrl+0
	movff	??_ISRCode+9,prodh+0
	movff	??_ISRCode+8,prodl+0
	movff	??_ISRCode+7,fsr2h+0
	movff	??_ISRCode+6,fsr2l+0
	movff	??_ISRCode+5,fsr1h+0
	movff	??_ISRCode+4,fsr1l+0
	movff	??_ISRCode+3,fsr0h+0
	movff	??_ISRCode+2,fsr0l+0
	movff	??_ISRCode+1,pclat+1
	movff	??_ISRCode+0,pclat+0
	retfie f
	opt stack 0
GLOBAL	__end_of_ISRCode
	__end_of_ISRCode:
	signat	_ISRCode,88
	GLOBAL	__activetblptr
__activetblptr	EQU	0
	psect	intsave_regs,class=BIGRAM,space=1,noexec
	PSECT	rparam,class=COMRAM,space=1,noexec
	GLOBAL	__Lrparam
	FNCONF	rparam,??,?
GLOBAL	__Lparam, __Hparam
GLOBAL	__Lrparam, __Hrparam
__Lparam	EQU	__Lrparam
__Hparam	EQU	__Hrparam
	end
