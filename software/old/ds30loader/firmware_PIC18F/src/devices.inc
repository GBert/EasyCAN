;------------------------------------------------------------------------------
;
; Title:			ds30 Loader for PIC18F
;
; File description:	device specific constants
;
; Copyright: 		Copyright © 10-11, Mikael Gustafsson
;                                                                             
;------------------------------------------------------------------------------

;-----------------------------------------------------------------------------
;    This file is part of ds30 Loader.
;
;    ds30 Loader is free software: you can redistribute it and/or modify
;    it under the terms of the GNU General Public License as published by
;    the Free Software Foundation.
;
;    ds30 Loader is distributed in the hope that it will be useful,
;    but WITHOUT ANY WARRANTY; without even the implied warranty of
;    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;    GNU General Public License for more details.
;
;    You should have received a copy of the GNU General Public License
;    along with ds30 Loader. If not, see <http:;www.gnu.org/licenses/>.
;------------------------------------------------------------------------------ 
		
		
		radix DEC
		
;------------------------------------------------------------------------------
; Includes
;------------------------------------------------------------------------------ 		
		#include	"devices_PIC18F.inc"
		#include	"devices_PIC18FJ.inc"
		
						
;------------------------------------------------------------------------------
; 
;------------------------------------------------------------------------------ 		
		ifndef VALID_DEV
			error "Unknown device specified"
		endif
