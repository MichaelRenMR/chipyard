#include <stdio.h>
#include <stdlib.h>
#include <riscv-pk/encoding.h>
#include <time.h>


int main(void) 
{
  // These sizes should explicitly target L1, L2, and DRAM
  const int SIZE = 32768;
  register size_t j;
  register uint32_t* mem_start;
  register int sum;
	register unsigned long start, end;

  sum = 0; 
  mem_start = 0x88000000;

  start = rdcycle(); 
  for (j = 0; j < SIZE; j += 16) {
    sum += mem_start[j]; 
  }
  end = rdcycle();
  printf("%d\n", end - start);

	return sum; 
}