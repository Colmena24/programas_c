#include <stdio.h>
#include <stdlib.h>

void cambiar_int(int x);
void cambiar_array(int arr[4]);

int main(void){

    int a = 10;
    int b[4] = {10, 11, 12, 13};
    
    cambiar_int(a);
    cambiar_array(b);

    printf("%i - %i\n", a, b[1]);    
    system("pause");
    }

void cambiar_int(int x){

    x += 5;
}

void cambiar_array(int arr[4]){

    arr[1] += 5;
}