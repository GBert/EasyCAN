        LIST

;==========================================================================
;  MPASM PIC18F26K80 processor include
; 
;  (c) Copyright 1999-2011 Microchip Technology, All rights reserved
;==========================================================================

        NOLIST

;==========================================================================
;  This header file defines configurations, registers, and other useful
;  bits of information for the PIC18F26K80 microcontroller.  These names
;  are taken to match the data sheets as closely as possible.
;
;  Note that the processor must be selected before this file is included.
;  The processor may be selected the following ways:
;
;       1. Command line switch:
;               C:\MPASM MYFILE.ASM /PIC18F26K80
;       2. LIST directive in the source file
;               LIST   P=PIC18F26K80
;       3. Processor Type entry in the MPASM full-screen interface
;       4. Setting the processor in the MPLAB Project Dialog
;==========================================================================

;==========================================================================
;
;       Verify Processor
;
;==========================================================================
        IFNDEF __18F26K80
           MESSG "Processor-header file mismatch.  Verify selected processor."
        ENDIF

;==========================================================================
;       18xxxx Family        EQUates
;==========================================================================
FSR0            EQU 0
FSR1            EQU 1
FSR2            EQU 2

FAST            EQU 1

W               EQU 0
A               EQU 0
ACCESS          EQU 0
BANKED          EQU 1
;==========================================================================

;==========================================================================
;       16Cxxx/17Cxxx Substitutions
;==========================================================================
  #define DDRA  TRISA      ; PIC17Cxxx SFR substitution
  #define DDRB  TRISB      ; PIC17Cxxx SFR substitution
  #define DDRC  TRISC      ; PIC17Cxxx SFR substitution
  #define DDRD  TRISD      ; PIC17Cxxx SFR substitution
  #define DDRE  TRISE      ; PIC17Cxxx SFR substitution

;==========================================================================
;
;       Register Definitions
;
;==========================================================================

;----- Register Files -----------------------------------------------------
RXERRCNT         EQU  H'0E41'
TXERRCNT         EQU  H'0E42'
BRGCON1          EQU  H'0E43'
BRGCON2          EQU  H'0E44'
BRGCON3          EQU  H'0E45'
RXFCON0          EQU  H'0E46'
RXFCON1          EQU  H'0E47'
RXF6SIDH         EQU  H'0E48'
RXF6SIDL         EQU  H'0E49'
RXF6EIDH         EQU  H'0E4A'
RXF6EIDL         EQU  H'0E4B'
RXF7SIDH         EQU  H'0E4C'
RXF7SIDL         EQU  H'0E4D'
RXF7EIDH         EQU  H'0E4E'
RXF7EIDL         EQU  H'0E4F'
RXF8SIDH         EQU  H'0E50'
RXF8SIDL         EQU  H'0E51'
RXF8EIDH         EQU  H'0E52'
RXF8EIDL         EQU  H'0E53'
RXF9SIDH         EQU  H'0E54'
RXF9SIDL         EQU  H'0E55'
RXF9EIDH         EQU  H'0E56'
RXF9EIDL         EQU  H'0E57'
RXF10SIDH        EQU  H'0E58'
RXF10SIDL        EQU  H'0E59'
RXF10EIDH        EQU  H'0E5A'
RXF10EIDL        EQU  H'0E5B'
RXF11SIDH        EQU  H'0E5C'
RXF11SIDL        EQU  H'0E5D'
RXF11EIDH        EQU  H'0E5E'
RXF11EIDL        EQU  H'0E5F'
RXF12SIDH        EQU  H'0E60'
RXF12SIDL        EQU  H'0E61'
RXF12EIDH        EQU  H'0E62'
RXF12EIDL        EQU  H'0E63'
RXF13SIDH        EQU  H'0E64'
RXF13SIDL        EQU  H'0E65'
RXF13EIDH        EQU  H'0E66'
RXF13EIDL        EQU  H'0E67'
RXF14SIDH        EQU  H'0E68'
RXF14SIDL        EQU  H'0E69'
RXF14EIDH        EQU  H'0E6A'
RXF14EIDL        EQU  H'0E6B'
RXF15SIDH        EQU  H'0E6C'
RXF15SIDL        EQU  H'0E6D'
RXF15EIDH        EQU  H'0E6E'
RXF15EIDL        EQU  H'0E6F'
SDFLC            EQU  H'0E70'
RXFBCON0         EQU  H'0E71'
RXFBCON1         EQU  H'0E72'
RXFBCON2         EQU  H'0E73'
RXFBCON3         EQU  H'0E74'
RXFBCON4         EQU  H'0E75'
RXFBCON5         EQU  H'0E76'
RXFBCON6         EQU  H'0E77'
RXFBCON7         EQU  H'0E78'
MSEL0            EQU  H'0E79'
MSEL1            EQU  H'0E7A'
MSEL2            EQU  H'0E7B'
MSEL3            EQU  H'0E7C'
BSEL0            EQU  H'0E7D'
BIE0             EQU  H'0E7E'
TXBIE            EQU  H'0E7F'
B0CON            EQU  H'0E80'
B0SIDH           EQU  H'0E81'
B0SIDL           EQU  H'0E82'
B0EIDH           EQU  H'0E83'
B0EIDL           EQU  H'0E84'
B0DLC            EQU  H'0E85'
B0D0             EQU  H'0E86'
B0D1             EQU  H'0E87'
B0D2             EQU  H'0E88'
B0D3             EQU  H'0E89'
B0D4             EQU  H'0E8A'
B0D5             EQU  H'0E8B'
B0D6             EQU  H'0E8C'
B0D7             EQU  H'0E8D'
CANSTAT_RO9      EQU  H'0E8E'
CANCON_RO9       EQU  H'0E8F'
B1CON            EQU  H'0E90'
B1SIDH           EQU  H'0E91'
B1SIDL           EQU  H'0E92'
B1EIDH           EQU  H'0E93'
B1EIDL           EQU  H'0E94'
B1DLC            EQU  H'0E95'
B1D0             EQU  H'0E96'
B1D1             EQU  H'0E97'
B1D2             EQU  H'0E98'
B1D3             EQU  H'0E99'
B1D4             EQU  H'0E9A'
B1D5             EQU  H'0E9B'
B1D6             EQU  H'0E9C'
B1D7             EQU  H'0E9D'
CANSTAT_RO8      EQU  H'0E9E'
CANCON_RO8       EQU  H'0E9F'
B2CON            EQU  H'0EA0'
B2SIDH           EQU  H'0EA1'
B2SIDL           EQU  H'0EA2'
B2EIDH           EQU  H'0EA3'
B2EIDL           EQU  H'0EA4'
B2DLC            EQU  H'0EA5'
B2D0             EQU  H'0EA6'
B2D1             EQU  H'0EA7'
B2D2             EQU  H'0EA8'
B2D3             EQU  H'0EA9'
B2D4             EQU  H'0EAA'
B2D5             EQU  H'0EAB'
B2D6             EQU  H'0EAC'
B2D7             EQU  H'0EAD'
CANSTAT_RO7      EQU  H'0EAE'
CANCON_RO7       EQU  H'0EAF'
B3CON            EQU  H'0EB0'
B3SIDH           EQU  H'0EB1'
B3SIDL           EQU  H'0EB2'
B3EIDH           EQU  H'0EB3'
B3EIDL           EQU  H'0EB4'
B3DLC            EQU  H'0EB5'
B3D0             EQU  H'0EB6'
B3D1             EQU  H'0EB7'
B3D2             EQU  H'0EB8'
B3D3             EQU  H'0EB9'
B3D4             EQU  H'0EBA'
B3D5             EQU  H'0EBB'
B3D6             EQU  H'0EBC'
B3D7             EQU  H'0EBD'
CANSTAT_RO6      EQU  H'0EBE'
CANCON_RO6       EQU  H'0EBF'
B4CON            EQU  H'0EC0'
B4SIDH           EQU  H'0EC1'
B4SIDL           EQU  H'0EC2'
B4EIDH           EQU  H'0EC3'
B4EIDL           EQU  H'0EC4'
B4DLC            EQU  H'0EC5'
B4D0             EQU  H'0EC6'
B4D1             EQU  H'0EC7'
B4D2             EQU  H'0EC8'
B4D3             EQU  H'0EC9'
B4D4             EQU  H'0ECA'
B4D5             EQU  H'0ECB'
B4D6             EQU  H'0ECC'
B4D7             EQU  H'0ECD'
CANSTAT_RO5      EQU  H'0ECE'
CANCON_RO5       EQU  H'0ECF'
B5CON            EQU  H'0ED0'
B5SIDH           EQU  H'0ED1'
B5SIDL           EQU  H'0ED2'
B5EIDH           EQU  H'0ED3'
B5EIDL           EQU  H'0ED4'
B5DLC            EQU  H'0ED5'
B5D0             EQU  H'0ED6'
B5D1             EQU  H'0ED7'
B5D2             EQU  H'0ED8'
B5D3             EQU  H'0ED9'
B5D4             EQU  H'0EDA'
B5D5             EQU  H'0EDB'
B5D6             EQU  H'0EDC'
B5D7             EQU  H'0EDD'
CANSTAT_RO4      EQU  H'0EDE'
CANCON_RO4       EQU  H'0EDF'
RXF0SIDH         EQU  H'0EE0'
RXF0SIDL         EQU  H'0EE1'
RXF0EIDH         EQU  H'0EE2'
RXF0EIDL         EQU  H'0EE3'
RXF1SIDH         EQU  H'0EE4'
RXF1SIDL         EQU  H'0EE5'
RXF1EIDH         EQU  H'0EE6'
RXF1EIDL         EQU  H'0EE7'
RXF2SIDH         EQU  H'0EE8'
RXF2SIDL         EQU  H'0EE9'
RXF2EIDH         EQU  H'0EEA'
RXF2EIDL         EQU  H'0EEB'
RXF3SIDH         EQU  H'0EEC'
RXF3SIDL         EQU  H'0EED'
RXF3EIDH         EQU  H'0EEE'
RXF3EIDL         EQU  H'0EEF'
RXF4SIDH         EQU  H'0EF0'
RXF4SIDL         EQU  H'0EF1'
RXF4EIDH         EQU  H'0EF2'
RXF4EIDL         EQU  H'0EF3'
RXF5SIDH         EQU  H'0EF4'
RXF5SIDL         EQU  H'0EF5'
RXF5EIDH         EQU  H'0EF6'
RXF5EIDL         EQU  H'0EF7'
RXM0SIDH         EQU  H'0EF8'
RXM0SIDL         EQU  H'0EF9'
RXM0EIDH         EQU  H'0EFA'
RXM0EIDL         EQU  H'0EFB'
RXM1SIDH         EQU  H'0EFC'
RXM1SIDL         EQU  H'0EFD'
RXM1EIDH         EQU  H'0EFE'
RXM1EIDL         EQU  H'0EFF'
TXB2CON          EQU  H'0F00'
TXB2SIDH         EQU  H'0F01'
TXB2SIDL         EQU  H'0F02'
TXB2EIDH         EQU  H'0F03'
TXB2EIDL         EQU  H'0F04'
TXB2DLC          EQU  H'0F05'
TXB2D0           EQU  H'0F06'
TXB2D1           EQU  H'0F07'
TXB2D2           EQU  H'0F08'
TXB2D3           EQU  H'0F09'
TXB2D4           EQU  H'0F0A'
TXB2D5           EQU  H'0F0B'
TXB2D6           EQU  H'0F0C'
TXB2D7           EQU  H'0F0D'
CANSTAT_RO3      EQU  H'0F0E'
CANCON_RO3       EQU  H'0F0F'
TXB1CON          EQU  H'0F10'
TXB1SIDH         EQU  H'0F11'
TXB1SIDL         EQU  H'0F12'
TXB1EIDH         EQU  H'0F13'
TXB1EIDL         EQU  H'0F14'
TXB1DLC          EQU  H'0F15'
TXB1D0           EQU  H'0F16'
TXB1D1           EQU  H'0F17'
TXB1D2           EQU  H'0F18'
TXB1D3           EQU  H'0F19'
TXB1D4           EQU  H'0F1A'
TXB1D5           EQU  H'0F1B'
TXB1D6           EQU  H'0F1C'
TXB1D7           EQU  H'0F1D'
CANSTAT_RO2      EQU  H'0F1E'
CANCON_RO2       EQU  H'0F1F'
TXB0CON          EQU  H'0F20'
TXB0SIDH         EQU  H'0F21'
TXB0SIDL         EQU  H'0F22'
TXB0EIDH         EQU  H'0F23'
TXB0EIDL         EQU  H'0F24'
TXB0DLC          EQU  H'0F25'
TXB0D0           EQU  H'0F26'
TXB0D1           EQU  H'0F27'
TXB0D2           EQU  H'0F28'
TXB0D3           EQU  H'0F29'
TXB0D4           EQU  H'0F2A'
TXB0D5           EQU  H'0F2B'
TXB0D6           EQU  H'0F2C'
TXB0D7           EQU  H'0F2D'
CANSTAT_RO1      EQU  H'0F2E'
CANCON_RO1       EQU  H'0F2F'
RXB1CON          EQU  H'0F30'
RXB1SIDH         EQU  H'0F31'
RXB1SIDL         EQU  H'0F32'
RXB1EIDH         EQU  H'0F33'
RXB1EIDL         EQU  H'0F34'
RXB1DLC          EQU  H'0F35'
RXB1D0           EQU  H'0F36'
RXB1D1           EQU  H'0F37'
RXB1D2           EQU  H'0F38'
RXB1D3           EQU  H'0F39'
RXB1D4           EQU  H'0F3A'
RXB1D5           EQU  H'0F3B'
RXB1D6           EQU  H'0F3C'
RXB1D7           EQU  H'0F3D'
CANSTAT_RO0      EQU  H'0F3E'
CANCON_RO0       EQU  H'0F3F'
CCP5CON          EQU  H'0F47'
CCPR5            EQU  H'0F48'
CCPR5L           EQU  H'0F48'
CCPR5H           EQU  H'0F49'
CCP4CON          EQU  H'0F4A'
CCPR4            EQU  H'0F4B'
CCPR4L           EQU  H'0F4B'
CCPR4H           EQU  H'0F4C'
CCP3CON          EQU  H'0F4D'
CCPR3            EQU  H'0F4E'
CCPR3L           EQU  H'0F4E'
CCPR3H           EQU  H'0F4F'
CCP2CON          EQU  H'0F50'
ECCP2CON         EQU  H'0F50'
CCPR2            EQU  H'0F51'
CCPR2L           EQU  H'0F51'
CCPR2H           EQU  H'0F52'
CTMUICON         EQU  H'0F53'
CTMUCONL         EQU  H'0F54'
CTMUCONH         EQU  H'0F55'
PADCFG1          EQU  H'0F56'
PMD2             EQU  H'0F57'
PMD1             EQU  H'0F58'
PMD0             EQU  H'0F59'
IOCB             EQU  H'0F5A'
WPUB             EQU  H'0F5B'
ANCON1           EQU  H'0F5C'
ANCON0           EQU  H'0F5D'
CM2CON           EQU  H'0F5E'
CM2CON1          EQU  H'0F5E'
CM1CON           EQU  H'0F5F'
CM1CON1          EQU  H'0F5F'
RXB0CON          EQU  H'0F60'
RXB0SIDH         EQU  H'0F61'
RXB0SIDL         EQU  H'0F62'
RXB0EIDH         EQU  H'0F63'
RXB0EIDL         EQU  H'0F64'
RXB0DLC          EQU  H'0F65'
RXB0D0           EQU  H'0F66'
RXB0D1           EQU  H'0F67'
RXB0D2           EQU  H'0F68'
RXB0D3           EQU  H'0F69'
RXB0D4           EQU  H'0F6A'
RXB0D5           EQU  H'0F6B'
RXB0D6           EQU  H'0F6C'
RXB0D7           EQU  H'0F6D'
CANSTAT          EQU  H'0F6E'
CANCON           EQU  H'0F6F'
CIOCON           EQU  H'0F70'
COMSTAT          EQU  H'0F71'
ECANCON          EQU  H'0F72'
EEDATA           EQU  H'0F73'
EEADR            EQU  H'0F74'
EEADRH           EQU  H'0F75'
PIE5             EQU  H'0F76'
PIR5             EQU  H'0F77'
IPR5             EQU  H'0F78'
TXREG2           EQU  H'0F79'
RCREG2           EQU  H'0F7A'
SPBRG2           EQU  H'0F7B'
SPBRGH2          EQU  H'0F7C'
SPBRGH1          EQU  H'0F7D'
EECON2           EQU  H'0F7E'
EECON1           EQU  H'0F7F'
PORTA            EQU  H'0F80'
PORTB            EQU  H'0F81'
PORTC            EQU  H'0F82'
PORTE            EQU  H'0F84'
TMR4             EQU  H'0F87'
T4CON            EQU  H'0F88'
LATA             EQU  H'0F89'
LATB             EQU  H'0F8A'
LATC             EQU  H'0F8B'
SLRCON           EQU  H'0F90'
ODCON            EQU  H'0F91'
TRISA            EQU  H'0F92'
TRISB            EQU  H'0F93'
TRISC            EQU  H'0F94'
CCPTMRS          EQU  H'0F99'
REFOCON          EQU  H'0F9A'
OSCTUNE          EQU  H'0F9B'
PSTR1CON         EQU  H'0F9C'
PIE1             EQU  H'0F9D'
PIR1             EQU  H'0F9E'
IPR1             EQU  H'0F9F'
PIE2             EQU  H'0FA0'
PIR2             EQU  H'0FA1'
IPR2             EQU  H'0FA2'
PIE3             EQU  H'0FA3'
PIR3             EQU  H'0FA4'
IPR3             EQU  H'0FA5'
RCSTA2           EQU  H'0FA6'
BAUDCON1         EQU  H'0FA7'
HLVDCON          EQU  H'0FA8'
PR4              EQU  H'0FA9'
T1GCON           EQU  H'0FAA'
RCSTA            EQU  H'0FAB'
RCSTA1           EQU  H'0FAB'
TXSTA            EQU  H'0FAC'
TXSTA1           EQU  H'0FAC'
TXREG            EQU  H'0FAD'
TXREG1           EQU  H'0FAD'
RCREG            EQU  H'0FAE'
RCREG1           EQU  H'0FAE'
SPBRG            EQU  H'0FAF'
SPBRG1           EQU  H'0FAF'
T3GCON           EQU  H'0FB0'
T3CON            EQU  H'0FB1'
TMR3             EQU  H'0FB2'
TMR3L            EQU  H'0FB2'
TMR3H            EQU  H'0FB3'
CMSTAT           EQU  H'0FB4'
CMSTATUS         EQU  H'0FB4'
CVRCON           EQU  H'0FB5'
PIE4             EQU  H'0FB6'
PIR4             EQU  H'0FB7'
IPR4             EQU  H'0FB8'
BAUDCON2         EQU  H'0FB9'
TXSTA2           EQU  H'0FBA'
CCP1CON          EQU  H'0FBB'
ECCP1CON         EQU  H'0FBB'
CCPR1            EQU  H'0FBC'
CCPR1L           EQU  H'0FBC'
CCPR1H           EQU  H'0FBD'
ECCP1DEL         EQU  H'0FBE'
PWM1CON          EQU  H'0FBE'
ECCP1AS          EQU  H'0FBF'
ADCON2           EQU  H'0FC0'
ADCON1           EQU  H'0FC1'
ADCON0           EQU  H'0FC2'
ADRES            EQU  H'0FC3'
ADRESL           EQU  H'0FC3'
ADRESH           EQU  H'0FC4'
SSPCON2          EQU  H'0FC5'
SSPCON1          EQU  H'0FC6'
SSPSTAT          EQU  H'0FC7'
SSPADD           EQU  H'0FC8'
SSPBUF           EQU  H'0FC9'
T2CON            EQU  H'0FCA'
PR2              EQU  H'0FCB'
TMR2             EQU  H'0FCC'
T1CON            EQU  H'0FCD'
TMR1             EQU  H'0FCE'
TMR1L            EQU  H'0FCE'
TMR1H            EQU  H'0FCF'
RCON             EQU  H'0FD0'
WDTCON           EQU  H'0FD1'
OSCCON2          EQU  H'0FD2'
OSCCON           EQU  H'0FD3'
T0CON            EQU  H'0FD5'
TMR0             EQU  H'0FD6'
TMR0L            EQU  H'0FD6'
TMR0H            EQU  H'0FD7'
STATUS           EQU  H'0FD8'
FSR2L            EQU  H'0FD9'
FSR2H            EQU  H'0FDA'
PLUSW2           EQU  H'0FDB'
PREINC2          EQU  H'0FDC'
POSTDEC2         EQU  H'0FDD'
POSTINC2         EQU  H'0FDE'
INDF2            EQU  H'0FDF'
BSR              EQU  H'0FE0'
FSR1L            EQU  H'0FE1'
FSR1H            EQU  H'0FE2'
PLUSW1           EQU  H'0FE3'
PREINC1          EQU  H'0FE4'
POSTDEC1         EQU  H'0FE5'
POSTINC1         EQU  H'0FE6'
INDF1            EQU  H'0FE7'
WREG             EQU  H'0FE8'
FSR0L            EQU  H'0FE9'
FSR0H            EQU  H'0FEA'
PLUSW0           EQU  H'0FEB'
PREINC0          EQU  H'0FEC'
POSTDEC0         EQU  H'0FED'
POSTINC0         EQU  H'0FEE'
INDF0            EQU  H'0FEF'
INTCON3          EQU  H'0FF0'
INTCON2          EQU  H'0FF1'
INTCON           EQU  H'0FF2'
INTCON1          EQU  H'0FF2'
PROD             EQU  H'0FF3'
PRODL            EQU  H'0FF3'
PRODH            EQU  H'0FF4'
TABLAT           EQU  H'0FF5'
TBLPTR           EQU  H'0FF6'
TBLPTRL          EQU  H'0FF6'
TBLPTRH          EQU  H'0FF7'
TBLPTRU          EQU  H'0FF8'
PC               EQU  H'0FF9'
PCL              EQU  H'0FF9'
PCLATH           EQU  H'0FFA'
PCLATU           EQU  H'0FFB'
STKPTR           EQU  H'0FFC'
TOS              EQU  H'0FFD'
TOSL             EQU  H'0FFD'
TOSH             EQU  H'0FFE'
TOSU             EQU  H'0FFF'

;----- RXERRCNT Bits -----------------------------------------------------
REC0             EQU  H'0000'
REC1             EQU  H'0001'
REC2             EQU  H'0002'
REC3             EQU  H'0003'
REC4             EQU  H'0004'
REC5             EQU  H'0005'
REC6             EQU  H'0006'
REC7             EQU  H'0007'


;----- TXERRCNT Bits -----------------------------------------------------
TEC0             EQU  H'0000'
TEC1             EQU  H'0001'
TEC2             EQU  H'0002'
TEC3             EQU  H'0003'
TEC4             EQU  H'0004'
TEC5             EQU  H'0005'
TEC6             EQU  H'0006'
TEC7             EQU  H'0007'


