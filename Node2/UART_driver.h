/*
 * UART_driver.h
 *
 * Created: 02.09.2020 15:04:48
 *  Author: Herbe
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
 * @brief
 *
 *
 * @return
 */
unsigned char USART_receive(void);

/**
 * @brief
 *
 * @param data
 *
 * @return
 */
void USART_send( unsigned char data);

#endif /* UART_DRIVER_H_ */
