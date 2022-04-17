//brief Muestra todos los resultados luego del calculo de precios
//param int : El precio original ingresado
//param float : El precio con el descuento por pagar con tarjeta debito
//param float : El precio con el aumento por pagar con tarjeta credito
//param float : El precio en bitcoins
//param float : El precio unitario de cada kilometro
//param char* : Nombre de la aerolinea que se mostraran los valores
//return No retorna nada
void mostrarResultados(int, float, float, float, float, char*);

//brief Pregunta al usuario por la cantidad de kilometros
//param No recibe ningun parametro
//return int: La cantidad de kilometros ingresados por el usuario
int ingresarKilometros(void);

//brief Pregunta al usuario por el valor del vuelo dependiendo de la Aerolinea
//param char*: Vector con los nombres de las Aerolineas
//return int: Los precios ingresados por el usuario
int ingresarPrecio(char*);

//brief El menu principal que muestra distintas opciones como la carga de datos, el calculo de precios o la muestra de los resultados de las cuentas.
//param int: Los kilometros del vuelo
//param int: Vector con los precios de las Aerolineas
//return int: La respuesta dada por el usuario.
int menuPrincipal(int, int i[]);
