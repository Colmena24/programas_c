#include <stdio.h>
#include <stdlib.h>

// Estructura de un nodo de la lista
struct Nodo {
    int valor;
    struct Nodo* siguiente;
};

// Función para imprimir los nodos de la lista
void imprimirLista(struct Nodo* inicio) {
    int contador = 1;
    struct Nodo* actual = inicio;
    
    while (actual != NULL) {
        printf("Nodo %d: Valor %d (Direccion actual: %p, Direccion siguiente: %p)\n", contador, actual->valor, (void*)actual, (void*)actual->siguiente);
        actual = actual->siguiente;
        contador++;
    }
}

int main(int argc, char* argv[]) {
    // Verificar si se proporcionaron argumentos
    if (argc < 2) {
        printf("Uso: %s <valores>\n", argv[0]);
        return 1;
    }

    // Inicializar la lista enlazada
    struct Nodo* inicio = NULL;
    struct Nodo* actual = NULL;

    // Crear la lista enlazada con los argumentos
    for (int i = 1; i < argc; i++) {
        int valor = atoi(argv[i]);
        struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
        nuevoNodo->valor = valor;
        nuevoNodo->siguiente = NULL;

        if (actual == NULL) {
            // El primer nodo se convierte en el inicio de la lista
            inicio = nuevoNodo;
            actual = inicio;
        } else {
            // Conectar el nuevo nodo al nodo actual
            actual->siguiente = nuevoNodo;
            actual = nuevoNodo;
        }
    }

    // Imprimir la lista enlazada
    imprimirLista(inicio);

    // Liberar la memoria de los nodos
    while (inicio != NULL) {
        struct Nodo* siguiente = inicio->siguiente;
        free(inicio);
        inicio = siguiente;
    }

    return 0;
}
