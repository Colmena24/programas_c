#include <stdio.h>
#include <stdlib.h>
#include <diprog.h>
#include <stdbool.h>

int main(int argc, string argv[]) {
        
// Verificar si se han pasado suficientes argumentos
    if (argc < 2) {
        printf("No se han ingresado argumentos.\n");
        return 1;
    }

// Declarar el array de enteros con el tamaño de los argumentos recibidos
    int numeros[argc - 1];

// Convertir los argumentos de cadena a enteros y almacenarlos en el array
    for (int i = 1; i < argc; i++) {
        numeros[i] = convertirEntero(argv[i]);
    }

// Muestra en pantalla los datos ya convertidos a int
    printf("Usted ingreso los siguientes datos: \n\n");
    for (int i = 1; i < argc; i++) {
        printf("#%i Argv[%i]\n", i, numeros[i]);
        }
        printf("\n");

// pedir un numero al usuario        
        int numero = leer_int("Ingrese el numero a buscar dentro del array: \n");
// verificar que el numero este en el array       
        bool estaEnArray = false;
        for (int i = 1; i < argc; i++) {
            if (numeros[i] == numero) {
            estaEnArray = true;
            break;
            }
        }
// Imprimir el resultado de la verificación
    if (estaEnArray) {
        printf("El numero %i esta en el array :)\n", numero);
    } else {
        printf("El numero %i NO esta en el array :(\n", numero);
    }
    return 0;
    system("pause");

}

int convertirEntero(string numStr) {
    /*Valida que sea un numero entero*/
    if (!isdigit(numStr[0])) {
        return -1;
    }
    
    return atoi(numStr); 
}