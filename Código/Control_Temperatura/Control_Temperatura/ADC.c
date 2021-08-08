
#include "ADC.h"


//funciones para el init
void ADC_preInit(void){
	ADCSRA=0;
	ADMUX= 0x00;
}
void ADC_set_ADC0_input_analog(void){
	DIDR0= 0x01;
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
//fin de funciones para el init
void ADC_init(int prescaler, int pin){
	ADC_preInit();
	ADC_set_ADC0_input_analog();
	ADC_enabled();
	ADC_preescaler(prescaler);
	ADC_select_pin(pin);
}
//funciones para operar el ADC
void ADC_Start(void){
	  ADCSRA |= (1<<ADSC);//start conversion
}

int ADC_conversion_completed(void){	
	return (ADCSRA&(1<<ADIF))==0; //devuelve 1 si la conversion esta completada
}

void ADC_flag_reset(void){
	ADCSRA |= (1<<ADIF); //borrar flag
}

int ADC_get_voltaje_entero(void){
	/**
	int resultado=ADCL;
	int basura=ADCH;  // esta linea no sirve para nada pero si lo quito se rompe todo el programa, ya que se tiene que leer la parte alta si o si, sino no funciona
	return  resultado;//give the high byte
	**/
	return ADC*5000.0/1024.0;
}

float ADC_get_voltaje_real(void){
	/**
	float resultado=ADCL; //give the high byte
	float basura=ADCH;    // esta linea no sirve para nada pero si lo quito se rompe todo el programa, ya que se tiene que leer la parte alta si o si, sino no funciona
	return  resultado;
	**/
	return ADC*500.0/1024.0;
}
