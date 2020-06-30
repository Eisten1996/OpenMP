#include <stdio.h>
#include <omp.h>

int main()
{
    // omp_get_max_threads sirve para saber cuantos hilos soporta
    printf("Número máximo de hilos que soporta %d\n", omp_get_max_threads());
    return 0;
}

