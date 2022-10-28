#include <stdio.h>
#include <stdlib.h>
#include <riscv-pk/encoding.h>
#include <time.h>


int main(void) 
{
  const int SIZES[] = {4096, 8192, 16384, 32768, 524288, 1048576, 2097152};
  register size_t i, j;
  register uint32_t* mem_start;
  register int sum, val;
	register unsigned long start, end;

  sum = 0; 
  mem_start = 0x88000000;

  for (i = 0; i < 7; i++) {
    printf("\n-- %d --\n", SIZES[i]);
    start = rdcycle(); 
    for (j = 0; j < SIZES[i]; j += 16) {
      // inline assembly 
      sum += mem_start[j]; 
    }
    end = rdcycle();
    printf("%d\n", end - start);
    // Always make sure we're reading from a non-cached portion of memory. 
    mem_start += 0x00200000;
  }

	return sum; 
}