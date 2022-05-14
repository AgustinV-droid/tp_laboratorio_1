/*
 ============================================================================
 Name        : TP_2
 Author      : Diego Agustin Villanueva
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "arrayPassanger.h"
#include "Funciones.h"
#define TRUE 0
#define FALSE 1
#define TAM 2000


int main(){
	Passanger ListaPasajeros[TAM];
	setbuf(stdout, NULL);
	int respuesta = 0;

	initPassanger(ListaPasajeros, TAM);

	respuesta = menuPrincipal();

	return 0;
}
