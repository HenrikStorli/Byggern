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
    while (1) 
    {

    }
}
