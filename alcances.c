#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int main(int argc, char **argv)
{
    system("cat /proc/cpuinfo");
    // printf("OS : %s\n", getenv("OS"));
    // printf("TERM : %s\n", getenv("TERM"));
    // system("uname -a");

#pragma omp parallel
    {
        printf("Hola mundo\n");
    }

    omp_set_num_threads(8);
#pragma omp parallel
    {
        printf("Hola victor\n");
    }

    return 0;
}
