#include <stdio.h>
#include <stdlib.h>
#include <riscv-pk/encoding.h>
#include <time.h>


int main(void) 
{
  const int SIZE = 2097152;
  const int STRIDE = 64;
  const int NUM_ITERS = SIZE / STRIDE;
  register size_t i;
  register char* mem_curr;
  register int val = 0;
	register unsigned long start, end;

  mem_curr = 0x88000000;

  start = rdcycle(); 
  for (i = 0; i < NUM_ITERS; i++) {
    __asm__ __volatile__("sw %0, %2(%1);" 
                : 
                : "r" (val), "r" (mem_curr), "i" (0));
    mem_curr += STRIDE;
  }
  end = rdcycle();
  printf("%d\n", end - start);

	return 0;
}