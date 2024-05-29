#include <stdio.h>
#include <stdlib.h>
#include <diprog.h>
#include <string.h>
#include <ctype.h>

// FUNCION PRINCIPAL

int main(void) {
    printf(" *** Minus-Mayus *** \n");
    
    string s = leer_string("Said a word! \n");

    int l = strlen(s);
    for (int i = 0; i < l; i++ ) {
        /* if (s[i] >='a' && s[i] <='z') {*/
        if (islower(s[i])){
        printf("%c", s[i] - 32);
        } else {
            printf("%c", s[i]);
        }
        
    }
    printf("Thanks!\n");
    system("pause");

}
