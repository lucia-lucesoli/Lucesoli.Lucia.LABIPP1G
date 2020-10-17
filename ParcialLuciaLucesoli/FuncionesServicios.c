

void mostrarServicios(eServicio servicio)
{
    printf("  %d      %25s     %d\n", servicio.id, servicio.descripcion, servicio.precio);
}

void listaServicios(eServicio servicios[], int tamServicio)
{
    printf("*** LISTA DE SERVICIOS ***\n\n");
    printf("   ID  -  DESCRIPCION  -  PRECIO\n");
    for (int i = 0; i < tamServicio; i++)
    {
        if (servicios != NULL)
        {
            mostrarServicios(servicios[i]);
        }
    }
}

int buscarServicioPorID(eServicio servicios[], int tamServicio, int idBuscar)
{
    int retorno = -1;
    for (int i = 0; i < tamServicio; i++)
    {
        if (servicios[i].id == idBuscar)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

int descripcionDeServicios(int id, eServicio servicio[], int tamServicio, char desc[])
{
    int retorno = 0;

    for (int i = 0; i < tamServicio; i++)
    {
        if (id == servicio[i].id)
        {
            strcpy(desc, servicio[i].descripcion);
            retorno = 1;
            break;
        }
    }
    return retorno;
}



int harcodearServicio(eServicio servicios[], int tamServicio, int cantidad)
{
    int contador = 0;
        eServicio list[] = {
            {20000, "Lavado", 250},
            {20001, "Pulido", 300},
            {20002, "Encerado", 400},
            {20003, "Completo", 600}
            };
    if (cantidad <= 5 && tamServicio >= cantidad)
    {
        for (int i = 0; i < cantidad; i++)
        {
            servicios[i] = list[i];
            contador++;
        }
    }
    return contador;
}
