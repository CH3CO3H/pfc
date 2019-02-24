CC=gcc
CFLAGS=-Wall
DIR=../../src/inl/
HF=../../src/h/

.PHONY:clean

main:main.o read_base.o read_bus.o read_branch.o
	$(CC) $(CFLAGS) $^ -o $@
%.o:%.c
	$(CC) $(CFLAGS) -c -I$(HF) $^
%.o:$(DIR)%.c
	$(CC) $(CFLAGS) -c -I$(HF) $^
clean:
	-rm *.o;rm main
