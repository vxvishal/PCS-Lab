#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[])
{
    int id;
    // double wtime;
    printf("Number of processors available = %d\n", omp_get_num_procs());
    printf("Number of threads = %d\n", omp_get_max_threads());
    id = omp_get_thread_num();
    printf("Hello from process %d\n", id);
    printf("\nInside parallel region:\n");

#pragma omp parallel private(id)
    {
        id = omp_get_thread_num();
        printf("\tHello from process %d\n", id);
    }
    printf("Outside parallel region\n");
    return 0;
}
