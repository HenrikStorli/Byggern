/*
 * SRAM_driver.h
 *
 * Created: 09.09.2020 11:43:17
 *  Author: Herbe
 */


#ifndef SRAM_DRIVER_H_
#define SRAM_DRIVER_H_

#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Initializes the SRAM module
 */
void SRAM_init(void);

/**
 * @brief Checks if the external SRAM can be accessed in a preferable way
 */
void SRAM_test(void);


#endif /* SRAM_DRIVER_H_ */
