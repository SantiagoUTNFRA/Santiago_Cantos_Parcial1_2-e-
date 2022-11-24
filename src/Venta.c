#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Controller.h"
#include "Venta.h"

/**
 * @fn Venta venta_new*()
 * @brief Funcion constructora de una venta
 *
 * @return int 0 si pudo, -1 si ocurrió un error
 */
Venta* venta_new()
{
	Venta *unaVenta = NULL;

	unaVenta = (Venta*) malloc(sizeof(Venta));

	if (unaVenta != NULL)
	{
		venta_setId(unaVenta, 0);
		venta_setCantidad(unaVenta, 0);
		venta_setPrecioUnitario(unaVenta, 0);
		venta_setDia(unaVenta, 0);
		venta_setMes(unaVenta, 0);
		venta_setAnio(unaVenta, 0);
		venta_setModeloAuto(unaVenta, " ");
		venta_setTarjetaCredito(unaVenta, " ");
	}

	return unaVenta;
}

/**
 * @fn Venta venta_newParametros*(char*, char*, char*, char*, char*, char*, char*, char*)
 * @brief Funcion constructora de una venta con parametros
 *
 * @param idStr Puntero a char que representa el id de una venta
 * @param diaStr Puntero a char que representa el dia de una venta
 * @param mesStr Puntero a char que representa el mes de una venta
 * @param anioStr Puntero a char que representa el anio de una venta
 * @param modeloStr Puntero a char que representa el modelo del auto de una venta
 * @param cantidadStr Puntero a char que representa la cantidad de una venta
 * @param precioStr Puntero a char que representa el precio de una venta
 * @param tarjetaStr Puntero a char que representa la tarjeta de credito de una venta
 * @return int 0 si pudo, -1 si ocurrió un error
 */
Venta* venta_newParametros(char *idStr, char *diaStr, char *mesStr, char *anioStr, char *modeloStr, char *cantidadStr, char *precioStr, char *tarjetaStr)
{
	Venta *unaVenta = NULL;

	unaVenta = venta_new();

	if (unaVenta != NULL)
	{
		if ((venta_setId(unaVenta, atoi(idStr)) || venta_setCantidad(unaVenta, atoi(cantidadStr)) || venta_setPrecioUnitario(unaVenta, atof(precioStr))
				|| venta_setModeloAuto(unaVenta, modeloStr) || venta_setTarjetaCredito(unaVenta, tarjetaStr) || venta_setDia(unaVenta, atoi(diaStr))
				|| venta_setMes(unaVenta, atoi(mesStr)) || venta_setAnio(unaVenta, atoi(anioStr))) != 0)
		{
			unaVenta = NULL;
			venta_delete(unaVenta);
		}
	}

	return unaVenta;
}

/**
 * @fn void venta_delete(Venta*)
 * @brief Funcion que elimina una venta
 *
 * @param this Puntero a una venta
 */
void venta_delete(Venta *this)
{
	if (this != NULL)
	{
		free(this);
	}
}

/**
 * @fn int venta_setId(Venta*, int)
 * @brief Funcion que setea el id en una venta
 *
 * @param this Puntero a una venta
 * @param id int id a setear
 * @return int 0 si pudo, -1 si ocurrio un problema
 */
int venta_setId(Venta *this, int id)
{
	int todoOk = -1;

	if (this != NULL && id >= 0)
	{
		this->idVenta = id;
		todoOk = 0;
	}

	return todoOk;
}

/**
 * @fn int venta_getId(Venta*, int*)
 * @brief Funcion que obtiene el id de una venta
 *
 * @param this Puntero a una venta
 * @param id int id a obtener
 * @return int 0 si pudo, -1 si ocurrio un problema
 */
int venta_getId(Venta *this, int *id)
{
	int todoOk = -1;

	if (this != NULL && id != NULL)
	{
		*id = this->idVenta;
		todoOk = 0;
	}

	return todoOk;
}

