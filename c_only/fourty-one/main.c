#include <stdio.h>
#include <stdlib.h>

#define NAME_MAX_SIZE 50

// dynamic alloc ex01



int main()
{
    int age = 0, nbrDynamic = 1;
    int * allocator = NULL;

    allocator = malloc(sizeof(int) * nbrDynamic);
    if(allocator == NULL)
        exit(-1);

    printf("What is your age ? :\n");
    scanf("%d", allocator);

    printf("Your are %d year old.\n", *allocator);

    // never forget to free memory !
    free(allocator);
    return 0;
}