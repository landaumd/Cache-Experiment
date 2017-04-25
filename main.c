#include <stdio.h>    /* for printf */
#include <stdlib.h>   /* for string to integer conversion, random numbers */
#include <time.h>
#include <stdint.h>
#include <unistd.h>
#include "memory.h"

#define BILLION 1E9
#define MILLION 1E6

/*
comment about the main
*/


int main(int argc, char** argv)
{

	struct timespec start;
	struct timespec end;

	long n = 100000; //num of times it runs

	int array_size = 1024*1024*16; //16MB array
	int *a;
	a = malloc((array_size)*sizeof(int));
	
	
	//step 4 - find time for cache retrieval
	int i, j, k;
	long *list;
	list = malloc(n*sizeof(long));


	for (k = 0; k < n; k++){

		//draws line into memory - mostly cache access after this
		a[0];
		j = 0;

		//begin clock
		clock_gettime(CLOCK_MONOTONIC, &start);

		//run for a while
		while (j < MILLION){
			a[j];
			j++;
		}

		//end clock
		clock_gettime(CLOCK_MONOTONIC, &end);

		//get difference
		long time_diff = (BILLION * ( end.tv_sec - start.tv_sec ) + ( end.tv_nsec - start.tv_nsec ));
		
		//add the average time it took to access the cache		
		list[k] = (time_diff/MILLION);

	}

	for (i = 0; i < 100; i++){
		printf("%ld\n", list[i]);

	}


}
