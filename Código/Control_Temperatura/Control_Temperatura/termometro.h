/*
 * termometro.h
 *
 * Created: 7/8/2021 12:33:40
 *  Author: soyal
 */ 
#include <avr/io.h>
void TERMOMETRO_init(void);
int TERMOMETRO_get_temperatura_entero(void);
float TERMOMETRO_get_temperatura_real(void);