;----- BRGCON1 Bits -----------------------------------------------------
BRP0             EQU  H'0000'
BRP1             EQU  H'0001'
BRP2             EQU  H'0002'
BRP3             EQU  H'0003'
BRP4             EQU  H'0004'
BRP5             EQU  H'0005'
SJW0             EQU  H'0006'
SJW1             EQU  H'0007'


;----- BRGCON2 Bits -----------------------------------------------------
SAM              EQU  H'0006'
SEG2PHTS         EQU  H'0007'

PRSEG0           EQU  H'0000'
PRSEG1           EQU  H'0001'
PRSEG2           EQU  H'0002'
SEG1PH0          EQU  H'0003'
SEG1PH1          EQU  H'0004'
SEG1PH2          EQU  H'0005'


;----- BRGCON3 Bits -----------------------------------------------------
WAKFIL           EQU  H'0006'
WAKDIS           EQU  H'0007'

SEG2PH0          EQU  H'0000'
SEG2PH1          EQU  H'0001'
SEG2PH2          EQU  H'0002'


;----- RXFCON0 Bits -----------------------------------------------------
RXF0EN           EQU  H'0000'
RXF1EN           EQU  H'0001'
RXF2EN           EQU  H'0002'
RXF3EN           EQU  H'0003'
RXF4EN           EQU  H'0004'
RXF5EN           EQU  H'0005'
RXF6EN           EQU  H'0006'
RXF7EN           EQU  H'0007'


;----- RXFCON1 Bits -----------------------------------------------------
RXF8EN           EQU  H'0000'
RXF9EN           EQU  H'0001'
RXF10EN          EQU  H'0002'
RXF11EN          EQU  H'0003'
RXF12EN          EQU  H'0004'
RXF13EN          EQU  H'0005'
RXF14EN          EQU  H'0006'
RXF15EN          EQU  H'0007'


;----- RXF6SIDH Bits -----------------------------------------------------
SID3             EQU  H'0000'
SID4             EQU  H'0001'
SID5             EQU  H'0002'
SID6             EQU  H'0003'
SID7             EQU  H'0004'
SID8             EQU  H'0005'
SID9             EQU  H'0006'
SID10            EQU  H'0007'


;----- RXF6SIDL Bits -----------------------------------------------------
EXIDEN           EQU  H'0003'

EID16            EQU  H'0000'
EID17            EQU  H'0001'
SID0             EQU  H'0005'
SID1             EQU  H'0006'
SID2             EQU  H'0007'


;----- RXF6EIDH Bits -----------------------------------------------------
EID8             EQU  H'0000'
EID9             EQU  H'0001'
EID10            EQU  H'0002'
EID11            EQU  H'0003'
EID12            EQU  H'0004'
EID13            EQU  H'0005'
EID14            EQU  H'0006'
EID15            EQU  H'0007'


;----- RXF6EIDL Bits -----------------------------------------------------
EID0             EQU  H'0000'
EID1             EQU  H'0001'
EID2             EQU  H'0002'
EID3             EQU  H'0003'
EID4             EQU  H'0004'
EID5             EQU  H'0005'
EID6             EQU  H'0006'
EID7             EQU  H'0007'


;----- RXF7SIDH Bits -----------------------------------------------------
SID3             EQU  H'0000'
SID4             EQU  H'0001'
SID5             EQU  H'0002'
SID6             EQU  H'0003'
SID7             EQU  H'0004'
SID8             EQU  H'0005'
SID9             EQU  H'0006'
SID10            EQU  H'0007'


;----- RXF7SIDL Bits -----------------------------------------------------
EXIDEN           EQU  H'0003'

EID16            EQU  H'0000'
EID17            EQU  H'0001'
SID0             EQU  H'0005'
SID1             EQU  H'0006'
SID2             EQU  H'0007'


;----- RXF7EIDH Bits -----------------------------------------------------
EID8             EQU  H'0000'
EID9             EQU  H'0001'
EID10            EQU  H'0002'
EID11            EQU  H'0003'
EID12            EQU  H'0004'
EID13            EQU  H'0005'
EID14            EQU  H'0006'
EID15            EQU  H'0007'


;----- RXF7EIDL Bits -----------------------------------------------------
EID0             EQU  H'0000'
EID1             EQU  H'0001'
EID2             EQU  H'0002'
EID3             EQU  H'0003'
EID4             EQU  H'0004'
EID5             EQU  H'0005'
EID6             EQU  H'0006'
EID7             EQU  H'0007'


;----- RXF8SIDH Bits -----------------------------------------------------
SID3             EQU  H'0000'
SID4             EQU  H'0001'
SID5             EQU  H'0002'
SID6             EQU  H'0003'
SID7             EQU  H'0004'
SID8             EQU  H'0005'
SID9             EQU  H'0006'
SID10            EQU  H'0007'


;----- RXF8SIDL Bits -----------------------------------------------------
EXIDEN           EQU  H'0003'

EID16            EQU  H'0000'
EID17            EQU  H'0001'
SID0             EQU  H'0005'
SID1             EQU  H'0006'
SID2             EQU  H'0007'


;----- RXF8EIDH Bits -----------------------------------------------------
EID8             EQU  H'0000'
EID9             EQU  H'0001'
EID10            EQU  H'0002'
EID11            EQU  H'0003'
EID12            EQU  H'0004'
EID13            EQU  H'0005'
EID14            EQU  H'0006'
EID15            EQU  H'0007'


;----- RXF8EIDL Bits -----------------------------------------------------
EID0             EQU  H'0000'
EID1             EQU  H'0001'
EID2             EQU  H'0002'
EID3             EQU  H'0003'
EID4             EQU  H'0004'
EID5             EQU  H'0005'
EID6             EQU  H'0006'
EID7             EQU  H'0007'


;----- RXF9SIDH Bits -----------------------------------------------------
SID3             EQU  H'0000'
SID4             EQU  H'0001'
SID5             EQU  H'0002'
SID6             EQU  H'0003'
SID7             EQU  H'0004'
SID8             EQU  H'0005'
SID9             EQU  H'0006'
SID10            EQU  H'0007'


;----- RXF9SIDL Bits -----------------------------------------------------
EXIDEN           EQU  H'0003'

EID16            EQU  H'0000'
EID17            EQU  H'0001'
SID0             EQU  H'0005'
SID1             EQU  H'0006'
SID2             EQU  H'0007'


;----- RXF9EIDH Bits -----------------------------------------------------
EID8             EQU  H'0000'
EID9             EQU  H'0001'
EID10            EQU  H'0002'
EID11            EQU  H'0003'
EID12            EQU  H'0004'
EID13            EQU  H'0005'
EID14            EQU  H'0006'
EID15            EQU  H'0007'


;----- RXF9EIDL Bits -----------------------------------------------------
EID0             EQU  H'0000'
EID1             EQU  H'0001'
EID2             EQU  H'0002'
EID3             EQU  H'0003'
EID4             EQU  H'0004'
EID5             EQU  H'0005'
EID6             EQU  H'0006'
EID7             EQU  H'0007'


;----- RXF10SIDH Bits -----------------------------------------------------
SID3             EQU  H'0000'
SID4             EQU  H'0001'
SID5             EQU  H'0002'
SID6             EQU  H'0003'
SID7             EQU  H'0004'
SID8             EQU  H'0005'
SID9             EQU  H'0006'
SID10            EQU  H'0007'


;----- RXF10SIDL Bits -----------------------------------------------------
EXIDEN           EQU  H'0003'

EID16            EQU  H'0000'
EID17            EQU  H'0001'
SID0             EQU  H'0005'
SID1             EQU  H'0006'
SID2             EQU  H'0007'


;----- RXF10EIDH Bits -----------------------------------------------------
EID8             EQU  H'0000'
EID9             EQU  H'0001'
EID10            EQU  H'0002'
EID11            EQU  H'0003'
EID12            EQU  H'0004'
EID13            EQU  H'0005'
EID14            EQU  H'0006'
EID15            EQU  H'0007'


;----- RXF10EIDL Bits -----------------------------------------------------
EID0             EQU  H'0000'
EID1             EQU  H'0001'
EID2             EQU  H'0002'
EID3             EQU  H'0003'
EID4             EQU  H'0004'
EID5             EQU  H'0005'
EID6             EQU  H'0006'
EID7             EQU  H'0007'


;----- RXF11SIDH Bits -----------------------------------------------------
SID3             EQU  H'0000'
SID4             EQU  H'0001'
SID5             EQU  H'0002'
SID6             EQU  H'0003'
SID7             EQU  H'0004'
SID8             EQU  H'0005'
SID9             EQU  H'0006'
SID10            EQU  H'0007'


;----- RXF11SIDL Bits -----------------------------------------------------
EXIDEN           EQU  H'0003'

EID16            EQU  H'0000'
EID17            EQU  H'0001'
SID0             EQU  H'0005'
SID1             EQU  H'0006'
SID2             EQU  H'0007'


;----- RXF11EIDH Bits -----------------------------------------------------
EID8             EQU  H'0000'
EID9             EQU  H'0001'
EID10            EQU  H'0002'
EID11            EQU  H'0003'
EID12            EQU  H'0004'
EID13            EQU  H'0005'
EID14            EQU  H'0006'
EID15            EQU  H'0007'


;----- RXF11EIDL Bits -----------------------------------------------------
EID0             EQU  H'0000'
EID1             EQU  H'0001'
EID2             EQU  H'0002'
EID3             EQU  H'0003'
EID4             EQU  H'0004'
EID5             EQU  H'0005'
EID6             EQU  H'0006'
EID7             EQU  H'0007'


;----- RXF12SIDH Bits -----------------------------------------------------
SID3             EQU  H'0000'
SID4             EQU  H'0001'
SID5             EQU  H'0002'
SID6             EQU  H'0003'
SID7             EQU  H'0004'
SID8             EQU  H'0005'
SID9             EQU  H'0006'
SID10            EQU  H'0007'


;----- RXF12SIDL Bits -----------------------------------------------------
EXIDEN           EQU  H'0003'

EID16            EQU  H'0000'
EID17            EQU  H'0001'
SID0             EQU  H'0005'
SID1             EQU  H'0006'
SID2             EQU  H'0007'


;----- RXF12EIDH Bits -----------------------------------------------------
EID8             EQU  H'0000'
EID9             EQU  H'0001'
EID10            EQU  H'0002'
EID11            EQU  H'0003'
EID12            EQU  H'0004'
EID13            EQU  H'0005'
EID14            EQU  H'0006'
EID15            EQU  H'0007'


;----- RXF12EIDL Bits -----------------------------------------------------
EID0             EQU  H'0000'
EID1             EQU  H'0001'
EID2             EQU  H'0002'
EID3             EQU  H'0003'
EID4             EQU  H'0004'
EID5             EQU  H'0005'
EID6             EQU  H'0006'
EID7             EQU  H'0007'


;----- RXF13SIDH Bits -----------------------------------------------------
SID3             EQU  H'0000'
SID4             EQU  H'0001'
SID5             EQU  H'0002'
SID6             EQU  H'0003'
SID7             EQU  H'0004'
SID8             EQU  H'0005'
SID9             EQU  H'0006'
SID10            EQU  H'0007'


;----- RXF13SIDL Bits -----------------------------------------------------
EXIDEN           EQU  H'0003'

EID16            EQU  H'0000'
EID17            EQU  H'0001'
SID0             EQU  H'0005'
SID1             EQU  H'0006'
SID2             EQU  H'0007'


;----- RXF13EIDH Bits -----------------------------------------------------
EID8             EQU  H'0000'
EID9             EQU  H'0001'
EID10            EQU  H'0002'
EID11            EQU  H'0003'
EID12            EQU  H'0004'
EID13            EQU  H'0005'
EID14            EQU  H'0006'
EID15            EQU  H'0007'


;----- RXF13EIDL Bits -----------------------------------------------------
EID0             EQU  H'0000'
EID1             EQU  H'0001'
EID2             EQU  H'0002'
EID3             EQU  H'0003'
EID4             EQU  H'0004'
EID5             EQU  H'0005'
EID6             EQU  H'0006'
EID7             EQU  H'0007'


;----- RXF14SIDH Bits -----------------------------------------------------
SID3             EQU  H'0000'
SID4             EQU  H'0001'
SID5             EQU  H'0002'
SID6             EQU  H'0003'
SID7             EQU  H'0004'
SID8             EQU  H'0005'
SID9             EQU  H'0006'
SID10            EQU  H'0007'


;----- RXF14SIDL Bits -----------------------------------------------------
EXIDEN           EQU  H'0003'

EID16            EQU  H'0000'
EID17            EQU  H'0001'
SID0             EQU  H'0005'
SID1             EQU  H'0006'
SID2             EQU  H'0007'


;----- RXF14EIDH Bits -----------------------------------------------------
EID8             EQU  H'0000'
EID9             EQU  H'0001'
EID10            EQU  H'0002'
EID11            EQU  H'0003'
EID12            EQU  H'0004'
EID13            EQU  H'0005'
EID14            EQU  H'0006'
EID15            EQU  H'0007'


;----- RXF14EIDL Bits -----------------------------------------------------
EID0             EQU  H'0000'
EID1             EQU  H'0001'
EID2             EQU  H'0002'
EID3             EQU  H'0003'
EID4             EQU  H'0004'
EID5             EQU  H'0005'
EID6             EQU  H'0006'
EID7             EQU  H'0007'


;----- RXF15SIDH Bits -----------------------------------------------------
SID3             EQU  H'0000'
SID4             EQU  H'0001'
SID5             EQU  H'0002'
SID6             EQU  H'0003'
SID7             EQU  H'0004'
SID8             EQU  H'0005'
SID9             EQU  H'0006'
SID10            EQU  H'0007'


;----- RXF15SIDL Bits -----------------------------------------------------
EXIDEN           EQU  H'0003'

EID16            EQU  H'0000'
EID17            EQU  H'0001'
SID0             EQU  H'0005'
SID1             EQU  H'0006'
SID2             EQU  H'0007'


;----- RXF15EIDH Bits -----------------------------------------------------
EID8             EQU  H'0000'
EID9             EQU  H'0001'
EID10            EQU  H'0002'
EID11            EQU  H'0003'
EID12            EQU  H'0004'
EID13            EQU  H'0005'
EID14            EQU  H'0006'
EID15            EQU  H'0007'


;----- RXF15EIDL Bits -----------------------------------------------------
EID0             EQU  H'0000'
EID1             EQU  H'0001'
EID2             EQU  H'0002'
EID3             EQU  H'0003'
EID4             EQU  H'0004'
EID5             EQU  H'0005'
EID6             EQU  H'0006'
EID7             EQU  H'0007'


;----- SDFLC Bits -----------------------------------------------------
FLC0             EQU  H'0000'
FLC1             EQU  H'0001'
FLC2             EQU  H'0002'
FLC3             EQU  H'0003'
FLC4             EQU  H'0004'


;----- RXFBCON0 Bits -----------------------------------------------------
F0BP_0           EQU  H'0000'
F0BP_1           EQU  H'0001'
F0BP_2           EQU  H'0002'
F0BP_3           EQU  H'0003'
F1BP_0           EQU  H'0004'
F1BP_1           EQU  H'0005'
F1BP_2           EQU  H'0006'
F1BP_3           EQU  H'0007'


;----- RXFBCON1 Bits -----------------------------------------------------
F2BP_0           EQU  H'0000'
F2BP_1           EQU  H'0001'
F2BP_2           EQU  H'0002'
F2BP_3           EQU  H'0003'
F3BP_0           EQU  H'0004'
F3BP_1           EQU  H'0005'
F3BP_2           EQU  H'0006'
F3BP_3           EQU  H'0007'


;----- RXFBCON2 Bits -----------------------------------------------------
F4BP_0           EQU  H'0000'
F4BP_1           EQU  H'0001'
F4BP_2           EQU  H'0002'
F4BP_3           EQU  H'0003'
F5BP_0           EQU  H'0004'
F5BP_1           EQU  H'0005'
F5BP_2           EQU  H'0006'
F5BP_3           EQU  H'0007'


;----- RXFBCON3 Bits -----------------------------------------------------
F6BP_0           EQU  H'0000'
F6BP_1           EQU  H'0001'
F6BP_2           EQU  H'0002'
F6BP_3           EQU  H'0003'
F7BP_0           EQU  H'0004'
F7BP_1           EQU  H'0005'
F7BP_2           EQU  H'0006'
F7BP_3           EQU  H'0007'


;----- RXFBCON4 Bits -----------------------------------------------------
F8BP_0           EQU  H'0000'
F8BP_1           EQU  H'0001'
F8BP_2           EQU  H'0002'
F8BP_3           EQU  H'0003'
F9BP_0           EQU  H'0004'
F9BP_1           EQU  H'0005'
F9BP_2           EQU  H'0006'
F9BP_3           EQU  H'0007'


;----- RXFBCON5 Bits -----------------------------------------------------
F10BP_0          EQU  H'0000'
F10BP_1          EQU  H'0001'
F10BP_2          EQU  H'0002'
F10BP_3          EQU  H'0003'
F11BP_0          EQU  H'0004'
F11BP_1          EQU  H'0005'
F11BP_2          EQU  H'0006'
F11BP_3          EQU  H'0007'


;----- RXFBCON6 Bits -----------------------------------------------------
F12BP_0          EQU  H'0000'
F12BP_1          EQU  H'0001'
F12BP_2          EQU  H'0002'
F12BP_3          EQU  H'0003'
F13BP_0          EQU  H'0004'
F13BP_1          EQU  H'0005'
F13BP_2          EQU  H'0006'
F13BP_3          EQU  H'0007'


;----- RXFBCON7 Bits -----------------------------------------------------
F14BP_0          EQU  H'0000'
F14BP_1          EQU  H'0001'
F14BP_2          EQU  H'0002'
F14BP_3          EQU  H'0003'
F15BP_0          EQU  H'0004'
F15BP_1          EQU  H'0005'
F15BP_2          EQU  H'0006'
F15BP_3          EQU  H'0007'


;----- MSEL0 Bits -----------------------------------------------------
FIL0_0           EQU  H'0000'
FIL0_1           EQU  H'0001'
FIL1_0           EQU  H'0002'
FIL1_1           EQU  H'0003'
FIL2_0           EQU  H'0004'
FIL2_1           EQU  H'0005'
FIL3_0           EQU  H'0006'
FIL3_1           EQU  H'0007'


;----- MSEL1 Bits -----------------------------------------------------
FIL4_0           EQU  H'0000'
FIL4_1           EQU  H'0001'
FIL5_0           EQU  H'0002'
FIL5_1           EQU  H'0003'
FIL6_0           EQU  H'0004'
FIL6_1           EQU  H'0005'
FIL7_0           EQU  H'0006'
FIL7_1           EQU  H'0007'


;----- MSEL2 Bits -----------------------------------------------------
FIL8_0           EQU  H'0000'
FIL8_1           EQU  H'0001'
FIL9_0           EQU  H'0002'
FIL9_1           EQU  H'0003'
FIL10_0          EQU  H'0004'
FIL10_1          EQU  H'0005'
FIL11_0          EQU  H'0006'
FIL11_1          EQU  H'0007'


;----- MSEL3 Bits -----------------------------------------------------
FIL12_0          EQU  H'0000'
FIL12_1          EQU  H'0001'
FIL13_0          EQU  H'0002'
FIL13_1          EQU  H'0003'
FIL14_0          EQU  H'0004'
FIL14_1          EQU  H'0005'
FIL15_0          EQU  H'0006'
FIL15_1          EQU  H'0007'


;----- BSEL0 Bits -----------------------------------------------------
B0TXEN           EQU  H'0002'
B1TXEN           EQU  H'0003'
B2TXEN           EQU  H'0004'
B3TXEN           EQU  H'0005'
B4TXEN           EQU  H'0006'
B5TXEN           EQU  H'0007'


;----- BIE0 Bits -----------------------------------------------------
RXB0IE           EQU  H'0000'
RXB1IE           EQU  H'0001'
B0IE             EQU  H'0002'
B1IE             EQU  H'0003'
B2IE             EQU  H'0004'
B3IE             EQU  H'0005'
B4IE             EQU  H'0006'
B5IE             EQU  H'0007'


;----- TXBIE Bits -----------------------------------------------------
TXB0IE           EQU  H'0002'
TXB1IE           EQU  H'0003'
TXB2IE           EQU  H'0004'


;----- B0CON Bits -----------------------------------------------------
FILHIT0_TXPRI0   EQU  H'0000'
FILHIT1_TXPRI1   EQU  H'0001'
FILHIT2_RTREN    EQU  H'0002'
FILHIT3_TXREQ    EQU  H'0003'
FILHIT4_TXERR    EQU  H'0004'
RXRTRRO_TXLARB   EQU  H'0005'
RXM1_TXABT       EQU  H'0006'
RXFUL_TXBIF      EQU  H'0007'

FILHIT0          EQU  H'0000'
FILHIT1          EQU  H'0001'
FILHIT2          EQU  H'0002'
FILHIT3          EQU  H'0003'
FILHIT4          EQU  H'0004'
RXRTRRO_B0CON    EQU  H'0005'
RXM1             EQU  H'0006'
RXFUL            EQU  H'0007'

TXPRI0           EQU  H'0000'
TXPRI1           EQU  H'0001'
RTREN            EQU  H'0002'
TXREQ            EQU  H'0003'
TXERR            EQU  H'0004'
TXLARB           EQU  H'0005'
TXABT            EQU  H'0006'
TXBIF            EQU  H'0007'


;----- B0SIDH Bits -----------------------------------------------------
SID3             EQU  H'0000'
SID4             EQU  H'0001'
SID5             EQU  H'0002'
SID6             EQU  H'0003'
SID7             EQU  H'0004'
SID8             EQU  H'0005'
SID9             EQU  H'0006'
SID10            EQU  H'0007'


;----- B0SIDL Bits -----------------------------------------------------
EXIDE            EQU  H'0003'
SRR              EQU  H'0004'

EID16            EQU  H'0000'
EID17            EQU  H'0001'
SID0             EQU  H'0005'
SID1             EQU  H'0006'
SID2             EQU  H'0007'


;----- B0EIDH Bits -----------------------------------------------------
EID8             EQU  H'0000'
EID9             EQU  H'0001'
EID10            EQU  H'0002'
EID11            EQU  H'0003'
EID12            EQU  H'0004'
EID13            EQU  H'0005'
EID14            EQU  H'0006'
EID15            EQU  H'0007'


;----- B0EIDL Bits -----------------------------------------------------
EID0             EQU  H'0000'
EID1             EQU  H'0001'
EID2             EQU  H'0002'
EID3             EQU  H'0003'
EID4             EQU  H'0004'
EID5             EQU  H'0005'
EID6             EQU  H'0006'
EID7             EQU  H'0007'


;----- B0DLC Bits -----------------------------------------------------
RXRTR_TXRTR      EQU  H'0006'

