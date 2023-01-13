#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int main()
{

#pragma omp parallel
#pragma omp sections
    {
#pragma omp section
        {
            int i, j, k, n, r, count1 = 0;
            for (i = 10; i <= 131702; i++)
            {
                k = i;
                n = i;
                j = 0;
                while (n > 0)
                {
                    r = n % 10;
                    j = j + (r * r * r);
                    n = n / 10;
                    if (k == j)
                    {
                        printf("%d \n", j);
                        count1++;
                    }
                }
            }
            printf("Number of Armstrong numbers between 1 to 131702 are: %d\n", count1);
            printf("Palindrome numbers between 1 and 131702 are:\n");
        }
#pragma omp section
        {
            int i, j, k, n, r, count = 0;

            for (i = 10; i <= 131702; i++)
            {
                k = i;
                n = i;
                j = 0;
                while (n > 0)
                {
                    r = n % 10;
                    j = j * 10 + r;
                    n = n / 10;
                    if (k == j)
                    {
                        printf("%d \n", j);
                        count++;
                    }
                }
            }
            printf("Number of Palindrome numbers between 1 and 131702 are: %d\n", count);
        }
    }
}
