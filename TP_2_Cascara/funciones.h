#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[33];
    int edad;
    int estado;
    int dni;

}ePersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @param tamaño del array
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(ePersona[], int);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param tamaño del array
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(ePersona[], int, int);

/** \brief Inicializa el estado en 0 de todas las celdas
 *
 * \param array que se pasa como parametro
 * \param tamaño del array
 *
 */
void inicializarPersonas(ePersona[], int);

/** \brief pide y guarda nombre, edad, dni y pone estado en 1
 *
 * \param array que se pasa como parametro
 * \param tamaño del array
 * \param lugar del array para guardar los datos
 *
 */
void pedirYGuardarDatos(ePersona[], int, int);

/** \brief ordena el array por orden alfabético
 *
 * \param array que se pasa como parametro
 * \param tamaño del array
 *
 */
void ordenarPorNombre(ePersona[], int);

/** \brief muestra la lista con nombre, edad y dni
 *
 * \param array que se pasa como parametro
 * \param tamaño del array
 *
 */
void mostrarLista(ePersona[], int);

/** \brief muestra el grafico de tres barras
 *
 * \param primera barra
 * \param segunda barra
 * \param tercer barra
 *
 */
void mostrarGrafico(int, int, int);

/** \brief obtiene la cantidad de personas con edad entre los parametros indicados del array que se pasa
 *
 * \param array que se pasa como parametro
 * \param tamaño del array
 * \param edad minima para contar
 * \param edad maxima para contar
 * \return cantidad de personas con edad entre las indicadas
 *
 */
int cantidadEdades(ePersona[], int, int, int);
#endif // FUNCIONES_H_INCLUDED
