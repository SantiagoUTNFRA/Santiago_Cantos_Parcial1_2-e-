#include "LinkedList.h"

int controller_cargarVentasDesdeTexto(char *path, LinkedList *pArrayListVenta);
int controller_listarVentas(LinkedList *pArrayListVenta);
int controller_agregarVenta(LinkedList *pArrayListVenta);
int controller_editarVenta(LinkedList *pArrayListVenta);
int controller_removerVenta(LinkedList *pArrayListVenta);
int controller_guardarVentasModoTexto(char *path, LinkedList *pArrayListVenta);
int controller_guardarVentasModoBinario(char *path, LinkedList *pArrayListVenta);
int controller_buscarVentaId(LinkedList *this, int id);
int controller_GenerarInforme(LinkedList *pArrayListVenta);

