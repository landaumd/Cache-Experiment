#include <stdio.h>    /* for printf */
#include <stdlib.h>   /* for string to integer conversion, random numbers */
#include <time.h>
#include <stdint.h>
#include <unistd.h>
#include "memory.h"

#define BILLION 1E9

/*
comment about the main
*/


int main(int argc, char** argv)
{

	struct timespec start;
	struct timespec end;

	long n = 10000; //num of times it runs

	int array_size = 1024*1024*16; //16MB array
	int *a;
	a = malloc((array_size)*sizeof(int));
	
	
	//step 4 - find time for cache retrieval
	int i, j, k;
	int *list;
	list = malloc(1000000*sizeof(int));


	for (k = 0; k < n; k++){

		a[0];
		j = 0;
		clock_gettime(CLOCK_MONOTONIC, &start);

		while (j < 1000000){
			a[j];
			j++;
		}

		clock_gettime(CLOCK_MONOTONIC, &start);
		uint64_t time_diff = (BILLION * ( end.tv_sec - start.tv_sec ) + ( end.tv_nsec - start.tv_nsec ));
		
		//add this part to the list		
		printf("%d\n", time_diff/1000000);

	}


}
