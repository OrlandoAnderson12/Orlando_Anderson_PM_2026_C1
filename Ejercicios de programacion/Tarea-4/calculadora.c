#include <stdio.h>
#include <math.h>

int main()
{
    char op;
    double primernumero, segundonumero;

    printf("--- Calculadora Simple ---\n");
    printf("Elija un operador (+, -, , /): ");
    scanf(" %c", &op);

    printf("Ingrese el primer numero: ");
    scanf("%lf", &primernumero);
    printf("Ingrese el segundo numero: ");
    scanf("%lf", &segundonumero);

    switch (op) {
        case '+':
            printf("Resultado: %.2lf\n", primernumero + segundonumero);
            break;
        case '-':
            printf("Resultado: %.2lf\n", primernumero - segundonumero);
            break;
        case '*':
            printf("Resultado: %.2lf\n", primernumero * segundonumero);
            break;
        case '/':
            if (segundonumero != 0) {
                printf("Resultado: %.2lf\n", primernumero / segundonumero);
            } else {
                printf("Error: Division por cero.\n");
            }
            break;
        default:
            printf("Operador no reconocido.\n");
    }
    return 0; // Indica que el programa finalizó correctamente
}