/**
 * @fn int venta_setModeloAuto(Venta*, char*)
 * @brief Funcion que setea el modeloAuto en una venta
 *
 * @param this Puntero a una venta
 * @param modeloAuto Puntero a char modeloAuto
 * @return int 0 si pudo, -1 si ocurrio un problema
 */
int venta_setModeloAuto(Venta *this, char *modeloAuto)
{
	int todoOk = -1;

	if (this != NULL && modeloAuto != NULL)
	{
		if (strlen(modeloAuto) < 50 && strlen(modeloAuto) > 1)
		{
			fflush(stdin);
			strcpy(this->modeloAuto, modeloAuto);
			strlwr(this->modeloAuto);
			this->modeloAuto[0] = toupper(this->modeloAuto[0]);
			todoOk = 0;
		}
	}

	return todoOk;
}

/**
 * @fn int venta_getModeloAuto(Venta*, char*)
 * @brief Funcion que obtiene el modeloAuto de una venta
 *
 * @param this Puntero a una venta
 * @param modeloAuto Puntero a char modeloAuto
 * @return int 0 si pudo, -1 si ocurrio un problema
 */
int venta_getModeloAuto(Venta *this, char *modeloAuto)
{
	int todoOk = -1;

	if (this != NULL && modeloAuto != NULL)
	{
		strcpy(modeloAuto, this->modeloAuto);
		todoOk = 0;
	}

	return todoOk;
}

/**
 * @fn int venta_setCantidad(Venta*, int)
 * @brief Funcion que setea la cantidad en una venta
 *
 * @param this Puntero a una venta
 * @param cantidad int cantidad a setear
 * @return int 0 si pudo, -1 si ocurrio un problema
 */
int venta_setCantidad(Venta *this, int cantidad)
{
	int todoOk = -1;

	if (this != NULL && cantidad > 0 && cantidad <= 5)
	{
		this->cantidad = cantidad;
		todoOk = 0;
	}

	return todoOk;
}

/**
 * @fn int venta_getCantidad(Venta*, int*)
 * @brief Funcion que obtiene la cantidad en una venta
 *
 * @param this Puntero a una venta
 * @param cantidad int cantidad a obtener
 * @return int 0 si pudo, -1 si ocurrio un problema
 */
int venta_getCantidad(Venta *this, int *cantidad)
{
	int todoOk = -1;

	if (this != NULL && cantidad != NULL)
	{
		*cantidad = this->cantidad;
		todoOk = 0;
	}

	return todoOk;
}

/**
 * @fn int venta_setPrecioUnitario(Venta*, float)
 * @brief Funcion que setea el precioUnitario en una venta
 *
 * @param this Puntero a una venta
 * @param precio float precio a setear
 * @return int 0 si pudo, -1 si ocurrio un problema
 */
int venta_setPrecioUnitario(Venta *this, float precio)
{
	int todoOk = -1;

	if (this != NULL && precio >= 0)
	{
		this->precioUnitario = precio;
		todoOk = 0;
	}
	return todoOk;
}

/**
 * @fn int venta_getPrecioUnitario(Venta*, float*)
 * @brief Funcion que obtiene la cantidad en una venta
 *
 * @param this Puntero a una venta
 * @param precio float precio a obtener
 * @return int 0 si pudo, -1 si ocurrio un problema
 */
int venta_getPrecioUnitario(Venta *this, float *precio)
{
	int todoOk = -1;

	if (this != NULL && precio != NULL)
	{
		*precio = this->precioUnitario;
		todoOk = 0;
	}

	return todoOk;
}

/**
 * @fn int venta_setTarjetaCredito(Venta*, char[])
 * @brief Funcion que setea la tarjeta en una venta
 *
 * @param this Puntero a una venta
 * @param tarjeta Puntero a char
 * @return int 0 si pudo, -1 si ocurrio un problema
 */
int venta_setTarjetaCredito(Venta *this, char tarjeta[])
{
	int todoOk = -1;

	if (this != NULL && tarjeta != NULL)
	{
		strcpy(this->tarjetaCredito, tarjeta);
		todoOk = 0;
	}

	return todoOk;
}

