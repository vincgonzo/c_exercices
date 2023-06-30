#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

int main()
{
    int variable = 0;
    int* pointer = &variable;
    printf("Entrez une valeur de int :");
    scanf("%d", pointer);
    fflush(stdin);

    printf("Nous avons donc %d stocker a %p\n", variable, pointer);

    return 0;
}
