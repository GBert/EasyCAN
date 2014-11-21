#------------------------------------------------------------------------------
#
# Title:	Can-can
#
# Copyright:	Copyright (c) 2014 Darron M Broad
#
#------------------------------------------------------------------------------

#------------------------------------------------------------------------------
#   This file is part of Can-can.
#
#   Can-can is free software: you can redistribute it and/or
#   modify it under the terms of the GNU General Public License as published
#   by the Free Software Foundation.
#
#   Can-can is distributed in the hope that it will be
#   useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
#   GNU General Public License for more details.
#
#   You should have received a copy of the GNU General Public License along
#   with Can-can. If not, see http://www.gnu.org/licenses/
#------------------------------------------------------------------------------

GPASM:=$(shell gpasm -l 2>/dev/null)
ifeq ($(strip $(GPASM)),)
$(error gputils unavailable)
endif

WELLINGTON:=../../wellington/include

AS:=gpasm -a inhx32 -e on -I $(WELLINGTON)

ASOURCE:=can-can.asm
AHEADER:=
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
