#include <stdio.h>
#include <stdlib.h>

void miau(int n) {

    for (int i = 0; i < n; i++){
        printf("Miau!!\n");
    }
        
}
// FUNCION PRINCIPAL

int main(void) {

    miau(50);
    system("pause");
}