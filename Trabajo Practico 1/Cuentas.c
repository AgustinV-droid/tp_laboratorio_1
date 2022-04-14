#include "Cuentas.h"

int calcularDebito(int precio){
	int precioDebito;
	precioDebito = precio * 0.9;
	return precioDebito;
}

int calcularCredito(int precio){
	int precioCredito;
	precioCredito = precio * 1.25;
	return precioCredito;
}

float calcularBitcoin(int precio){
	float Bitcoin = 4606954.55;
	float precioBitcoin;
	precioBitcoin = precio / Bitcoin;
	return precioBitcoin;
}

float calcularUnitaro(int precio,int kilometros){
	float precioUnitaro;
	precioUnitaro = precio / kilometros;
	return precioUnitaro;
}

int calcularDiferencia(int precioLatam, int precioAerolineas){
	int diferencia;
	diferencia = precioLatam - precioAerolineas;
	if (diferencia < 0){
		diferencia = diferencia *-1;
	}
	return diferencia;
}
