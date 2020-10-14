/*
 * ADC_driver.h
 *
 * Created: 09.09.2020 13:15:29
 *  Author: Herbe
 */


#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_

#include <stdint.h>
#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>


typedef struct calibration_values_t   {
    int center_X;
    int center_Y;
} calibration_values;

calibration_values P_cal;

/**
 * @brief Reads the values from the adc.
 *
 * @param channel The desired channal that wants to be converted.
 *
 *   channel 0 gives joystick X value.
 *   Channel 1 gives joystick Y.
 *   Channel 2 gives slider right.
 *   Channel 3 gives slider left .
 *
 * @return The digital value return from the adc.
 */
uint8_t ADC_read(uint8_t channel);

/**
 * @brief Calibrates the adc.
 *
 * @param cal_pos pointer to the struct containing calibration values for the adc.
 */
void ADC_calibrate(calibration_values* cal_pos);        // maybe store in flash?

/**
 * @brief Tests if the adc works appropriately.
 */
void ADC_Test(void);

/**
 * @brief Sets the clock signal to the adc.
 */
void ADC_timer_init(void);

#endif /* ADC_DRIVER_H_ */
