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

build:
	cd fw && $(MAKE) build
	cd test && $(MAKE) build

install:build
	cd fw && $(MAKE) install
	cd test && $(MAKE) install

clean:
	cd fw && $(MAKE) clean
	cd test && $(MAKE) clean
	rm -f *~

uninstall:clean
	cd fw && $(MAKE) uninstall
	cd test && $(MAKE) uninstall
