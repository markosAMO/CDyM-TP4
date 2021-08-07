/*
 * Aplicación.c
 *
 * Created: 6/08/2021 17:54:52
 * Author : GOD
 */ 

#include <avr/io.h>
#include "lcd.h"
#include "controlador_lcd.h"
#define F_CPU 8000000L
int main(void)
{
	
    LCDinit();
	actualizarVarInferior("HOLA COMO ESTÁS?");
	actualizarVarSuperior("HOLA COMO ESTÁS?");
    while (1) 
    {
		mostrar();
    }
}

