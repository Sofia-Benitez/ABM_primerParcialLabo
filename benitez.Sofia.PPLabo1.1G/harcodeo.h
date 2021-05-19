#ifndef HARCODEO_H_INCLUDED
#define HARCODEO_H_INCLUDED

#include "cliente.h"


#endif // HARCODEO_H_INCLUDED


/** \brief  carga en el array clientes una serie de datos de un datawarehouse
 *
 * \param lista[] eCliente     array del tipo eCliente donde se cargan los datos
 * \param tam int               tamanio del array
 * \param cant int              cantidad de estructuras a cargar
 * \param pCodigo int*          puntero al codigo del cliente
 * \return int                  devuelve la cantidad de estructuras que se cargaron correctamente
 *
 */
int harcodearClientes(eCliente lista[], int tam, int cant, int* pCodigo);
