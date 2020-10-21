/*
 * servo_ctrl.h
 *
 * Created: 19.10.2020 14:18:27
 *  Author: henri
 */ 


#ifndef SERVO_CTRL_H_
#define SERVO_CTRL_H_

#include <sam.h>

void servo_pwm_init(void);

void servo_set_pwm(int joystick_position);

void servo_set_pwm_test(void);
	


#endif /* SERVO_CTRL_H_ */