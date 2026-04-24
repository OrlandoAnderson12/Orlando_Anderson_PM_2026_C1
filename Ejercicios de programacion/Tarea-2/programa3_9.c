#include <stdio.h>
#include <string.h>

int main() {
    int MED, SME;
    float VAL, resultado;
    char nuevaMedida[20];

    printf("Ingrese tipo de conversion (1=longitud, 2=volumen, 3=peso): ");
    scanf("%d", &MED);
    printf("Ingrese sub-tipo de conversion: ");
    scanf("%d", &SME);
    printf("Ingrese valor a convertir: ");
    scanf("%f", &VAL);

    if (MED == 1) { // Longitud
        if (SME == 1) { resultado = VAL * 25.40; strcpy(nuevaMedida,"mm"); }
        else if (SME == 2) { resultado = VAL * 0.9144; strcpy(nuevaMedida,"m"); }
        else if (SME == 3) { resultado = VAL * 1.6093; strcpy(nuevaMedida,"km"); }
    } else if (MED == 2) { // Volumen
        if (SME == 1) { resultado = VAL * 0.02832; strcpy(nuevaMedida,"m3"); }
        else if (SME == 2) { resultado = VAL * 0.7646; strcpy(nuevaMedida,"m3"); }
        else if (SME == 3) { resultado = VAL * 0.56826; strcpy(nuevaMedida,"l"); }
    } else if (MED == 3) { // Peso
        if (SME == 1) { resultado = VAL * 28.35; strcpy(nuevaMedida,"g"); }
        else if (SME == 2) { resultado = VAL * 0.45359; strcpy(nuevaMedida,"kg"); }
        else if (SME == 3) { resultado = VAL * 1016; strcpy(nuevaMedida,"t"); }
    } else {
        printf("Opcion invalida.\n");
        return 1;
    }

    printf("El valor convertido es: %.2f %s\n", resultado, nuevaMedida);
    return 0;
}