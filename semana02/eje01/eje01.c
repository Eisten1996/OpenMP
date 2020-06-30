#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

#define N 50000

void ceros(long n, int v[]);
void iniciar(long n, int v[]);
void sumar(long int ini, long int fin, int x[], int y[], int z[]);
void imprimir(long int ini, long int fin, int x[], int y[], int z[]);

int main()
{
    int a[N], b[N], c[N];
    double inicio, termino;

    srand(1000);
    // Inicializar a y b
    iniciar(N, a);
    iniciar(N, b);
    ceros(N, c);

    // suma secuencial
    // calculo del work(G)
    inicio = omp_get_wtime();
    sumar(0, N, a, b, c);
    termino = omp_get_wtime();
    printf("Demoro %f segundos \n", termino - inicio);
    // imprimir(0,10,a,b,c);

    // en paralelo 1

    // en paralelo forma 2

    return 0;
}

void ceros(long n, int v[])
{
    long i;
    for (i = 0; i < n; i++)
        v[i] = 0;
}

void iniciar(long n, int v[])
{
    long i;
    for (i = 0; i < n; i++)
        v[i] = rand();
}

void sumar(long int ini, long int fin, int x[], int y[], int z[])
{
    long i;
    for (i = ini; i < fin; i++)
        z[i] = x[i] + y[i];
}

void imprimir(long int ini, long int fin, int x[], int y[], int z[])
{
    long i;
    for (i = ini; i < fin; i++)
        printf("[%li] %d = %d + %d \n", i, z[i], x[i], y[i]);
}
