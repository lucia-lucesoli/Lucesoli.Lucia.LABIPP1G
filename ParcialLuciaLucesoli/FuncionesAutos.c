#include <stdio.h>
#include <stdlib.h>



void inicializarAuto(eAuto vehiculos[], int tamAutos)
{
    for(int i = 0; i < tamAutos; i++)
    {
        vehiculos[i].isEmpty = 1;
    }
}


int buscarAuto(eAuto vehiculos[], int tamAutos)
{
    int retorno = -1;
    for(int i = 0; i < tamAutos; i++)
    {
        if(vehiculos[i].isEmpty == 1)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}


int seleccionDelAuto(eAuto vehiculos[], int tamAutos)
{
    int retorno = 0;
    for(int i = 0; i < tamAutos; i++)
    {
        if (vehiculos[i].isEmpty == 0)
        {
            retorno = 1;
        }
    }
    return retorno;
}


eAuto nuevoAuto(int id, int patente, int idMarca, int idColor, int modelo)
{
    eAuto vehiculo;
    vehiculo.id = id;
    vehiculo.patente = patente;
    vehiculo.idColor = idColor;
    vehiculo.idMarca = idMarca;
    vehiculo.modelo = modelo;
    vehiculo.isEmpty = 0;
    return vehiculo;
}




int altaAuto(eAuto vehiculos[], int tamAutos, int idAuto, eMarcas marcas[], int tamMarca, eColor colores[], int tamColor)
{
    int retorno = 0;
    int auxPatente;
    int auxIdMarca;
    int auxIdColor;
    int auxModelo;
    int inicioAutos;
    system("cls");
    printf("*** ALTA DE VEHICULOS ***\n\n");
    inicioAutos = buscarAuto(vehiculos, tamAutos);
    if (inicioAutos == -1)
    {
        printf("Error en el alta del vehiculo. Reintentar\n\n");
    }
    else
    {
        printf("Ingrese la patente del vehiculo: \n");
        fflush(stdin);
        scanf("%d", &auxPatente);
        while(!validacionDePatente(auxPatente))
        {
            printf("Error, la patente ingresada debe tener seis numeros. Reingresar: \n");
            fflush(stdin);
            scanf("%d", &auxPatente);
        }
        marcaAutos(marcas, tamMarca);
        printf("Ingrese el ID de la marca del vehiculo: ");
        fflush(stdin);
        scanf("%d", &auxIdMarca);
        while(!validacionDeMarca(marcas, tamMarca, auxIdMarca))
        {
            printf("Error en la marca ingresa. Reingresar: ");
            fflush(stdin);
            scanf("%d", &auxIdMarca);
        }
        colorAutos(colores, tamColor);
        printf("Ingrese el ID del color del vehiculo: ");
        fflush(stdin);
        scanf("%d", &auxIdColor);
        while(!validacionDeColor(colores, tamColor, auxIdColor))
        {
            printf("ID del color ingresado incorrecto. Reingresar: ");
            fflush(stdin);
            scanf("%d", &auxIdColor);
        }
        printf("Ingrese el anio de fabricacion del vehiculo: ");
        fflush(stdin);
        scanf("%d", &auxModelo);
        while (!validacionDeModelo(auxModelo))
        {
            printf("Error al ingresar anio. Reingresar: ");
            fflush(stdin);
            scanf("%d", &auxModelo);
        }
        vehiculos[inicioAutos] = nuevoAuto(idAuto, auxPatente, auxIdMarca, auxIdColor, auxModelo);
        printf(" *** Se ha realizado con exito el alta del vehiculo ***\n\n");
        retorno = 1;
    }

    return retorno;
}


void mostrarAuto(eAuto vehiculos, eMarcas marca[], int tamMarca, eColor colores[], int tamColor)
{
    char descColores[20];
    char descMarca[20];

    mostrarColoresAutos(vehiculos.idColor, colores, tamColor, descColores);
    mostrarMarcasAutos(vehiculos.idMarca, marca, tamMarca, descMarca);

    printf("  %d    %d %10s   %8s   %d\n",
           vehiculos.id,
           vehiculos.patente,
           descMarca,
           descColores,
           vehiculos.modelo);
}



void listadoAutos(eAuto vehiculos[], int tamAutos, eMarcas marcas[], int tamMarca, eColor color[], int tamColor)
{

    printf("*** VEHICULOS ORDENADOS SEGUN MARCA Y PATENTE ***\n\n");


    printf("ID AUTO      PATENTE      MARCA      COLOR      MODELO\n\n");
    for(int i = 0; i < tamAutos; i++)
    {
        if (vehiculos[i].isEmpty == 0)
        {
            mostrarAuto(vehiculos[i], marcas, tamMarca, color, tamColor);
        }
    }
}


int bajaAuto(eAuto vehiculos[], int tamAutos, eMarcas marcas[], int tamMarca, eColor color[], int tamColor)
{
    system("cls");
    int retorno = 0;
    int auxIDAuto;
    int inicioAutos;
    char respuesta;

    printf("*** BAJA DE VEHICULOS ***\n\n");
    listadoAutos(vehiculos, tamAutos, marcas, tamMarca, color, tamColor);
    printf("Ingrese el ID del vehiculo para darlo de baja: ");
    fflush(stdin);
    scanf("%d", &auxIDAuto);
    inicioAutos = searchIDCarEnArray(vehiculos, tamAutos, auxIDAuto);
    if(inicioAutos != -1)
    {
        printf("*** ID AUTO     PATENTE     MARCA     COLOR     MODELO ***");
        mostrarAuto(vehiculos[inicioAutos], marcas, tamMarca, color, tamColor);
        printf("Esta seguro que quiere dar de baja el vehiculo? (s/n):\n ");
        fflush(stdin);
        scanf("%c", &respuesta);
        opcion(&respuesta);
        if(respuesta == 's')
        {
            vehiculos[inicioAutos].isEmpty = 1;
            printf("*** Se ha realizado con exito la baja del vehiculo ***\n");
            retorno = 1;
        }
        else
        {
            printf("Se ha cancelado la baja del vehiculo.");
        }
    }
    else
    {
        printf("El ID del vehiculo es incorrecto. Reingresar. \n");
    }
    return retorno;
}


int buscarAutoPorId(eAuto vehiculos[], int tamAutos, int idBuscar)
{
    int retorno = -1;
    for (int i = 0; i < tamAutos; i++)
    {
        if (vehiculos[i].id == idBuscar)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}


int buscarAutoPorPatente(eAuto vehiculos[], int tamAutos, int buscarPatente)
{
    int retorno = -1;
    for (int i = 0; i < tamAutos; i++)
    {
        if (vehiculos[i].patente == buscarPatente)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}


void modificarAuto(eAuto vehiculos[], int tamAutos, eMarcas marcas[], int tamMarca, eColor color[], int tamColor)
{
    int auxPatente;
    int auxColor;
    int auxMarca;
    int inicio;
    int opcion;

    system("cls");
    printf("*** MODIFICAR VEHICULOS ***\n\n");
    listadoAutos(vehiculos, tamAutos, marcas, tamMarca, color, tamColor);
    printf("Ingrese la patente del vehiculo a modificar: ");
    fflush(stdin);
    scanf("%d", &auxPatente);

    inicio = buscarAutoPorPatente(vehiculos, tamAutos, auxPatente);
    if(inicio != -1)
    {
        mostrarAuto(vehiculos[inicio], marcas, tamMarca, color, tamColor);
        printf("1. Modificar Color\n");
        printf("2. Modificar Modelo\n");
        printf("3. Cancelar operacion\n\n");
        printf("Elija la opcion a modificar: ");
        fflush(stdin);
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            colorAuto(color, tamColor);
            printf("Ingrese el ID del nuevo color: ");
            fflush(stdin);
            scanf("%d", &auxColor);
            if(validacionDeColor(color, tamColor, auxColor))
            {
                vehiculos[inicio].idColor = auxColor;
                printf("*** Se ha realizado con exito el cambio del color del vehiculo ***\n");
                system("pause");
            }
            else
            {
                printf("El ID del color es incorrecto. Reintentar \n");
                system("pause");
            }
            break;
        case 2:
            marcaAuto(marcas, tamMarca);
            printf("Ingrese la marca del vehiculo: ");
            fflush(stdin);
            scanf("%d", &auxMarca);
            if(validacionDeMarca(marcas, tamMarca, auxMarca))
            {
                vehiculos[inicio].idMarca = auxMarca;
                printf("*** Se ha realizado con exito el cambio de marca del vehiculo ***\n");
                system("pause");
            }
            else
            {
                printf("La marca incorrecta. Reintentar.\n");
                system("pause");
            }
            break;
        case 3:
            printf("Se cancelo la modificacion de vehiculos.\n\n");
            break;
        default:
            printf("La opcion ingresada es incorrecta. Por favor ingrese una opcion valida.\n\n");
            system("pause");
        }
    }
    else
    {
        printf("La pantente ingresada es inexistente. Reingresar\n");
    }
}


void ordenarAutos(eAuto vehiculos[], int tamAutos, eMarcas marcas[], int tamMarca, eColor color[], int tamColor)
{

    eAuto auxVehiculo;
    for (int i = 0; i < tamAutos-1; i++)
    {
        for (int j = i+1; j < tamAutos; j++)
        {
            if(vehiculos[i].idMarca > vehiculos[j].idMarca && !vehiculos[i].isEmpty && !vehiculos[i].isEmpty)
            {
                auxVehiculo = vehiculos[i];
                vehiculos[i] = vehiculos[j];
                vehiculos[j] = auxVehiculo;
            }
            if (vehiculos[i].idMarca == vehiculos[j].idMarca && vehiculos[i].patente > vehiculos[j].patente && !vehiculos[i].isEmpty && !vehiculos[i].isEmpty)
            {
                auxVehiculo = vehiculos[i];
                vehiculos[i] = vehiculos[j];
                vehiculos[j] = auxVehiculo;
            }
        }
    }
}



int harcodearAutos(eAuto vehiculos[], int tamAutos, int cantidadAutos)
{
    int contador;

    eAuto list[] =
    {
        {7000, 300555, 1002, 5004, 2018, 0},
        {7001, 403600, 1003, 5002, 1999, 0},
        {7002, 899600, 1000, 5003, 2001, 0},
        {7003, 552103, 1001, 5000, 1970, 0},
        {7004, 325700, 1005, 5003, 2016, 0},
        {7005, 830690, 1001, 5002, 2014, 0},
        {7006, 708505, 1000, 5000, 1940, 0}
    };
    if (cantidadAutos <= 7 && tamAutos >= cantidadAutos)
    {
        for (int i = 0; i < cantidadAutos; i++)
        {
            vehiculos[i] = list[i];
            contador++;
        }
    }
    return contador;
}










