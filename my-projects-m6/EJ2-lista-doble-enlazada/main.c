#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nodo {
    int valor;
    struct Nodo* siguiente;
    struct Nodo* anterior;
};

struct Nodo* crearNodo(int valor) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = NULL;
    nuevoNodo->anterior = NULL;
    return nuevoNodo;
}

void imprimirLista(struct Nodo* inicio) {
    struct Nodo* temp = inicio;
    printf("Lista: ");
    while (temp != NULL) {
        printf("%d ", temp->valor);
        temp = temp->siguiente;
    }
    printf("\n");
}

void buscarValor(struct Nodo* inicio, int valor) {
    struct Nodo* temp = inicio;
    while (temp != NULL) {
        if (temp->valor == valor) {
            printf("Valor %d encontrado en la dirección de memoria %p\n", valor, temp);
            return;
        }
        temp = temp->siguiente;
    }
    printf("Valor %d no encontrado en la lista.\n", valor);
}

void eliminarValor(struct Nodo** inicio, int valor) {
    struct Nodo* temp = *inicio;
    while (temp != NULL) {
        if (temp->valor == valor) {
            if (temp->anterior != NULL) {
                temp->anterior->siguiente = temp->siguiente;
            }
            if (temp->siguiente != NULL) {
                temp->siguiente->anterior = temp->anterior;
            }
            free(temp);
            printf("Valor %d eliminado de la lista.\n", valor);
            return;
        }
        temp = temp->siguiente;
    }
    printf("Valor %d no encontrado en la lista.\n", valor);
}

void eliminarLista(struct Nodo** inicio) {
    struct Nodo* temp;
    while (*inicio != NULL) {
        temp = *inicio;
        *inicio = (*inicio)->siguiente;
        free(temp);
    }
    printf("Lista eliminada.\n");
}

int main() {
    struct Nodo* inicio = NULL;
    int opcion, valor;

    do {
        printf("\n----- Menu Principal -----\n");
        printf("1) Mostrar lista\n");
        printf("2) Buscar valor\n");
        printf("3) Eliminar valor\n");
        printf("4) Eliminar lista completa\n");
        printf("0) Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                imprimirLista(inicio);
                break;
            case 2:
                printf("Ingrese el valor a buscar: ");
                scanf("%d", &valor);
                buscarValor(inicio, valor);
                break;
            case 3:
                printf("Ingrese el valor a eliminar: ");
                scanf("%d", &valor);
                eliminarValor(&inicio, valor);
                break;
            case 4:
                eliminarLista(&inicio);
                break;
            case 0:
                printf("Ha finalizado con éxito.\n");
                break;
            default:
                printf("Opción no válida. Intente nuevamente.\n");
        }
    } while (opcion != 0);

    return 0;
}