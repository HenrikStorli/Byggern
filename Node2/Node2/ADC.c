/*
 * IR.c
 *
 * Created: 19.10.2020 14:02:12
 *  Author: Herbe
 */ 
#include "ADC.h"

void IR_init(void){
	
    REG_PMC_PCER1 |= (1 << 5);  // enable ADC on ID37 could write ID_ADC?
    REG_ADC_MR |= (1 << 7); // ADC in free run mode
    REG_ADC_CHER |= ADC_CHER_CH7; //enable as adc channel on AD7 extra func     
}

uint16_t IR_read(void){
   uint16_t data = ADC->ADC_CDR[7];
return data;
}

uint8_t IR_check(void){
	
	uint16_t data = ADC->ADC_CDR[7];
	
    if(data < 60){
        return 1;
    }
    else{
        return 0;
    }
}
