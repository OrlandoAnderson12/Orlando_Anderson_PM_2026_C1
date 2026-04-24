#include <stdio.h>

int main() {
    float n1, n2, n3, promedio;

    printf("Ingrese tres calificaciones: ");
    scanf("%f %f %f", &n1, &n2, &n3);

    promedio = (n1 + n2 + n3) / 3;

    if (promedio >= 70)
        printf("Aprobado. Promedio: %.2f", promedio);
    else
        printf("Reprobado. Promedio: %.2f", promedio);

    return 0;
}