DLC0             EQU  H'0000'
DLC1             EQU  H'0001'
DLC2             EQU  H'0002'
DLC3             EQU  H'0003'
RB0_B0DLC        EQU  H'0004'
RB1_B0DLC        EQU  H'0005'
RXRTR            EQU  H'0006'

TXRTR            EQU  H'0006'


;----- B0D0 Bits -----------------------------------------------------
B0D00            EQU  H'0000'
B0D01            EQU  H'0001'
B0D02            EQU  H'0002'
B0D03            EQU  H'0003'
B0D04            EQU  H'0004'
B0D05            EQU  H'0005'
B0D06            EQU  H'0006'
B0D07            EQU  H'0007'


;----- B0D1 Bits -----------------------------------------------------
B0D10            EQU  H'0000'
B0D11            EQU  H'0001'
B0D12            EQU  H'0002'
B0D13            EQU  H'0003'
B0D14            EQU  H'0004'
B0D15            EQU  H'0005'
B0D16            EQU  H'0006'
B0D17            EQU  H'0007'


;----- B0D2 Bits -----------------------------------------------------
B0D20            EQU  H'0000'
B0D21            EQU  H'0001'
B0D22            EQU  H'0002'
B0D23            EQU  H'0003'
B0D24            EQU  H'0004'
B0D25            EQU  H'0005'
B0D26            EQU  H'0006'
B0D27            EQU  H'0007'


;----- B0D3 Bits -----------------------------------------------------
B0D30            EQU  H'0000'
B0D31            EQU  H'0001'
B0D32            EQU  H'0002'
B0D33            EQU  H'0003'
B0D34            EQU  H'0004'
B0D35            EQU  H'0005'
B0D36            EQU  H'0006'
B0D37            EQU  H'0007'


;----- B0D4 Bits -----------------------------------------------------
B0D40            EQU  H'0000'
B0D41            EQU  H'0001'
B0D42            EQU  H'0002'
B0D43            EQU  H'0003'
B0D44            EQU  H'0004'
B0D45            EQU  H'0005'
B0D46            EQU  H'0006'
B0D47            EQU  H'0007'


;----- B0D5 Bits -----------------------------------------------------
B0D50            EQU  H'0000'
B0D51            EQU  H'0001'
B0D52            EQU  H'0002'
B0D53            EQU  H'0003'
B0D54            EQU  H'0004'
B0D55            EQU  H'0005'
B0D56            EQU  H'0006'
B0D57            EQU  H'0007'


;----- B0D6 Bits -----------------------------------------------------
B0D60            EQU  H'0000'
B0D61            EQU  H'0001'
B0D62            EQU  H'0002'
B0D63            EQU  H'0003'
B0D64            EQU  H'0004'
B0D65            EQU  H'0005'
B0D66            EQU  H'0006'
B0D67            EQU  H'0007'


;----- B0D7 Bits -----------------------------------------------------
B0D70            EQU  H'0000'
B0D71            EQU  H'0001'
B0D72            EQU  H'0002'
B0D73            EQU  H'0003'
B0D74            EQU  H'0004'
B0D75            EQU  H'0005'
B0D76            EQU  H'0006'
B0D77            EQU  H'0007'


;----- CANSTAT_RO9 Bits -----------------------------------------------------
EICODE0          EQU  H'0000'
EICODE1_ICODE0   EQU  H'0001'
EICODE2_ICODE1   EQU  H'0002'
EICODE3_ICODE2   EQU  H'0003'
EICODE4          EQU  H'0004'

EICODE1          EQU  H'0001'
EICODE2          EQU  H'0002'
EICODE3          EQU  H'0003'
OPMODE0          EQU  H'0005'
OPMODE1          EQU  H'0006'
OPMODE2          EQU  H'0007'

ICODE0           EQU  H'0001'
ICODE1           EQU  H'0002'
ICODE2           EQU  H'0003'


;----- CANCON_RO9 Bits -----------------------------------------------------
FP0              EQU  H'0000'
WIN0_FP1         EQU  H'0001'
WIN1_FP2         EQU  H'0002'
WIN2_FP3         EQU  H'0003'
ABAT             EQU  H'0004'

WIN0             EQU  H'0001'
WIN1             EQU  H'0002'
WIN2             EQU  H'0003'

FP1              EQU  H'0001'
FP2              EQU  H'0002'
FP3              EQU  H'0003'


;----- B1CON Bits -----------------------------------------------------
FILHIT0_TXPRI0   EQU  H'0000'
FILHIT1_TXPRI1   EQU  H'0001'
FILHIT2_RTREN    EQU  H'0002'
FILHIT3_TXREQ    EQU  H'0003'
FILHIT4_TXERR    EQU  H'0004'
RXRTRRO_TXLARB   EQU  H'0005'
RXM1_TXABT       EQU  H'0006'
RXFUL_TXBIF      EQU  H'0007'

FILHIT0          EQU  H'0000'
FILHIT1          EQU  H'0001'
FILHIT2          EQU  H'0002'
FILHIT3          EQU  H'0003'
FILHIT4          EQU  H'0004'
RXRTRRO_B1CON    EQU  H'0005'
RXM1             EQU  H'0006'
RXFUL            EQU  H'0007'

TXPRI0           EQU  H'0000'
TXPRI1           EQU  H'0001'
RTREN            EQU  H'0002'
TXREQ            EQU  H'0003'
TXERR            EQU  H'0004'
TXLARB           EQU  H'0005'
TXABT            EQU  H'0006'
TXBIF            EQU  H'0007'


;----- B1SIDH Bits -----------------------------------------------------
SID3             EQU  H'0000'
SID4             EQU  H'0001'
SID5             EQU  H'0002'
SID6             EQU  H'0003'
SID7             EQU  H'0004'
SID8             EQU  H'0005'
SID9             EQU  H'0006'
SID10            EQU  H'0007'


;----- B1SIDL Bits -----------------------------------------------------
EXIDE            EQU  H'0003'
SRR              EQU  H'0004'

EID16            EQU  H'0000'
EID17            EQU  H'0001'
SID0             EQU  H'0005'
SID1             EQU  H'0006'
SID2             EQU  H'0007'


;----- B1EIDH Bits -----------------------------------------------------
EID8             EQU  H'0000'
EID9             EQU  H'0001'
EID10            EQU  H'0002'
EID11            EQU  H'0003'
EID12            EQU  H'0004'
EID13            EQU  H'0005'
EID14            EQU  H'0006'
EID15            EQU  H'0007'


;----- B1EIDL Bits -----------------------------------------------------
EID0             EQU  H'0000'
EID1             EQU  H'0001'
EID2             EQU  H'0002'
EID3             EQU  H'0003'
EID4             EQU  H'0004'
EID5             EQU  H'0005'
EID6             EQU  H'0006'
EID7             EQU  H'0007'


;----- B1DLC Bits -----------------------------------------------------
RXRTR_TXRTR      EQU  H'0006'

DLC0             EQU  H'0000'
DLC1             EQU  H'0001'
DLC2             EQU  H'0002'
DLC3             EQU  H'0003'
RB0_B1DLC        EQU  H'0004'
RB1_B1DLC        EQU  H'0005'
RXRTR            EQU  H'0006'

TXRTR            EQU  H'0006'


;----- B1D0 Bits -----------------------------------------------------
B1D00            EQU  H'0000'
B1D01            EQU  H'0001'
B1D02            EQU  H'0002'
B1D03            EQU  H'0003'
B1D04            EQU  H'0004'
B1D05            EQU  H'0005'
B1D06            EQU  H'0006'
B1D07            EQU  H'0007'


;----- B1D1 Bits -----------------------------------------------------
B1D10            EQU  H'0000'
B1D11            EQU  H'0001'
B1D12            EQU  H'0002'
B1D13            EQU  H'0003'
B1D14            EQU  H'0004'
B1D15            EQU  H'0005'
B1D16            EQU  H'0006'
B1D17            EQU  H'0007'


;----- B1D2 Bits -----------------------------------------------------
B1D20            EQU  H'0000'
B1D21            EQU  H'0001'
B1D22            EQU  H'0002'
B1D23            EQU  H'0003'
B1D24            EQU  H'0004'
B1D25            EQU  H'0005'
B1D26            EQU  H'0006'
B1D27            EQU  H'0007'


;----- B1D3 Bits -----------------------------------------------------
B1D30            EQU  H'0000'
B1D31            EQU  H'0001'
B1D32            EQU  H'0002'
B1D33            EQU  H'0003'
B1D34            EQU  H'0004'
B1D35            EQU  H'0005'
B1D36            EQU  H'0006'
B1D37            EQU  H'0007'


;----- B1D4 Bits -----------------------------------------------------
B1D40            EQU  H'0000'
B1D41            EQU  H'0001'
B1D42            EQU  H'0002'
B1D43            EQU  H'0003'
B1D44            EQU  H'0004'
B1D45            EQU  H'0005'
B1D46            EQU  H'0006'
B1D47            EQU  H'0007'


;----- B1D5 Bits -----------------------------------------------------
B1D50            EQU  H'0000'
B1D51            EQU  H'0001'
B1D52            EQU  H'0002'
B1D53            EQU  H'0003'
B1D54            EQU  H'0004'
B1D55            EQU  H'0005'
B1D56            EQU  H'0006'
B1D57            EQU  H'0007'


;----- B1D6 Bits -----------------------------------------------------
B1D60            EQU  H'0000'
B1D61            EQU  H'0001'
B1D62            EQU  H'0002'
B1D63            EQU  H'0003'
B1D64            EQU  H'0004'
B1D65            EQU  H'0005'
B1D66            EQU  H'0006'
B1D67            EQU  H'0007'


;----- B1D7 Bits -----------------------------------------------------
B1D70            EQU  H'0000'
B1D71            EQU  H'0001'
B1D72            EQU  H'0002'
B1D73            EQU  H'0003'
B1D74            EQU  H'0004'
B1D75            EQU  H'0005'
B1D76            EQU  H'0006'
B1D77            EQU  H'0007'


;----- CANSTAT_RO8 Bits -----------------------------------------------------
EICODE0          EQU  H'0000'
EICODE1_ICODE0   EQU  H'0001'
EICODE2_ICODE1   EQU  H'0002'
EICODE3_ICODE2   EQU  H'0003'
EICODE4          EQU  H'0004'

EICODE1          EQU  H'0001'
EICODE2          EQU  H'0002'
EICODE3          EQU  H'0003'
OPMODE0          EQU  H'0005'
OPMODE1          EQU  H'0006'
OPMODE2          EQU  H'0007'

ICODE0           EQU  H'0001'
ICODE1           EQU  H'0002'
ICODE2           EQU  H'0003'


;----- CANCON_RO8 Bits -----------------------------------------------------
FP0              EQU  H'0000'
WIN0_FP1         EQU  H'0001'
WIN1_FP2         EQU  H'0002'
WIN2_FP3         EQU  H'0003'
ABAT             EQU  H'0004'

WIN0             EQU  H'0001'
WIN1             EQU  H'0002'
WIN2             EQU  H'0003'

FP1              EQU  H'0001'
FP2              EQU  H'0002'
FP3              EQU  H'0003'


;----- B2CON Bits -----------------------------------------------------
FILHIT0_TXPRI0   EQU  H'0000'
FILHIT1_TXPRI1   EQU  H'0001'
FILHIT2_RTREN    EQU  H'0002'
FILHIT3_TXREQ    EQU  H'0003'
FILHIT4_TXERR    EQU  H'0004'
RXRTRRO_TXLARB   EQU  H'0005'
RXM1_TXABT       EQU  H'0006'
RXFUL_TXBIF      EQU  H'0007'

FILHIT0          EQU  H'0000'
FILHIT1          EQU  H'0001'
FILHIT2          EQU  H'0002'
FILHIT3          EQU  H'0003'
FILHIT4          EQU  H'0004'
RXRTRRO_B2CON    EQU  H'0005'
RXM1             EQU  H'0006'
RXFUL            EQU  H'0007'

TXPRI0           EQU  H'0000'
TXPRI1           EQU  H'0001'
RTREN            EQU  H'0002'
TXREQ            EQU  H'0003'
TXERR            EQU  H'0004'
TXLARB           EQU  H'0005'
TXABT            EQU  H'0006'
TXBIF            EQU  H'0007'


;----- B2SIDH Bits -----------------------------------------------------
SID3             EQU  H'0000'
SID4             EQU  H'0001'
SID5             EQU  H'0002'
SID6             EQU  H'0003'
SID7             EQU  H'0004'
SID8             EQU  H'0005'
SID9             EQU  H'0006'
SID10            EQU  H'0007'


;----- B2SIDL Bits -----------------------------------------------------
EXIDE            EQU  H'0003'
SRR              EQU  H'0004'

EID16            EQU  H'0000'
EID17            EQU  H'0001'
SID0             EQU  H'0005'
SID1             EQU  H'0006'
SID2             EQU  H'0007'


;----- B2EIDH Bits -----------------------------------------------------
EID8             EQU  H'0000'
EID9             EQU  H'0001'
EID10            EQU  H'0002'
EID11            EQU  H'0003'
EID12            EQU  H'0004'
EID13            EQU  H'0005'
EID14            EQU  H'0006'
EID15            EQU  H'0007'


;----- B2EIDL Bits -----------------------------------------------------
EID0             EQU  H'0000'
EID1             EQU  H'0001'
EID2             EQU  H'0002'
EID3             EQU  H'0003'
EID4             EQU  H'0004'
EID5             EQU  H'0005'
EID6             EQU  H'0006'
EID7             EQU  H'0007'


;----- B2DLC Bits -----------------------------------------------------
RXRTR_TXRTR      EQU  H'0006'

DLC0             EQU  H'0000'
DLC1             EQU  H'0001'
DLC2             EQU  H'0002'
DLC3             EQU  H'0003'
RB0_B2DLC        EQU  H'0004'
RB1_B2DLC        EQU  H'0005'
RXRTR            EQU  H'0006'

TXRTR            EQU  H'0006'


;----- B2D0 Bits -----------------------------------------------------
B2D00            EQU  H'0000'
B2D01            EQU  H'0001'
B2D02            EQU  H'0002'
B2D03            EQU  H'0003'
B2D04            EQU  H'0004'
B2D05            EQU  H'0005'
B2D06            EQU  H'0006'
B2D07            EQU  H'0007'


;----- B2D1 Bits -----------------------------------------------------
B2D10            EQU  H'0000'
B2D11            EQU  H'0001'
B2D12            EQU  H'0002'
B2D13            EQU  H'0003'
B2D14            EQU  H'0004'
B2D15            EQU  H'0005'
B2D16            EQU  H'0006'
B2D17            EQU  H'0007'


;----- B2D2 Bits -----------------------------------------------------
B2D20            EQU  H'0000'
B2D21            EQU  H'0001'
B2D22            EQU  H'0002'
B2D23            EQU  H'0003'
B2D24            EQU  H'0004'
B2D25            EQU  H'0005'
B2D26            EQU  H'0006'
B2D27            EQU  H'0007'


;----- B2D3 Bits -----------------------------------------------------
B2D30            EQU  H'0000'
B2D31            EQU  H'0001'
B2D32            EQU  H'0002'
B2D33            EQU  H'0003'
B2D34            EQU  H'0004'
B2D35            EQU  H'0005'
B2D36            EQU  H'0006'
B2D37            EQU  H'0007'


;----- B2D4 Bits -----------------------------------------------------
B2D40            EQU  H'0000'
B2D41            EQU  H'0001'
B2D42            EQU  H'0002'
B2D43            EQU  H'0003'
B2D44            EQU  H'0004'
B2D45            EQU  H'0005'
B2D46            EQU  H'0006'
B2D47            EQU  H'0007'


;----- B2D5 Bits -----------------------------------------------------
B2D50            EQU  H'0000'
B2D51            EQU  H'0001'
B2D52            EQU  H'0002'
B2D53            EQU  H'0003'
B2D54            EQU  H'0004'
B2D55            EQU  H'0005'
B2D56            EQU  H'0006'
B2D57            EQU  H'0007'


;----- B2D6 Bits -----------------------------------------------------
B2D60            EQU  H'0000'
B2D61            EQU  H'0001'
B2D62            EQU  H'0002'
B2D63            EQU  H'0003'
B2D64            EQU  H'0004'
B2D65            EQU  H'0005'
B2D66            EQU  H'0006'
B2D67            EQU  H'0007'


;----- B2D7 Bits -----------------------------------------------------
B2D70            EQU  H'0000'
B2D71            EQU  H'0001'
B2D72            EQU  H'0002'
B2D73            EQU  H'0003'
B2D74            EQU  H'0004'
B2D75            EQU  H'0005'
B2D76            EQU  H'0006'
B2D77            EQU  H'0007'


;----- CANSTAT_RO7 Bits -----------------------------------------------------
EICODE0          EQU  H'0000'
EICODE1_ICODE0   EQU  H'0001'
EICODE2_ICODE1   EQU  H'0002'
EICODE3_ICODE2   EQU  H'0003'
EICODE4          EQU  H'0004'

EICODE1          EQU  H'0001'
EICODE2          EQU  H'0002'
EICODE3          EQU  H'0003'
OPMODE0          EQU  H'0005'
OPMODE1          EQU  H'0006'
OPMODE2          EQU  H'0007'

ICODE0           EQU  H'0001'
ICODE1           EQU  H'0002'
ICODE2           EQU  H'0003'


;----- CANCON_RO7 Bits -----------------------------------------------------
FP0              EQU  H'0000'
WIN0_FP1         EQU  H'0001'
WIN1_FP2         EQU  H'0002'
WIN2_FP3         EQU  H'0003'
ABAT             EQU  H'0004'

WIN0             EQU  H'0001'
WIN1             EQU  H'0002'
WIN2             EQU  H'0003'

FP1              EQU  H'0001'
FP2              EQU  H'0002'
FP3              EQU  H'0003'


;----- B3CON Bits -----------------------------------------------------
FILHIT0_TXPRI0   EQU  H'0000'
FILHIT1_TXPRI1   EQU  H'0001'
FILHIT2_RTREN    EQU  H'0002'
FILHIT3_TXREQ    EQU  H'0003'
FILHIT4_TXERR    EQU  H'0004'
RXRTRRO_TXLARB   EQU  H'0005'
RXM1_TXABT       EQU  H'0006'
RXFUL_TXBIF      EQU  H'0007'

FILHIT0          EQU  H'0000'
FILHIT1          EQU  H'0001'
FILHIT2          EQU  H'0002'
FILHIT3          EQU  H'0003'
FILHIT4          EQU  H'0004'
RXRTRRO_B3CON    EQU  H'0005'
RXM1             EQU  H'0006'
RXFUL            EQU  H'0007'

TXPRI0           EQU  H'0000'
TXPRI1           EQU  H'0001'
RTREN            EQU  H'0002'
TXREQ            EQU  H'0003'
TXERR            EQU  H'0004'
TXLARB           EQU  H'0005'
TXABT            EQU  H'0006'
TXBIF            EQU  H'0007'


;----- B3SIDH Bits -----------------------------------------------------
SID3             EQU  H'0000'
SID4             EQU  H'0001'
SID5             EQU  H'0002'
SID6             EQU  H'0003'
SID7             EQU  H'0004'
SID8             EQU  H'0005'
SID9             EQU  H'0006'
SID10            EQU  H'0007'


;----- B3SIDL Bits -----------------------------------------------------
EXIDE            EQU  H'0003'
SRR              EQU  H'0004'

EID16            EQU  H'0000'
EID17            EQU  H'0001'
SID0             EQU  H'0005'
SID1             EQU  H'0006'
SID2             EQU  H'0007'


;----- B3EIDH Bits -----------------------------------------------------
EID8             EQU  H'0000'
EID9             EQU  H'0001'
EID10            EQU  H'0002'
EID11            EQU  H'0003'
EID12            EQU  H'0004'
EID13            EQU  H'0005'
EID14            EQU  H'0006'
EID15            EQU  H'0007'


;----- B3EIDL Bits -----------------------------------------------------
EID0             EQU  H'0000'
EID1             EQU  H'0001'
EID2             EQU  H'0002'
EID3             EQU  H'0003'
EID4             EQU  H'0004'
EID5             EQU  H'0005'
EID6             EQU  H'0006'
EID7             EQU  H'0007'


;----- B3DLC Bits -----------------------------------------------------
RXRTR_TXRTR      EQU  H'0006'

DLC0             EQU  H'0000'
DLC1             EQU  H'0001'
DLC2             EQU  H'0002'
DLC3             EQU  H'0003'
RB0_B3DLC        EQU  H'0004'
RB1_B3DLC        EQU  H'0005'
RXRTR            EQU  H'0006'

TXRTR            EQU  H'0006'


;----- B3D0 Bits -----------------------------------------------------
B3D00            EQU  H'0000'
B3D01            EQU  H'0001'
B3D02            EQU  H'0002'
B3D03            EQU  H'0003'
B3D04            EQU  H'0004'
B3D05            EQU  H'0005'
B3D06            EQU  H'0006'
B3D07            EQU  H'0007'


;----- B3D1 Bits -----------------------------------------------------
B3D10            EQU  H'0000'
B3D11            EQU  H'0001'
B3D12            EQU  H'0002'
B3D13            EQU  H'0003'
B3D14            EQU  H'0004'
B3D15            EQU  H'0005'
B3D16            EQU  H'0006'
B3D17            EQU  H'0007'


;----- B3D2 Bits -----------------------------------------------------
B3D20            EQU  H'0000'
B3D21            EQU  H'0001'
B3D22            EQU  H'0002'
B3D23            EQU  H'0003'
B3D24            EQU  H'0004'
B3D25            EQU  H'0005'
B3D26            EQU  H'0006'
B3D27            EQU  H'0007'


;----- B3D3 Bits -----------------------------------------------------
B3D30            EQU  H'0000'
B3D31            EQU  H'0001'
B3D32            EQU  H'0002'
B3D33            EQU  H'0003'
B3D34            EQU  H'0004'
B3D35            EQU  H'0005'
B3D36            EQU  H'0006'
B3D37            EQU  H'0007'


;----- B3D4 Bits -----------------------------------------------------
B3D40            EQU  H'0000'
B3D41            EQU  H'0001'
B3D42            EQU  H'0002'
B3D43            EQU  H'0003'
B3D44            EQU  H'0004'
B3D45            EQU  H'0005'
B3D46            EQU  H'0006'
B3D47            EQU  H'0007'


;----- B3D5 Bits -----------------------------------------------------
B3D50            EQU  H'0000'
B3D51            EQU  H'0001'
B3D52            EQU  H'0002'
B3D53            EQU  H'0003'
B3D54            EQU  H'0004'
B3D55            EQU  H'0005'
B3D56            EQU  H'0006'
B3D57            EQU  H'0007'


;----- B3D6 Bits -----------------------------------------------------
B3D60            EQU  H'0000'
B3D61            EQU  H'0001'
B3D62            EQU  H'0002'
B3D63            EQU  H'0003'
B3D64            EQU  H'0004'
B3D65            EQU  H'0005'
B3D66            EQU  H'0006'
B3D67            EQU  H'0007'


