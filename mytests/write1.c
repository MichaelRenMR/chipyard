#include <stdio.h>
#include <stdlib.h>
#include <riscv-pk/encoding.h>


int main(void) 
{

  const int SIZES[] = {1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152};
  //const int SIZES[] = {64, 128};
  register size_t i, j;
  register int* mem_start;
	register unsigned long start, end;

  mem_start = 0x88000000;

  for (i = 0; i < 12; i++) {
    printf("\n-- %d --\n", SIZES[i]);
    for (j = 0; j < SIZES[i]; j += 16) {
      start = rdcycle(); 
      mem_start[j] = 0xCAFEB0BA;
      end = rdcycle();
      printf("%d, ", end - start);
    }
    printf("\n");
  }

	return 0;
}