/**
 * @fn int venta_getTarjetaCredito(Venta*, char[])
 * @brief Funcion que obtiene la tarjeta en una venta
 *
 * @param this Puntero a una venta
 * @param tarjeta
 * @return int 0 si pudo, -1 si ocurrio un problema
 */
int venta_getTarjetaCredito(Venta *this, char tarjeta[])
{
	int todoOk = -1;

	if (this != NULL && tarjeta != NULL)
	{
		strcpy(tarjeta, this->tarjetaCredito);
		todoOk = 0;
	}

	return todoOk;
}

/**
 * @fn int venta_setDia(Venta*, int)
 * @brief Funcion que setea el dia en una venta
 *
 * @param this Puntero a una venta
 * @param dia int dia a setear
 * @return int 0 si pudo, -1 si ocurrio un problema
 */
int venta_setDia(Venta *this, int dia)
{
	int todoOk = -1;

	if (this != NULL && dia > 0 && dia <= 31)
	{
		this->fecha.dia = dia;
		todoOk = 0;
	}

	return todoOk;
}

/**
 * @fn int venta_getDia(Venta*, int*)
 * @brief Funcion que obtiene el dia en una venta
 *
 * @param this Puntero a una venta
 * @param dia int dia a obtener
 * @return int 0 si pudo, -1 si ocurrio un problema
 */
int venta_getDia(Venta *this, int *dia)
{
	int todoOk = -1;

	if (this != NULL && dia != NULL)
	{
		*dia = this->fecha.dia;
		todoOk = 0;
	}

	return todoOk;
}

/**
 * @fn int venta_setMes(Venta*, int)
 * @brief Funcion que setea el mes en una venta
 *
 * @param this Puntero a una venta
 * @param mes int mes a setear
 * @return int 0 si pudo, -1 si ocurrio un problema
 */
int venta_setMes(Venta *this, int mes)
{
	int todoOk = -1;

	if (this != NULL && mes > 0 && mes <= 12)
	{
		this->fecha.mes = mes;
		todoOk = 0;
	}

	return todoOk;
}

/**
 * @fn int venta_getMes(Venta*, int*)
 * @brief Funcion que obtiene el mes en una venta
 *
 * @param this Puntero a una venta
 * @param mes int mes a obtener
 * @return int 0 si pudo, -1 si ocurrio un problema
 */
int venta_getMes(Venta *this, int *mes)
{
	int todoOk = -1;

	if (this != NULL && mes != NULL)
	{
		*mes = this->fecha.mes;
		todoOk = 0;
	}

	return todoOk;
}

/**
 * @fn int venta_setAnio(Venta*, int)
 * @brief Funcion que setea el anio en una venta
 *
 * @param this Puntero a una venta
 * @param anio int anio a setear
 * @return int 0 si pudo, -1 si ocurrio un problema
 */
int venta_setAnio(Venta *this, int anio)
{
	int todoOk = -1;

	if (this != NULL && anio >= 1950 && anio <= 2022)
	{
		this->fecha.anio = anio;
		todoOk = 0;
	}

	return todoOk;
}

/**
 * @fn int venta_getAnio(Venta*, int*)
 * @brief Funcion que obtiene el anio en una venta
 *
 * @param this Puntero a una venta
 * @param anio int anio a obtener
 * @return int 0 si pudo, -1 si ocurrio un problema
 */
int venta_getAnio(Venta *this, int *anio)
{
	int todoOk = -1;

	if (this != NULL && anio != NULL)
	{
		*anio = this->fecha.anio;
		todoOk = 0;
	}

	return todoOk;
}

/**
 * @fn int venta_MostrarUnaVenta(Venta*)
 * @brief Funcion que muestra una venta
 *
 * @param this Puntero a una venta
 * @return int 0 si pudo, -1 si ocurrio un problema
 */
