#------------------------------------------------------------------------------
#
# Title:        Can-can
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

build:
	cd rehearsal && $(MAKE) build
	cd stage && $(MAKE) build

install:build
	cd rehearsal && $(MAKE) install
	cd stage && $(MAKE) install

clean:
	cd rehearsal && $(MAKE) clean
	cd stage && $(MAKE) clean
	rm -f *~

uninstall:clean
	cd rehearsal && $(MAKE) uninstall
	cd stage && $(MAKE) uninstall
