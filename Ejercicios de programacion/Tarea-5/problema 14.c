/* PS7_14.c */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define FILAS 10
#define COLS  51
#define MAXW  500   // maximo aproximado de palabras

static void extraer_palabras(char arc[FILAS][COLS], int n, char words[MAXW][COLS], int *cw){
    *cw = 0;
    for (int i=0;i<n;++i){
        const char *s = arc[i];
        char w[COLS]; int k=0;
        for (size_t j=0;;++j){
            int ch = (unsigned char)s[j];
            int es = isalnum(ch);
            if (es) { if (k<COLS-1) w[k++]=(char)ch; }
            if (!es || ch==0){
                if (k>0){
                    w[k]='\0';
                    if (*cw < MAXW) strcpy(words[(*cw)++], w);
                    k=0;
                }
                if (ch==0) break;
            }
        }
    }
}

int main(void){
    int n; printf("Cuantas cadenas (1..10): ");
    if (scanf("%d",&n)!=1||n<1||n>10) return 1;
    int c; while((c=getchar())!='\n' && c!=EOF){}

    char arc[FILAS][COLS];
    for (int i=0;i<n;++i){
        printf("Cadena %d: ", i+1);
        if (!fgets(arc[i], sizeof(arc[i]), stdin)) return 1;
        size_t L=strlen(arc[i]); if(L && (arc[i][L-1]=='\n'||arc[i][L-1]=='\r')) arc[i][--L]='\0';
    }

    char words[MAXW][COLS]; int cw=0;
    extraer_palabras(arc, n, words, &cw);

    // orden estable por longitud (insercion)
    for (int i=1;i<cw;++i){
        char key[COLS]; strcpy(key, words[i]);
        int j=i-1;
        while (j>=0 && strlen(words[j]) > strlen(key)) {
            strcpy(words[j+1], words[j]);
            --j;
        }
        strcpy(words[j+1], key);
    }

    // armar salida
    char out[5000]="";
    for (int i=0;i<cw;++i){
        if (i) strcat(out," ");
        strcat(out, words[i]);
    }
    printf("%s\n", out);
    return 0;
}