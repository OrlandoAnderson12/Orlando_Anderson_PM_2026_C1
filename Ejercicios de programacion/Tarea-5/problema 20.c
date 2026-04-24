#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXP 100

typedef struct {
    int clave;          // clave del producto
    char nombre[60];    // nombre del producto (cadena)
    int existencia;     // existencia (unidades)
} Producto;

/* Busca la posicion de una clave. Retorna indice (0..n-1) o -1 si no existe */
static int buscar_por_clave(Producto v[], int n, int clave) {
    for (int i = 0; i < n; ++i) {
        if (v[i].clave == clave) return i;
    }
    return -1;
}

/* Ordenar por clave ascendente (burbuja simple; n <= 100) */
static void ordenar_por_clave(Producto v[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (v[j].clave < v[i].clave) {
                Producto tmp = v[i]; v[i] = v[j]; v[j] = tmp;
            }
        }
    }
}

int main(void) {
    int N;
    Producto tienda[MAXP];

    /* ---- Carga inicial ---- */
    printf("Numero de productos (1..100): ");
    if (scanf("%d", &N) != 1 || N < 1 || N > MAXP) return 1;
    int ch; while ((ch = getchar()) != '\n' && ch != EOF) {}  // limpia stdin

    for (int i = 0; i < N; ++i) {
        printf("\nProducto %d\n", i + 1);
        printf("Clave: ");
        if (scanf("%d", &tienda[i].clave) != 1) return 1;
        while ((ch = getchar()) != '\n' && ch != EOF) {}

        printf("Nombre: ");
        if (!fgets(tienda[i].nombre, sizeof(tienda[i].nombre), stdin)) return 1;
        size_t L = strlen(tienda[i].nombre);
        if (L && (tienda[i].nombre[L - 1] == '\n' || tienda[i].nombre[L - 1] == '\r'))
            tienda[i].nombre[--L] = '\0';

        printf("Existencia: ");
        if (scanf("%d", &tienda[i].existencia) != 1) return 1;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
    }

    /* (Opcional) ordenar por clave para facilitar lectura al final */
    ordenar_por_clave(tienda, N);

    /* ---- Procesamiento de transacciones ----
       Formato de cada linea:
           OPE CLA CAN
       con OPE en {'c','v'} o '0' para terminar.
    */
    printf("\nTransacciones (OPE CLA CAN). Termine con: 0 0 0\n");
    for (;;) {
        char ope;
        int cla, can;

        /* Leemos con espacios tolerantes: 'c 123 5' o 'c,123,5' (usaremos scanf que ignora comas si ponemos %*[, ]). 
           Para máxima robustez con las comas del libro, leemos una linea y la parseamos con sscanf flexible. */
        char linea[128];
        if (!fgets(linea, sizeof(linea), stdin)) break;

        /* Intentar leer en cualquiera de estos formatos:
           - "c 123 5"
           - "c, 123, 5"
           - "c  ,123 ,   5"
           - "0 0 0"
        */
        int ok = 0;
        if (sscanf(linea, " %c %d %d", &ope, &cla, &can) == 3) {
            ok = 1;
        } else if (sscanf(linea, " %c , %d , %d", &ope, &cla, &can) == 3) {
            ok = 1;
        } else if (sscanf(linea, " %c , %d %d", &ope, &cla, &can) == 3) {
            ok = 1;
        }

        if (!ok) {
            /* Linea vacia o formato no valido: ignorar y continuar */
            continue;
        }

        if (ope == '0' && cla == 0 && can == 0) {
            /* Fin de datos */
            break;
        }

        /* Normalizar operacion a minuscula */
        ope = (char)tolower((unsigned char)ope);

        int idx = buscar_por_clave(tienda, N, cla);
        if (idx < 0) {
            printf("Clave %d no encontrada. Transaccion ignorada.\n", cla);
            continue;
        }

        if (ope == 'c') {
            /* Compras: aumentan existencia */
            if (can < 0) { printf("Cantidad invalida.\n"); continue; }
            tienda[idx].existencia += can;
        } else if (ope == 'v') {
            /* Ventas: disminuyen existencia; validar stock */
            if (can < 0) { printf("Cantidad invalida.\n"); continue; }
            if (tienda[idx].existencia >= can) {
                tienda[idx].existencia -= can;
            } else {
                printf("Existencia insuficiente para clave %d. Venta rechazada.\n", cla);
            }
        } else {
            printf("Operacion desconocida '%c'. Use 'c' o 'v'.\n", ope);
        }
    }

    /* ---- Salida final: inventario actualizado ---- */
    ordenar_por_clave(tienda, N);
    printf("\nInventario actualizado:\n");
    printf("%-8s  %-30s  %s\n", "Clave", "Nombre", "Existencia");
    for (int i = 0; i < N; ++i) {
        printf("%-8d  %-30s  %d\n", tienda[i].clave, tienda[i].nombre, tienda[i].existencia);
    }

    return 0;
}