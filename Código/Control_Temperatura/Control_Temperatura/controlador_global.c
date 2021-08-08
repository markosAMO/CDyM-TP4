/*
 * controlador_global.c
 *
 * Created: 07/08/2021 17:05:32
 *  Author: Agustín
 */ 

#include "controlador_lcd.h"
#include "termometro.h"
#include "actuadores.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "string.h"
#include "avr/interrupt.h"

int limite_inferior = 17;
int limite_superior = 25;

uint8_t linea_superior[] = "Temperatura:    ";
uint8_t linea_inferior[] = "                                ";

float temp;

void set_temperatura_display_int(int temperatura);
void set_temperatura_display_float(float temperatura);

void regular_temperatura()
{
	int temperatura_actual = TERMOMETRO_get_temperatura_entero();
	temp= temperatura_actual/10.0;
	//float temperatura_actual = TERMOMETRO_get_temperatura_real();

	
	cli();
	set_temperatura_display_int(temperatura_actual);
	//set_temperatura_display_float(temperatura_actual);
	sei();
	
	if (temp <= limite_inferior)
	{
		encender_estufa();
		apagar_ventilador();
	}
	else if (temp >= limite_superior)
	{
		encender_ventilador();
		apagar_estufa();
	}
	else
	{
		apagar_ventilador();
		apagar_estufa();
	}
	
}

void set_temperatura_display_int(int temperatura)
{
	int fracc = (temperatura) % 10;
	int enter = (int)(temperatura / 10);
	
	sprintf(linea_inferior, "%d.%d C              ", enter,fracc);
}

void set_temperatura_display_float(float temperatura)
{
	int fracc = (int)(temperatura * 10) % 10;
	int enter = (int)temperatura;
	
	sprintf(linea_inferior, "%d.%d C              ", enter,fracc);
	
	
}
void set_renglones_display()
{
	actualizarVarInferior(linea_inferior);
	actualizarVarSuperior(linea_superior);
}