;----- B3D7 Bits -----------------------------------------------------
B3D70            EQU  H'0000'
B3D71            EQU  H'0001'
B3D72            EQU  H'0002'
B3D73            EQU  H'0003'
B3D74            EQU  H'0004'
B3D75            EQU  H'0005'
B3D76            EQU  H'0006'
B3D77            EQU  H'0007'


;----- CANSTAT_RO6 Bits -----------------------------------------------------
EICODE0          EQU  H'0000'
EICODE1_ICODE0   EQU  H'0001'
EICODE2_ICODE1   EQU  H'0002'
EICODE3_ICODE2   EQU  H'0003'
EICODE4          EQU  H'0004'

EICODE1          EQU  H'0001'
EICODE2          EQU  H'0002'
EICODE3          EQU  H'0003'
OPMODE0          EQU  H'0005'
OPMODE1          EQU  H'0006'
OPMODE2          EQU  H'0007'

ICODE0           EQU  H'0001'
ICODE1           EQU  H'0002'
ICODE2           EQU  H'0003'


;----- CANCON_RO6 Bits -----------------------------------------------------
FP0              EQU  H'0000'
WIN0_FP1         EQU  H'0001'
WIN1_FP2         EQU  H'0002'
WIN2_FP3         EQU  H'0003'
ABAT             EQU  H'0004'

WIN0             EQU  H'0001'
WIN1             EQU  H'0002'
WIN2             EQU  H'0003'

FP1              EQU  H'0001'
FP2              EQU  H'0002'
FP3              EQU  H'0003'


;----- B4CON Bits -----------------------------------------------------
FILHIT0_TXPRI0   EQU  H'0000'
FILHIT1_TXPRI1   EQU  H'0001'
FILHIT2_RTREN    EQU  H'0002'
FILHIT3_TXREQ    EQU  H'0003'
FILHIT4_TXERR    EQU  H'0004'
RXRTRRO_TXLARB   EQU  H'0005'
RXM1_TXABT       EQU  H'0006'
RXFUL_TXBIF      EQU  H'0007'

FILHIT0          EQU  H'0000'
FILHIT1          EQU  H'0001'
FILHIT2          EQU  H'0002'
FILHIT3          EQU  H'0003'
FILHIT4          EQU  H'0004'
RXRTRRO_B4CON    EQU  H'0005'
RXM1             EQU  H'0006'
RXFUL            EQU  H'0007'

TXPRI0           EQU  H'0000'
TXPRI1           EQU  H'0001'
RTREN            EQU  H'0002'
TXREQ            EQU  H'0003'
TXERR            EQU  H'0004'
TXLARB           EQU  H'0005'
TXABT            EQU  H'0006'
TXBIF            EQU  H'0007'


;----- B4SIDH Bits -----------------------------------------------------
SID3             EQU  H'0000'
SID4             EQU  H'0001'
SID5             EQU  H'0002'
SID6             EQU  H'0003'
SID7             EQU  H'0004'
SID8             EQU  H'0005'
SID9             EQU  H'0006'
SID10            EQU  H'0007'


;----- B4SIDL Bits -----------------------------------------------------
EXIDE            EQU  H'0003'
SRR              EQU  H'0004'

EID16            EQU  H'0000'
EID17            EQU  H'0001'
SID0             EQU  H'0005'
SID1             EQU  H'0006'
SID2             EQU  H'0007'


;----- B4EIDH Bits -----------------------------------------------------
EID8             EQU  H'0000'
EID9             EQU  H'0001'
EID10            EQU  H'0002'
EID11            EQU  H'0003'
EID12            EQU  H'0004'
EID13            EQU  H'0005'
EID14            EQU  H'0006'
EID15            EQU  H'0007'


;----- B4EIDL Bits -----------------------------------------------------
EID0             EQU  H'0000'
EID1             EQU  H'0001'
EID2             EQU  H'0002'
EID3             EQU  H'0003'
EID4             EQU  H'0004'
EID5             EQU  H'0005'
EID6             EQU  H'0006'
EID7             EQU  H'0007'


;----- B4DLC Bits -----------------------------------------------------
RXRTR_TXRTR      EQU  H'0006'

DLC0             EQU  H'0000'
DLC1             EQU  H'0001'
DLC2             EQU  H'0002'
DLC3             EQU  H'0003'
RB0_B4DLC        EQU  H'0004'
RB1_B4DLC        EQU  H'0005'
RXRTR            EQU  H'0006'

TXRTR            EQU  H'0006'


;----- B4D0 Bits -----------------------------------------------------
B4D00            EQU  H'0000'
B4D01            EQU  H'0001'
B4D02            EQU  H'0002'
B4D03            EQU  H'0003'
B4D04            EQU  H'0004'
B4D05            EQU  H'0005'
B4D06            EQU  H'0006'
B4D07            EQU  H'0007'


;----- B4D1 Bits -----------------------------------------------------
B4D10            EQU  H'0000'
B4D11            EQU  H'0001'
B4D12            EQU  H'0002'
B4D13            EQU  H'0003'
B4D14            EQU  H'0004'
B4D15            EQU  H'0005'
B4D16            EQU  H'0006'
B4D17            EQU  H'0007'


;----- B4D2 Bits -----------------------------------------------------
B4D20            EQU  H'0000'
B4D21            EQU  H'0001'
B4D22            EQU  H'0002'
B4D23            EQU  H'0003'
B4D24            EQU  H'0004'
B4D25            EQU  H'0005'
B4D26            EQU  H'0006'
B4D27            EQU  H'0007'


;----- B4D3 Bits -----------------------------------------------------
B4D30            EQU  H'0000'
B4D31            EQU  H'0001'
B4D32            EQU  H'0002'
B4D33            EQU  H'0003'
B4D34            EQU  H'0004'
B4D35            EQU  H'0005'
B4D36            EQU  H'0006'
B4D37            EQU  H'0007'


;----- B4D4 Bits -----------------------------------------------------
B4D40            EQU  H'0000'
B4D41            EQU  H'0001'
B4D42            EQU  H'0002'
B4D43            EQU  H'0003'
B4D44            EQU  H'0004'
B4D45            EQU  H'0005'
B4D46            EQU  H'0006'
B4D47            EQU  H'0007'


;----- B4D5 Bits -----------------------------------------------------
B4D50            EQU  H'0000'
B4D51            EQU  H'0001'
B4D52            EQU  H'0002'
B4D53            EQU  H'0003'
B4D54            EQU  H'0004'
B4D55            EQU  H'0005'
B4D56            EQU  H'0006'
B4D57            EQU  H'0007'


;----- B4D6 Bits -----------------------------------------------------
B4D60            EQU  H'0000'
B4D61            EQU  H'0001'
B4D62            EQU  H'0002'
B4D63            EQU  H'0003'
B4D64            EQU  H'0004'
B4D65            EQU  H'0005'
B4D66            EQU  H'0006'
B4D67            EQU  H'0007'


;----- B4D7 Bits -----------------------------------------------------
B4D70            EQU  H'0000'
B4D71            EQU  H'0001'
B4D72            EQU  H'0002'
B4D73            EQU  H'0003'
B4D74            EQU  H'0004'
B4D75            EQU  H'0005'
B4D76            EQU  H'0006'
B4D77            EQU  H'0007'


;----- CANSTAT_RO5 Bits -----------------------------------------------------
EICODE0          EQU  H'0000'
EICODE1_ICODE0   EQU  H'0001'
EICODE2_ICODE1   EQU  H'0002'
EICODE3_ICODE2   EQU  H'0003'
EICODE4          EQU  H'0004'

EICODE1          EQU  H'0001'
EICODE2          EQU  H'0002'
EICODE3          EQU  H'0003'
OPMODE0          EQU  H'0005'
OPMODE1          EQU  H'0006'
OPMODE2          EQU  H'0007'

ICODE0           EQU  H'0001'
ICODE1           EQU  H'0002'
ICODE2           EQU  H'0003'


;----- CANCON_RO5 Bits -----------------------------------------------------
FP0              EQU  H'0000'
WIN0_FP1         EQU  H'0001'
WIN1_FP2         EQU  H'0002'
WIN2_FP3         EQU  H'0003'
ABAT             EQU  H'0004'

WIN0             EQU  H'0001'
WIN1             EQU  H'0002'
WIN2             EQU  H'0003'

FP1              EQU  H'0001'
FP2              EQU  H'0002'
FP3              EQU  H'0003'


;----- B5CON Bits -----------------------------------------------------
FILHIT0_TXPRI0   EQU  H'0000'
FILHIT1_TXPRI1   EQU  H'0001'
FILHIT2_RTREN    EQU  H'0002'
FILHIT3_TXREQ    EQU  H'0003'
FILHIT4_TXERR    EQU  H'0004'
RXRTRRO_TXLARB   EQU  H'0005'
RXM1_TXABT       EQU  H'0006'
RXFUL_TXBIF      EQU  H'0007'

FILHIT0          EQU  H'0000'
FILHIT1          EQU  H'0001'
FILHIT2          EQU  H'0002'
FILHIT3          EQU  H'0003'
FILHIT4          EQU  H'0004'
RXRTRRO_B5CON    EQU  H'0005'
RXM1             EQU  H'0006'
RXFUL            EQU  H'0007'

TXPRI0           EQU  H'0000'
TXPRI1           EQU  H'0001'
RTREN            EQU  H'0002'
TXREQ            EQU  H'0003'
TXERR            EQU  H'0004'
TXLARB           EQU  H'0005'
TXABT            EQU  H'0006'
TXBIF            EQU  H'0007'


;----- B5SIDH Bits -----------------------------------------------------
SID3             EQU  H'0000'
SID4             EQU  H'0001'
SID5             EQU  H'0002'
SID6             EQU  H'0003'
SID7             EQU  H'0004'
SID8             EQU  H'0005'
SID9             EQU  H'0006'
SID10            EQU  H'0007'


;----- B5SIDL Bits -----------------------------------------------------
EXIDE            EQU  H'0003'
SRR              EQU  H'0004'

EID16            EQU  H'0000'
EID17            EQU  H'0001'
SID0             EQU  H'0005'
SID1             EQU  H'0006'
SID2             EQU  H'0007'


;----- B5EIDH Bits -----------------------------------------------------
EID8             EQU  H'0000'
EID9             EQU  H'0001'
EID10            EQU  H'0002'
EID11            EQU  H'0003'
EID12            EQU  H'0004'
EID13            EQU  H'0005'
EID14            EQU  H'0006'
EID15            EQU  H'0007'


;----- B5EIDL Bits -----------------------------------------------------
EID0             EQU  H'0000'
EID1             EQU  H'0001'
EID2             EQU  H'0002'
EID3             EQU  H'0003'
EID4             EQU  H'0004'
EID5             EQU  H'0005'
EID6             EQU  H'0006'
EID7             EQU  H'0007'


;----- B5DLC Bits -----------------------------------------------------
RXRTR_TXRTR      EQU  H'0006'

DLC0             EQU  H'0000'
DLC1             EQU  H'0001'
DLC2             EQU  H'0002'
DLC3             EQU  H'0003'
RB0_B5DLC        EQU  H'0004'
RB1_B5DLC        EQU  H'0005'
RXRTR            EQU  H'0006'

TXRTR            EQU  H'0006'


;----- B5D0 Bits -----------------------------------------------------
B5D00            EQU  H'0000'
B5D01            EQU  H'0001'
B5D02            EQU  H'0002'
B5D03            EQU  H'0003'
B5D04            EQU  H'0004'
B5D05            EQU  H'0005'
B5D06            EQU  H'0006'
B5D07            EQU  H'0007'


;----- B5D1 Bits -----------------------------------------------------
B5D10            EQU  H'0000'
B5D11            EQU  H'0001'
B5D12            EQU  H'0002'
B5D13            EQU  H'0003'
B5D14            EQU  H'0004'
B5D15            EQU  H'0005'
B5D16            EQU  H'0006'
B5D17            EQU  H'0007'


;----- B5D2 Bits -----------------------------------------------------
B5D20            EQU  H'0000'
B5D21            EQU  H'0001'
B5D22            EQU  H'0002'
B5D23            EQU  H'0003'
B5D24            EQU  H'0004'
B5D25            EQU  H'0005'
B5D26            EQU  H'0006'
B5D27            EQU  H'0007'


;----- B5D3 Bits -----------------------------------------------------
B5D30            EQU  H'0000'
B5D31            EQU  H'0001'
B5D32            EQU  H'0002'
B5D33            EQU  H'0003'
B5D34            EQU  H'0004'
B5D35            EQU  H'0005'
B5D36            EQU  H'0006'
B5D37            EQU  H'0007'


;----- B5D4 Bits -----------------------------------------------------
B5D40            EQU  H'0000'
B5D41            EQU  H'0001'
B5D42            EQU  H'0002'
B5D43            EQU  H'0003'
B5D44            EQU  H'0004'
B5D45            EQU  H'0005'
B5D46            EQU  H'0006'
B5D47            EQU  H'0007'


;----- B5D5 Bits -----------------------------------------------------
B5D50            EQU  H'0000'
B5D51            EQU  H'0001'
B5D52            EQU  H'0002'
B5D53            EQU  H'0003'
B5D54            EQU  H'0004'
B5D55            EQU  H'0005'
B5D56            EQU  H'0006'
B5D57            EQU  H'0007'


;----- B5D6 Bits -----------------------------------------------------
B5D60            EQU  H'0000'
B5D61            EQU  H'0001'
B5D62            EQU  H'0002'
B5D63            EQU  H'0003'
B5D64            EQU  H'0004'
B5D65            EQU  H'0005'
B5D66            EQU  H'0006'
B5D67            EQU  H'0007'


;----- B5D7 Bits -----------------------------------------------------
B5D70            EQU  H'0000'
B5D71            EQU  H'0001'
B5D72            EQU  H'0002'
B5D73            EQU  H'0003'
B5D74            EQU  H'0004'
B5D75            EQU  H'0005'
B5D76            EQU  H'0006'
B5D77            EQU  H'0007'


;----- CANSTAT_RO4 Bits -----------------------------------------------------
EICODE0          EQU  H'0000'
EICODE1_ICODE0   EQU  H'0001'
EICODE2_ICODE1   EQU  H'0002'
EICODE3_ICODE2   EQU  H'0003'
EICODE4          EQU  H'0004'

EICODE1          EQU  H'0001'
EICODE2          EQU  H'0002'
EICODE3          EQU  H'0003'
OPMODE0          EQU  H'0005'
OPMODE1          EQU  H'0006'
OPMODE2          EQU  H'0007'

ICODE0           EQU  H'0001'
ICODE1           EQU  H'0002'
ICODE2           EQU  H'0003'


;----- CANCON_RO4 Bits -----------------------------------------------------
FP0              EQU  H'0000'
WIN0_FP1         EQU  H'0001'
WIN1_FP2         EQU  H'0002'
WIN2_FP3         EQU  H'0003'
ABAT             EQU  H'0004'

WIN0             EQU  H'0001'
WIN1             EQU  H'0002'
WIN2             EQU  H'0003'

FP1              EQU  H'0001'
FP2              EQU  H'0002'
FP3              EQU  H'0003'


;----- RXF0SIDH Bits -----------------------------------------------------
SID3             EQU  H'0000'
SID4             EQU  H'0001'
SID5             EQU  H'0002'
SID6             EQU  H'0003'
SID7             EQU  H'0004'
SID8             EQU  H'0005'
SID9             EQU  H'0006'
SID10            EQU  H'0007'


;----- RXF0SIDL Bits -----------------------------------------------------
EXIDEN           EQU  H'0003'

EID16            EQU  H'0000'
EID17            EQU  H'0001'
SID0             EQU  H'0005'
SID1             EQU  H'0006'
SID2             EQU  H'0007'


;----- RXF0EIDH Bits -----------------------------------------------------
EID8             EQU  H'0000'
EID9             EQU  H'0001'
EID10            EQU  H'0002'
EID11            EQU  H'0003'
EID12            EQU  H'0004'
EID13            EQU  H'0005'
EID14            EQU  H'0006'
EID15            EQU  H'0007'


;----- RXF0EIDL Bits -----------------------------------------------------
EID0             EQU  H'0000'
EID1             EQU  H'0001'
EID2             EQU  H'0002'
EID3             EQU  H'0003'
EID4             EQU  H'0004'
EID5             EQU  H'0005'
EID6             EQU  H'0006'
EID7             EQU  H'0007'


;----- RXF1SIDH Bits -----------------------------------------------------
SID3             EQU  H'0000'
SID4             EQU  H'0001'
SID5             EQU  H'0002'
SID6             EQU  H'0003'
SID7             EQU  H'0004'
SID8             EQU  H'0005'
SID9             EQU  H'0006'
SID10            EQU  H'0007'


;----- RXF1SIDL Bits -----------------------------------------------------
EXIDEN           EQU  H'0003'

EID16            EQU  H'0000'
EID17            EQU  H'0001'
SID0             EQU  H'0005'
SID1             EQU  H'0006'
SID2             EQU  H'0007'


;----- RXF1EIDH Bits -----------------------------------------------------
EID8             EQU  H'0000'
EID9             EQU  H'0001'
EID10            EQU  H'0002'
EID11            EQU  H'0003'
EID12            EQU  H'0004'
EID13            EQU  H'0005'
EID14            EQU  H'0006'
EID15            EQU  H'0007'


;----- RXF1EIDL Bits -----------------------------------------------------
EID0             EQU  H'0000'
EID1             EQU  H'0001'
EID2             EQU  H'0002'
EID3             EQU  H'0003'
EID4             EQU  H'0004'
EID5             EQU  H'0005'
EID6             EQU  H'0006'
EID7             EQU  H'0007'


;----- RXF2SIDH Bits -----------------------------------------------------
SID3             EQU  H'0000'
SID4             EQU  H'0001'
SID5             EQU  H'0002'
SID6             EQU  H'0003'
SID7             EQU  H'0004'
SID8             EQU  H'0005'
SID9             EQU  H'0006'
SID10            EQU  H'0007'


;----- RXF2SIDL Bits -----------------------------------------------------
EXIDEN           EQU  H'0003'

EID16            EQU  H'0000'
EID17            EQU  H'0001'
SID0             EQU  H'0005'
SID1             EQU  H'0006'
SID2             EQU  H'0007'


;----- RXF2EIDH Bits -----------------------------------------------------
EID8             EQU  H'0000'
EID9             EQU  H'0001'
EID10            EQU  H'0002'
EID11            EQU  H'0003'
EID12            EQU  H'0004'
EID13            EQU  H'0005'
EID14            EQU  H'0006'
EID15            EQU  H'0007'


;----- RXF2EIDL Bits -----------------------------------------------------
EID0             EQU  H'0000'
EID1             EQU  H'0001'
EID2             EQU  H'0002'
EID3             EQU  H'0003'
EID4             EQU  H'0004'
EID5             EQU  H'0005'
EID6             EQU  H'0006'
EID7             EQU  H'0007'


;----- RXF3SIDH Bits -----------------------------------------------------
SID3             EQU  H'0000'
SID4             EQU  H'0001'
SID5             EQU  H'0002'
SID6             EQU  H'0003'
SID7             EQU  H'0004'
SID8             EQU  H'0005'
SID9             EQU  H'0006'
SID10            EQU  H'0007'


;----- RXF3SIDL Bits -----------------------------------------------------
EXIDEN           EQU  H'0003'

EID16            EQU  H'0000'
EID17            EQU  H'0001'
SID0             EQU  H'0005'
SID1             EQU  H'0006'
SID2             EQU  H'0007'


;----- RXF3EIDH Bits -----------------------------------------------------
EID8             EQU  H'0000'
EID9             EQU  H'0001'
EID10            EQU  H'0002'
EID11            EQU  H'0003'
EID12            EQU  H'0004'
EID13            EQU  H'0005'
EID14            EQU  H'0006'
EID15            EQU  H'0007'


;----- RXF3EIDL Bits -----------------------------------------------------
EID0             EQU  H'0000'
EID1             EQU  H'0001'
EID2             EQU  H'0002'
EID3             EQU  H'0003'
EID4             EQU  H'0004'
EID5             EQU  H'0005'
EID6             EQU  H'0006'
EID7             EQU  H'0007'


;----- RXF4SIDH Bits -----------------------------------------------------
SID3             EQU  H'0000'
SID4             EQU  H'0001'
SID5             EQU  H'0002'
SID6             EQU  H'0003'
SID7             EQU  H'0004'
SID8             EQU  H'0005'
SID9             EQU  H'0006'
SID10            EQU  H'0007'


;----- RXF4SIDL Bits -----------------------------------------------------
EXIDEN           EQU  H'0003'

EID16            EQU  H'0000'
EID17            EQU  H'0001'
SID0             EQU  H'0005'
SID1             EQU  H'0006'
SID2             EQU  H'0007'


;----- RXF4EIDH Bits -----------------------------------------------------
EID8             EQU  H'0000'
EID9             EQU  H'0001'
EID10            EQU  H'0002'
EID11            EQU  H'0003'
EID12            EQU  H'0004'
EID13            EQU  H'0005'
EID14            EQU  H'0006'
EID15            EQU  H'0007'


;----- RXF4EIDL Bits -----------------------------------------------------
EID0             EQU  H'0000'
EID1             EQU  H'0001'
EID2             EQU  H'0002'
EID3             EQU  H'0003'
EID4             EQU  H'0004'
EID5             EQU  H'0005'
EID6             EQU  H'0006'
EID7             EQU  H'0007'


;----- RXF5SIDH Bits -----------------------------------------------------
SID3             EQU  H'0000'
SID4             EQU  H'0001'
SID5             EQU  H'0002'
SID6             EQU  H'0003'
SID7             EQU  H'0004'
SID8             EQU  H'0005'
SID9             EQU  H'0006'
SID10            EQU  H'0007'


;----- RXF5SIDL Bits -----------------------------------------------------
EXIDEN           EQU  H'0003'

EID16            EQU  H'0000'
EID17            EQU  H'0001'
SID0             EQU  H'0005'
SID1             EQU  H'0006'
SID2             EQU  H'0007'


;----- RXF5EIDH Bits -----------------------------------------------------
EID8             EQU  H'0000'
EID9             EQU  H'0001'
EID10            EQU  H'0002'
EID11            EQU  H'0003'
EID12            EQU  H'0004'
EID13            EQU  H'0005'
EID14            EQU  H'0006'
EID15            EQU  H'0007'


;----- RXF5EIDL Bits -----------------------------------------------------
EID0             EQU  H'0000'
EID1             EQU  H'0001'
EID2             EQU  H'0002'
EID3             EQU  H'0003'
EID4             EQU  H'0004'
EID5             EQU  H'0005'
EID6             EQU  H'0006'
EID7             EQU  H'0007'


;----- RXM0SIDH Bits -----------------------------------------------------
SID3             EQU  H'0000'
SID4             EQU  H'0001'
SID5             EQU  H'0002'
SID6             EQU  H'0003'
SID7             EQU  H'0004'
SID8             EQU  H'0005'
SID9             EQU  H'0006'
SID10            EQU  H'0007'


