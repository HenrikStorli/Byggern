/*
 * Node2.c
 *
 * Created: 12.10.2020 15:10:31
 * Author : Herbe
 */ 

#include <sam3x8e.h>
//#include <>
#include "sam.h"

#include "uart.h"
#include "printf-stdarg.h"
//#include "wdt.h"

#define F_CPU 84E6
#define BR_CAN 500E3

int main(void)
{
    /* Initialize the SAM system */
    SystemInit();
    configure_uart();
    uint8_t can_status = can_init(BR_CAN, 1, 1);
    
    WDT->WDT_MR = WDT_MR_WDDIS; // Dissable watchdog      

    REG_PIOA_PER |= (1 << 19) | (1 << 20); // set as gpio on pin 19 and 20
    REG_PIOA_OER |= (1 << 19) | (1 << 20); // output enable
    REG_PIOA_SODR = (1 << 19) | (1 << 20); // set output data   
    
    //init can config
    Can can_struct;
    can_struct.CAN_MR = CAN_MR_CANEN;
    can_struct.CAN_BR = 0x00A3153;  
    
    
    while (1) 
    {
    CAN_MESSAGE can_msg;    
    uint8_t mailbox_status = can_receive(&can_msg, 0);
    
//    printf("Halla jeg funker yolo lel derp  \n\r");
    }
}
