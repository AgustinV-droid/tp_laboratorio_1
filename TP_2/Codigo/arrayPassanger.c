#include "arrayPassanger.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "GetValues.h"
#define TRUE 0
#define FALSE 1
#define NOACTIVO 1
#define ACTIVO 1
#define TAM 2000



int initPassanger(Passanger* list, int len){
	for(int i = 0; i < len ; i++){
		list[i].isEmpty = TRUE;
		}
	return 0;
}

int addPassanger(Passanger* list, int len, int id,char name[], char lastName[],float price,char flycode[],int typePassanger){
	int retornar;
	for(int i = 0; i < len ; i++){
		if(list[i].isEmpty == TRUE){
			list[i].isEmpty = FALSE;
			list[i].id = id;
			strcpy(list[i].name, name);
			strcpy(list[i].lastname, lastName);
			list[i].price = price;
			strcpy(list[i].flycode,flycode);
			list[i].typePassanger = typePassanger;
			if((id%2) == 0){
				list[i].statusFlight = ACTIVO;
			}else{
				list[i].statusFlight = NOACTIVO;
			}
			retornar = 0;
			break;
		}
	}
	return retornar;
}

int findPassanger(Passanger* list, int len, int id){
	int retornar = -1;
	for(int i = 0; i < len ; i++){
		if((list[i].isEmpty == FALSE) && (list[i].id == id)){
			printf("  |%4d %s %s %5.2f %-10s %d \n",
					list[i].id,
					list[i].name,
					list[i].lastname,
					list[i].price,
					list[i].flycode,
					list[i].typePassanger);
			retornar = 0;
			break;
		}
	}
	if(retornar == -1){
		printf("  |El Pasajero no se encuentra registrado \n");
	}
	return retornar;
}

int removePassanger(Passanger* list, int len, int id){
	int retornar = -1;
	char respuesta;
	for(int i = 0; i < len ; i++){
		if((list[i].isEmpty == FALSE) && (list[i].id == id)){
			printf("  |Esta seguro que quiere eliminar este pasajero?(S/N)");
			fflush(stdout);
			scanf("%c",&respuesta);
			if(respuesta == 'S'){
				list[i].isEmpty = TRUE;
			}
			break;
			retornar = 0;
		}
	}
	if(retornar == -1){
		printf("  |El Pasajero no se encuentra registrado \n");
	}
	return retornar;
}

int printPassanger(Passanger* list, int lenght){
	for(int i = 0; i < lenght ; i++){
		if((list[i].isEmpty == FALSE)){
			printf("%4d %s %s %5.2f %-10s %d \n",
					list[i].id,
					list[i].name,
					list[i].lastname,
					list[i].price,
					list[i].flycode,
					list[i].typePassanger);
		}
	}
	return 0;
}

