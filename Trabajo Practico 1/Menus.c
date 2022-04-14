#include <stdio.h>
#include "Menus.h"
#define TAM 2

void mostrarResultados(int precio, float precioDebito, float precioCredito, float precioBitcoin, float precioUnitario, char* nombre){
	printf("Precios %s: %i \n", nombre, precio);
	printf("Precio con tarjeta de débito: %f \n", precioDebito);
	printf("Precio con tarjeta de crédito: %f \n", precioCredito);
	printf("Precio con bitcoin: %f \n", precioBitcoin);
	printf("Precio unitario: %f \n", precioUnitario);
}

int ingresarPrecio(char* nombre){
	int Precio;
	printf("Ingrese el precio de %s: ", nombre);
	fflush( stdout );
	scanf("%i", &Precio);
	return Precio;
}

int ingresarKilometros(void){
	int kilometros;
	printf("Ingrese la cantidad de kilometros a viajar: ");
	fflush( stdout );
	scanf("%i", &kilometros);
	return kilometros;
}

int menuPrincipal(int kilometros, int precios[]){
	int opcion;
		printf("1. Ingresar Kilómetros \n");
		printf("- Kilometros ingresados: %i \n", kilometros);

		printf("2. Ingresar Precio de Vuelos: \n");

		printf(" - Precio vuelo Aerolíneas: %i \n", precios[0]);
		printf(" - Precio vuelo Latam: %i \n",precios[1]);

		printf("3. Calcular todos los costos \n");

		printf("4. Informar Resultados \n");

		printf("5. Carga Forzada de datos \n");

		printf("6. Salir \n");

		printf("Elija una opcion (1-6): ");
		fflush( stdout );
		scanf("%i", &opcion);
	return opcion;
}
