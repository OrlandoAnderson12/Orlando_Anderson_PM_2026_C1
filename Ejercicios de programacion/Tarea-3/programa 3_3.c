#include <stdio.h>

int main() {
    int a, b;

    printf("Ingrese dos numeros: ");
    scanf("%d %d", &a, &b);

    if (a > b)
        printf("El mayor es: %d", a);
    else
        printf("El mayor es: %d", b);

    return 0;
}
