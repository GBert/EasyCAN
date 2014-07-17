/* ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <info@gerhard-bertelsmann.de> wrote this file. As long as you retain this
 * notice you can do whatever you want with this stuff. If we meet some day,
 * and you think this stuff is worth it, you can buy me a beer in return
 * Gerhard Bertelsmann
 * ----------------------------------------------------------------------------
 */

#include "main.h"

void init_timer(void) {
    // time period = 1/16MHz = 0.0625 us
    // prescaler period = .0625us * 256 = 16us
    // overflow period  = 16us * 256 = 4.096ms
    T0CONbits.T0PS=0b111;    //Prescaler is divide by 256

    T0CONbits.PSA=0;      //Timer Clock Source is from Prescaler
    T0CONbits.T0CS=0;     //Prescaler gets clock from FCPU (16MHz)

    T0CONbits.T08BIT=1;   //8 BIT MODE

    INTCONbits.TMR0IE=1;   //Enable TIMER0 Interrupt
    INTCONbits.PEIE=1;     //Enable Peripheral Interrupt
    INTCONbits.GIE=1;      //Enable INTs globally

    T0CONbits.TMR0ON=1;   //Now start the timer!
}

