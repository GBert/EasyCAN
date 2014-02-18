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
	ifdef	__18F24J10
		#include	P18F24J10.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x4000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	1024
		#define	DEVICEID	360
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F24J11
		#include	P18F24J11.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x4000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3800
		#define	DEVICEID	361
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
		#define	HAS_PPS	1
	endif
	ifdef	__18F24J50
		#include	P18F24J50.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x4000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3800
		#define	DEVICEID	362
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
		#define	HAS_PPS	1
	endif
	ifdef	__18F25J10
		#include	P18F25J10.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x8000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	1024
		#define	DEVICEID	370
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F25J11
		#include	P18F25J11.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x8000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3800
		#define	DEVICEID	371
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
		#define	HAS_PPS	1
	endif
	ifdef	__18F25J50
		#include	P18F25J50.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x8000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3800
		#define	DEVICEID	372
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
		#define	HAS_PPS	1
	endif
	ifdef	__18F26J11
		#include	P18F26J11.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x10000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3800
		#define	DEVICEID	386
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
		#define	HAS_PPS	1
	endif
	ifdef	__18F26J13
		#include	P18F26J13.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x10000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3800
		#define	DEVICEID	425
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
		#define	HAS_PPS	1
	endif
	ifdef	__18F26J50
		#include	P18F26J50.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x10000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3800
		#define	DEVICEID	387
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
		#define	HAS_PPS	1
	endif
	ifdef	__18F26J53
		#include	P18F26J53.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x10000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3800
		#define	DEVICEID	432
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
		#define	HAS_PPS	1
	endif
	ifdef	__18F27J13
		#include	P18F27J13.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x20000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3800
		#define	DEVICEID	426
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
		#define	HAS_PPS	1
	endif
	ifdef	__18F27J53
		#include	P18F27J53.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x20000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3800
		#define	DEVICEID	431
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
		#define	HAS_PPS	1
	endif
	ifdef	__18F44J10
		#include	P18F44J10.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x4000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	1024
		#define	DEVICEID	363
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F44J11
		#include	P18F44J11.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x4000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3800
		#define	DEVICEID	364
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
		#define	HAS_PPS	1
	endif
	ifdef	__18F44J50
		#include	P18F44J50.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x4000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3800
		#define	DEVICEID	365
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
		#define	HAS_PPS	1
	endif
	ifdef	__18F45J10
		#include	P18F45J10.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x8000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	1024
		#define	DEVICEID	373
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F45J11
		#include	P18F45J11.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x8000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3800
		#define	DEVICEID	374
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
		#define	HAS_PPS	1
	endif
	ifdef	__18F45J50
		#include	P18F45J50.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x8000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3800
		#define	DEVICEID	375
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F46J11
		#include	P18F46J11.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x10000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3800
		#define	DEVICEID	388
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
		#define	HAS_PPS	1
	endif
	ifdef	__18F46J13
		#include	P18F46J13.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x10000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3800
		#define	DEVICEID	427
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F46J50
		#include	P18F46J50.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x10000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3800
		#define	DEVICEID	389
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
		#define	HAS_PPS	1
	endif
	ifdef	__18F46J53
		#include	P18F46J53.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x10000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3800
		#define	DEVICEID	430
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
		#define	HAS_PPS	1
	endif
	ifdef	__18F47J13
		#include	P18F47J13.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x20000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3800
		#define	DEVICEID	428
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
		#define	HAS_PPS	1
	endif
	ifdef	__18F47J53
		#include	P18F47J53.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x20000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3800
		#define	DEVICEID	429
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
		#define	HAS_PPS	1
	endif
	ifdef	__18F63J11
		#include	P18F63J11.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x2000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	1024
		#define	DEVICEID	356
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F63J90
		#include	P18F63J90.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x2000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	1024
		#define	DEVICEID	357
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F64J11
		#include	P18F64J11.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x4000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	1024
		#define	DEVICEID	366
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F64J90
		#include	P18F64J90.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x4000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	1024
		#define	DEVICEID	367
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F65J10
		#include	P18F65J10.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x8000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	2048
		#define	DEVICEID	376
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F65J11
		#include	P18F65J11.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x8000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	2048
		#define	DEVICEID	377
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F65J15
		#include	P18F65J15.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0xC000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	2048
		#define	DEVICEID	384
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F65J50
		#include	P18F65J50.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x8000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3904
		#define	DEVICEID	378
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F65J90
		#include	P18F65J90.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x8000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	2048
		#define	DEVICEID	379
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F66J10
		#include	P18F66J10.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x10000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	2048
		#define	DEVICEID	390
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F66J11
		#include	P18F66J11.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x10000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3904
		#define	DEVICEID	391
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F66J15
		#include	P18F66J15.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x18000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3936
		#define	DEVICEID	403
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F66J16
		#include	P18F66J16.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x18000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3904
		#define	DEVICEID	404
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F66J50
		#include	P18F66J50.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x10000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3904
		#define	DEVICEID	392
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F66J55
		#include	P18F66J55.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x18000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3904
		#define	DEVICEID	405
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F66J60
		#include	P18F66J60.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x10000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3808
		#define	DEVICEID	393
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F66J65
		#include	P18F66J65.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x18000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3808
		#define	DEVICEID	406
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F66J90
		#include	P18F66J90.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x10000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3900
		#define	DEVICEID	394
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F66J93
		#include	P18F66J93.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x10000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3900
		#define	DEVICEID	395
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F67J10
		#include	P18F67J10.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x20000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3936
		#define	DEVICEID	412
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F67J11
		#include	P18F67J11.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x20000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3904
		#define	DEVICEID	413
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F67J50
		#include	P18F67J50.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x20000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3904
		#define	DEVICEID	414
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F67J60
		#include	P18F67J60.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x20000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3808
		#define	DEVICEID	415
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F67J90
		#include	P18F67J90.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x20000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3900
		#define	DEVICEID	416
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F67J93
		#include	P18F67J93.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x20000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3900
		#define	DEVICEID	417
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F83J11
		#include	P18F83J11.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x2000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	1024
		#define	DEVICEID	358
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F83J90
		#include	P18F83J90.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x2000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	1024
		#define	DEVICEID	359
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F84J11
		#include	P18F84J11.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x4000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	1024
		#define	DEVICEID	368
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F84J90
		#include	P18F84J90.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x4000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	1024
		#define	DEVICEID	369
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F85J10
		#include	P18F85J10.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x8000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	2048
		#define	DEVICEID	380
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F85J11
		#include	P18F85J11.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x8000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	2048
		#define	DEVICEID	381
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F85J15
		#include	P18F85J15.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0xC000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	2048
		#define	DEVICEID	385
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F85J50
		#include	P18F85J50.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x8000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3904
		#define	DEVICEID	382
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F85J90
		#include	P18F85J90.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x8000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	2048
		#define	DEVICEID	383
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F86J10
		#include	P18F86J10.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x10000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	2048
		#define	DEVICEID	396
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F86J11
		#include	P18F86J11.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x10000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3904
		#define	DEVICEID	397
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F86J15
		#include	P18F86J15.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x18000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3936
		#define	DEVICEID	407
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F86J16
		#include	P18F86J16.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x18000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3904
		#define	DEVICEID	408
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F86J50
		#include	P18F86J50.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x10000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3904
		#define	DEVICEID	398
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F86J55
		#include	P18F86J55.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x18000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3904
		#define	DEVICEID	409
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F86J60
		#include	P18F86J60.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x10000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3808
		#define	DEVICEID	399
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F86J65
		#include	P18F86J65.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x18000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3808
		#define	DEVICEID	410
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F86J90
		#include	P18F86J90.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x10000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3900
		#define	DEVICEID	400
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F86J93
		#include	P18F86J93.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x10000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3900
		#define	DEVICEID	401
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F87J10
		#include	P18F87J10.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x20000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3936
		#define	DEVICEID	418
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F87J11
		#include	P18F87J11.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x20000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3904
		#define	DEVICEID	419
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F87J50
		#include	P18F87J50.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x20000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3904
		#define	DEVICEID	420
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F87J60
		#include	P18F87J60.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x20000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3808
		#define	DEVICEID	421
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F87J90
		#include	P18F87J90.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x20000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3900
		#define	DEVICEID	422
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F87J93
		#include	P18F87J93.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x20000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3900
		#define	DEVICEID	423
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F96J60
		#include	P18F96J60.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x10000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3808
		#define	DEVICEID	402
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F96J65
		#include	P18F96J65.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x18000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3808
		#define	DEVICEID	411
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
	ifdef	__18F97J60
		#include	P18F97J60.inc
		#define	IS_PIC18FJ	1
		#define	VALID_DEV	1
		#define	MAX_FLASH	0x20000
		#define	RAM_START	0x0
		#define	RAM_SIZEB	3808
		#define	DEVICEID	424
		#define	HAS_UART2	1
		#define	PAGESIZEW	512
		#define	ROWSIZEW	32
	endif
