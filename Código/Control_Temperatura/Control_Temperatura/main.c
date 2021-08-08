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
#include <math.h>
#include <stdlib.h>
#include <string.h>


void intTostring(int temperatura, char* string){
	itoa(temperatura,string,10);
	if (temperatura<10){
		string[1]=string[0];
		string[0]='0';
	}
}
void imprimir( uint8_t temperatura ){
	char string[3]="00";
	intTostring(temperatura,string);
	mostrarString(string,0,0,2);
	
}


void floatToString(float temperatura, char* stringFinal){
	char string[2]="00";
	//descompongo el numero
	double ParteEntera;
	double parteFraccional = modf(temperatura, &ParteEntera);
	
	//parte entera
	intTostring(ParteEntera,string);
	stringFinal[0]=string[0];
	stringFinal[1]=string[1];

	//parte fraccional
	if (parteFraccional*100<10){
		// primera parte fraccional
		stringFinal[3]='0';
		// segunda parte fraccional
		itoa(parteFraccional*100, string, 10);
		stringFinal[4]=string[0];
		}else{
		// parte fraccional
		itoa(parteFraccional*100, string, 10);
			stringFinal[3]=string[0];
			stringFinal[4]=string[1];
	}
}
void imprimir_float( float temperatura ){
	char string[5]="00.00";
	floatToString(temperatura,string);
	mostrarString(string,0,0,5);
}
int main (void)
{
	LCDinit();
	TERMOMETRO_init();
	while(1)
	{
		imprimir_float( TERMOMETRO_get_temperatura_real() );
		//imprimir_float( 11.11 );
		//imprimir( TERMOMETRO_get_temperatura_entero() );
		_delay_ms(100);
		LCDclr();			
	}
	return 1;
}




