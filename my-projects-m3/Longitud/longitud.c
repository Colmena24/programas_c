#include <stdio.h>
#include <stdlib.h>
#include <diprog.h>
#include <string.h>

// FUNCION PRINCIPAL

int longitud(string s);

int main(void) {

    printf(" *** Longitud *** \n");
    string s = leer_string("Palabra? ");
    int i = strlen(s);
    printf("longitud: %i\n" , i );
    
    
    system("pause");
}

int longitud(string s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    

}