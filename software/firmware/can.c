/* ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <info@gerhard-bertelsmann.de> wrote this file. As long as you retain this
 * notice you can do whatever you want with this stuff. If we meet some day,
 * and you think this stuff is worth it, you can buy me a beer in return
 * Gerhard Bertelsmann
 * ----------------------------------------------------------------------------
 */

#include "can.h"

volatile struct CAN_MSG TX_CANMessage;
volatile struct CAN_MSG RX_CANMessage;


/* TODO: until now we all clear all filters */
void init_can_filter(void) {
     // Initialize Acceptance Filters and Masks to 0x00:
     RXF0SIDH = 0; // SID10 to SID3
     RXF0SIDL = 0; // SID2 to SID0; Standard frame
     RXF1SIDH = 0;
     RXF1SIDL = 0;
     RXF2SIDH = 0;
     RXF2SIDL = 0;
     RXF3SIDH = 0;
     RXF3SIDL = 0;
     RXF4SIDH = 0;
     RXF4SIDL = 0;
     RXF5SIDH = 0;
     RXF5SIDL = 0;
     RXM0SIDH = 0;
     RXM0SIDL = 0;
     RXM1SIDH = 0;
     RXM1SIDL = 0;
}

void init_can(const char brgcon1, unsigned char brgcon2, unsigned char brgcon3) {
    /* enter CAN config mode */
    //CANCONbits.REQOP2 = 1;
    //CANSTATbits.OPMODE = 0x04
    CANCON = 0x80;
    while(!(CANSTATbits.OPMODE == 0x04));

    /* using ECAN 0 mode aka legacy mode */
    ECANCON = 0x00;

    /* set timing parameters */
    BRGCON1 = brgcon1;
    BRGCON2 = brgcon2;
    BRGCON3 = brgcon3;

    init_can_filter();

    // CANTX will drive VDD when recessive TODO
    CIOCON = 0x20;

    /* leaving CAN config mode */
    //CANCONbits.REQOP2 = 0;
    CANCON = 0x00;
    // TODO do we need to wait ?
    while(CANSTATbits.OPMODE == 0 );

    // Set Receive Mode for buffers
    RXB0CON = 0x00;
    RXB1CON = 0x00;
}

char can_readmsg(void) {
     char ReturnValue = 0;  
     // doesn't look genius but it's faster&smaller without a loop 
     // find full receiver
     if(RXB0CONbits.RXFUL){
        ReturnValue|=1;
        RX_CANMessage.EIDH=RXB0EIDH;
        RX_CANMessage.EIDL=RXB0EIDL;  
        RX_CANMessage.SIDH=RXB0SIDH;
        RX_CANMessage.SIDL=RXB0SIDL;  
        RX_CANMessage.Data[0]=RXB0D0;
        RX_CANMessage.Data[1]=RXB0D1;
        RX_CANMessage.Data[2]=RXB0D2;
        RX_CANMessage.Data[3]=RXB0D3;
        RX_CANMessage.Data[4]=RXB0D4;
        RX_CANMessage.Data[5]=RXB0D5;
        RX_CANMessage.Data[6]=RXB0D6;
        RX_CANMessage.Data[7]=RXB0D7;
        RX_CANMessage.DLC=RXB0DLC;
        RX_CANMessage.Priority=(RXB0CON&0x03);
        RXB0CONbits.RXFUL=0;
    }
    if(RXB1CONbits.RXFUL){
        ReturnValue|=2;
        RX_CANMessage.EIDH=RXB1EIDH;
        RX_CANMessage.EIDL=RXB1EIDL;  
        RX_CANMessage.SIDH=RXB1SIDH;
        RX_CANMessage.SIDL=RXB1SIDL;  
        RX_CANMessage.Data[0]=RXB1D0;
        RX_CANMessage.Data[1]=RXB1D1;
        RX_CANMessage.Data[2]=RXB1D2;
        RX_CANMessage.Data[3]=RXB1D3;
        RX_CANMessage.Data[4]=RXB1D4;
        RX_CANMessage.Data[5]=RXB1D5;
        RX_CANMessage.Data[6]=RXB1D6;
        RX_CANMessage.Data[7]=RXB1D7;
        RX_CANMessage.DLC=RXB1DLC;
        RX_CANMessage.Priority=(RXB1CON&0x03);
        RXB1CONbits.RXFUL=0;    
   }
   return ReturnValue;  
}

char putCAN(void){
    char ReturnValue = 0;
    
    // find emtpy transmitter buffer
    if (!(TXB0CONbits.TXREQ)) {
        ReturnValue=1;
        TXB0EIDH=TX_CANMessage.EIDH;
        TXB0EIDL=TX_CANMessage.EIDL;  
        TXB0SIDH=TX_CANMessage.SIDH;
        TXB0SIDL=TX_CANMessage.SIDL;  
        TXB0D0=TX_CANMessage.Data[0];
        TXB0D1=TX_CANMessage.Data[1];
        TXB0D2=TX_CANMessage.Data[2];
        TXB0D3=TX_CANMessage.Data[3];
        TXB0D4=TX_CANMessage.Data[4];
        TXB0D5=TX_CANMessage.Data[5];
        TXB0D6=TX_CANMessage.Data[6];
        TXB0D7=TX_CANMessage.Data[7];
        TXB0DLC=TX_CANMessage.DLC;
        // TXB0CON=(8|TX_CANMessage.Priority);
    } else if (!(TXB1CONbits.TXREQ)) {
        ReturnValue=2;
        TXB1EIDH=TX_CANMessage.EIDH;
        TXB1EIDL=TX_CANMessage.EIDL;  
        TXB1SIDH=TX_CANMessage.SIDH;
        TXB1SIDL=TX_CANMessage.SIDL;  
        TXB1D0=TX_CANMessage.Data[0];
        TXB1D1=TX_CANMessage.Data[1];
        TXB1D2=TX_CANMessage.Data[2];
        TXB1D3=TX_CANMessage.Data[3];
        TXB1D4=TX_CANMessage.Data[4];
        TXB1D5=TX_CANMessage.Data[5];
        TXB1D6=TX_CANMessage.Data[6];
        TXB1D7=TX_CANMessage.Data[7];
        TXB1DLC=TX_CANMessage.DLC;
        // TXB1CON=(8|TX_CANMessage.Priority);
    } else if (!(TXB2CONbits.TXREQ)) {
        ReturnValue=3;
        TXB2EIDH=TX_CANMessage.EIDH;
        TXB2EIDL=TX_CANMessage.EIDL;  
        TXB2SIDH=TX_CANMessage.SIDH;
        TXB2SIDL=TX_CANMessage.SIDL;  
        TXB2D0=TX_CANMessage.Data[0];
        TXB2D1=TX_CANMessage.Data[1];
        TXB2D2=TX_CANMessage.Data[2];
        TXB2D3=TX_CANMessage.Data[3];
        TXB2D4=TX_CANMessage.Data[4];
        TXB2D5=TX_CANMessage.Data[5];
        TXB2D6=TX_CANMessage.Data[6];
        TXB2D7=TX_CANMessage.Data[7];
        TXB2DLC=TX_CANMessage.DLC;
        // TXB2CON=(8|TX_CANMessage.Priority);
    }
    return ReturnValue;
}

