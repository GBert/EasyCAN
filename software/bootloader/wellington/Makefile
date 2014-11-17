#------------------------------------------------------------------------------
#
# Title:	The Wellington Boot Loader for PIC18
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

build:
	cd demo && $(MAKE) build
	cd loader && $(MAKE) build
	cd boot && $(MAKE) build

install:build
	cd demo && $(MAKE) install
	cd loader && $(MAKE) install
	cd boot && $(MAKE) install

clean:
	cd demo && $(MAKE) clean
	cd loader && $(MAKE) clean
	cd boot && $(MAKE) clean
	find . -name "*~" -exec rm {} \;

uninstall:clean
	cd demo && $(MAKE) uninstall
	cd loader && $(MAKE) uninstall
	cd boot && $(MAKE) uninstall
