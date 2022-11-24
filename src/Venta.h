#include "LinkedList.h"
#ifndef VENTA_H_
#define VENTA_H_

typedef struct
{
	int dia;
	int mes;
	int anio;
} Fecha;

typedef struct
{
	int idVenta;
	Fecha fecha;
	char modeloAuto[50];
	int cantidad;
	float precioUnitario;
	char tarjetaCredito[50];
} Venta;

#endif /* VENTA_H_ */

Venta* venta_new();

Venta* venta_newParametros(char *idStr, char *diaStr, char *mesStr, char *anioStr, char *modeloStr, char *cantidadStr, char *precioStr, char *tarjetaStr);

void venta_delete(Venta *this);

int venta_setId(Venta *this, int id);

int venta_getId(Venta *this, int *id);

int venta_setModeloAuto(Venta *this, char *modeloAuto);

int venta_getModeloAuto(Venta *this, char *modeloAuto);

int venta_setCantidad(Venta *this, int cantidad);

int venta_getCantidad(Venta *this, int *cantidad);

int venta_setPrecioUnitario(Venta *this, float precio);

int venta_getPrecioUnitario(Venta *this, float *precio);

int venta_setTarjetaCredito(Venta *this, char *tarjeta);

int venta_getTarjetaCredito(Venta *this, char *tarjeta);

int venta_setDia(Venta *this, int dia);

int venta_getDia(Venta *this, int *dia);

int venta_setMes(Venta *this, int mes);

int venta_getMes(Venta *this, int *mes);

int venta_setAnio(Venta *this, int anio);

int venta_getAnio(Venta *this, int *anio);

int venta_MostrarUnaVenta(Venta *this);

int venta_CriterioTotalVentas(void *this);

int venta_CriterioMayorDiezMil(void *this);

int venta_CriterioMayorVeinteMil(void *this);

int venta_CriterioIgualFalcon(void *this);
