#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50

typedef struct Nodo {
    char palabra[MAX_WORD_LENGTH];
    struct Nodo *siguiente;
} Nodo;

// Función para crear un nuevo nodo
Nodo* crear_nodo(const char* palabra) {
    Nodo* nuevo_nodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevo_nodo) {
        strncpy(nuevo_nodo->palabra, palabra, MAX_WORD_LENGTH);
        nuevo_nodo->siguiente = NULL;
    }
    return nuevo_nodo;
}

// Función para insertar un nodo al final de la lista
void insertar_nodo(Nodo** cabeza, const char* palabra) {
    Nodo* nuevo_nodo = crear_nodo(palabra);
    if (!nuevo_nodo) {
        printf("Error al crear un nuevo nodo.\n");
        return;
    }
    if (*cabeza == NULL) {
        *cabeza = nuevo_nodo;
    } else {
        Nodo* temp = *cabeza;
        while (temp->siguiente) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo_nodo;
    }
}

// Función para buscar una palabra en la lista
int buscar_palabra(Nodo* cabeza, const char* palabra) {
    Nodo* temp = cabeza;
    while (temp) {
        if (strcmp(temp->palabra, palabra) == 0) {
            return 1;
        }
        temp = temp->siguiente;
    }
    return 0;
}

// Función para liberar la memoria de la lista
void liberar_lista(Nodo* cabeza) {
    Nodo* temp;
    while (cabeza) {
        temp = cabeza;
        cabeza = cabeza->siguiente;
        free(temp);
    }
}

// Función para cargar el diccionario desde un archivo
void cargar_diccionario(const char* palabras_espanol, Nodo** cabeza) {
    FILE* archivo = fopen(palabras_espanol, "r");
    if (!archivo) {
        printf("No se pudo abrir el archivo %s\n", palabras_espanol);
        return;
    }

    char palabra[MAX_WORD_LENGTH];
    while (fgets(palabra, sizeof(palabra), archivo)) {
        // Eliminar el salto de línea al final de la palabra
        palabra[strcspn(palabra, "\n")] = '\0';
        insertar_nodo(cabeza, palabra);
    }
    fclose(archivo);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Uso: %s <ruta_al_archivo_de_diccionario>\n", argv[0]);
        return 1;
    }

    const char* palabras_espanol = argv[1];
    Nodo* diccionario = NULL;

    // Cargar el diccionario desde el archivo
    cargar_diccionario(palabras_espanol, &diccionario);
    if (!diccionario) {
        printf("No se cargó ninguna palabra en el diccionario.\n");
        return 1;
    }

    char palabra[MAX_WORD_LENGTH];
    while (1) {
        printf("Ingrese una palabra (o presione Enter para salir): ");
        if (!fgets(palabra, sizeof(palabra), stdin)) {
            break;
        }

        // Eliminar el salto de línea al final de la palabra
        palabra[strcspn(palabra, "\n")] = '\0';

        if (strlen(palabra) == 0) {
            break;
        }

        if (buscar_palabra(diccionario, palabra)) {
            printf("La palabra '%s' es válida.\n", palabra);
        } else {
            printf("La palabra '%s' no es válida.\n", palabra);
        }
    }

    // Liberar la memoria de la lista
    liberar_lista(diccionario);
    return 0;
}
