#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char codigo[16];
    char nombre[151];
    float precio;
} Producto;

int validarCodigo(char *codigo) {
    int len = strlen(codigo);
    if (len < 1 || len > 15) {
        printf("El código debe tener entre 1 y 15 caracteres.\n");
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (!isalnum(codigo[i])) {  // Solo letras y números
            printf("El código debe contener solo letras y números.\n");
            return 0;
        }
    }
    return 1;
}

int validarNombre(char *nombre) {
    int len = strlen(nombre);
    if (len < 1 || len > 150) {
        printf("El nombre debe tener entre 1 y 150 caracteres.\n");
        return 0;
    }
    return 1;
}

int validarPrecio(char *precioStr, float *precio) {
    int len = strlen(precioStr);
    if (len == 0) {
        *precio = -1; // Indica que no se ingresó precio
        return 1;
    }

    int puntoEncontrado = 0;
    for (int i = 0; i < len; i++) {
        if (precioStr[i] == '.') {
            if (puntoEncontrado) {
                printf("El precio no es válido, hay más de un punto.\n");
                return 0;
            }
            puntoEncontrado = 1;
        } else if (!isdigit(precioStr[i])) {
            printf("El precio debe contener solo números y un punto decimal.\n");
            return 0;
        }
    }

    *precio = atof(precioStr);
    if (*precio < 0) {
        printf("El precio no puede ser negativo.\n");
        return 0;
    }

    return 1;
}

int codigoUnico(char *codigo, Producto *productos, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        if (strcmp(productos[i].codigo, codigo) == 0) {
            printf("El código ya existe.\n");
            return 0;
        }
    }
    return 1;
}

void agregarProducto(Producto *productos, int *cantidad) {
    Producto nuevoProducto;
    char precioStr[20];

    printf("Ingrese el código del producto: ");
    scanf("%s", nuevoProducto.codigo);

    while (!validarCodigo(nuevoProducto.codigo) || !codigoUnico(nuevoProducto.codigo, productos, *cantidad)) {
        printf("Ingrese un código válido: ");
        scanf("%s", nuevoProducto.codigo);
    }

    printf("Ingrese el nombre del producto: ");
    scanf(" %[^\n]", nuevoProducto.nombre);

    while (!validarNombre(nuevoProducto.nombre)) {
        printf("Ingrese un nombre válido: ");
        scanf(" %[^\n]", nuevoProducto.nombre);
    }

    printf("Ingrese el precio del producto (opcional): ");
    scanf("%s", precioStr);

    while (!validarPrecio(precioStr, &nuevoProducto.precio)) {
        printf("Ingrese un precio válido (opcional): ");
        scanf("%s", precioStr);
    }

    productos[*cantidad] = nuevoProducto;
    (*cantidad)++;
    printf("Producto agregado correctamente.\n");
}

void modificarProducto(Producto *productos, int cantidad) {
    char codigo[16];
    int encontrado = 0;

    printf("Ingrese el código del producto a modificar: ");
    scanf("%s", codigo);

    for (int i = 0; i < cantidad; i++) {
        if (strcmp(productos[i].codigo, codigo) == 0) {
            encontrado = 1;
            Producto *productoAModificar = &productos[i];
            char nuevoCodigo[16], nuevoNombre[151], nuevoPrecioStr[20];
            float nuevoPrecio;

            printf("Código? (Presione [Enter] para conservar el actual \"%s\"): ", productoAModificar->codigo);
            fgets(nuevoCodigo, 16, stdin);
            nuevoCodigo[strcspn(nuevoCodigo, "\n")] = '\0';

            if (strlen(nuevoCodigo) > 0) {
                if (validarCodigo(nuevoCodigo) && codigoUnico(nuevoCodigo, productos, cantidad)) {
                    strcpy(productoAModificar->codigo, nuevoCodigo);
                }
            }

            printf("Nombre? (Presione [Enter] para conservar el actual \"%s\"): ", productoAModificar->nombre);
            fgets(nuevoNombre, 151, stdin);
            nuevoNombre[strcspn(nuevoNombre, "\n")] = '\0';

            if (strlen(nuevoNombre) > 0) {
                if (validarNombre(nuevoNombre)) {
                    strcpy(productoAModificar->nombre, nuevoNombre);
                }
            }

            printf("Precio? (Presione [Enter] para conservar el actual \"%.2f\"): ", productoAModificar->precio);
            fgets(nuevoPrecioStr, 20, stdin);
            nuevoPrecioStr[strcspn(nuevoPrecioStr, "\n")] = '\0';

            if (strlen(nuevoPrecioStr) > 0) {
                if (validarPrecio(nuevoPrecioStr, &nuevoPrecio)) {
                    productoAModificar->precio = nuevoPrecio;
                }
            }

            printf("Producto modificado correctamente.\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Producto no encontrado.\n");
    }
}

int main() {
    Producto productos[100];
    int cantidad = 0;
    int opcion;

    do {
        printf("\n*** Menu Principal ***\n");
        printf("1) Ver lista de precios\n");
        printf("2) Agregar un producto a la lista de precios\n");
        printf("3) Buscar producto\n");
        printf("4) Eliminar producto\n");
        printf("5) Modificar producto\n");
        printf("0) Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                // Implementar la función para ver lista de precios.
                break;
            case 2:
                agregarProducto(productos, &cantidad);
                break;
            case 3:
                // Implementar la función para buscar producto.
                break;
            case 4:
                // Implementar la función para eliminar producto.
                break;
            case 5:
                modificarProducto(productos, cantidad);
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Intente nuevamente.\n");
        }
    } while(opcion != 0);

    return 0;
}
