/*\n >< B b*/
#include <stdio.h>
#include <stdlib.h>
#include "Menus.h"
#include "Cuentas.h"
#define TAM 2//Define la cantidad direcciones que tendran los vectores utilizados


int main() {
	int opcion; //Variable donde se guarda la decision del usuario en el menu principal
	int kilometros = 0; //variable donde se almacena la cantidad de Kilometros ingresada por el usuario
	int flagKilometro = 0;//Sirve para comprobar si se han ingresado los kilometros o no
	int precios[TAM]; //Un vector donde se almacenan los dos precios ingresados por el usuario
	precios[0] = 0;//Inicializa las direcciones del vector
	precios[1] = 0;
	int flagPrecio = 0;//Sirve para comprobar si se han ingresado los precios o no
	float preciosDebito[TAM];//Un vector donde se almacenan los dos precios luego del descuento de debito
	float preciosCredito[TAM];//Un vector donde se almacenan los dos precios luego del aumento de credito
	float preciosBitcoin[TAM];//Un vector donde se almacenan los dos precios en bitcoin
	float preciosUnitarios[TAM];//Un vector donde se almacenan el valor de cada kilometro individual
	char* nombre[TAM];//Un vector donde se almacenan los nombres de las aerolineas
	nombre[0] = "Aerolineas";//Pre carga de los nombres de als aerolineas
	nombre[1] = "Latam";
	int flagCuentas = 0;//Sirve para comprobar si se han realizado las cuentas o no
	int diferencia = 0;//Variable donde se guarda el valor de la diferencia
	do{
		opcion = menuPrincipal(kilometros, precios);//Llama menu principal y almacena la decision que tomo el usuario para ser evaluada
		switch(opcion){//Evalua la decision del usuario recibida anterior mente
			case 1 ://opcion = 1
				kilometros = ingresarKilometros();//Llama al menu donde se pregunta al usuario cuantos Kilometros va a viajar
				flagKilometro = 1;//Setea la flag de Kilometros en 1
				flagCuentas = 0;//Setea la flag de Cuentas en 0
				break;
			case 2 ://opcion = 2
				precios[0] = ingresarPrecio(nombre[0]);//Llama al menu donde se pregunta al usuario cuantos caunto vale el vuelo con una aerolinea
				precios[1] = ingresarPrecio(nombre[1]);//Llama al menu donde se pregunta al usuario cuantos caunto vale el vuelo con una aerolinea
				flagPrecio = 1;//Setea la flag de Precios en 1
				flagCuentas = 0;//Setea la flag de Cuentas en 0
				break;
			case 3://opcion = 3
				if(flagKilometro == 1 && flagPrecio == 1){
					for(int i = 0; i < 2 ;i++){
						preciosDebito[i] = calcularDebito(precios[i]);//Calcula un descuento de 10%
						preciosCredito[i] = calcularCredito(precios[i]);//Calcula un aumento del 25%
						preciosBitcoin[i] = calcularBitcoin(precios[i]);//Calcula el precio en bitcoins
						preciosUnitarios[i] = calcularUnitaro(precios[i],kilometros);//Calcula el valor unitario por kilometro
					}
					flagCuentas = 1;//Setea la flag de Cuentas en 1
				}else{
					printf("Por favor ingrese los datos necesarios para poder realizar las cuentas.\n");
				}
				diferencia = calcularDiferencia(precios[1],precios[0]);//Calcula la diferencia entre los 2 precios
				break;
			case 4://opcion = 4
				if(flagCuentas == 1){
						for(int i = 0; i < 2 ;i++){
							mostrarResultados(precios[i], preciosDebito[i], preciosCredito[i], preciosBitcoin[i], preciosUnitarios[i],nombre[i]);
							//Llama al menu donde se muestran los valores de las cuentas
						};
						printf("La diferecnia de precio es: %i \n", diferencia);//Muestra el valor de la diferencia entre los precios al usuario
						fflush( stdout );
						system("PAUSE");//Pausa el programa y espera a que precione enter para continuar
				}else{
					printf("Por favor realice las cuentas para poder mostrar los resultados con los valores ingresados.\n");
				}
				break;
			case 5://opcion = 5
				kilometros = 7090;//Hardcodea el valor de kilometros
				precios[0] = 162965 ;//Hardcodea el valor del primer precio
				precios[1] = 159339;//Hardcodea el valor del segundo precio
				for(int i = 0; i < 2 ;i++){
					preciosDebito[i] = calcularDebito(precios[i]);//Calcula un descuento de 10%
					preciosCredito[i] = calcularCredito(precios[i]);//Calcula un aumento del 25%
					preciosBitcoin[i] = calcularBitcoin(precios[i]);//Calcula el precio en bitcoins
					preciosUnitarios[i] = calcularUnitaro(precios[i],kilometros);//Calcula el valor unitario por kilometro
				}
				diferencia= calcularDiferencia(precios[1],precios[0]);//Calcula la diferencia entre los 2 precios
				for(int i = 0; i < 2 ;i++){
					mostrarResultados(precios[i], preciosDebito[i], preciosCredito[i], preciosBitcoin[i], preciosUnitarios[i], nombre[i]);
					//Llama al menu donde se muestran los valores de las cuentas
				}
				printf("La diferecnia de precio es: %i \n", diferencia);//Muestra el valor de la diferencia entre los precios al usuario
				fflush( stdout );
				system("PAUSE");//Pausa el programa y espera a que precione enter para continuar
				break;
		}
	}while(opcion != 6);
    return 0;
}
