#include <stdio.h>
#include <diprog.h>
#include <string.h>

typedef struct {
    string codigo;
    string nombre;
    float precio;
}
producto;


int imprimirMenuYObtenerOpcion();
int agregarProducto();
int mostrarProductos();


/**
 * Función principal. Muestra el menú y ejecuta las opciónes elegidas
 * hasta que el usuario elije 0) Salir
 */
int main(void)
{    
    int opcion;

    // Bucle principal del programa. 
    // Mostrar el menu y ejecutar hasta que el usuario elija salir del programa
    do {

        opcion = imprimirMenuYObtenerOpcion();
        int res;
        switch (opcion) {

            // Mostrar
            case 1:
                res = mostrarProductos();                
                break;

            // Agregar un producto
            case 2:
                res = agregarProducto();                
                break;

        }

        if (res != 0) {
            // Se produjo un error, terminar ejecución de manera erronea
            return res;
        }

    } while (opcion != 0);    
}


/**
 * Abre la lista de precios en el modo indicado y retorna el puntero al archivo.
 * Si el archivo no existe, intenta crearlo y retornar el puntero al archivo.
 */
FILE *abrirOCrearArchivo(string modo)
{
    // Nombre "cableado" del archivo a utilizar
    string nombreArchivo = "lista-precios.csv";

    // Intenar abrir archivo...
    FILE *archivo = fopen(nombreArchivo, modo);    
    if (archivo == NULL && strcmp(modo, "r") == 0) {
        // Error, posiblemente no existe el archivo en disco. Intentar crear.
        archivo = fopen(nombreArchivo, "w");
        if (archivo != NULL) {
            fclose(archivo);
            archivo = fopen(nombreArchivo, "r");
        }        
    }
    return archivo;
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
int agregarProducto()
{
    producto p;
    
    // Pedir los datos
    printf("\n");
    printf("* Por favor ingrese los datos para el nuevo producto: \n");
    p.codigo = leer_string("Código? ");
    p.nombre = leer_string("Nombre? ");
    p.precio = leer_float("Precio? ");

    // Abrir archivo en modo escritura para agregar (append)
    FILE *archivo = abrirOCrearArchivo("a");
    if (archivo == NULL) {
        // Si hay error, salir
        return 100;
    }

    // Agregar producto al final del archivo
    fprintf(archivo, "%s,%s,%f\n", p.codigo, p.nombre, p.precio);

    // Cerrar archivo
    fclose(archivo);

    // Retornar con éxito!
    return 0;
}


/**
 * Muestra todos los productos almacenados en el archivo de la lista de precios.
 */
int mostrarProductos()
{
    printf("\n");
    printf("* Productos: \n\n");
    
    // Abrir archivo en modo lectura (read)
    FILE *archivo = abrirOCrearArchivo("r");
    if (archivo == NULL) {
        // Si hay error, salir
        return 201;
    }

    char linea[500]; // tamaño 500, suficientemente grande como para recibir una linea completa del archivo
    
    // Recorro todo el archivo, y voy leyendo linea por linea
    while(fgets(linea, sizeof(linea), archivo) != NULL) {
        
        producto p;

        // Leer codigo
        string token = strtok(linea, ",");
        p.codigo = token;

        // Leer nombre
        token = strtok(NULL, ",");
        p.nombre = token;

        // Leer precio
        token = strtok(NULL, ",");
        p.precio = atof(token);
        
        printf("- [%s] %s | $%f\n", p.codigo, p.nombre, p.precio);
    }

    // Estoy al final del archivo?
    if (feof(archivo)) {
        // Leímos correctamente todo el archivo
        fclose(archivo);
        return 0;
    } else {
        // Se produjo un error en alguna linea...
        fclose(archivo);
        return 202;
    }
        
}


