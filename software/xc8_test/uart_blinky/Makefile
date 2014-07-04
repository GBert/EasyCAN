# ----------------------------------------------------------------------------
# "THE BEER-WARE LICENSE" (Revision 42):
# <info@gerhard-bertelsmann.de> wrote this file. As long as you retain this
# notice you can do whatever you want with this stuff. If we meet some day,
# and you think this stuff is worth it, you can buy me a beer in return
# Gerhard Bertelsmann
# ----------------------------------------------------------------------------

PROJ_DIR	= .
XC8DIR		= /opt/microchip/xc8/v1.30
# XC8DIR		= /Applications/microchip/xc8/v1.30
CC_INCLUDE	= -I$(XC8DIR)/include

PROCESSOR	= 18F26K80
MAIN		= main
SRC		= main.c usart.c
CC_FLAGS	= -P -N255 --warn=0 --addrqual=ignore --mode=free# --echo
OPTIMISATION	= --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --runtime=+plib
CC		= $(XC8DIR)/bin/xc8
DEFINES		= -DBAUDRATE=500000
BOOTLOADER	= pirate-loader
TERMINAL	= com
# CC		= sdcc

all: $(MAIN).hex

$(MAIN).hex: $(SRC)
	$(CC) $(SRC) $(CC_FLAGS) $(OPTIMISATION) $(DEFINES) --ROM=default,-fc00-ffff --chip=$(PROCESSOR) $(CC_INCLUDE) --ASMLIST -M

flash: 
	$(BOOTLOADER) --reset_rts --dev=/dev/ttyUSB0 --hex=$(MAIN).hex

terminal:
	$(TERMINAL) /dev/ttyUSB0 500000	

clean:
	rm -f $(MAIN).hex funclist $(MAIN).cof $(MAIN).hxl *.p1 $(MAIN).sdb startup.* *.cmf *.rlf *.map *.as *.d *.obj *.lst *.pre $(MAIN).sym

