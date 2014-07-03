; compiler: jal jalv24q2 (compiled Jan 25 2014)

; command line:  jalv2 -loader18 4 18f26k80_usart.jal
                                list p=18f26k80, r=dec
                                errorlevel -306 ; no page boundary warnings
                                errorlevel -302 ; no bank 0 warnings
                                errorlevel -202 ; no 'argument out of range' warnings

                             __config 0x00300000, 0x5d
                             __config 0x00300001, 0x12
                             __config 0x00300002, 0x7f
                             __config 0x00300003, 0x7e
                             __config 0x00300004, 0x00
                             __config 0x00300005, 0x89
                             __config 0x00300006, 0x91
                             __config 0x00300007, 0x00
                             __config 0x00300008, 0x0f
                             __config 0x00300009, 0xc0
                             __config 0x0030000a, 0x0f
                             __config 0x0030000b, 0xe0
                             __config 0x0030000c, 0x0f
                             __config 0x0030000d, 0x40
v_true                         EQU 1
v_false                        EQU 0
v_enabled                      EQU 1
v_input                        EQU 1
v_output                       EQU 0
v_ancon1                       EQU 0x0f5c  ; ancon1
v_ancon0                       EQU 0x0f5d  ; ancon0
v_cm2con                       EQU 0x0f5e  ; cm2con
v_cm1con                       EQU 0x0f5f  ; cm1con
v_spbrgh1                      EQU 0x0f7d  ; spbrgh1
v_trisa                        EQU 0x0f92  ; trisa
v_trisa_trisa0                 EQU 0x0f92  ; trisa_trisa0-->trisa:0
v_trisc                        EQU 0x0f94  ; trisc
v_trisc_trisc6                 EQU 0x0f94  ; trisc_trisc6-->trisc:6
v_trisc_trisc7                 EQU 0x0f94  ; trisc_trisc7-->trisc:7
v_pie1                         EQU 0x0f9d  ; pie1
v_pie1_tx1ie                   EQU 0x0f9d  ; pie1_tx1ie-->pie1:4
v_pie1_rc1ie                   EQU 0x0f9d  ; pie1_rc1ie-->pie1:5
v_pir1                         EQU 0x0f9e  ; pir1
v_pir1_tx1if                   EQU 0x0f9e  ; pir1_tx1if-->pir1:4
v_baudcon1                     EQU 0x0fa7  ; baudcon1
v_baudcon1_brg16               EQU 0x0fa7  ; baudcon1_brg16-->baudcon1:3
v_rcsta1                       EQU 0x0fab  ; rcsta1
v_rcsta1_cren                  EQU 0x0fab  ; rcsta1_cren-->rcsta1:4
v_rcsta1_spen                  EQU 0x0fab  ; rcsta1_spen-->rcsta1:7
v_txsta1                       EQU 0x0fac  ; txsta1
v_txsta1_brgh                  EQU 0x0fac  ; txsta1_brgh-->txsta1:2
v_txsta1_txen                  EQU 0x0fac  ; txsta1_txen-->txsta1:5
v_txreg1                       EQU 0x0fad  ; txreg1
v_spbrg1                       EQU 0x0faf  ; spbrg1
v_adcon2                       EQU 0x0fc0  ; adcon2
v_adcon1                       EQU 0x0fc1  ; adcon1
v_adcon0                       EQU 0x0fc2  ; adcon0
v__banked                      EQU 1
v__access                      EQU 0
v___data_91                    EQU 0x000a  ; _serial_hw_data_put:data
v___data_85                    EQU 0       ; serial_hw_write_word(): data
v___data_83                    EQU 0x000b  ; serial_hw_write:data
v_usart_div                    EQU 1659    ; _calculate_and_set_baudrate(): usart_div
v___data_63                    EQU 0       ; print_dword_hex(): data
v___data_59                    EQU 0       ; print_word_hex(): data
v___data_49                    EQU 0       ; print_dword_bin(): data
v___data_43                    EQU 0       ; print_word_bin(): data
v___str_1                      EQU 0       ; print_string(): str
v___data_19                    EQU 0       ; format_dword_hex(): data
v___data_17                    EQU 0       ; format_word_hex(): data
;   21 include 18f26k80
                               org      4
                               goto     l__main
l__main
;   32 enable_digital_io()
; 18f26k80.jal
; 4730    ANCON0 = 0b0000_0000        -- digital I/O
                               movlb    15
                               clrf     v_ancon0,v__banked
; 4731    ANCON1 = 0b0000_0000        -- digital I/O
                               clrf     v_ancon1,v__banked
