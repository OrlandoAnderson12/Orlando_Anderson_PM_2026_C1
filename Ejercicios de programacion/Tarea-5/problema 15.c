/* PS8_1.c */
#include <stdio.h>
#include <string.h>

#define MAXC 100

typedef struct {
    char calle_num[60], cp[12], colonia[40], ciudad[40], telefono[20];
} Domicilio;

typedef struct {
    long cuenta;
    char nombre[60];
    Domicilio dom;
    double saldo;
} Cliente;

static int buscar(Cliente v[], int n, long cuenta){
    int l=0, r=n-1;
    while(l<=r){
        int m=(l+r)/2;
        if (v[m].cuenta==cuenta) return m;
        if (v[m].cuenta<cuenta) l=m+1; else r=m-1;
    }
    return -1;
}

int main(void){
    int n;
    printf("Numero de clientes (1..100): ");
    if (scanf("%d",&n)!=1 || n<1 || n>MAXC) return 1;
    int c; while((c=getchar())!='\n' && c!=EOF){}

    Cliente cli[MAXC];
    printf("Ingrese datos ordenados por numero de cuenta ascendente\n");
    for (int i=0;i<n;++i){
        printf("\nCliente %d\n", i+1);
        printf("Cuenta: "); scanf("%ld",&cli[i].cuenta); while((c=getchar())!='\n'&&c!=EOF){}
        printf("Nombre: "); fgets(cli[i].nombre, sizeof(cli[i].nombre), stdin);
        size_t L=strlen(cli[i].nombre); if(L&&cli[i].nombre[L-1]=='\n') cli[i].nombre[--L]='\0';
        printf("Calle y numero: "); fgets(cli[i].dom.calle_num, sizeof(cli[i].dom.calle_num), stdin);
        L=strlen(cli[i].dom.calle_num); if(L&&cli[i].dom.calle_num[L-1]=='\n') cli[i].dom.calle_num[--L]='\0';
        printf("Codigo Postal: "); fgets(cli[i].dom.cp, sizeof(cli[i].dom.cp), stdin);
        L=strlen(cli[i].dom.cp); if(L&&cli[i].dom.cp[L-1]=='\n') cli[i].dom.cp[--L]='\0';
        printf("Colonia: "); fgets(cli[i].dom.colonia, sizeof(cli[i].dom.colonia), stdin);
        L=strlen(cli[i].dom.colonia); if(L&&cli[i].dom.colonia[L-1]=='\n') cli[i].dom.colonia[--L]='\0';
        printf("Ciudad: "); fgets(cli[i].dom.ciudad, sizeof(cli[i].dom.ciudad), stdin);
        L=strlen(cli[i].dom.ciudad); if(L&&cli[i].dom.ciudad[L-1]=='\n') cli[i].dom.ciudad[--L]='\0';
        printf("Telefono: "); fgets(cli[i].dom.telefono, sizeof(cli[i].dom.telefono), stdin);
        L=strlen(cli[i].dom.telefono); if(L&&cli[i].dom.telefono[L-1]=='\n') cli[i].dom.telefono[--L]='\0';
        printf("Saldo inicial: "); scanf("%lf",&cli[i].saldo); while((c=getchar())!='\n'&&c!=EOF){}
    }

    printf("\nTransacciones (cuenta 0 para terminar)\n");
    for (;;) {
        long cta; double monto; int tipo;
        printf("Cuenta: ");
        if (scanf("%ld",&cta)!=1) return 1;
        if (cta==0) break;
        int k = buscar(cli, n, cta);
        if (k<0){ printf("Cuenta no encontrada.\n"); while((c=getchar())!='\n'&&c!=EOF){} continue; }
        printf("Tipo (1=deposito, 2=retiro): "); scanf("%d",&tipo);
        printf("Monto: "); scanf("%lf",&monto);
        while((c=getchar())!='\n'&&c!=EOF){}
        if (tipo==1){
            cli[k].saldo += monto;
            printf("Nuevo saldo: %.2f\n", cli[k].saldo);
        } else if (tipo==2){
            if (cli[k].saldo >= monto){
                cli[k].saldo -= monto;
                printf("Nuevo saldo: %.2f\n", cli[k].saldo);
            } else {
                printf("Saldo insuficiente. Operacion no autorizada.\n");
            }
        } else {
            printf("Tipo invalido.\n");
        }
    }

    puts("\nSaldos finales:");
    for (int i=0;i<n;++i)
        printf("%ld  %s  Saldo: %.2f\n", cli[i].cuenta, cli[i].nombre, cli[i].saldo);
    return 0;
}