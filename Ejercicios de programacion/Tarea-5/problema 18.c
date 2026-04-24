/* PS8_4.c */
#include <stdio.h>
#include <string.h>

#define MAXE 100

typedef struct {
    char calle_num[60], colonia[40], cp[12], ciudad[40], tel[20];
} Domicilio;

typedef struct {
    int num;
    char nombre[60];
    char depto[30];
    Domicilio dom;
    double salario;
} Empleado;

static int buscar(Empleado v[], int n, int num){
    int l=0,r=n-1;
    while(l<=r){
        int m=(l+r)/2;
        if(v[m].num==num) return m;
        if(v[m].num<num) l=m+1; else r=m-1;
    }
    return -l-1; // posicion de insercion negativa
}

int main(void){
    int n=0;
    Empleado v[MAXE];

    for(;;){
        int op;
        printf("\n1 Altas  2 Bajas  3 Listado por depto  0 Salir\nOpcion: ");
        if (scanf("%d",&op)!=1) return 1;
        int c; while((c=getchar())!='\n' && c!=EOF){}

        if (op==0) break;

        if (op==1){ // Altas
            if (n==MAXE){ printf("Arreglo lleno.\n"); continue; }
            Empleado e;
            printf("Numero: "); scanf("%d",&e.num); while((c=getchar())!='\n'&&c!=EOF){}
            int pos = buscar(v,n,e.num);
            if (pos>=0){ printf("Ya existe.\n"); continue; }
            pos = -pos-1;
            printf("Nombre: "); fgets(e.nombre,sizeof(e.nombre),stdin);
            size_t L=strlen(e.nombre); if(L&&e.nombre[L-1]=='\n') e.nombre[--L]='\0';
            printf("Departamento: "); fgets(e.depto,sizeof(e.depto),stdin);
            L=strlen(e.depto); if(L&&e.depto[L-1]=='\n') e.depto[--L]='\0';
            printf("Calle y numero: "); fgets(e.dom.calle_num,sizeof(e.dom.calle_num),stdin);
            L=strlen(e.dom.calle_num); if(L&&e.dom.calle_num[L-1]=='\n') e.dom.calle_num[--L]='\0';
            printf("Colonia: "); fgets(e.dom.colonia,sizeof(e.dom.colonia),stdin);
            L=strlen(e.dom.colonia); if(L&&e.dom.colonia[L-1]=='\n') e.dom.colonia[--L]='\0';
            printf("CP: "); fgets(e.dom.cp,sizeof(e.dom.cp),stdin);
            L=strlen(e.dom.cp); if(L&&e.dom.cp[L-1]=='\n') e.dom.cp[--L]='\0';
            printf("Ciudad: "); fgets(e.dom.ciudad,sizeof(e.dom.ciudad),stdin);
            L=strlen(e.dom.ciudad); if(L&&e.dom.ciudad[L-1]=='\n') e.dom.ciudad[--L]='\0';
            printf("Telefono: "); fgets(e.dom.tel,sizeof(e.dom.tel),stdin);
            L=strlen(e.dom.tel); if(L&&e.dom.tel[L-1]=='\n') e.dom.tel[--L]='\0';
            printf("Salario: "); scanf("%lf",&e.salario); while((c=getchar())!='\n'&&c!=EOF){}

            for (int i=n; i>pos; --i) v[i]=v[i-1];
            v[pos]=e; ++n;
            printf("Alta realizada.\n");
        }
        else if (op==2){ // Bajas
            int num; printf("Numero a eliminar: "); scanf("%d",&num); while((c=getchar())!='\n'&&c!=EOF){}
            int k = buscar(v,n,num);
            if (k<0){ printf("No existe.\n"); continue; }
            for (int i=k; i<n-1; ++i) v[i]=v[i+1];
            --n; printf("Baja realizada.\n");
        }
        else if (op==3){ // Listado
            char depto[30];
            printf("Departamento: "); fgets(depto,sizeof(depto),stdin);
            size_t L=strlen(depto); if(L&&depto[L-1]=='\n') depto[--L]='\0';
            printf("%-8s %-30s %10s\n","Numero","Nombre","Salario");
            for (int i=0;i<n;++i)
                if (strcasecmp(v[i].depto,depto)==0)
                    printf("%-8d %-30s %10.2f\n", v[i].num, v[i].nombre, v[i].salario);
        }
        else printf("Opcion invalida.\n");
    }
    return 0;
}