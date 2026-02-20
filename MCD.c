#include <stdio.h>
int main(int argc, char** argv ){
    printf("Bienvenido usuario programa de Maximo comun Divisor\n");
    printf("Usuario ingrese el primer numero: ");
    int num1;
    scanf("%d", &num1);
    printf("Usuario ingrese el segundo numero: ");
    int num2;
    scanf("%d", &num2);
    int a = num1;
    int b = num2;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    printf("El MCD es: %d\n", a);
}