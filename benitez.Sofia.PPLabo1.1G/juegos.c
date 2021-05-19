#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "juegos.h"
#include "categoria.h"
#include "alquiler.h"
#include "utn.h"



void mostrarJuego(eJuego unJuego, int tamC, eCategoria categorias[])
{
    char descripcion[20];
    cargarDescripcionCategorias(unJuego.idCategoria, categorias, tamC, descripcion);
    printf("%d        %15s                 %.2f           %15s  \n", unJuego.codigo, unJuego.descripcion, unJuego.importe, descripcion);

}


int mostrarJuegos(eJuego juegos[], int tamJ, eCategoria categorias[], int tamC)
{
    int todoOk=0;

    printf("\n                   ******Lista de juegos******    \n");
    printf("Codigo             Descripcion            Importe              Categoria \n");

    if(juegos!=NULL &&tamJ>0 && categorias!=NULL &&tamC>0)
    {
        for(int i=0; i<tamJ; i++)
        {
            mostrarJuego(juegos[i], tamC, categorias);
        }
        todoOk=1;
    }


    return todoOk;
}

int cargarDescripcionJuegos(int codigo, eJuego juegos[], int tamJ, char descripcion[])///puntero a descripcion para usarla en otra funcion
{
    int todoOk=0;

    if(codigo>=1 &&  codigo<=10 && descripcion!=NULL && juegos!=NULL && tamJ>0)
    {
        for(int i=0; i<tamJ; i++)
        {
            if(juegos[i].codigo==codigo)
            {
                strcpy(descripcion, juegos[i].descripcion);///cargo la cadena que me pasan en la funcion
                todoOk=1;
                break;///ya consegui la descripcion correspondiente
            }
        }
    }

    return todoOk;
}
