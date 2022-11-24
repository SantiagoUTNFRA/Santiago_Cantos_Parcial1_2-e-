#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Venta.h"

/**
 * @fn int parser_VentasDesdeTexto(FILE*, LinkedList*)
 * @brief Parsea los datos de las ventas desde el archivo data.csv (modo texto).
 *
 * @param pFile Puntero a File
 * @param pArrayListVenta Puntero a mi Linkedlist
 * @return int 0 si pudo , -1 si ocurrió un problema
 */
int parser_VentasDesdeTexto(FILE *pFile, LinkedList *pArrayListVenta)
{

	int todoOk = -1;
	char id[30], modeloAuto[50], cantidad[30], precioUnitario[30], tarjetaCredito[50], dia[30], mes[30], anio[30], header[256];
	Venta *unaVenta;

//	fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, dia, modeloAuto, cantidad, precioUnitario, tarjetaCredito);
	fscanf(pFile, "%[^\n]\n", header);

	while (!feof(pFile))
	{
		fscanf(pFile, "%[^,],%[^/]/%[^/]/%[^,],%[^,],%[^,],$%[^,],%[^\n]\n", id, dia, mes, anio, modeloAuto, cantidad, precioUnitario, tarjetaCredito);

		unaVenta = venta_newParametros(id, dia, mes, anio, modeloAuto, cantidad, precioUnitario, tarjetaCredito);

		ll_add(pArrayListVenta, unaVenta);

		todoOk = 0;
	}

	return todoOk;
}
