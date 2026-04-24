/* PS7_3.c */
#include <stdio.h>
#include <string.h>

int main(void) {
    char cad[31];  // 30 max + '\0'

    // Lee una linea (hasta 30 chars + '\0')
    if (!fgets(cad, sizeof(cad), stdin)) return 0;

    // Quitar fin de linea (soporta \n y \r\n)
    size_t len = strcspn(cad, "\r\n");
    cad[len] = '\0';

    // Rellenar con '-' hasta 30
    for (size_t i = len; i < 30; ++i) cad[i] = '-';
    cad[30] = '\0';

    // Imprime la cadena final (30 caracteres)
    puts(cad);
    return 0;
}