#------------------------------------------------------------------------------
#
# Title:	Take it Easy Loader for The Wellington Boot Loader for PIC18
#
# Copyright:	Copyright (c) 2014 The Duke of Welling Town
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

SYSTEM:=$(shell uname -s)

CC=gcc
CFLAGS=-Os -std=gnu99 -pedantic-errors -Wall -DOS=$(SYSTEM)

CTARGET=easy-loader
CSOURCE=easy-loader.c
COBJECT=$(CSOURCE:.c=.o)

build:$(COBJECT) $(CTARGET)

$(CTARGET):$(COBJECT)

$(COBJECT):$(CHEADER) Makefile

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

install:build
	mkdir -p /usr/local/bin/
	cp $(CTARGET) /usr/local/bin/

uninstall:clean

clean:
	rm -f *.o *~ $(CTARGET)
