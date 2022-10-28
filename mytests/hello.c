#include <stdio.h>

#include <riscv-pk/encoding.h>


void print_hello(void)
{
  printf("Hello world!\n");
}


int main(void) 
{
	unsigned long start, end; 
  start = rdcycle();
  print_hello();
  end = rdcycle();

  printf("print_hello %lu cycles\n", end - start);

	return 0;
}