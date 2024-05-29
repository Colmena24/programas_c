#include <stdio.h>
#include <stdlib.h>
#include <diprog.h>

// FUNCION PRINCIPAL

int main(void) {

    printf(" *** Promedio *** \n");
    
    int cantNotas = leer_int("Cuantas notas? ");

    int notas[cantNotas];

    for (int i = 0; i < cantNotas; i++) {
        notas[i] = leer_int("Nota? ");
    }
    
    int total = 0;
    for (int j = 0; j < cantNotas; j++) {
        total += notas[j];
    }
    
    printf("El promedio es: %f\n", total / (float) cantNotas);
    system("pause");
}