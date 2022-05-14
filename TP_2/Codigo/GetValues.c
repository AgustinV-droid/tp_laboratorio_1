#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Funciones.h"
#include "GetValues.h"

#include "arrayPassanger.h"
#define TRUE 0
#define FALSE 1
#define TAM 2000

int myGets(char* cadena, int longitud){
	int retorno =-1;
	char bufferString[4096];
	if(cadena != NULL && longitud > 0){
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL){
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n'){
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud){
				strncpy(cadena,bufferString,longitud);
				retorno = 0;
			}
		}
	}

	return retorno;
}

int esNumericaInt(char* cadena, int limite){
	int retorno = -1;
	for(int i = 0; i < limite && cadena[i] != '\0'; i++){
		if(i == 0 && (cadena[i] == '+' || cadena[i] == '-')){
			continue;
		}
		if(cadena[i] > '9' || cadena[i] < '0'){
			retorno = 0;
			break;
		}
	}
	return retorno;
}


int getInt(int* pResultado){
	int retorno = 0;
	char bufferString[51];
	if(pResultado != NULL && myGets(bufferString,sizeof(bufferString)) == 0 && esNumericaInt(bufferString,sizeof(bufferString))){
		retorno = 0;
		*pResultado = atoi(bufferString);
	}
	return retorno;
}


int getNumInt(int* pResultado, char* mensaje, char* mensajeError,char* mensajeSinReintentos, int minimo, int maximo, int reintentos){
	int bufferInt;
	int retorno = -1;
	printf("%s", mensaje);
	do{
		if((getInt(&bufferInt) == 0) && (bufferInt >= minimo) && (bufferInt <= maximo)){
			retorno = 0;
			*pResultado = bufferInt;
			break;

		}
		if(reintentos == 0){
			printf("%s", mensajeSinReintentos);
		}else{
			printf("%s %i \n",mensajeError,reintentos);
		}
		reintentos--;
	}while(reintentos >= 0);
	return retorno;
}

int esNumericaFloat(char* cadena, int limite){
	int retorno = -1;
	int contadorPuntos = 0;
	for(int i = 0; i < limite && cadena[i] != '\0'; i++){
		if(i == 0 && (cadena[i] == '+' || cadena[i] == '-')){
			continue;
		}
		if(cadena[i] == '.'){
			contadorPuntos ++;
			if(contadorPuntos > 1){
				break;
			}
		}
		if(cadena[i] > '9' || cadena[i] < '0'){
			retorno = 1;
			break;
		}
	}
	return retorno;
}

int getFloat(float* pResultado){
	int retorno = 0;
	char bufferString[51];
	if(pResultado != NULL && myGets(bufferString,sizeof(bufferString)) == 0 && esNumericaFloat(bufferString,sizeof(bufferString))){
		retorno = 0;
		*pResultado = atof(bufferString);
	}
	return retorno;
}

int getNumFloat(float* pResultado, char* mensaje, char* mensajeError,char* mensajeSinReintentos, float minimo, float maximo, int reintentos){
	float bufferFloat;
	int retorno = -1;
	printf("%s", mensaje);
	do{
		if((getFloat(&bufferFloat) == 0) && (bufferFloat >= minimo) && (bufferFloat <= maximo)){
			retorno = 0;
			*pResultado = bufferFloat;
			break;
		}
		if(reintentos == 0){
			printf("%s", mensajeSinReintentos);
		}else{
			printf("%s %i \n",mensajeError,reintentos);
		}
		reintentos--;
	}while(reintentos >= 0);
	return retorno;
}

int getString(char pResultado[], char* mensaje, char* mensajeError,char* mensajeSinReintentos,int len, int reintentos){
	char bufferString[len];
	int retorno = -1;
	printf("%s", mensaje);
	do{
		if((myGets(bufferString, len) == 0)){
			retorno = 0;
			strcpy(pResultado,bufferString);
			break;
		}
		if(reintentos == 0){
			printf("%s", mensajeSinReintentos);
		}else{
			printf("%s %i \n",mensajeError,reintentos);
		}
		reintentos--;
	}while(reintentos >= 0);
	return retorno;
}
