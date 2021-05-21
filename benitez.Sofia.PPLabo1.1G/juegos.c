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

    if(juegos!=NULL &&tamJ>0 && categorias!=NULL &&tamC>0)
    {
        printf("\n                   ******Lista de juegos******    \n");
        printf("Codigo             Descripcion            Importe              Categoria \n");

        for(int i=0; i<tamJ; i++)
        {
            if(juegos[i].isEmpty==0)
            {
                mostrarJuego(juegos[i], tamC, categorias);
            }

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

int inicializarJuegos(eJuego juegos[], int tamJ)
{

    int todoOk=0;
    if(juegos!=NULL && tamJ>0)
    {
        for(int i=0; i<tamJ; i++)//recorro el array para inicializar
        {
            juegos[i].isEmpty= 1;
        }
        todoOk=1;
    }


    return todoOk;
}

int buscarLibreJuego(eJuego juegos[], int tamJ)
{
    int indice=-1;

    if(juegos!=NULL && tamJ>0)
    {
        for(int i=0; i<tamJ; i++)
        {
            if(juegos[i].isEmpty)//si es 1
            {
                indice=i;
                break;
            }
        }

    }

    return indice;
}

int altaJuegos(eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat, int*pCodigoJuego)
{
    int todoOk=0;
    int indice;

    eJuego nuevoJuego;  ///auxiliar


    if(juegos!=NULL && tamJ>0 && pCodigoJuego!=NULL)
    {
        system("cls");
        printf("Alta de juego\n\n");
        printf("Codigo: %d\n", *pCodigoJuego);
        indice=buscarLibreJuego(juegos, tamJ);
        if(indice==-1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {

            nuevoJuego.codigo= *pCodigoJuego; ///traigo el codigo

            utn_getStringLetras(nuevoJuego.descripcion, "Ingrese la descripcion del juego: ", "Error, descripcion incorrecta.\n", 3);

            utn_getNumeroFloat(&nuevoJuego.importe, "Ingrese el importe: ", "Error.\n", 1, 9000000, 3);

            mostrarCategorias(categorias, tamCat);

            utn_getNumero(&nuevoJuego.idCategoria, "Ingrese la categoria del juego: ", "Error, categoria incorrecta.\n", 500, 600, 3);

            nuevoJuego.isEmpty=0;///ahora es una estructura cargada

            juegos[indice]=nuevoJuego;

            ///actualizo el proximo cod
            *pCodigoJuego=(*pCodigoJuego)+1;


             todoOk=1;
        }

    }

    return todoOk;
}

int cargarImporteJuegos(int codigo, eJuego juegos[], int tamJ, float* importe)///puntero a importe para usarla en otra funcion
{
    int todoOk=0;

    if(codigo>=1 &&  codigo<=20 && juegos!=NULL && tamJ>0)
    {
        for(int i=0; i<tamJ; i++)
        {
            if(juegos[i].codigo==codigo)
            {
                *importe=juegos[i].importe;///guardo el importe en la direccion de memoria del puntero
                todoOk=1;
                break;
            }
        }
    }

    return todoOk;
}
