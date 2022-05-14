#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Funciones.h"

#include "arrayPassanger.h"
#include "GetValues.h"
#define TRUE 0
#define FALSE 1
#define TAM 2000

void promedioPasajeros(Passanger* list, int len){
	int contadorTotal = 0;
	int total = 0;
	float promedio = 0;
	int contadorMayor = 0;
	for(int i; i < len; i++){
		if(list[i].isEmpty == FALSE){
			contadorTotal ++;
			total =+ list[i].price;
		}
	}
	promedio = total/contadorTotal;
	for(int i; i < len; i++){
		if(list[i].isEmpty == FALSE && list[i].price > promedio){
			contadorMayor ++;
			total =+ list[i].price;
		}
	}
	printf("  |El total de los pasajes es: %i \n",total);
	printf("  |El promedio de los pasajes es: %f \n",promedio);
	printf("  |%i pasajeros pagan mas que el promedio de los pasajes es \n",contadorMayor);
}



int deteccionDentrada(Passanger* list, int largo, int entrada,int* contadorId){
	float precio = 0;
	int respuesta = 0;
	int id;
	int len = 51;
	int opcion = 0;
	int aModificar = 0;
	char nombre[len];
	char apellido[len];
	char codigoVuelo[10];
	int tipoPasajero;
	char mensaje[200];
	char mensajeError[200];
	char mensajeSinReintentos[200];


	strcpy(mensajeSinReintentos, "  |Cantidad de intentos agotada, volviendo al Menu\n ");
	switch(entrada){
		case 1:
			strcpy(mensaje, "  |Porfavor ingrese el valor del precio: ");
			strcpy(mensajeError, "  |Error! Error! Ingrese un precio valido le quedan la siguiente cantidad de intentos: ");
			respuesta = getNumFloat(&precio, mensaje, mensajeError, mensajeSinReintentos, 1, 100000000, 2);
			if (respuesta == -1){
				break;
			}
			respuesta = 0;
			strcpy(mensaje, "  |Porfavor ingrese el nombre del pasajero: ");
			strcpy(mensajeError, "  |Error! Error! Ingrese un precio valido le quedan la siguiente cantidad de intentos: ");
			respuesta = getString(nombre, mensaje, mensajeError, mensajeSinReintentos,len , 2);
			if (respuesta == -1){
				break;
			}
			respuesta = 0;
			strcpy(mensaje, "  |Porfavor ingrese el apellido del pasajero: ");
			strcpy(mensajeError, "  |Error! Error! un dato valido le quedan la siguiente cantidad de intentos: ");
			respuesta = getString(apellido, mensaje, mensajeError, mensajeSinReintentos,len , 2);
			if (respuesta == -1){
				break;
			}
			respuesta = 0;
			strcpy(mensaje, "  |Porfavor ingrese el codigo del vuelo: ");
			strcpy(mensajeError, "  |Error! Error! Ingrese un codigo valido le quedan la siguiente cantidad de intentos: ");
			respuesta = getString(codigoVuelo, mensaje, mensajeError, mensajeSinReintentos,10 , 2);
			if (respuesta == -1){
				break;
			}
			respuesta = 0;
			strcpy(mensaje, "  |1 First Class\n  |2 Business\n  |3 Premium Economy\n  |4 Economy\n  |Ingrese un numero correspondiente segun la clase contratada: ");
			strcpy(mensajeError, "  |Error! Error! Ingrese un numero, valido le quedan la siguiente cantidad de intentos: ");
			respuesta = getNumInt(&tipoPasajero, mensaje, mensajeError, mensajeSinReintentos, 1, 4, 2);
			if (respuesta == -1){
				break;
			}
			*contadorId = *contadorId + 1;
			id = *contadorId;
			addPassanger(list, largo, id ,nombre , apellido ,precio ,codigoVuelo ,tipoPasajero );
			break;
		case 2:
			strcpy(mensaje, "  |Porfavor ingrese el ID del pasajero a modificar: ");
			strcpy(mensajeError, "	|Error! Error! Ingrese un ID valido, le quedan la siguiente cantidad de intentos: ");
			respuesta = getNumInt(&id, mensaje, mensajeError, mensajeSinReintentos, 1, 2000, 2);
			if (respuesta == -1){
				break;
			}
			findPassanger(list, TAM, id);
			strcpy(mensaje, " |1 Modificar Nombre\n |2 Modificar Apellido\n |3 Modificar Precio\n |4 Modificar calidad de pasajero\n |5 Modificar Codigo Vuelo\n |Porfavor ingrese el ID del pasajero a modificar: ");
			strcpy(mensajeError, "	|Error! Error! Ingrese un ID valido, le quedan la siguiente cantidad de intentos: ");
			respuesta = getNumInt(&aModificar, mensaje, mensajeError, mensajeSinReintentos, 1, 2000, 2);
			if (respuesta == -1){
				break;
			}
			modifyPassanger(list, TAM, id, aModificar);
			break;
		case 3:
			strcpy(mensaje, "  |Porfavor ingrese el ID del pasajero a eliminar: ");
			strcpy(mensajeError, "	|Error! Error! Ingrese un ID valido, le quedan la siguiente cantidad de intentos: ");
			respuesta = getNumInt(&id, mensaje, mensajeError, mensajeSinReintentos, 1, 2000, 2);
			if (respuesta == -1){
				break;
			}
			removePassanger(list, TAM, id);
			break;
		case 4:
			strcpy(mensaje, "  |1 Pasajeros ordenados por nombre y apellido\n  |2 Mostrar promedio y totald de los pasajes\n  |3 Pasajeros ordenados con vuelo activo\n |Porfavor ingrese el numero correspondiente a una opcion: ");
			strcpy(mensajeError, "	|Error! Error! Ingrese un numero, valido le quedan la siguiente cantidad de intentos: ");
			respuesta = getNumInt(&opcion, mensaje, mensajeError, mensajeSinReintentos, 1, 3, 2);
			if (respuesta == -1){
				break;
			}
			switch(opcion){
			case 1:
				strcpy(mensaje, "  |0 Mostrar de Mayor a Menor\n  |1 Mostrar de Menor a Mayor\n  |Porfavor ingrese el numero correspondiente a una opcion: ");
				strcpy(mensajeError, "	|Error! Error! Ingrese un numero, valido le quedan la siguiente cantidad de intentos: ");
				respuesta = getNumInt(&opcion, mensaje, mensajeError, mensajeSinReintentos, 1, 3, 2);
				if (respuesta == -1){
					break;
				}
				sortPassangerByCode(list, largo, opcion);
				break;
			case 2:
				promedioPasajeros(list, largo);
				break;
			case 3:
				strcpy(mensaje, "  |0 Mostrar de Mayor a Menor\n  |1 Mostrar de Menor a Mayor\n  |Porfavor ingrese el numero correspondiente a una opcion: ");
				strcpy(mensajeError, "	|Error! Error! Ingrese un numero, valido le quedan la siguiente cantidad de intentos: ");
				respuesta = getNumInt(&opcion, mensaje, mensajeError, mensajeSinReintentos, 1, 3, 2);
				if (respuesta == -1){
					break;
				}
				sortPassangerByCode(list,largo,opcion);
				break;
			}
			break;
	}
	return 0;
}

int menuPrincipal(Passanger* list, int largo){
	char mensaje[200];
	char mensajeError[200];
	char mensajeSinReintentos[200];
	int respuesta = 0;;
	int retorno = 0;
	int contadorId = 0;
	strcpy(mensaje, " 1|Alta de pasajeros \n 2|Modificar un pasajero \n 3|Eliminar un pasajero \n 4|Informar datos\n  |Porfavor ingrese el numero correspondiente a una opcion: ");
	strcpy(mensajeError, "Error! Error! Ingrese un numero valido le quedan la siguiente cantidad de intentos: ");
	strcpy(mensajeSinReintentos, "Cantidad de intentos agotada, volviendo al Menu\n ");
	do{
		getNumInt(&respuesta, mensaje, mensajeError, mensajeSinReintentos, 1, 5, 2);
		deteccionDentrada(list, largo, respuesta, &contadorId);
	}while(respuesta != 5);
	return retorno;
}
