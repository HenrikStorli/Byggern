/*
 * TestYolo.c
 *
 * Created: 26.08.2020 13:11:03
 * Author : Herbe
*/

#define F_CPU  4915200

#include <stdio.h>

#include <avr/io.h>
#include <util/delay.h>

#include "UART_driver.h"

#include "SRAM_driver.h"
#include "ADC_driver.h"
#include "pos_read.h"

#include "OLED.h"
#include "OLED_menu.h"

//#include "spi_driver.h"
//#include "mcp2515_driver.h"
//#include "CAN_communication.h"


int main(void)
{
    //printf("Main kjører");

    SRAM_init();
    timer_init();
    USART_init();
    fdevopen(USART_send, USART_receive);
    ADC_calibrate(&P_cal);
    OLED_init();
    pos_readSettings();
    oled_clear();

    //mcp_init(MODE_LOOPBACK);
    // uint8_t c = 'a';
    // char* k = "halla";
    // write_character(c);
    // oled_print(k);

    // oled_clear_line(4);
    // char c[] = "derp";
    // oled_pos_set(3, 62);
    // oled_print(&c);

    //printf("Main kjører");
    

    menu();
    //CAN_init(MODE_LOOPBACK);

    while (1) {

        printf("Main kjører");
        //CAN_communication_test();

        // mcp_init(MODE_LOOPBACK);


        // mcp_write(MCP_CANCTRL, 0x10);
        //_delay_ms(1000);
        // r = mcp_read(MCP_CANCTRL);

        // printf("%d\n\r", r);

  } // end main loop

} //end main
