#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cliente.h"
#include "utn.h"


//menu
void menu(void)
{

    system("cls");

    printf("Alquiler de juegos\n");
    printf("1. CLIENTES\n");
    printf("2. ALQUILERES\n");
    printf("3. JUEGOS (mostrar) \n");
    printf("4. INFORMES\n");
    printf("5. --------\n");
    printf("6. ---------- \n");
    printf("10. Salir\n");



}

void menuClientes(void)
{
    system("cls");

    printf("CLIENTES\n");
    printf("1. Alta \n");
    printf("2. Baja\n");
    printf("3. Modificacion \n");
    printf("4. Listar\n");
    printf("5. --------\n");
    printf("6. ---------- \n");
    printf("10. Salir\n");
}

///clientes

int inicializarClientes(eCliente lista[], int tam)
{
    int todoOk=0;
    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)//recorro el array para inicializar
        {
               lista[i].isEmpty=1;
        }
        todoOk=1;
    }
    return todoOk;
}

void mostrarCliente(eCliente unCliente)
{


    printf("%d          %10s            %10s                     %c                       %s          \n",
           unCliente.codigo,
           unCliente.apellido,
           unCliente.nombre,
           unCliente.sexo,
           unCliente.telefono
           );

}

int mostrarClientes(eCliente lista[], int tam)
{
    int flag=1;
    int todoOk=0;

    if(lista!=NULL && tam>0)
    {
        printf("\n                                        ******Lista de clientes******\n");
        printf("Codigo            Apellido                 Nombre                 Sexo                  Telefono \n");
        printf("----------------------------------------------------------------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty==0)///muestra los que estan en el indice que estan ocupados
            {
                mostrarCliente(lista[i]);
                flag=0;
            }
        }
        if(flag)
        {
            printf("\n\n                                      No hay clientes en la lista\n");
        }
        printf("\n\n");
        todoOk=1;
    }


    return todoOk;
}

int buscarCliente(eCliente lista[], int tam, int codigo)
{
    int indice=-1;///si no lo encunetra devuelve -1 que es imposible como indice

    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(!lista[i].isEmpty && lista[i].codigo == codigo)//si no es 1, es decir si esta ocupado && si el indice es igual al legajo que me pasan
            {
                indice=i;///guardo en la variable indice le indice de la estructura que coincide
                break;///si no rompe me devuelve el indice de la ultima estructura vacia y yo necesito el primero.
            }
        }
    }

    return indice;

}


int buscarLibre(eCliente lista[], int tam)
{
    int indice=-1;

    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty)//si es 1
            {
                indice=i;
                break;
            }
        }

    }

    return indice;
}


