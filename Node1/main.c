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

#include "spi_driver.h"
#include "mcp2515_driver.h"
#include "CAN_communication.h"
#include "CAN_joystick_messages.h"


int main(void)
{
    
    SRAM_init();
    ADC_timer_init();
    USART_init();
    fdevopen(USART_send, USART_receive);
    ADC_calibrate(&P_cal);
    OLED_init();
    pos_readSettings();
    oled_clear();
	CAN_init(MODE_NORMAL);

    //mcp_init(MODE_LOOPBACK);
    // uint8_t c = 'a';
    // char* k = "halla";
    // write_character(c);
    // oled_print(k);

    // oled_clear_line(4);
    // char c[] = "derp";
    // oled_pos_set(3, 62);
    // oled_print(&c);
    
	
    //menu();
    //CAN_init(MODE_LOOPBACK);
    //CAN_communication_test();
    //mcp_init(MODE_LOOPBACK);
    //uint8_t r;

//    _delay_ms(1000);
//    CAN_communication_test();
 //   _delay_ms(1000);
//    CAN_communication_test2();

    CAN_message_t recieve_message;
    printf("Initiating node 1 \n\r");
    
    while (1) {
     
        recieve_message = message_handler();
        
        if(recieve_message.data[0] > 0){
        printf("Lengden er : %d\n\r Dataen er: %d\n\r ID'en er: %d\n\r", recieve_message.data_length, recieve_message.data[0], recieve_message.data_length);
        }        
               
        
  } // end main loop

} //end main
