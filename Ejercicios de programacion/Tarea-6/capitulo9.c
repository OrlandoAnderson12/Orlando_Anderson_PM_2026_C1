#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Prototipos */
void crearArchivo(const char *nombre, int n);
int leerArchivo(const char *nombre, int **vec);
void ordenar(int *vec, int n);
void grabarArchivoOrdenado(const char *nombre, int *vec, int n);
void imprimirVector(int *vec, int n);

int main(void)
{
    int n;
    int *numeros = NULL;

    printf("Ingrese la cantidad de numeros casuales: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("La cantidad debe ser mayor que 0.\n");
        return 1;
    }

    /* 1. Crear archivo con numeros casuales */
    crearArchivo("numeros.txt", n);

    /* 2. Leer todos los numeros usando memoria dinamica */
    n = leerArchivo("numeros.txt", &numeros);

    if (numeros == NULL || n == 0)
    {
        printf("No se pudieron leer los numeros del archivo.\n");
        return 1;
    }

    printf("\nNumeros leidos del archivo:\n");
    imprimirVector(numeros, n);

    /* 3. Ordenar los numeros en memoria */
    ordenar(numeros, n);

    printf("\nNumeros ordenados:\n");
    imprimirVector(numeros, n);

    /* 4. Grabar los numeros ordenados en otro archivo */
    grabarArchivoOrdenado("ordenados.txt", numeros, n);

    free(numeros);

    printf("\nProceso terminado. Se generaron los archivos:\n");
    printf(" - numeros.txt\n");
    printf(" - ordenados.txt\n");

    return 0;
}

void crearArchivo(const char *nombre, int n)
{
    FILE *archivo;
    int i, num;

    archivo = fopen(nombre, "w");
    if (archivo == NULL)
    {
        printf("No se pudo crear el archivo %s\n", nombre);
        exit(1);
    }

    srand((unsigned)time(NULL));

    for (i = 0; i < n; i++)
    {
        num = rand() % 1000; /* numeros entre 0 y 999 */
        fprintf(archivo, "%d ", num);
    }

    fclose(archivo);
}

int leerArchivo(const char *nombre, int **vec)
{
    FILE *archivo;
    int num, contador = 0, i;

    archivo = fopen(nombre, "r");
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo %s\n", nombre);
        return 0;
    }

    /* Contar cuantos numeros hay */
    while (fscanf(archivo, "%d", &num) == 1)
    {
        contador++;
    }

    if (contador == 0)
    {
        fclose(archivo);
        *vec = NULL;
        return 0;
    }

    *vec = (int *)malloc(contador * sizeof(int));
    if (*vec == NULL)
    {
        printf("No se pudo reservar memoria dinamica.\n");
        fclose(archivo);
        return 0;
    }

    rewind(archivo);

    for (i = 0; i < contador; i++)
    {
        fscanf(archivo, "%d", &((*vec)[i]));
    }

    fclose(archivo);
    return contador;
}

void ordenar(int *vec, int n)
{
    int i, j, aux;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
            }
        }
    }
}

void grabarArchivoOrdenado(const char *nombre, int *vec, int n)
{
    FILE *archivo;
    int i;

    archivo = fopen(nombre, "w");
    if (archivo == NULL)
    {
        printf("No se pudo crear el archivo %s\n", nombre);
        exit(1);
    }

    for (i = 0; i < n; i++)
    {
        fprintf(archivo, "%d ", vec[i]);
    }

    fclose(archivo);
}

void imprimirVector(int *vec, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}