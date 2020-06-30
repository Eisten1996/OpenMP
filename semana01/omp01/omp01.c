#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char **argv)
{
    int threads = 100;
    int id = 100;

    printf("Hola desde el hilo % i hay % i hilos\n", id, threads);

    return 0;
}
