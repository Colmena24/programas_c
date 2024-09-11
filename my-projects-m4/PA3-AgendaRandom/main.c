#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estructura de contacto
typedef struct {
    char nombre[50];
    char apellido[50];
    char email[50];
    char telefono[20];
} Contacto;

#define MAX_CONTACTOS 100
Contacto agenda[MAX_CONTACTOS];
int total_contactos = 0;

// Arrays predefinidos de datos
char *nombres[] = {"Carlos", "Ana", "Juan", "Maria", "Luis", "Laura", "Miguel", "Elena", "Javier", "Sara"};
char *apellidos[] = {"Gomez", "Perez", "Lopez", "Martinez", "Rodriguez", "Fernandez", "Garcia", "Diaz", "Ruiz", "Moreno"};
char *emails[] = {"carlos@gmail.com", "ana@hotmail.com", "juan@yahoo.com", "maria@gmail.com", "luis@hotmail.com", 
                  "laura@yahoo.com", "miguel@gmail.com", "elena@hotmail.com", "javier@yahoo.com", "sara@gmail.com"};
char *telefonos[] = {"2231472587", "2233698521", "2239874567", "2235874961", "2235948165", 
                     "2235386482", "2237594275", "2231829468", "2238864572", "2233928176"};

// Función para agregar un contacto manualmente
void agregarContacto() {
    if (total_contactos >= MAX_CONTACTOS) {
        printf("La agenda está llena.\n");
        return;
    }
    
    printf("Ingrese nombre: ");
    scanf("%s", agenda[total_contactos].nombre);
    printf("Ingrese apellido: ");
    scanf("%s", agenda[total_contactos].apellido);
    printf("Ingrese email: ");
    scanf("%s", agenda[total_contactos].email);
    printf("Ingrese teléfono: ");
    scanf("%s", agenda[total_contactos].telefono);
    
    total_contactos++;
    printf("Contacto agregado.\n");
}

// Función para mostrar todos los contactos
void mostrarContactos() {
    if (total_contactos == 0) {
        printf("No hay contactos en la agenda.\n");
        return;
    }

    for (int i = 0; i < total_contactos; i++) {
        printf("Contacto %d:\n", i + 1);
        printf("Nombre: %s\n", agenda[i].nombre);
        printf("Apellido: %s\n", agenda[i].apellido);
        printf("Email: %s\n", agenda[i].email);
        printf("Teléfono: %s\n\n", agenda[i].telefono);
    }
}

// Función para cargar datos de prueba aleatorios
void cargarDatosDePrueba(int cantidad) {
    srand(time(NULL));  // Inicializar la semilla para la generación de números aleatorios

    for (int i = 0; i < cantidad && total_contactos < MAX_CONTACTOS; i++) {
        int idx_nombre = rand() % 10;
        int idx_apellido = rand() % 10;
        int idx_email = rand() % 10;
        int idx_telefono = rand() % 10;

        strcpy(agenda[total_contactos].nombre, nombres[idx_nombre]);
        strcpy(agenda[total_contactos].apellido, apellidos[idx_apellido]);
        strcpy(agenda[total_contactos].email, emails[idx_email]);
        strcpy(agenda[total_contactos].telefono, telefonos[idx_telefono]);

        total_contactos++;
    }
    printf("%d contactos agregados de prueba.\n", cantidad);
}

// Función principal
int main() {
    int opcion;
    int cantidad;

    do {
        printf("\n*** Menu Principal ***\n");
        printf("1) Ver contactos\n");
        printf("2) Agregar contacto\n");
        printf("3) Cargar datos de prueba\n");
        printf("0) Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                mostrarContactos();
                break;
            case 2:
                agregarContacto();
                break;
            case 3:
                printf("Ingrese la cantidad de contactos de prueba a cargar: ");
                scanf("%d", &cantidad);
                cargarDatosDePrueba(cantidad);
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Intente nuevamente.\n");
                break;
        }
    } while (opcion != 0);

    return 0;
}
