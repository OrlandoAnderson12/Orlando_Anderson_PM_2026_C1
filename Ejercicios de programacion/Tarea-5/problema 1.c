#include <stdio.h>
#include <string.h>

static void limpiar_fin_linea(char *s);

int main(void) {
    char cad[51];  // 50 max + '\0'
    printf("Ingrese la cadena: ");
    if (!fgets(cad, sizeof(cad), stdin)) return 1;

    limpiar_fin_linea(cad);
    size_t len = strlen(cad);

    printf("Caracteres en posiciones impares:\n");
    for (size_t i = 1; i < len; i += 2) {
        putchar(cad[i]);
    }
    putchar('\n');
    return 0;
}
