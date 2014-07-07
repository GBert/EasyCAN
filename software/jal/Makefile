SYSTEM:=$(shell uname -s)

JAL	= jal
JALFLGS	= -long-start 

OBJECT	= ser1

BOOTLOADER      = pirate-loader
TERMINAL        = com

TARGET		= ser1.hex

build:$(TARGET)

$(TARGET):$(OBJECT)
        $(JAL) $(JALFLAGS) $(OBJECT)

install:build

uninstall:clean

clean:
	find . -regextype posix-extended -regex ".*\.(o|asm|cod|err|hex|log|lst)" -delete

flash:
	$(BOOTLOADER) --reset_rts --dev=/dev/ttyUSB0 --hex=$(MAIN).hex

terminal:
	$(TERMINAL) /dev/ttyUSB0 500000
