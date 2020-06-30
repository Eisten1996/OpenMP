#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char **argv)
{
#pragma omp parallel
    {
        printf("Hilo %d de %d hilos\n", omp_get_thread_num(), omp_get_num_threads());
    }
    return 0;
}
