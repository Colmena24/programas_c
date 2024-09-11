#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100  // Definimos un número máximo de contactos

// Definimos la estructura para los contactos
struct Contact {
    char nombre[50];
    char apellido[50];
    char email[50];
    char telefono[20];
};

// Función para agregar un nuevo contacto
void agregarContacto(struct Contact *agenda, int *totalContactos) {
    if (*totalContactos >= MAX_CONTACTS) {
        printf("La agenda está llena. No se pueden agregar más contactos.\n");
        return;
    }

    printf("Ingrese el nombre: ");
    scanf("%s", agenda[*totalContactos].nombre);
    printf("Ingrese el apellido: ");
    scanf("%s", agenda[*totalContactos].apellido);
    printf("Ingrese el email: ");
    scanf("%s", agenda[*totalContactos].email);
    printf("Ingrese el teléfono: ");
    scanf("%s", agenda[*totalContactos].telefono);

    (*totalContactos)++;  // Incrementamos el número de contactos en la agenda
    printf("Contacto agregado correctamente.\n");
}

// Función para mostrar todos los contactos existentes
void mostrarContactos(struct Contact *agenda, int totalContactos) {
    if (totalContactos == 0) {
        printf("No hay contactos en la agenda.\n");
        return;
    }

    printf("\n--- Lista de Contactos ---\n");
    for (int i = 0; i < totalContactos; i++) {
        printf("Contacto %d:\n", i + 1);
        printf("Nombre: %s\n", agenda[i].nombre);
        printf("Apellido: %s\n", agenda[i].apellido);
        printf("Email: %s\n", agenda[i].email);
        printf("Teléfono: %s\n", agenda[i].telefono);
        printf("-------------------------\n");
    }
}

// Función principal (main)
int main() {
    struct Contact agenda[MAX_CONTACTS];
    int totalContactos = 0;
    int opcion;

    do {
        printf("\n*** Menu Principal ***\n");
        printf("1) Agregar un contacto a la agenda\n");
        printf("2) Mostrar los contactos existentes\n");
        printf("0) Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarContacto(agenda, &totalContactos);
                break;
            case 2:
                mostrarContactos(agenda, totalContactos);
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Intente nuevamente.\n");
        }
    } while (opcion != 0);

    return 0;
}
