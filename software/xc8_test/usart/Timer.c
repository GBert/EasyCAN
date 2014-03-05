#include "Timer.h"

static volatile DWORD ticksCount;
static volatile DWORD secondsCount;

void TMRInit(void)
{
	T0CONbits.T08BIT = 1;			// 16-bit Mode Clock
	T0CONbits.T0CS = 0;			// Internal Instruction Clock
	T0CONbits.PSA = 0;			// Prescaler Assigned
	T0CONbits.T0PS = 0b100;			// 1:32 Prescaler Selection

	TMR0 = TMR_PRELOAD;			// Preload Timer 0 for about 1ms Overflow

	ticksCount = 0;
	secondsCount = 0;

	INTCONbits.T0IE = 1;			// Enable Timer 0 Interrupt
	T0CONbits.TMR0ON = 1;			// Enable Timer 0
}

void TMRServeInt(void)
{
	INTCONbits.T0IF = 0;			// Clear TMR0 Interrupt Flag
	TMR0 = TMR_PRELOAD;			// Preload Timer 0 for 1ms Overflow
	ticksCount++;				// Increment Ticks Counter
	
	if (ticksCount % 1000 == 0)
		secondsCount++;
}

void TMRDelayMs(DWORD milliseconds)
{
	DWORD currentTicks = ticksCount;
	DWORD count;

	do
	{
		count = ticksCount - currentTicks;
	}
	while (count < milliseconds);
}

DWORD TMRGetTicksCount(void)
{
	return ticksCount;
}

DWORD TMRGetSecondsCount(void)
{
	return secondsCount;
}

DWORD TMRTicksElapsed(DWORD start)
{
	return (ticksCount - start);
}

DWORD TMRSecondsElapsed(DWORD start)
{
	return (secondsCount - start);
}
