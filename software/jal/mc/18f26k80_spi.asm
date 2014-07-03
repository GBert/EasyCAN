; compiler: jal jalv24q2 (compiled Jan 25 2014)

; command line:  jalv2 -loader18 4 18f26k80_spi.jal
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
v_high                         EQU 1
v_low                          EQU 0
v_enabled                      EQU 1
v_input                        EQU 1
v_output                       EQU 0
v_ancon1                       EQU 0x0f5c  ; ancon1
v_ancon0                       EQU 0x0f5d  ; ancon0
v_cm2con                       EQU 0x0f5e  ; cm2con
v_cm1con                       EQU 0x0f5f  ; cm1con
v_spbrgh1                      EQU 0x0f7d  ; spbrgh1
v_lata                         EQU 0x0f89  ; lata
v_trisa                        EQU 0x0f92  ; trisa
v_trisa_trisa0                 EQU 0x0f92  ; trisa_trisa0-->trisa:0
v_trisa_trisa5                 EQU 0x0f92  ; trisa_trisa5-->trisa:5
v_trisc                        EQU 0x0f94  ; trisc
v_trisc_trisc3                 EQU 0x0f94  ; trisc_trisc3-->trisc:3
v_trisc_trisc4                 EQU 0x0f94  ; trisc_trisc4-->trisc:4
v_trisc_trisc5                 EQU 0x0f94  ; trisc_trisc5-->trisc:5
v_trisc_trisc6                 EQU 0x0f94  ; trisc_trisc6-->trisc:6
v_trisc_trisc7                 EQU 0x0f94  ; trisc_trisc7-->trisc:7
v_pie1                         EQU 0x0f9d  ; pie1
v_pie1_tx1ie                   EQU 0x0f9d  ; pie1_tx1ie-->pie1:4
v_pie1_rc1ie                   EQU 0x0f9d  ; pie1_rc1ie-->pie1:5
v_baudcon1                     EQU 0x0fa7  ; baudcon1
v_baudcon1_brg16               EQU 0x0fa7  ; baudcon1_brg16-->baudcon1:3
v_rcsta1                       EQU 0x0fab  ; rcsta1
v_rcsta1_cren                  EQU 0x0fab  ; rcsta1_cren-->rcsta1:4
v_rcsta1_spen                  EQU 0x0fab  ; rcsta1_spen-->rcsta1:7
v_txsta1                       EQU 0x0fac  ; txsta1
v_txsta1_brgh                  EQU 0x0fac  ; txsta1_brgh-->txsta1:2
v_txsta1_txen                  EQU 0x0fac  ; txsta1_txen-->txsta1:5
v_spbrg1                       EQU 0x0faf  ; spbrg1
v_adcon2                       EQU 0x0fc0  ; adcon2
v_adcon1                       EQU 0x0fc1  ; adcon1
v_adcon0                       EQU 0x0fc2  ; adcon0
v_sspcon1                      EQU 0x0fc6  ; sspcon1
v_sspcon1_ckp                  EQU 0x0fc6  ; sspcon1_ckp-->sspcon1:4
v_sspcon1_sspen                EQU 0x0fc6  ; sspcon1_sspen-->sspcon1:5
v_sspcon1_wcol                 EQU 0x0fc6  ; sspcon1_wcol-->sspcon1:7
v_sspstat                      EQU 0x0fc7  ; sspstat
v_sspstat_bf                   EQU 0x0fc7  ; sspstat_bf-->sspstat:0
v_sspstat_cke                  EQU 0x0fc7  ; sspstat_cke-->sspstat:6
v_sspstat_smp                  EQU 0x0fc7  ; sspstat_smp-->sspstat:7
v_sspbuf                       EQU 0x0fc9  ; sspbuf
v__status                      EQU 0x0fd8  ; _status
v__z                           EQU 2
v__banked                      EQU 1
v__access                      EQU 0
v_spi_mode_01                  EQU 1
v_spi_mode_10                  EQU 2
v_spi_mode_11                  EQU 3
v_spi_rate_fosc_16             EQU 1
v__pic_temp                    EQU 0x0009  ; _pic_temp-->_pic_state
v__pic_state                   EQU 0x0009  ; _pic_state
v___x_76                       EQU 0x0f89  ; x-->lata:5
v___x_77                       EQU 0x0f89  ; x-->lata:5
v___spi_mode_3                 EQU 0x000b  ; spi_init:spi_mode
v___spi_rate_3                 EQU 0x000c  ; spi_init:spi_rate
v____temp_55                   EQU 0       ; _spi_master_hw_get(): _temp
v___data_96                    EQU 0x000b  ; _spi_master_hw_put:data
v____temp_54                   EQU 0       ; _spi_master_hw_put(): _temp
v___m_data_1                   EQU 0x000c  ; spi_master_hw_exchange:m_data
v___data_85                    EQU 0       ; serial_hw_write_word(): data
v_usart_div                    EQU 138     ; _calculate_and_set_baudrate(): usart_div
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
; 18f26k80_spi.jal
;   32 enable_digital_io()
; 18f26k80.jal
; 4755    analog_off()
; 18f26k80_spi.jal
;   32 enable_digital_io()
; 18f26k80.jal
; 4738    ADCON0 = 0b0000_0000         -- disable ADC
                               clrf     v_adcon0,v__access
; 4739    ADCON1 = 0b0000_0000
                               clrf     v_adcon1,v__access
; 4740    ADCON2 = 0b0000_0000
                               clrf     v_adcon2,v__access
; 18f26k80_spi.jal
;   32 enable_digital_io()
; 18f26k80.jal
; 4756    adc_off()
; 18f26k80_spi.jal
;   32 enable_digital_io()
; 18f26k80.jal
; 4747    CM1CON = 0b0000_0000        -- disable comparator
                               clrf     v_cm1con,v__banked
