#include <stdio.h>

int main() {
    float valor_inicial, valor_final, depreciacion_mensual, valor_actual;
    int meses;

    FILE *archivo = fopen("amortizacion.txt", "w");

    if (archivo == NULL) {
        printf("Error al crear el archivo");
        return 1;
    }

    printf("Ingrese valor inicial del vehiculo: ");
    scanf("%f", &valor_inicial);

    printf("Ingrese valor final del vehiculo: ");
    scanf("%f", &valor_final);

    printf("Ingrese tiempo en meses: ");
    scanf("%d", &meses);

    depreciacion_mensual = (valor_inicial - valor_final) / meses;
    valor_actual = valor_inicial;

    fprintf(archivo, "Mes\tValor Inicial\tDepreciacion\tValor Final\n");

    for (int i = 1; i <= meses; i++) {
        float valor_mes_final = valor_actual - depreciacion_mensual;

        fprintf(archivo, "%d\t%.2f\t\t%.2f\t\t%.2f\n",
                i, valor_actual, depreciacion_mensual, valor_mes_final);

        valor_actual = valor_mes_final;
    }

    fclose(archivo);

    printf("Tabla generada en amortizacion.txt\n");

    return 0;
}