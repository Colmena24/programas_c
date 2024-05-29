#include <stdio.h>
#include <stdlib.h>

void imprimirArreglo(int arr[], int n);
void ordenamientoSeleccion(int arr[], int n);

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        printf("Ingrese un numero entero como argumento.\n");
        return 1;
    }

    int n = argc - 1;
    int *arreglo = (int *)malloc(n * sizeof(int));

    printf("Arreglo original:\n");
    for (int i = 1; i <= n; i++) {
        arreglo[i - 1] = atoi(argv[i]);
        printf("Posicion %i: %i\n", i, arreglo[i - 1]);
    }

    ordenamientoSeleccion(arreglo, n);

    printf("\nArreglo ordenado de mayor a menor:\n\n");
    imprimirArreglo(arreglo, n);

    free(arreglo);

    return 0;
}

void imprimirArreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void ordenamientoSeleccion(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[maxIndex];
        arr[maxIndex] = temp;
    }
}
