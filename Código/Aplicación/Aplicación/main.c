/*
 * Aplicacion.c
 *
 * Created: 6/08/2021 17:54:52
 * Author : GOD
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
	
    OCR0A = 250;
	TCCR0A = 0x02; //se activa modo CTC
	TCCR0B = 0x02;
	TIMSK0 = (1<<OCIE0A);
	sei();
	while(1)
    {
		mostrar();
	}
}
ISR(TIMER0_COMPA_vect){
	contador++;
	if(contador == 250) //con esto debería hacer la interrupción cada 0.5 segundos
	{
		flag = 1;
		contador = 0;
	}
}

