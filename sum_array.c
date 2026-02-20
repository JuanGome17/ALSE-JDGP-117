#include <stdio.h>
int main(int argc, char** argv ){
    printf("Bienvenido usuario al programa para sumar elementos de un arreglo\n");
    printf("Por favor ingrese el tamaño del arreglo: ");
    int tam;
    scanf("%d",&tam);
    int arr[tam];
    for (int rep = 0; rep < tam; rep++){
        printf("usuario digite el numero %d: ", rep + 1);
        scanf("%d", &arr[rep]);
    }
    int suma = 0;
    for (int rep = 0; rep < tam; rep++){
        suma = suma + arr[rep];
    }
    printf("la suma de los elementros del arreglo es de %d\n", suma);
}
