#include <stdio.h>
#include <math.h>

int main(int argc, char** argv ){
    printf("Bienvenido usuario al programa de interes compuesto\n");
    printf("Por favor ingrese el monto inicial: ");
    int monin;
    scanf("%d", &monin);
    printf("Por favor ingrese la tasa de interes anual: ");
    float tasa;
    scanf("%f", &tasa);
    float tasat = tasa / 100;
    printf("Por favor ingrese el numero de años: ");
    int años;
    scanf("%d", &años);
    printf("Digite el numero de veces que se le aplicara el interes al año:");
    int cantv;
    scanf("%d", &cantv);
    float monto_final = monin * pow((1 + tasat/(cantv)),cantv * años);
    printf("El monto final es: %.2f\n", monto_final);
    return 0;
}