#include <stdio.h>
#include <stdlib.h>

/** \brief Suma dos valores
 *
 * \param sumando 1
 * \param sumando 2
 * \return resultado de la suma de los valores
 *
 */
float suma(float a,float b) {
    return a+b;
}

/** \brief Resta dos valores
 *
 * \param minuendo
 * \param sustraendo
 * \return Resultado de la resta
 *
 */
float resta(float a,float b) {
    return a-b;
}

/** \brief Divide dos valores
 *
 * \param dividendo
 * \param divisor
 * \return Resultado de la divisi�n (cociente)
 *
 */
float division(float a,float b) {
    if (b == 0) return 0;

    return a/b;
}

/** \brief Multiplica dos valores
 *
 * \param factor 1
 * \param factor 2
 * \return Resultado de la multiplicaci�n
 *
 */
float multiplicacion(float a,float b) {
    return a*b;
}

/** \brief Calcula el factorial de un valor
 *
 * \param n�mero
 * \return Factorial del n�mero
 *
 */
int factorial(int num) {
    int i;
    int resultado = 1;
    for (i=num; i>0; i--) {
        resultado *= i;
    }
    return resultado;
}

/** \brief Solicita un n�mero y devuelve el resultado
 *
 * \param Mensaje a ser mostrado
 * \return N�mero ingresado
 *
 */
float getFloat(char mensaje[]) {
    float num;
    printf("%s", mensaje);
    scanf("%f", &num);
    return num;
}
