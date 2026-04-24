#include <stdio.h>
#include <math.h>

int main() {
    float L1, L2, L3, s, area;
    printf("Ingrese los tres lados: ");
    scanf("%f %f %f", &L1, &L2, &L3);

    if ( (L1+L2>L3) && (L1+L3>L2) && (L2+L3>L1) ) {
        printf("Es un triangulo.\n");
        s = (L1+L2+L3)/2;
        area = sqrt(s*(s-L1)*(s-L2)*(s-L3));
        printf("Area = %.2f\n", area);

        if (L1==L2 && L2==L3)
            printf("Es equilatero.\n");
        else if (L1==L2 || L1==L3 || L2==L3)
            printf("Es isosceles.\n");
        else
            printf("Es escaleno.\n");
    } else {
        printf("No es un triangulo.\n");
    }

    return 0;
}