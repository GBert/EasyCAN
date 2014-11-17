#------------------------------------------------------------------------------
#
# Title:        The Wellington Boot Loader for PIC18
#
# Copyright:    Copyright (c) 2014 The Duke of Welling Town
#
#------------------------------------------------------------------------------

#------------------------------------------------------------------------------
#   This file is part of The Wellington Boot Loader.
#
#   The Wellington Boot Loader is free software: you can redistribute it and/or
#   modify it under the terms of the GNU General Public License as published
#   by the Free Software Foundation.
#
#   The Wellington Boot Loader is distributed in the hope that it will be
#   useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
#   GNU General Public License for more details.
#
#   You should have received a copy of the GNU General Public License along
#   with The Wellington Boot Loader. If not, see http://www.gnu.org/licenses/
#------------------------------------------------------------------------------

AS=gpasm
CC=sdcc

CFLAGS=--disable-warning 85 --Werror
CFLAGS+=--use-non-free --fomit-frame-pointer --pstack-model=small --std-sdcc99 -mpic16 -p18f26k80
CLIB=-llibc18f.lib

TARGET = easy-can.hex

CSOURCE = easy-can.c
ASOURCE = $(CSOURCE:.c=.asm)
CHEADER = $(CSOURCE:.c=.h)
COBJECT = $(CSOURCE:.c=.o)
LSCRIPT = $(CSOURCE:.c=.lkr)

build:$(TARGET)

$(TARGET):$(ASOURCE) $(COBJECT)
	@echo -n "[LINK] "
	$(CC) $(CFLAGS) $(COBJECT) -Wl,-s$(LSCRIPT) -o $(TARGET) $(CLIB)

$(ASOURCE):$(CHEADER) $(LSCRIPT) easy-can.mk

install:build

uninstall:clean

upload:build
	easy-loader -q /dev/ttyS0 $(TARGET)

clean:
	rm -f $(ASOURCE) $(COBJECT) $(TARGET) *.lst *.cod

%.asm:%.c
	@echo -n "[CC] "
	$(CC) -S $(CFLAGS) -c $< -o $@

%.o:%.asm
	@echo -n "[AS] "
	$(AS) -c $< -o $@
