/*
 * IR.c
 *
 * Created: 19.10.2020 14:02:12
 *  Author: Herbe
 */ 
#include "ADC.h"

void IR_init(void){ /* PA16 is A0 https://www.arduino.cc/en/Hacking/PinMappingSAM3X */
    REG_PMC_PCER1 |= (1 << 5);  // enable ADC on ID37 could write ID_ADC?
   // REG_PIOA_PDR |= (1 << 16); // Disable as gpio pin 
    REG_ADC_MR |= (1 << 7); // ADC in free run mode
    // PIOA->PIO_PDR|= PIO_PDR_P7;
    REG_ADC_CHER |= ADC_CHER_CH7; //enable as adc channel on AD7 extra func     
}

uint16_t IR_read(void){
   uint16_t data = ADC->ADC_CDR[7];
return data;
}

uint8_t IR_check(uint16_t data){
    if(data < 200){
        return 1;
    }
    else{
        return 0;
    }
}
