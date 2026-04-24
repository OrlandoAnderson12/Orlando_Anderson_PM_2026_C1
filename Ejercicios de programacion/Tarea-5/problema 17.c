/* PS8_3.c */
#include <stdio.h>
#include <string.h>

#define MAXP 200

typedef struct {
    int num;
    char nombre[60];
    char depto[30];
    char puesto[40];
    char grado[30];
    char nac[30];
    double salario[12];
} Profesor;

int main(void){
    int n;
    printf("Numero de profesores (1..200): ");
    if (scanf("%d",&n)!=1 || n<1 || n>MAXP) return 1;
    int c; while((c=getchar())!='\n' && c!=EOF){}

    Profesor v[MAXP];
    for (int i=0;i<n;++i){
        printf("\nProfesor %d\n", i+1);
        printf("No empleado: "); scanf("%d",&v[i].num); while((c=getchar())!='\n'&&c!=EOF){}
        printf("Nombre y apellido: "); fgets(v[i].nombre, sizeof(v[i].nombre), stdin);
        size_t L=strlen(v[i].nombre); if(L&&v[i].nombre[L-1]=='\n') v[i].nombre[--L]='\0';
        printf("Departamento: "); fgets(v[i].depto, sizeof(v[i].depto), stdin);
        L=strlen(v[i].depto); if(L&&v[i].depto[L-1]=='\n') v[i].depto[--L]='\0';
        printf("Puesto: "); fgets(v[i].puesto, sizeof(v[i].puesto), stdin);
        L=strlen(v[i].puesto); if(L&&v[i].puesto[L-1]=='\n') v[i].puesto[--L]='\0';
        printf("Grado: "); fgets(v[i].grado, sizeof(v[i].grado), stdin);
        L=strlen(v[i].grado); if(L&&v[i].grado[L-1]=='\n') v[i].grado[--L]='\0';
        printf("Nacionalidad: "); fgets(v[i].nac, sizeof(v[i].nac), stdin);
        L=strlen(v[i].nac); if(L&&v[i].nac[L-1]=='\n') v[i].nac[--L]='\0';
        printf("12 salarios mensuales:\n");
        for (int m=0;m<12;++m) { printf(" Mes %2d: ", m+1); scanf("%lf",&v[i].salario[m]); }
        while((c=getchar())!='\n'&&c!=EOF){}
    }

    int idxMax=0; double totMax=-1;
    double totalUni=0, totalExtranjeros=0;
    // acumulador por departamento (max 100 distintos, usamos vector simple)
    char depN[100][30]; double depSum[100]={0}; int depCnt=0;

    for (int i=0;i<n;++i){
        double sum=0; for(int m=0;m<12;++m) sum+=v[i].salario[m];
        if (sum>totMax){ totMax=sum; idxMax=i; }
        totalUni += sum;

        if (strcasecmp(v[i].nac,"Colombia")!=0) totalExtranjeros += sum;

        // acum por depto
        int k=-1;
        for(int d=0; d<depCnt; ++d) if (strcasecmp(depN[d], v[i].depto)==0){k=d;break;}
        if (k<0 && depCnt<100){ k=depCnt++; strcpy(depN[k], v[i].depto); }
        depSum[k]+=sum;
    }

    // depto mayor egreso
    int kmax=0; for(int d=1; d<depCnt; ++d) if (depSum[d]>depSum[kmax]) kmax=d;

    printf("\n(a) Profesor con mayor ingreso anual:\n");
    printf("   %s | Dept: %s | Nac: %s | Total: %.2f\n", v[idxMax].nombre, v[idxMax].depto, v[idxMax].nac, totMax);

    printf("(b) Total a extranjeros: %.2f (%.2f%% del total %.2f)\n",
           totalExtranjeros, totalUni? (100.0*totalExtranjeros/totalUni):0.0, totalUni);

    printf("(c) Departamento con mayor egreso: %s (%.2f)\n", depN[kmax], depSum[kmax]);
    return 0;
}