;----- RXM0SIDL Bits -----------------------------------------------------
EXIDEN           EQU  H'0003'

EID16            EQU  H'0000'
EID17            EQU  H'0001'
SID0             EQU  H'0005'
SID1             EQU  H'0006'
SID2             EQU  H'0007'


;----- RXM0EIDH Bits -----------------------------------------------------
EID8             EQU  H'0000'
EID9             EQU  H'0001'
EID10            EQU  H'0002'
EID11            EQU  H'0003'
EID12            EQU  H'0004'
EID13            EQU  H'0005'
EID14            EQU  H'0006'
EID15            EQU  H'0007'


;----- RXM0EIDL Bits -----------------------------------------------------
EID0             EQU  H'0000'
EID1             EQU  H'0001'
EID2             EQU  H'0002'
EID3             EQU  H'0003'
EID4             EQU  H'0004'
EID5             EQU  H'0005'
EID6             EQU  H'0006'
EID7             EQU  H'0007'


;----- RXM1SIDH Bits -----------------------------------------------------
SID3             EQU  H'0000'
SID4             EQU  H'0001'
SID5             EQU  H'0002'
SID6             EQU  H'0003'
SID7             EQU  H'0004'
SID8             EQU  H'0005'
SID9             EQU  H'0006'
SID10            EQU  H'0007'


;----- RXM1SIDL Bits -----------------------------------------------------
EXIDEN           EQU  H'0003'

EID16            EQU  H'0000'
EID17            EQU  H'0001'
SID0             EQU  H'0005'
SID1             EQU  H'0006'
SID2             EQU  H'0007'


;----- RXM1EIDH Bits -----------------------------------------------------
EID8             EQU  H'0000'
EID9             EQU  H'0001'
EID10            EQU  H'0002'
EID11            EQU  H'0003'
EID12            EQU  H'0004'
EID13            EQU  H'0005'
EID14            EQU  H'0006'
EID15            EQU  H'0007'


;----- RXM1EIDL Bits -----------------------------------------------------
EID0             EQU  H'0000'
EID1             EQU  H'0001'
EID2             EQU  H'0002'
EID3             EQU  H'0003'
EID4             EQU  H'0004'
EID5             EQU  H'0005'
EID6             EQU  H'0006'
EID7             EQU  H'0007'


;----- TXB2CON Bits -----------------------------------------------------
TXREQ            EQU  H'0003'
TXERR            EQU  H'0004'
TXLARB           EQU  H'0005'
TXABT            EQU  H'0006'
TXBIF            EQU  H'0007'

TXPRI0           EQU  H'0000'
TXPRI1           EQU  H'0001'


;----- TXB2SIDH Bits -----------------------------------------------------
SID3             EQU  H'0000'
SID4             EQU  H'0001'
SID5             EQU  H'0002'
SID6             EQU  H'0003'
SID7             EQU  H'0004'
SID8             EQU  H'0005'
SID9             EQU  H'0006'
SID10            EQU  H'0007'


;----- TXB2SIDL Bits -----------------------------------------------------
EXIDE            EQU  H'0003'
SRR              EQU  H'0004'

EID16            EQU  H'0000'
EID17            EQU  H'0001'
SID0             EQU  H'0005'
SID1             EQU  H'0006'
SID2             EQU  H'0007'


;----- TXB2EIDH Bits -----------------------------------------------------
EID8             EQU  H'0000'
EID9             EQU  H'0001'
EID10            EQU  H'0002'
EID11            EQU  H'0003'
EID12            EQU  H'0004'
EID13            EQU  H'0005'
EID14            EQU  H'0006'
EID15            EQU  H'0007'


;----- TXB2EIDL Bits -----------------------------------------------------
EID0             EQU  H'0000'
EID1             EQU  H'0001'
EID2             EQU  H'0002'
EID3             EQU  H'0003'
EID4             EQU  H'0004'
EID5             EQU  H'0005'
EID6             EQU  H'0006'
EID7             EQU  H'0007'


;----- TXB2DLC Bits -----------------------------------------------------
TXRTR            EQU  H'0006'

DLC0             EQU  H'0000'
DLC1             EQU  H'0001'
DLC2             EQU  H'0002'
DLC3             EQU  H'0003'


;----- TXB2D0 Bits -----------------------------------------------------
TXB2D00          EQU  H'0000'
TXB2D01          EQU  H'0001'
TXB2D02          EQU  H'0002'
TXB2D03          EQU  H'0003'
TXB2D04          EQU  H'0004'
TXB2D05          EQU  H'0005'
TXB2D06          EQU  H'0006'
TXB2D07          EQU  H'0007'


;----- TXB2D1 Bits -----------------------------------------------------
TXB2D10          EQU  H'0000'
TXB2D11          EQU  H'0001'
TXB2D12          EQU  H'0002'
TXB2D13          EQU  H'0003'
TXB2D14          EQU  H'0004'
TXB2D15          EQU  H'0005'
TXB2D16          EQU  H'0006'
TXB2D17          EQU  H'0007'


;----- TXB2D2 Bits -----------------------------------------------------
TXB2D20          EQU  H'0000'
TXB2D21          EQU  H'0001'
TXB2D22          EQU  H'0002'
TXB2D23          EQU  H'0003'
TXB2D24          EQU  H'0004'
TXB2D25          EQU  H'0005'
TXB2D26          EQU  H'0006'
TXB2D27          EQU  H'0007'


;----- TXB2D3 Bits -----------------------------------------------------
TXB2D30          EQU  H'0000'
TXB2D31          EQU  H'0001'
TXB2D32          EQU  H'0002'
TXB2D33          EQU  H'0003'
TXB2D34          EQU  H'0004'
TXB2D35          EQU  H'0005'
TXB2D36          EQU  H'0006'
TXB2D37          EQU  H'0007'


;----- TXB2D4 Bits -----------------------------------------------------
TXB2D40          EQU  H'0000'
TXB2D41          EQU  H'0001'
TXB2D42          EQU  H'0002'
TXB2D43          EQU  H'0003'
TXB2D44          EQU  H'0004'
TXB2D45          EQU  H'0005'
TXB2D46          EQU  H'0006'
TXB2D47          EQU  H'0007'


;----- TXB2D5 Bits -----------------------------------------------------
TXB2D50          EQU  H'0000'
TXB2D51          EQU  H'0001'
TXB2D52          EQU  H'0002'
TXB2D53          EQU  H'0003'
TXB2D54          EQU  H'0004'
TXB2D55          EQU  H'0005'
TXB2D56          EQU  H'0006'
TXB2D57          EQU  H'0007'


;----- TXB2D6 Bits -----------------------------------------------------
TXB2D60          EQU  H'0000'
TXB2D61          EQU  H'0001'
TXB2D62          EQU  H'0002'
TXB2D63          EQU  H'0003'
TXB2D64          EQU  H'0004'
TXB2D65          EQU  H'0005'
TXB2D66          EQU  H'0006'
TXB2D67          EQU  H'0007'


;----- TXB2D7 Bits -----------------------------------------------------
TXB2D70          EQU  H'0000'
TXB2D71          EQU  H'0001'
TXB2D72          EQU  H'0002'
TXB2D73          EQU  H'0003'
TXB2D74          EQU  H'0004'
TXB2D75          EQU  H'0005'
TXB2D76          EQU  H'0006'
TXB2D77          EQU  H'0007'


;----- CANSTAT_RO3 Bits -----------------------------------------------------
EICODE0          EQU  H'0000'
EICODE1_ICODE0   EQU  H'0001'
EICODE2_ICODE1   EQU  H'0002'
EICODE3_ICODE2   EQU  H'0003'
EICODE4          EQU  H'0004'

EICODE1          EQU  H'0001'
EICODE2          EQU  H'0002'
EICODE3          EQU  H'0003'
OPMODE0          EQU  H'0005'
OPMODE1          EQU  H'0006'
OPMODE2          EQU  H'0007'

ICODE0           EQU  H'0001'
ICODE1           EQU  H'0002'
ICODE2           EQU  H'0003'


;----- CANCON_RO3 Bits -----------------------------------------------------
FP0              EQU  H'0000'
WIN0_FP1         EQU  H'0001'
WIN1_FP2         EQU  H'0002'
WIN2_FP3         EQU  H'0003'
ABAT             EQU  H'0004'

WIN0             EQU  H'0001'
WIN1             EQU  H'0002'
WIN2             EQU  H'0003'

FP1              EQU  H'0001'
FP2              EQU  H'0002'
FP3              EQU  H'0003'


;----- TXB1CON Bits -----------------------------------------------------
TXREQ            EQU  H'0003'
TXERR            EQU  H'0004'
TXLARB           EQU  H'0005'
TXABT            EQU  H'0006'
TXBIF            EQU  H'0007'

TXPRI0           EQU  H'0000'
TXPRI1           EQU  H'0001'


;----- TXB1SIDH Bits -----------------------------------------------------
SID3             EQU  H'0000'
SID4             EQU  H'0001'
SID5             EQU  H'0002'
SID6             EQU  H'0003'
SID7             EQU  H'0004'
SID8             EQU  H'0005'
SID9             EQU  H'0006'
SID10            EQU  H'0007'


;----- TXB1SIDL Bits -----------------------------------------------------
EXIDE            EQU  H'0003'
SRR              EQU  H'0004'

EID16            EQU  H'0000'
EID17            EQU  H'0001'
SID0             EQU  H'0005'
SID1             EQU  H'0006'
SID2             EQU  H'0007'


;----- TXB1EIDH Bits -----------------------------------------------------
EID8             EQU  H'0000'
EID9             EQU  H'0001'
EID10            EQU  H'0002'
EID11            EQU  H'0003'
EID12            EQU  H'0004'
EID13            EQU  H'0005'
EID14            EQU  H'0006'
EID15            EQU  H'0007'


;----- TXB1EIDL Bits -----------------------------------------------------
EID0             EQU  H'0000'
EID1             EQU  H'0001'
EID2             EQU  H'0002'
EID3             EQU  H'0003'
EID4             EQU  H'0004'
EID5             EQU  H'0005'
EID6             EQU  H'0006'
EID7             EQU  H'0007'


;----- TXB1DLC Bits -----------------------------------------------------
TXRTR            EQU  H'0006'

DLC0             EQU  H'0000'
DLC1             EQU  H'0001'
DLC2             EQU  H'0002'
DLC3             EQU  H'0003'


;----- TXB1D0 Bits -----------------------------------------------------
TXB1D00          EQU  H'0000'
TXB1D01          EQU  H'0001'
TXB1D02          EQU  H'0002'
TXB1D03          EQU  H'0003'
TXB1D04          EQU  H'0004'
TXB1D05          EQU  H'0005'
TXB1D06          EQU  H'0006'
TXB1D07          EQU  H'0007'


;----- TXB1D1 Bits -----------------------------------------------------
TXB1D10          EQU  H'0000'
TXB1D11          EQU  H'0001'
TXB1D12          EQU  H'0002'
TXB1D13          EQU  H'0003'
TXB1D14          EQU  H'0004'
TXB1D15          EQU  H'0005'
TXB1D16          EQU  H'0006'
TXB1D17          EQU  H'0007'


;----- TXB1D2 Bits -----------------------------------------------------
TXB1D20          EQU  H'0000'
TXB1D21          EQU  H'0001'
TXB1D22          EQU  H'0002'
TXB1D23          EQU  H'0003'
TXB1D24          EQU  H'0004'
TXB1D25          EQU  H'0005'
TXB1D26          EQU  H'0006'
TXB1D27          EQU  H'0007'


;----- TXB1D3 Bits -----------------------------------------------------
TXB1D30          EQU  H'0000'
TXB1D31          EQU  H'0001'
TXB1D32          EQU  H'0002'
TXB1D33          EQU  H'0003'
TXB1D34          EQU  H'0004'
TXB1D35          EQU  H'0005'
TXB1D36          EQU  H'0006'
TXB1D37          EQU  H'0007'


;----- TXB1D4 Bits -----------------------------------------------------
TXB1D40          EQU  H'0000'
TXB1D41          EQU  H'0001'
TXB1D42          EQU  H'0002'
TXB1D43          EQU  H'0003'
TXB1D44          EQU  H'0004'
TXB1D45          EQU  H'0005'
TXB1D46          EQU  H'0006'
TXB1D47          EQU  H'0007'


;----- TXB1D5 Bits -----------------------------------------------------
TXB1D50          EQU  H'0000'
TXB1D51          EQU  H'0001'
TXB1D52          EQU  H'0002'
TXB1D53          EQU  H'0003'
TXB1D54          EQU  H'0004'
TXB1D55          EQU  H'0005'
TXB1D56          EQU  H'0006'
TXB1D57          EQU  H'0007'


;----- TXB1D6 Bits -----------------------------------------------------
TXB1D60          EQU  H'0000'
TXB1D61          EQU  H'0001'
TXB1D62          EQU  H'0002'
TXB1D63          EQU  H'0003'
TXB1D64          EQU  H'0004'
TXB1D65          EQU  H'0005'
TXB1D66          EQU  H'0006'
TXB1D67          EQU  H'0007'


;----- TXB1D7 Bits -----------------------------------------------------
TXB1D70          EQU  H'0000'
TXB1D71          EQU  H'0001'
TXB1D72          EQU  H'0002'
TXB1D73          EQU  H'0003'
TXB1D74          EQU  H'0004'
TXB1D75          EQU  H'0005'
TXB1D76          EQU  H'0006'
TXB1D77          EQU  H'0007'


;----- CANSTAT_RO2 Bits -----------------------------------------------------
EICODE0          EQU  H'0000'
EICODE1_ICODE0   EQU  H'0001'
EICODE2_ICODE1   EQU  H'0002'
EICODE3_ICODE2   EQU  H'0003'
EICODE4          EQU  H'0004'

EICODE1          EQU  H'0001'
EICODE2          EQU  H'0002'
EICODE3          EQU  H'0003'
OPMODE0          EQU  H'0005'
OPMODE1          EQU  H'0006'
OPMODE2          EQU  H'0007'

ICODE20          EQU  H'0001'
ICODE21          EQU  H'0002'
ICODE2           EQU  H'0003'


;----- CANCON_RO2 Bits -----------------------------------------------------
FP0              EQU  H'0000'
WIN0_FP1         EQU  H'0001'
WIN1_FP2         EQU  H'0002'
WIN2_FP3         EQU  H'0003'
ABAT             EQU  H'0004'

WIN0             EQU  H'0001'
WIN1             EQU  H'0002'
WIN2             EQU  H'0003'

FP1              EQU  H'0001'
FP2              EQU  H'0002'
FP3              EQU  H'0003'


;----- TXB0CON Bits -----------------------------------------------------
TXREQ            EQU  H'0003'
TXERR            EQU  H'0004'
TXLARB           EQU  H'0005'
TXABT            EQU  H'0006'
TXBIF            EQU  H'0007'

TXPRI0           EQU  H'0000'
TXPRI1           EQU  H'0001'


;----- TXB0SIDH Bits -----------------------------------------------------
SID3             EQU  H'0000'
SID4             EQU  H'0001'
SID5             EQU  H'0002'
SID6             EQU  H'0003'
SID7             EQU  H'0004'
SID8             EQU  H'0005'
SID9             EQU  H'0006'
SID10            EQU  H'0007'


;----- TXB0SIDL Bits -----------------------------------------------------
EXIDE            EQU  H'0003'
SRR              EQU  H'0004'

EID16            EQU  H'0000'
EID17            EQU  H'0001'
SID0             EQU  H'0005'
SID1             EQU  H'0006'
SID2             EQU  H'0007'


;----- TXB0EIDH Bits -----------------------------------------------------
EID8             EQU  H'0000'
EID9             EQU  H'0001'
EID10            EQU  H'0002'
EID11            EQU  H'0003'
EID12            EQU  H'0004'
EID13            EQU  H'0005'
EID14            EQU  H'0006'
EID15            EQU  H'0007'


;----- TXB0EIDL Bits -----------------------------------------------------
EID0             EQU  H'0000'
EID1             EQU  H'0001'
EID2             EQU  H'0002'
EID3             EQU  H'0003'
EID4             EQU  H'0004'
EID5             EQU  H'0005'
EID6             EQU  H'0006'
EID7             EQU  H'0007'


;----- TXB0DLC Bits -----------------------------------------------------
TXRTR            EQU  H'0006'

DLC0             EQU  H'0000'
DLC1             EQU  H'0001'
DLC2             EQU  H'0002'
DLC3             EQU  H'0003'


;----- TXB0D0 Bits -----------------------------------------------------
TXB0D00          EQU  H'0000'
TXB0D01          EQU  H'0001'
TXB0D02          EQU  H'0002'
TXB0D03          EQU  H'0003'
TXB0D04          EQU  H'0004'
TXB0D05          EQU  H'0005'
TXB0D06          EQU  H'0006'
TXB0D07          EQU  H'0007'


;----- TXB0D1 Bits -----------------------------------------------------
TXB0D10          EQU  H'0000'
TXB0D11          EQU  H'0001'
TXB0D12          EQU  H'0002'
TXB0D13          EQU  H'0003'
TXB0D14          EQU  H'0004'
TXB0D15          EQU  H'0005'
TXB0D16          EQU  H'0006'
TXB0D17          EQU  H'0007'


;----- TXB0D2 Bits -----------------------------------------------------
TXB0D20          EQU  H'0000'
TXB0D21          EQU  H'0001'
TXB0D22          EQU  H'0002'
TXB0D23          EQU  H'0003'
TXB0D24          EQU  H'0004'
TXB0D25          EQU  H'0005'
TXB0D26          EQU  H'0006'
TXB0D27          EQU  H'0007'


;----- TXB0D3 Bits -----------------------------------------------------
TXB0D30          EQU  H'0000'
TXB0D31          EQU  H'0001'
TXB0D32          EQU  H'0002'
TXB0D33          EQU  H'0003'
TXB0D34          EQU  H'0004'
TXB0D35          EQU  H'0005'
TXB0D36          EQU  H'0006'
TXB0D37          EQU  H'0007'


;----- TXB0D4 Bits -----------------------------------------------------
TXB0D40          EQU  H'0000'
TXB0D41          EQU  H'0001'
TXB0D42          EQU  H'0002'
TXB0D43          EQU  H'0003'
TXB0D44          EQU  H'0004'
TXB0D45          EQU  H'0005'
TXB0D46          EQU  H'0006'
TXB0D47          EQU  H'0007'


;----- TXB0D5 Bits -----------------------------------------------------
TXB0D50          EQU  H'0000'
TXB0D51          EQU  H'0001'
TXB0D52          EQU  H'0002'
TXB0D53          EQU  H'0003'
TXB0D54          EQU  H'0004'
TXB0D55          EQU  H'0005'
TXB0D56          EQU  H'0006'
TXB0D57          EQU  H'0007'


;----- TXB0D6 Bits -----------------------------------------------------
TXB0D60          EQU  H'0000'
TXB0D61          EQU  H'0001'
TXB0D62          EQU  H'0002'
TXB0D63          EQU  H'0003'
TXB0D64          EQU  H'0004'
TXB0D65          EQU  H'0005'
TXB0D66          EQU  H'0006'
TXB0D67          EQU  H'0007'


;----- TXB0D7 Bits -----------------------------------------------------
TXB0D70          EQU  H'0000'
TXB0D71          EQU  H'0001'
TXB0D72          EQU  H'0002'
TXB0D73          EQU  H'0003'
TXB0D74          EQU  H'0004'
TXB0D75          EQU  H'0005'
TXB0D76          EQU  H'0006'
TXB0D77          EQU  H'0007'


;----- CANSTAT_RO1 Bits -----------------------------------------------------
EICODE0          EQU  H'0000'
EICODE1_ICODE0   EQU  H'0001'
EICODE2_ICODE1   EQU  H'0002'
EICODE3_ICODE2   EQU  H'0003'
EICODE4          EQU  H'0004'

EICODE1          EQU  H'0001'
EICODE2          EQU  H'0002'
EICODE3          EQU  H'0003'
OPMODE0          EQU  H'0005'
OPMODE1          EQU  H'0006'
OPMODE2          EQU  H'0007'

ICODE0           EQU  H'0001'
ICODE1           EQU  H'0002'
ICODE2           EQU  H'0003'


;----- CANCON_RO1 Bits -----------------------------------------------------
FP0              EQU  H'0000'
WIN0_FP1         EQU  H'0001'
WIN1_FP2         EQU  H'0002'
WIN2_FP3         EQU  H'0003'
ABAT             EQU  H'0004'

WIN0             EQU  H'0001'
WIN1             EQU  H'0002'
WIN2             EQU  H'0003'

FP1              EQU  H'0001'
FP2              EQU  H'0002'
FP3              EQU  H'0003'


;----- RXB1CON Bits -----------------------------------------------------
FILHIT0          EQU  H'0000'
FILHIT1          EQU  H'0001'
FILHIT2          EQU  H'0002'
RXRTRRO_FILHIT3  EQU  H'0003'
FILHIT4          EQU  H'0004'
RXM0_RTRRO       EQU  H'0005'
RXM1             EQU  H'0006'
RXFUL            EQU  H'0007'

RXRTRRO_RXB1CON  EQU  H'0003'
RXM0             EQU  H'0005'

FILHIT3          EQU  H'0003'
RTRRO            EQU  H'0005'


;----- RXB1SIDH Bits -----------------------------------------------------
SID3             EQU  H'0000'
SID4             EQU  H'0001'
SID5             EQU  H'0002'
SID6             EQU  H'0003'
SID7             EQU  H'0004'
SID8             EQU  H'0005'
SID9             EQU  H'0006'
SID10            EQU  H'0007'


;----- RXB1SIDL Bits -----------------------------------------------------
EXID             EQU  H'0003'
SRR              EQU  H'0004'

EDI16            EQU  H'0000'
EDI17            EQU  H'0001'
SID0             EQU  H'0005'
SID1             EQU  H'0006'
SID2             EQU  H'0007'


;----- RXB1EIDH Bits -----------------------------------------------------
EID8             EQU  H'0000'
EID9             EQU  H'0001'
EID10            EQU  H'0002'
EID11            EQU  H'0003'
EID12            EQU  H'0004'
EID13            EQU  H'0005'
EID14            EQU  H'0006'
EID15            EQU  H'0007'


;----- RXB1EIDL Bits -----------------------------------------------------
EID0             EQU  H'0000'
EID1             EQU  H'0001'
EID2             EQU  H'0002'
EID3             EQU  H'0003'
EID4             EQU  H'0004'
EID5             EQU  H'0005'
EID6             EQU  H'0006'
EID7             EQU  H'0007'


;----- RXB1DLC Bits -----------------------------------------------------
RXRTR            EQU  H'0006'

DLC0             EQU  H'0000'
DLC1             EQU  H'0001'
DLC2             EQU  H'0002'
DLC3             EQU  H'0003'
RB0_RXB1DLC      EQU  H'0004'
RB1_RXB1DLC      EQU  H'0005'


