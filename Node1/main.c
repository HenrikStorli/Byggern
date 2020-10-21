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
    CAN_init(MODE_NORMAL);
//    _delay_ms(1000);
//    CAN_communication_test();
 //   _delay_ms(1000);
//    CAN_communication_test2();
    
    CAN_message_t test_message;
    
    test_message.identifier = 2;
    test_message.data[0] = 'H';
    test_message.data[1] = 'E';
    test_message.data[2] = 'I';
    test_message.data_length = 3;
    
    CAN_message_t revieve_message;
    printf("Initiating node 1 \n\r");
    while (1) {
    //    CAN_message_transmission(&test_message);
    
    
       uint8_t joyButton = usb_button_pushed(JOYSTICK_BUTTON);
       uint8_t joyDirection = joystick_direction(); 
       pos_read(&P_pos);
       //printf("X = %d Y = %d, joybutton = %d, joydirection = %d \n\r", P_pos.posX, P_pos.posY, joyButton, joyDirection);
       //printf("Bro");
	   joyStick_Can_Message();
        
       // revieve_message = message_handler();
        
        
        //printf("Lengden er : %d\n\r Dataen er: %d\n\r ID'en er: %d\n\r", revieve_message.data_length, revieve_message.data[0], revieve_message.data_length);
        
        //pos_read(&P_pos);
        //
        //uint8_t sliderX = ADC_read(3);
        //uint8_t sliderY = ADC_read(2);
        //printf("kjører");

        //mcp_init(MODE_LOOPBACK);

        //printf("FLAG IS: %d", flag);


        //mcp_write(MCP_CANCTRL, 0x10);
        //_delay_ms(1000);
        //r = mcp_read(MCP_CANCTRL);
        //
        //printf("%d\n\r", r);

        // spi_master_CS(0);
        // //mcp_write(MCP_CANCTRL, DUMMY);
        // r = mcp_read(MCP_CANCTRL);       
        // spi_master_CS(1);

        //    char test = spi_read();
        //    printf("test is:  %d \n \r", test);

        
        //printf("Right button pressed: %d , Left button pressed: %d  joy button pressed: %d \r", usb_button_pushed(RIGHT_BUTTON), usb_button_pushed(LEFT_BUTTON), usb_button_pushed(JOYSTICK_BUTTON) );
        //printf("Pos X val is %4d , Pos Y is %4d, sliderX is %4d,  sliderY is %4d  \n \r", P_pos.posX, P_pos.posY, sliderX, sliderY);
        //  printf("Direction is: %4d \n \r", joystick_direction());

    //_delay_ms(100);
  } // end main loop

} //end main
