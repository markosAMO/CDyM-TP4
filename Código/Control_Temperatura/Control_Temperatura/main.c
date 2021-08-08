/*
 * Control_Temperatura.c
 *
 * Created: 7/8/2021 12:53:16
 * Author : soyal
 */ 
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "ADC.h"
#include "termometro.h"
#include "controlador_lcd.h"
#include "lcd.h"
#include "controlador_global.h"
#include "actuadores.h"

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <avr/interrupt.h>

float temp;
volatile uint8_t flag = 0;
volatile uint16_t contador = 0;

int main (void)
{
	LCDinit();
	TERMOMETRO_init();
	set_renglones_display();
	set_puertos();
		/*se configura las interrupciones por temporizador*/
		OCR0A = 250;
		TCCR0A = 0x02; //se activa modo CTC
		TCCR0B = 0x02;
		TIMSK0 = (1<<OCIE0A);
		sei();
		/*se configura las interrupciones por temporizador*/
	
	while(1)
	{
		regular_temperatura();
		_delay_ms(100);			
	}
	return 1;
}

ISR(TIMER0_COMPA_vect){
	contador++;
	if(contador == 1935)
	{
		mostrar();
		flag = 1;
		contador = 0;
	}
}


