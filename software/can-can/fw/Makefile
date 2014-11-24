#------------------------------------------------------------------------------
#
# Can-Can Makefile
#
# Copyright (c) 2014 Darron M Broad
#
#------------------------------------------------------------------------------
#
# This file is part of the Can-Can CAN bus interface project.
#
# Can-Can is licensed under the CC BY-NC-SA 4.0.
#
# See file /LICENSE for details.
# 
#------------------------------------------------------------------------------

GPASM:=$(shell gpasm -l 2>/dev/null)
ifeq ($(strip $(GPASM)),)
$(error gputils unavailable)
endif

WELLINGTON:=../../wellington/include

AS:=gpasm -a inhx32 -e on -I $(WELLINGTON)

ASOURCE:=firmware.asm
AHEADER:=ascii.inc can.inc ring.inc timer.inc uart.inc
AOBJECT:=$(ASOURCE:.asm=.hex)

build:$(AOBJECT)

$(AOBJECT):$(AHEADER) Makefile

%.hex:%.asm
	@echo -n "[AS] "
	$(AS) $< -o $@

upload:build
#	easy-loader -v /dev/ttyPL2303 $(AOBJECT)
	easy-loader -r -v /dev/ttyUSB0 $(AOBJECT)

install:build

uninstall:clean

clean:
	rm -f *.lst *.hex *.cod *.log *.o *~
