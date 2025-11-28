CC=gcc
OBJ=xor_encrypt base64_encode 

.PHONY: all clean

all: $(OBJ)

xor_encrypt: xor_encrypt.c
	$(CC) -o xor_encrypt -O2 xor_encrypt.c

heapoverflow: base64_encode.c
	$(CC) -o base64encode -O2 base64_encode.c

clean:
	rm -f $(OBJ)
