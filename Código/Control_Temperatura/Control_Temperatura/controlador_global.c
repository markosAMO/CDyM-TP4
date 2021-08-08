

#include "controlador_lcd.h"
#include "termometro.h"
#include "actuadores.h"
#include <stdio.h>

#include "string.h"
#include "avr/interrupt.h"

int limite_inferior = 17;
int limite_superior = 24;

char linea_superior[] = "Climatizador:    ";
char linea_inferior[] = "                                ";


void set_temperatura_display_int(int temperatura);
void set_temperatura_display_float(float temperatura);

void regular_temperatura()
{
/*	int temperatura_actual = TERMOMETRO_get_temperatura_entero();*/
	float temperatura_actual = TERMOMETRO_get_temperatura_real();

	
	cli();
/*	set_temperatura_display_int(temperatura_actual);*/
	set_temperatura_display_float(temperatura_actual);
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

// void set_temperatura_display_int(int temperatura)
// {
// 	
// 	sprintf(linea_inferior, "TEMP: %d.0 C              ", temperatura);
// }

void set_temperatura_display_float(float temperatura)
{
	int fracc = (int)(temperatura * 10) % 10;
	int enter = (int)temperatura;
	
	sprintf(linea_inferior, "TEMP: %d.%d C              ", enter,fracc);
	
	
}
void set_renglones_display()
{
	actualizarVarInferior(linea_inferior);
	actualizarVarSuperior(linea_superior);
}
