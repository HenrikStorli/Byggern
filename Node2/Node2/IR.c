/*
 * IR.c
 *
 * Created: 19.10.2020 14:02:12
 *  Author: Herbe
 */ 
#include "IR.h"

void IR_init(void){ /* PA16 is A0 https://www.arduino.cc/en/Hacking/PinMappingSAM3X */
    REG_PMC_PCER1 |= (1 << 5);  // enable ADC on ID37
    REG_PIOA_PDR |= (1 << 16); // Disable as gpio pin 
    REG_ADC_MR |= (1 << 7); // ADC in free run mode
    // PIOA->PIO_PDR|= PIO_PDR_P7;
    REG_ADC_CHER |= ADC_CHER_CH7; //enable as adc channel on AD7 extra func     
}

uint16_t ADC_data(void){
    data = ADC->ADC_CDR[7];
}