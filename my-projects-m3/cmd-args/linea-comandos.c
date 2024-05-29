#include <stdio.h>
#include <stdlib.h>
#include <diprog.h>

int main(int argc, string argv[]) {
    
    for (int i = 0; i < argc; i++) {
        printf("argv[%i] = %s\n", i, argv[i]);
    }

    printf("argv[%i] = %s\n", argc + 1, argv[argc + 1]);
    printf("argv[%i] = %s\n", argc + 2, argv[argc + 2]);
    printf("argv[%i] = %s\n", argc + 3, argv[argc + 3]);
    system("pause");
    }