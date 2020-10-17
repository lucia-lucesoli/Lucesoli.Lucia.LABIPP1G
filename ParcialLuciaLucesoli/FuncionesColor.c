
void mostrarColor(eColor color)
{
    printf("    %d    %10s\n", color.id, color.nombre);
}


void listadoColores(eColor color[], int tamColor)
{

    printf("*** LISTA DE COLORES ***\n\n");
    printf("ID  -  COLOR  -  DESCRIPCION\n\n");
    for(int i = 0; i < tamColor; i++)
        {
            if (color != NULL)
            {
                mostrarColor(color[i]);
            }
        }
    printf("\n");
}



int descripcionDeColor(int id, eColor color[], int tamColor, char desc[])
{
    int retorno = 0;

    for (int i = 0; i < tamColor; i++){
        if (id == color[i].id){
            strcpy(desc, color[i].nombre);
            retorno = 1;
            break;
        }
    }
    return retorno;
}


int harcodearColores(eColor colores[], int tamColor, int cantidad)
{
    int contador = 0;
        eColor list[] = {
            {5000, "NEGRO"},
            {5001, "BLANCO"},
            {5002, "GRIS"},
            {5003, "ROJO"},
            {5004, "AZUL"}
            };
    if (cantidad <= 5 && tamColor >= cantidad)
    {
        for (int i = 0; i < cantidad; i++)
        {
            colores[i] = list[i];
            contador++;
        }
    }
    return contador;
}



