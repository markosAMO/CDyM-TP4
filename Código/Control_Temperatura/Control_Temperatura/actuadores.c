/*
 * actuadores.c
 *
 * Created: 07/08/2021 17:32:45
 *  Author: Agustín
 */ 

#include "avr/io.h"

void set_puertos()
{
	DDRC = 0x03;
	PORTC = 0x00;
}

void encender_estufa()
{
	PORTC = 0x01;
}

void apagar()
{
	PORTC = 0x00;
}

void encender_ventilador()
{
	PORTC = 0x02;
}