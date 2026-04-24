#include <stdio.h>

int main() {
    int MED;
    float VAL, resultado;

    printf("Ingrese tipo de conversion (1=Pulgadas a mm, 2=Yardas a m, 3=Millas a km): ");
    scanf("%d", &MED);
    printf("Ingrese el valor a convertir: ");
    scanf("%f", &VAL);

    if (MED == 1)
        resultado = VAL * 25.40;
    else if (MED == 2)
        resultado = VAL * 0.9144;
    else if (MED == 3)
        resultado = VAL * 1.6093;
    else {
        printf("Opcion invalida.\n");
        return 1;
    }

    printf("El resultado de la conversion es: %.2f\n", resultado);
    return 0;
}