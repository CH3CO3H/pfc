CC=gcc
CFLAGS=-Wall
DIR=../../src/matrix/
G_DIR=../../src/g/
HF=../../src/h/

.PHONY:clean

main:test_inverse_matrix.o swap_double.o matrix_add.o matrix_swap.o matrix_mult.o input_matrix.o inverse_matrix.o matrix_set_1.o matrix_set_e.o
	$(CC) $(CFLAGS) $^ -o $@
matrix_add.o:$(DIR)matrix_add.c
	$(CC) $(CFLAGS) -c -I$(HF) $^ -o $@
matrix_mult.o:$(DIR)matrix_mult.c
	$(CC) $(CFLAGS) -c -I$(HF) $^ -o $@
matrix_swap.o:$(DIR)matrix_swap.c
	$(CC) $(CFLAGS) -c -I$(HF) $^ -o $@
swap_double.o:
	$(CC) $(CFLAGS) -c -I$(HF) $(G_DIR)swap_double.c
clean:
	rm *.o;rm a.out
