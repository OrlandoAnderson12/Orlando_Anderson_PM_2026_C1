/* PS7_6.c */
#include <stdio.h>
#include <string.h>

int main(void) {
    char resp;
    char cad[21];       // 20 + '\0'
    char mayor[21] = "";
    size_t len_mayor = 0;

    for (;;) {
        printf("Desea ingresar cadena? (S/N): ");
        if (scanf(" %c", &resp) != 1) return 1;
        int c; while ((c=getchar())!='\n' && c!=EOF){}  // limpia stdin
        if (resp!='S' && resp!='s') break;

        printf("Cadena (max 20): ");
        if (!fgets(cad, sizeof(cad), stdin)) return 1;
        size_t n = strlen(cad);
        if (n && (cad[n-1]=='\n'||cad[n-1]=='\r')) cad[--n]='\0';

        if (n > len_mayor) { strcpy(mayor, cad); len_mayor = n; }
    }

    if (len_mayor) printf("Cadena de mayor longitud:\n%s\n", mayor);
    else printf("No se ingresaron cadenas.\n");
    return 0;
}