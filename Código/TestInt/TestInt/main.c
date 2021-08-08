/*
 * TestInt.c
 *
 * Created: 8/8/2021 00:24:53
 * Author : God
 */ 

#include <avr/io.h>
#include "lcd.h"
#include "controlador_lcd.h"
#define F_CPU 8000000L
#include <avr/interrupt.h>
volatile uint8_t flag = 0;
volatile uint16_t contador = 0;

int main(void)
{
	LCDinit();
	/*se configura las interrupciones por temporizador*/
	OCR0A = 250;
	TCCR0A = 0x02; //se activa modo CTC
	TCCR0B = 0x02;
	TIMSK0 = (1<<OCIE0A);
	sei();
	/*se configura las interrupciones por temporizador*/

	while (1)
	{
	}
}
ISR(TIMER0_COMPA_vect){
	contador++;
	if(contador == 500)
	{
		flag = 1;
		contador = 0;
	}
}

