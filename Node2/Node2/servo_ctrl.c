/*
 * servo_ctrl.c
 *
 * Created: 19.10.2020 14:18:07
 *  Author: henri
 */ 


void servo_set_pwm(int joystick_position){
	
	//Skru av IO funksjonalitet, som pinnen er i by default
	PIOc->PIO_PDR |= PIO_PDR_Pn //der c er port og n er pin-nummer.
	
	//Velge peripheral A og B
	PIOc->PIO_ABSR |= PIO_ABSR_Pn //der c port og n er pin-nummer. 
	
	REG_PWM_CLK //Sett riktig klokkefrekvens
	
	// PWML0 er peripheral B på pin PA21
	// PWMH0 er peripheral B på pin PA8
	
	// n er hvilken kanal.
	REG_PWM_CMRn //Sett riktig modus
	REG_PWM_CPRD1n //Sett riktig periodetid
	REG_PWM_CDTYn //Sett riktig kanal
	
	REG_PWM_ENA //Aktiver pwm
	
}