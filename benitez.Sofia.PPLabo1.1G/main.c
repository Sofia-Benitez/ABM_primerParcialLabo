#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cliente.h"
#include "categoria.h"
#include "alquiler.h"
#include "juegos.h"
#include "utn.h"
#include "informes.h"
#include "harcodeo.h"

#define TAMC 1000
#define TAMA 1000
#define TAM_CAT 5
#define TAMJ 50

int main()
{
    int opcionMenuPrincipal;
    int opcionInformes;
    int opcionClientes;
    int opcionAlquileres;
    char seguir = 's';
    int nextCodigo=100;//arranca de este valor
    int nextIdAlquiler=5000;
    int nextCodigoJuego=1;

    ///clientes
    eCliente clientes[TAMC];

    inicializarClientes(clientes, TAMC);

    harcodearClientes(clientes, TAMC, 10, &nextCodigo);

    ///alquileres
    eAlquileres alquileres[TAMA];

    inicializarAlquileres(alquileres, TAMA);

    harcodearAlquileres(alquileres, TAMA, 10, &nextIdAlquiler);

    ///juegos

    eJuego juegos[TAMJ];

    inicializarJuegos(juegos, TAMJ);

    harcodearJuegos(juegos, TAMJ, 10, &nextCodigoJuego);


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
            ///clientes
            menuClientes();
            utn_getNumero(&opcionClientes, "Ingrese una opcion: ", "Error. Opcion invalida.\n", 1, 20, 3);
            switch(opcionClientes)
            {
            case 1:
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
                    bajaAlquilerDelCliente(alquileres, TAMA, clientes, TAMC);
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
            }
            break;
        case 2:
            ///alquileres
            menuAlquileres();
            utn_getNumero(&opcionAlquileres, "Ingrese una opcion: ", "Error. Opcion invalida.\n", 1, 20, 3);
            switch(opcionAlquileres)
            {
            case 1:
                ///nuevo alquiler
                if(altaAlquiler(alquileres, TAMA, clientes, TAMC, categorias, TAM_CAT, juegos, TAMJ, &nextIdAlquiler))
                {
                    printf("Alta exitosa\n");
                }
                else
                {
                    printf("Hubo un problema al dar de alta\n");
                }
                break;

            case 2:
                //baja alquiler
                if(bajaAlquiler(alquileres, TAMA, clientes, TAMC, juegos, TAMJ, categorias, TAM_CAT))
                {
                    printf("Cancelacion realizada con exito.\n");
                }
                else
                {
                    printf("Hubo un problema al cancelar el alquiler\n");
                }
                break;
            case 3:
                ///listar alquileres
                mostrarAlquileres(alquileres, TAMA, clientes, TAMC, categorias, TAM_CAT, juegos, TAMJ);
                break;
            }//fin alquileres
            break;
        case 3:
            ///juegos
            mostrarJuegos(juegos, TAMJ, categorias, TAM_CAT);

            break;
        case 4:
            //informes
            menuInformes();
            utn_getNumero(&opcionInformes, "Ingrese una opcion: ", "Error\n", 1, 20, 3);
            switch(opcionInformes)
            {
            case 1:
                mostrarAlquileresPorCliente(alquileres, TAMA, clientes, TAMC, juegos, TAMJ, categorias, TAM_CAT);
                break;
            case 2:
                clientesMasAlquileres(alquileres, TAMA, clientes, TAMC, juegos, TAMJ, categorias, TAM_CAT);
                break;
            case 3:
                gastoCliente(alquileres, TAMA, clientes, TAMC, juegos, TAMJ, categorias, TAM_CAT);
                break;
            case 4:
                juegoMasAlquilado(alquileres, TAMA, clientes, TAMC, juegos, TAMJ, categorias, TAM_CAT);
                break;
            case 5:
                categoriaMasJuegos(alquileres, TAMA, clientes, TAMC, juegos, TAMJ, categorias, TAM_CAT);
                break;
            case 6:
                actualizarPrecioPorCategoria(alquileres, TAMA, clientes, TAMC, juegos, TAMJ, categorias, TAM_CAT);
                break;
            case 7:
                categoriaPreferidaCliente(alquileres, TAMA, clientes, TAMC, juegos, TAMJ, categorias, TAM_CAT);
                break;
            }
            break;
        case 10:
            seguir='n';

            break;
        }

        printf("Desea seleccionar otra opcion?: ");
        fflush(stdin);
        scanf("%c", &seguir);

        system("pause");

    }



    return 0;
}



