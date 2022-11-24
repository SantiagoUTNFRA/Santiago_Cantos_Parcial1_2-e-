#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "parser.h"
#include "inputs.h"
#include "Venta.h"

int main()
{
	setbuf(stdout, NULL);

	char seguir = 's';

	LinkedList *listaVentas = ll_newLinkedList();

	do
	{
		switch (menu())
		{
			case 1: //CARGA DE ARCHIVOS
				if (controller_cargarVentasDesdeTexto("data.csv", listaVentas) != 0)
				{
					printf("\nHa ocurrido un error al cargar el archivo data.csv\n");
				}
				else
				{
					printf("\nArchivo data.csv cargado con exito\n");
				}
				break;
			case 2: //ALTA DE VENTA
				if (ll_len(listaVentas) > 0)
				{
					if (controller_agregarVenta(listaVentas) != 0)
					{
						printf("\nHa ocurrido un error al agregar una venta\n");
					}
					else
					{
						printf("\nVenta agregada con exito\n");
					}
				}
				else
				{
					printf("Primero cargue el archivo para agregar una venta\n");
				}

				break;
			case 3: //BAJA DE VENTA
				if (ll_len(listaVentas) > 0)
				{
					if (controller_removerVenta(listaVentas) != 0)
					{
						printf("\nHa ocurrido un error al remover la venta\n");
					}
					else
					{
						printf("\nVenta removida con exito\n");
					}
				}
				else
				{
					printf("Primero cargue el archivo para dar de baja una venta\n");
				}

				break;
			case 4: //MODIFICACION DE VENTA
				if (ll_len(listaVentas) > 0)
				{
					if (controller_editarVenta(listaVentas) != 0)
					{
						printf("\nHa ocurrido un error al editar la venta\n");
					}
					else
					{
						printf("\nVenta editada con exito\n");
					}
				}
				else
				{
					printf("Primero cargue el archivo para modificar la venta\n");
				}

				break;
			case 5: //GENERAR INFORME DE VENTAS
				if (ll_len(listaVentas) > 0)
				{
					if (controller_GenerarInforme(listaVentas) != 0)
					{
						printf("\nHa ocurrido un error al generar el informe de ventas\n");
					}
					else
					{
						printf("\nInforme de venta generado con exito\n");
					}
				}
				else
				{
					printf("Primero cargue el archivo para generar un informe\n");
				}

				break;
			case 6: //GUARDAR EN MODO TEXTO
				if (ll_len(listaVentas) > 0)
				{
					if (controller_guardarVentasModoTexto("data.csv", listaVentas) != 0)
					{
						printf("\nHa ocurrido un error al guardar el archivo data.csv\n");

					}
					else
					{
						printf("\nArchivo guardado en modo texto con exito\n");
					}
				}
				else
				{
					printf("Primero cargue el archivo para guardar el archivo\n");
				}

				break;
			case 7: //GUARDAR EN MODO BINARIO
				if (ll_len(listaVentas) > 0)
				{
					if (controller_guardarVentasModoBinario("data.bin", listaVentas) != 0)
					{
						printf("\nHa ocurrido un error al guardar el archivo data.bin\n");
					}
					else
					{
						printf("\nArchivo guardado en modo binario con exito\n");
					}
				}
				else
				{
					printf("Primero cargue el archivo para guardar el archivo\n");
				}

				break;
			case 8: //LISTAR VENTAS (PLUS YA QUE NO FUE PEDIDO)
				if (ll_len(listaVentas) > 0)
				{
					if (controller_listarVentas(listaVentas) != 0)
					{
						printf("\nHa ocurrido un error al listar las ventas\n");
					}
				}
				else
				{
					printf("Primero cargue el archivo para listar las ventas\n");
				}

				break;
			case 9: //SALIR
				seguir = 'n';
				printf("Adios, exitos!");
				break;
		}
	} while (seguir == 's');

	return 0;
}