void modifyPassanger(Passanger* list, int len, int id, int entrada){
	int modifInt;
	float modifFloat;
	char modifName[51];
	char modifLName[51];
	char modifCode[10];
	char mensaje[200];
	char mensajeError[200];
	char mensajeSinReintentos[200];
	int respuesta = 0;
	for(int i = 0; i < len ; i++){
		if((list[i].isEmpty == FALSE) && (list[i].id == id)){
			switch(entrada){
				case 1:
					strcpy(mensaje, "  |Porfavor ingrese el nuevo nombre del pasajero: ");
					strcpy(mensajeError, "Error! Error! Ingrese un precio valido le quedan la siguiente cantidad de intentos: ");
					respuesta = getString(modifName, mensaje, mensajeError, mensajeSinReintentos,len , 2);
					if (respuesta == -1){
						break;
					}
					strcpy(list[i].name, modifName);
					break;
				case 2:
					strcpy(mensaje, "  |Porfavor ingrese el nuevo apellido del pasajero: ");
					strcpy(mensajeError, "Error! Error! un dato valido le quedan la siguiente cantidad de intentos: ");
					respuesta = getString(modifLName, mensaje, mensajeError, mensajeSinReintentos,len , 2);
					if (respuesta == -1){
						break;
					}
					strcpy(list[i].lastname, modifLName);
					break;
				case 3:
					strcpy(mensaje, "  |Porfavor ingrese el nuevo valor del precio: ");
					strcpy(mensajeError, "Error! Error! Ingrese un precio valido le quedan la siguiente cantidad de intentos: ");
					respuesta = getNumFloat(&modifFloat, mensaje, mensajeError, mensajeSinReintentos, 1, 100000000, 2);
					if (respuesta == -1){
						break;
					}
					list[i].price = modifFloat;
					break;
				case 4:
					strcpy(mensaje, "  |1 First Class\n  |2 Business\n  |3 Premium Economy\n  |4 Economy\n  |Ingrese un numero correspondiente a la nueva clase contratada: ");
					strcpy(mensajeError, "Error! Error! Ingrese un numero, valido le quedan la siguiente cantidad de intentos: ");
					respuesta = getNumInt(&modifInt, mensaje, mensajeError, mensajeSinReintentos, 1, 4, 2);
					if (respuesta == -1){
						break;
					}
					list[i].typePassanger = modifInt;
					break;
				case 5:
					strcpy(mensaje, "  |Porfavor ingrese el nuevo codigo del vuelo: ");
					strcpy(mensajeError, "Error! Error! Ingrese un codigo valido le quedan la siguiente cantidad de intentos: ");
					respuesta = getString(modifCode, mensaje, mensajeError, mensajeSinReintentos,10 , 2);
					if (respuesta == -1){
						break;
					}
					strcpy(list[i].name, modifCode);
					break;
			}

			break;
		}
	}
}

int sortPassangerByCode(Passanger* list, int len, int order){
	int retorno = -1;
	Passanger Aux;
	if(list != NULL){
		if(order == 0){
			for(int i; i < len - 1;i++){
				if(list[i].statusFlight == ACTIVO){
					for(int j; j < len;j++){
						if(list[j].statusFlight == ACTIVO){
							if(strcmp(list[i].flycode,list[j].flycode) > 0){
								Aux = list[i];
								list[i] = list[j];
								list[j] = Aux;
							}
						}
					}
				}
			}
		}else{
			if(order == 1){
				for(int i; i < len - 1;i++){
					if(list[i].statusFlight == ACTIVO){
						for(int j; j < len;j++){
							if(list[j].statusFlight == ACTIVO){
								if(strcmp(list[i].flycode,list[j].flycode) < 0){
									Aux = list[i];
									list[i] = list[j];
									list[j] = Aux;
								}
							}
						}
					}
				}
			}
		}
		retorno = 0;
		printPassanger(list, len);
	}else{
		printf("La lista de pasajero esta vacia\n");
	}
	return retorno;
}

int sortPassenger(Passanger* list, int len, int order){
	int retorno = -1;
	Passanger Aux;
	if(list != NULL){
		if(order == 0){
			for(int i; i < len - 1;i++){
				for(int j; j < len;j++){
					if(strcmp(list[i].lastname,list[j].lastname) > 0){
						Aux = list[i];
						list[i] = list[j];
						list[j] = Aux;
					}
					if(strcmp(list[i].lastname,list[j].lastname) == 0){
						if(strcmp(list[i].name,list[j].name) > 0){
							Aux = list[i];
							list[i] = list[j];
							list[j] = Aux;
						}
					}
				}
			}
		}else{
			if(order == 1){
				for(int i; i < len - 1;i++){
					for(int j; j < len;j++){
						if(strcmp(list[i].lastname,list[j].lastname) < 0){
							Aux = list[i];
							list[i] = list[j];
							list[j] = Aux;
						}
						if(strcmp(list[i].lastname,list[j].lastname) == 0){
							if(strcmp(list[i].name,list[j].name) < 0){
								Aux = list[i];
								list[i] = list[j];
								list[j] = Aux;
							}
						}
					}
				}
			}
		}
		printPassanger(list, len);
		retorno = 0;
	}else{
		printf("La lista de pasajero esta vacia\n");
	}
	return retorno;
}
