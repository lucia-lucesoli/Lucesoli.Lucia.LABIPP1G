


int agregarTrabajo(eTrabajo trabajo[], int tamTrabajo, eAuto autos[], int tamAutos, eServicio servicios[], int tamServicio, eMarcas marcas[], int tamMarcas, eColor colores[], int tamColores, int idTrabajo)
{
    int retorno = 0;
    int auxIdVehiculo;
    int auxIdServicio;
    int inicioAutos;
    int inicioServicios;
    int inicioTrabajos;
    eFecha auxFecha;

    system("cls");

    printf("*** ALTA DE TRABAJO ***\n\n");
    inicioTrabajos = agregarTrabajo(trabajo, tamTrabajo);
    if (inicioTrabajos == -1)
    {
        printf("*** El cupo de trabajo es completo ***\n\n");
    } else
        {
        listadoAutos(autos, tamAutos, marcas, tamMarcas, colores, tamColores);
        printf("Ingrese el ID del vehiculo para realizar un trabajo: ");
        fflush(stdin);
        scanf("%d", &auxIdVehiculo);
        inicioAutos = buscarAutoPorId(autos, tamAutos, auxIdVehiculo);
        if(inicioAutos != -1)
        {
            mostrarServicios(servicios, tamServicio);
            printf("Ingrese el ID del servicio: ");
            fflush(stdin);
            scanf("%d", &auxIdServicio);
            inicioServicios = busc(servicios, tamServicio, auxIdServicio);
            if (inicioServicios != -1)
            {
                printf("Ingrese la fecha del trabajo:\n");
                printf("Dia: ");
                fflush(stdin);
                scanf("%d", &auxFecha.dia);
                while(!validacionDeDia(auxFecha.dia))
                {
                    printf("Ingrese un dia correcto!\n");
                    printf("Dia: ");
                    scanf("%d", &auxFecha.dia);
                }
                printf("Mes: ");
                fflush(stdin);
                scanf("%d", &auxFecha.mes);
                while(!validacionDeMes(auxFecha.mes))
                {
                    printf("Ingrese un mes correcto!\n");
                    printf("Mes: ");
                    scanf("%d", &auxFecha.mes);
                }
                printf("Anio: ");
                fflush(stdin);
                scanf("%d", &auxFecha.anio);
                while(!validacionDeAnio(auxFecha.anio))
                {
                    printf("Ingrese un anio correcto!\n");
                    printf("Anio: ");
                    scanf("%d", &auxFecha.anio);
                }
                trabajo[inicioTrabajos] = cargarTrabajo(idTrabajo, autos[inicioAutos].patente, servicios[inicioServicios].id, auxFecha);
                printf("*** Se ha realizado la carga del trabajo con exito ***\n\n");
                retorno = 1;
            } else
                {
                    printf("No se ha encontrado ningun servicio con ese ID indicado. Reingresar \n\n");
                }
        } else
            {
                printf("No se ha encontrado ningun vehiculo con ese ID. Reingresar. \n\n");
            }
        }
    return retorno;
}




eTrabajo cargarTrabajo(int id, int patente, int servicio, eFecha fecha)
{
    eTrabajo trabajo;
    trabajo.id = id;
    trabajo.patente = patente;
    trabajo.idServicio = servicio;
    trabajo.fechaDeTrabajo = fecha;
    trabajo.isEmpty = 0;
    return trabajo;
}



void inicializarTrabajo(eTrabajo trabajo[], int tamTrabajo)
{
    for (int i = 0; i < tamTrabajo; i++)
    {
        trabajo[i].isEmpty = 1;
    }
}



int buscarTrabajo(eTrabajo trabajo[], int tamTrabajo)
{
    int retorno = -1;
    for (int i = 0; i < tamTrabajo; i++)
    {
        if(trabajo[i].isEmpty == 1)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}



void mostrarTrabajo(eTrabajo trabajo, eServicio servicios[], int tamServicio)
{
    char descServicio[20];
    descripcionDeTrabajo(trabajo.idServicio, servicios, tamServicio, descServicio);

    printf("      %d      %d      %20s      %02d/%02d/%d\n\n", trabajo.id,
            trabajo.patente,
            descServicio,
            trabajo.fechaDeTrabajo.dia,
            trabajo.fechaDeTrabajo.mes,
            trabajo.fechaDeTrabajo.anio);
}


int listadoTrabajos(eTrabajo trabajo[], int tamTrabajo, eServicio servicios[], int tamServicio)
{
    int retorno = 0;

    printf("*** LISTADO DE TRABAJOS ACTUALES ***\n\n");

    printf("     ID  -  PATENTE  -  TRABAJO  -  FECHA DE TRABAJO\n\n");
    for(int i = 0; i < tamTrabajo; i++)
    {
        if (trabajo[i].isEmpty == 0)
        {
            mostrarTrabajo(trabajo[i], servicios, tamServicio);
            retorno = 1;
        }
    }
    return retorno;
}



