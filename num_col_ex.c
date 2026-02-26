#include <stdio.h>
#include <ctype.h>
int titleToNumber(char* columnTitle) {
    int result = 0;
    for (int rep = 0; columnTitle[rep] != '\0'; rep++) {
        char c = toupper(columnTitle[rep]);
        result = result * 26 + (c - 'A' + 1);
    }
    return result;
}
int main() {
    char col[50];
    printf("Ingrese la columna: ");
    scanf("%49s", col);
    printf("Valor: %d\n", titleToNumber(col));
    return 0;
}