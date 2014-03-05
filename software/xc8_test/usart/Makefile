PROJ_DIR	= .
XC8DIR		= /opt/microchip/xc8/v1.30
CC_INCLUDE	= -I$(XC8DIR)/include

PROCESSOR	= 18F26K80
MAIN		= main
SRC		= main.c FIFO.c UART.c HardwareProfile.c Timer.c
CC		= $(XC8DIR)/bin/xc8
BOOTLOADER	= mphidflash

all: $(MAIN).hex

$(MAIN).hex: $(SRC)
	$(CC) $(SRC) --chip=$(PROCESSOR) $(CC_INCLUDE) # --CODEOFFSET=1000h --ROM=default,-0-fff

flash: 
	$(BOOTLOADER) -write main.hex -reset

clean:
	rm -f $(MAIN).hex funclist $(MAIN).cof $(MAIN).hxl *.p1 $(MAIN).sdb startup.* *.as *.d *.obj *.lst *.pre $(MAIN).sym

