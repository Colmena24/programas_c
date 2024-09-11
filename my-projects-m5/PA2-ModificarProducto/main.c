#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "productos.txt"

typedef struct {
    char codigo[20];
    char nombre[50];
    float precio;
} Producto;

void mostrarMenu() {
    printf("\n*** Menu Principal ***\n");
    printf("1) Ver lista de precios\n");
    printf("2) Agregar un producto a la lista de precios\n");
    printf("3) Buscar producto\n");
    printf("4) Eliminar producto\n");
    printf("5) Modificar producto\n");
    printf("0) Salir\n");
}

void verListaPrecios() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No se encontró el archivo de la lista de precios.\n");
        return;
    }

    Producto prod;
    printf("\nLista de Precios:\n");
    while (fscanf(file, "%s %s %f", prod.codigo, prod.nombre, &prod.precio) != EOF) {
        printf("Código: %s\n", prod.codigo);
        printf("Nombre: %s\n", prod.nombre);
        printf("Precio: %.2f\n", prod.precio);
        printf("-----------------------\n");
    }

    fclose(file);
}

void agregarProducto() {
    Producto prod;
    printf("Ingrese el código del producto: ");
    scanf("%s", prod.codigo);
    printf("Ingrese el nombre del producto: ");
    scanf("%s", prod.nombre);
    printf("Ingrese el precio del producto: ");
    scanf("%f", &prod.precio);

    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    fprintf(file, "%s %s %.2f\n", prod.codigo, prod.nombre, prod.precio);
    printf("Producto agregado correctamente.\n");

    fclose(file);
}

void buscarProducto() {
    char codigo[20];
    printf("Ingrese el código del producto a buscar: ");
    scanf("%s", codigo);

    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No se encontró el archivo de la lista de precios.\n");
        return;
    }

    Producto prod;
    int encontrado = 0;
    while (fscanf(file, "%s %s %f", prod.codigo, prod.nombre, &prod.precio) != EOF) {
        if (strcmp(prod.codigo, codigo) == 0) {
            printf("Producto encontrado:\n");
            printf("Código: %s\n", prod.codigo);
            printf("Nombre: %s\n", prod.nombre);
            printf("Precio: %.2f\n", prod.precio);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Producto no encontrado.\n");
    }

    fclose(file);
}

void eliminarProducto() {
    char codigo[20];
    printf("Ingrese el código del producto a eliminar: ");
    scanf("%s", codigo);

    FILE *file = fopen(FILENAME, "r");
    FILE *temp = fopen("temp.txt", "w");

    if (file == NULL || temp == NULL) {
        printf("Error al abrir los archivos.\n");
        return;
    }

    Producto prod;
    int encontrado = 0;
    while (fscanf(file, "%s %s %f", prod.codigo, prod.nombre, &prod.precio) != EOF) {
        if (strcmp(prod.codigo, codigo) != 0) {
            fprintf(temp, "%s %s %.2f\n", prod.codigo, prod.nombre, prod.precio);
        } else {
            encontrado = 1;
        }
    }

    fclose(file);
    fclose(temp);

    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (encontrado) {
        printf("Producto eliminado correctamente.\n");
    } else {
        printf("Producto no encontrado.\n");
    }
}

void modificarProducto() {
    char codigo[20];
    printf("Ingrese el código del producto a modificar: ");
    scanf("%s", codigo);

    FILE *file = fopen(FILENAME, "r");
    FILE *temp = fopen("temp.txt", "w");

    if (file == NULL || temp == NULL) {
        printf("Error al abrir los archivos.\n");
        return;
    }

    Producto prod;
    int encontrado = 0;
    while (fscanf(file, "%s %s %f", prod.codigo, prod.nombre, &prod.precio) != EOF) {
        if (strcmp(prod.codigo, codigo) == 0) {
            encontrado = 1;

            char nuevoCodigo[20], nuevoNombre[50];
            float nuevoPrecio;

            printf("Código? (Presione [Enter] para conservar el actual \"%s\"): ", prod.codigo);
            scanf(" %[^\n]", nuevoCodigo);
            if (strcmp(nuevoCodigo, "") != 0) {
                strcpy(prod.codigo, nuevoCodigo);
            }

            printf("Nombre? (Presione [Enter] para conservar el actual \"%s\"): ", prod.nombre);
            scanf(" %[^\n]", nuevoNombre);
            if (strcmp(nuevoNombre, "") != 0) {
                strcpy(prod.nombre, nuevoNombre);
            }

            printf("Precio? (Presione [Enter] para conservar el actual \"%.2f\"): ", prod.precio);
            if (scanf("%f", &nuevoPrecio) == 1) {
                prod.precio = nuevoPrecio;
            }
        }
        fprintf(temp, "%s %s %.2f\n", prod.codigo, prod.nombre, prod.precio);
    }

    fclose(file);
    fclose(temp);

    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (encontrado) {
        printf("Producto modificado correctamente.\n");
    } else {
        printf("Producto no encontrado.\n");
    }
}

int main() {
    int opcion;

    while (1) {
        mostrarMenu();
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                verListaPrecios();
                break;
            case 2:
                agregarProducto();
                break;
            case 3:
                buscarProducto();
                break;
            case 4:
                eliminarProducto();
                break;
            case 5:
                modificarProducto();
                break;
            case 0:
                printf("Saliendo del programa...\n");
                return 0;
            default:
                printf("Opción no válida. Intente nuevamente.\n");
        }
    }

    return 0;
}
