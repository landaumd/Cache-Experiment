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
	long total_main = 0; //accumulation of total time taken for main memory retrieval
	long total_cache = 0; //accumulation of total time taken for cache retrieval
	long n = 1000000; //num of times it runs
	int array_size = 1024*1024*16; //16 MB array
	int j, k;
	int *a;
	a = malloc((array_size)*sizeof(int));
	
	
	long cell_count = 0;

	//get clock resolution...??
	uint64_t res = clock_getres(CLOCK_MONOTONIC, &start);
	printf("%ld\n", start.tv_nsec);

	

	for (j = 0; j < n; j++)
	{
		for (k = 0; k < 2; k++){

			//system("sync"); //do we need to flush the cache? Super slow...
			//get first time			
			clock_gettime(CLOCK_MONOTONIC, &start); 
			
			//do something with memory
		        //a[j];
 
			//get end time
			clock_gettime(CLOCK_MONOTONIC, &end); 

			//calculate the time difference ... is this right???
			uint64_t time_diff = (BILLION * ( end.tv_sec - start.tv_sec ) + ( end.tv_nsec - start.tv_nsec ));
			//uint64_t time_diff=((uint64_t)end.tv_sec+1.0e-9*end.tv_nsec)-((uint64_t)start.tv_sec+ 1.0e-9*start.tv_nsec);

			//accumulate the lines in between significant time differences
			cell_count++; 
			
			//usleep(1);
			//printf("time diff = %ld\n", time_diff);

			if (time_diff > 100 ){ //if there is a significant enough diff in time ... what constitutes as significant??
				//printf("&a[j] = %p\n", &a[j]);

				//if ( k == 0 ){ //we are retrieving for the first time -> MAIN (hopefully)
					total_main += time_diff;
			  		printf("MAIN MEM? Cell count: %-10ld %ld nanoseconds\n", cell_count, time_diff);
				//}
				//else{ //we are retrieving for the second time -> CACHE
				//	total_cache += time_diff;
				//	printf("---CACHE? Cell count: %-10ld %ld nanoseconds\n", cell_count, time_diff);
				//}
				cell_count = 0;
			}
		}
	}
	
	printf("\nAverage time for a retrieval from MAIN = %ld nanoseconds\n", total_main/n); //slower
	printf("Average time for a retrieval from CACHE = %ld nanoseconds\n", total_cache/n); //expect faster results

  /*struct timespec requestStart, requestEnd;
  clock_gettime(CLOCK_REALTIME, &requestStart);

  int x = rand();
  printf("%d\n", x); 

  clock_gettime(CLOCK_REALTIME, &requestEnd);

  double accum = ( requestEnd.tv_sec - requestStart.tv_sec )
    + ( requestEnd.tv_nsec - requestStart.tv_nsec )
    / BILLION;

  printf( "%lf\n", accum );


  struct timespec requestStart1, requestEnd1;
  clock_gettime(CLOCK_REALTIME, &requestStart1);

  int x = rand();
  printf("%d\n", x); 


  clock_gettime(CLOCK_REALTIME, &requestEnd1);


  double accum1 = ( requestEnd1.tv_sec - requestStart1.tv_sec )
    + ( requestEnd1.tv_nsec - requestStart1.tv_nsec )
    / BILLION;

  printf( "%lf\n", accum1 );*/
  


}
