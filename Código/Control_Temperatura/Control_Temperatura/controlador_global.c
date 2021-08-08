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

#include "string.h"
#include "avr/interrupt.h"

int limite_inferior = 17;
int limite_superior = 25;

uint8_t linea_superior[] = "Temperatura:    ";
uint8_t linea_inferior[] = "                                ";

void set_temperatura_display(int temperatura);

void regular_temperatura()
{
	int temperatura_actual = TERMOMETRO_get_temperatura();
	
	cli();
	set_temperatura_display(temperatura_actual);
	sei();
	
	if (temperatura_actual <= limite_inferior)
	{
		encender_estufa();
		apagar_ventilador();
	}
	else if (temperatura_actual >= limite_superior)
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

void set_temperatura_display(int temperatura)
{
	sprintf(linea_inferior, "%d               ", temperatura);
}

void set_renglones_display()
{
	actualizarVarInferior(linea_inferior);
	actualizarVarSuperior(linea_superior);
}
