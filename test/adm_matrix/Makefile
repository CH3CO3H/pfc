CC=gcc
CFLAGS=-Wall
DIR=../../src/adm-matrix/
HF=../../src/h/

.PHONY:clean

main:main.o adm_graph.o adm_matrix.o swap.o
	$(CC) $(CFLAGS) $^
main.o:main.c
	$(CC) $(CFLAGS) -c -I$(HF) $^
adm_graph.o:swap.o
	$(CC) $(CFLAGS) -c -I$(HF) $(DIR)adm_graph.c
adm_matrix.o:
	$(CC) $(CFLAGS) -c -I$(HF) $(DIR)adm_matrix.c
swap.o:
	$(CC) $(CFLAGS) -c -I$(HF) $(DIR)../swap.c
clean:
	rm *.o;rm a.out
