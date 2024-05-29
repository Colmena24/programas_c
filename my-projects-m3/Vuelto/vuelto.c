#include <stdio.h>

int main() {
    float i;
    float j;
    
    printf("*** *** Vuelto *** ***\n");
    
    printf("Ingrese precio de venta $: ");
    scanf("%f" , &i);
    printf("\nIngrese monto entregado $: ");
    scanf("%f" , &j);
    
    if ( i > j ) {
        printf("Todavia falta $:  %.3f por entregar\n", i - j);
    } else if ( i < j) {
        printf("Su vuelto es $: %.3f", j - i);
    } else if ( i = j) {
        printf("No se debe entregar vuelto");
    }
    
    return 0;
}
