CC=gcc
CFLAGS=-Wall
DIR=../../src/adm/
HF=../../src/h/

.PHONY:clean

main:main.o adm_graph.o adm_matrix.o swap_s.o
	$(CC) $(CFLAGS) $^ -o $@
main.o:main.c
	$(CC) $(CFLAGS) -c -I$(HF) $^
%.o:$(DIR)%.c
	$(CC) $(CFLAGS) -c -I$(HF) $^
swap_s.o:$(DIR)../g/swap_s.c
	$(CC) $(CFLAGS) -c -I$(HF) $^
clean:
	-rm *.o;rm main
