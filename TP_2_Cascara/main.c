#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <conio.h>

#define ITEMS 20

int main()
{
    char seguir='s';
    int opcion;
    int id;
    int dni;

    ePersona lista[ITEMS];
    inicializarPersonas(lista, ITEMS);

    do {
        system("cls");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                id = obtenerEspacioLibre(lista, ITEMS);
                if (id == -1) {
                    printf("No se puede agregar mas de %d personas. Saliendo . . .\n", ITEMS);
                    system("pause");
                    break;
                }
                pedirYGuardarDatos(lista, ITEMS, id);
                printf("\nSe agrego persona\n %s \t Edad %d \t DNI %d \n\n", lista[id].nombre, lista[id].edad, lista[id].dni);

                system("pause");
                break;
            case 2: //borrar
                mostrarLista(lista, ITEMS);

                printf("Ingrese el DNI para borrar\n");
                fflush(stdin);
                scanf("%d", &dni);

                id = buscarPorDni(lista, ITEMS, dni);
                if (id == -1 || lista[id].estado == 0) {
                    printf("No se encuentra coincidencia de DNI. Saliendo . . .\n");
                    system("pause");
                    break;
                }
                printf("Presione 's' para borrar a %s DNI %d\n", lista[id].nombre, lista[id].dni);
                fflush(stdin);
                if( getch() == 's') {
                    lista[id].estado = 0;
                    printf("Persona borrada correctamente.\n");
                }
                else {
                    printf("\n Saliendo sin borrar . . .\n");
                }

                system("pause");
                break;
            case 3: //lista ordenada por nombre
                ordenarPorNombre(lista, ITEMS);
                mostrarLista(lista, ITEMS);

                system("pause");
                break;
            case 4:
                printf("\n\n");
                mostrarGrafico(cantidadEdades(lista, ITEMS, 0, 18), cantidadEdades(lista, ITEMS, 18, 35), cantidadEdades(lista, ITEMS, 35, 120));
                printf(">18 \t19-35 \t<35\n");

                system("pause");
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("Error. Ingrese una opcion valida.\n");

                system("pause");
                break;
        }
    }while(seguir=='s');

    return 0;
}
