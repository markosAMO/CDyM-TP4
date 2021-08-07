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

uint8_t TERMOMETRO_get_temperatura(void){
	
	ADC_Start();
	while(ADC_conversion_completed()); //wait for conversion to finish
	ADC_flag_reset();	
	return ADC_get_resultado_bajo()/2;
}
