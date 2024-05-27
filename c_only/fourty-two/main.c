#include <stdio.h>
#include <stdlib.h>

// dynamic alloc ex02
void displayArrayPointer(int*, int);

int main()
{
    int size = 0;
    printf("Size of the integer array ? :\n");
    scanf("%d", &size);

    int* intArray = (int*)malloc(sizeof(int) * size);
    if(intArray == NULL)
        exit(-1);
    printf("value of malloc address %p", intArray);

    for (size_t i = 0; i < size; i++)
    {
        printf("\ntab[%d] = ", i);
        scanf("%d", (intArray + i));
    }
    
    displayArrayPointer(intArray, size);

    // never forget to free memory !
    free(intArray);
    return 0;
}

void displayArrayPointer(int* array, int size){
    printf("tab = {");
    for (size_t i = 0; i < size; i++)
        if(i == size - 1)
            printf("%d", *(array + i));
        else
            printf("%d,", *(array + i));
    printf("}\n");
}