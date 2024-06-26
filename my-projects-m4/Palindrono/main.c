#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Función para verificar si un carácter es una letra o un número
int es_letra_o_numero(char c) {
    return isalnum(c);
}

// Función para convertir un carácter a minúscula
char a_minuscula(char c) {
    return tolower(c);
}

// Función para comprobar si una cadena es un palíndromo
int es_palindromo(const char *cadena) {
    int izquierda = 0;
    int derecha = strlen(cadena) - 1;

    while (izquierda < derecha) {
        // Ignorar caracteres no alfanuméricos desde la izquierda
        while (izquierda < derecha && !es_letra_o_numero(cadena[izquierda])) {
            izquierda++;
        }
        // Ignorar caracteres no alfanuméricos desde la derecha
        while (izquierda < derecha && !es_letra_o_numero(cadena[derecha])) {
            derecha--;
        }
        // Comparar caracteres en minúsculas
        if (a_minuscula(cadena[izquierda]) != a_minuscula(cadena[derecha])) {
            return 0; // No es un palíndromo
        }
        izquierda++;
        derecha--;
    }
    return 1; // Es un palíndromo
}

int main() {
    // Casos de prueba
    const char *cadena1 = "A man, a plan, a canal, Panama";
    const char *cadena2 = "No 'x' in Nixon";
    const char *cadena3 = "Hello, World!";
    const char *cadena4 = "racecar";
    const char *cadena5 = "Was it a car or a cat I saw";

    printf("'%s' es palíndromo? %d\n", cadena1, es_palindromo(cadena1));
    printf("'%s' es palíndromo? %d\n", cadena2, es_palindromo(cadena2));
    printf("'%s' es palíndromo? %d\n", cadena3, es_palindromo(cadena3));
    printf("'%s' es palíndromo? %d\n", cadena4, es_palindromo(cadena4));
    printf("'%s' es palíndromo? %d\n", cadena5, es_palindromo(cadena5));

    return 0;
}
