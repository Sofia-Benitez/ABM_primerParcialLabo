#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "harcodeo.h"

static char nombres[10][51]={
            "Donato",
            "German",
            "Damian",
            "Gaston",
            "Daniela",
            "Andrea",
            "Daniel",
            "Candela",
            "Georgina",
            "Maria"};

static char apellidos[10][51]={
            "Di Santis",
            "Martitegui",
            "Betular",
            "Dalmau",
            "Chepi",
            "Rincon",
            "Araoz",
            "Vetrano",
            "Barbarosa",
            "Odonell"};

static char sexos[10]={'m', 'm', 'm', 'm', 'f', 'f', 'm', 'f', 'f', 'f'};

static char telefonos[10][21]={"4637-9044", "115225878487", "376546741", "3040-9999", "3050-9898", "4054-9999", "115528585878", "+5427658853211", "+547025542655", "4530-5555"};

static int codigoJuego[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};///para los alquileres

static int codigoCliente[10] = {100, 101, 102, 103, 104, 105, 105, 106, 109, 106};

static eFecha fechaAlquiler[10]={{10,6,2021}, {25,8,2019}, {25,12,2018}, {25,5,2020}, {25,5,2016}, {20,10,2020}, {13,11,2021}, {25,5,2020}, {12,3,2020}, {11,1,2017}};

static char descripcionJuego[10][21]={"TEG", "Ruleta", "LIFE", "varita", "pool", "metegol", "dados", "cartas", "kit de magia", "pictionary"};

static float importeJuego[10]={1000, 2000, 2500, 900, 8000, 7000, 100, 150, 1000, 3200};

static int idCategoria[10] = {502, 501, 500, 504, 503, 503, 500, 500, 504, 500};




int harcodearClientes(eCliente lista[], int tam, int cant, int* pCodigo)///devuleve todos los empleados que se pudieron cargar correctamente
{
    int total = 0;//si no entra al for devuelve 0

    if(lista!=NULL && tam>0 && cant>=0 && cant<=tam && pCodigo!=NULL)///recorrer el array
    {

        for(int i=0; i<cant; i++)
        {
            lista[i].codigo=*pCodigo;///valor de codigo en ese momento en main
            (*pCodigo)++;
            strcpy(lista[i].nombre, nombres[i]);
            strcpy(lista[i].apellido, apellidos[i]);
            strcpy(lista[i].telefono, telefonos[i]);
            lista[i].sexo=sexos[i];
            lista[i].isEmpty=0;

            total++;
        }
    }
    return total;
}

int harcodearAlquileres(eAlquileres alquileres[], int tamA, int cant, int* pId)
{
    int total = 0;//si no entra al for devuelve 0

    if(alquileres!=NULL && tamA>0 && cant>=0 && cant<=tamA && pId!=NULL)///recorrer el array
    {

        for(int i=0; i<cant; i++)
        {
            alquileres[i].codigoAlquiler=*pId;///valor de codigo en ese momento en main
            (*pId)++;
            alquileres[i].codigoCliente=codigoCliente[i];
            alquileres[i].codigoJuego=codigoJuego[i];
            alquileres[i].fechaAlquiler=fechaAlquiler[i];
            alquileres[i].isEmpty=0;

            total++;
        }
    }
    return total;

}

int harcodearJuegos(eJuego juegos[], int tamJ, int cant, int* pCodigo)
{
    int total = 0;//si no entra al for devuelve 0

    if(juegos!=NULL && tamJ>0 && cant>=0 && cant<=tamJ && pCodigo!=NULL)///recorrer el array
    {

        for(int i=0; i<cant; i++)
        {
            juegos[i].codigo=*pCodigo;///valor de codigo en ese momento en main

            strcpy(juegos[i].descripcion, descripcionJuego[i]);
            juegos[i].importe=importeJuego[i];
            juegos[i].idCategoria=idCategoria[i];
            juegos[i].isEmpty=0;
            (*pCodigo)++;
            total++;
        }
    }
    return total;
}
