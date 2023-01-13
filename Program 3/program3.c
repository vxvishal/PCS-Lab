#include <omp.h>
#include <stdio.h>
int main()
{
    int n, m;
    printf("Enter the size of the first matrix: ");
    scanf("%d %d", &n, &m);
    int o, p;
    printf("Enter the size of the second matrix: ");
    scanf("%d %d", &o, &p);
    if (m != o)
    {
        printf("Matrices cannot be multiplied");
        return 0;
    }

    int a[n][m];
    printf("Enter matrix 1 values: ");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);

    int b[o][p];
    printf("Enter matrix 2 values: ");
    for (int i = 0; i < o; i++)
        for (int j = 0; j < p; j++)
            scanf("%d", &b[i][j]);

    int c[n][p];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)
            c[i][j] = 0;

#pragma omp parallel shared(a, b, c, n, m, p)
    {
#pragma omp for
        for (int i = 0; i < n; i++)
            for (int j = 0; j < p; j++)
                for (int k = 0; k < m; k++)
                    c[i][j] += a[i][k] * b[k][j];
    }
    printf("\nResultant Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
            printf("%d\t", c[i][j]);
        printf("\n");
    }
    return 0;
}
