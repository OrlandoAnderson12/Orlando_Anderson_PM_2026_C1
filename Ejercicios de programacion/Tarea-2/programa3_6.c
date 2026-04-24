#include <stdio.h>

int main() {
    float N1, N2, N3, mayor;

    printf("Ingrese tres numeros reales: ");
    scanf("%f %f %f", &N1, &N2, &N3);

    mayor = N1;
    if (N2 > mayor) mayor = N2;
    if (N3 > mayor) mayor = N3;

    printf("El numero mayor es: %.2f\n", mayor);

    return 0;
    }