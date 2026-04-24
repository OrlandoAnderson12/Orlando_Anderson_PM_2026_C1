#include <stdio.h>

int main(void) {
    int Sal;
    double nuevosalario;
    printf("Ingrese el salario anual en pesos:");
    scanf("%d", &Sal);
    if (Sal < 18000) { nuevosalario = Sal * 1.12;
        printf("El salario es menor a 18,000 pesos y incremento un 12 porciento.\n");
        printf("Salario original: %d\n", Sal);
        printf("Nuevo salario: %.2f\n", nuevosalario);
    } else if (Sal <= 30000) {
        nuevosalario = Sal * 1.08;
        printf("El salario esta entre 18,000 y 30,000 pesos entonces aumento un 8 porciento.\n");
        printf("Salario original: %d\n", Sal);
        printf("Nuevo salario: %.2f\n", nuevosalario);
    } else if (Sal <= 50000) {
        nuevosalario = Sal * 1.07;
        printf("El salario esta entre 30,000 y 50,000 pesos entonces aumento un 7 porciento.\n");
        printf("Salario original: %d\n", Sal);
        printf("Nuevo salario: %.2f\n", nuevosalario);
    } else if (Sal > 50000) {
    nuevosalario = Sal * 1.06;
    printf("El salario es mayor a 50,000 pesos entonces aumento un 6 porciento.\n");
    printf("Salario original: %d\n", Sal);
    printf("Nuevo salario: %.2f\n", nuevosalario);
    }
    return 0;
     }

