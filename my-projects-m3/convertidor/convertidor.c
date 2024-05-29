#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

int convertirDigito(char digito);


int main(void) {
    
    char c0 = '0';
    char c1 = '1';
    char c9 = '9';

    printf("%c = % i\n", c0 , c0);
    printf("%c = % i\n", c1 , c1);
    printf("%c = % i\n", c9 , c9);
    printf("\n");
    printf("%c = % i\n", c0 , convertirDigito(c0));
    printf("%c = % i\n", c1 , convertirDigito(c1));
    printf("%c = % i\n", c9 , convertirDigito(c9));
    printf("%c = % i\n", 'a' , convertirDigito('a'));
    system("pause");
    }

int convertirDigito(char digito){
    if (!(digito >= '0' && digito <= '9')) {
        return -1;
    }
    return digito - 48;
}