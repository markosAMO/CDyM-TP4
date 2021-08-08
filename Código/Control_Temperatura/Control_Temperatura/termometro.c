/*
 * termometro.c
 *
 * Created: 7/8/2021 12:30:07
 *  Author: soyal
 */ 

#include "ADC.h"
#include "termometro.h"
#include <avr/io.h>


void TERMOMETRO_init(void){
	ADC_init(64,0);
}

int TERMOMETRO_get_temperatura_entero(void){
	
	ADC_Start();
	while(ADC_conversion_completed()); //wait for conversion to finish
	ADC_flag_reset();	
	int temperatura=ADC_get_voltaje_entero();
	if (temperatura>500){temperatura=500;}
	if (temperatura<0){temperatura=0;}	
	return temperatura;
}


float TERMOMETRO_get_temperatura_real(void){
	ADC_Start();
	while(ADC_conversion_completed()); //wait for conversion to finish
	ADC_flag_reset();
	
	float temperatura=ADC_get_voltaje_real();
	if (temperatura>50){temperatura=50;}
	if (temperatura<0){temperatura=0;}
	return temperatura;
}