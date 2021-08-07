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

#include <stdlib.h>
#include <string.h>
void imprimir( uint8_t temperatura ){
		char temperatura_en_string[3]="00";
		itoa(temperatura,temperatura_en_string,10);
		if (temperatura<10){
			mostrarString(temperatura_en_string,0,0,1);	
		}else{
			mostrarString(temperatura_en_string,0,0,2);
		}			
}

int main (void)
{
	LCDinit();
	TERMOMETRO_init();
	while(1)
	{
		imprimir(TERMOMETRO_get_temperatura_entero());
		_delay_ms(100);
		LCDclr();			
	}
	return 1;
}

