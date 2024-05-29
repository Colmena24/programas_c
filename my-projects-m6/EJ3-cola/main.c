#include <stdio.h>
#include <stdlib.h>

// Estructura del nodo de la cola
struct Node {
    int data;
    struct Node* next;
};

// Prototipos de funciones
void enqueue(struct Node** front, struct Node** rear, int data);
int dequeue(struct Node** front, struct Node** rear);
void displayQueue(struct Node* front);
void freeQueue(struct Node** front);

// Función principal
int main() {
    struct Node* front = NULL;
    struct Node* rear = NULL;
    int choice, data;

    do {
        // Mostrar el menú de opciones
        printf("\n*** Menu de opciones ***\n");
        printf("1) Agregar a la cola\n");
        printf("2) Sacar de la cola\n");
        printf("3) Mostrar cola\n");
        printf("4) Liberar cola completa\n");
        printf("0) Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Ingrese el valor a agregar: ");
                scanf("%d", &data);
                enqueue(&front, &rear, data);
                break;
            case 2:
                if (front != NULL) {
                    data = dequeue(&front, &rear);
                    printf("Elemento sacado de la cola: %d\n", data);
                } else {
                    printf("La cola está vacía.\n");
                }
                break;
            case 3:
                displayQueue(front);
                break;
            case 4:
                freeQueue(&front);
                printf("Cola liberada.\n");
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (choice != 0);

    return 0;
}

// Función para agregar un nodo al final de la cola
void enqueue(struct Node** front, struct Node** rear, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Error: Memoria insuficiente para agregar el nodo.\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    if (*rear == NULL) {
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

// Función para tomar un nodo del principio de la cola
int dequeue(struct Node** front, struct Node** rear) {
    int data;
    struct Node* temp = *front;
    if (*front == NULL) {
        return -1; // Cola vacía
    }
    data = temp->data;
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    free(temp);
    return data;
}

// Función para mostrar la cola
void displayQueue(struct Node* front) {
    if (front == NULL) {
        printf("La cola está vacía.\n");
        return;
    }
    printf("La cola es: ");
    while (front != NULL) {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}

// Función para liberar la cola completa
void freeQueue(struct Node** front) {
    struct Node* temp;
    while (*front != NULL) {
        temp = *front;
        *front = (*front)->next;
        free(temp);
    }
}
