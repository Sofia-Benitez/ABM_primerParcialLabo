#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alquiler.h"
#include "cliente.h"
#include "utn.h"
#include "juegos.h"

void menuAlquileres(void)
{
    system("cls");

    printf("ALQUILERES\n");
    printf("1. Alta \n");
    printf("2. Baja\n");
    printf("3. Listar\n");
    printf("4. --------\n");
    printf("5. ---------- \n");
    printf("10. Salir\n");
}

int inicializarAlquileres(eAlquileres alquileres[], int tamA)
{

    int todoOk=0;
    if(alquileres!=NULL && tamA>0)
    {
        for(int i=0; i<tamA; i++)//recorro el array para inicializar
        {
            alquileres[i].isEmpty= 1;
        }
        todoOk=1;
    }


    return todoOk;
}

int buscarLibreAlquileres(eAlquileres alquileres[], int tamA)
{
    int indice=-1;

    if(alquileres!=NULL && tamA>0)
    {
        for(int i=0; i<tamA; i++)
        {
            if(alquileres[i].isEmpty)//si es 1
            {
                indice=i;
                break;
            }
        }

    }

    return indice;
}

int altaAlquiler(eAlquileres alquileres[], int tamA, eCliente lista[], int tam, eCategoria categorias[], int tamCat, eJuego juegos[], int tamJ, int* pIdAlquiler)
{
    int todoOk=0;
    int indice;


    eAlquileres nuevoAlquiler;  ///auxiliar


    if(alquileres!=NULL && tamA>0 && pIdAlquiler!=NULL && lista!=NULL && tam>0 && categorias!=NULL && tamCat>0 && juegos!=NULL && tamJ>0)
    {
        system("cls");
        printf("Alta alquiler\n\n");
        printf("ID alquiler: %d\n", *pIdAlquiler);
        indice=buscarLibreAlquileres(alquileres, tamA);///busco el lugar donde se realiza la alta
        if(indice==-1)
        {
            printf("No hay disponibilidad para mas alquileres \n");
        }
        else
        {

            nuevoAlquiler.codigoAlquiler= *pIdAlquiler; ///traigo el id

            mostrarClientes(lista, tam);
            utn_getNumero(&nuevoAlquiler.codigoCliente, "Ingrese el codigo del cliente que alquila: ", "Error, codigo incorrecto. \n", 100, 1100, 3);
            while(buscarCliente(lista, tam, nuevoAlquiler.codigoCliente)==-1)
            {
                utn_getNumero(&nuevoAlquiler.codigoCliente, "Cliente invalido. Ingrese el codigo del cliente que alquila: ", "Error, codigo incorrecto. \n", 100, 1100, 3);
            }

            mostrarJuegos(juegos, tamJ, categorias, tamCat);
            utn_getNumero(&nuevoAlquiler.codigoJuego, "Ingrese el codigo del juego: ", "Error, codigo incorrecto. \n", 1, 15, 3);


            printf("Ingrese fecha de alquiler dd/mm/aaaa: ");
            scanf("%d/%d/%d", &nuevoAlquiler.fechaAlquiler.dia, &nuevoAlquiler.fechaAlquiler.mes, &nuevoAlquiler.fechaAlquiler.anio);


            nuevoAlquiler.isEmpty=0;

            alquileres[indice]=nuevoAlquiler;///copio los valores del nuevo auxiliar a la estructura en el indice vacio

            ///actualizo el proximo id
            *pIdAlquiler=(*pIdAlquiler)+1;


             todoOk=1;
        }

    }

    return todoOk;
}



void mostrarAlquiler(eAlquileres unAlquiler, int tamA, eCliente lista[], int tam, eCategoria categorias[], int tamCat, eJuego juegos[], int tamJ)
{
    char descripcion[20];//del juego
    char nombre[20];//del cliente
    float importe;

    if(cargarNombreCliente(unAlquiler.codigoCliente, lista, tam, nombre)
        && cargarDescripcionJuegos(unAlquiler.codigoJuego, juegos, tamJ, descripcion)
       && cargarImporteJuegos(unAlquiler.codigoJuego, juegos, tamJ, &importe))
    {


        printf("%d        %10s          %10s       %.2f      %02d/%02d/%02d\n",
           unAlquiler.codigoAlquiler,
           nombre,
           descripcion,
           importe,
           unAlquiler.fechaAlquiler.dia,
           unAlquiler.fechaAlquiler.mes,
           unAlquiler.fechaAlquiler.anio);

    }

    else
    {
       printf("Hubo un problema al mostrar el alquiler \n");
    }



}

