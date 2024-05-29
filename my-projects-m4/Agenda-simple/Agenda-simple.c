#include <stdio.h>
#include <diprog.h>
#include <string.h>
#include <stdlib.h>

int main(void) {

    string nombres[] = {"Cesar", "John"};
    string telefonos[] = {"12345", "67890"};

        for (int i = 0; i < 2; i++) {
        if (strcmp(nombres[i], "John") == 0) {
            printf("Lo encontre, su numero es: %s!\n", telefonos[i]);
            return 0;
        }
    }
    printf("No lo encontre!\n");
    system("pause");
    
    
    }
