#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char **argv)
{
#pragma omp parallel
    {
        printf("Hola mundo\n");
    }
    return 0;
}
