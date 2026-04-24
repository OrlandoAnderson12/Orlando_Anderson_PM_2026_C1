#include <stdio.h>

int main() {
    float SAL, pagoExtra = 0;
    int CAT, PHE, tarifa = 0;

    printf("Ingrese salario: ");
    scanf("%f", &SAL);
    printf("Ingrese categoria (1-3): ");
    scanf("%d", &CAT);
    printf("Ingrese horas extra: ");
    scanf("%d", &PHE);

    if (CAT >= 4) {
        printf("No tiene derecho a horas extra.\n");
    } else {
        if (PHE > 30) PHE = 30; // Limite de horas
        if (CAT == 1) tarifa = 40;
        else if (CAT == 2) tarifa = 50;
        else if (CAT == 3) tarifa = 85;

        pagoExtra = PHE * tarifa;
        printf("Pago total = %.2f (Salario %.2f + Horas extra %.2f)\n", SAL + pagoExtra, SAL, pagoExtra);
    }

    return 0;
}
