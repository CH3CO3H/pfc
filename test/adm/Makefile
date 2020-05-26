CC=gcc
CFLAGS=-Wall
ADM_DIR=../../src/adm/
INL_DIR=../../src/inl/
HF=../../src/h/

.PHONY:clean

main:main.o adm_matrix.o read_base.o read_bus.o read_branch.o
	$(CC) $(CFLAGS) $^ -o $@
%.o:%.c
	$(CC) $(CFLAGS) -c -I$(HF) $^
%.o:$(ADM_DIR)%.c
	$(CC) $(CFLAGS) -c -I$(HF) $^
%.o:$(INL_DIR)%.c
	$(CC) $(CFLAGS) -c -I$(HF) $^
clean:
	-rm *.o;rm main
