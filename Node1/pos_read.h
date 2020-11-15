/*
 * pos_read.h
 *
 * Created: 16.09.2020 13:43:55
 *  Author: Herbe
 */

/**
* @file
* @brief Library for using ADC to read joystick information
*/


#include "ADC_driver.h"
#include <avr/io.h>

#include <math.h>
#define PI 3.141592654


#ifndef POS_READ_H_
#define POS_READ_H_

typedef enum{RIGHT_BUTTON, LEFT_BUTTON, JOYSTICK_BUTTON} USB_BUTTON;
typedef enum{LEFT, RIGHT, UP, DOWN, NEUTRAL, BUTTON_PRESS} DIRECTION;

typedef struct position_t {
    int posX;
    int posY;
} position;

position P_pos;

/**
 * @brief Gives the position of the joystick in the x- and y- axis on a scale from -100 to 100.
 *
 * @param pos Pointer to struct containg digital values returned from adc.
 */
void pos_read(position* pos);


/**
 * @brief Gives the direction of the joystick.
 *
 * @return Direction of joystick (LEFT, RIGHT, UP, DOWN, NEUTRAL).
 */
DIRECTION joystick_direction(void);

/**
 * @brief Checks if one of the buttons on the USB-multifunction board are pushed.
 *
 * @param BUTTON One of the two buttons (RIGHT_BUTTON or LEFT_BUTTON).
 *
 * @return True if one of the buttons are pushed, False otherwise.
 */
uint8_t usb_button_pushed(USB_BUTTON BUTTON);

/**
 * @brief Sets the settings for the pos_read module
 */
void pos_readSettings(void);

#endif /* POS_READ_H_ */
