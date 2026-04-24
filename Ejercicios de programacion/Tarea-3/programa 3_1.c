#include <stdio.h>

int main() {
    int num;

    printf("Ingrese un numero: ");
    scanf("%d", &num);

    if (num > 0)
        printf("El numero es positivo");
    else if (num < 0)
        printf("El numero es negativo");
    else
        printf("El numero es cero");

    return 0;
}