;----- RXB1D0 Bits -----------------------------------------------------
RXB1D00          EQU  H'0000'
RXB1D01          EQU  H'0001'
RXB1D02          EQU  H'0002'
RXB1D03          EQU  H'0003'
RXB1D04          EQU  H'0004'
RXB1D05          EQU  H'0005'
RXB1D06          EQU  H'0006'
RXB1D07          EQU  H'0007'


;----- RXB1D1 Bits -----------------------------------------------------
RXB1D10          EQU  H'0000'
RXB1D11          EQU  H'0001'
RXB1D12          EQU  H'0002'
RXB1D13          EQU  H'0003'
RXB1D14          EQU  H'0004'
RXB1D15          EQU  H'0005'
RXB1D16          EQU  H'0006'
RXB1D17          EQU  H'0007'


;----- RXB1D2 Bits -----------------------------------------------------
RXB1D20          EQU  H'0000'
RXB1D21          EQU  H'0001'
RXB1D22          EQU  H'0002'
RXB1D23          EQU  H'0003'
RXB1D24          EQU  H'0004'
RXB1D25          EQU  H'0005'
RXB1D26          EQU  H'0006'
RXB1D27          EQU  H'0007'


;----- RXB1D3 Bits -----------------------------------------------------
RXB1D30          EQU  H'0000'
RXB1D31          EQU  H'0001'
RXB1D32          EQU  H'0002'
RXB1D33          EQU  H'0003'
RXB1D34          EQU  H'0004'
RXB1D35          EQU  H'0005'
RXB1D36          EQU  H'0006'
RXB1D37          EQU  H'0007'


;----- RXB1D4 Bits -----------------------------------------------------
RXB1D40          EQU  H'0000'
RXB1D41          EQU  H'0001'
RXB1D42          EQU  H'0002'
RXB1D43          EQU  H'0003'
RXB1D44          EQU  H'0004'
RXB1D45          EQU  H'0005'
RXB1D46          EQU  H'0006'
RXB1D47          EQU  H'0007'


;----- RXB1D5 Bits -----------------------------------------------------
RXB1D50          EQU  H'0000'
RXB1D51          EQU  H'0001'
RXB1D52          EQU  H'0002'
RXB1D53          EQU  H'0003'
RXB1D54          EQU  H'0004'
RXB1D55          EQU  H'0005'
RXB1D56          EQU  H'0006'
RXB1D57          EQU  H'0007'


;----- RXB1D6 Bits -----------------------------------------------------
RXB1D60          EQU  H'0000'
RXB1D61          EQU  H'0001'
RXB1D62          EQU  H'0002'
RXB1D63          EQU  H'0003'
RXB1D64          EQU  H'0004'
RXB1D65          EQU  H'0005'
RXB1D66          EQU  H'0006'
RXB1D67          EQU  H'0007'


;----- RXB1D7 Bits -----------------------------------------------------
RXB1D70          EQU  H'0000'
RXB1D71          EQU  H'0001'
RXB1D72          EQU  H'0002'
RXB1D73          EQU  H'0003'
RXB1D74          EQU  H'0004'
RXB1D75          EQU  H'0005'
RXB1D76          EQU  H'0006'
RXB1D77          EQU  H'0007'


;----- CANSTAT_RO0 Bits -----------------------------------------------------
EICODE0          EQU  H'0000'
EICODE1_ICODE0   EQU  H'0001'
EICODE2_ICODE1   EQU  H'0002'
EICODE3_ICODE2   EQU  H'0003'
EICODE4          EQU  H'0004'

EICODE1          EQU  H'0001'
EICODE2          EQU  H'0002'
EICODE3          EQU  H'0003'
OPMODE0          EQU  H'0005'
OPMODE1          EQU  H'0006'
OPMODE2          EQU  H'0007'

ICODE0           EQU  H'0001'
ICODE1           EQU  H'0002'
ICODE2           EQU  H'0003'


;----- CANCON_RO0 Bits -----------------------------------------------------
FP0              EQU  H'0000'
WIN0_FP1         EQU  H'0001'
WIN1_FP2         EQU  H'0002'
WIN2_FP3         EQU  H'0003'
ABAT             EQU  H'0004'

WIN0             EQU  H'0001'
WIN1             EQU  H'0002'
WIN2             EQU  H'0003'

FP1              EQU  H'0001'
FP2              EQU  H'0002'
FP3              EQU  H'0003'


;----- CCP5CON Bits -----------------------------------------------------
CCP5M0           EQU  H'0000'
CCP5M1           EQU  H'0001'
CCP5M2           EQU  H'0002'
CCP5M3           EQU  H'0003'
DC5B0            EQU  H'0004'
DC5B1            EQU  H'0005'

CCP5Y            EQU  H'0004'
CCP5X            EQU  H'0005'


;----- CCP4CON Bits -----------------------------------------------------
CCP4M0           EQU  H'0000'
CCP4M1           EQU  H'0001'
CCP4M2           EQU  H'0002'
CCP4M3           EQU  H'0003'
DC4B0            EQU  H'0004'
DC4B1            EQU  H'0005'

CCP4Y            EQU  H'0004'
CCP4X            EQU  H'0005'


;----- CCP3CON Bits -----------------------------------------------------
CCP3M0           EQU  H'0000'
CCP3M1           EQU  H'0001'
CCP3M2           EQU  H'0002'
CCP3M3           EQU  H'0003'
DC3B0            EQU  H'0004'
DC3B1            EQU  H'0005'

CCP3Y            EQU  H'0004'
CCP3X            EQU  H'0005'


;----- CCP2CON Bits -----------------------------------------------------
CCP2M0           EQU  H'0000'
CCP2M1           EQU  H'0001'
CCP2M2           EQU  H'0002'
CCP2M3           EQU  H'0003'
DC2B0            EQU  H'0004'
DC2B1            EQU  H'0005'

CCP2Y            EQU  H'0004'
CCP2X            EQU  H'0005'


;----- ECCP2CON Bits -----------------------------------------------------
CCP2M0           EQU  H'0000'
CCP2M1           EQU  H'0001'
CCP2M2           EQU  H'0002'
CCP2M3           EQU  H'0003'
DC2B0            EQU  H'0004'
DC2B1            EQU  H'0005'

CCP2Y            EQU  H'0004'
CCP2X            EQU  H'0005'


;----- CTMUICON Bits -----------------------------------------------------
IRNG0            EQU  H'0000'
IRNG1            EQU  H'0001'
ITRIM0           EQU  H'0002'
ITRIM1           EQU  H'0003'
ITRIM2           EQU  H'0004'
ITRIM3           EQU  H'0005'
ITRIM4           EQU  H'0006'
ITRIM5           EQU  H'0007'


;----- CTMUCONL Bits -----------------------------------------------------
EDG1STAT         EQU  H'0000'
EDG2STAT         EQU  H'0001'
EDG1POL          EQU  H'0004'
EDG2POL          EQU  H'0007'

EDG1SEL0         EQU  H'0002'
EDG1SEL1         EQU  H'0003'
EDG2SEL0         EQU  H'0005'
EDG2SEL1         EQU  H'0006'


;----- CTMUCONH Bits -----------------------------------------------------
CTTRIG           EQU  H'0000'
IDISSEN          EQU  H'0001'
EDGSEQEN         EQU  H'0002'
EDGEN            EQU  H'0003'
TGEN             EQU  H'0004'
CTMUSIDL         EQU  H'0005'
CTMUEN           EQU  H'0007'


;----- PADCFG1 Bits -----------------------------------------------------
CTMUDS           EQU  H'0000'


;----- PMD2 Bits -----------------------------------------------------
CMP1MD           EQU  H'0000'
CMP2MD           EQU  H'0001'
ECANMD           EQU  H'0002'


;----- PMD1 Bits -----------------------------------------------------
TMR0MD           EQU  H'0000'
TMR1MD           EQU  H'0001'
TMR2MD           EQU  H'0002'
TMR3MD           EQU  H'0003'
TMR4MD           EQU  H'0004'
ADCMD            EQU  H'0005'
CTMUMD           EQU  H'0006'
PSPMD            EQU  H'0007'


;----- PMD0 Bits -----------------------------------------------------
SSPMD            EQU  H'0000'
UART1MD          EQU  H'0001'
UART2MD          EQU  H'0002'
CCP1MD           EQU  H'0003'
CCP2MD           EQU  H'0004'
CCP3MD           EQU  H'0005'
CCP4MD           EQU  H'0006'
CCP5MD           EQU  H'0007'


;----- IOCB Bits -----------------------------------------------------
IOCB4            EQU  H'0004'
IOCB5            EQU  H'0005'
IOCB6            EQU  H'0006'
IOCB7            EQU  H'0007'


;----- WPUB Bits -----------------------------------------------------
WPUB0            EQU  H'0000'
WPUB1            EQU  H'0001'
WPUB2            EQU  H'0002'
WPUB3            EQU  H'0003'
WPUB4            EQU  H'0004'
WPUB5            EQU  H'0005'
WPUB6            EQU  H'0006'
WPUB7            EQU  H'0007'


;----- ANCON1 Bits -----------------------------------------------------
ANSEL8           EQU  H'0000'
ANSEL9           EQU  H'0001'
ANSEL10          EQU  H'0002'


;----- ANCON0 Bits -----------------------------------------------------
ANSEL0           EQU  H'0000'
ANSEL1           EQU  H'0001'
ANSEL2           EQU  H'0002'
ANSEL3           EQU  H'0003'
ANSEL4           EQU  H'0004'


;----- CM2CON Bits -----------------------------------------------------
CREF             EQU  H'0002'
CPOL             EQU  H'0005'
COE              EQU  H'0006'
CON              EQU  H'0007'

CCH0             EQU  H'0000'
CCH1             EQU  H'0001'
EVPOL0           EQU  H'0003'
EVPOL1           EQU  H'0004'


;----- CM2CON1 Bits -----------------------------------------------------
CREF             EQU  H'0002'
CPOL             EQU  H'0005'
COE              EQU  H'0006'
CON              EQU  H'0007'

CCH0             EQU  H'0000'
CCH1             EQU  H'0001'
EVPOL0           EQU  H'0003'
EVPOL1           EQU  H'0004'


;----- CM1CON Bits -----------------------------------------------------
CREF             EQU  H'0002'
CPOL             EQU  H'0005'
COE              EQU  H'0006'
CON              EQU  H'0007'

CCH0             EQU  H'0000'
CCH1             EQU  H'0001'
EVPOL0           EQU  H'0003'
EVPOL1           EQU  H'0004'


;----- CM1CON1 Bits -----------------------------------------------------
CREF             EQU  H'0002'
CPOL             EQU  H'0005'
COE              EQU  H'0006'
CON              EQU  H'0007'

CCH0             EQU  H'0000'
CCH1             EQU  H'0001'
EVPOL0           EQU  H'0003'
EVPOL1           EQU  H'0004'


;----- RXB0CON Bits -----------------------------------------------------
FILHIT0          EQU  H'0000'
JTOFF_FILHIT1    EQU  H'0001'
RB0DBEN_FILHIT2  EQU  H'0002'
RXRTRRO_FILHIT3  EQU  H'0003'
FILHIT4          EQU  H'0004'
RXM0_RTRRO       EQU  H'0005'
RXM1             EQU  H'0006'
RXFUL            EQU  H'0007'

JTOFF            EQU  H'0001'
RB0DBEN          EQU  H'0002'
RXRTRRO_RXB0CON  EQU  H'0003'
RTRRO            EQU  H'0005'

FILHIT1          EQU  H'0001'
FILHIT2          EQU  H'0002'
FILHIT3          EQU  H'0003'
RXM0             EQU  H'0005'


;----- RXB0SIDH Bits -----------------------------------------------------
SID3             EQU  H'0000'
SID4             EQU  H'0001'
SID5             EQU  H'0002'
SID6             EQU  H'0003'
SID7             EQU  H'0004'
SID8             EQU  H'0005'
SID9             EQU  H'0006'
SID10            EQU  H'0007'


;----- RXB0SIDL Bits -----------------------------------------------------
EXID             EQU  H'0003'
SRR              EQU  H'0004'

EID16            EQU  H'0000'
EID17            EQU  H'0001'
SID0             EQU  H'0005'
SID1             EQU  H'0006'
SID2             EQU  H'0007'


;----- RXB0EIDH Bits -----------------------------------------------------
EID8             EQU  H'0000'
EID9             EQU  H'0001'
EID10            EQU  H'0002'
EID11            EQU  H'0003'
EID12            EQU  H'0004'
EID13            EQU  H'0005'
EID14            EQU  H'0006'
EID15            EQU  H'0007'


;----- RXB0EIDL Bits -----------------------------------------------------
EID0             EQU  H'0000'
EID1             EQU  H'0001'
EID2             EQU  H'0002'
EID3             EQU  H'0003'
EID4             EQU  H'0004'
EID5             EQU  H'0005'
EID6             EQU  H'0006'
EID7             EQU  H'0007'


;----- RXB0DLC Bits -----------------------------------------------------
RXRTR            EQU  H'0006'

DLC0             EQU  H'0000'
DLC1             EQU  H'0001'
DLC2             EQU  H'0002'
DLC3             EQU  H'0003'
RB0_RXB0DLC      EQU  H'0004'
RB1_RXB0DLC      EQU  H'0005'


;----- RXB0D0 Bits -----------------------------------------------------
RXB0D00          EQU  H'0000'
RXB0D01          EQU  H'0001'
RXB0D02          EQU  H'0002'
RXB0D03          EQU  H'0003'
RXB0D04          EQU  H'0004'
RXB0D05          EQU  H'0005'
RXB0D06          EQU  H'0006'
RXB0D07          EQU  H'0007'


;----- RXB0D1 Bits -----------------------------------------------------
RXB0D10          EQU  H'0000'
RXB0D11          EQU  H'0001'
RXB0D12          EQU  H'0002'
RXB0D13          EQU  H'0003'
RXB0D14          EQU  H'0004'
RXB0D15          EQU  H'0005'
RXB0D16          EQU  H'0006'
RXB0D17          EQU  H'0007'


;----- RXB0D2 Bits -----------------------------------------------------
RXB0D20          EQU  H'0000'
RXB0D21          EQU  H'0001'
RXB0D22          EQU  H'0002'
RXB0D23          EQU  H'0003'
RXB0D24          EQU  H'0004'
RXB0D25          EQU  H'0005'
RXB0D26          EQU  H'0006'
RXB0D27          EQU  H'0007'


;----- RXB0D3 Bits -----------------------------------------------------
RXB0D30          EQU  H'0000'
RXB0D31          EQU  H'0001'
RXB0D32          EQU  H'0002'
RXB0D33          EQU  H'0003'
RXB0D34          EQU  H'0004'
RXB0D35          EQU  H'0005'
RXB0D36          EQU  H'0006'
RXB0D37          EQU  H'0007'


;----- RXB0D4 Bits -----------------------------------------------------
RXB0D40          EQU  H'0000'
RXB0D41          EQU  H'0001'
RXB0D42          EQU  H'0002'
RXB0D43          EQU  H'0003'
RXB0D44          EQU  H'0004'
RXB0D45          EQU  H'0005'
RXB0D46          EQU  H'0006'
RXB0D47          EQU  H'0007'


;----- RXB0D5 Bits -----------------------------------------------------
RXB0D50          EQU  H'0000'
RXB0D51          EQU  H'0001'
RXB0D52          EQU  H'0002'
RXB0D53          EQU  H'0003'
RXB0D54          EQU  H'0004'
RXB0D55          EQU  H'0005'
RXB0D56          EQU  H'0006'
RXB0D57          EQU  H'0007'


;----- RXB0D6 Bits -----------------------------------------------------
RXB0D60          EQU  H'0000'
RXB0D61          EQU  H'0001'
RXB0D62          EQU  H'0002'
RXB0D63          EQU  H'0003'
RXB0D64          EQU  H'0004'
RXB0D65          EQU  H'0005'
RXB0D66          EQU  H'0006'
RXB0D67          EQU  H'0007'


;----- RXB0D7 Bits -----------------------------------------------------
RXB0D70          EQU  H'0000'
RXB0D71          EQU  H'0001'
RXB0D72          EQU  H'0002'
RXB0D73          EQU  H'0003'
RXB0D74          EQU  H'0004'
RXB0D75          EQU  H'0005'
RXB0D76          EQU  H'0006'
RXB0D77          EQU  H'0007'


;----- CANSTAT Bits -----------------------------------------------------
EICODE0          EQU  H'0000'
EICODE1_ICODE0   EQU  H'0001'
EICODE2_ICODE1   EQU  H'0002'
EICODE3_ICODE2   EQU  H'0003'
EICODE4          EQU  H'0004'

EICODE1          EQU  H'0001'
EICODE2          EQU  H'0002'
EICODE3          EQU  H'0003'
OPMODE0          EQU  H'0005'
OPMODE1          EQU  H'0006'
OPMODE2          EQU  H'0007'

ICODE0           EQU  H'0001'
ICODE1           EQU  H'0002'
ICODE2           EQU  H'0003'


;----- CANCON Bits -----------------------------------------------------
FP0              EQU  H'0000'
WIN0_FP1         EQU  H'0001'
WIN1_FP2         EQU  H'0002'
WIN2_FP3         EQU  H'0003'
ABAT             EQU  H'0004'

WIN0             EQU  H'0001'
WIN1             EQU  H'0002'
WIN2             EQU  H'0003'

FP1              EQU  H'0001'
FP2              EQU  H'0002'
FP3              EQU  H'0003'


;----- CIOCON Bits -----------------------------------------------------
CLKSEL           EQU  H'0000'
CANCAP           EQU  H'0004'
ENDRHI           EQU  H'0005'
TX2EN            EQU  H'0006'
TX2SRC           EQU  H'0007'


;----- COMSTAT Bits -----------------------------------------------------
EWARN            EQU  H'0000'
RXWARN           EQU  H'0001'
TXWARN           EQU  H'0002'
RXBP             EQU  H'0003'
TXBP             EQU  H'0004'
TXBO             EQU  H'0005'
RXB1OVFL         EQU  H'0006'
RXB0OVFL         EQU  H'0007'

NOT_FIFOEMPTY    EQU  H'0007'


;----- ECANCON Bits -----------------------------------------------------
FIFOWM           EQU  H'0005'

EWIN0            EQU  H'0000'
EWIN1            EQU  H'0001'
EWIN2            EQU  H'0002'
EWIN3            EQU  H'0003'
EWIN4            EQU  H'0004'
MDSEL0           EQU  H'0006'
MDSEL1           EQU  H'0007'


;----- PIE5 Bits -----------------------------------------------------
RXB0IE           EQU  H'0000'
RXB1IE           EQU  H'0001'
TXB0IE           EQU  H'0002'
TXB1IE           EQU  H'0003'
TXB2IE           EQU  H'0004'
ERRIE            EQU  H'0005'
WAKIE            EQU  H'0006'
IRXIE            EQU  H'0007'

FIFOWMIE         EQU  H'0000'
RXBnIE           EQU  H'0001'
TXBnIE           EQU  H'0004'


;----- PIR5 Bits -----------------------------------------------------
RXB0IF           EQU  H'0000'
RXB1IF           EQU  H'0001'
TXB0IF           EQU  H'0002'
TXB1IF           EQU  H'0003'
TXB2IF           EQU  H'0004'
ERRIF            EQU  H'0005'
WAKIF            EQU  H'0006'
IRXIF            EQU  H'0007'

FIFOWMIF         EQU  H'0000'
RXBnIF           EQU  H'0001'
TXBnIF           EQU  H'0004'


;----- IPR5 Bits -----------------------------------------------------
RXB0IP           EQU  H'0000'
RXB1IP           EQU  H'0001'
TXB0IP           EQU  H'0002'
TXB1IP           EQU  H'0003'
TXB2IP           EQU  H'0004'
ERRIP            EQU  H'0005'
WAKIP            EQU  H'0006'
IRXIP            EQU  H'0007'

FIFOWMIP         EQU  H'0000'
RXBnIP           EQU  H'0001'
TXBnIP           EQU  H'0004'


;----- EECON1 Bits -----------------------------------------------------
RD               EQU  H'0000'
WR               EQU  H'0001'
WREN             EQU  H'0002'
WRERR            EQU  H'0003'
FREE             EQU  H'0004'
CFGS             EQU  H'0006'
EEPGD            EQU  H'0007'


;----- PORTA Bits -----------------------------------------------------
RA0              EQU  H'0000'
RA1              EQU  H'0001'
RA2              EQU  H'0002'
RA3              EQU  H'0003'
RA5              EQU  H'0005'
RA6              EQU  H'0006'
RA7              EQU  H'0007'


;----- PORTB Bits -----------------------------------------------------
RB0_PORTB        EQU  H'0000'
RB1_PORTB        EQU  H'0001'
RB2              EQU  H'0002'
RB3              EQU  H'0003'
RB4              EQU  H'0004'
RB5              EQU  H'0005'
RB6              EQU  H'0006'
RB7              EQU  H'0007'


;----- PORTC Bits -----------------------------------------------------
RC0              EQU  H'0000'
RC1              EQU  H'0001'
RC2              EQU  H'0002'
RC3              EQU  H'0003'
RC4              EQU  H'0004'
RC5              EQU  H'0005'
RC6              EQU  H'0006'
RC7              EQU  H'0007'


;----- PORTE Bits -----------------------------------------------------
RE3              EQU  H'0003'


;----- T4CON Bits -----------------------------------------------------
TMR4ON           EQU  H'0002'

T4CKPS0          EQU  H'0000'
T4CKPS1          EQU  H'0001'
T4OUTPS0         EQU  H'0003'
T4OUTPS1         EQU  H'0004'
T4OUTPS2         EQU  H'0005'
T4OUTPS3         EQU  H'0006'


;----- LATA Bits -----------------------------------------------------
LATA0            EQU  H'0000'
LATA1            EQU  H'0001'
LATA2            EQU  H'0002'
LATA3            EQU  H'0003'
LATA5            EQU  H'0005'
LATA6            EQU  H'0006'
LATA7            EQU  H'0007'


;----- LATB Bits -----------------------------------------------------
LATB0            EQU  H'0000'
LATB1            EQU  H'0001'
LATB2            EQU  H'0002'
LATB3            EQU  H'0003'
LATB4            EQU  H'0004'
LATB5            EQU  H'0005'
LATB6            EQU  H'0006'
LATB7            EQU  H'0007'


;----- LATC Bits -----------------------------------------------------
LATC0            EQU  H'0000'
LATC1            EQU  H'0001'
LATC2            EQU  H'0002'
LATC3            EQU  H'0003'
LATC4            EQU  H'0004'
LATC5            EQU  H'0005'
LATC6            EQU  H'0006'
LATC7            EQU  H'0007'


;----- SLRCON Bits -----------------------------------------------------
SLRA             EQU  H'0000'
SLRB             EQU  H'0001'
SLRC             EQU  H'0002'


