#include <stdio.h>
#include <stdlib.h>
#include <diprog.h>

int main() {
    char c;
    int num1;
    int num2;
    do {
    printf("Ingrese operacion a realizar  ( + , - , * , / ): ");
    fflush(stdin);
    scanf("%c", &c);
    } while (c != '+' && c != '-' && c != '*' && c != '/');
        num1 = leer_int("Primer numero\n");
        num2 = leer_int("Segundo numero\n");
    
        switch (c) {
    case '+':
        printf("El resultado de la suma de (%i + %.i) = %.3f\n", num1, num2, (float) num1 + num2);
        break;
    case '-':
        printf("El resultado de la resta de (%i - %.i) = %.3f\n", num1, num2, (float) num1 - num2);
        break;
    case '*':
      printf("El resultado de la multiplicacion de (%i * %.i) = %.3f\n", num1, num2, (float) num1 * num2);
        break;
    case '/':
        printf("El resultado de la division de (%i / %.i) = %.3f\n", num1, num2, (float) num1 / num2);
        break;
        
    }
    system("pause\n");

}