#include <stdio.h>
int main(int argc, char** argv ){
    printf("Bienvenido usuario a la conjetura collatz \n");
    printf("Ingrese un numero entero positivo: \n");
    int num;
    scanf("%d", &num);
    if (num <= 0){
        printf("El numero debe ser entero positivo");
        return 1;
    }
    while (num != 1){
        printf("%d -> ", num);
        if (num % 2 == 0){
            num = num / 2;
        } else {
            num = 3 * num + 1;
        }
        }
    printf("El resultado es: %d\n", num);
    return 0;
}