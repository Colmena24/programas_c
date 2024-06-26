#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "lista_precios.txt"
#define TEMP_FILENAME "temp_lista_precios.txt"

typedef struct {
    int codigo;
    char nombre[50];
    float precio;
} Producto;

void ver_lista_precios() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No se puede abrir el archivo.\n");
        return;
    }

    Producto p;
    printf("Lista de precios:\n");
    while (fread(&p, sizeof(Producto), 1, file)) {
        printf("Codigo: %d, Nombre: %s, Precio: %.2f\n", p.codigo, p.nombre, p.precio);
    }

    fclose(file);
}

void agregar_producto() {
    FILE *file = fopen(FILENAME, "ab");
    if (file == NULL) {
        printf("No se puede abrir el archivo.\n");
        return;
    }

    Producto p;
    printf("Ingrese el codigo del producto: ");
    scanf("%d", &p.codigo);
    printf("Ingrese el nombre del producto: ");
    scanf("%s", p.nombre);
    printf("Ingrese el precio del producto: ");
    scanf("%f", &p.precio);

    fwrite(&p, sizeof(Producto), 1, file);
    fclose(file);
    printf("Producto agregado exitosamente.\n");
}

void buscar_producto() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No se puede abrir el archivo.\n");
        return;
    }

    int codigo;
    printf("Ingrese el codigo del producto a buscar: ");
    scanf("%d", &codigo);

    Producto p;
    int encontrado = 0;
    while (fread(&p, sizeof(Producto), 1, file)) {
        if (p.codigo == codigo) {
            printf("Producto encontrado:\n");
            printf("Codigo: %d, Nombre: %s, Precio: %.2f\n", p.codigo, p.nombre, p.precio);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Producto no encontrado.\n");
    }

    fclose(file);
}

void eliminar_producto() {
    FILE *file = fopen(FILENAME, "r");
    FILE *tempFile = fopen(TEMP_FILENAME, "w");
    if (file == NULL || tempFile == NULL) {
        printf("No se puede abrir el archivo.\n");
        return;
    }

    int codigo;
    printf("Ingrese el codigo del producto a eliminar: ");
    scanf("%d", &codigo);

    Producto p;
    int encontrado = 0;
    while (fread(&p, sizeof(Producto), 1, file)) {
        if (p.codigo == codigo) {
            encontrado = 1;
        } else {
            fwrite(&p, sizeof(Producto), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove(FILENAME);
    rename(TEMP_FILENAME, FILENAME);

    if (encontrado) {
        printf("Producto eliminado exitosamente.\n");
    } else {
        printf("Producto no encontrado.\n");
    }
}

int main() {
    int opcion;

    do {
        printf("\nMenu principal:\n");
        printf("1) Ver lista de precios\n");
        printf("2) Agregar un producto a la lista de precios\n");
        printf("3) Buscar producto\n");
        printf("4) Eliminar producto\n");
        printf("0) Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ver_lista_precios();
                break;
            case 2:
                agregar_producto();
                break;
            case 3:
                buscar_producto();
                break;
            case 4:
                eliminar_producto();
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
    } while (opcion != 0);

    return 0;
}
