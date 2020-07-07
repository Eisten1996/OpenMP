#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#define N 10000

int main()
{
    double inicio, termino;

    // #pragma omp parallel
    //     {
    //         int threadnum = omp_get_thread_num(),
    //             numthreads = omp_get_num_threads();
    //         int low = N * threadnum / numthreads,
    //             high = N * (threadnum + 1) / numthreads;
    //         for (int i = low; i < high; i++)
    //         {
    //             printf("GAAAAAAA %d\n", omp_get_thread_num());
    //         }
    //         // do something with i
    //     }
    //     printf("\n");

    inicio = omp_get_wtime();

    for (int i = 0; i < 4 * N; i++)
    {
        printf("code2 %d - %d\n", i, omp_get_thread_num());
    }
    termino = omp_get_wtime();
    printf("Demoro %f segundos \n", termino - inicio);

    // #pragma omp parallel
    //     {
    //         printf("code1 %d\n", omp_get_thread_num());
    //         inicio = omp_get_wtime();
    // #pragma omp for

    //         for (int i = 0; i < 4 * N; i++)
    //         {
    //             printf("code2 %d - %d\n", i, omp_get_thread_num());
    //         }
    //         termino = omp_get_wtime();
    //         printf("Demoro %f segundos \n", termino - inicio);

    //         printf("code3 %d\n", omp_get_thread_num());
    //     }
}