#include <math.h>

int main() {
    int Y;
    double f;

    printf("Ingrese un numero entero Y: ");
    scanf("%d", &Y);

    switch (Y % 4) {
        case 0:
            f = pow(Y, 3);
            break;
        case 1:
            f = (pow(Y, 2) - 14) / pow(Y, 3);
            break;
        case 2:
            f = pow(Y, 3) + 5;
            break;
        case 3:
            f = pow(Y, 0.5);
            break;
    }

    printf("El valor de f(Y) es: %.2f\n", f);

    return 0;
}
