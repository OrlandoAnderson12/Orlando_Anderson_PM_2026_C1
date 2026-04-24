#include <stdio.h>

int main() {
    int a, b;

    printf("Ingrese dos numeros: ");
    scanf("%d %d", &a, &b);

    if (a % b == 0)
        printf("%d es multiplo de %d", a, b);
    else
        printf("%d no es multiplo de %d", a, b);

    return 0;
}