int altaCliente(eCliente lista[], int tam, int* pCodigo)///devuelve 0 si no se puede y 1 si se puede
{
    int todoOk=0;
    int indice;



    eCliente nuevoCliente;  ///auxiliar


    if(lista!=NULL && tam>0 && pCodigo!=NULL)
    {
        system("cls");
        printf("Alta de cliente\n\n");
        printf("Codigo: %d\n", *pCodigo);
        indice=buscarLibre(lista, tam);
        if(indice==-1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {

            nuevoCliente.codigo= *pCodigo; ///traigo el codigo

            utn_getStringNombre(nuevoCliente.nombre, "Ingrese el nombre del cliente: ", "Error, ingrese un nombre valido.\n", 51, 3);

            utn_getStringNombre(nuevoCliente.apellido, "Ingrese el apellido del cliente: ", "Error, ingrese un apellido valido.\n", 51, 3);

            utn_getGenero(&nuevoCliente.sexo, "Ingrese el genero: ");

            utn_getTelefono(nuevoCliente.telefono, "Ingrese el telefono: ", "Error, telefono invalido.\n", 21, 3);

            nuevoCliente.isEmpty=0;///ahora es una estructura cargada

            lista[indice]=nuevoCliente;

            ///actualizo el proximo cod
            *pCodigo=(*pCodigo)+1;


             todoOk=1;
        }

    }

    return todoOk;
}


int modificarCliente(eCliente lista[], int tam)
{
    int todoOk=0;
    int indice;//para guardar la ubicacion
    int codigo;
    int opcion;
    char nuevoNombre[51];
    char nuevoApellido[51];
    char nuevoTelefono[21];
    char confirma='s';
    int flagNombre=0;
    int flagApellido=0;
    int flagTelefono=0;


    system("cls");
    printf("       Modificacion de clientes\n");

    mostrarClientes(lista, tam);

    utn_getNumero(&codigo, "Ingrese el codigo del cliente que desea modificar: ", "Error, codigo invalido. \n", 100, 1100, 3);

    indice=buscarCliente(lista, tam, codigo);

    if(indice==-1)
    {
        printf("No existe un cliente con el codigo %d", codigo);
    }
    else
    {
        mostrarCliente(lista[indice]);

        printf("1. Modificar nombre\n");
        printf("2. Modificar apellido\n");
        printf("3. Modificar telefono\n");

        utn_getNumero(&opcion, "Ingrese el campo que desea modificar: ", "Error.\n", 1, 3, 3);
        switch(opcion)
        {
            case 1:
                utn_getStringNombre(nuevoNombre, "Ingrese el nuevo nombre: ", "Error.\n", 51, 3);
                flagNombre=1;

                break;
            case 2:
                utn_getStringNombre(nuevoApellido, "Ingrese el nuevo apellido: ", "Error.\n", 51, 3);
                flagApellido=1;

                break;
            case 3:
                utn_getTelefono(nuevoTelefono, "Ingrese el nuevo telefono: ", "Error, telefono invalido.\n", 21, 3);
                flagTelefono=1;

                break;

        }

        printf("Confirma la modificacion del cliente? (s para aceptar) ");
        scanf("%c", &confirma);
        if(confirma=='s')
        {
            if(flagNombre==1)
            {
                strcpy(lista[indice].nombre,nuevoNombre);
                printf("Nombre actualizado\n");
            }
            if(flagApellido==1)
            {
                strcpy(lista[indice].apellido,nuevoApellido);
                printf("Apellido actualizado\n");
            }
            if(flagTelefono==1)
            {
                strcpy(lista[indice].telefono,nuevoTelefono);
                printf("Telefono actualizado\n");
            }
            todoOk=1;
        }
        else
        {
            printf("Modificacion cancelada por el usuario.\n");
            todoOk=0;
        }


    }


    return todoOk;
}


int bajaCliente(eCliente lista[], int tam)
{
    int todoOk=0;
    int indice;//para guardar la ubicacion
    int codigo;
    char confirma;

    system("cls");
    printf("       Baja de clientes\n");

    mostrarClientes(lista, tam);

    utn_getNumero(&codigo, "Ingrese el codigo del cliente que desea dar de baja: ", "Error, codigo invalido. \n", 100, 1100, 3);

    indice=buscarCliente(lista, tam, codigo);

    if(indice==-1)
    {
        printf("No existe un cliente con el codigo %d", codigo);
    }
    else
    {
        mostrarCliente(lista[indice]);

        printf("Confirma la baja del cliente %d?: ", codigo);
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma=='s')
        {
            lista[indice].isEmpty=1;

            todoOk=1;
        }
        else
        {
            printf("Baja cancelada por el usuario\n");
        }
    }
    return todoOk;
}

int ordenarClientes(eCliente lista[], int tam, int criterio)
{
    int todoOk=0;//si no se puede ordenar
    eCliente auxCliente;//auxiliar de lo que voy a ordenar

    if(lista!=NULL && tam>0)
    {
        if(criterio==1)
        {

            for(int i=0; i<tam-1; i++)
            {
                for(int j=i+1; j<tam; j++)
                {
                    if(strcmp(lista[i].apellido, lista[j].apellido)>0)
                    {
                        auxCliente=lista[i];
                        lista[i]=lista[j];
                        lista[j]=auxCliente;
                    }
                }
            }

        }
        //else



    }

    todoOk=1;


    return todoOk;
}


int cargarNombreCliente(int codigo, eCliente lista[], int tam, char nombre[])
{
    int todoOk=0;

    if(lista!=NULL && tam>0 && nombre!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(lista[i].codigo==codigo && !lista[i].isEmpty)
            {
                strcpy(nombre, lista[i].nombre);///cargo la cadena que me pasan en la funcion
                todoOk=1;
                break;///ya consegui la descripcion correspondiente
            }
        }
    }

    return todoOk;
}


int mostrarClientesDeBaja(eCliente lista[], int tam)
{
    int flag=1;
    int todoOk=0;

    if(lista!=NULL && tam>0)
    {
        printf("\n                                        ******Lista de clientes******\n");
        printf("Codigo            Apellido                 Nombre                 Sexo                  Telefono \n");
        printf("----------------------------------------------------------------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty==1 && lista[i].codigo>=100 && lista[i].codigo<=1100 && utn_esSoloLetras(lista[i].nombre) && (lista[i].sexo=='f' ||lista[i].sexo=='m'||lista[i].sexo=='o'))///muestra los que estan en el indice que estan ocupados
            {
                mostrarCliente(lista[i]);
                flag=0;
            }
        }
        if(flag)
        {
            printf("\n\n                                      No hay clientes en la lista\n");
        }
        printf("\n\n");
        todoOk=1;
    }


    return todoOk;
}
