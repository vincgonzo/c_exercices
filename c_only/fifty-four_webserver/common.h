#ifndef COMMON_H
#define COMMON_H

#include <sys/socket.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <netdb.h>

#define SERVER_PORT 18000
#define MAX_LINES 4096
#define SA struct sockaddr

void err_n_die(const char* fmt, ...);
char* bin2hex(const unsigned char* input, size_t len);

#endif