;----- ODCON Bits -----------------------------------------------------
U1OD             EQU  H'0000'
U2OD             EQU  H'0001'
CCP1OD           EQU  H'0002'
CCP2OD           EQU  H'0003'
CCP3OD           EQU  H'0004'
CCP4OD           EQU  H'0005'
CCP5OD           EQU  H'0006'
SSPOD            EQU  H'0007'


;----- TRISA Bits -----------------------------------------------------
TRISA0           EQU  H'0000'
TRISA1           EQU  H'0001'
TRISA2           EQU  H'0002'
TRISA3           EQU  H'0003'
TRISA5           EQU  H'0005'
TRISA6           EQU  H'0006'
TRISA7           EQU  H'0007'


;----- TRISB Bits -----------------------------------------------------
TRISB0           EQU  H'0000'
TRISB1           EQU  H'0001'
TRISB2           EQU  H'0002'
TRISB3           EQU  H'0003'
TRISB4           EQU  H'0004'
TRISB5           EQU  H'0005'
TRISB6           EQU  H'0006'
TRISB7           EQU  H'0007'


;----- TRISC Bits -----------------------------------------------------
TRISC0           EQU  H'0000'
TRISC1           EQU  H'0001'
TRISC2           EQU  H'0002'
TRISC3           EQU  H'0003'
TRISC4           EQU  H'0004'
TRISC5           EQU  H'0005'
TRISC6           EQU  H'0006'
TRISC7           EQU  H'0007'


;----- CCPTMRS Bits -----------------------------------------------------
C1TSEL           EQU  H'0000'
C2TSEL           EQU  H'0001'
C3TSEL           EQU  H'0002'
C4TSEL           EQU  H'0003'
C5TSEL           EQU  H'0004'


;----- REFOCON Bits -----------------------------------------------------
ROSEL            EQU  H'0004'
ROSSLP           EQU  H'0005'
ROON             EQU  H'0007'

RODIV0           EQU  H'0000'
RODIV1           EQU  H'0001'
RODIV2           EQU  H'0002'
RODIV3           EQU  H'0003'


;----- OSCTUNE Bits -----------------------------------------------------
PLLEN            EQU  H'0006'
INTSRC           EQU  H'0007'

TUN0             EQU  H'0000'
TUN1             EQU  H'0001'
TUN2             EQU  H'0002'
TUN3             EQU  H'0003'
TUN4             EQU  H'0004'
TUN5             EQU  H'0005'


;----- PSTR1CON Bits -----------------------------------------------------
STRA             EQU  H'0000'
STRB             EQU  H'0001'
STRC             EQU  H'0002'
STRD             EQU  H'0003'
STRSYNC          EQU  H'0004'

CMPL0            EQU  H'0006'
CMPL1            EQU  H'0007'


;----- PIE1 Bits -----------------------------------------------------
TMR1IE           EQU  H'0000'
TMR2IE           EQU  H'0001'
TMR1GIE          EQU  H'0002'
SSPIE            EQU  H'0003'
TX1IE            EQU  H'0004'
RC1IE            EQU  H'0005'
ADIE             EQU  H'0006'

TXIE             EQU  H'0004'
RCIE             EQU  H'0005'


;----- PIR1 Bits -----------------------------------------------------
TMR1IF           EQU  H'0000'
TMR2IF           EQU  H'0001'
TMR1GIF          EQU  H'0002'
SSPIF            EQU  H'0003'
TX1IF            EQU  H'0004'
RC1IF            EQU  H'0005'
ADIF             EQU  H'0006'

TXIF             EQU  H'0004'
RCIF             EQU  H'0005'


;----- IPR1 Bits -----------------------------------------------------
TMR1IP           EQU  H'0000'
TMR2IP           EQU  H'0001'
TMR1GIP          EQU  H'0002'
SSPIP            EQU  H'0003'
TX1IP            EQU  H'0004'
RC1IP            EQU  H'0005'
ADIP             EQU  H'0006'

TXIP             EQU  H'0004'
RCIP             EQU  H'0005'


;----- PIE2 Bits -----------------------------------------------------
TMR3GIE          EQU  H'0000'
TMR3IE           EQU  H'0001'
HLVDIE           EQU  H'0002'
BCLIE            EQU  H'0003'
OSCFIE           EQU  H'0007'

LVDIE            EQU  H'0002'


;----- PIR2 Bits -----------------------------------------------------
TMR3GIF          EQU  H'0000'
TMR3IF           EQU  H'0001'
HLVDIF           EQU  H'0002'
BCLIF            EQU  H'0003'
OSCFIF           EQU  H'0007'

LVDIF            EQU  H'0002'


;----- IPR2 Bits -----------------------------------------------------
TMR3GIP          EQU  H'0000'
TMR3IP           EQU  H'0001'
HLVDIP           EQU  H'0002'
BCLIP            EQU  H'0003'
OSCFIP           EQU  H'0007'

LVDIP            EQU  H'0002'


;----- PIE3 Bits -----------------------------------------------------
CCP1IE           EQU  H'0001'
CCP2IE           EQU  H'0002'
CTMUIE           EQU  H'0003'
TX2IE            EQU  H'0004'
RC2IE            EQU  H'0005'


;----- PIR3 Bits -----------------------------------------------------
CCP1IF           EQU  H'0001'
CCP2IF           EQU  H'0002'
CTMUIF           EQU  H'0003'
TX2IF            EQU  H'0004'
RC2IF            EQU  H'0005'


;----- IPR3 Bits -----------------------------------------------------
CCP1IP           EQU  H'0001'
CCP2IP           EQU  H'0002'
CTMUIP           EQU  H'0003'
TX2IP            EQU  H'0004'
RC2IP            EQU  H'0005'


;----- RCSTA2 Bits -----------------------------------------------------
RX9D             EQU  H'0000'
OERR             EQU  H'0001'
FERR             EQU  H'0002'
ADDEN            EQU  H'0003'
CREN             EQU  H'0004'
SREN             EQU  H'0005'
RX9              EQU  H'0006'
SPEN             EQU  H'0007'

RX9D2            EQU  H'0000'
OERR2            EQU  H'0001'
FERR2            EQU  H'0002'
ADDEN2           EQU  H'0003'
CREN2            EQU  H'0004'
SREN2            EQU  H'0005'
RX92             EQU  H'0006'
SPEN2            EQU  H'0007'


;----- BAUDCON1 Bits -----------------------------------------------------
ABDEN            EQU  H'0000'
WUE              EQU  H'0001'
BRG16            EQU  H'0003'
TXCKP            EQU  H'0004'
RXDTP            EQU  H'0005'
RCIDL            EQU  H'0006'
ABDOVF           EQU  H'0007'

RCMT             EQU  H'0006'


;----- HLVDCON Bits -----------------------------------------------------
HLVDEN           EQU  H'0004'
IRVST            EQU  H'0005'
BGVST            EQU  H'0006'
VDIRMAG          EQU  H'0007'

HLVDL0           EQU  H'0000'
HLVDL1           EQU  H'0001'
HLVDL2           EQU  H'0002'
HLVDL3           EQU  H'0003'


;----- T1GCON Bits -----------------------------------------------------
T1GVAL           EQU  H'0002'
T1GGO_NOT_T1DONE EQU  H'0003'
T1GSPM           EQU  H'0004'
T1GTM            EQU  H'0005'
T1GPOL           EQU  H'0006'
TMR1GE           EQU  H'0007'

T1GSS0           EQU  H'0000'
T1GSS1           EQU  H'0001'
T1GGO            EQU  H'0003'

NOT_T1DONE       EQU  H'0003'


;----- RCSTA Bits -----------------------------------------------------
RX9D             EQU  H'0000'
OERR             EQU  H'0001'
FERR             EQU  H'0002'
ADDEN            EQU  H'0003'
CREN             EQU  H'0004'
SREN             EQU  H'0005'
RX9              EQU  H'0006'
SPEN             EQU  H'0007'

RCD8             EQU  H'0000'
ADEN             EQU  H'0003'
RC9              EQU  H'0006'

NOT_RC8          EQU  H'0006'

RC8_9            EQU  H'0006'

RX9D1            EQU  H'0000'
OERR1            EQU  H'0001'
FERR1            EQU  H'0002'
ADDEN1           EQU  H'0003'
CREN1            EQU  H'0004'
SREN1            EQU  H'0005'
RX91             EQU  H'0006'
SPEN1            EQU  H'0007'


;----- RCSTA1 Bits -----------------------------------------------------
RX9D             EQU  H'0000'
OERR             EQU  H'0001'
FERR             EQU  H'0002'
ADDEN            EQU  H'0003'
CREN             EQU  H'0004'
SREN             EQU  H'0005'
RX9              EQU  H'0006'
SPEN             EQU  H'0007'

RCD8             EQU  H'0000'
ADEN             EQU  H'0003'
RC9              EQU  H'0006'

NOT_RC8          EQU  H'0006'

RC8_9            EQU  H'0006'

RX9D1            EQU  H'0000'
OERR1            EQU  H'0001'
FERR1            EQU  H'0002'
ADDEN1           EQU  H'0003'
CREN1            EQU  H'0004'
SREN1            EQU  H'0005'
RX91             EQU  H'0006'
SPEN1            EQU  H'0007'


;----- TXSTA Bits -----------------------------------------------------
TX9D             EQU  H'0000'
TRMT             EQU  H'0001'
BRGH             EQU  H'0002'
SENDB            EQU  H'0003'
SYNC             EQU  H'0004'
TXEN             EQU  H'0005'
TX9              EQU  H'0006'
CSRC             EQU  H'0007'

TXD8             EQU  H'0000'
TX8_9            EQU  H'0006'

NOT_TX8          EQU  H'0006'

TX9D1            EQU  H'0000'
TRMT1            EQU  H'0001'
BRGH1            EQU  H'0002'
SENDB1           EQU  H'0003'
SYNC1            EQU  H'0004'
TXEN1            EQU  H'0005'
TX91             EQU  H'0006'
CSRC1            EQU  H'0007'


;----- TXSTA1 Bits -----------------------------------------------------
TX9D             EQU  H'0000'
TRMT             EQU  H'0001'
BRGH             EQU  H'0002'
SENDB            EQU  H'0003'
SYNC             EQU  H'0004'
TXEN             EQU  H'0005'
TX9              EQU  H'0006'
CSRC             EQU  H'0007'

TXD8             EQU  H'0000'
TX8_9            EQU  H'0006'

NOT_TX8          EQU  H'0006'

TX9D1            EQU  H'0000'
TRMT1            EQU  H'0001'
BRGH1            EQU  H'0002'
SENDB1           EQU  H'0003'
SYNC1            EQU  H'0004'
TXEN1            EQU  H'0005'
TX91             EQU  H'0006'
CSRC1            EQU  H'0007'


;----- T3GCON Bits -----------------------------------------------------
T3GVAL           EQU  H'0002'
T3GGO_NOT_T3DONE EQU  H'0003'
T3GSPM           EQU  H'0004'
T3GTM            EQU  H'0005'
T3GPOL           EQU  H'0006'
TMR3GE           EQU  H'0007'

T3GSS0           EQU  H'0000'
T3GSS1           EQU  H'0001'
T3GGO            EQU  H'0003'

NOT_T3DONE       EQU  H'0003'


;----- T3CON Bits -----------------------------------------------------
TMR3ON           EQU  H'0000'
RD16             EQU  H'0001'
NOT_T3SYNC       EQU  H'0002'
SOSCEN           EQU  H'0003'

T3CKPS0          EQU  H'0004'
T3CKPS1          EQU  H'0005'
TMR3CS0          EQU  H'0006'
TMR3CS1          EQU  H'0007'


;----- CMSTAT Bits -----------------------------------------------------
CMP1OUT          EQU  H'0006'
CMP2OUT          EQU  H'0007'


;----- CMSTATUS Bits -----------------------------------------------------
CMP1OUT          EQU  H'0006'
CMP2OUT          EQU  H'0007'


;----- CVRCON Bits -----------------------------------------------------
CVRSS            EQU  H'0005'
CVROE            EQU  H'0006'
CVREN            EQU  H'0007'

CVR0             EQU  H'0000'
CVR1             EQU  H'0001'
CVR2             EQU  H'0002'
CVR3             EQU  H'0003'
CVR4             EQU  H'0004'


;----- PIE4 Bits -----------------------------------------------------
CCP3IE           EQU  H'0000'
CCP4IE           EQU  H'0001'
CCP5IE           EQU  H'0002'
CMP1IE           EQU  H'0004'
CMP2IE           EQU  H'0005'
EEIE             EQU  H'0006'
TMR4IE           EQU  H'0007'


;----- PIR4 Bits -----------------------------------------------------
CCP3IF           EQU  H'0000'
CCP4IF           EQU  H'0001'
CCP5IF           EQU  H'0002'
CMP1IF           EQU  H'0004'
CMP2IF           EQU  H'0005'
EEIF             EQU  H'0006'
TMR4IF           EQU  H'0007'


;----- IPR4 Bits -----------------------------------------------------
CCP3IP           EQU  H'0000'
CCP4IP           EQU  H'0001'
CCP5IP           EQU  H'0002'
CMP1IP           EQU  H'0004'
CMP2IP           EQU  H'0005'
EEIP             EQU  H'0006'
TMR4IP           EQU  H'0007'


;----- BAUDCON2 Bits -----------------------------------------------------
ABDEN            EQU  H'0000'
WUE              EQU  H'0001'
BRG16            EQU  H'0003'
TXCKP            EQU  H'0004'
RXDTP            EQU  H'0005'
RCIDL            EQU  H'0006'
ABDOVF           EQU  H'0007'

RCMT             EQU  H'0006'


;----- TXSTA2 Bits -----------------------------------------------------
TX9D             EQU  H'0000'
TRMT             EQU  H'0001'
BRGH             EQU  H'0002'
SENDB            EQU  H'0003'
SYNC             EQU  H'0004'
TXEN             EQU  H'0005'
TX9              EQU  H'0006'
CSRC             EQU  H'0007'

TX9D2            EQU  H'0000'
TRMT2            EQU  H'0001'
BRGH2            EQU  H'0002'
SENDB2           EQU  H'0003'
SYNC2            EQU  H'0004'
TXEN2            EQU  H'0005'
TX92             EQU  H'0006'
CSRC2            EQU  H'0007'


;----- CCP1CON Bits -----------------------------------------------------
CCP1M0           EQU  H'0000'
CCP1M1           EQU  H'0001'
CCP1M2           EQU  H'0002'
CCP1M3           EQU  H'0003'
DC1B0            EQU  H'0004'
DC1B1            EQU  H'0005'
P1M0             EQU  H'0006'
P1M1             EQU  H'0007'

CCP1Y            EQU  H'0004'
CCP1X            EQU  H'0005'


;----- ECCP1CON Bits -----------------------------------------------------
CCP1M0           EQU  H'0000'
CCP1M1           EQU  H'0001'
CCP1M2           EQU  H'0002'
CCP1M3           EQU  H'0003'
DC1B0            EQU  H'0004'
DC1B1            EQU  H'0005'
P1M0             EQU  H'0006'
P1M1             EQU  H'0007'

CCP1Y            EQU  H'0004'
CCP1X            EQU  H'0005'


;----- ECCP1DEL Bits -----------------------------------------------------
P1RSEN           EQU  H'0007'

P1DC0            EQU  H'0000'
P1DC1            EQU  H'0001'
P1DC2            EQU  H'0002'
P1DC3            EQU  H'0003'
P1DC4            EQU  H'0004'
P1DC5            EQU  H'0005'
P1DC6            EQU  H'0006'


;----- PWM1CON Bits -----------------------------------------------------
P1RSEN           EQU  H'0007'

P1DC0            EQU  H'0000'
P1DC1            EQU  H'0001'
P1DC2            EQU  H'0002'
P1DC3            EQU  H'0003'
P1DC4            EQU  H'0004'
P1DC5            EQU  H'0005'
P1DC6            EQU  H'0006'


;----- ECCP1AS Bits -----------------------------------------------------
ECCP1ASE         EQU  H'0007'

PSS1BD0          EQU  H'0000'
PSS1BD1          EQU  H'0001'
PSS1AC0          EQU  H'0002'
PSS1AC1          EQU  H'0003'
ECCP1AS0         EQU  H'0004'
ECCP1AS1         EQU  H'0005'
ECCP1AS2         EQU  H'0006'


;----- ADCON2 Bits -----------------------------------------------------
ADFM             EQU  H'0007'

ADCS0            EQU  H'0000'
ADCS1            EQU  H'0001'
ADCS2            EQU  H'0002'
ACQT0            EQU  H'0003'
ACQT1            EQU  H'0004'
ACQT2            EQU  H'0005'


;----- ADCON1 Bits -----------------------------------------------------
VNCFG            EQU  H'0003'

CHSN0            EQU  H'0000'
CHSN1            EQU  H'0001'
CHSN2            EQU  H'0002'
VCFG0            EQU  H'0004'
VCFG1            EQU  H'0005'
TRIGSEL0         EQU  H'0006'
TRIGSEL1         EQU  H'0007'


;----- ADCON0 Bits -----------------------------------------------------
ADON             EQU  H'0000'
GO_NOT_DONE      EQU  H'0001'

DONE             EQU  H'0001'
CHS0             EQU  H'0002'
CHS1             EQU  H'0003'
CHS2             EQU  H'0004'
CHS3             EQU  H'0005'
CHS4             EQU  H'0006'

GO               EQU  H'0001'

NOT_DONE         EQU  H'0001'


;----- SSPCON2 Bits -----------------------------------------------------
SEN              EQU  H'0000'
RSEN             EQU  H'0001'
PEN              EQU  H'0002'
RCEN             EQU  H'0003'
ACKEN            EQU  H'0004'
ACKDT            EQU  H'0005'
ACKSTAT          EQU  H'0006'
GCEN             EQU  H'0007'

ADMSK1           EQU  H'0001'
ADMSK2           EQU  H'0002'
ADMSK3           EQU  H'0003'
ADMSK4           EQU  H'0004'
ADMSK5           EQU  H'0005'


;----- SSPCON1 Bits -----------------------------------------------------
CKP              EQU  H'0004'
SSPEN            EQU  H'0005'
SSPOV            EQU  H'0006'
WCOL             EQU  H'0007'

SSPM0            EQU  H'0000'
SSPM1            EQU  H'0001'
SSPM2            EQU  H'0002'
SSPM3            EQU  H'0003'


;----- SSPSTAT Bits -----------------------------------------------------
BF               EQU  H'0000'
UA               EQU  H'0001'
R_NOT_W          EQU  H'0002'
S                EQU  H'0003'
P                EQU  H'0004'
D_NOT_A          EQU  H'0005'
CKE              EQU  H'0006'
SMP              EQU  H'0007'

R_W              EQU  H'0002'
D_A              EQU  H'0005'

NOT_W            EQU  H'0002'
NOT_A            EQU  H'0005'

NOT_WRITE        EQU  H'0002'
NOT_ADDRESS      EQU  H'0005'

READ_WRITE       EQU  H'0002'
DATA_ADDRESS     EQU  H'0005'

I2C_READ         EQU  H'0002'
I2C_START        EQU  H'0003'
I2C_STOP         EQU  H'0004'
I2C_DAT          EQU  H'0005'


;----- SSPADD Bits -----------------------------------------------------
MSK0             EQU  H'0000'
MSK1             EQU  H'0001'
MSK2             EQU  H'0002'
MSK3             EQU  H'0003'
MSK4             EQU  H'0004'
MSK5             EQU  H'0005'
MSK6             EQU  H'0006'
MSK7             EQU  H'0007'


;----- T2CON Bits -----------------------------------------------------
TMR2ON           EQU  H'0002'

T2CKPS0          EQU  H'0000'
T2CKPS1          EQU  H'0001'
T2OUTPS0         EQU  H'0003'
T2OUTPS1         EQU  H'0004'
T2OUTPS2         EQU  H'0005'
T2OUTPS3         EQU  H'0006'


;----- T1CON Bits -----------------------------------------------------
TMR1ON           EQU  H'0000'
RD16             EQU  H'0001'
NOT_T1SYNC       EQU  H'0002'
SOSCEN           EQU  H'0003'

T1CKPS0          EQU  H'0004'
T1CKPS1          EQU  H'0005'
TMR1CS0          EQU  H'0006'
TMR1CS1          EQU  H'0007'


;----- RCON Bits -----------------------------------------------------
NOT_BOR          EQU  H'0000'
NOT_POR          EQU  H'0001'
NOT_PD           EQU  H'0002'
NOT_TO           EQU  H'0003'
NOT_RI           EQU  H'0004'
NOT_CM           EQU  H'0005'
SBOREN           EQU  H'0006'
IPEN             EQU  H'0007'

BOR              EQU  H'0000'
POR              EQU  H'0001'
PD               EQU  H'0002'
TO               EQU  H'0003'
RI               EQU  H'0004'
CM               EQU  H'0005'


;----- WDTCON Bits -----------------------------------------------------
SWDTEN           EQU  H'0000'
ULPSINK          EQU  H'0001'
ULPEN            EQU  H'0002'
SRETEN           EQU  H'0004'
ULPLVL           EQU  H'0005'
REGSLP           EQU  H'0007'

SWDTE            EQU  H'0000'


;----- OSCCON2 Bits -----------------------------------------------------
MFIOSEL          EQU  H'0000'
MFIOFS           EQU  H'0001'
SOSCGO           EQU  H'0003'
SOSCDRV          EQU  H'0004'
SOSCRUN          EQU  H'0006'

LVDL0            EQU  H'0000'
LVDL1            EQU  H'0001'
LVDL2            EQU  H'0002'
LVDL3            EQU  H'0003'


;----- OSCCON Bits -----------------------------------------------------
HFIOFS           EQU  H'0002'
OSTS             EQU  H'0003'
IDLEN            EQU  H'0007'

SCS0             EQU  H'0000'
SCS1             EQU  H'0001'
IRCF0            EQU  H'0004'
IRCF1            EQU  H'0005'
IRCF2            EQU  H'0006'


;----- T0CON Bits -----------------------------------------------------
PSA              EQU  H'0003'
T0SE             EQU  H'0004'
T0CS             EQU  H'0005'
T08BIT           EQU  H'0006'
TMR0ON           EQU  H'0007'

T0PS0            EQU  H'0000'
T0PS1            EQU  H'0001'
T0PS2            EQU  H'0002'


;----- STATUS Bits -----------------------------------------------------
C                EQU  H'0000'
DC               EQU  H'0001'
Z                EQU  H'0002'
OV               EQU  H'0003'
N                EQU  H'0004'


;----- INTCON3 Bits -----------------------------------------------------
INT1IF           EQU  H'0000'
INT2IF           EQU  H'0001'
INT3IF           EQU  H'0002'
INT1IE           EQU  H'0003'
INT2IE           EQU  H'0004'
INT3IE           EQU  H'0005'
INT1IP           EQU  H'0006'
INT2IP           EQU  H'0007'

