/*
 * UART_driver.h
 *
 * Created: 02.09.2020 15:04:48
 *  Author: Herbe
 */

/**
* @file
* @brief Library for using UART
*/


#ifndef UART_DRIVER_H_
#define UART_DRIVER_H_

#include <avr/io.h>
#include <stdio.h>

#define F_CPU 4915200
#define BAUDRATE 9600
#define BAUD_PRESCALER (((F_CPU / (BAUDRATE *16UL))) - 1 )

/**
 * @brief Initializes the uart.
 */
void USART_init(void);

/**
 * @brief Gives the message received on the usart
 *
 * @return The value received
 */
unsigned char USART_receive(void);

/**
 * @brief Sends data over the USART
 *
 * @param data The data to be sent
 */
void USART_send( unsigned char data);

#endif /* UART_DRIVER_H_ */
