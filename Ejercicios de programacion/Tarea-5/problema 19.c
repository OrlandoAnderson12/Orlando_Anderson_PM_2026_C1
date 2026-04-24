/* PS8_6.c */
#include <stdio.h>
#include <string.h>

#define MAXA 1000
#define MAT 7

typedef struct { char materia[30]; double prom; } Calif;

typedef struct {
    int matricula;
    char nombre[60];
    struct { char calle_num[60]; int cp; char colonia[40]; char ciudad[40]; char tel[20]; } dom;
    struct { char nivel[20]; int grado; int salon; } niv;
    Calif cal[MAT];
} Alumno;

static double promedio(const Alumno *a){
    double s=0; for (int i=0;i<MAT;++i) s += a->cal[i].prom; return s/MAT;
}

int main(void){
    int n;
    printf("Numero de alumnos (1..1000): ");
    if (scanf("%d",&n)!=1 || n<1 || n>MAXA) return 1;
    int c; while((c=getchar())!='\n'&&c!=EOF){}

    Alumno v[MAXA];
    for (int i=0;i<n;++i){
        printf("\nAlumno %d\n", i+1);
        printf("Matricula: "); scanf("%d",&v[i].matricula); while((c=getchar())!='\n'&&c!=EOF){}
        printf("Nombre: "); fgets(v[i].nombre,sizeof(v[i].nombre),stdin);
        size_t L=strlen(v[i].nombre); if(L&&v[i].nombre[L-1]=='\n') v[i].nombre[--L]='\0';
        printf("Domicilio - calle y numero: "); fgets(v[i].dom.calle_num,sizeof(v[i].dom.calle_num),stdin);
        L=strlen(v[i].dom.calle_num); if(L&&v[i].dom.calle_num[L-1]=='\n') v[i].dom.calle_num[--L]='\0';
        printf("Codigo Postal: "); scanf("%d",&v[i].dom.cp); while((c=getchar())!='\n'&&c!=EOF){}
        printf("Colonia: "); fgets(v[i].dom.colonia,sizeof(v[i].dom.colonia),stdin);
        L=strlen(v[i].dom.colonia); if(L&&v[i].dom.colonia[L-1]=='\n') v[i].dom.colonia[--L]='\0';
        printf("Ciudad: "); fgets(v[i].dom.ciudad,sizeof(v[i].dom.ciudad),stdin);
        L=strlen(v[i].dom.ciudad); if(L&&v[i].dom.ciudad[L-1]=='\n') v[i].dom.ciudad[--L]='\0';
        printf("Telefono: "); fgets(v[i].dom.tel,sizeof(v[i].dom.tel),stdin);
        L=strlen(v[i].dom.tel); if(L&&v[i].dom.tel[L-1]=='\n') v[i].dom.tel[--L]='\0';

        printf("Nivel (primaria/secundaria/preparatoria): ");
        fgets(v[i].niv.nivel,sizeof(v[i].niv.nivel),stdin);
        L=strlen(v[i].niv.nivel); if(L&&v[i].niv.nivel[L-1]=='\n') v[i].niv.nivel[--L]='\0';
        printf("Grado: "); scanf("%d",&v[i].niv.grado);
        printf("Salon: "); scanf("%d",&v[i].niv.salon); while((c=getchar())!='\n'&&c!=EOF){}

        for (int m=0;m<MAT;++m){
            printf("Materia %d: ", m+1); fgets(v[i].cal[m].materia,sizeof(v[i].cal[m].materia),stdin);
            L=strlen(v[i].cal[m].materia); if(L&&v[i].cal[m].materia[L-1]=='\n') v[i].cal[m].materia[--L]='\0';
            printf("Promedio: "); scanf("%lf",&v[i].cal[m].prom); while((c=getchar())!='\n'&&c!=EOF){}
        }
    }

    for(;;){
        int op; printf("\n1 Promedio por matricula  2 Listado por nivel/grado/salon  0 Salir\nOpcion: ");
        if (scanf("%d",&op)!=1) return 1;
        int c; while((c=getchar())!='\n'&&c!=EOF){}
        if (op==0) break;

        if (op==1){
            int mat; printf("Matricula: "); scanf("%d",&mat); while((c=getchar())!='\n'&&c!=EOF){}
            int k=-1; for (int i=0;i<n;++i) if (v[i].matricula==mat){k=i;break;}
            if (k<0) printf("No existe.\n");
            else printf("Alumno: %s  Promedio general: %.2f\n", v[k].nombre, promedio(&v[k]));
        } else if (op==2){
            char nivel[20]; int grado, salon;
            printf("Nivel: "); fgets(nivel,sizeof(nivel),stdin);
            size_t L=strlen(nivel); if(L&&nivel[L-1]=='\n') nivel[--L]='\0';
            printf("Grado: "); scanf("%d",&grado);
            printf("Salon: "); scanf("%d",&salon); while((c=getchar())!='\n'&&c!=EOF){}
            printf("%-10s %-30s %-8s\n","Matricula","Nombre","Prom");
            for (int i=0;i<n;++i)
                if (strcasecmp(v[i].niv.nivel,nivel)==0 && v[i].niv.grado==grado && v[i].niv.salon==salon)
                    printf("%-10d %-30s %-8.2f\n", v[i].matricula, v[i].nombre, promedio(&v[i]));
        } else {
            printf("Opcion invalida.\n");
        }
    }
    return 0;
}