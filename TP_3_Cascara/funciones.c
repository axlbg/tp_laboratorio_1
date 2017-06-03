#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define ARCHIVO_BIN "peliculas.bin"
#define ARCHIVO_DATOS "datos.bin"
#define ARCHIVO_HTML "mipagina.html"

agregarPelicula(sMovie movie)
{
	FILE  *arch;
	if ((arch=fopen(ARCHIVO_BIN,"ab"))==NULL) {
        return 1;
	}

	fwrite(&movie, sizeof(sMovie), 1, arch);
	fclose(arch);

	return 0;
}

int opcionAgregarPeli()
{
    sMovie peli;
    peli = pedirDatosMovie();

    if (agregarPelicula(peli)) {
        printf("Error. No se pudo agregar la pelicula.");
        return 1;
    }

    printf("La pelicula fue agregada correctamente.");
    return 0;
}

sMovie pedirDatosMovie()
{
    sMovie peli;
    int duracion, puntaje;
    char titulo[20], genero[20], descripcion[50], linkImagen[50];

    printf("Ingrese Titulo: ");
    fflush(stdin);
    gets(titulo);

    printf("Ingrese genero: ");
    fflush(stdin);
    gets(genero);

    printf("Ingrese duracion: ");
    fflush(stdin);
    while(scanf("%d", &duracion) != 1) {
        printf("Error. Ingrese una duracion valida: ");
        fflush(stdin);
    }

    printf("Ingrese descripcion: ");
    fflush(stdin);
    gets(descripcion);

    printf("Ingrese puntaje: ");
    fflush(stdin);
    while(scanf("%d", &puntaje) != 1) {
        printf("Error. Ingrese un puntaje valido: ");
        fflush(stdin);
    }
    printf("Ingrese link de imagen: ");
    fflush(stdin);
    gets(linkImagen);

    strcpy(peli.titulo, titulo);
    strcpy(peli.genero, genero);
    peli.duracion = duracion;
    strcpy(peli.descripcion, descripcion);
    peli.puntaje = puntaje;
    strcpy(peli.linkImagen, linkImagen);

    return peli;
}

int generarPagina(sMovie movie, int flag)
{
    FILE *arch;
    if (flag == 0) {
        if ((arch=fopen(ARCHIVO_HTML,"w"))==NULL) {
            return 1;
        }
    }
    else {
        if ((arch=fopen(ARCHIVO_HTML,"a"))==NULL) {
            return 1;
        }
    }

	fprintf(arch, "<article class='col-md-4 article-intro'>\
         <a href='#'>\
            <img class='img-responsive img-rounded' src='%s'alt=''>\
        </a>\
        <h3>\
            <a href='#'>%s</a>\
        </h3>\
        <ul>\
            <li>Género:%s</li>\
            <li>Puntaje:%d</li>\
            <li>Duración:%d</li>\
        </ul>\
        <p>%s</p></article>", movie.linkImagen, movie.titulo, movie.genero, movie.puntaje, movie.duracion, movie.descripcion);
	fclose(arch);

	return 0;
}

int opcionGenerarPagica()
{
    FILE *arch;
    sMovie peli;
    int retorno = 1;
    int flag = 0;

	if ((arch=fopen(ARCHIVO_BIN,"rb")) == NULL) {
        printf("Error. No se puede abrir el archivo binario.");
        return retorno;
	}

    while (!feof(arch)) {
        if (fread(&peli, sizeof(sMovie), 1, arch) != 1) {
            if (feof(arch)) {
                retorno = 0;
                break;
            }
            else {
                printf("Error. No se pudo generar la pagina.");
                break;
            }
        }
        generarPagina(peli, flag);
        flag = 1;
    }
    fclose(arch);

    if (retorno == 0)  printf("Paginca HTML generada correctamente.");

	return retorno;
}

int opcionModificarPeli()
{
    FILE* arch;
    char titulo[20];
    sMovie peli;
    int flag = 0;

    printf("Escriba el titulo de la pelicula a modificar: ");
    fflush(stdin);
    gets(titulo);

    if ((arch=fopen(ARCHIVO_BIN, "rb")) == NULL) {
        printf("Error. No se puede abrir el archivo binario.");
        return 1;
    }

    while (!feof(arch)) {
        if(fread(&peli, sizeof(sMovie), 1, arch) != 1) {
            printf("Error. No se puede leer.");
            return 1;
        }

        if (strcmp(peli.titulo, titulo) == 0) {
            peli = pedirDatosMovie();
            flag = 1;
            fseek ( arch , (long) (-1)*sizeof ( sMovie ) , SEEK_CUR );
            break;
        }
    }
    if (flag == 0) {
        printf("No se encuentra coincidencia.");
        return 0;
    }
    fclose(arch);

    if ((arch=fopen(ARCHIVO_BIN, "ab+")) == NULL) {
        return 1;
    }

    fwrite(&peli,sizeof(sMovie),1,arch);
    fclose(arch);

    return 0;
}


int opcionBorrarPeli()
{
    FILE  *arch, *aux;
	sMovie peli;
	char titulo[20];
	int flag = 0;

    printf("Escriba el titulo de la pelicula a borrar: ");
    fflush(stdin);
    gets(titulo);

	arch = fopen(ARCHIVO_BIN,"rb+");
	aux = fopen(ARCHIVO_DATOS,"wb");

	while (!feof(arch)) {
        if(fread(&peli,sizeof(sMovie),1,arch)!=1) {
            break;
        }
        if(strcmp(peli.titulo, titulo) == 0) {
            flag = 1;
        }
        else {
            fwrite(&peli,sizeof(sMovie),1,aux);
        }
    }
    if (flag == 0) {
        printf("No se encuentra coincidencia.");
        return 0;
    }

    fclose(aux);
    fclose(arch);
    arch=fopen(ARCHIVO_BIN,"wb");
	aux=fopen(ARCHIVO_DATOS,"rb+");

    while(!feof(aux)) {
        if(fread(&peli,sizeof(sMovie),1,aux) != 1) {
                break;
        }
        fwrite(&peli,sizeof(sMovie),1,arch);
    }

    fclose(aux);
    fclose(arch);
    remove(ARCHIVO_DATOS);
    printf("Pelicula borrada correctamente.");

    return 0;
}