INT1F            EQU  H'0000'
INT2F            EQU  H'0001'
INT3F            EQU  H'0002'
INT1E            EQU  H'0003'
INT2E            EQU  H'0004'
INT3E            EQU  H'0005'
INT1P            EQU  H'0006'
INT2P            EQU  H'0007'


;----- INTCON2 Bits -----------------------------------------------------
RBIP             EQU  H'0000'
INT3IP           EQU  H'0001'
TMR0IP           EQU  H'0002'
INTEDG3          EQU  H'0003'
INTEDG2          EQU  H'0004'
INTEDG1          EQU  H'0005'
INTEDG0          EQU  H'0006'
NOT_RBPU         EQU  H'0007'

INT3P            EQU  H'0001'
T0IP             EQU  H'0002'
RBPU             EQU  H'0007'


;----- INTCON Bits -----------------------------------------------------
RBIF             EQU  H'0000'
INT0IF           EQU  H'0001'
TMR0IF           EQU  H'0002'
RBIE             EQU  H'0003'
INT0IE           EQU  H'0004'
TMR0IE           EQU  H'0005'
PEIE_GIEL        EQU  H'0006'
GIE_GIEH         EQU  H'0007'

INT0F            EQU  H'0001'
T0IF             EQU  H'0002'
INT0E            EQU  H'0004'
T0IE             EQU  H'0005'
PEIE             EQU  H'0006'
GIE              EQU  H'0007'

GIEL             EQU  H'0006'
GIEH             EQU  H'0007'


;----- INTCON1 Bits -----------------------------------------------------
RBIF             EQU  H'0000'
INT0IF           EQU  H'0001'
TMR0IF           EQU  H'0002'
RBIE             EQU  H'0003'
INT0IE           EQU  H'0004'
TMR0IE           EQU  H'0005'
PEIE_GIEL        EQU  H'0006'
GIE_GIEH         EQU  H'0007'

INT0F            EQU  H'0001'
T0IF             EQU  H'0002'
INT0E            EQU  H'0004'
T0IE             EQU  H'0005'
PEIE             EQU  H'0006'
GIE              EQU  H'0007'

GIEL             EQU  H'0006'
GIEH             EQU  H'0007'


;----- STKPTR Bits -----------------------------------------------------
STKUNF           EQU  H'0006'
STKFUL           EQU  H'0007'

SP0              EQU  H'0000'
SP1              EQU  H'0001'
SP2              EQU  H'0002'
SP3              EQU  H'0003'
SP4              EQU  H'0004'
STKOVF           EQU  H'0007'



;==========================================================================
;
;       RAM Definitions
;
;==========================================================================
       __MAXRAM  H'0FFF'
       __BADRAM  H'0F40'-H'0F46'
       __BADRAM  H'0F83'
       __BADRAM  H'0F85'-H'0F86'
       __BADRAM  H'0F8C'-H'0F8F'
       __BADRAM  H'0F95'-H'0F98'
       __BADRAM  H'0FD4'

;==========================================================================
;
;   IMPORTANT: For the PIC18 devices, the __CONFIG directive has been
;              superseded by the CONFIG directive.  The following settings
;              are available for this device.
;
;   VREG Sleep Enable bit:
;     RETEN = ON           Ultra low-power regulator is Enabled (Controlled by SRETEN bit)
;     RETEN = OFF          Ultra low-power regulator is Disabled (Controlled by REGSLP bit)
;
;   LF-INTOSC Low-power Enable bit:
;     INTOSCSEL = LOW      LF-INTOSC in Low-power mode during Sleep
;     INTOSCSEL = HIGH     LF-INTOSC in High-power mode during Sleep
;
;   SOSC Power Selection and mode Configuration bits:
;     SOSCSEL = LOW        Low Power SOSC circuit selected
;     SOSCSEL = DIG        Digital (SCLKI) mode
;     SOSCSEL = HIGH       High Power SOSC circuit selected
;
;   Extended Instruction Set:
;     XINST = OFF          Disabled
;     XINST = ON           Enabled
;
;   Oscillator:
;     FOSC = LP            LP oscillator
;     FOSC = XT            XT oscillator
;     FOSC = HS2           HS oscillator (High power, 16 MHz - 25 MHz)
;     FOSC = HS1           HS oscillator (Medium power, 4 MHz - 16 MHz)
;     FOSC = EC3IO         EC oscillator, CLKOUT function on OSC2 (High power, 16 MHz - 64 MHz)
;     FOSC = EC3           EC oscillator (High power, 16 MHz - 64 MHz)
;     FOSC = RC            External RC oscillator, CLKOUT function on OSC2
;     FOSC = RCIO          External RC oscillator
;     FOSC = INTIO2        Internal RC oscillator
;     FOSC = INTIO1        Internal RC oscillator, CLKOUT function on OSC2
;     FOSC = EC2IO         EC oscillator, CLKOUT function on OSC2 (Medium power, 160 kHz - 4 MHz)
;     FOSC = EC2           EC oscillator (Medium power, 160 kHz - 4 MHz)
;     FOSC = EC1IO         EC oscillator, CLKOUT function on OSC2 (Low power, DC - 160 kHz)
;     FOSC = EC1           EC oscillator (Low power, DC - 160 kHz)
;
;   PLL x4 Enable bit:
;     PLLCFG = OFF         Disabled
;     PLLCFG = ON          Enabled
;
;   Fail-Safe Clock Monitor:
;     FCMEN = OFF          Disabled
;     FCMEN = ON           Enabled
;
;   Internal External Oscillator Switch Over Mode:
;     IESO = OFF           Disabled
;     IESO = ON            Enabled
;
;   Power Up Timer:
;     PWRTEN = ON          Enabled
;     PWRTEN = OFF         Disabled
;
;   Brown Out Detect:
;     BOREN = OFF          Disabled in hardware, SBOREN disabled
;     BOREN = ON           Controlled with SBOREN bit
;     BOREN = NOSLP        Enabled while active, disabled in SLEEP, SBOREN disabled
;     BOREN = SBORDIS      Enabled in hardware, SBOREN disabled
;
;   Brown-out Reset Voltage bits:
;     BORV = 0             3.0V
;     BORV = 1             2.7V
;     BORV = 2             2.0V
;     BORV = 3             1.8V
;
;   BORMV Power level:
;     BORPWR = LOW         BORMV set to low power level
;     BORPWR = MEDIUM      BORMV set to medium power level
;     BORPWR = HIGH        BORMV set to high power level
;     BORPWR = ZPBORMV     ZPBORMV instead of BORMV is selected
;
;   Watchdog Timer:
;     WDTEN = OFF          WDT disabled in hardware; SWDTEN bit disabled
;     WDTEN = NOSLP        WDT enabled only while device is active and disabled in Sleep mode; SWDTEN bit disabled
;     WDTEN = ON           WDT controlled by SWDTEN bit setting
;     WDTEN = SWDTDIS      WDT enabled in hardware; SWDTEN bit disabled
;
;   Watchdog Postscaler:
;     WDTPS = 1            1:1
;     WDTPS = 2            1:2
;     WDTPS = 4            1:4
;     WDTPS = 8            1:8
;     WDTPS = 16           1:16
;     WDTPS = 32           1:32
;     WDTPS = 64           1:64
;     WDTPS = 128          1:128
;     WDTPS = 256          1:256
;     WDTPS = 512          1:512
;     WDTPS = 1024         1:1024
;     WDTPS = 2048         1:2048
;     WDTPS = 4096         1:4096
;     WDTPS = 8192         1:8192
;     WDTPS = 16384        1:16384
;     WDTPS = 32768        1:32768
;     WDTPS = 65536        1:65536
;     WDTPS = 131072       1:131072
;     WDTPS = 262144       1:262144
;     WDTPS = 524288       1:524288
;     WDTPS = 1048576      1:1048576
;
;   ECAN Mux bit:
;     CANMX = PORTC        ECAN TX and RX pins are located on RC6 and RC7, respectively
;     CANMX = PORTB        ECAN TX and RX pins are located on RB2 and RB3, respectively
;
;   MSSP address masking:
;     MSSPMSK = MSK5       5 bit address masking mode
;     MSSPMSK = MSK7       7 Bit address masking mode
;
;   Master Clear Enable:
;     MCLRE = OFF          MCLR Disabled, RG5 Enabled
;     MCLRE = ON           MCLR Enabled, RG5 Disabled
;
;   Stack Overflow Reset:
;     STVREN = OFF         Disabled
;     STVREN = ON          Enabled
;
;   Boot Block Size:
;     BBSIZ = BB1K         1K word Boot Block size
;     BBSIZ = BB2K         2K word Boot Block size
;
;   Code Protect 00800-03FFF:
;     CP0 = ON             Enabled
;     CP0 = OFF            Disabled
;
;   Code Protect 04000-07FFF:
;     CP1 = ON             Enabled
;     CP1 = OFF            Disabled
;
;   Code Protect 08000-0BFFF:
;     CP2 = ON             Enabled
;     CP2 = OFF            Disabled
;
;   Code Protect 0C000-0FFFF:
;     CP3 = ON             Enabled
;     CP3 = OFF            Disabled
;
;   Code Protect Boot:
;     CPB = ON             Enabled
;     CPB = OFF            Disabled
;
;   Data EE Read Protect:
;     CPD = ON             Enabled
;     CPD = OFF            Disabled
;
;   Table Write Protect 00800-03FFF:
;     WRT0 = ON            Enabled
;     WRT0 = OFF           Disabled
;
;   Table Write Protect 04000-07FFF:
;     WRT1 = ON            Enabled
;     WRT1 = OFF           Disabled
;
;   Table Write Protect 08000-0BFFF:
;     WRT2 = ON            Enabled
;     WRT2 = OFF           Disabled
;
;   Table Write Protect 0C000-0FFFF:
;     WRT3 = ON            Enabled
;     WRT3 = OFF           Disabled
;
;   Config. Write Protect:
;     WRTC = ON            Enabled
;     WRTC = OFF           Disabled
;
;   Table Write Protect Boot:
;     WRTB = ON            Enabled
;     WRTB = OFF           Disabled
;
;   Data EE Write Protect:
;     WRTD = ON            Enabled
;     WRTD = OFF           Disabled
;
;   Table Read Protect 00800-03FFF:
;     EBTR0 = ON           Enabled
;     EBTR0 = OFF          Disabled
;
;   Table Read Protect 04000-07FFF:
;     EBTR1 = ON           Enabled
;     EBTR1 = OFF          Disabled
;
;   Table Read Protect 08000-0BFFF:
;     EBTR2 = ON           Enabled
;     EBTR2 = OFF          Disabled
;
;   Table Read Protect 0C000-0FFFF:
;     EBTR3 = ON           Enabled
;     EBTR3 = OFF          Disabled
;
;   Table Read Protect Boot:
;     EBTRB = ON           Enabled
;     EBTRB = OFF          Disabled
;
;==========================================================================
;==========================================================================
;
;       Configuration Bits
;
;   NAME            Address
;   CONFIG1L        300000h
;   CONFIG1H        300001h
;   CONFIG2L        300002h
;   CONFIG2H        300003h
;   CONFIG3H        300005h
;   CONFIG4L        300006h
;   CONFIG5L        300008h
;   CONFIG5H        300009h
;   CONFIG6L        30000Ah
;   CONFIG6H        30000Bh
;   CONFIG7L        30000Ch
;   CONFIG7H        30000Dh
;
;==========================================================================

; The following is an assignment of address values for all of the
; configuration registers for the purpose of table reads
_CONFIG1L        EQU  H'300000'
_CONFIG1H        EQU  H'300001'
_CONFIG2L        EQU  H'300002'
_CONFIG2H        EQU  H'300003'
_CONFIG3H        EQU  H'300005'
_CONFIG4L        EQU  H'300006'
_CONFIG5L        EQU  H'300008'
_CONFIG5H        EQU  H'300009'
_CONFIG6L        EQU  H'30000A'
_CONFIG6H        EQU  H'30000B'
_CONFIG7L        EQU  H'30000C'
_CONFIG7H        EQU  H'30000D'

;----- CONFIG1L Options --------------------------------------------------
_RETEN_ON_1L         EQU  H'FE'    ; Ultra low-power regulator is Enabled (Controlled by SRETEN bit)
_RETEN_OFF_1L        EQU  H'FF'    ; Ultra low-power regulator is Disabled (Controlled by REGSLP bit)

_INTOSCSEL_LOW_1L    EQU  H'FB'    ; LF-INTOSC in Low-power mode during Sleep
_INTOSCSEL_HIGH_1L   EQU  H'FF'    ; LF-INTOSC in High-power mode during Sleep

_SOSCSEL_LOW_1L      EQU  H'EF'    ; Low Power SOSC circuit selected
_SOSCSEL_DIG_1L      EQU  H'F7'    ; Digital (SCLKI) mode
_SOSCSEL_HIGH_1L     EQU  H'FF'    ; High Power SOSC circuit selected

_XINST_OFF_1L        EQU  H'BF'    ; Disabled
_XINST_ON_1L         EQU  H'FF'    ; Enabled

;----- CONFIG1H Options --------------------------------------------------
_FOSC_LP_1H          EQU  H'F0'    ; LP oscillator
_FOSC_XT_1H          EQU  H'F1'    ; XT oscillator
_FOSC_HS2_1H         EQU  H'F2'    ; HS oscillator (High power, 16 MHz - 25 MHz)
_FOSC_HS1_1H         EQU  H'F3'    ; HS oscillator (Medium power, 4 MHz - 16 MHz)
_FOSC_EC3IO_1H       EQU  H'F4'    ; EC oscillator, CLKOUT function on OSC2 (High power, 16 MHz - 64 MHz)
_FOSC_EC3_1H         EQU  H'F5'    ; EC oscillator (High power, 16 MHz - 64 MHz)
_FOSC_RC_1H          EQU  H'F6'    ; External RC oscillator, CLKOUT function on OSC2
_FOSC_RCIO_1H        EQU  H'F7'    ; External RC oscillator
_FOSC_INTIO2_1H      EQU  H'F8'    ; Internal RC oscillator
_FOSC_INTIO1_1H      EQU  H'F9'    ; Internal RC oscillator, CLKOUT function on OSC2
_FOSC_EC2IO_1H       EQU  H'FA'    ; EC oscillator, CLKOUT function on OSC2 (Medium power, 160 kHz - 4 MHz)
_FOSC_EC2_1H         EQU  H'FB'    ; EC oscillator (Medium power, 160 kHz - 4 MHz)
_FOSC_EC1IO_1H       EQU  H'FC'    ; EC oscillator, CLKOUT function on OSC2 (Low power, DC - 160 kHz)
_FOSC_EC1_1H         EQU  H'FD'    ; EC oscillator (Low power, DC - 160 kHz)

_PLLCFG_OFF_1H       EQU  H'EF'    ; Disabled
_PLLCFG_ON_1H        EQU  H'FF'    ; Enabled

_FCMEN_OFF_1H        EQU  H'BF'    ; Disabled
_FCMEN_ON_1H         EQU  H'FF'    ; Enabled

_IESO_OFF_1H         EQU  H'7F'    ; Disabled
_IESO_ON_1H          EQU  H'FF'    ; Enabled

;----- CONFIG2L Options --------------------------------------------------
_PWRTEN_ON_2L        EQU  H'FE'    ; Enabled
_PWRTEN_OFF_2L       EQU  H'FF'    ; Disabled

_BOREN_OFF_2L        EQU  H'F9'    ; Disabled in hardware, SBOREN disabled
_BOREN_ON_2L         EQU  H'FB'    ; Controlled with SBOREN bit
_BOREN_NOSLP_2L      EQU  H'FD'    ; Enabled while active, disabled in SLEEP, SBOREN disabled
_BOREN_SBORDIS_2L    EQU  H'FF'    ; Enabled in hardware, SBOREN disabled

_BORV_0_2L           EQU  H'E7'    ; 3.0V
_BORV_1_2L           EQU  H'EF'    ; 2.7V
_BORV_2_2L           EQU  H'F7'    ; 2.0V
_BORV_3_2L           EQU  H'FF'    ; 1.8V

_BORPWR_LOW_2L       EQU  H'9F'    ; BORMV set to low power level
_BORPWR_MEDIUM_2L    EQU  H'BF'    ; BORMV set to medium power level
_BORPWR_HIGH_2L      EQU  H'DF'    ; BORMV set to high power level
_BORPWR_ZPBORMV_2L   EQU  H'FF'    ; ZPBORMV instead of BORMV is selected

;----- CONFIG2H Options --------------------------------------------------
_WDTEN_OFF_2H        EQU  H'FC'    ; WDT disabled in hardware; SWDTEN bit disabled
_WDTEN_NOSLP_2H      EQU  H'FD'    ; WDT enabled only while device is active and disabled in Sleep mode; SWDTEN bit disabled
_WDTEN_ON_2H         EQU  H'FE'    ; WDT controlled by SWDTEN bit setting
_WDTEN_SWDTDIS_2H    EQU  H'FF'    ; WDT enabled in hardware; SWDTEN bit disabled

_WDTPS_1_2H          EQU  H'83'    ; 1:1
_WDTPS_2_2H          EQU  H'87'    ; 1:2
_WDTPS_4_2H          EQU  H'8B'    ; 1:4
_WDTPS_8_2H          EQU  H'8F'    ; 1:8
_WDTPS_16_2H         EQU  H'93'    ; 1:16
_WDTPS_32_2H         EQU  H'97'    ; 1:32
_WDTPS_64_2H         EQU  H'9B'    ; 1:64
_WDTPS_128_2H        EQU  H'9F'    ; 1:128
_WDTPS_256_2H        EQU  H'A3'    ; 1:256
_WDTPS_512_2H        EQU  H'A7'    ; 1:512
_WDTPS_1024_2H       EQU  H'AB'    ; 1:1024
_WDTPS_2048_2H       EQU  H'AF'    ; 1:2048
_WDTPS_4096_2H       EQU  H'B3'    ; 1:4096
_WDTPS_8192_2H       EQU  H'B7'    ; 1:8192
_WDTPS_16384_2H      EQU  H'BB'    ; 1:16384
_WDTPS_32768_2H      EQU  H'BF'    ; 1:32768
_WDTPS_65536_2H      EQU  H'C3'    ; 1:65536
_WDTPS_131072_2H     EQU  H'C7'    ; 1:131072
_WDTPS_262144_2H     EQU  H'CB'    ; 1:262144
_WDTPS_524288_2H     EQU  H'CF'    ; 1:524288
_WDTPS_1048576_2H    EQU  H'FF'    ; 1:1048576

;----- CONFIG3H Options --------------------------------------------------
_CANMX_PORTC_3H      EQU  H'FE'    ; ECAN TX and RX pins are located on RC6 and RC7, respectively
_CANMX_PORTB_3H      EQU  H'FF'    ; ECAN TX and RX pins are located on RB2 and RB3, respectively

_MSSPMSK_MSK5_3H     EQU  H'F7'    ; 5 bit address masking mode
_MSSPMSK_MSK7_3H     EQU  H'FF'    ; 7 Bit address masking mode

_MCLRE_OFF_3H        EQU  H'7F'    ; MCLR Disabled, RG5 Enabled
_MCLRE_ON_3H         EQU  H'FF'    ; MCLR Enabled, RG5 Disabled

;----- CONFIG4L Options --------------------------------------------------
_STVREN_OFF_4L       EQU  H'FE'    ; Disabled
_STVREN_ON_4L        EQU  H'FF'    ; Enabled

_BBSIZ_BB1K_4L       EQU  H'EF'    ; 1K word Boot Block size
_BBSIZ_BB2K_4L       EQU  H'FF'    ; 2K word Boot Block size

;----- CONFIG5L Options --------------------------------------------------
_CP0_ON_5L           EQU  H'FE'    ; Enabled
_CP0_OFF_5L          EQU  H'FF'    ; Disabled

_CP1_ON_5L           EQU  H'FD'    ; Enabled
_CP1_OFF_5L          EQU  H'FF'    ; Disabled

_CP2_ON_5L           EQU  H'FB'    ; Enabled
_CP2_OFF_5L          EQU  H'FF'    ; Disabled

_CP3_ON_5L           EQU  H'F7'    ; Enabled
_CP3_OFF_5L          EQU  H'FF'    ; Disabled

;----- CONFIG5H Options --------------------------------------------------
_CPB_ON_5H           EQU  H'BF'    ; Enabled
_CPB_OFF_5H          EQU  H'FF'    ; Disabled

_CPD_ON_5H           EQU  H'7F'    ; Enabled
_CPD_OFF_5H          EQU  H'FF'    ; Disabled

;----- CONFIG6L Options --------------------------------------------------
_WRT0_ON_6L          EQU  H'FE'    ; Enabled
_WRT0_OFF_6L         EQU  H'FF'    ; Disabled

_WRT1_ON_6L          EQU  H'FD'    ; Enabled
_WRT1_OFF_6L         EQU  H'FF'    ; Disabled

_WRT2_ON_6L          EQU  H'FB'    ; Enabled
_WRT2_OFF_6L         EQU  H'FF'    ; Disabled

_WRT3_ON_6L          EQU  H'F7'    ; Enabled
_WRT3_OFF_6L         EQU  H'FF'    ; Disabled

;----- CONFIG6H Options --------------------------------------------------
_WRTC_ON_6H          EQU  H'DF'    ; Enabled
_WRTC_OFF_6H         EQU  H'FF'    ; Disabled

_WRTB_ON_6H          EQU  H'BF'    ; Enabled
_WRTB_OFF_6H         EQU  H'FF'    ; Disabled

_WRTD_ON_6H          EQU  H'7F'    ; Enabled
_WRTD_OFF_6H         EQU  H'FF'    ; Disabled

;----- CONFIG7L Options --------------------------------------------------
_EBTR0_ON_7L         EQU  H'FE'    ; Enabled
_EBTR0_OFF_7L        EQU  H'FF'    ; Disabled

_EBTR1_ON_7L         EQU  H'FD'    ; Enabled
_EBTR1_OFF_7L        EQU  H'FF'    ; Disabled

_EBTR2_ON_7L         EQU  H'FB'    ; Enabled
_EBTR2_OFF_7L        EQU  H'FF'    ; Disabled

_EBTR3_ON_7L         EQU  H'F7'    ; Enabled
_EBTR3_OFF_7L        EQU  H'FF'    ; Disabled

;----- CONFIG7H Options --------------------------------------------------
_EBTRB_ON_7H         EQU  H'BF'    ; Enabled
_EBTRB_OFF_7H        EQU  H'FF'    ; Disabled


;----- DEVID Equates --------------------------------------------------
_DEVID1          EQU  H'3FFFFE'
_DEVID2          EQU  H'3FFFFF'

;----- IDLOC Equates --------------------------------------------------
_IDLOC0          EQU  H'200000'
_IDLOC1          EQU  H'200001'
_IDLOC2          EQU  H'200002'
_IDLOC3          EQU  H'200003'
_IDLOC4          EQU  H'200004'
_IDLOC5          EQU  H'200005'
_IDLOC6          EQU  H'200006'
_IDLOC7          EQU  H'200007'

        LIST
