/*
 * position_controller.h
 *
 * Created: 28.10.2020 10:35:02
 *  Author: henri
 */ 


#ifndef POSITION_CONTROLLER_H_
#define POSITION_CONTROLLER_H_

#include "can_interrupt.h"
#include "motor_interface.h"

void postion_controller_parameters(float K_i, float K_p, float K_d);

void position_controller_update();




#endif /* POSITION_CONTROLLER_H_ */