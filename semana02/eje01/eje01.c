#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

#define N 100000

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
    // imprimir(0, N, a, b, c);
    printf("Demoro %f segundos \n", termino - inicio);

// en paralelo 1
#pragma omp parallel
    {
        inicio = omp_get_wtime();

#pragma omp for
        for (int i = 1; i <= N; i++)
        {
            // if (omp_get_thread_num() == 0 && i > 0 && i <= N / 4)
            // {
            //     c[i] = a[i] + b[i];
            // }
            // else if (omp_get_thread_num() == 0 && i > N / 4 && i <= N / 2)
            // {
            //     c[i] = a[i] + b[i];
            // }
            // else if (omp_get_thread_num() == 0 && i > N / 2 && i <= 3 * N / 4)
            // {
            //     c[i] = a[i] + b[i];
            // }
            // else if (omp_get_thread_num() == 0 && i > 3 * N / 4 && i <= N)
            // {
            //     c[i] = a[i] + b[i];
            // }
            c[i] = a[i] + b[i];
        }
        termino = omp_get_wtime();
    }
    // imprimir(0, N, a, b, c);
    printf("Demoro %f segundos \n", termino - inicio);

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
