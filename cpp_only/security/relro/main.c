#include <stdio.h>
#include <stdlib.h>

/*
* RELRO example from : https://www.redhat.com/en/blog/hardening-elf-binaries-using-relocation-read-only-relro
*/

int main(int argc, int *argv[])
{
    size_t *p = (size_t *) strtol(argv[1], NULL, 16);

    p[0] = 0xdeadbeef;

    printf("RELRO: %p\n", p);

    return 0;
}
