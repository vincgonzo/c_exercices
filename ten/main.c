#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#define typename(x) _Generic((x), \
    int:     "int", \
    float:   "float", \
    char:   "char", \
    default: "other")

int main()
{
    char variable = 'A';
    char *pointerChar = &variable;
    printf("Les infos de la variables sont :\n");

    printf("type : %s \ntaille: %d octets\ncontenu: %c\nadresse: %p\n", typename(variable), sizeof(variable), *pointerChar, &variable);

    return 0;
}