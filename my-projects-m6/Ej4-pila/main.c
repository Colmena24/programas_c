#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo de la pila
struct Node {
    int data;
    struct Node* next;
};

// Función para inicializar una pila vacía
struct Node* initializeStack() {
    return NULL;
}

// Función para verificar si la pila está vacía
int isEmpty(struct Node* top) {
    return top == NULL;
}

// Función para agregar un elemento al tope de la pila
void push(struct Node** top, int value) {
    // Crear un nuevo nodo
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Error: No se pudo asignar memoria para el nuevo nodo.\n");
        return;
    }

    // Establecer el valor del nuevo nodo
    newNode->data = value;

    // Establecer el siguiente del nuevo nodo al actual tope de la pila
    newNode->next = *top;

    // Establecer el nuevo nodo como el nuevo tope de la pila
    *top = newNode;

    printf("Elemento %d agregado a la pila.\n", value);
}

// Función para sacar el tope de la pila
void pop(struct Node** top) {
    if (isEmpty(*top)) {
        printf("Error: La pila esta vacia. No se puede sacar ningun elemento.\n");
        return;
    }

    // Guardar el nodo a eliminar
    struct Node* temp = *top;

    // Establecer el tope de la pila al siguiente nodo
    *top = (*top)->next;

    // Liberar la memoria del nodo eliminado
    free(temp);

    printf("Elemento sacado de la pila.\n");
}

// Función para mostrar todos los elementos de la pila
void display(struct Node* top) {
    if (isEmpty(top)) {
        printf("La pila esta vacia.\n");
        return;
    }

    struct Node* current = top;
    printf("Elementos de la pila: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Función para liberar todos los nodos de la pila
void clear(struct Node** top) {
    while (*top != NULL) {
        struct Node* temp = *top;
        *top = (*top)->next;
        free(temp);
    }
    printf("Pila liberada.\n");
}

// Función principal
int main() {
    struct Node* top = initializeStack(); // Inicializar la pila

    int option, value;

    do {
        // Mostrar el menú
        printf("\n*** Menu de opciones ***\n");
        printf("1) Mostrar pila\n");
        printf("2) Agregar a la pila\n");
        printf("3) Sacar tope\n");
        printf("4) Liberar pila completa\n");
        printf("0) Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &option);

        // Realizar la acción correspondiente según la opción seleccionada
        switch (option) {
            case 1:
                display(top);
                break;
            case 2:
                printf("Ingrese el valor a agregar: ");
                scanf("%d", &value);
                push(&top, value);
                break;
            case 3:
                pop(&top);
                break;
            case 4:
                clear(&top);
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida. Intente nuevamente.\n");
        }
    } while (option != 0);

    return 0;
}
