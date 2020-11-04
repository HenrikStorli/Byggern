/*
 * motor_controller.c
 *
 * Created: 04.11.2020 09:28:29
 *  Author: henri
 */ 

#include "position_controller.h"

static float Ki = 0;
static float Kp = 0.5;
static float Kd = 0;

static int T = 0; //DENNE MÅ ENDRES !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void postion_controller_parameters(float K_i, float K_p, float K_d){
	Ki = K_i;
	Kp = K_p;
	Kd = K_d;
}

void position_controller_update(){
	static int integral_error;
	
	//Reference and actual position
	int real_postion = motor_read_counter(); //Denne må skaleres til mellom 0 og 255.
	
	if(real_postion > 20000){
		real_postion = 0;
	}
	real_postion = (-255.0/17000.0)*real_postion + 255;
	
	int reference_position = received_joystick_data.sliderRight;
	
	//Error and the sum of all errors
	int position_error = reference_position - real_postion;
	integral_error += position_error;
	
	//Calculate the motor input
	int motor_input = Kp * position_error; // + T * Ki * integral_error; (Used for integral effect)
	
	
	if(motor_input < 0){
		motor_select_direction(MOTOR_RIGHT);
		motor_set_input(-motor_input);
		
	}
	else{
		motor_select_direction(MOTOR_LEFT);
		motor_set_input(motor_input);
	}
}