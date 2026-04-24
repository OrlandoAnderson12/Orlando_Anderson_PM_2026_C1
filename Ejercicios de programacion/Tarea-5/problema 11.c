/* PS7_11.c */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

static int es_vocal(unsigned char c){
    c=(unsigned char)tolower(c);
    const char *v="aeiou";
    for (const char *p=v; *p; ++p) if (c==(unsigned char)*p) return 1;
    // opcional: acentuadas
    const char *ac = "\xC3\xA1\xC3\xA9\xC3\xAD\xC3\xB3\xC3\xBA"; // si usas UTF-8 en fuente/terminal
    (void)ac; // ignora si no usas UTF-8
    return 0;
}

int main(void){
    int n;
    printf("Cuantas cadenas (1..10): ");
    if (scanf("%d",&n)!=1 || n<1 || n>10) return 1;
    int c; while((c=getchar())!='\n' && c!=EOF){}

    char arc[10][51];
    for(int i=0;i<n;++i){
        printf("Cadena %d: ", i+1);
        if(!fgets(arc[i], sizeof(arc[i]), stdin)) return 1;
        size_t L=strlen(arc[i]);
        if(L && (arc[i][L-1]=='\n'||arc[i][L-1]=='\r')) arc[i][--L]='\0';
    }

    int idx=0, maxv=-1;
    for(int i=0;i<n;++i){
        int v=0;
        for(size_t k=0; arc[i][k]; ++k) if (es_vocal((unsigned char)arc[i][k])) ++v;
        if (v>maxv){maxv=v; idx=i;}
    }
    printf("Cadena con mas vocales:\n%s\n", arc[idx]);
    return 0;
}