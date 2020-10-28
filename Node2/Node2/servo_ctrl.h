/*
 * servo_ctrl.h
 *
 * Created: 19.10.2020 14:18:27
 *  Author: henri
 */ 


#ifndef SERVO_CTRL_H_
#define SERVO_CTRL_H_

#include <sam.h>
#include "can_interrupt.h"
#include "printf-stdarg.h"

/**
 * @brief Initializes the pwm peripheral
 */
void servo_pwm_init(void);

/**
 * @brief Sets the given pwm signal
 *
 * @param duty_cycle duty cycleof the pwm
 *
 * @return 1 if duty_cycle is too large or too small, else return 0.
 */
int servo_set_pwm(float duty_cycle);

/**
 * @brief Sets the angle on the servo.
 *
 * @param data Struct containing information about the joystick position
 */
void servo_set_angle(joystick_data_t data);

/**
 * @brief Tests if the pwm signal is correct.
 */
void servo_set_pwm_test(void);
	
#endif /* SERVO_CTRL_H_ */