#include <stdio.h>

void ordenamientoBurbujeo(int arr[], int n);

int main() {
    int arreglo[] = {5, 2, 7, 1, 3};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);
    int i;

    printf("Arreglo original: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arreglo[i]);
    }

    ordenamientoBurbujeo(arreglo, n);

    printf("\nArreglo ordenado: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arreglo[i]);
    }

    return 0;
}

void ordenamientoBurbujeo(int arr[], int n) {
    int temp;
    int i, j;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Intercambiar elementos
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
