CC=gcc
CFLAGS=-Wall -std=c99
AD=../../src/adm/
MD=../../src/matrix/
SD=../../src/solve/
ID=../../src/h/
TMD=../matrix/
TAD=../adm/
OBJ=main.o adm_graph.o adm_matrix.o swap_s.o has_branch.o swap_double.o matrix_add.o matrix_swap.o inverse_matrix.o matrix_set_1.o matrix_set_e.o matrix_row_mult.o matrix_cp.o cal_sij.o cal_ss.o get_dlt_ef_max.o get_new_ef.o initial.o mk_jcb.o set_ub.o solve_func.o solve.o set_sij.o print_vector.o print_matrix.o print_adm_matrix.o

.PHONY:clean

main:$(OBJ)
	$(CC) $(CFLAGS) -I$(ID) $^ -o $@
%.o:%.c
	$(CC) $(CFLAGS) -I$(ID) -c $^
%.o:$(AD)%.c
	$(CC) $(CFLAGS) -I$(ID) -c $^
%.o:$(MD)%.c
	$(CC) $(CFLAGS) -I$(ID) -c $^
%.o:$(SD)%.c
	$(CC) $(CFLAGS) -I$(ID) -c $^
%.o:$(TMD)%.c
	$(CC) $(CFLAGS) -I$(ID) -c $^
%.o:$(TAD)%.c
	$(CC) $(CFLAGS) -I$(ID) -c $^
clean:
	-rm *.o main
