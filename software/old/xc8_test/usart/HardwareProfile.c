#include "HardwareProfile.h"
#include "Timer.h"

void BoardInit(void) {
    // TODO Init Clock

    /* Turn off ADCs */

    ANCON0 = 0b11111111;
    ANCON1 = 0b11111111;

    ADCON0 = 0x00;
    ADCON1 = 0x00;
    ADCON2 = 0x00;

    /* turn off comperators */
    CM1CON = 0x00;
    CM2CON = 0x00;

    RXD_TRIS = INPUT_PIN;
    TXD_TRIS = OUTPUT_PIN;
    LED_TRIS = OUTPUT_PIN;

    LED = 0;

    EnableInterrupts();
}

void EnableInterrupts(void) {
    RCONbits.IPEN = 0;		// Disable Interrupt Priorities
    INTCONbits.GIE = 1;		// Enable Peripheral Interrupts
}
