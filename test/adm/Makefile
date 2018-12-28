CC=gcc
CFLAGS=-Wall -std=c99
DIR=../../src/adm/
HF=../../src/h/

.PHONY:clean

main:main.o adm_graph.o adm_matrix.o swap_s.o
	$(CC) $(CFLAGS) $^ -o $@
%.o:%.c
	$(CC) $(CFLAGS) -c -I$(HF) $^
%.o:$(DIR)%.c
	$(CC) $(CFLAGS) -c -I$(HF) $^
clean:
	-rm *.o;rm main
