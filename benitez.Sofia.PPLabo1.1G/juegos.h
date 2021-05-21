#ifndef JUEGOS_H_INCLUDED
#define JUEGOS_H_INCLUDED
#include "categoria.h"

//JUEGO
/*Código
• Descripción
• Importe
• idCategoria*/

typedef struct{

    int codigo;
    char descripcion[20];
    float importe;
    int idCategoria;
    int isEmpty;
}eJuego;

#endif // JUEGOS_H_INCLUDED

/** \brief imprime los datos de una estructura del tipo eJuego
 *
 * \param unJuego eJuego    estructura a mostrar
 * \param tamC int          tamanio del array categorias
 * \param categorias[] eCategoria           array categorias para poder cargar su descripcion
 * \return void
 *
 */
void mostrarJuego(eJuego unJuego, int tamC, eCategoria categorias[]);


/** \brief    imprime un array de estructura eJuego
 *
 * \param juegos[] eJuego               array que imprime
 * \param tamJ int                      tamanio del array
 * \param categorias[] eCategoria     array de categorias para poder mostrar sus descripciones
 * \param tamC int                     tamanio del array categorias
 * \return int                         devuelve 1 si pudo imprimir correctamente
 *
 */
int mostrarJuegos(eJuego juegos[], int tamJ, eCategoria categorias[], int tamC);



/** \brief    carga las descripciones de los juegos en un array para poder utilizarlas en otras funciones
 *
 * \param codigo int                codigo del juego cuya descripcion se quiere mostrar
 * \param juegos[] eJuego           array a recorrer
 * \param tamJ int                  tamanio del array
 * \param descripcion[] char        array de descripcion para cargar la descripcion del juego
 * \return int                      devuelve 1 si funciona correctamente, 0 sino
 *
 */
int cargarDescripcionJuegos(int codigo, eJuego juegos[], int tamJ, char descripcion[]);

int inicializarJuegos(eJuego juegos[], int tamJ);

int buscarLibreJuego(eJuego juegos[], int tamJ);

int altaJuegos(eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat, int*pCodigoJuego);

int cargarImporteJuegos(int codigo, eJuego juegos[], int tamJ, float* importe);///puntero a descripcion para usarla en otra funcion
