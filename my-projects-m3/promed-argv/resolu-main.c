#include <stdio.h>
#include <diprog.h>
#include <string.h>

int convertirEntero(string numStr);
int convertirDigito(char digito);


int main(int argc, string argv[])
{
        
    int suma = 0;
    // Convertir cada nota
    // Inicio el bucle en 1, para saltearme el primer argumento que se corresponde al nombre del programa
    for (int i = 1;  i < argc; i++) { 
        int res = convertirEntero(argv[i]);
        if (res < 0) {
            // Hubo un error, posiblemente porque el número ingresado no es un numero entero válido
            printf("El número ingresado (%s) no es un 'int' válido.\n", argv[i]);
            return 1;
        }
        suma += res;
    }

    // Calcular promedio
    float prom = (float) suma / (argc-1);

    printf("El promedio de las notas es: %f\n", prom);
}


/**
 * Convierte el string pasado en el parametro num as su correspondinete valor entero.
 * Valida que sea realmente un número
 */
int convertirEntero(string numStr)
{
    // Obtener la longitud del string
    int longitud = strlen(numStr);

    // inicializar variable sumadora del valor de cada dígito.
    int suma = 0;

    // inicializar valor posicional de los dígitos. Iniciamos en las unidades, valor = 1.
    int valorPos = 1;

    // Recorrer la cadena de caracteres como array de manera inversa, es decir desde
    // el último dígito que representa las unidades, hasta el primero.
    for (int i = longitud-1; i >= 0; i--) {
        
        // Convertimos el digito a su representacion int
        int digito = convertirDigito(numStr[i]);
        if (digito == -1) {
            // Hubo un error!
            return -1;
        }

        // Calcular el valor del dígito        
        int valorDigito;
        if (i == longitud-1) {
            // Estamos en el útlimo dígito, correspondiente a las unidades.
            // En las unidades no es necesario calcular ni adicionar valor posicional.
            valorDigito = digito;            
        } else {
            valorDigito = digito * valorPos;
        }

        // Adicionar a la suma el valor que corresponde al dígito en cuestión
        suma += valorDigito;

        // Recalcular el próximo valor posicional
        valorPos *= 10;

        //printf("digito = %i - valorDigito = %i - suma = %i\n", digito, valorDigito, suma);

    }

    return suma;
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