#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf(" *** ***Array con malloc*** *** \n");

    // int lista[3];
    int *lista = malloc(3 * sizeof(int));
    if (lista == NULL) {
        return 1;
    }
    

    lista[0] = 1;
    lista[1] = 2;
    lista[2] = 3;

    // ..
    // ..
    int *tmp = malloc(4 * sizeof(int));
    if (tmp == NULL) {
        free(lista);
        return 1;
    }

    for (int i = 0; i < 3; i++) {
        tmp[i] = lista[i];
    }
    tmp[3] = 4;
    free(lista);
    lista = tmp;


    for (int i = 0; i < 4; i++) {
        printf("%i.\n", lista[i]);
    }
    system("pause");
    }