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
	
    menu();

    printf("Initiating node 1 \n\r");
    while (1) {

	   joyStick_Can_Message();
        
        uint8_t sliderX = ADC_read(3);
        uint8_t sliderY = ADC_read(2);
  
        printf("Pos X val is %4d , Pos Y is %4d, sliderX is %4d,  sliderY is %4d  \n \r", P_pos.posX, P_pos.posY, sliderX, sliderY);

  } // end main loop

} //end main
