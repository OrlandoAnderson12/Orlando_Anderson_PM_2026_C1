#include <stdio.h>

int main(void) {
    int N1, N2, N3;

    printf("Pon N1: ");
    scanf("%d", &N1);

    printf("Pon N2: ");
    scanf("%d", &N2);

    printf("Pon N3: ");
    scanf("%d", &N3);

    if (N1 < N2 && N2 < N3) {
        printf("Los numeros son crecientes.\n");
    } else {
        printf("Los numeros no son crecientes.\n");
    }

    return 0;
}
