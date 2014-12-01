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

#IFDEF UART2
                BCF     TRISB,6             ; UART2 TX
                BSF     TRISB,7             ; UART2 RX
#ENDIF
#IFDEF UART1
                BCF     TRISC,6             ; UART1 TX
                BSF     TRISC,7             ; UART1 RX
#ENDIF

                ; CAN port setting
                BCF     TRISB,2             ; CAN TX
                BSF     TRISB,3             ; CAN RX

