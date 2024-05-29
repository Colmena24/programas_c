#include <stdio.h>
#include <stdlib.h>
#include <diprog.h>


int convertirEntero(string numStr);
// FUNCION PRINCIPAL

int main(int argc, string argv[]) {
    int total = 0;
    int count = 0;

    for (int i = 1; i < argc; i++) {
        int num = convertirEntero(argv[i]);

        if (num == -1) {
            printf("El numero ingresado '%s' no es un 'int' valido.\n", argv[i]);
            return 1;
        }

        total += num;
        count++;
    }

    if (count > 0) {
        float promedio = (float)total / count;
        printf("El promedio de los numeros es: %.2f\n", promedio);
    } else {
        printf("No se han ingresado numeros enteros como argumentos.\n");
    }

    return 0;

}

int convertirEntero(string numStr) {
    /*Valida que sea un numero entero*/
    if (!isdigit(numStr[0])) {
        return -1;
    }
    
    return atoi(numStr); 
}