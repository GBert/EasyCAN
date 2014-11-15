SYSTEM:=$(shell uname -s)

MCU=18f26k80
CC=sdcc
CFLAGS=--obanksel=9 --use-non-free --use-crt=crt0iz.o --pstack-model=small -mpic16 -p$(MCU) #-DDEBUG=1
CLIB=-llibc18f.lib

MAIN=main
TARGET=main.hex
SOURCE=main.c timer.c usart.c can.c slcan.c
OBJECT=$(SOURCE:.c=.o)
HEADER=$(SOURCE:.c=.h) prototypes.h

BOOTLOADER	= easy-loader
TERMINAL	= com

build:$(TARGET)

$(TARGET):$(OBJECT)
	@echo -n "[LINK] "
	$(CC) $(CFLAGS) $(OBJECT) -o $(TARGET) $(CLIB) -m$(MCU)

$(OBJECT):$(HEADER) Makefile

install:build

uninstall:clean

clean:
ifneq (,$(findstring Linux,$(SYSTEM)))
	find . -regextype posix-extended -regex ".*\.(o|asm|cod|err|hex|log|lst)" -delete
else
	find -E . -regex ".*\.(o|asm|cod|err|hex|log|lst)" -delete
endif

%.o:%.c
	@echo -n "[CC]   "
	$(CC) $(CFLAGS) -c $< -o $@

flash:
	$(BOOTLOADER) -r /dev/ttyUSB0 $(MAIN).hex

verify:
	$(BOOTLOADER) -r /dev/ttyUSB0 -v $(MAIN).hex

com:
	$(TERMINAL) /dev/ttyUSB0 500000

terminal:
	$(TERMINAL) /dev/ttyUSB0 500000
