#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int filas;
    int columnas;
    float **dato;
} Matriz;

/* Prototipos */
Matriz crearMatriz(int filas, int columnas);
void liberarMatriz(Matriz *m);
void imprimirMatriz(Matriz m);
void leerMatrizTeclado(Matriz m);
int cargarMatrizArchivo(const char *nombre, Matriz *m);

Matriz sumarMatrices(Matriz a, Matriz b);
Matriz restarMatrices(Matriz a, Matriz b);
Matriz multiplicarMatrices(Matriz a, Matriz b);
Matriz transpuesta(Matriz m);

int menuEntrada(void);

int main(void) {
    Matriz A = {0, 0, NULL};
    Matriz B = {0, 0, NULL};
    Matriz R = {0, 0, NULL};

    int opcion, forma;
    int filas, columnas;
    char archivo[100];

    do {
        printf("\n=== CALCULADORA DE MATRICES ===\n");
        printf("1. Sumar matrices\n");
        printf("2. Restar matrices\n");
        printf("3. Multiplicar matrices\n");
        printf("4. Transpuesta de una matriz\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        if (opcion >= 1 && opcion <= 3) {
            printf("\n--- MATRIZ A ---\n");
            forma = menuEntrada();

            if (forma == 1) {
                printf("Ingrese filas y columnas de A: ");
                scanf("%d %d", &filas, &columnas);
                A = crearMatriz(filas, columnas);
                leerMatrizTeclado(A);
            } else if (forma == 2) {
                printf("Nombre del archivo de A: ");
                scanf("%s", archivo);
                if (!cargarMatrizArchivo(archivo, &A)) {
                    printf("No se pudo cargar la matriz A.\n");
                    continue;
                }
            }

            printf("\n--- MATRIZ B ---\n");
            forma = menuEntrada();

            if (forma == 1) {
                printf("Ingrese filas y columnas de B: ");
                scanf("%d %d", &filas, &columnas);
                B = crearMatriz(filas, columnas);
                leerMatrizTeclado(B);
            } else if (forma == 2) {
                printf("Nombre del archivo de B: ");
                scanf("%s", archivo);
                if (!cargarMatrizArchivo(archivo, &B)) {
                    printf("No se pudo cargar la matriz B.\n");
                    liberarMatriz(&A);
                    continue;
                }
            }

            printf("\nMatriz A:\n");
            imprimirMatriz(A);
            printf("\nMatriz B:\n");
            imprimirMatriz(B);

            switch (opcion) {
                case 1:
                    if (A.filas == B.filas && A.columnas == B.columnas) {
                        R = sumarMatrices(A, B);
                        printf("\nResultado de A + B:\n");
                        imprimirMatriz(R);
                        liberarMatriz(&R);
                    } else {
                        printf("\nNo se pueden sumar: dimensiones diferentes.\n");
                    }
                    break;

                case 2:
                    if (A.filas == B.filas && A.columnas == B.columnas) {
                        R = restarMatrices(A, B);
                        printf("\nResultado de A - B:\n");
                        imprimirMatriz(R);
                        liberarMatriz(&R);
                    } else {
                        printf("\nNo se pueden restar: dimensiones diferentes.\n");
                    }
                    break;

                case 3:
                    if (A.columnas == B.filas) {
                        R = multiplicarMatrices(A, B);
                        printf("\nResultado de A * B:\n");
                        imprimirMatriz(R);
                        liberarMatriz(&R);
                    } else {
                        printf("\nNo se pueden multiplicar: columnas de A != filas de B.\n");
                    }
                    break;
            }

            liberarMatriz(&A);
            liberarMatriz(&B);
        }

        else if (opcion == 4) {
            printf("\n--- MATRIZ ---\n");
            forma = menuEntrada();

            if (forma == 1) {
                printf("Ingrese filas y columnas: ");
                scanf("%d %d", &filas, &columnas);
                A = crearMatriz(filas, columnas);
                leerMatrizTeclado(A);
            } else if (forma == 2) {
                printf("Nombre del archivo: ");
                scanf("%s", archivo);
                if (!cargarMatrizArchivo(archivo, &A)) {
                    printf("No se pudo cargar la matriz.\n");
                    continue;
                }
            }

            printf("\nMatriz original:\n");
            imprimirMatriz(A);

            R = transpuesta(A);
            printf("\nMatriz transpuesta:\n");
            imprimirMatriz(R);

            liberarMatriz(&A);
            liberarMatriz(&R);
        }

        else if (opcion != 0) {
            printf("\nOpcion no valida.\n");
        }

    } while (opcion != 0);

    printf("\nPrograma finalizado.\n");
    return 0;
}