int venta_MostrarUnaVenta(Venta *this)
{
	int todoOk = -1, auxId, auxDia, auxMes, auxAnio, auxCantidad;
	float auxPrecio;
	char auxModeloAuto[100], auxTarjeta[30];

	if (this != NULL)
	{
		venta_getId(this, &auxId);
		venta_getCantidad(this, &auxCantidad);
		venta_getPrecioUnitario(this, &auxPrecio);
		venta_getDia(this, &auxDia);
		venta_getMes(this, &auxMes);
		venta_getAnio(this, &auxAnio);
		venta_getModeloAuto(this, auxModeloAuto);
		venta_getTarjetaCredito(this, auxTarjeta);

		printf("| %-5d | %.2d/%.2d/%-6d | %-22s | %-11d | $%-12.2f | %-20s|\n", auxId, auxDia, auxMes, auxAnio, auxModeloAuto, auxCantidad, auxPrecio,
				auxTarjeta);
		todoOk = 0;
	}
	return todoOk;
}

/**
 * @fn int venta_CriterioTotalVentas(void*)
 * @brief Funcion que acumula el total de las ventas
 *
 * @param this Puntero a void
 * @return int 0 si pudo, -1 si ocurrio un problema
 */
int venta_CriterioTotalVentas(void *this)
{
	int acumVentas = 0, auxCantidad;
	Venta *unaVenta;

	if (this != NULL)
	{
		unaVenta = (Venta*) this;

		venta_getCantidad(unaVenta, &auxCantidad);
		acumVentas = auxCantidad;
	}
	return acumVentas;
}

/**
 * @fn int venta_CriterioMayorDiezMil(void*)
 * @brief Funcion que cuenta las ventas mayores a diez mil $
 *
 * @param this Puntero a void
 * @return int 0 si pudo, -1 si ocurrio un problema
 */
int venta_CriterioMayorDiezMil(void *this)
{
	int todoOk = 0, auxCantidad;
	float auxPrecio, criterioMayor;
	Venta *unaVenta = NULL;

	if (this != NULL)
	{
		unaVenta = (Venta*) this;

		venta_getPrecioUnitario(unaVenta, &auxPrecio);
		venta_getCantidad(unaVenta, &auxCantidad);

		criterioMayor = auxCantidad * auxPrecio;
		if (criterioMayor > 10000)
		{
			todoOk = 1;
		}
	}

	return todoOk;
}

/**
 * @fn int venta_CriterioMayorVeinteMil(void*)
 * @brief Funcion que cuenta las ventas mayores a veinte mil $
 *
 * @param this Puntero a void
 * @return int 0 si pudo, -1 si ocurrio un problema
 */
int venta_CriterioMayorVeinteMil(void *this)
{
	int todoOk = 0, auxCantidad;
	float auxPrecio, maximo;
	Venta *unaVenta = NULL;

	if (this != NULL)
	{
		unaVenta = (Venta*) this;

		venta_getPrecioUnitario(unaVenta, &auxPrecio);
		venta_getCantidad(unaVenta, &auxCantidad);

		maximo = auxCantidad * auxPrecio;
		if (maximo > 20000)
		{
			todoOk = 1;
		}
	}

	return todoOk;
}

/**
 * @fn int venta_CriterioIgualFalcon(void*)
 * @brief Funcion que cuenta las ventas cuando el modelo es igual a falcon
 *
 * @param this Puntero a void
 * @return  int 0 si pudo, -1 si ocurrio un problema
 */
int venta_CriterioIgualFalcon(void *this)
{
	int acumIguales = 0, auxCantidad;
	char auxModeloAuto[] = "Falcon";

	Venta *unaVenta = NULL;

	if (this != NULL)
	{
		unaVenta = (Venta*) this;

		venta_getCantidad(unaVenta, &auxCantidad);
		venta_getModeloAuto(unaVenta, auxModeloAuto);

		if (strcmp(auxModeloAuto, "Falcon") == 0)
		{
			acumIguales = auxCantidad;
		}
	}
	return acumIguales;
}
