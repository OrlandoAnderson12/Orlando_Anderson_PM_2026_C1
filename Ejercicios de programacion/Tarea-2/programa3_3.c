#include <stdio.h>

int main(void)
{
    int N1, N2;

    printf("Enter N1: ");
    scanf("%d", &N1);
    printf("Enter N2: ");
    scanf("%d", &N2);

    if (N1 != 0) {
        printf("N2/N1 = %f\n", (double)N2/N1);
        printf("N2%%N1 = %d\n", N2 % N1);
    } else {
        printf("N2/N1 = Undefined (division by zero)\n");
        printf("N2%%N1 = Undefined (division by zero)\n");
    }

    if (N2 != 0) {
        printf("N1/N2 = %f\n", (double)N1/N2);
        printf("N1%%N2 = %d\n", N1 % N2);
    } else {
        printf("N1/N2 = Undefined (division by zero)\n");
        printf("N1%%N2 = Undefined (division by zero)\n");
    }

    return 0;
}


