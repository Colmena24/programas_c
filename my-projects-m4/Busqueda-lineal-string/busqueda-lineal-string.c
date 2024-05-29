#include <stdio.h>
#include <diprog.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    string nombres [] = {"Gandalf", "Frodo", "Pippin", "Sam", "Merry", "Aragon", "Boromir", "Legolas", "Gimly"};
    
    printf("*** Busqueda lineal de strings ***\n");
    
    for (int i = 0; i < 9; i++) {
        if (strcmp(nombres[i], "Gimly") == 0) {
            printf("Lo encontre\n");
            return 0;
        }
    }
    printf("No lo encontre!\n");
    system("pause");
    }