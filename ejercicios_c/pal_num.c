#include <stdio.h>
int main(int argc, char** argv ){
    int num, og, inv = 0, dig;
    printf("Bienvenido usuario al programa verificador de palindromos\n");
    printf("Usuario ingrese el numero a verificar");
    scanf("%d", &num);
    og = num;
    while(num > 0){
        dig = num % 10;
        inv = inv *10 + dig;
        num = num / 10;
    }
    if (og == inv)
        printf("El numero es un palindromo\n");
    else
        printf("El numero no es un palindromo\n");
    return 0;
}