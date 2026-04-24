/* PS7_12.c */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

    int idx=0, maxc=-1;
    for (int i=0;i<n;++i){
        int cMay=0;
        for (size_t k=0; arc[i][k]; ++k) if (isupper((unsigned char)arc[i][k])) ++cMay;
        if (cMay>maxc){maxc=cMay; idx=i;}
    }
    printf("Cadena con mas mayusculas:\n%s\n", arc[idx]);
    return 0;
}