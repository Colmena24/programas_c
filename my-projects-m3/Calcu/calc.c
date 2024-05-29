#include <stdio.h>
#include "../../librerias/diprog/diprog.h"

// Función principal de nuestro programa sumador!
int main(void)
{
    printf("*** Sumar 2 números enteros ***\n");
    int a = leer_int("Ingrese numero 1: ");
    int b = leer_int("Ingrese numero 2: ");
    int resultado = a + b;    
    printf("La suma de %i + %i = %i\n", a, b, resultado);
}