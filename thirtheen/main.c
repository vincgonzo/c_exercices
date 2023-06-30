#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

void displayArrayValues(char array[], int n, int dir)
{
    for(int i = 0; i < n;i++){
    	printf("tab[%d] = %c (%p)\n", i, array[i], &array[i]);
    }
}

void displayArrayValuesPointer(char array[], int n, int dir)
{
    for(int i = 0; i < n;i++){
    	printf("*(tab+%d) = %c (%p)\n", i, *(array+i), (array+i));
    }
}


int main()
{
    char variables[5] = { 'C', 'O', 'D', 'E', 'R' };
    int length = sizeof(variables) / sizeof(variables[0]);

    displayArrayValues(variables, length, 0);
    displayArrayValuesPointer(variables, length, 0);
    return 0;
}
