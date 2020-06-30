#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
int main()
{
#pragma omp parallel
    {
#pragma omp for
        for (int i = 1; i <= 10; i++)
        {
            printf("Hola %d - %li\n", i, omp_get_thread_num());
        }
    }
}