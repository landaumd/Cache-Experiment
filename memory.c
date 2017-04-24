#include <stdio.h>    // for printf statements when debugging
#include <stdlib.h>   // for malloc() and free()
#include "memory.h"

static dur_t* memory;
static int mem_size;

int mem_allocate(mem_strats_t strategy, int size, dur_t duration)
{
  int probe_count = 0;

  return probe_count;
}


int mem_single_time_unit_transpired()
{
  for (int i = 0; i < mem_size; i++){
    if (memory[i] != 0){
      memory[i]--; //decrement all values by 1 unless they are a 0
    }
  }
  return 0;
}


int mem_fragment_count(int frag_size)
{
  return 0;
}


void mem_clear()
{
  for (int i = 0; i < mem_size; i++) {
    memory[i] = 0;
  }
}


void mem_init(int size)
{
  memory = malloc(size * sizeof(dur_t));
  mem_size = size;
  memory[size-1] = '\0';
  mem_clear();
}


void mem_free()
{
  free(memory);
}


void mem_print()
{
  for (int i = 0; i < mem_size; i++) {
    printf("[%d]    %d\n", i, memory[i]);
    printf("    ---------\n");
  }
}
