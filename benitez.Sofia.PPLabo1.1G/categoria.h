#ifndef CATEGORIA_H_INCLUDED
#define CATEGORIA_H_INCLUDED


/*Categoria:
• id
• Descripción (máximo 51 caracteres) (mesa, azar, estrategia, salón, magia)
*/

typedef struct{

    int id;
    char descripcion[51];

}eCategoria;

#endif // CATEGORIA_H_INCLUDED



/** \brief imprime un elemento del tipo estructura eCategoria
 *
 * \param unaCategoria eCategoria    elemento a imprimir
 * \return void
 *
 */
void mostrarCategoria(eCategoria unaCategoria);


/** \brief recorre un array de estructuras eCategoria y las imprime llamando a la funcion mostrarCategoria();
 *
 * \param categorias[] eCategoria    array
 * \param tamCat int    tamanio del array
 * \return int   devuleve 1 si se imprimen correctamente
 *
 */
int mostrarCategorias(eCategoria categorias[], int tamCat);


/** \brief carga la descripcion de una categoria en un puntero descripcion para ser utilizado en otra funcion
 *
 * \param id int    id de la categoria que sera cargada
 * \param categorias[] eCategoria
 * \param tamCat int
 * \param descripcion[] char        puntero a la dir de memoria del descripcion para utilizarla en otra funcion
 * \return int                   devuelve 1 si la descripcion es cargada correctamente y 0 sino
 *
 */
int cargarDescripcionCategorias(int id, eCategoria categorias[], int tamCat, char descripcion[]);
