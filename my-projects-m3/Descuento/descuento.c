#include <stdio.h>
#include <stdlib.h>
#include <diprog.h>

float descuento(float precio, int descuentoPorc);

// FUNCION PRINCIPAL

int main(void) {

    printf(" *** DESCUENTOS *** \n");
    
    float precio = leer_float("Precio?\n ");
    int descuentoPorc = leer_int("Descuento?\n ");
    float oferta = descuento(precio, descuentoPorc);
    printf("oferta --> $ %2.f\n", oferta);

    system("pause");
}

float descuento(float precio, int descuentoPorc){

    precio = precio * ( (float) (100 - descuentoPorc) / 100 );
    return precio;

}