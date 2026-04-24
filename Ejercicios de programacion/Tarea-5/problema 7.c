/* PS7_7.c */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char cad[31];
    printf("Numero telefonico (solo digitos, ej 5256284000): ");
    if (!fgets(cad, sizeof(cad), stdin)) return 1;
    size_t n = strlen(cad);
    if (n && (cad[n-1]=='\n'||cad[n-1]=='\r')) cad[--n]='\0';

    // valida y cuenta digitos
    size_t dig=0;
    for (size_t i=0;i<n;++i) if (isdigit((unsigned char)cad[i])) ++dig;
    if (dig < 4) { printf("Entrada invalida.\n"); return 0; }

    // toma los primeros 2, luego 1, luego resto (solo digitos)
    char cc[3]={0}, area[2]={0}, resto[30]={0};
    size_t k=0, i=0;

    // cc (2)
    while (i<n && !isdigit((unsigned char)cad[i])) ++i;
    for (int t=0; t<2 && i<n; ++t){ while(i<n && !isdigit((unsigned char)cad[i])) ++i; if(i<n) cc[t]=cad[i++]; }
    // area (1)
    while(i<n && !isdigit((unsigned char)cad[i])) ++i; if (i<n) area[0]=cad[i++];
    // resto
    while(i<n){ if (isdigit((unsigned char)cad[i])) resto[k++]=cad[i]; ++i; }

    printf("Nueva cadena: (%s): %s-%s\n", cc, area, resto);
    return 0;
}