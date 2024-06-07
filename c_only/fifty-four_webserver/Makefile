
CC=gcc

CFLAGS=-g

COMMON_OBJS= common.o

all: $(COMMON_OBJS) socket server

socket: tcpclient.c $(COMMON_OBJS)
	$(CC) $(CFLAGS) -o socket tcpclient.c $(COMMON_OBJS)

server: tcpserver.c $(COMMON_OBJS)
	$(CC) $(CFLAGS) -o server tcpserver.c $(COMMON_OBJS)

clean:
	rm -rf *.o *.dSYM socket server