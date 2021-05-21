#ifndef HARCODEO_H_INCLUDED
#define HARCODEO_H_INCLUDED

#include "cliente.h"
#include "alquiler.h"
#include "juegos.h"


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


int harcodearAlquileres(eAlquileres alquileres[], int tamA, int cant, int* pId);

int harcodearJuegos(eJuego juegos[], int tamJ, int cant, int* pCodigo);
