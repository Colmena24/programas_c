#include <stdio.h>
#include <stdlib.h>
#include <diprog.h>
// FUNCION PRINCIPAL

int main(void) {

    const int MI_PUNTAJE = 20;
    int puntaje = leer_int("Que puntaje sacaste?  ");
    if (puntaje < MI_PUNTAJE) {
        printf("Sacaste menor puntaje que yo xd\n");
    }   else if (puntaje > MI_PUNTAJE) {
        printf("Sacaste mayor puntaje que yo!!\n");
    }   else {
        printf("Sacamos el mismo puntaje");
    }
    system("pause");
}