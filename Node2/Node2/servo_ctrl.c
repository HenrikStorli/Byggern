/*
 * servo_ctrl.c
 *
 * Created: 19.10.2020 14:18:07
 *  Author: henri
 */ 


void servo_set_pwm(int joystick_position){
	//First enable PWM clock
	REG_PMC_PCER1 |= (1<<4); 
	
	//Turn of the PIO conteller for pin PC19. PIN 44 on shield.
	PIOC->PIO_PDR |= PIO_PDR_P19;
	
	//Choose peripheral B for PC19, PWMH5
	PIOC->PIO_ABSR |= PIO_ABSR_P19; 
	
	//Set clock frequency for PWM, 2Mhz, CLKA.
	REG_PWM_CLK = 0x002A0000;
	
	//Set channel mode
	REG_PWM_CMR5 =0x0000000C; //Sett riktig modus
	REG_PWM_CPRD1n //Sett riktig periodetid
	REG_PWM_CDTYn //Sett riktig kanal
	
	REG_PWM_ENA //Aktiver pwm
	
}