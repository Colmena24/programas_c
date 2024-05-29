#include <stdio.h>
#include <stdlib.h>
#include <diprog.h>
#include <limits.h>

int convertirEntero(string numStr);

int main(void)
{
    printf("*** *** Convierte tu string a entero *** ***\n");
    /*pedir no 1, sino 2 numeros enteros*/
    string s = leer_string ("Introduzca un numero entero: ");
    string c = leer_string ("Introduzca un segundo entero: ");
    /* Aca simplemente no hace nada, solo muestra
    /* el string y su valor en entero sin uso
    /* de la funcion */
    printf("El %s es = %i\n", s , s );
    printf("El %s es = %i\n", c , c );  
    /* separamos*/
    printf("--------------\n");
    /* Aca se implementa el uso de la funcion convertirEntero
    /* dando como resultado el numero correspondiente
    */
    printf("El %s es = %i\n", s , convertirEntero(s) );
    printf("El %s es = %i\n", c , convertirEntero(c) );
    system("pause");
    }

int convertirEntero(string numStr) {
    /*Valida que sea un numero entero*/
    if (!isdigit(numStr[0])) {
        return -1;
    }
    
    return atoi(numStr); 
}