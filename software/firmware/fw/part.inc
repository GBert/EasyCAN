#IFDEF __18F26K80
                ; disbale all analog
                CLRF    ANCON0
                CLRF    ANCON1
                CLRF    ADCON0              ; disable ADCs
                CLRF    ADCON1
                CLRF    ADCON2
                CLRF    CM1CON              ; disable comperators
                CLRF    CM2CON
#ENDIF

                ; UART port setting
                BCF     TRISB,6             ; UART2 TX
                BSF     TRISB,7             ; UART2 RX

                ; CAN port setting
                BCF     TRISB,2             ; CAN TX
                BSF     TRISB,3             ; CAN RX