; 18f26k80_usart.jal
;   32 enable_digital_io()
; 18f26k80.jal
; 4755    analog_off()
; 18f26k80_usart.jal
;   32 enable_digital_io()
; 18f26k80.jal
; 4738    ADCON0 = 0b0000_0000         -- disable ADC
                               clrf     v_adcon0,v__access
; 4739    ADCON1 = 0b0000_0000
                               clrf     v_adcon1,v__access
; 4740    ADCON2 = 0b0000_0000
                               clrf     v_adcon2,v__access
; 18f26k80_usart.jal
;   32 enable_digital_io()
; 18f26k80.jal
; 4756    adc_off()
; 18f26k80_usart.jal
;   32 enable_digital_io()
; 18f26k80.jal
; 4747    CM1CON = 0b0000_0000        -- disable comparator
                               clrf     v_cm1con,v__banked
; 4748    CM2CON = 0b0000_0000        -- digital I/O
                               clrf     v_cm2con,v__banked
; 18f26k80_usart.jal
;   32 enable_digital_io()
; 18f26k80.jal
; 4757    comparator_off()
; 18f26k80_usart.jal
;   32 enable_digital_io()
;   35 pin_A0_direction =  output
                               bcf      v_trisa, 0,v__access ; trisa_trisa0
; usart_common.jal
;   58 procedure _calculate_and_set_baudrate() is
                               goto     l__l467
l__calculate_and_set_baudrate
;   65          BAUDCON_BRG16 = TRUE
                               bsf      v_baudcon1, 3,v__access ; baudcon1_brg16
;   66          TXSTA_BRGH = TRUE
                               bsf      v_txsta1, 2,v__access ; txsta1_brgh
;   81          SPBRGL = byte(usart_div)                  -- MSB
                               movlw    123
                               movwf    v_spbrg1,v__access
;   82          SPBRGH = byte(usart_div >> 8)             -- LSB
                               movlw    6
                               movwf    v_spbrgh1,v__access
;  167 end procedure
                               return   
; serial_hardware.jal
;   42 procedure serial_hw_init() is
l_serial_hw_init
;   44    TXSTA = 0b0000_0000                             -- reset (8 databits, async)
                               clrf     v_txsta1,v__access
;   45    RCSTA = 0b0000_0000                             -- reset (8 databits, async)
                               clrf     v_rcsta1,v__access
;   47    _calculate_and_set_baudrate()                   -- transmit and receive speed
                               call     l__calculate_and_set_baudrate
;   49    PIE1_RCIE = FALSE                               -- disable receive interrupts
                               bcf      v_pie1, 5,v__access ; pie1_rc1ie
;   50    PIE1_TXIE = FALSE                               -- disable transmit interrupts
                               bcf      v_pie1, 4,v__access ; pie1_tx1ie
;   52    pin_RX_direction = INPUT                        -- make receive pin input
                               bsf      v_trisc, 7,v__access ; trisc_trisc7
;   53    pin_TX_direction = INPUT                        -- make transmit pin input!
                               bsf      v_trisc, 6,v__access ; trisc_trisc6
;   57    TXSTA_TXEN = TRUE                               -- Enable transmitter
                               bsf      v_txsta1, 5,v__access ; txsta1_txen
;   60    RCSTA_SPEN = enabled                            -- activate serial port
                               bsf      v_rcsta1, 7,v__access ; rcsta1_spen
;   61    RCSTA_CREN = enabled                            -- continuous receive
                               bsf      v_rcsta1, 4,v__access ; rcsta1_cren
;   63 end procedure
                               return   
;   96 procedure serial_hw_write(byte in data) is
l_serial_hw_write
                               movwf    v___data_83,v__access
;   97    while !PIR1_TXIF loop  end loop                 -- wait while transmission pending
l__l429
                               btfss    v_pir1, 4,v__access ; pir1_tx1if
                               goto     l__l429
l__l430
;   98    TXREG = data                                    -- transfer data
                               movf     v___data_83,w,v__access
                               movwf    v_txreg1,v__access
;   99 end procedure
                               return   
;  168 procedure serial_hw_data'put(byte in data) is
l__serial_hw_data_put
                               movwf    v___data_91,v__access
;  169    serial_hw_write(data)
                               goto     l_serial_hw_write
;  170 end procedure
;  207 end function
l__l467
; 18f26k80_usart.jal
;   40 serial_hw_init()
                               call     l_serial_hw_init
;   42 forever loop
l__l469
;   43   serial_hw_data = 0x55
                               movlw    85
                               call     l__serial_hw_data_put
;   44 end loop
                               goto     l__l469
                               end
