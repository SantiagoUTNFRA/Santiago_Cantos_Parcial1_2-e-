#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "inputs.h"

static int imprimeMensaje(char mensaje[]);
static int pideDato(char *cadena);
//static int soloLetras(char cadena[]);
static int ordenarCadena(char cadena[]);
static int validarEntero(char pEnteroAValidar[]);

//EMPIEZAN LAS FUNCIONES.
static int imprimeMensaje(char mensaje[])
{
	int todoOk = -1;
	if (mensaje != NULL)
	{
		printf(mensaje);
		todoOk = 0;
	}
	return todoOk;
}

static int pideDato(char *cadena)
{
	if (cadena != NULL)
	{

		char buffer[256];
		fflush(stdin);
		fgets(buffer, sizeof(buffer), stdin);
		buffer[strlen(buffer) - 1] = '\0';
		strcpy(cadena, buffer);
		return 0;
	}

	return -1;
}

static int validarEntero(char pEnteroAValidar[])
{
	int todoOk = 1;

	if (strlen(pEnteroAValidar) > 0)
	{
		for (int i = 0; i < strlen(pEnteroAValidar); i++)
		{
			if (isdigit(pEnteroAValidar[i]) == 0)
			{
				if (i == 0 && pEnteroAValidar[0] == '-')
				{
					todoOk = 1;

				}
				else
				{
					todoOk = 0;
				}
			}
		}
	}
	else
	{
		todoOk = 0;
	}

	return todoOk;
}

//static int soloLetras(char cadena[])
//{
//	int soloHayLetras = 1;
//	int i = 0;
//
//	if (cadena != NULL)
//	{
//		while (cadena[i] != '\0')
//		{
//			if (cadena[i] != ' ' && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z'))
//			{
//				soloHayLetras = 0;
//			}
//			i++;
//		}
//	}
//	return soloHayLetras;
//}

static int ordenarCadena(char cadena[])
{
	int todoOk = -1;

	if (cadena != NULL)
	{
		strlwr(cadena);
		cadena[0] = toupper(cadena[0]);

		for (int i = 0; cadena[i] != '\0'; i++)
		{
			if (cadena[i] == ' ')
				cadena[i + 1] = toupper(cadena[i + 1]);
		}
		todoOk = 0;
	}
	return todoOk;
}

int pedirFlotante(float *numFloat, char mensaje[], char mensajeError[], float min, float max)
{
	int todoOk = -1;

	if (numFloat != NULL && mensaje != NULL && mensajeError != NULL && min < max)
	{
		char auxFlotante[150];
		imprimeMensaje(mensaje);
		pideDato(auxFlotante);

		while (validarEntero(auxFlotante) == 0 || atof(auxFlotante) > max || atof(auxFlotante) < min)
		{
			imprimeMensaje(mensaje);
			pideDato(auxFlotante);
		}

		*numFloat = atof(auxFlotante);
		todoOk = 1;
	}
	return todoOk;
}

int pedirEntero(int *enteroValidado, char mensaje[], char mensajeError[], int min, int max)
{
	int todoOk = 0;

	if (enteroValidado != NULL && mensaje != NULL && mensajeError != NULL && min < max)
	{
		char auxEntero[150];
		imprimeMensaje(mensaje);
		pideDato(auxEntero);
		fflush(stdin);

		while (validarEntero(auxEntero) == 0 || atoi(auxEntero) > max || atoi(auxEntero) < min)
		{
			imprimeMensaje(mensaje);
			pideDato(auxEntero);
			fflush(stdin);
		}

		*enteroValidado = atoi(auxEntero);
		todoOk = 1;
	}
	return todoOk;
}

int pedirShort(short *shortValidado, char mensaje[], char mensajeError[], int min, int max)
{
	int todoOk = 0;

	if (shortValidado != NULL && mensaje != NULL && mensajeError != NULL && min < max)
	{
		char auxEntero[150];
		imprimeMensaje(mensaje);
		fflush(stdin);
		pideDato(auxEntero);

		while (validarEntero(auxEntero) == 0 || atoi(auxEntero) > max || atoi(auxEntero) < min)
		{
			imprimeMensaje(mensaje);
			fflush(stdin);
			pideDato(auxEntero);
		}

		*shortValidado = atoi(auxEntero);
		todoOk = 1;
	}
	return todoOk;
}

int pedirCaracter(char *charValidado, char mensaje[], char mensajeError[], char primerChar, char segundoChar)
{
	int todoOk = -1;
	char auxChar;

	if (mensaje != NULL && mensajeError != NULL)
	{
		imprimeMensaje(mensaje);
		fflush(stdin);
		scanf("%c", &auxChar);

		while (auxChar != primerChar && auxChar != segundoChar)
		{
			imprimeMensaje(mensajeError);
			fflush(stdin);
			scanf("%c", &auxChar);
		}

		*charValidado = auxChar;
		todoOk = 1;
	}
	return todoOk;
}

int pedirCadena(char cadena[], char mensaje[], char mensajeError[], int max)
{
	int todoOk = -1;

	if (cadena != NULL && mensaje != NULL && mensajeError != NULL && max > 0)
	{
		char auxString[256];
		imprimeMensaje(mensaje);
		pideDato(auxString);
		fflush(stdin);
		while (strlen(auxString) > max || auxString[0] == 00)
		{
			fflush(stdin);
			imprimeMensaje(mensajeError);
			pideDato(auxString);
		}
		fflush(stdin);
		strcpy(cadena, auxString);
		ordenarCadena(cadena);

		todoOk = 0;
	}
	return todoOk;
}

int menu()
{
	int opcion;

	printf("\n\n                                         ***  ABM VENTAS  ***                \n\n\n");
	printf("1) Cargar datos de ventas desde los archivos data.csv.\n");
	printf("2) Alta de venta.\n");
	printf("3) Baja de venta.\n");
	printf("4) Modificacion de venta.\n");
	printf("5) Generar informe ventas.\n");
	printf("6) Guardar los datos del archivo data.csv(MODO TEXTO).\n");
	printf("7) Guardar los datos del archivo data.bin(MODO BINARIO).\n");
	printf("8) Listar ventas(PLUS, YA QUE ESTO NO FUE PEDIDO)\n");
	printf("9) Salir.\n");

	pedirEntero(&opcion, "\nIngrese opcion: ", "\nError, reingrese opcion: ", 1, 9);

	return opcion;
}

int menuModificacion()
{
	int opcion;

	printf("              			***  MENU MODIFICACION  ***                        \n");
	printf("\n");
	printf("1) Modificar dia de la venta.\n");
	printf("2) Modificar mes de la venta.\n");
	printf("3) Modificar anio de la venta.\n");
	printf("4) Modificar modelo del auto.\n");
	printf("5) Modificar cantidad.\n");
	printf("6) Modificar precio.\n");
	printf("7) Modificar tarjeta de credito.\n");

	pedirEntero(&opcion, "\nIngrese opcion: ", "\nError, reingrese opcion valida: ", 1, 7);

	return opcion;
}
