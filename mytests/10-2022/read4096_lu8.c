#include <stdio.h>
#include <stdlib.h>
#include <riscv-pk/encoding.h>
#include <time.h>


int main(void) 
{
  const int SIZE = 4096;
  const int STRIDE = 512;
  const int NUM_ITERS = SIZE / STRIDE;
  register size_t i;
  register uint32_t* mem_curr;
  register int val;
	register unsigned long start, end;

  mem_curr = 0x88000000;

// TODO: Inline assembly
  start = rdcycle(); 
  for (i = 0; i < NUM_ITERS; i++) {
    __asm__ __volatile__("lw %0, %2(%1);" 
                : "=r" (val)
                : "r" (mem_curr), "i" (0));
    __asm__ __volatile__("lw %0, %2(%1);" 
                : "=r" (val)
                : "r" (mem_curr), "i" (64));  
    __asm__ __volatile__("lw %0, %2(%1);" 
                : "=r" (val)
                : "r" (mem_curr), "i" (128));
    __asm__ __volatile__("lw %0, %2(%1);" 
                : "=r" (val)
                : "r" (mem_curr), "i" (192));  
    __asm__ __volatile__("lw %0, %2(%1);" 
                : "=r" (val)
                : "r" (mem_curr), "i" (256));
    __asm__ __volatile__("lw %0, %2(%1);" 
                : "=r" (val)
                : "r" (mem_curr), "i" (320));  
    __asm__ __volatile__("lw %0, %2(%1);" 
                : "=r" (val)
                : "r" (mem_curr), "i" (384));
    __asm__ __volatile__("lw %0, %2(%1);" 
                : "=r" (val)
                : "r" (mem_curr), "i" (448));  
    mem_curr += STRIDE;
  }
  end = rdcycle();
  printf("%d\n", end - start);

	return 0;
}