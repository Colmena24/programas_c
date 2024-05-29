#include <stdio.h>
#include <stdlib.h>
#include <diprog.h>

// FUNCION PRINCIPAL

int main(void) {

    // pedirle al usuario el tamaño de la pared a imprimir
    // validar que sea un num entre 1 y 80
    int tamano = 0;
    do {
        tamano = leer_int("Defina su tamano: \n");
    } while (tamano <=0 || tamano > 80);
    
    // por cada fila, ponemos una nueva linea de ladrillos
    for (int j = 0; j < tamano; j++) {
        // por cada columna, poner ladrillo
        for (int i = 0; i < tamano; i++) {
        // imprimir un ladrillo
        printf("#");
    }
    //final de pantalla, movernos a la siguiente fila
    printf("\n");    
    }
    system("pause");
}