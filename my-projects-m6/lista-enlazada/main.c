#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
    int numero;
    struct nodo *sig;
}
nodo;


int main(int argc, char *argv[]) {
    printf(" *** ***Lista enlazada*** *** \n");
    
    
    nodo *lista = NULL;

    for (int i = 1; 1 < argc; i++) {
        //convertir el string en int
        int numero = atoi(argv[1]);

        //crear el nodo en memoria
        nodo *n = malloc(sizeof(nodo));
        if (n == NULL) {
            return 1;
        }
        n->numero = numero;
        n->sig = NULL;
        // insertar el nodo en nuestra lista
        n-> sig = lista;
        lista = n;

    }
    //recorro mi lista enlazada e imprimo
    nodo *p = lista;
    while(p != NULL) {
        printf("%i \n ", p->numero );
        p = p->sig;
    }
    //liberar memoria
    p = lista;
    while (p != NULL) {
        nodo *tmp = p ->sig;
        free(p);
        p = tmp;
    }
    system("pause");
    }