#include <stdio.h>
#include <stdlib.h>
#include <diprog.h>

// FUNCION PRINCIPAL

int main(void) {

    // pedirle al usuario el tamaño(ancho y alto) de la pared a imprimir
    // validar que sea un num entre 1 y 80
    int ancho = 0;
    int alto = 0;
    do {
        alto = leer_int("Defina su alto: \n");
        ancho = leer_int("Defina su ancho: \n");
    } while (alto <=0 || alto > 24 , ancho <= 0 || ancho > 80);
    
    // por cada columna, ponemos una nueva linea de ladrillos
    for (int j = 0; j < alto; j++) {
        // por cada columna, poner ladrillo
        for (int i = 0; i < ancho; i++) {
        // imprimir un ladrillo
        printf("#");
    }
    //final de pantalla, movernos a la siguiente fila
    printf("\n");    
    }
    system("pause");
}