int mostrarAlquileres(eAlquileres alquileres[], int tamA, eCliente lista[], int tam, eCategoria categorias[], int tamCat, eJuego juegos[], int tamJ)
{
    int flag=1;
    int todoOk=0;

    if(alquileres!=NULL && tamA>0)
    {
        printf("\n                      ******Lista alquileres******\n");
        printf("Codigo           Cliente            Juego        Importe         Fecha      \n");

        for(int i=0; i<tamA; i++)
        {
            if(alquileres[i].isEmpty==0)///muestra los que estan en el indice que estan ocupados
            {
                mostrarAlquiler(alquileres[i], tamA, lista, tam, categorias, tamCat, juegos, tamJ);//llamo a la funcion que muestra un almuerzo
                flag=0;
            }
        }
        if(flag)
        {
            printf("No hay alquileres realizados");
        }
        printf("\n\n");

        todoOk=1;
    }

    return todoOk;
}
int buscarAlquiler(eAlquileres alquileres[], int tamA, int codigoAlquiler)
{
    int indice=-1;///si no lo encunetra devuelve -1 que es imposible como indice

    if(alquileres!=NULL && tamA>0)
    {
        for(int i=0; i<tamA; i++)
        {
            if(!alquileres[i].isEmpty && alquileres[i].codigoAlquiler == codigoAlquiler)//si no es 1, es decir si esta ocupado && si el indice es igual al legajo que me pasan
            {
                indice=i;///guardo en la variable indice le indice de la estructura que coincide
                break;///si no rompe me devuelve el indice de la ultima estructura vacia y yo necesito el primero.
            }
        }
    }

    return indice;

}


int bajaAlquiler(eAlquileres alquileres[], int tamA, eCliente lista[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat)
{
    int todoOk=0;
    int indice;//para guardar la ubicacion
    int codigo;
    char confirma;

    system("cls");
    printf("                Cancelacion de alquileres     \n");

    mostrarAlquileres(alquileres, tamA, lista, tam, categorias, tamCat, juegos, tamJ);

    utn_getNumero(&codigo, "Ingrese el codigo del alquiler que desea dar de baja: ", "Error, codigo invalido. \n", 5000, 6000, 3);

    indice=buscarAlquiler(alquileres, tamA, codigo);

    if(indice==-1)
    {
        printf("No existe un alquiler con el codigo %d", codigo);
    }
    else
    {
        mostrarAlquiler(alquileres[indice], tamA, lista, tam, categorias, tamCat, juegos, tamJ);

        printf("Confirma la cancelacion del alquiler %d?: ", codigo);
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma=='s')
        {
            alquileres[indice].isEmpty=1;
            todoOk=1;
        }
        else
        {
            printf("Baja cancelada por el usuario\n");
        }

    }
    return todoOk;
}

int bajaAlquilerDelCliente(eAlquileres alquileres[], int tamA, eCliente lista[], int tam)
{
    int codigoCliente;
    char respuesta;
    int todoOk=0;

    if(alquileres!=NULL && tamA>0 && lista!=NULL && tam>0)
    {
        printf("Desea cancelar los alquileres de un cliente dado de baja?: ");
        fflush(stdin);
        scanf("%c", &respuesta);


        if(respuesta=='s')
        {
            printf("\n Clientes dados de baja\n");
            mostrarClientesDeBaja(lista, tam);
            utn_getNumero(&codigoCliente, "Ingrese el codigo del cliente: ", "Error\n", 100, 1100, 3);

            for(int i=0; i<tamA; i++)
            {
                if(alquileres[i].codigoCliente==codigoCliente)
                {
                    alquileres[i].isEmpty==1;
                }
            }
            printf("Alquileres del cliente codigo %d cancelados\n", codigoCliente);
        }
        else
        {
            printf("No se daran de baja los alquileres del cliente codigo %d\n", codigoCliente);
        }

        todoOk=1;
    }


    return todoOk;
}

