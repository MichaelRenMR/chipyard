CFILE="file.c" 
build: 
	riscv64-unknown-elf-gcc -O2 -fno-common -fno-builtin-printf -specs=htif_nano.specs -c $(CFILE:=.c)
	riscv64-unknown-elf-gcc -static -specs=htif_nano.specs $(CFILE:=.o) -o $(CFILE:=.riscv)
	riscv64-unknown-elf-objdump -D $(CFILE:=.riscv) > $(CFILE:=.dump)

