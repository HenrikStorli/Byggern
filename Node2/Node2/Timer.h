/*
 * Timer.h
 *
 * Created: 21.10.2020 15:01:40
 *  Author: Herbe
 */ 


/**
* @file
* @brief Library for using timers
*/

#ifndef TIMER_H_
#define TIMER_H_

#include "sam.h"
#include "printf-stdarg.h"
#include "motor_controller.h"

/**
 * @brief Initializes the timer use for controller update and highscore
 */
void timer_init(void);

/**
 * @brief ISR for tc0_handler.
 */
void TC0_Handler(void);

/**
 * @brief Starts and stops the timer
 *
 * @param state If timer should be on or of. Starts if 1, stops if 0
 */
void SetTimer(uint8_t state);

/**
 * @brief Checks what the counter is at the current time
 *
 * @return The count value
 */
uint32_t count_value(void);

/**
 * @brief Resets count to zero
 */
void reset_count(void);

#endif /* TIMER_H_ */