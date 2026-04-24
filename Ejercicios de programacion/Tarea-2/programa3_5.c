#include <stdio.h>

int main() {
    float COM, PRECIO_FINAL, DES;

    // Entrada del monto de la compra
    printf("Ingrese el monto de la compra: ");
    scanf("%f", &COM);

    // Determinar el descuento según el monto
    if (COM < 800) {
        DES = 0.0;
    } else if (COM <= 1500) {
        DES = 0.10;
    } else if (COM <= 5000) {
        DES = 0.15;
    } else {
        DES = 0.20;
    }

    // Calcular precio final
    PRECIO_FINAL = COM * (1 - DES);

    // Mostrar resultado
    printf("El precio a pagar despues del descuento es: %.2f\n", PRECIO_FINAL);

    return 0;
}