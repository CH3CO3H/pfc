CC=gcc
CFLAGS=-Wall
DIR=../../src/matrix/cmpy/
GD=../../src/g/
HF=../../src/h/
OBJ=matrix_input.o matrix_inverse.o matrix_print.o matrix_mult.o
O_C=cmpy.o matrix_cmpy.o matrix_ret.o

.PHONY:clean

cmpy:$(OBJ) $(O_C)
	$(CC) $(CFLAGS) $^ -o main
row_ex:$(OBJ)
	$(CC) $(CFLAGS) $^ -o main
%.o:$(DIR)%.c
	$(CC) $(CFLAGS) -c -I$(HF) $^ -o $@
%.o:%.c
	$(CC) $(CFLAGS) -c -I$(HF) $^ -o $@
clean:
	rm *.o;rm main
