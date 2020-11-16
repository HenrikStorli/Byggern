/*
 * IR.h
 *
 * Created: 19.10.2020 14:10:40
 *  Author: Herbe
 */ 

/**
* @file
* @brief Library for using IR
*/

#ifndef IR_H_
#define IR_H_

#include "sam.h"

/**
 * @brief Initializes the IR
 */
void IR_init(void);

/**
 * @brief Reads the digital value from the reciever diode.
 *
 * @return The value from the adc.
 */
uint16_t IR_read(void);

/**
 * @brief Checks if the value is under a certan threshold
 *
 * @return 1 if the value is under the threshold, 0 else.
 */
uint8_t IR_check(void);

#endif /* IR_H_ */