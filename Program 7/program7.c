#include <omp.h>
#include <stdio.h>

int fibo(int i)
{
    if (i == 1)
        return 0;
    else if (i == 2 || i == 3)
        return 1;
    return fibo(i - 1) + fibo(i - 2);
}

int main()
{

    int n;
    printf("Enter the noumber of terms: ");
    scanf("%d", &n);
    printf("\nThe fibonacci series is: ");
    int id;
#pragma omp parallel shared(n) private(id) num_threads(4)
    {
// printf("%d\n", omp_get_thread_num());
#pragma omp for
        for (int i = 0; i < n; i++)
            printf("\nNumber %d is generated by thread %d", fibo(i + 1), omp_get_thread_num());
    }
    return 0;
}
