#ifndef _TIMER_H_
#define _TIMER_H_

#include "HardwareProfile.h"

#define TMR_PRELOAD 65379

extern void TMRInit(void);
extern void TMRServeInt(void);
extern void TMRDelayMs(DWORD milliseconds);
extern DWORD TMRGetTicksCount(void);
extern DWORD TMRTicksElapsed(DWORD start);
extern DWORD TMRGetSecondsCount(void);
extern DWORD TMRSecondsElapsed(DWORD start);

#endif
