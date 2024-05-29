#include <stdio.h>
#include <stdlib.h>
#include <diprog.h>

long factorial(int n);

int main() {
    int num = leer_int("Ingrese un numero entero: ");

    if (num < 0) {
        printf("El factorial no está definido para números negativos.\n");
    } else {
        long result = factorial(num);
        printf("El factorial de %i es %ld\n", num, result);
    }
    return 0;
}

long factorial(int n) {
    if (n <= 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}