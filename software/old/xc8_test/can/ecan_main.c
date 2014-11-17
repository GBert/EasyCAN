/**********************************************************************
* 2010 Microchip Technology Inc.
*
* FileName:        main.c
* Dependencies:    main (.h) files if applicable, see below
* Processor:       PIC18F66K80 family
* Linker:          MPLINK 4.37+
* Compiler:        C18 3.36+
*
* SOFTWARE LICENSE AGREEMENT:
* Microchip Technology Incorporated ("Microchip") retains all 
* ownership and intellectual property rights in the code accompanying
* this message and in all derivatives hereto.  You may use this code,
* and any derivatives created by any person or entity by or on your 
* behalf, exclusively with Microchip's proprietary products.  Your 
* acceptance and/or use of this code constitutes agreement to the 
* terms and conditions of this notice.
*
* CODE ACCOMPANYING THIS MESSAGE IS SUPPLIED BY MICROCHIP "AS IS". NO 
* WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT 
* NOT LIMITED TO, IMPLIED WARRANTIES OF NON-INFRINGEMENT, 
* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS 
* CODE, ITS INTERACTION WITH MICROCHIP'S PRODUCTS, COMBINATION WITH 
* ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
*
* YOU ACKNOWLEDGE AND AGREE THAT, IN NO EVENT, SHALL MICROCHIP BE 
* LIABLE, WHETHER IN CONTRACT, WARRANTY, TORT (INCLUDING NEGLIGENCE OR
* BREACH OF STATUTORY DUTY), STRICT LIABILITY, INDEMNITY, 
* CONTRIBUTION, OR OTHERWISE, FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
* EXEMPLARY, INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, FOR COST OR 
* EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE CODE, HOWSOEVER 
* CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE
* DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT ALLOWABLE BY LAW, 
* MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO THIS
* CODE, SHALL NOT EXCEED THE PRICE YOU PAID DIRECTLY TO MICROCHIP 
* SPECIFICALLY TO HAVE THIS CODE DEVELOPED.
*
* You agree that you are solely responsible for testing the code and 
* determining its suitability.  Microchip has no obligation to modify,
* test, certify, or support the code.
*
* REVISION HISTORY:
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        Date      	Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Manning C.    12/1/2010	First release of source file
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*
* ADDITIONAL NOTES:
* Code Tested on:
* PIC18 Explorer Demo Board with PIC18F46K80 (PIC18F66K80 family) controller + ECAN/LIN Daughterboard 
*
* DESCRIPTION:
* In this example, CPU is initially configured to run from external 
* secondary osc and then clock switching is initiated to run from 
* Internal FRC.
*********************************************************************/



/*********************************************************************
*
*                            Includes 
*
*********************************************************************/
#include <p18cxxx.h>
#include "ECAN.h"




/*********************************************************************
*
*                       Config Bit Settings
*
*********************************************************************/
#pragma config XINST = OFF


/*********************************************************************
*
*                             Defines 
*
*********************************************************************/
#define BTN1        PORTBbits.RB0

#define PRESSED     0

#define TRUE    1
#define FALSE   0

#define DEVICE_OSC  64
#define ONE_MS      (unsigned int)(DEVICE_OSC/4)*80


/*********************************************************************
*
*                        Function Prototypes 
*
*********************************************************************/
void InitDevice(void);
unsigned char ButtonPressed(void);
void Delay(unsigned int count);
void Heartbeat(void);


/*********************************************************************
*
*                            Global Variables 
*
*********************************************************************/
unsigned int heartbeatCount;
unsigned char buttonWasPressed;



/*********************************************************************
*
*                            Main Function 
*
*********************************************************************/
void main(void)
{    
    InitDevice();
    
    while(1)
    {
        if(ButtonPressed())
        {
            ECAN_Transmit();
        }
        
        if(ECAN_Receive())
        {
            LATD++;
        }

        Heartbeat();
        
        // Delay for one millisecond to debounce pushbutton
        Delay(ONE_MS);
    }
}


/*********************************************************************
*
*                       Initialize the Device 
*
*********************************************************************/
void InitDevice(void)
{
    // Set the internal oscillator to 64MHz
    OSCCONbits.IRCF = 7;
    OSCTUNEbits.PLLEN = 1;
    
    // Initialize global variables to 0
    heartbeatCount = 0;
    buttonWasPressed = 0;
    
    // Initialize I/O to be digital, with PORTD (LEDs) as outputs and PORTB as inputs (pushbutton)
    ANCON0 = ANCON1 = 0x00;
    LATD = 0x00;
    TRISD = 0x00;
    TRISB = 0xFF;
    
    // Initialize CAN module
    InitECAN();
}


/*********************************************************************
*
*                 Check to see if Button is pressed 
*
*********************************************************************/
unsigned char ButtonPressed(void)
{
    unsigned char buttonPressedState = FALSE;
    
    // Check to see if the pushbutton is pressed
    if(BTN1 == PRESSED)
    {        
        // If button wasn't previously pressed, then set current button pressed state to true
        if(buttonWasPressed == FALSE)
        {
            buttonPressedState = TRUE;
        }
        
        // Set flag to say button was previously pressed
        buttonWasPressed = TRUE;
    }
    else
    {
        // Clear flag to say button was previously not pressed
        buttonWasPressed = FALSE;
    }    
    
    // Return button pressed state
    return buttonPressedState;
}


/*********************************************************************
*
*                 Perform a simple delay 
*
*********************************************************************/
void Delay(unsigned int count)
{
    // Countdown until equal to zero and then return
    while(count--);
}    

/*********************************************************************
*
*             Toggle LED to show device is working 
*
*********************************************************************/
void Heartbeat(void)
{
    // Toggle LED every 256th time this function is called
    if (heartbeatCount < 255)
    {
        heartbeatCount++;
    }
    else
    {
        heartbeatCount = 0;
        LATDbits.LATD7 ^= 1;
    }
}





