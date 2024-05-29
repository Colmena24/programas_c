#include <stdio.h>
#include <stdlib.h>
#include <diprog.h>

int main(void)
{
    printf("*** *** ARQUEO *** ***\n");
    
        int bm = leer_int("\nCantidad de billetes de $ 1000: ");
        int bq = leer_int("\nCantidad de billetes de $  500: ");
        int bc = leer_int("\nCantidad de billetes de $  100: ");
        int cb = leer_int("\nCantidad de billetes de $   50: ");
        int bv = leer_int("\nCantidad de billetes de $   20: ");
        int bd = leer_int("\nCantidad de billetes de $   10: ");
        int mt = leer_int("\nCantidad de monedas de  $   10: ");
        int mc = leer_int("\nCantidad de monedas de  $    5: ");
        int md = leer_int("\nCantidad de monedas de  $    2: ");
        int mu = leer_int("\nCantidad de monedas de  $    1: ");

        int total = ((bm*1000)+(bq*500)+(bc*100)+(cb*50)+(bv*20)+(bd*10)+(mt*10)+(mc*5)+(md*2)+(mu));
        printf("\nMonto total de caja: $%i\n" , total );
        printf("*** *** *** *** ***\n");
    system("pause");
    }