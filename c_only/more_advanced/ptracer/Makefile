
CC = gcc
CFLAGS = -Wall -O2
EXE = main

all:$(EXE)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean: 
	rm -rf *.dSYM *.o $(EXE)
