/*
 * Node2.c
 *
 * Created: 12.10.2020 15:10:31
 * Author : Herbe
 */ 

#include <sam3x8e.h>
#include "sam.h"

#include "uart.h"
#include "printf-stdarg.h"
#include "can_controller.h"
#include "can_interrupt.h"
#include "servo_ctrl.h"
#include "motor_interface.h"
#include "motor_controller.h"
#include "IR.h"
#include "Timer.h"

int main(void)
{
    /* Initialize the SAM system */
    SystemInit();
    configure_uart();
	servo_pwm_init();
	motor_init_DAC();   
    IR_init();
    timer_init();
    
    // Initializes can config     
    uint32_t can_msk = 0x00143555;
    uint8_t can_status = can_init(can_msk, 2, 1);
    
	// Disable watchdog 
    WDT->WDT_MR = WDT_MR_WDDIS;      
    
    SetTimer(1);  
    motor_enable();
	init_motor_controller_parameters(0.003, 0.9, 0);
	
	// Creates game over message
	CAN_MESSAGE game_over_message;
	game_over_message.id = 0;
	game_over_message.data_length = 2;
	
	// Value checking if mailbox is busy
	uint8_t mailbox_busy;
	
	
    while (1) 
    {	
		// Set input to the game equipment 
		motor_controller_set_input();
		servo_set_angle(received_joystick_data);
		servo_activate_solonoid(received_joystick_data);
		
		// Checks if the game is lost
		if(IR_check()){
			
			// Sends game over message
			game_over_message.data[0] = 0b10101011;
			game_over_message.data[1] = count_value();
			mailbox_busy = can_send(&game_over_message, 0);
			
		}
    }
}
