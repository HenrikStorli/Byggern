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
#include "ADC.h"
#include "Timer.h"

#define F_CPU 84E6 //84Mhz

int main(void)
{
    /* Initialize the SAM system */
    SystemInit();
    configure_uart();
	servo_pwm_init();
	motor_init_DAC();   
    IR_init();
    timer_init();
    
    //init can config     
    uint32_t can_msk = 0x00143555;
    uint8_t can_status = can_init(can_msk, 1, 1);
    
    WDT->WDT_MR = WDT_MR_WDDIS; // Dissable watchdog      
    
    SetTimer(1);  
	uint16_t counter_value;
    motor_enable();
	init_motor_controller_parameters(0.5, 1.5, 0);
    while (1) 
    {
		
		motor_controller_set_input();
		servo_set_angle(received_joystick_data);
		servo_activate_solonoid(received_joystick_data);
		
		if(IR_check()){
			CAN_MESSAGE game_over_message;
			game_over_message.id = 0;
			game_over_message.data_length = 8;
			game_over_message.data[0] = 0b11111111;
			
			//printf("IR_CHECK FUNGERER");
			
			uint8_t mailbox_busy;
			
			mailbox_busy = can_send(&game_over_message, 0);
			
			printf("MAILBOX BUSY: %d", mailbox_busy);
		}
		
		//counter_value = motor_read_counter();
		
		//printf("Counter Value: %d\n\r", counter_value);
		
		uint16_t ir_value = IR_read();
		
		//printf("IR value is: %d\n\r", ir_value);

		


    //printf("X = %d Y = %d, joybutton = %d, joydirection = %d, SliderY = %d \n\r", received_joystick_data.posX, received_joystick_data.posY, received_joystick_data.button_pushed, received_joystick_data.joystick_direction, received_joystick_data.sliderRight);
    
    }
}
