#include <stdio.h>
#include <stdlib.h>
#include <riscv-pk/encoding.h>
#include <time.h>


int main(void) 
{
  // These sizes should explicitly target L1, L2, and DRAM
  const int SIZE = 128;
  register size_t j;
  register uint32_t* mem_start;
  register int sum;
	register unsigned long start, end;


// fsdb file 
// use verdi 
// TOP > TestHarness > chiptop > system tile_reset_domain > tile > core / dcache
// split looping test into different tests 
// goal: d_valid always high  
  sum = 0; 
  mem_start = 0x88000000;

  start = rdcycle(); 
  sum += mem_start[0];
  sum += mem_start[16];
  sum += mem_start[32];
  sum += mem_start[48];
  sum += mem_start[64];
  sum += mem_start[72];
  sum += mem_start[80];
  sum += mem_start[96];
  sum += mem_start[112];
  sum += mem_start[128];
  end = rdcycle();
  printf("%d\n", end - start);

	return sum; 
}


