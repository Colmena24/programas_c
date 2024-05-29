#include <stdio.h>
#include <stdlib.h>

int main(void){
    int escalones = leer_int("Ingrese la altura deseada: \n");
    dibujar(escalones);
    }

void dibujar(int n){
    //condicion de salida
    if (n <= 0) {
        return;
    }
    dibujar(n-1);
    //dibujar la fila actual
    for (int i = 0; i < n; i++)
    {
        printf("##");
    }
    printf("\n");
}