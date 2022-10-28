#include <stdio.h>
#include <stdlib.h>
#include <riscv-pk/encoding.h>


int main(void) 
{

  const int SIZES[] = {1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152};

  register size_t i, j;
  register int val;
	register unsigned long start, end; 

  int* long_array;
  int* reset_cache;

  for (j = 0; j < 12; j++) {
    long_array = malloc(SIZES[j] * sizeof(int));
    reset_cache = malloc(262144 * sizeof(int));
    start = rdcycle();
    for (i = 0; i < SIZES[j]; i++) {
      long_array[i] += 0xCAFEB0BA;
    }
    end = rdcycle();
    printf("update1 %lu cycles\n", end - start);
  }

	return 0;
}
