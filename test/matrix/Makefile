CC=gcc
CFLAGS=-Wall
DIR=../../src/matrix/
GD=../../src/g/
HF=../../src/h/
OBJ=test_inverse_matrix.o swap_double.o matrix_add.o matrix_swap.o matrix_mult.o input_matrix.o inverse_matrix.o matrix_set_1.o matrix_set_e.o print_matrix.o matrix_row_mult.o matrix_cp.o

.PHONY:clean

main:$(OBJ)
	$(CC) $(CFLAGS) $^ -o $@
swap_double.o:$(GD)swap_double.c
	$(CC) $(CFLAGS) -c -I$(HF) $(GD)swap_double.c
%.o:$(DIR)%.c
	$(CC) $(CFLAGS) -c -I$(HF) $^ -o $@
%.o:%.c
	$(CC) $(CFLAGS) -c -I$(HF) $^ -o $@
clean:
	rm *.o;rm main
