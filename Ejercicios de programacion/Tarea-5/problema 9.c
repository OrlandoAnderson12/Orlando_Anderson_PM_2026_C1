/* PS7_9.c */
#include <stdio.h>
#include <string.h>

int main(void) {
    char cad[51];
    printf("Ingrese la cadena: ");
    if (!fgets(cad, sizeof(cad), stdin)) return 1;
    size_t n=strlen(cad);
    if (n && (cad[n-1]=='\n'||cad[n-1]=='\r')) cad[--n]='\0';

    char *w[100]; int c=0;
    for (char *p=strtok(cad," "); p; p=strtok(NULL," ")) w[c++]=p;

    for (int i=c-1; i>=0; --i) {
        printf("%s", w[i]);
        if (i) putchar(' ');
    }
    putchar('\n');
    return 0;
}