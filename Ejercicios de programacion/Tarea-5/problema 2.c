#include <stdio.h>
#include <string.h>
#include <ctype.h>

static void limpiar_fin_linea(char *s) {
    size_t len = strlen(s);
    while (len > 0 && (s[len - 1] == '\n' || s[len - 1] == '\r')) {
        s[--len] = '\0';
    }
}

int main(void) {
    char cad[51];  // 50 + '\0'
    printf("Ingrese la cadena: ");
    if (!fgets(cad, sizeof(cad), stdin)) return 1;

    limpiar_fin_linea(cad);
    size_t len = strlen(cad);

    printf("Digitos en posiciones pares (contando desde 1):\n");
    // i = 1 → posicion 2 (par 1-based), luego 3,5,7...
    for (size_t i = 1; i < len; i += 2) {
        if (isdigit((unsigned char)cad[i])) {
            putchar(cad[i]);           // ¡ojo: %c o putchar, nunca %d!
        }
    }
    putchar('\n');
    return 0;
}