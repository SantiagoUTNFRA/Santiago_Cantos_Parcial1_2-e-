#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Venta.h"
#include "Controller.h"
#include "parser.h"
#include "inputs.h"
#include "LinkedList.h"

static void printAlta();
static void printModificar();
static void printBaja();
static void printVenta();

static int controller_siguienteId();
static void controller_guardarIdSiguiente(int idActual);
static int controller_validarId(LinkedList *pArrayListJugador, int id);

/**
 * @fn int controller_cargarVentasDesdeTexto(char*, LinkedList*)
 * @brief Carga los datos de las ventas desde el archivo ventas.csv
 *
 * @param path Puntero a char, path de mi archivo
 * @param pArrayListVenta Puntero a mi Linkedlist
 * @return int 0 si pudo, -1 si ocurrió un problema
 */
int controller_cargarVentasDesdeTexto(char *path, LinkedList *pArrayListVenta)
{
	int todoOk = -1;
	FILE *f;

	if (path != NULL && pArrayListVenta != NULL)
	{
		f = fopen(path, "r");

		if (f == NULL)
		{
			return todoOk;
		}
		else
		{
			parser_VentasDesdeTexto(f, pArrayListVenta);
			todoOk = 0;
		}
		fclose(f);
	}
	return todoOk;
}

/**
 * @fn int controller_agregarVenta(LinkedList*)
 * @brief Funcion que da de alta una venta
 *
 * @param pArrayListVenta Puntero a mi Linkedlist
 * @return int 0 si pudo, -1 si ocurrió un problem
 */
int controller_agregarVenta(LinkedList *pArrayListVenta)
{
	int todoOk = -1, id, dia, mes, anio, cantidad;
	float precioUnitario;
	char modeloAuto[30], tarjetaCredito[30];

	Venta *unaVenta;

	if (pArrayListVenta != NULL)
	{
		printAlta();
		unaVenta = venta_new();
		if (unaVenta != NULL)
		{
			id = controller_siguienteId();
			venta_setId(unaVenta, id);

			pedirEntero(&dia, "\nIngrese el dia de la venta(1~31): ", "\nError. ingrese el dia de la venta: ", 1, 31);
			venta_setDia(unaVenta, dia);

			pedirEntero(&mes, "\nIngrese el mes de la venta(1~12): ", "\nError. ingrese el mes de la venta: ", 1, 12);
			venta_setMes(unaVenta, mes);

			pedirEntero(&anio, "\nIngrese el anio de la venta(1950~2022): ", "\nError. ingrese el anio de la venta: ", 1950, 2022);
			venta_setAnio(unaVenta, anio);

			pedirEntero(&cantidad, "\nIngrese la cantidad(1~5): ", "\nError.Ingrese la cantidad(1~5): ", 1, 5);
			venta_setCantidad(unaVenta, cantidad);

			pedirCadena(modeloAuto, "\nIngrese el modelo del auto: ", "\nError.Ingrese el modelo del auto: ", 30);
			venta_setModeloAuto(unaVenta, modeloAuto);

			pedirFlotante(&precioUnitario, "\nIngrese el precio de la venta: ", "\nError, Ingrese el precio de la venta: ", 1500, 20000);
			venta_setPrecioUnitario(unaVenta, precioUnitario);

			pedirCadena(tarjetaCredito, "\nIngrese la tarjeta de credito: ", "\nError. Ingrese la tarjeta de credito: ", 30);
			venta_setTarjetaCredito(unaVenta, tarjetaCredito);

			printVenta();
			venta_MostrarUnaVenta(unaVenta);

			ll_add(pArrayListVenta, unaVenta);
			controller_guardarIdSiguiente(id);
			todoOk = 0;
		}
	}
	return todoOk;
}

/**
 * @fn int controller_removerVenta(LinkedList*)
 * @brief Funcion que remueve una venta
 *
 * @param pArrayListVenta Puntero a mi Linkedlist
 * @return int 0 si pudo, -1 si ocurrió un problema
 */
