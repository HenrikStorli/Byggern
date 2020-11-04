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

void postion_controller_parameters(float K_i, float K_p, float K_d);

void position_controller_update();


#endif /* MOTOR_CONTROLLER_H_ */