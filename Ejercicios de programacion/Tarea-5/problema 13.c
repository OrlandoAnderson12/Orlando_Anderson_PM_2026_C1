/* PS7_13.c */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

static int contar_palabras(const char* s){
    int en=0, cnt=0;
    for (size_t i=0; s[i]; ++i){
        if (!isspace((unsigned char)s[i])) { if(!en){++cnt; en=1;} }
        else en=0;
    }
    return cnt;
}

int main(void){
    int n; printf("Cuantas cadenas (1..10): ");
    if (scanf("%d",&n)!=1||n<1||n>10) return 1;
    int c; while((c=getchar())!='\n' && c!=EOF){}

    char arc[10][51];
    for (int i=0;i<n;++i){
        printf("Cadena %d: ", i+1);
        if (!fgets(arc[i], sizeof(arc[i]), stdin)) return 1;
        size_t L=strlen(arc[i]); if(L && (arc[i][L-1]=='\n'||arc[i][L-1]=='\r')) arc[i][--L]='\0';
    }

    for (int i=0;i<n;++i){
        printf("Cadena %d -> %d palabras\n", i+1, contar_palabras(arc[i]));
    }
    return 0;
}