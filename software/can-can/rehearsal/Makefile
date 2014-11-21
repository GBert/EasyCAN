#------------------------------------------------------------------------------
#
# Title:	Do the Can-can Rehearsal
#
# Copyright:    Copyright (c) 2014 Darron M Broad
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

BINDIR=/usr/local/bin
BINFILE=can-can

CC=gcc
CFLAGS=-Os -std=gnu99 -pedantic-errors -Wall -ggdb
CLIB=-lm

CSOURCE=can-can.c
COBJECT=can-can.o
CTARGET=can-can

build:$(COBJECT) $(CTARGET)

$(CTARGET):$(COBJECT)
	$(CC) $(COBJECT) -o $(CTARGET) $(CLIB)

$(COBJECT):$(CHEADER) Makefile

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

install:build
	mkdir -p $(BINDIR)
	cp $(CTARGET) $(BINDIR)/$(BINFILE)

uninstall:clean

clean:
	rm -f *.o *~ $(CTARGET)
