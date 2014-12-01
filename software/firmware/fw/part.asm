
                ; disbale all analog
                CLRF  ANCON0
                CLRF  ANCON1
                CLRF  ADCON0  ; disable ADC
                CLRF  ADCON1
                CLRF  ADCON2
                CLRF  CM1CON  ; disable comperator
                CLRF  CM2CON  ; disable comperator
                ; UART port setting
                BCF   TRISB,6 ; output UART2
                BSF   TRISB,7 ; input UART2
                ; CAN port setting
                BCF   TRISB,2
                BSF   TRISB,3