int controller_removerVenta(LinkedList *pArrayListVenta)
{
	int todoOk = 0, id, indiceVenta;
	char respuesta;
	Venta *unaVenta;

	if (pArrayListVenta != NULL)
	{
		printBaja();
		controller_listarVentas(pArrayListVenta);

		do
		{
			pedirEntero(&id, "\nIngrese ID de la venta a dar de baja: ", "Error, Reingrese ID de la venta a dar de baja: ", 1, 1000);
		} while (controller_validarId(pArrayListVenta, id) != 0);

		indiceVenta = controller_buscarVentaId(pArrayListVenta, id);

		if (indiceVenta == -1)
		{
			printf("El id ingresado no existe\n");
		}
		else
		{
			unaVenta = ll_get(pArrayListVenta, indiceVenta);

			printVenta();
			venta_MostrarUnaVenta(unaVenta);

			pedirCaracter(&respuesta, "\nSeguro que desea remover esta venta? (s: SI y n: NO): ",
					"\nError. Seguro que desea remover esta venta? (s: SI y n: NO): ", 's', 'n');

			if (respuesta == 's')
			{
				ll_remove(pArrayListVenta, indiceVenta);
				venta_delete(unaVenta);
				todoOk = 0;
			}
		}
	}
	return todoOk;
}

/**
 * @fn int controller_editarVenta(LinkedList*)
 * @brief Funcion que modifica los datos de una venta
 *
 * @param pArrayListVenta Puntero a mi Linkedlist
 * @return int 0 si pudo, -1 si ocurrió un problema
 */
int controller_editarVenta(LinkedList *pArrayListVenta)
{
	int todoOk = -1, id, dia, mes, anio, cantidad, indiceVenta;
	float precioUnitario;
	char modeloAuto[30], tarjetaCredito[30];

	Venta *unaVenta;

	if (pArrayListVenta != NULL)
	{
		printModificar();

		controller_listarVentas(pArrayListVenta);

		do
		{
			pedirEntero(&id, "\nIngrese ID de la venta a modificar: ", "Error, Reingrese ID de la venta a modificar: ", 1, 1000);
		} while (controller_validarId(pArrayListVenta, id) != 0);

		indiceVenta = controller_buscarVentaId(pArrayListVenta, id);

		unaVenta = ll_get(pArrayListVenta, indiceVenta);

		if (indiceVenta == -1)
		{
			printf("El id ingresado no existe\n");
		}
		else
		{
			printVenta();
			venta_MostrarUnaVenta(unaVenta);

			switch (menuModificacion())
			{
				case 1:
					pedirEntero(&dia, "\nIngrese el nuevo dia de la venta: ", "\nError, reingrese el nuevo dia  de la venta: ", 1, 31);
					venta_setDia(unaVenta, dia);
					todoOk = 0;
					break;
				case 2:
					pedirEntero(&mes, "\nIngrese el nuevo mes de la venta: ", "\nError, reingrese el nuevo mes de la venta: ", 1, 12);
					venta_setDia(unaVenta, mes);
					todoOk = 0;
					break;
				case 3:
					pedirEntero(&anio, "\nIngrese el nuevo anio de la venta: ", "\nError, reingrese el nuevo anio de la venta: ", 1950, 2022);
					venta_setDia(unaVenta, anio);
					todoOk = 0;
					break;
				case 4:
					pedirCadena(modeloAuto, "\nIngrese el nuevo modelo del auto: ", "\nError, reingrese el nuevo modelo del auto: ", 30);
					venta_setModeloAuto(unaVenta, modeloAuto);
					todoOk = 0;
					break;
				case 5:
					pedirEntero(&cantidad, "\nIngrese la nueva cantidad de la venta: ", "\nError, reingrese el nuevo anio de la venta: ", 1950, 2022);
					venta_setDia(unaVenta, cantidad);
					todoOk = 0;
					break;
				case 6:
					pedirFlotante(&precioUnitario, "\nIngrese el nuevo precio de la venta: ", "\nIngrese el nuevo precio de la venta: ", 1500, 20000);
					venta_setPrecioUnitario(unaVenta, precioUnitario);
					todoOk = 0;
					break;
				case 7:
					pedirCadena(tarjetaCredito, "\nIngrese la nueva tarjeta de credito: ", "\nIngrese la nueva tarjeta de credito: ", 30);
					venta_setTarjetaCredito(unaVenta, tarjetaCredito);
					todoOk = 0;
					break;
			}
		}
	}

	return todoOk;
}

/**
 * @fn int controller_GenerarInforme(LinkedList*)
 * @brief Funcion que genera un archivo de texto con informacion de las ventas
 *
 * @param pArrayListVenta Puntero a mi Linkedlist
 * @return int 0 si pudo, -1 si ocurrió un problem
 */
