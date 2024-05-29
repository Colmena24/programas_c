#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <diprog.h>

// FUNCION PRINCIPAL

int main(void) {

    printf(" *** Centavos *** \n");

    float pesos = leer_float("Cuantos pesos quieres convertir? \n");
    int centavos = round (pesos * 100);
    printf("El total es de %.2i centavos\n", centavos);
    system("pause");
}