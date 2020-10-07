/*
 * UART_driver.c
 *
 * Created: 02.09.2020 15:02:14
 *  Author: Herbe
 */
#include "UART_driver.h"


void USART_init(void){
    UBRR0L = (uint8_t)(BAUD_PRESCALER);
    UBRR0H = (uint8_t)((uint8_t) BAUD_PRESCALER>>8);
    UCSR0B = (1 << RXEN0)|(1 << TXEN0);
    UCSR0C = (1 << URSEL0)|(1 << USBS0)|(3 << UCSZ00);
}

unsigned char USART_receive(void){
    while(!(UCSR0A & (1 << RXC0)));
    return UDR0;
}

void USART_send( unsigned char data){
    while(!(UCSR0A & (1 << UDRE0)));
    UDR0 = data;
}
