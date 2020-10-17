

void mostrarMarca(eMarca marca)
{
    printf("    %d    %10s\n", marca.id, marca.nombre);
}


void listadoMarcas(eMarca marca[], int tamMarca)
{

    printf("*** LISTA DE MARCAs ***\n\n");
    printf("ID  -  MARCA  -  DESCRIPCION\n\n");
    for(int i = 0; i < tamMarca; i++)
        {
            if (marca != NULL)
            {
                mostrarMarca(marca[i]);
            }
        }
    printf("\n");
}


int descripcionDeMarca(int id, eMarca marca[], int tamMarca, char desc[])
{
    int retorno = 0;

    for (int i = 0; i < tamMarca; i++){
        if (id == marca[i].id){
            strcpy(desc, marca[i].nombre);
            retorno = 1;
            break;
        }
    }
    return retorno;
}


int harcodearMarcas(eMarca marca[], int tamMarca, int cantidad)
{
    int contador = 0;
        eMarca list[] = {
            {5000, "RENAULT"},
            {5001, "FIAT"},
            {5002, "FORD"},
            {5003, "CHEVROLET"},
            {5004, "PEUGEOT"}
            };
    if (cantidad <= 5 && tamMarca >= cantidad)
    {
        for (int i = 0; i < cantidad; i++)
        {
            marca[i] = list[i];
            contador++;
        }
    }
    return contador;
}
