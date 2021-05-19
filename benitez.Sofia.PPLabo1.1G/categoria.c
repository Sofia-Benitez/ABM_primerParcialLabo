#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "categoria.h"
#include "juegos.h"
#include "utn.h"



///mostrar categorias

void mostrarCategoria(eCategoria unaCategoria)
{
    printf("     %d     %10s\n", unaCategoria.id, unaCategoria.descripcion);

}


int mostrarCategorias(eCategoria categorias[], int tamCat)
{
    int todoOk=0;
    if(categorias!=NULL && tamCat>0)
    {
        printf("Categorias de juegos\n\n");
        printf("     ID      Descripcion\n");

        for(int i=0; i<tamCat; i++)
        {
            mostrarCategoria(categorias[i]);
        }
        printf("\n\n");

        todoOk=1;
    }
    return todoOk;
}

int cargarDescripcionCategorias(int id, eCategoria categorias[], int tamCat, char descripcion[])///puntero a descripcion para usarla en otra funcion
{
    int todoOk=0;

    if(id>=500 &&  id<=504 && categorias!=NULL && tamCat>0 && descripcion!=NULL)
    {
        for(int i=0; i<tamCat; i++)
        {
            if(categorias[i].id==id)
            {
                strcpy(descripcion, categorias[i].descripcion);///cargo la cadena que me pasan en la funcion
                todoOk=1;
                break;///ya consegui la descripcion correspondiente
            }
        }
    }

    return todoOk;
}


