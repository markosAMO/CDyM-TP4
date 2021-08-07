/*
 * Control_Temperatura.c
 *
 * Created: 7/8/2021 12:53:16
 * Author : soyal
 */ 
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include "ADC.h"
#include "termometro.h"
int main (void)
{
	DDRD=0xff;
	PORTD=0x0;
	TERMOMETRO_init();
	int dato=0;
	while(1)
	{
		dato=TERMOMETRO_get_temperatura();
		mostrarString(&dato, 1, 1, 8 );
		
		
			_delay_ms(100);
	}
	return 1;
}

