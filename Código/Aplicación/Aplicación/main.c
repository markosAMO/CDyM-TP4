#include <avr/io.h>
#define F_CPU 16000000UL

#include <util/delay.h>
#include "ADC.h"



int main (void)
{
	DDRB = 0xFF;//make Port B an output
	DDRD = 0xFF; //make Port D an output
	ADC_init(128,0);
	while(1)
	{
		ADC_Start();
		while(ADC_conversion_completed()); //wait for conversion to finish
		ADC_flag_reset();
		PORTD = ADC_get_resultado_bajo();
		PORTB = ADC_get_resultado_alto();
		_delay_ms(100);
	}
	return 1;
}

