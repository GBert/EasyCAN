#include <xc.h>

#define _XTAL_FREQ 64000000   // This is the speed your controller is running at
#define FCYC (_XTAL_FREQ/4L)  // target device instruction clock freqency

#define LED_TRIS        (TRISAbits.TRISA0)
#define LED             (LATAbits.LATA0)

/* USART calculating Baud Rate Generator
 * if BRGH = 0 => FOSC/[64 (n + 1)]
 * if BRGH = 1 => FOSC/[16 (n + 1)]
 * avoid rounding errors
 */ 

#define BAUDRATE	500000
#define USE_BRG16	0
#define USE_BRGH	1

#if USE_BRGH == 0
#define	SBRG_VAL	( (((_XTAL_FREQ / BAUDRATE) / 32) - 1) / 2 )
#else
#define	SBRG_VAL	( (((_XTAL_FREQ / BAUDRATE) / 8) - 1) / 2 )
#endif

void interrupt ISRCode();

int i = 0;
volatile unsigned char timer_ticks=0;
void Delay1Second(void);

void init_port(void) {
    ADCON1 = 0x0F;		// Default all pins to digital
    LED_TRIS = 0;
}

void init_uart (void) {
    // USART configuration
    TXSTAbits.TX9  = 0;    // 8-bit transmission
    TXSTAbits.TXEN = 1;    // transmit enabled
    TXSTAbits.SYNC = 0;    // asynchronous mode
    TXSTAbits.BRGH = 1;    // high speed
    RCSTAbits.SPEN = 1;    // enable serial port (configures RX/DT and TX/CK pins as serial port pins)
    RCSTAbits.RX9  = 0;    // 8-bit reception
    RCSTAbits.CREN = USE_BRGH;    // enable receiver
    BAUDCON1bits.BRG16 = USE_BRG16; // 8-bit baud rate generator

    SPBRG = SBRG_VAL;      // calculated by defines
    
    TRISCbits.TRISC6 = 0;     // make the TX pin a digital output
    TRISCbits.TRISC7 = 1;     // make the RX pin a digital input
    
    /* don' use interrupts at the moment 
    // interrupts / USART interrupts configuration
    RCONbits.IPEN   = 0; // disable interrupt priority
    INTCONbits.GIE  = 1; // enable interrupts
    INTCONbits.PEIE = 1; // enable peripheral interrupts.
    PIE1bits.RCIE   = 1; // enable USART receive interrupt
    PIE1bits.TXIE   = 0; // disable USART TX interrupt
    */
    PIR1bits.RCIF = 0;
}

void init_timer(void) {
    // time period = 1/16MHz = 0.0625 us
    // prescaler period = .0625us * 256 = 16us
    // overflow period  = 16us * 256 = 4.096ms
    T0PS0=1;    //Prescaler is divide by 256
    T0PS1=1;
    T0PS2=1;

    PSA=0;      //Timer Clock Source is from Prescaler
    T0CS=0;     //Prescaler gets clock from FCPU (16MHz)

    T08BIT=1;   //8 BIT MODE

    TMR0IE=1;   //Enable TIMER0 Interrupt
    PEIE=1;     //Enable Peripheral Interrupt
    GIE=1;      //Enable INTs globally

    TMR0ON=1;   //Now start the timer!
}


void main(int argc, char** argv) {
    init_port();
    init_timer();
    init_uart();

    //infinite loop
    while(1) {
        /* LED = 1;
        Delay1Second();
	LED = 0;
        Delay1Second();
        */
    }
}

void Delay1Second() {
    for(i=0;i<50;i++)
        __delay_ms(10);
}

void interrupt ISRCode() {
    if (TMR0IE && TMR0IF) {
        // overflow every 4.096ms
        timer_ticks++;
        // 400ms
        if (timer_ticks==98) {
            LED = 1;
        }
        // 800ms
        if (timer_ticks==195) {
            LED = 0;
            timer_ticks=0;
        }
        TMR0IF = 0;
    }
}
