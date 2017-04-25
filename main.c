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


long get_mode(long arr[],long len) {
   long max_val = 0; 
   long max_count = 0; 
   int i; 
   int j;

   for (i = 0; i < len; ++i) {
      int count = 0;
      
      for (j = 0; j < len; ++j) {
         if (arr[j] == arr[i])
         ++count;
      }
      
      if (count > max_count) {
         max_count = count;
         max_val = arr[i];
      }
   }

   return max_val;
}

long bub_sort(long arr[], long len)
{
    long i, j , temp;
  /*   Bubble sorting begins */
    for (i = 0; i < len; i++)
    {
        for (j = 0; j < (len - i - 1); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    // Median getter
    long middle = len/2;
    if (len % 2 == 1) 
    {
        return arr[middle];
        
    }
    else 
    {
        return ((arr[middle-1] + arr[middle]) / 2.0);
    }
    return 0;
} 


int main(int argc, char** argv)
{

	struct timespec start;
	struct timespec end;

	long n = 100000; //num of times it runs
	long inner_runs = 1000000;

	int array_size = 1024*1024*16; //16MB array
	int *a;
	a = malloc((array_size)*sizeof(int));
	
	
	//Number 4 - find time for cache retrieval
	int i, j, k;
	long *list;
	list = malloc(n*sizeof(long));

	//find time for sys calls
	/*clock_gettime(CLOCK_MONOTONIC, &start);
	while (j < inner_runs){
		j++;
	}
	clock_gettime(CLOCK_MONOTONIC, &end);
	long sys_time = (BILLION * ( end.tv_sec - start.tv_sec ) + ( end.tv_nsec - start.tv_nsec ));

	printf("%ld\n", sys_time/inner_runs);*/



	for (k = 0; k < n; k++){

		//draws line into memory - mostly cache access after this
		a[0];
		j = 0;

		//begin clock
		clock_gettime(CLOCK_MONOTONIC, &start);

		//run for a while
		while (j < inner_runs){
			a[j];
			j++;
		}

		//end clock
		clock_gettime(CLOCK_MONOTONIC, &end);

		//get difference
		long time_diff = (BILLION * ( end.tv_sec - start.tv_sec ) + ( end.tv_nsec - start.tv_nsec ));
		
		//add the average time it took to access the cache		
		list[k] = (time_diff/inner_runs); // - sys_time/inner_runs

	}

	//find median and mode of list and print... then use in the next problem?
	long cache_time_median = bub_sort(list, n);
	printf("Median: %ld nanoseconds\n", cache_time_median);

	long cache_time_mode = get_mode(list, n);
	printf("Mode: %ld\n", cache_time_mode);
	


	//Number 1 - find the cache line/block size
		
	/*	for (k = 0; k < n; k++){
			




		}*/
		






/*
	for (i = 0; i < 100; i++){
		printf("%ld\n", list[i]);
	}*/


}
