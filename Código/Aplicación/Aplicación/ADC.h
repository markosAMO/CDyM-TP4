/*
 * ADC.h
 *
 * Created: 7/8/2021 00:04:36
 *  Author: soyal
 */ 
#include <avr/io.h>
#define F_CPU 16000000UL

#include <util/delay.h>


//funciones para el init
void ADC_estado_defecto(void);
void ADC_set_ADC0_input_analog(void);
void ADC_enabled(void);
void ADC_preescaler(int prescaler);
void ADC_select_pin(int pin);
//fin de funciones para el init

void ADC_Start(void);
int ADC_conversion_completed(void);

void ADC_flag_reset(void);

int ADC_get_resultado_alto(void);
int ADC_get_resultado_bajo(void);

void ADC_init(int prescaler, int pin);