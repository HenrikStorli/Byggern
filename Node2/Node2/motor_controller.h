/*
 * motor_controller.h
 *
 * Created: 04.11.2020 09:28:49
 *  Author: henri
 */ 


#ifndef MOTOR_CONTROLLER_H_
#define MOTOR_CONTROLLER_H_

#include "can_interrupt.h"
#include "motor_interface.h"

typedef struct regulator_parameter_t
{
	float Ki;
	float Kp;
	float Kd ;
	
	float T;
	
	volatile float error_sum;
	int current_error;
	int previous_error;
	
	int motor_input;
}regulator_parameter;

regulator_parameter reg_parameters;

//void postion_controller_parameters(float K_i, float K_p, float K_d);

void init_motor_controller_parameters(float K_i, float K_p, float K_d);

void motor_controller_update();

void motor_controller_set_input();


#endif /* MOTOR_CONTROLLER_H_ */