#include <stdio.h>
#include <stdlib.h>
#include <diprog.h>

// FUNCION PRINCIPAL

int main(void) {

    printf(" *** Estamos de acuerdo, o no? *** \n\n");

    char c = leer_char("Estamos de acuerdo??\n\n ");
    if (c == 's' || c == 'S' ){
        printf("Estamos de acuerdo <3\n\n");
         printf(" *** *** *** *** *** \n\n");
    } else if (c == 'n' || c == 'N'){
        printf("Jamas pense que algun dia ibamos a estar en desacuerdo :c\n\n");
        printf(" *** *** *** *** *** *** *** *** *** *** *** *** *** ***\n\n");
    }
    
    system("pause");
}