
#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include "ADC.h"
#include "termometro.h"
#include "controlador_lcd.h"
#include "lcd.h"
#include "controlador_global.h"
#include "actuadores.h"

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
	}
	return 0;
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


