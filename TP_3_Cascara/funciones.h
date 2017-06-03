#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[100];
}sMovie;

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(sMovie movie);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(sMovie movie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param movie la estructura a ser agregada al archivo html
 *  @param flag 0 = solo escribir 1 = agregar a lo escrito
 */
int generarPagina(sMovie movie, int flag);

/** \brief Opcion para agregar peliculas
 *
 * \return retorna 1 o 0 de acuerdo si pudo realizar la opcion o no
 *
 */
int opcionAgregarPeli();

/** \brief Opcion para generar la pagina de la lista de peliculas
 *
 * \return retorna 1 o 0 de acuerdo si pudo realizar la opcion o no
 *
 */
int opcionGenerarPagica();

/** \brief Opcion para borrar una pelicula
 *
 * \return retorna 1 o 0 de acuerdo si pudo realizar la opcion o no
 *
 */
int opcionBorrarPeli();

/** \brief Opcion para modificar una pelicula
 *
 * \return retorna 1 o 0 de acuerdo si pudo realizar la opcion o no
 *
 */
int opcionModificarPeli();

sMovie pedirDatosMovie();
#endif // FUNCIONES_H_INCLUDED
