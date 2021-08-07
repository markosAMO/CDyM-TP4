/*
 * controlador_global.c
 *
 * Created: 07/08/2021 17:05:32
 *  Author: Agustín
 */ 

#include "controlador_lcd.h"
#include "termometro.h"
#include "string.h"
#include "avr/interrupt.h"

int limite_inferior = 17;
int limite_superior = 25;

char linea_superior[] = "Temperatura:";
char linea_inferior[] = "                ";

void regular_temperatura()
{
	int temperatura_actual = TERMOMETRO_get_temperatura();
	
	cli();
	set_temperatura_display(temperatura_actual);
	sei();
	
	if (temperatura_actual <= limite_inferior)
	{
		//encender estufa y apagar ventilador
	}
	else if (temperatura_actual >= limite_superior)
	{
		//apagar estufa y encender ventilador
	}
	else
	{
		//apagar estufa y ventilador
	}
	
}

void set_temperatura_display(int temperatura)
{
	sprintf(linea_inferior, "%d", temperatura) 
}