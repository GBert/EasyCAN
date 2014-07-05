SYSTEM:=$(shell uname -s)

MCU=18f26k80
CC=sdcc
CFLAGS=--use-non-free --fomit-frame-pointer --pstack-model=small -mpic16 -p$(MCU) #-DDEBUG=1
CLIB=-llibc18f.lib

TARGET=main.hex
SOURCE=main.c usart.c
OBJECT=$(SOURCE:.c=.o)
HEADER=$(SOURCE:.c=.h) prototypes.h

BOOTLOADER	= pirate-loader
TERMINAL	= com

build:$(TARGET)

$(TARGET):$(OBJECT)
	@echo "[LINK] \c"
	$(CC) $(CFLAGS) $(OBJECT) -o $(TARGET) $(CLIB) -m$(MCU)

$(OBJECT):$(HEADER) Makefile

install:build

uninstall:clean

clean:
	find -E . -regex ".*\.(o|asm|cod|err|hex|log|lst)" -delete
	
%.o:%.c
	@echo "[CC]   \c"
	$(CC) $(CFLAGS) -c $< -o $@

flash:
	$(BOOTLOADER) --reset_rts --dev=/dev/ttyUSB0 --hex=$(MAIN).hex

terminal:
	$(TERMINAL) /dev/ttyUSB0 500000
