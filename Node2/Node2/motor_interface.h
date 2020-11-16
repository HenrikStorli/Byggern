/*
 * motor_controll.h
 *
 * Created: 26.10.2020 14:01:21
 *  Author: henri
 */ 

/**
* @file
* @brief Library for using motor interface box
*/


#ifndef MOTOR_CONTROLL_H_
#define MOTOR_CONTROLL_H_

#include <sam.h>

typedef enum{MOTOR_RIGHT, MOTOR_LEFT}MOTOR_DIRECTION;
typedef enum{ENCODER_HIGHER_BYTE, ENCODER_LOWER_BYTE} ENCODER_BYTE;
	
	
/**
 * @brief Initializes the motor and the DAC
 */
void motor_init_DAC(void);

/**
 * @brief Sets the given input to the motor
 *
 * @param input The input that sets the speed to the motor
 */
void motor_set_input(int input);

/**
 * @brief Selects the given direction for the motor box
 *
 * @param direction The direction the motor should move in
 */
void motor_select_direction(MOTOR_DIRECTION direction);

/**
 * @brief Enables the motor
 */
void motor_enable(void);

/**
 * @brief Resets the encoder value in the motorbox
 */
void motor_reset_counter(void);

/**
 * @brief Controls the output of the motor box counter
 *
 * @param on 1 if it is to activate, 0 if not
 */
void motor_activate_counter_output(uint8_t on);

/**
 * @brief Selects the desired byte to output from the motot box counter
 *
 * @param byte Select the higher or lower byte in the 16-bit register
 */
void motor_select_encoder_byte(ENCODER_BYTE byte);

/**
 * @brief Reads the encoder value from the motor
 *
 * @return The encoder value
 */
uint16_t motor_read_counter(void);

#endif /* MOTOR_CONTROLL_H_ */