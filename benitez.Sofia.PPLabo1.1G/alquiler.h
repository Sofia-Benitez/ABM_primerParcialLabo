#ifndef ALQUILER_H_INCLUDED
#define ALQUILER_H_INCLUDED

#include "cliente.h"
#include "categoria.h"
#include "juegos.h"

typedef struct{

    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct{

    int codigoAlquiler;
    int codigoJuego;
    int codigoCliente;
    eFecha fechaAlquiler;
    int isEmpty;

}eAlquileres;

#endif // ALQUILER_H_INCLUDED


/** \brief asigna un 1 en el campo isEmpty a todos los alquileres indicando que estan vacios
 *
 * \param alquileres[] eAlquileres     array que recorre
 * \param tamA int                     tamanio del array
 * \return int                         devuelve 1 si se ejecuto correctamente y 0 sino
 *
 */
int inicializarAlquileres(eAlquileres alquileres[], int tamA);


/** \brief busca el primer alquiler libre, que tenga isEmpty=1.
 *
 * \param alquileres[] eAlquileres    array que recorre
 * \param tamA int                      tamanio del array
 * \return int   devuelve el indice del alquiler libre
 *
 */
int buscarLibreAlquileres(eAlquileres alquileres[], int tamA);

/** \brief permite ingresar un nuevo alquiler. Lo almacena en el indice que devuelve buscarLibreAlquileres y luego de cargar los datos cambia su estado de isEmpty a 0 para ocuparlo
 *
 * \param alquileres[] eAlquileres    array que recorre para cargar un nuevo alquiler
 * \param tamA int                    tamanio del array
 * \param lista[] eCliente            array de clientes para poder mostrarlos
 * \param tam int                      tamanio del array clientes
 * \param categorias[] eCategoria       array categorias para poder mostrar su descripcion
 * \param tamC int                      tamanio del array
 * \param juegos[] eJuego               array juegos para poder mostrarlos
 * \param tamJ int                      tamanio del array juegos
 * \param pIdAlquiler int*              puntero al codigo del alquiler (autoincremental)
 * \return int                          devuelve 1 si se realizo el alta correctamente y 0 sino
 *
 */
int altaAlquiler(eAlquileres alquileres[], int tamA, eCliente lista[], int tam, eCategoria categorias[], int tamC, eJuego juegos[], int tamJ, int* pIdAlquiler);


/** \brief imprime un alquiler, utiliza la descripcion de categorias y el nombre del cliente
 *
 * \param unAlquiler eAlquileres    alquiler del tipo eAlquileres a mostrar
 * \param tamA int                   tamanio del array
 * \param lista[] eCliente           array de clientes para poder obtener su descripcion
 * \param tam int                       tamanio del array cliente
 * \param categorias[] eCategoria       array categorias para obtener la descripcion
 * \param tamC int                      tamanio del array categorias
 * \param juegos[] eJuego               array juegos para poder cargar su descripcion
 * \param tamJ int                      tamanio del array juegos
 * \return void
 *
 */
void mostrarAlquiler(eAlquileres unAlquiler, int tamA, eCliente lista[], int tam, eCategoria categorias[], int tamC, eJuego juegos[], int tamJ);


/** \brief imprime todas las estructuras del tipo eAlquileres que no estan vacias, llamando a la funcion mostrarAlquiler();
 *
 * \param unAlquiler eAlquileres    array a mostrar
 * \param tamA int                   tamanio del array
 * \param lista[] eCliente           array de clientes para poder obtener su descripcion
 * \param tam int                       tamanio del array cliente
 * \param categorias[] eCategoria       array categorias para obtener la descripcion
 * \param tamC int                      tamanio del array categorias
 * \param juegos[] eJuego               array juegos para poder cargar su descripcion
 * \param tamJ int                      tamanio del array juegos
 * \return int
 *
 */
int mostrarAlquileres(eAlquileres alquileres[], int tamA, eCliente lista[], int tam, eCategoria categorias[], int tamC, eJuego juegos[], int tamJ);


/** \brief busca el indice de un alquiler segun el codigo que se pasa por parametro
 *
 * \param alquileres[] eAlquileres      array que recorre
 * \param tamA int                         tamanio del array
 * \param codigoAlquiler int                codigo del alquiler que se quiere buscar
 * \return int                              indice del alquiler que se paso por parametros
 *
 */
int buscarAlquiler(eAlquileres alquileres[], int tamA, int codigoAlquiler);


/** \brief da la baja logica de los alquileres pasando isEmpty a 1
 *
 * \param alquileres[] eAlquileres    array que recorre
 * \param tamA int                      tamanio del array
 * \param lista[] eCliente              array de clientes para mostrarlos
 * \param tam int                       tamanio del array
 * \param juegos[] eJuego               array de juegos para mostrarlos
 * \param tamJ int                      tamanio del array
 * \param categorias[] eCategoria        array de categorias para mostrar sus descripciones
 * \param tamCat int                      tamanio del array
 * \return int                             devuelve 1 si se ejecuto correctamente y 0 sino
 *
 */
int bajaAlquiler(eAlquileres alquileres[], int tamA, eCliente lista[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat);
