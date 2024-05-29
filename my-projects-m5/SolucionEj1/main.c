#include <stdio.h>
#include <diprog.h>
#include <string.h>

#define MAX_PRODUCTOS 10

typedef struct {
    string codigo;
    string nombre;
    float precio;
}
producto;


int imprimirMenuYObtenerOpcion();
void agregarProducto(producto lista[MAX_PRODUCTOS], int posicion);
void mostrarProductos(producto lista[MAX_PRODUCTOS], int cant);

/**
 * Función principal. Muestra el menú y ejecuta las opciónes elegidas
 * hasta que el usuario elije 0) Salir.
 * Declara una variable array para mantener la lista de precios, de un tamaño
 * maximo definido con una constante.
 */
int main(void)
{
    // Declarar un array para usar como agenda
    producto lista_precios[MAX_PRODUCTOS];
    
    // Cantidad de productos en la lista
    int cantProductos = 0;

    int opcion;

    // Bucle principal del programa. 
    // Mostrar el menu y ejecutar hasta que el usuario elija salir del programa
    do {

        opcion = imprimirMenuYObtenerOpcion();
        switch (opcion) {

            // Mostrar
            case 1:

                if (cantProductos == 0) {
                    printf("\nNo hay productos en la lista!\n");
                } else {
                    mostrarProductos(lista_precios, cantProductos);
                }
                break;

            // Agregar un producto
            case 2:
                // Verificar si la lista se encuentra completa
                if (cantProductos >= MAX_PRODUCTOS) {
                    printf("ERR: La lista de precios está completa!\n");
                } else {
                    // Agregar un nuevo producto
                    agregarProducto(lista_precios, cantProductos);                    
                    cantProductos++;
                    printf("Producto agregado!\n");
                }
                break;
                

        }

    } while (opcion != 0);    
}


/**
 * Muestra el menú de opciones del programa, pide la opción al usuario
 * y la devuelve.
 */
int imprimirMenuYObtenerOpcion()
{
    printf("\n");
    printf("*** Lista de Precios de Productos ***\n");
    printf("1) Mostrar Productos\n");
    printf("2) Agregar Producto\n");
    printf("0) Salir\n");

    int opcion = 0;
    opcion = leer_int("Opción? ");

    while (opcion < 0 || opcion > 2) {
        opcion = leer_int("Opción inválida. Opción? ");
    }

    return opcion;
}


/**
 * Agrega un nuevo producto a la lista de precios.
 */
void agregarProducto(producto lista[MAX_PRODUCTOS], int posicion)
{
    // Pedir los datos
    printf("\n");
    printf("* Por favor ingrese los datos para el nuevo producto: \n");    
    lista[posicion].codigo = leer_string("Código? ");
    lista[posicion].nombre = leer_string("Nombre? ");
    lista[posicion].precio = leer_float("Precio? ");
}


/**
 * Muestra todos los productos almacenados en el archivo de la lista de precios.
 */
void mostrarProductos(producto lista[MAX_PRODUCTOS], int cant)
{
    printf("\n");
    printf("* Productos: \n\n");
    for (int i = 0; i < cant; i++) {
        printf("- [%s] %s | $%f\n", lista[i].codigo, lista[i].nombre, lista[i].precio);
    }
}