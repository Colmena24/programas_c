#include <stdio.h>
#include <stdlib.h>
#include <diprog.h>
// FUNCION PRINCIPAL

int main(void) {

    printf(" *** SUMAR 2 NUMEROS ENTEROS *** \n");
    int a = leer_int("Ingrese el primer numero: ");
    int b = leer_int("Ingrese el segundo numero: ");
    int resultado = a + b;
    printf("El resultado de %i + %i = %i\n", a, b, resultado);
    system("pause");
}