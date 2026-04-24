/* PS8_2.c */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXE 20

typedef struct {
    char nombre[40];
    int J,G,E,P,GF,GC,DF,PTS;
    int activo; // 1 si existe
} Equipo;

static void trim(char *s){
    size_t n=strlen(s);
    while(n && isspace((unsigned char)s[n-1])) s[--n]='\0';
    size_t i=0; while(isspace((unsigned char)s[i])) ++i;
    if (i) memmove(s, s+i, n+1-i);
}

static int buscar(Equipo t[], int *n, const char *nom){
    for (int i=0;i<*n;++i) if (t[i].activo && strcasecmp(t[i].nombre, nom)==0) return i;
    if (*n<MAXE){
        strcpy(t[*n].nombre, nom);
        t[*n].J=t[*n].G=t[*n].E=t[*n].P=t[*n].GF=t[*n].GC=t[*n].DF=t[*n].PTS=0;
        t[*n].activo=1;
        return (*n)++;
    }
    return -1;
}

static void ordenar(Equipo t[], int n){
    for (int i=0;i<n-1;++i)
        for (int j=i+1;j<n;++j){
            int a=t[i].PTS, b=t[j].PTS;
            int ad=t[i].DF, bd=t[j].DF;
            int ag=t[i].GF, bg=t[j].GF;
            if (b>a || (b==a && (bd>ad || (bd==ad && bg>ag)))){
                Equipo tmp=t[i]; t[i]=t[j]; t[j]=tmp;
            }
        }
}

int main(void){
    Equipo T[MAXE]={0}; int n=0;
    char linea[128];

    printf("Ingrese resultados (\"FIN\" para terminar)\n");
    while (1){
        if (!fgets(linea,sizeof(linea),stdin)) return 1;
        size_t L=strlen(linea); if(L&&(linea[L-1]=='\n'||linea[L-1]=='\r')) linea[--L]='\0';
        if (strcasecmp(linea,"FIN")==0) break;
        if (!*linea) continue;

        // divide por '-'
        char *mitad = strchr(linea, '-');
        if (!mitad){ printf("Formato invalido.\n"); continue; }
        *mitad = '\0';
        char izq[64], der[64];
        strcpy(izq, linea);
        strcpy(der, mitad+1);
        trim(izq); trim(der);

        // en cada mitad, el ultimo token es el marcador entero
        int g1, g2;
        // separa marcador desde el final
        char *p = izq + strlen(izq) - 1;
        while (p>izq && isdigit((unsigned char)*p)) --p;
        g1 = atoi(p+1); if (p>izq && isspace((unsigned char)*p)) *p='\0'; else *(p+1)='\0';
        trim(izq);

        p = der + strlen(der) - 1;
        while (p>der && isdigit((unsigned char)*p)) --p;
        g2 = atoi(p+1); if (p>der && isspace((unsigned char)*p)) *p='\0'; else *(p+1)='\0';
        trim(der);

        int i = buscar(T, &n, izq);
        int j = buscar(T, &n, der);
        if (i<0 || j<0){ printf("Demasiados equipos.\n"); break; }

        T[i].J++; T[j].J++;
        T[i].GF += g1; T[i].GC += g2;
        T[j].GF += g2; T[j].GC += g1;
        T[i].DF = T[i].GF - T[i].GC;
        T[j].DF = T[j].GF - T[j].GC;

        if (g1>g2){ T[i].G++; T[i].PTS+=3; T[j].P++; }
        else if (g2>g1){ T[j].G++; T[j].PTS+=3; T[i].P++; }
        else { T[i].E++; T[j].E++; T[i].PTS++; T[j].PTS++; }
    }

    ordenar(T,n);
    printf("\nTabla de posiciones:\n");
    printf("%-20s %2s %2s %2s %2s %3s %3s %3s %3s\n","Equipo","J","G","E","P","GF","GC","DF","PTS");
    for (int i=0;i<n;++i)
        printf("%-20s %2d %2d %2d %2d %3d %3d %3d %3d\n",
               T[i].nombre, T[i].J,T[i].G,T[i].E,T[i].P,T[i].GF,T[i].GC,T[i].DF,T[i].PTS);
    return 0;
}