#include <stdio.h>
#include <stdlib.h>
#include <diprog.h>

int main(void)
{
    string nombre = leer_string("Cual es tu nombre?\n");
    printf("Hola, %s!\n", nombre);
    system("pause");
    }