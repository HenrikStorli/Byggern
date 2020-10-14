/*
 * Node2.c
 *
 * Created: 12.10.2020 15:10:31
 * Author : Herbe
 */ 

#include <sam3x8e.h
//#include <>
#include "sam.h"


int main(void)
{
    /* Initialize the SAM system */
    SystemInit();

    PIOF = (1 << PIOF);  
    while (1) 
    {
    }
}
