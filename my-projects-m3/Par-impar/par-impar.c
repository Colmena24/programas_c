#include <stdio.h>
#include <stdlib.h>
#include <diprog.h>

// FUNCION PRINCIPAL

int main(void) {

    printf(" *** PAR - IMPAR *** \n");
    int num = leer_int("Introduzca su numero\n");
    if (num % 2 == 0)    {
        printf("Su numero es par\n");
    } else {
        printf ("Su numero es impar\n");
    }
    printf(" *** *** *** *** *** \n");
    system("pause");
}