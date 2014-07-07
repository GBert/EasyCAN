MAIN		= ser1
SOURCE		= $(MAIN).jal

SYSTEM:=$(shell uname -s)

JAL		= jalv2
JALFLAGS	= -long-start

BOOTLOADER      = pirate-loader
TERMINAL        = com

TARGET		= $(MAIN).hex

build:$(TARGET)

$(TARGET):$(OBJECT)
	$(JAL) $(JALFLAGS) $(SOURCE)

install:build

uninstall:clean

clean:
ifneq (,$(findstring Linux,$(SYSTEM)))
	find . -regextype posix-extended -regex ".*\.(o|asm|cod|err|hex|log|lst)" -delete
else
	find -E . -regex ".*\.(o|asm|cod|err|hex|log|lst)" -delete
endif


flash:
	$(BOOTLOADER) --reset_rts --dev=/dev/ttyUSB0 --hex=$(MAIN).hex

terminal:

com:
	$(TERMINAL) /dev/ttyUSB0 500000
