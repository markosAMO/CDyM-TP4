
#include <avr/io.h>
/**
#define F_CPU 16000000UL

#include <util/delay.h>
**/

//funciones para el init
void  ADC_preInit(void);
void  ADC_set_ADC0_input_analog(void);
void  ADC_enabled(void);
void  ADC_preescaler(int prescaler);
void  ADC_select_pin(int pin);
//fin de funciones para el init
void  ADC_init(int prescaler, int pin);
//funciones para operar el ADC
void  ADC_Start(void);
int   ADC_conversion_completed(void);
void  ADC_flag_reset(void);
int   ADC_get_voltaje_entero(void);
float ADC_get_voltaje_real(void);