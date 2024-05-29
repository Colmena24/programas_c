#include <stdio.h>
#include <diprog.h>

int main(void)
{
    printf("*** Calculadora Simple de 2 Números Enteros ***\n");
        
    // Pedir operación a realizar y validar
    char op;    
    
    do {
        // Pedir operación
        op = leer_char("Seleccione operación (símbolo) a realizar (Posibles operaciones: [+ - * /])? ");        
    } while (op != '+' && op != '-' && op != '*' && op != '/');


    // Pedir operandos al usuario
    int num1 = leer_int("Ingrese numero 1: ");
    int num2 = leer_int("Ingrese numero 2: ");

    // Realizar la operación matemática    
    string opStr;
    double res;    
    switch (op) {
        case '+':
            opStr = "suma";
            res = (double) num1 + num2;
            break;
        case '-':
            opStr = "resta";
            res = (double) num1 - num2;
            break;
        case '*':
            opStr = "multiplicación";
            res = (double) num1 * num2;
            break;
        case '/':
            opStr = "división";
            res = (double) num1 / num2;
            break;
    }

    // Mostrar resultado x pantalla
    printf("El resultado de la %s (%i %c %i) es: %f\n", opStr, num1, op, num2, res);

}