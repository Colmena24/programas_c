#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x = 0;
    int y = incremento(x);
    printf("- main -------> x = %i - y = %i\n", x, y);
    system("pause");
    }

int incremento (int x){

    int y =0;
    y = x++;
    printf("- incremento -> x = %i - y = %i\n", x, y);
    return y;


}