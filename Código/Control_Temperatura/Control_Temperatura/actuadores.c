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
	PORTD = 0x01;
}

void apagar_estufa()
{
	PORTD = PORTD & 0xfe;
}

void encender_ventilador()
{
	PORTD = 0x02;
}

void apagar_ventilador()
{
	PORTD = PORTD & 0xfd;
}