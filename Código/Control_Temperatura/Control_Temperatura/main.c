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

int main (void)
{
	LCDinit();
	TERMOMETRO_init();
	set_renglones_display();
	set_puertos();
	
	while(1)
	{
		regular_temperatura();
		mostrar();
		_delay_ms(100);			
	}
	return 1;
}

