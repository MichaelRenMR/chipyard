#include <stdio.h>
#include <stdlib.h>
#include <riscv-pk/encoding.h>
#include <time.h>


int main(void) 
{
  const int SIZE = 524288;
  const int STRIDE = 64;
  const int NUM_ITERS = SIZE / STRIDE;
  register size_t i;
  register char* mem_read, mem_write;
  register int val = 0;
	register unsigned long start, end;

  mem_read = 0x88000000;
  mem_write = 0x88100000;

  start = rdcycle(); 
  for (i = 0; i < NUM_ITERS; i++) {
    __asm__ __volatile__("lw %0, %2(%1);" 
                : "=r" (val)
                : "r" (mem_read), "i" (0));
    __asm__ __volatile__("sw %0, %2(%1);" 
                : 
                : "r" (val), "r" (mem_write), "i" (0));
    mem_read += STRIDE;
    mem_write += STRIDE;
  }
  end = rdcycle();
  printf("%d\n", end - start);

	return 0;
}