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
void imprimir_float( float temperatura ){
	char string[3]="000";
	
	//descompongo el numero
	double ParteEntera;
	double parteFraccional = modf(temperatura, &ParteEntera);
	
	//imprimo la parte entera
	imprimir(ParteEntera);
	//imprimo la coma
	mostrarString(".",2,0,1);	
	//imprimo la parte fraccional
	itoa(parteFraccional, string, 10);
	mostrarString(string,3,0,1);
}

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
		imprimir_float( TERMOMETRO_get_temperatura_real() );
		_delay_ms(100);
		LCDclr();			
	}
	return 1;
}




