#include <stdio.h>
#include <omp.h>
#include <time.h>   	// for time()
#include <unistd.h> 	

// main function to find the execution time of a C program
int main()
{
	int id = omp_get_thread_num();
	#pragma omp parallel private(id)
	{
		int id = omp_get_thread_num();
		time_t begin = time(NULL);

		// do some stuff here
		sleep(3);

		time_t end = time(NULL);

		// calculate elapsed time by finding difference (end - begin)
		printf("Time elapsed = %d seconds Thread no = %d\n", (end - begin), id);
	}
	return 0;
}
