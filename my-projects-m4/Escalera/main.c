#include <stdio.h>
#include <diprog.h>
#include <stdlib.h>

void dibujar(int n);

int main(void) {
    int escalones = leer_int("Altura? ");

    dibujar (escalones);
    system("pause");
    }

    void dibujar(int n){

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                printf("#");
            }
            printf("\n");            
        }
        
    }