int menuEntrada(void) {
    int op;
    printf("1. Ingresar matriz por teclado\n");
    printf("2. Cargar matriz desde archivo de texto\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &op);
    return op;
}

Matriz crearMatriz(int filas, int columnas) {
    Matriz m;
    int i;

    m.filas = filas;
    m.columnas = columnas;
    m.dato = (float **)malloc(filas * sizeof(float *));

    for (i = 0; i < filas; i++) {
        m.dato[i] = (float *)malloc(columnas * sizeof(float));
    }

    return m;
}

void liberarMatriz(Matriz *m) {
    int i;

    if (m->dato != NULL) {
        for (i = 0; i < m->filas; i++) {
            free(m->dato[i]);
        }
        free(m->dato);
    }

    m->dato = NULL;
    m->filas = 0;
    m->columnas = 0;
}

void leerMatrizTeclado(Matriz m) {
    int i, j;

    for (i = 0; i < m.filas; i++) {
        for (j = 0; j < m.columnas; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%f", &m.dato[i][j]);
        }
    }
}

void imprimirMatriz(Matriz m) {
    int i, j;

    for (i = 0; i < m.filas; i++) {
        for (j = 0; j < m.columnas; j++) {
            printf("%8.2f ", m.dato[i][j]);
        }
        printf("\n");
    }
}

int cargarMatrizArchivo(const char *nombre, Matriz *m) {
    FILE *archivo;
    char linea[1024];
    int filas = 0, columnas = 0;
    int i, j;
    char *token;

    archivo = fopen(nombre, "r");
    if (archivo == NULL) {
        return 0;
    }

    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        int cuenta = 0;
        token = strtok(linea, ",\n");
        while (token != NULL) {
            cuenta++;
            token = strtok(NULL, ",\n");
        }

        if (cuenta == 0) {
            continue;
        }

        if (columnas == 0) {
            columnas = cuenta;
        } else if (cuenta != columnas) {
            fclose(archivo);
            return 0;
        }

        filas++;
    }

    if (filas == 0 || columnas == 0) {
        fclose(archivo);
        return 0;
    }

    *m = crearMatriz(filas, columnas);

    rewind(archivo);

    i = 0;
    while (fgets(linea, sizeof(linea), archivo) != NULL && i < filas) {
        j = 0;
        token = strtok(linea, ",\n");
        while (token != NULL && j < columnas) {
            m->dato[i][j] = (float)atof(token);
            token = strtok(NULL, ",\n");
            j++;
        }
        i++;
    }

    fclose(archivo);
    return 1;
}

Matriz sumarMatrices(Matriz a, Matriz b) {
    Matriz r = crearMatriz(a.filas, a.columnas);
    int i, j;

    for (i = 0; i < a.filas; i++) {
        for (j = 0; j < a.columnas; j++) {
            r.dato[i][j] = a.dato[i][j] + b.dato[i][j];
        }
    }

    return r;
}

Matriz restarMatrices(Matriz a, Matriz b) {
    Matriz r = crearMatriz(a.filas, a.columnas);
    int i, j;

    for (i = 0; i < a.filas; i++) {
        for (j = 0; j < a.columnas; j++) {
            r.dato[i][j] = a.dato[i][j] - b.dato[i][j];
        }
    }

    return r;
}

Matriz multiplicarMatrices(Matriz a, Matriz b) {
    Matriz r = crearMatriz(a.filas, b.columnas);
    int i, j, k;

    for (i = 0; i < a.filas; i++) {
        for (j = 0; j < b.columnas; j++) {
            r.dato[i][j] = 0;
            for (k = 0; k < a.columnas; k++) {
                r.dato[i][j] += a.dato[i][k] * b.dato[k][j];
            }
        }
    }

    return r;
}

Matriz transpuesta(Matriz m) {
    Matriz r = crearMatriz(m.columnas, m.filas);
    int i, j;

    for (i = 0; i < m.filas; i++) {
        for (j = 0; j < m.columnas; j++) {
            r.dato[j][i] = m.dato[i][j];
        }
    }

    return r;
}