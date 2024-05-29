#include <stdio.h>

int convertirDigito(char digito);

int main(void)
{

    char c0 = '0';
    char c1 = '1';
    char c9 = '9';

    printf("%c = %i\n", c0, c0);
    printf("%c = %i\n", c1, c1);
    printf("%c = %i\n", c9, c9);
    printf("\n");
    printf("%c = %i\n", c0, convertirDigito(c0));
    printf("%c = %i\n", c1, convertirDigito(c1));
    printf("%c = %i\n", c9, convertirDigito(c9));
    printf("%c = %i\n", 'a', convertirDigito('a'));

}

/**
 * Convierte un character del '0' al '9' en su valor entero.
 * Si el caracter ingresado no es un numero, devuelve -1.
 */
int convertirDigito(char digito)
{
    // Validar que sea realmente un caracter que representa a un digito del 0 al 9.
    if (!(digito >= '0' && digito <= '9')) {
        return -1;
    }

    return digito - 48;
}
