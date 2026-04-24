/* PS7_5.c */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char cad[51];  // 50 + '\0'
    printf("Ingrese la cadena: ");
    if (!fgets(cad, sizeof(cad), stdin)) return 1;

    size_t n = strlen(cad);
    if (n && (cad[n-1]=='\n'||cad[n-1]=='\r')) cad[--n]='\0';

    int inicio = 1;
    for (size_t i = 0; i < n; ++i) {
        if (inicio && isalpha((unsigned char)cad[i]) && islower((unsigned char)cad[i])) {
            cad[i] = (char)toupper((unsigned char)cad[i]);
            inicio = 0;
        } else if (cad[i]==' ') {
            inicio = 1;
        } else {
            inicio = 0;
        }
    }

    printf("%s\n", cad);
    return 0;
}