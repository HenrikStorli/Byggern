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

#include "music.h"

int main(void)
{
	// Initializes everything needed for operation 
    InitMusic();
    SRAM_init();
    ADC_timer_init();
    USART_init();
    fdevopen(USART_send, USART_receive);
    ADC_calibrate(&P_cal);
    OLED_init();
    pos_readSettings();
    oled_clear();
	CAN_init(MODE_NORMAL);
	
	// Where all interactions occur
    menu();

} 
