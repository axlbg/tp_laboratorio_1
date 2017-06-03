#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        printf("\n1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        opcion = getch();

        switch(opcion)
        {
            case '1': opcionAgregarPeli();
                break;
            case '2': opcionBorrarPeli();
                break;
            case '3': opcionModificarPeli();
               break;
            case '4': opcionGenerarPagica();
               break;
            case '5':
                seguir = 'n';
                break;
            default:
                printf("Ingrese opcion valida.");
                break;
        }
    }

    return 0;
}

