#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "informes.h"
#include "alquiler.h"
#include "utn.h"

void menuInformes(void)
{
    system("cls");

    printf("Informes\n");
    printf("1. Alquileres por cliente\n");
    printf("2. Cliente con mas alquileres\n");
    printf("3. gasto por cliente\n");
    printf("4. juego mas alquilado\n");
    printf("5.categoria con mas juegos\n");
    printf("6. actualizar precio por categoria\n");
    printf("7. categoria preferida cliente\n");
}

int mostrarAlquileresPorCliente(eAlquileres alquileres[], int tamA, eCliente lista[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat)
{
    int todoOk=0;
    int codigoCliente;

    if(alquileres!=NULL && tamA>0 && lista!=NULL && tam>0 && juegos!=NULL && tamJ>0 && categorias!=NULL && tamCat>0)
    {
        printf("\nAlquileres por cliente\n");
        mostrarClientes(lista, tam);

        utn_getNumero(&codigoCliente, "Seleccione el codigo del cliente: ", "Error.\n", 100,1100,3);
        while(buscarCliente(lista, tam, codigoCliente)==-1)
        {
             utn_getNumero(&codigoCliente, "Codigo invalido. Seleccione el codigo del cliente: ", "Error.\n", 100,1100,3);
        }

        for(int i=0; i<tamA; i++)
        {
            if(codigoCliente==alquileres[i].codigoCliente)
            {
                mostrarAlquiler(alquileres[i], tamA, lista, tam, categorias, tamCat, juegos, tamJ);
                todoOk=1;
            }
        }

        return todoOk;
    }




}

int clientesMasAlquileres(eAlquileres alquileres[], int tamA, eCliente lista[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat)
{
    int todoOk=0;
    int contadorAlquileres[tam];///alquileres por empleados
    int mayor;
    int flag=1;

    for(int i=0; i<tam; i++)///inicializo los contadores de cada empleado
    {
        contadorAlquileres[i]=0;
    }

    if(alquileres!=NULL && tamA>0 && lista!=NULL && tam>0 && juegos!=NULL && tamJ>0 && categorias!=NULL && tamCat>0)
    {
            for(int i=0; i<tam; i++)///recorro clientes
            {
                for(int j=0; j<tamA; j++)///recorro alquileres
                {
                    if(alquileres[j].isEmpty==0 && alquileres[j].codigoCliente==lista[i].codigo)///si el codigo de cliente del alquiler coincide con el codigo del cliente que recorro
                    {
                        contadorAlquileres[i]++;
                        todoOk=1;
                    }
                }
            }

      for(int i=0; i<tam; i++)
      {
          if(flag || contadorAlquileres[i]>mayor)
          {
              mayor=contadorAlquileres[i];
              flag=0;
          }
      }

      for(int i=0; i<tam; i++)
      {
          if(contadorAlquileres[i]==mayor)
          {
              printf("%s\n", lista[i].nombre);
          }

      }


    }

    return todoOk;
}

void gastoCliente(eAlquileres alquileres[], int tamA, eCliente lista[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat)
{
    float gastoCliente=0;///acumulador
    int codigo;
    int flag=0;

    mostrarClientes(lista, tam);
    utn_getNumero(&codigo, "Ingrese el codigo del empleado: ", "Error\n", 100, 1100, 3);


        for(int j=0; j<tamA; j++)
        {
            if(alquileres[j].codigoCliente==codigo && alquileres[j].isEmpty==0)
            {
                for(int i=0; i<tamJ; i++)
                {
                    if(juegos[i].codigo==alquileres[j].codigoJuego)///busco el juego que alquilo el cliente
                    {
                        gastoCliente+=juegos[i].importe;
                        flag=1;
                    }
                }
            }
        }

    if(!flag)
    {
        printf("No hay alquileres de ese cliente\n");
    }
    else
    {
        printf("El total de gastos del cliente %d es %.2f: ", codigo, gastoCliente);
    }

}

void juegoMasAlquilado(eAlquileres alquileres[], int tamA, eCliente lista[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat)
{
    int contadorJuego[tamJ];//contador por cada juego para ver cual es el mas alquilado
    int mayor;
    int flag=1;

    for(int i=0; i<tamJ;i++)//inicializo contadores
    {
        contadorJuego[i]=0;
    }

    for(int i=0; i<tamJ;i++)
    {
        for(int j=0; j<tamA; j++)
        {
            if(alquileres[j].isEmpty==0 && alquileres[j].codigoJuego==juegos[i].codigo)
            {
                (contadorJuego[i])++;
            }
        }
    }

    for(int i=0; i<tamJ;i++)
    {
        if(flag || contadorJuego[i]>mayor)
        {
            mayor=contadorJuego[i];
            flag=0;
        }
    }
    printf("Juegos mas alquilados: \n");
    for(int i=0; i<tamJ;i++)
    {
        if(contadorJuego[i]==mayor)
        {
            printf("%s\n", juegos[i].descripcion);
        }
    }

}

void categoriaMasJuegos(eAlquileres alquileres[], int tamA, eCliente lista[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat)
{
    int contador[tamCat];
    int mayor;
    int flag=1;

    for(int i=0; i<tamCat;i++)//inicializo contadores
    {
        contador[i]=0;
    }

    for(int i=0; i<tamCat;i++)
    {
        for(int j=0; j<tamJ; j++)
        {
            if(juegos[j].idCategoria==categorias[i].id)
            {
                (contador[i])++;
            }
        }
    }

    for(int i=0; i<tamCat;i++)
    {
        if(flag || contador[i]>mayor)
        {
            mayor=contador[i];
            flag=0;
        }
    }
    printf("Categorias con mas juegos: \n");
    for(int i=0; i<tamCat;i++)
    {
        if(contador[i]==mayor)
        {
            printf("%s\n", categorias[i].descripcion);
        }
    }
}

void actualizarPrecioPorCategoria(eAlquileres alquileres[], int tamA, eCliente lista[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat)
{
    float precio;
    float nuevoPrecio;
    int categoria;
    int porcentajeDescuento;

    mostrarCategorias(categorias, tamCat);
    printf("Seleccione la categoria: ");
    scanf("%d", &categoria);

    printf("Ingrese el porcentaje de descuento: ");
    scanf("%d", &porcentajeDescuento);

    for(int i=0; i<tamJ; i++)
    {
        if(juegos[i].idCategoria==categoria)
        {
            precio=juegos[i].importe;
            nuevoPrecio=  precio- precio * porcentajeDescuento/100;
            juegos[i].importe=nuevoPrecio;
        }
    }

    printf("Precios actualizados\n");
    for(int i=0; i<tamJ; i++)
    {
        if(juegos[i].idCategoria==categoria)
        {
            mostrarJuego(juegos[i], tamCat, categorias);
        }
    }
}

void categoriaPreferidaCliente(eAlquileres alquileres[], int tamA, eCliente lista[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat)
{
    int contadorCat[tamCat]; ///contador por categoria para ver cual es la mas elegida por un cliente
    int codigo;
    int mayor;
    int flag=1;

    for(int i=0; i<tamCat;i++)//inicializo contadores
    {
        contadorCat[i]=0;
    }


    mostrarClientes(lista, tam);
    utn_getNumero(&codigo, "Ingrese el codigo del empleado: ", "Error\n", 100, 1100, 3);

    for(int i=0; i<tamA; i++)///recorro los alquileres
    {
        if(alquileres[i].codigoCliente==codigo)//alquileres del empleado
        {
            for(int j=0; j<tamJ; j++)//recorro los juegos
            {
                if(alquileres[i].codigoJuego==juegos[j].codigo)//encuentro el juego que alquilo
                {
                    for(int k=0; k<tamCat; k++)//recorro las categorias
                    {
                        if(juegos[j].idCategoria==categorias[k].id)//busco la categoria del juego que alquilo
                        {
                            contadorCat[k]++;
                        }
                    }
                }
            }
        }
    }

    for(int i=0; i<tamCat;i++)
    {
        if(flag || contadorCat[i]>mayor)
        {
            mayor=contadorCat[i];
            flag=0;
        }
    }
    printf("Categorias preferidas del cliente: \n");
    for(int i=0; i<tamCat;i++)
    {
        if(contadorCat[i]==mayor)
        {
            printf("%s\n", categorias[i].descripcion);
        }
    }
}
