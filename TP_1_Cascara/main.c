#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int hayOperandos(int, int);

int main()
{
    int salir=0;
    int opcion;
    int flag1 = 0;
    int flag2 = 0;
    float operandoUno;
    float operandoDos;

    do
    {
        if (flag1 == 0)
            printf("\n\n1- Ingresar 1er operando (A)\n");
        else
            printf("\n\n1- Reingresar 1er operando (A=%.2f)\n", operandoUno);
        if (flag2 == 0)
            printf("2- Ingresar 2do operando (B)\n");
        else
            printf("2- Reingresar 2do operando (B=%.2f)\n", operandoDos);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                operandoUno = getFloat("Ingrese el primer operando: ");
                flag1 = 1;
                break;
            case 2:
                operandoDos = getFloat("Ingrese el segundo operando: ");
                flag2 = 1;
                break;
            case 3: // suma
                if (hayOperandos(flag1, flag2)) {
                    printf("\n Suma: %.2f + %.2f = %.2f ", operandoUno, operandoDos, suma(operandoUno, operandoDos));
                }
                break;
            case 4: // resta
                if (hayOperandos(flag1, flag2)) {
                    printf("\n Resta: %.2f - %.2f = %.2f", operandoUno, operandoDos, resta(operandoUno, operandoDos));
                }
                break;
            case 5: //division
                if (hayOperandos(flag1, flag2)) {
                    if (operandoDos == 0) {
                        printf("Error. El divisor no puede ser cero.");
                    }
                    else {
                        printf("\n Division: %.2f : %.2f = %.2f", operandoUno, operandoDos, division(operandoUno, operandoDos));
                    }
                }
                break;
            case 6: // multiplicacion
                if (hayOperandos(flag1, flag2)) {
                    printf("\n Multiplicacion: %.2f x %.2f = %.2f", operandoUno, operandoDos, multiplicacion(operandoUno, operandoDos));
                }
                break;
            case 7: // factorial
                if (flag1 == 1) {
                    printf("\n Factorial de A: %d", factorial((int)operandoUno));
                }
                else {
                    printf("\n Error. Ingrese el operando A");
                }
                break;
            case 8:
                if (hayOperandos(flag1, flag2)) {
                    printf("Operando A: %.2f -- Operando B: %.2f", operandoUno, operandoDos);
                    printf("\n Suma: %.2f ", suma(operandoUno, operandoDos));
                    printf("\n Resta: %.2f ", resta(operandoUno, operandoDos));
                    if (operandoDos == 0) {
                        printf("\n Division: No se puede dividir por cero.");
                    }
                    else {
                        printf("\n Division: %.2f ", division(operandoUno, operandoDos));
                    }
                    printf("\n Multiplicacion: %.2f", multiplicacion(operandoUno, operandoDos));
                    printf("\n Factorial de A: %d", factorial((int)operandoUno));
                }
                break;
            case 9:
                salir = 1;
                break;
        }
    }while(salir==0);

    return 0;
}

int hayOperandos(int flag1, int flag2) {
    if (flag1 + flag2 == 2)
        return 1;

    printf("\n Error. Ingrese los dos operandos antes de operar.");
    return 0;
}
