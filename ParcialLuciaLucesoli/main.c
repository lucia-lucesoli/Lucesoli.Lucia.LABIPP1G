#include <stdio.h>
#include <stdlib.h>

#include "FuncionesAutos.h"
#include "FuncionesTrabajo.h"
#include "FuncionesServicios.h"
#include "FuncionesMarcas.h"
#include "FuncionesColor.h"

#define TAM_AUTO 1000
#define TAM_MARCA 5
#define TAM_COLOR 5
#define TAM_TRABAJO 100
#define TAM_SERVICIO 4

int main()
{

    int idAuto = 7000;
    int idMarca = 1000;
    int idColor = 5000;
    int idServicio = 20000;
    int idTrabajo = 10000;
    char salir = 'n';

    inicializarAuto(listadoAutos, TAM_AUTO);
    inicializarTrabajo(listadoTrabajos, TAM_TRABAJO);

    eAuto listaAutos[TAM_AUTO];
    eMarcas listaMarcas[TAM_MARCA];
    eColor listaColores[TAM_COLOR];
    eTrabajo listaTrabajos[TAM_TRABAJO];
    eServicio listaServicios[TAM_SERVICIO];

    idAuto = idAuto + harcodearAutos(listaAutos, TAM_AUTO, 7);
    idMarca = idMarca + harcodearMarcas(listaMarcas, TAM_MARCA, 5);
    idColor = idColor + harcodearColores(listaColores, TAM_COLOR, 5);
    idServicio = idServicio + harcodearServicio(listaServicios, TAM_SERVICIO, 4);




    do
    {
        switch(menuPrincipal())
        {
        case 1:
            if((listaAutos, TAM_AUTO, idAuto, listaMarcas, TAM_MARCA, listaColores, TAM_COLOR))
            {
                idAuto++;
            }
            break;
        case 2:
            if(seleccionDelAuto(listaAutos, TAM_AUTO))
            {
                modificarAuto(listaAutos, TAM_AUTO, listaMarcas, TAM_MARCA, listaColores, TAM_COLOR);
            } else
                {
                    printf("*** Modificar vehiculo ***\n\n");
                }
            break;
        case 3:
            if(seleccionDelAuto(listaAutos, TAM_AUTO))
            {
                bajaAuto(listaAutos, TAM_AUTO, listaMarcas, TAM_MARCA, listaColores, TAM_COLOR);
            } else
                {
                    printf("*** Baja de vehiculo ***\n\n");
                }
            break;
        case 4:
            if(seleccionDelAuto(listaAutos, TAM_AUTO))
            {
                system("cls");
                ordenarAutos(listaAutos, TAM_AUTO, listaMarcas, TAM_MARCA, listaColores, TAM_COLOR);
                listaAutos(listaAutos, TAM_AUTO, listaMarcas, TAM_MARCA, listaColores, TAM_COLOR);
            } else
                {
                    printf("*** Ordenar vehiculos ***\n\n");
                }
            break;
        case 5:
            system("cls");
            listaMarcas(listaMarcas, TAM_MARCA);
            break;
        case 6:
            system("cls");
            listaColores(listaColores, TAM_COLOR);
            break;
        case 7:
            system("cls");
            listaServicios(listaServicios, TAM_SERVICIO);
            break;
        case 8:
            if(agregarTrabajo(listaTrabajos, TAM_TRABAJO, listaAutos, TAM_AUTO, listaServicios, TAM_SERVICIO, listaMarcas, TAM_MARCA, listaColores, TAM_COLOR, idTrabajo))
            {
                idTrabajo++;
            }
            break;
        case 9:
            system("cls");
            listaTrabajos(listaTrabajos, TAM_TRABAJO, listaServicios, TAM_SERVICIO);
            break;
        case 10:
            printf("Desea continuar? (s/n): ");
            fflush(stdin);
            scanf("%c", &salir);
            salir = tolower(salir);
            validarOpcion(&salir);
            break;
            default:
                printf("La opcion ingresada es incorrecta. Reingrese opcion: ");
        }

        system("pause");

    }while(salir == 'n');

    return 0;

}
