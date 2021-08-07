#include <avr/io.h>
#include <string.h>
#include "lcd.h"
uint8_t x = 16;
uint8_t *datoInferior;
uint8_t *datoSuperior;

//métodos que serían llamados por la mef
void actualizarVarInferior(const uint8_t *dato) 
{
	datoInferior = dato;
}
void actualizarVarSuperior(const uint8_t *dato)
{
	datoSuperior = dato;
}
void mostrarString(const uint8_t *dato, uint8_t x, uint8_t y, uint8_t size )
{ //recibe el string, la posición a ser mostrado y la longitud del string
	uint8_t i;
	LCDGotoXY(x,y);
	for(i=0;i<size;i++){
		LCDsendChar(dato[i]);
	}
}
void mostrarArriba()
{ //recibe el string, la posición a ser mostrado y la longitud del string
	uint8_t i;
	LCDGotoXY(0,0);
	for(i=0;i<x;i++){
		LCDsendChar(datoSuperior[i]);
	}
}
void mostrarAbajo()
{ //recibe el string, la posición a ser mostrado y la longitud del string
	uint8_t i;
	LCDGotoXY(0,1);
	for(i=0;i<x;i++){
		LCDsendChar(datoInferior[i]);
	}
}
void mostrar() //método que llamaría en la interrupción
{
	mostrarArriba();
	mostrarAbajo();
}