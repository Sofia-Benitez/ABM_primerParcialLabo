#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cliente.h"
#include "categoria.h"
#include "alquiler.h"
#include "juegos.h"
#include "utn.h"
#include "harcodeo.h"

#define TAMC 1000
#define TAMA 100
#define TAM_CAT 5
#define TAMJ 10

int main()
{
    int opcionMenuPrincipal;
    char seguir = 's';
    int nextCodigo=100;//arranca de este valor
    int nextIdAlquiler=5000;

    eCliente clientes[TAMC];

    //inicializar clientes
    inicializarClientes(clientes, TAMC);

    harcodearClientes(clientes, TAMC, 10, &nextCodigo);

    eAlquileres alquileres[TAMA];

    //inicializar alquileres
    inicializarAlquileres(alquileres, TAMA);


    eJuego juegos[TAMJ] = {
        {1, "TEG", 1000, 502},
        {2, "Ruleta", 2000, 501},
        {3, "LIFE", 5000, 500},
        {4, "varita", 600, 504},
        {5, "pool", 8000, 503},
        {6, "metegol", 8000, 503},
        {7, "dados", 100, 500},
        {8, "cartas", 200, 500},
        {9, "kit de magia", 1000, 504},
        {10, "pictionary", 2000, 500}
        };

    eCategoria categorias[TAM_CAT] = {
        {500, "Mesa"},
        {501, "Azar"},
        {502, "Estrategia"},
        {503, "Salon"},
        {504, "Magia"}
        };



    while(seguir=='s')
    {
        menu();
        utn_getNumero(&opcionMenuPrincipal, "Ingrese una opcion: ", "Error. Opcion invalida.\n", 1, 20, 3);
        switch(opcionMenuPrincipal)
        {
            case 1:
                //alta
                if(altaCliente(clientes, TAMC, &nextCodigo))
                {
                    printf("Alta exitosa\n");
                }
                else
                {
                    printf("Hubo un problema al dar de alta");
                }
                break;
            case 2:
                //baja
                    if(bajaCliente(clientes, TAMC))
                    {
                        printf("Baja exitosa\n");
                    }
                    else
                    {
                        printf("Hubo un problema al dar de baja\n");
                    }
                break;
            case 3:
                //modificacion
                printf("modificar empleado");
                if(modificarCliente(clientes, TAMC))
                {
                    printf("Modificacion exitosa\n");
                }
                else
                {
                    printf("Hubo un problema al modificar el cliente\n");
                }
                break;
            case 4:
                //listar
                ordenarClientes(clientes, TAMC, 1);
                mostrarClientes(clientes, TAMC);
                break;
            case 5:
                ///nuevo alquiler
                altaAlquiler(alquileres, TAMA, clientes, TAMC, categorias, TAM_CAT, juegos, TAMJ, &nextIdAlquiler);
                break;
            case 6:
                ///listar alquileres
                mostrarAlquileres(alquileres, TAMA, clientes, TAMC, categorias, TAM_CAT, juegos, TAMJ);
                break;
            case 7:
                if(bajaAlquiler(alquileres, TAMA, clientes, TAMC, juegos, TAMJ, categorias, TAM_CAT))
                {
                    printf("Cancelacion realizada con exito.\n");
                }
                else
                {
                    printf("Hubo un problema al cancelar el alquiler\n");
                }
                break;
            case 8:
                mostrarJuegos(juegos, TAMJ, categorias, TAM_CAT);

                break;
            case 20:
            seguir='n';
            //salir, desea salir?
            break;
        }

        printf("Desea seleccionar otra opcion?: ");
        fflush(stdin);
        scanf("%c", &seguir);

        system("pause");

        }



    return 0;
}



