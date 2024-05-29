#include <stdio.h>
#include <diprog.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    string nombre;
    string telefono;
}
contacto;

int main(void) {

    contacto agenda[2];
    
    agenda[0].nombre = "Cesar";
    agenda[0].telefono = "12345";
    agenda[1].nombre = "John";
    agenda[1].telefono = "67890";

        for (int i = 0; i < 2; i++) {
        if (strcmp(agenda[i].nombre, "John") == 0) {
            printf("Encontre a %s, su numero es: %s!\n",agenda[i].nombre, agenda[i].telefono);
            return 0;
        }
    }
    printf("No lo encontre!\n");
    system("pause");
    
    
    }
