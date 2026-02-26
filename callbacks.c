#include <stdio.h>
#include <stdlib.h>
double suma(double a, double b)  { return a + b; }
double resta(double a, double b) { return a - b; }
double mult(double a, double b)  { return a * b; }
double divi(double a, double b)  { return a / b; }
int main(int argc, char** argv) {
    printf("Bienvenido usuario a los callbacks \n");
    if (argc != 4) {
        printf("Ha ingresado valores inadecuados para el programa\n");
        printf("USO ./<ejecutable> <num1> <operador> <num2>\n");
        return 1;
    }
    double num1 = strtod(argv[1], NULL);
    double num2 = strtod(argv[3], NULL);
    char operador = argv[2][0];
    double (*operacion)(double, double) = NULL;
    switch (operador) {
        case '+': operacion = suma;  break;
        case '-': operacion = resta; break;
        case '*': operacion = mult;  break;
        case '/':
            if (num2 == 0) {
                printf("Error: Division por cero\n");
                return 1;
            }
            operacion = divi;
            break;
        default:
            printf("Error: Operador no reconocido\n");
            return 1;
    }
    double resultado = operacion(num1, num2);
    printf("El resultado de %.2f %c %.2f es: %.2f\n", num1, operador, num2, resultado);
    return 0;
}