/*
 * actuadores.c
 *
 * Created: 07/08/2021 17:32:45
 *  Author: Agustín
 */ 

#include "avr/io.h"

void set_puertos()
{
	DDRD = 0x03;
	PORTD = 0x00;
}

void encender_estufa()
{
	PORTD0 = 1;
}

void apagar_estufa()
{
	PORTD0 = 0;
}

void encender_ventilador()
{
	PORTD1 = 1;
}

void apagar_ventilador()
{
	PORTD = 0;
}