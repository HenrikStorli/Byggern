/*
 * Node2.c
 *
 * Created: 12.10.2020 15:10:31
 * Author : Herbe
 */ 

#include <sam3x8e.h>
//#include <>
#include "sam.h"

#include "uart.h"
#include "printf-stdarg.h"
//#include "wdt.h"
#include "can_controller.h"
#include "can_interrupt.h"
#include "servo_ctrl.h"
#include "motor_interface.h"
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
	
    //SetTimer(1);  
    //motor_enable();
    //GAME_OVER();
    printf("start delay\n\r");
    delay_2us(168);
    printf("end delay\n\r");
    while (1) 
    {
        //uint16_t read = IR_read();
		//uint8_t IR_stat = IR_check(read);
        //motor_set_input(received_joystick_data.sliderRight);
		//servo_set_angle(received_joystick_data);


//        printf("X = %d Y = %d, joybutton = %d, joydirection = %d \n\r", received_joystick_data.posX, received_joystick_data.posY, received_joystick_data.button_pushed, received_joystick_data.joystick_direction);

   // CAN_MESSAGE can_msg;    
   // uint8_t mailbox_status = can_receive(&can_msg, 1);
   // if(can_msg.id > 0){
   // printf("Lengden er : %d\n Dataen er: %d\n ID'en er: %d", can_msg.data_length, can_msg.data[0], can_msg.data_length);    
   // }
    
//    printf("Halla jeg funker yolo lel derp  \n\r");
    }
}
