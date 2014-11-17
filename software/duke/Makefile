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

BOOTLOADER      = easy-loader
TERMINAL        = com

build:
	$(MAKE) -f gpasm.mk build
	$(MAKE) -f easy-can.mk build

install:build
	$(MAKE) -f gpasm.mk install
	$(MAKE) -f easy-can.mk install

uninstall:
	$(MAKE) -f gpasm.mk uninstall
	$(MAKE) -f easy-can.mk uninstall

clean:
	$(MAKE) -f gpasm.mk clean
	$(MAKE) -f easy-can.mk clean

flash:
	$(BOOTLOADER) -r /dev/ttyUSB0 $(MAIN).hex

verify:
	$(BOOTLOADER) -r /dev/ttyUSB0 -v $(MAIN).hex

com:
	$(TERMINAL) /dev/ttyUSB0 500000

trial:
	$(BOOTLOADER) -r /dev/ttyUSB0 -q $(MAIN).hex
	$(TERMINAL) /dev/ttyUSB0 500000
