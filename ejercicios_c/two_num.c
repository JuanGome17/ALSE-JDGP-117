#include <stdio.h>
int main(int argc, char** argv ){
    printf("bienvenido usuario al programa de suma de unumeros de un arreglo\n");
    int num;
    printf("ingrese el numero de elementos del arreglo\n");
    scanf("%d", &num );
    int arreglo[num];
    for (int rep = 0; rep < num; rep ++){
        printf("ingrese el numero &d del arreglo\n", rep + 1);
        scanf("%d", &arreglo[rep]);
    }
    int target;
    printf("ingrese el numero a buscar en el arreglo\n");
    scanf("%d", &target);
    for (int rep = 0; rep < num; rep++){
        for (int rep2 = rep + 1; rep2 < num; rep2++){
            if (arreglo[rep] + arreglo[rep2] == target){
                printf("los numeros %d y %d suman el numero objetivo\n", arreglo[rep], arreglo[rep2]);
                return 0;
            }
        }
    }
    printf("no se encontraron numeros que sumen el numero objetivo\n");
    return 0;
}