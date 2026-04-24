/* PS7_8.c */
#include <stdio.h>
#include <string.h>

int main(void) {
    char cad1[51], cad2[51];
    printf("Cadena 1: "); if (!fgets(cad1, sizeof(cad1), stdin)) return 1;
    printf("Cadena 2: "); if (!fgets(cad2, sizeof(cad2), stdin)) return 1;
    size_t n1=strlen(cad1), n2=strlen(cad2);
    if (n1 && (cad1[n1-1]=='\n'||cad1[n1-1]=='\r')) cad1[--n1]='\0';
    if (n2 && (cad2[n2-1]=='\n'||cad2[n2-1]=='\r')) cad2[--n2]='\0';

    // tokeniza por espacios
    char *w1[100], *w2[100]; int c1=0, c2=0;
    for (char *p=strtok(cad1," "); p; p=strtok(NULL," ")) w1[c1++]=p;
    for (char *p=strtok(cad2," "); p; p=strtok(NULL," ")) w2[c2++]=p;

    char out[200]="";
    int i=0,j=0; int first=1;
    while (i<c1 || j<c2) {
        if (i<c1) { if(!first) strcat(out," "); strcat(out, w1[i++]); first=0; }
        if (j<c2) { if(!first) strcat(out," "); strcat(out, w2[j++]); first=0; }
    }
    printf("%s\n", out);
    return 0;
}