CC=gcc
CFLAGS=-Wall -O -pg
# LDFLAGS=-lm -pg
AD=../../src/adm/
MD=../../src/matrix/
SD=../../src/solve/
ID=../../src/h/
TMD=../matrix/
TAD=../adm/
S_MC=../../src/matrix/cmpy/
S_MR=../../src/matrix/row-ex/
# S_ML=../../src/matrix/lu/
OBJ=main.o adm_graph.o adm_matrix.o swap_s.o has_branch.o cal_sij.o cal_ss.o get_dlt_ef_max.o get_new_ef.o initial.o mk_jcb.o set_ub.o solve_func.o solve.o set_sij.o print_vector.o matrix_print.o print_adm_matrix.o matrix_inverse.o
O_MC=matrix_cmpy.o matrix_ret.o
O_MR=matrix_set_1.o matrix_set_e.o matrix_row_mult.o swap_double.o matrix_add.o matrix_swap.o matrix_cp.o
# OBJ_LU=matrix_inverse.o 

.PHONY:clean

row_ex:$(OBJ) $(O_MR)
	$(CC) $(CFLAGS) -I$(ID) $^ -o $@ $(LDFLAGS)
cmpy:$(OBJ) $(O_MC)
	$(CC) $(CFLAGS) -I$(ID) $^ -o $@ $(LDFLAGS)
# lu:$(OBJ) $(OBJ_LU)
# 	$(CC) $(CFLAGS) -I$(ID) $^ -o $@ $(LDFLAGS)
matrix_inverse.o:$(S_MR)matrix_inverse.c	# change this
	$(CC) -c $(CFLAGS) -I$(ID) $^
%.o:%.c
	$(CC) -c  $(CFLAGS) -I$(ID) $^ $(LDFLAGS)
%.o:$(AD)%.c
	$(CC) -c  $(CFLAGS) -I$(ID) $^ $(LDFLAGS)
%.o:$(MD)%.c
	$(CC) -c  $(CFLAGS) -I$(ID) $^ $(LDFLAGS)
%.o:$(SD)%.c
	$(CC) -c  $(CFLAGS) -I$(ID) $^ $(LDFLAGS)
%.o:$(TMD)%.c
	$(CC) -c  $(CFLAGS) -I$(ID) $^ $(LDFLAGS)
%.o:$(TAD)%.c
	$(CC) -c  $(CFLAGS) -I$(ID) $^ $(LDFLAGS)
%.o:$(S_MC)%.c
	$(CC) -c $(CFLAGS) -I$(ID) $^
%.o:$(S_MR)%.c
	$(CC) -c $(CFLAGS) -I$(ID) $^
clean:
	-rm *.o cmpy row_ex
