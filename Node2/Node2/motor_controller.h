/*
 * motor_controller.h
 *
 * Created: 04.11.2020 09:28:49
 *  Author: henri
 */ 


/**
* @file
* @brief Library for using motor controller
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

/**
 * @brief Initializes the values used in the motor controller
 *
 * @param K_i The integral gain
 * @param K_p The proportional gain
 * @param K_d The derivative gain
 */
void init_motor_controller_parameters(float K_i, float K_p, float K_d);

/**
 * @brief Updates the values used to control the motor 
 */
void motor_controller_update();

/**
 * @brief Sets the calculated input out to the motor box
 */
void motor_controller_set_input();

#endif /* MOTOR_CONTROLLER_H_ */