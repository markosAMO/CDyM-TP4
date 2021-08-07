/*
 * ADC.c
 *
 * Created: 6/8/2021 23:34:08
 *  Author: soyal
 */ 
#include "ADC.h"

void ADC_estado_defecto(void){
	ADCSRA=0;
	ADMUX= 0x00;
}

void ADC_enabled(void){
	ADCSRA|=(1<<ADEN);
	
}


void ADC_preescaler(int prescaler){
	switch (prescaler)
	{
		case 2:ADCSRA|=0b00000001;
		break;
		case 4:ADCSRA|=0b00000010;
		break;
		case 8:ADCSRA|=0b00000011;
		break;
		case 16:ADCSRA|=0b00000100;
		break;
		case 32:ADCSRA|=0b00000101;
		break;
		case 64:ADCSRA|=0b00000110;
		break;
		case 128:ADCSRA|=0b00000111;
		break;
		default:ADCSRA|=0b00000000;
		break;
	}
}

void ADC_select_pin(int pin){
	ADMUX|= pin;
	
}

void ADC_set_ADC0_input_analog(void){
	DIDR0= 0x01;
}

void ADC_Start(void){
	  ADCSRA |= (1<<ADSC);//start conversion
}

int ADC_conversion_completed(void){	
	return (ADCSRA&(1<<ADIF))==0; //devuelve 1 si la conversion esta completada
}

void ADC_flag_reset(void){
	ADCSRA |= (1<<ADIF); //borrar flag
}

int ADC_get_resultado_alto(void){
	return  ADCH;//give the low byte
}
int ADC_get_resultado_bajo(void){
	return  ADCL;//give the high byte
}

void ADC_init(int prescaler, int pin){
		ADC_estado_defecto();
		ADC_set_ADC0_input_analog();
		ADC_enabled();
		ADC_preescaler(128);
		ADC_select_pin(0);
}