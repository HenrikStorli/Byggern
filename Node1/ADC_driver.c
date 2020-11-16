/*
 * ADC_driver.c
 *
 * Created: 09.09.2020 13:13:13
 *  Author: Herbe
 */

/**
* @file
* @brief Implementation file for ADC_driver
*/

#define F_CPU 4915200

#include "ADC_driver.h"


uint8_t ADC_read(uint8_t channel){
	
	// Pointer to base adress for ADC
    volatile char *ext_adc = (char *) 0x1400; 
	
	// Write instruction choosing wich channel to read
    ext_adc[1] = 0b10000000 | channel;


    _delay_us(150);
	
	// Return converted value
	return ext_adc[1];
}


void ADC_calibrate(calibration_values* cal_pos){

    cal_pos -> center_X = ADC_read(0);   //read x and set center offset
    cal_pos -> center_Y = ADC_read(1);   //read y and set center offset

}


void ADC_Test(void) {
    uint16_t adrs = 0x0000;

    volatile uint8_t *ext_ram1 = (uint8_t *) 0x1400; // Start address for the ADC

    ext_ram1[adrs] = 0b01010101;
    uint8_t retreived_value = ext_ram1[adrs];
    if (retreived_value != 0b01010101) {
        printf("ADC error, ext_ram1[%4d] = %02X  \n\r", adrs, retreived_value);
    }
    else{
        printf("ADC success, ext_ram1[%4d] = %02X  \n\r", adrs, retreived_value);
    }
}


void ADC_timer_init(void) {

    DDRB|=(1<<PB0);  /*set OC0 pin as output*/

    TCCR0 |= (1<<WGM01) | (0<<WGM00);
    TCCR0 |= (1<<COM00);
    TCCR0 |= (1<<CS00);

    OCR0 = 0b00000001;
}



