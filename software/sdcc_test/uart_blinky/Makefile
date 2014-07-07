SYSTEM:=$(shell uname -s)

MCU=18f26k80
CC=sdcc
CFLAGS=--use-non-free --use-crt=crt0.o --pstack-model=small -mpic16 -p$(MCU) #-DDEBUG=1
CLIB=-llibc18f.lib

MAIN=main
TARGET=main.hex
SOURCE=main.c usart.c
OBJECT=$(SOURCE:.c=.o)
HEADER=$(SOURCE:.c=.h) prototypes.h

BOOTLOADER	= pirate-loader
TERMINAL	= com

build:$(TARGET)

$(TARGET):$(OBJECT)
	@echo -n "[LINK] "
	$(CC) $(CFLAGS) $(OBJECT) -o $(TARGET) $(CLIB) -m$(MCU)

$(OBJECT):$(HEADER) Makefile

install:build

uninstall:clean

clean:
#	find -E . -regex ".*\.(o|asm|cod|err|hex|log|lst)" -delete
	find . -regextype posix-extended -regex ".*\.(o|asm|cod|err|hex|log|lst)" -delete
%.o:%.c
	@echo -n "[CC]   "
	$(CC) $(CFLAGS) -c $< -o $@

flash:
	$(BOOTLOADER) --reset_rts --dev=/dev/ttyUSB0 --hex=$(MAIN).hex

terminal:
	$(TERMINAL) /dev/ttyUSB0 500000
