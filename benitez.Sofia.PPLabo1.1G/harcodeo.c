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

