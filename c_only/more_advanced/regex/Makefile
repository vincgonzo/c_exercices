CC=gcc
CFLAGS=-Wall -g3
EXE=main

all:$(EXE)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean: 
	rm -rf *.dSYM *.o $(EXE)