; 4748    CM2CON = 0b0000_0000        -- digital I/O
                               clrf     v_cm2con,v__banked
; 18f26k80_spi.jal
;   32 enable_digital_io()
; 18f26k80.jal
; 4757    comparator_off()
; 18f26k80_spi.jal
;   32 enable_digital_io()
;   35 pin_A0_direction =  output
                               bcf      v_trisa, 0,v__access ; trisa_trisa0
; usart_common.jal
;   58 procedure _calculate_and_set_baudrate() is
                               goto     l__l466
l__calculate_and_set_baudrate
;   65          BAUDCON_BRG16 = TRUE
                               bsf      v_baudcon1, 3,v__access ; baudcon1_brg16
;   66          TXSTA_BRGH = TRUE
                               bsf      v_txsta1, 2,v__access ; txsta1_brgh
;   81          SPBRGL = byte(usart_div)                  -- MSB
                               movlw    138
                               movwf    v_spbrg1,v__access
;   82          SPBRGH = byte(usart_div >> 8)             -- LSB
                               clrf     v_spbrgh1,v__access
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
;  207 end function
l__l466
; 18f26k80_spi.jal
;   40 serial_hw_init()
                               call     l_serial_hw_init
; spi_master_hw.jal
;   21 function spi_master_hw_exchange(byte in m_data) return byte is
                               goto     l__l499
l_spi_master_hw_exchange
                               movwf    v___m_data_1,v__access
;   23    SSPBUF = m_data
                               movwf    v_sspbuf,v__access
;   25    if ( SSPCON1_WCOL != 0 ) then
                               btfsc    v_sspcon1, 7,v__access ; sspcon1_wcol
;   27       return 0xFF
                               retlw    255
;   28    end if
l__l471
;   30    while ( SSPSTAT_BF == 0 ) loop end loop
l__l472
                               btfss    v_sspstat, 0,v__access ; sspstat_bf
                               goto     l__l472
l__l473
;   33    return SSPBUF
                               movf     v_sspbuf,w,v__access
;   34 end function
l__l469
                               return   
;   37 procedure spi_master_hw'put(byte in data) is
l__spi_master_hw_put
                               movwf    v___data_96,v__access
;   39    dummy = spi_master_hw_exchange(data)
                               goto     l_spi_master_hw_exchange
;   40 end procedure
;   95 procedure spi_init(byte in spi_mode, byte in spi_rate) is
l_spi_init
                               movwf    v___spi_mode_3,v__access
;   96    SSPCON1 = 0
                               clrf     v_sspcon1,v__access
;   97    SSPSTAT_SMP = 0
                               bcf      v_sspstat, 7,v__access ; sspstat_smp
;   99    spi_master_hw_set_mode(spi_mode)
                               movf     v___spi_mode_3,w,v__access
                               btfss    v__status, v__z,v__access
                               goto     l__l502
                               bcf      v_sspcon1, 4,v__access ; sspcon1_ckp
                               bsf      v_sspstat, 6,v__access ; sspstat_cke
                               goto     l__l508
l__l502
                               decf     v___spi_mode_3,w,v__access
                               btfss    v__status, v__z,v__access
                               goto     l__l504
                               bcf      v_sspcon1, 4,v__access ; sspcon1_ckp
                               bcf      v_sspstat, 6,v__access ; sspstat_cke
                               goto     l__l508
l__l504
                               movlw    2
                               subwf    v___spi_mode_3,w,v__access
                               btfss    v__status, v__z,v__access
                               goto     l__l506
                               bsf      v_sspcon1, 4,v__access ; sspcon1_ckp
                               bsf      v_sspstat, 6,v__access ; sspstat_cke
                               goto     l__l508
l__l506
                               bsf      v_sspcon1, 4,v__access ; sspcon1_ckp
                               bcf      v_sspstat, 6,v__access ; sspstat_cke
l__l508
                               movlw    15
                               andwf    v___spi_rate_3,w,v__access
                               movwf    v__pic_temp,v__access
                               movlw    240
                               andwf    v_sspcon1,w,v__access
                               iorwf    v__pic_temp,w,v__access
                               movwf    v_sspcon1,v__access
                               bsf      v_sspcon1, 5,v__access ; sspcon1_sspen
                               return   
l__l499
; 18f26k80_spi.jal
;   46 pin_sdi_direction = input    -- spi data input
                               bsf      v_trisc, 4,v__access ; trisc_trisc4
;   47 pin_sdo_direction = output   -- spi data output
                               bcf      v_trisc, 5,v__access ; trisc_trisc5
;   48 pin_sck_direction = output   -- spi data clock
                               bcf      v_trisc, 3,v__access ; trisc_trisc3
;   54 device_chip_select_direction = output    -- chip select/slave select pin
                               bcf      v_trisa, 5,v__access ; trisa_trisa5
;   55 device_chip_select = low                -- disable the device
                               bcf      v_lata, 5,v__access ; x76
;   57 spi_init(SPI_MODE_11,SPI_RATE_FOSC_16) -- choose spi mode and speed
                               movlw    1
                               movwf    v___spi_rate_3,v__access
                               movlw    3
                               call     l_spi_init
;   58 device_chip_select = high -- enable the device
                               bsf      v_lata, 5,v__access ; x77
;   60 forever loop
l__l513
;   62   spi_master_hw = 0xAA
                               movlw    170
                               call     l__spi_master_hw_put
;   63   spi_master_hw = 0xCC
                               movlw    204
                               call     l__spi_master_hw_put
;   64 end loop
                               goto     l__l513
                               end
