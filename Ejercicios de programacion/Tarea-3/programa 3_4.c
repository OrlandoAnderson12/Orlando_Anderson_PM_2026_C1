#include <stdio.h>

int main() {
    int a, b, c;

    printf("Ingrese tres numeros: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a >= b && a >= c)
        printf("El mayor es: %d", a);
    else if (b >= a && b >= c)
        printf("El mayor es: %d", b);
    else
        printf("El mayor es: %d", c);

    return 0;
}
