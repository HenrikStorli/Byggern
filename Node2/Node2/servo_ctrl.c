/*
 * servo_ctrl.c
 *
 * Created: 19.10.2020 14:18:07
 *  Author: henri
 */ 

#include "servo_ctrl.h"

void servo_pwm_init(void){
		//Initializing pin for solonoid 
		REG_PIOC_PER |= (1 << 28); // set as gpio on pin 23 port C
		REG_PIOC_OER |= (1 << 28); // output enable
		REG_PIOC_SODR = (1 << 28); // set output data low
	
	
		//First enable PWM clock
		REG_PMC_PCER1 |= (1<<4);
		
		//Turn of the PIO conteller for pin PC19. PIN 44 on shield.
		PIOC->PIO_PDR |= PIO_PDR_P19;
		
		//Choose peripheral B for PC19, PWMH5
		PIOC->PIO_ABSR |= PIO_ABSR_P19;
		
		//Set clock frequency for PWM, 2Mhz, CLKA.
		REG_PWM_CLK = 0x002A0000;
		
		//Set channel mode
		REG_PWM_CMR5 = 0x0000000C;
		
		//Set channel period to 20ms
		REG_PWM_CPRD5 = 0x00009C40;
}

int servo_set_pwm(float duty_cycle){
	
	if(duty_cycle < 0.040){
		printf("ERROR: duty cycle too low");
		return 1;
	}
	else if(duty_cycle > 110){
		printf("ERROR: duty cycle too high");
		return 1;
	}
	//Value to be set in duty cycle register
	float CDTY = 2000000*0.02*(1 - duty_cycle); //pwm_clock_frequency*period*(1-duty_cycle)
	
	//Set channel duty register
	REG_PWM_CDTY5 = CDTY;  
	
	//Activate PWM signal
	REG_PWM_ENA |= 0x00000020;
	
	return 0;	
}

void servo_set_angle(joystick_data_t data){

	float servo_position = -data.posX;
	
	 //Linearization of joystick position to pulse with
	float pulse_width = 0.006*servo_position + 1.5; 
	
	float duty_cycle = pulse_width / 20.0; //20.0 is PWM period.
	
	servo_set_pwm(duty_cycle);
}

void servo_activate_solonoid(joystick_data_t data){
	
	if(data.button_pushed){
		REG_PIOC_CODR = (1 << 28); // Enable voltage to solonoid
	}
	else{
		REG_PIOC_SODR = (1 << 28); // Set solonoid pin low
	}
	//for(int i = 0; i < 400; i++); // Delay
	
}

void servo_set_pwm_test(void){	
	//Set channel duty register
	REG_PWM_CDTY5 = 0x00008CA0;
	
	//Enable PWM signal
	REG_PWM_ENA |= 0x00000020;
}