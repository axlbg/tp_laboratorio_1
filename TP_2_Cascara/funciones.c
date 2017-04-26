#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"
#include <string.h>

int obtenerEspacioLibre(ePersona lista[], int tam) {
    int i;
    for (i=0; i<tam; i++) {
        if (lista[i].estado == 0) {
            return i;
        }
    }
    return -1;
}

int buscarPorDni(ePersona lista[], int tam, int dni) {
    int i;
    for (i=0; i<tam; i++) {
        if (lista[i].dni == dni) {
            return i;
        }
    }
    return -1;
}

void inicializarPersonas(ePersona pers[], int tam) {
    int i;
    for (i=0; i<tam; i++) {
        pers[i].estado = 0;
    }
}

void pedirYGuardarDatos(ePersona lista[], int tam, int id) {
    char nombre[33];
    int edad, dni;

    printf("Ingrese nombre\n");
    fflush(stdin);
    gets(nombre);
    nombre[0] = toupper(nombre[0]);
    strcpy(lista[id].nombre, nombre);

    printf("Ingrese edad\n");
    fflush(stdin);
    scanf("%d", &edad);
    while (edad < 0 || edad > 150)
    {
        printf("Error. Ingrese edad valida.\n");
        fflush(stdin);
        scanf("%d", &edad);
    }
    lista[id].edad = edad;

    printf("Ingrese DNI\n");
    fflush(stdin);
    scanf("%d", &dni);

    while (buscarPorDni(lista, tam, dni) != -1) {
        printf("Error: DNI ya ingresado. Ingrese nuevo DNI\n");
        fflush(stdin);
        scanf("%d", &dni);
    }
    lista[id].dni = dni;

    lista[id].estado = 1;
}

void ordenarPorNombre(ePersona lista[], int tam) {
    int i, j;
    ePersona aux;
    for (i=0; i<tam-1; i++) {
        for(j=i+1; j<tam; j++) {
            if (strcmp(lista[i].nombre, lista[j].nombre) > 0) {
                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }
}

void mostrarLista(ePersona lista[], int tam) {
    int i;
    printf("Nombre \t\t Edad \t\t DNI\n\n");
    for (i=0; i<tam; i++) {
        if (lista[i].estado == 1) {
            printf("%s\t\t", lista[i].nombre);
            printf("%d\t\t", lista[i].edad);
            printf("%d\t\t", lista[i].dni);
            printf("\n \n");
        }
    }
}

void mostrarGrafico(int a, int b, int c) {
    int valores[3] = {a, b, c};
    int i, j;
    int max = 0;

    for (j=0; j<3; j++) {
        if (max < valores[j]) {
            max = valores[j];
        }
    }

    for (i=max; i>0; i--) {
        for (j=0; j<3; j++) {
            if (valores[j] < i) {
                printf("\t");
                continue;
            }
            printf(" *\t");
        }
        printf("\n");
    }
}

int cantidadEdades(ePersona lista[], int tam, int min, int max) {
    int i;
    int cont = 0;
    int edad;

    for (i=0; i<tam; i++) {
        if (lista[i].estado == 0) {
            continue;
        }

        edad = lista[i].edad;
        if (min <= edad && max >= edad) {
            cont++;
        }
    }
    return cont;
}
