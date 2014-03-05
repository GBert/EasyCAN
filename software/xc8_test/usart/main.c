#include <p18f26k80.h>    
#include <usart.h> 
#pragma config WDTEN = OFF 
#pragma config FOSC = HS2 
//#pragma config LVP = ON

void main(void) 
{ 
// configure USART 
unsigned int item,i; 
item=0x61; 
PORTB=0xff; 
Open1USART( USART_TX_INT_OFF & USART_RX_INT_OFF & USART_ASYNCH_MODE 
	& USART_EIGHT_BIT & USART_CONT_RX & USART_BRGH_HIGH, 51 );/////////////////baud rate 9600 for sync=0,brgh=1,brg16=0 
    //for(i=0;i<40000;i++); 
    Write1USART('H'); //write value of PORTD 
    Close1USART(); 
    while(1); 
} 
