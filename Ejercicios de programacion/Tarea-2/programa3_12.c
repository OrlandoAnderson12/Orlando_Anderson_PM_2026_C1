#include <stdio.h>

int main() {
    int NUM, d1, d2, d3, d4;
    printf("Ingrese un numero de 4 digitos: ");
    scanf("%d", &NUM);

    d4 = NUM % 10;
    d3 = (NUM / 10) % 10;
    d2 = (NUM / 100) % 10;
    d1 = (NUM / 1000) % 10;

    if (d1%2==0 && d2%2==0 && d3%2==0 && d4%2==0)
        printf("Todos los digitos son pares.\n");
    else
        printf("No todos los digitos son pares.\n");

    return 0;
}