int controller_GenerarInforme(LinkedList *pArrayListVenta)
{
	int todoOk = -1;

	FILE *f;

	if (pArrayListVenta != NULL)
	{
		int totalVentas = ll_count(pArrayListVenta, venta_CriterioTotalVentas);
		int cantMayorDiezMil = ll_count(pArrayListVenta, venta_CriterioMayorDiezMil);
		int cantMayorVeinteMil = ll_count(pArrayListVenta, venta_CriterioMayorVeinteMil);
		int cantModelosIguales = ll_count(pArrayListVenta, venta_CriterioIgualFalcon);

		f = fopen("informe.txt", "w");

		fprintf(f, "********************\n");
		fprintf(f, "Informe de ventas\n");
		fprintf(f, "********************\n");
		fprintf(f, "- Cantidad de unidades vendidas totales: %d\n", totalVentas);
		fprintf(f, "- Cantidad de ventas por un monto mayor a $10000: %d\n", cantMayorDiezMil);
		fprintf(f, "- Cantidad de ventas por un monto mayor a $20000: %d\n", cantMayorVeinteMil);
		fprintf(f, "- Cantidad de autos modelo falcon vendidos: %d\n", cantModelosIguales);

		fclose(f);

		todoOk = 0;
	}

	return todoOk;
}

/**
 * @fn int controller_guardarVentasModoTexto(char*, LinkedList*)
 * @brief Funcion que guarda los datos de las ventas en el archivo data.csv(MODO TEXTO)
 *
 * @param path Puntero a char que corresponde al Path de mi archivo
 * @param pArrayListVenta Puntero a mi Linkedlist
 * @return int 0 si pudo, -1 si ocurrió un problema.
 */
int controller_guardarVentasModoTexto(char *path, LinkedList *pArrayListVenta)
{
	int todoOk = -1, id, dia, mes, anio, cantidad;
	float precioUnitario;
	char modeloAuto[30], tarjetaCredito[30];

	Venta *unaVenta;
	FILE *f;

	if (path != NULL && pArrayListVenta != NULL)
	{
		f = fopen(path, "w");

		unaVenta = venta_new();

		fprintf(f, "id,fecha,modeloAuto,cantidad,precioUnitario,tarjeta\n");

		for (int i = 0; i < ll_len(pArrayListVenta); i++)
		{
			unaVenta = ll_get(pArrayListVenta, i);
			if (unaVenta != NULL)
			{
				venta_getId(unaVenta, &id);
				venta_getDia(unaVenta, &dia);
				venta_getMes(unaVenta, &mes);
				venta_getAnio(unaVenta, &anio);
				venta_getModeloAuto(unaVenta, modeloAuto);
				venta_getCantidad(unaVenta, &cantidad);
				venta_getPrecioUnitario(unaVenta, &precioUnitario);
				venta_getTarjetaCredito(unaVenta, tarjetaCredito);

				fprintf(f, "%d,%d/%d/%d,%s,%d,$%f,%s\n", id, dia, mes, anio, modeloAuto, cantidad, precioUnitario, tarjetaCredito);

				todoOk = 0;
			}
		}

		fclose(f);
	}
	return todoOk;
}

/**
 * @fn int controller_guardarVentasModoBinario(char*, LinkedList*)
 * @brief Funcion que guarda los datos de las ventas en el archivo data.bin(MODO BINARIO)
 *
 * @param path Puntero a char que corresponde al Path de mi archivo
 * @param pArrayListVenta Puntero a mi Linkedlist
 * @return int 0 si pudo, -1 si ocurrio un problema.
 */
int controller_guardarVentasModoBinario(char *path, LinkedList *pArrayListVenta)
{
	int todoOk = -1;
	FILE *f;
	Venta *unaVenta;

	if (path != NULL && pArrayListVenta != NULL)
	{
		f = fopen(path, "wb");

		unaVenta = venta_new();

		if (unaVenta != NULL)
		{
			for (int i = 0; i < ll_len(pArrayListVenta); i++)
			{
				unaVenta = ll_get(pArrayListVenta, i);
				fwrite(unaVenta, sizeof(Venta), 1, f);
			}
			todoOk = 0;
		}
		fclose(f);
	}
	return todoOk;
}

/**
 * @fn int controller_listarVentas(LinkedList*)
 * @brief Funcion que lista todas las ventas cargadas
 *
 * @param pArrayListVenta Puntero a mi Linkedlist
 * @return int 0 si pudo, -1 si ocurrió un problema
 */
