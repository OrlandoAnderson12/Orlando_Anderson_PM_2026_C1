/* PS7_10.c */
#include <stdio.h>
#include <string.h>
#include <time.h>

int main(void) {
    char hoy[11]; // dd/mm/aaaa
    time_t t = time(NULL);
    struct tm *lt = localtime(&t);
    strftime(hoy, sizeof(hoy), "%d/%m/%Y", lt);

    char resp, cad[51];
    for (;;) {
        printf("Desea ingresar cadena? (S/N): ");
        if (scanf(" %c", &resp) != 1) return 1;
        int c; while((c=getchar())!='\n' && c!=EOF) {}
        if (resp!='S' && resp!='s') break;

        printf("Cadena (formato dd/mm/aaaa ...): ");
        if (!fgets(cad, sizeof(cad), stdin)) return 1;
        size_t n=strlen(cad);
        if (n && (cad[n-1]=='\n'||cad[n-1]=='\r')) cad[--n]='\0';

        if (n>=10 && strncmp(cad, hoy, 10)==0) {
            printf("%s\n", cad);
        }
    }
    return 0;
}