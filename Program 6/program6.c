#include <stdio.h>
#include <omp.h>
void main()
{
    int n, i, j, c = 0, k = 0, id, m = 0, sum = 0;
    printf("The number of processors are: %d\n", omp_get_num_procs());
    printf("The max number of threads are: %d\n", omp_get_max_threads());
    id = omp_get_thread_num();
    printf("Enter the number till where you would like to find the prime numbers: ");
    scanf("%d", &n);
    printf("\nOutput from thread %d\n", id);
    printf("The prime numbers are: ");
    for (i = 0; i <= n; i++)
    {
        k = 0;
        for (j = 1; j <= n; j++)
        {
            if (i % j == 0)
                k++;
        }
        if (k <= 2)
        {
            printf("%d ", i);
            c++;
        }
    }
    // printf("\n");
    printf("\nThe number of elements: %d\n", c);
    printf("\nEntering parallel section \n");
    printf("\n");
    k = 0, c = 0;
#pragma omp parallel private(id)
    {
        id = omp_get_thread_num();
        printf("Output from thread %d\n", id);
        printf("The prime numbers are: ");
        for (i = 0; i < (n / omp_get_max_threads()); i++, m++)
        {
            k = 0;
            for (j = 1; j < n; j++)
            {
                if (m % j == 0)
                {
                    k++;
                }
            }
            if (k <= 2)
            {
                printf("%d ", m);
                c++;
            }
        }
        // printf("\n");
        printf("\nThe number of elements: %d\n\n", c);
        // printf("\n");
    }
    printf("\nOutside parallel section\n");
}
