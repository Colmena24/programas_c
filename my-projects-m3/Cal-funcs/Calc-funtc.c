#include <stdio.h>
#include <stdlib.h>
#include <diprog.h>

string obtenerNombreOperacion(char op);
double calcular(double num1, double num2, char op);

int main(void){
    
    printf("*** Calculadora Simple de 2 Números Enteros ***\n");
        
    // Pedir operación a realizar y validar
    char o;    
    
    do {
        // Pedir operación
        o = leer_char("Seleccione operacion (simbolo) a realizar (Posibles operaciones: [+ - * /])? ");        
    } while (o != '+' && o != '-' && o != '*' && o != '/');


    // Pedir operandos al usuario
    int op1 = leer_int("Ingrese numero 1: ");
    int op2 = leer_int("Ingrese numero 2: ");

    string operacion = obtenerNombreOperacion(o);
    double resultado = calcular(op1, op2, o);
    
    // Mostrar resultado x pantalla
    printf("El resultado de la %s (%i %c %i) es: %f\n", operacion, op1, o, op2, resultado);
    system("pause");
    }

double calcular(double num1, double num2, char op){

    // Realizar la operación matemática    

    double res;    
    switch (op) {
        case '+':
            res = (double) num1 + num2;
            break;
        case '-':
            res = (double) num1 - num2;
            break;
        case '*':
            res = (double) num1 * num2;
            break;
        case '/':
            res = (double) num1 / num2;
            break;
    }
    return res;
}
    string obtenerNombreOperacion(char op){
        string opStr;
        switch (op) {
            case '+':
                opStr = "suma";
                break;
            case '-':
                opStr = "resta";
                break;
            case '*':
                opStr = "multiplicación";
                break;
            case '/':
                opStr = "división";
                break;
    }
    }