#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int numeros [] = {2, 5, 1, 4, 8, 6, 3, 7};
    printf("*** Busqueda lineal ***\n");
    for (int i = 0; i < 7; i++){
        if (numeros[i] == 3)
        {
            printf("Lo encontre\n");
            return 0;
        }
        

    }
    printf("No lo encontre!\n");
    system("pause");
    }