int controller_listarVentas(LinkedList *pArrayListVenta)
{
	int todoOk = -1, lenLista;
	Venta *auxVenta = NULL;

	if (pArrayListVenta != NULL)
	{
		lenLista = ll_len(pArrayListVenta);
		if (lenLista > 0)
		{
			todoOk = 0;

			printVenta();

			for (int i = 0; i < lenLista; i++)
			{
				auxVenta = (Venta*) ll_get(pArrayListVenta, i);
				venta_MostrarUnaVenta(auxVenta);
			}
		}
	}
	else
	{
		venta_delete(auxVenta);
	}
	return todoOk;
}

/**
 * @fn void printAlta()
 * @brief Funcion que imprime un mensaje de alta en pantalla
 *
 */
static void printAlta()
{
	printf("\n                                         *** Alta de venta ***                  \n\n");
}

/**
 * @fn void printModificar()
 * @brief Funcion que imprime un mensaje de modificacion en pantalla
 *
 */
static void printModificar()
{
	printf("\n                                         *** Modificacion de venta ***                  \n\n");
}

/**
 * @fn void printBaja()
 * @brief Funcion que imprime un mensaje de baja en pantalla
 *
 */
static void printBaja()
{
	printf("\n                                         *** Baja de venta ***                  \n\n");
}

/**
 * @fn void printVenta()
 * @brief Funcion que imprime una cabezera de una tabla por pantalla
 *
 */
static void printVenta()
{
	printf("\n-----------------------------------------------------------------------------------------------------\n");
	printf("| ID    | FECHA        | MODELO                 | CANTIDAD    | PRECIO        | TARJETA DE CREDITO  |\n");
	printf("-----------------------------------------------------------------------------------------------------\n");
}

/**
 * @fn int controller_siguienteId()
 * @brief Funcion que carga el siguiente id
 *
 * @return int 0 si pudo, -1 si ocurrió un problema
 */
static int controller_siguienteId()
{
	FILE *f = fopen("ultimoIdVenta.txt", "r");
	int *idActual = (int*) malloc(sizeof(int));
	int siguienteId;

	if (f == NULL)
	{
		siguienteId = 101;
	}
	else
	{
		fscanf(f, "%d", idActual);
		siguienteId = *idActual + 1;
	}
	fclose(f);

	return siguienteId;
}

/**
 * @fn void controller_guardarIdSiguiente(int)
 * @brief Funcion que carga el id en un archivo.txt
 *
 * @param idActual Int id que representa el ultimo id actualmente
 */
static void controller_guardarIdSiguiente(int idActual)
{
	FILE *f = fopen("ultimoID.txt", "r+");

	if (f == NULL)
	{
		f = fopen("ultimoID.txt", "w");
	}

	fprintf(f, "%d", idActual);
	fclose(f);
}

/**
 * @fn int controller_validarId(LinkedList*, int)
 * @brief Funcion que valida si el id pasado por parametro existe
 *
 * @param pArrayListJugador Puntero a mi Linkedlist
 * @param id Int id a validar
 * @return int 0 si pudo, -1 si ocurrió un problema
 */
static int controller_validarId(LinkedList *pArrayListVenta, int id)
{
	int todoOk = -1, idEncontrado, lenLista;

	Venta *unaVenta;

	if (pArrayListVenta != NULL && id >= 0)
	{
		lenLista = ll_len(pArrayListVenta);

		for (int i = 0; i < lenLista; ++i)
		{
			unaVenta = ll_get(pArrayListVenta, i);

			if (unaVenta != NULL)
			{
				venta_getId(unaVenta, &idEncontrado);

				if (id == idEncontrado)
				{
					todoOk = 0;
					break;
				}
			}
		}
	}
	return todoOk;
}

/**
 * @fn int controller_buscarJugadorId(LinkedList*, int)
 * @brief Funcion que busca una venta por id
 *
 * @param this Puntero a mi Linkedlist
 * @param id Int id a buscar en mi lista
 * @return int 0 si encontró, -1 si no
 */
int controller_buscarVentaId(LinkedList *this, int id)
{
	int todoOk = -1, idComparar;
	Venta *unaVenta;

	if (this != NULL && id > 0)
	{
		for (int i = 0; i < ll_len(this); i++)
		{
			unaVenta = ll_get(this, i);

			if (unaVenta != NULL)
			{
				venta_getId(unaVenta, &idComparar);
				if (idComparar == id)
				{
					todoOk = i;
					break;
				}
			}
		}
	}
	return todoOk;
}
