#include <avr/io.h>
#define F_CPU 16000000UL
//#include <util/delay.h>
//#include "ADC.h"
#include "termometro.h"
int main (void)
{
	DDRB=0xff;
	TERMOMETRO_init();
	while(1)
	{	
		if (TERMOMETRO_get_temperatura()==25){
			PORTB^=1;
		}	
	//	_delay_ms(100);
	}
	return 1;
}

