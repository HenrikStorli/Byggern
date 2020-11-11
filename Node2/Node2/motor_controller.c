/*
 * motor_controller.c
 *
 * Created: 04.11.2020 09:28:29
 *  Author: henri
 */ 

#include "motor_controller.h"

void init_motor_controller_parameters(float K_i, float K_p, float K_d){
	reg_parameters.Ki = K_i;
	reg_parameters.Kp = K_p;
	reg_parameters.Kd = K_d;
	
	reg_parameters.T = 0.01;
	
	reg_parameters.error_sum = 0;
	reg_parameters.current_error = 0;
	reg_parameters.previous_error = 0;
	reg_parameters.motor_input = 0;
	
}

void motor_controller_update(){
	//Reference and actual position
	int real_postion = motor_read_counter();
	
	// Scaling the value to fit within [0,255]
	if(real_postion > 20000){
		real_postion = 0;
	}
	real_postion = (-255.0/17000.0)*real_postion + 255;
	
	int reference_position = received_joystick_data.sliderRight;
	
	//Error and the sum of all errors
	reg_parameters.current_error = reference_position - real_postion;
	
	//Calculate the motor input
	reg_parameters.motor_input =  reg_parameters.Kp * reg_parameters.current_error + reg_parameters.T * reg_parameters.Ki * reg_parameters.error_sum; // (Used for integral effect)
}

void motor_controller_set_input(){

	if(reg_parameters.motor_input < 0){
		motor_select_direction(MOTOR_RIGHT);
		motor_set_input(-reg_parameters.motor_input);
		
	}
	else{
		motor_select_direction(MOTOR_LEFT);
		motor_set_input(reg_parameters.motor_input);
	}
	
	reg_parameters.previous_error = reg_parameters.current_error;
	reg_parameters.error_sum += reg_parameters.current_error;
}