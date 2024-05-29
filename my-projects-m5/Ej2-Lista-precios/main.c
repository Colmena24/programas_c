#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define FILENAME "productos.txt"

void agregarProducto();
void verListaPrecios();
void mostrarMenu();

struct Producto {
    char codigo[20];
    char nombre[50];
    float precio;
};

struct Producto productos[MAX_PRODUCTS];
int cantidadProductos = 0;

int main() {
    int opcion;
    
    do {
        mostrarMenu();
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                verListaPrecios();
                break;
            case 2:
                agregarProducto();
                break;
            case 3:
                printf("Ha finalizado con exito\n");
                break;
            default:
                printf("Opcion no valida. Intente nuevamente.\n");
        }
    } while (opcion != 3);
    
    return 0;
}

void mostrarMenu() {
    printf("\n----- Menu Principal -----\n");
    printf("1) Ver lista de precios\n");
    printf("2) Agregar un producto\n");
    printf("3) Salir\n");
    printf("Seleccione una opcion: ");
}

void verListaPrecios() {
    FILE *archivo = fopen(FILENAME, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }
    
    printf("\n----- Lista de Precios -----\n");
    struct Producto producto;
    while (fread(&producto, sizeof(struct Producto), 1, archivo)) {
        printf("Codigo: %s\n", producto.codigo);
        printf("Nombre: %s\n", producto.nombre);
        printf("Precio: %.2f\n\n", producto.precio);
    }
    
    fclose(archivo);
}

void agregarProducto() {
    if (cantidadProductos < MAX_PRODUCTS) {
        struct Producto nuevoProducto;
        
        printf("\n----- Agregar Producto -----\n");
        printf("Ingrese el codigo: ");
        scanf("%s", nuevoProducto.codigo);
        printf("Ingrese el nombre: ");
        scanf("%s", nuevoProducto.nombre);
        printf("Ingrese el precio: ");
        scanf("%f", &nuevoProducto.precio);
        
        FILE *archivo = fopen(FILENAME, "a");
        if (archivo == NULL) {
            printf("No se pudo abrir el archivo.\n");
            return;
        }
        
        fwrite(&nuevoProducto, sizeof(struct Producto), 1, archivo);
        fclose(archivo);
        
        productos[cantidadProductos] = nuevoProducto;
        cantidadProductos++;
    } else {
        printf("No es posible agregar mas productos.\n");
    }
}