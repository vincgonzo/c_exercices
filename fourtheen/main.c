#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

void displayArrayStats(int array[], int n)
{
    int min = array[0], max, sum;
    for(int i = 0; i < n;i++){
    	if(array[i] < min)
            min = array[i];
    	if(array[i] > max)
            max = array[i];
        sum += array[i];
    }
    printf("max = %d, min = %d, moyenne = %.2f\n", max, min, ((float) sum / (float) n));
}

int main()
{
    const int LEN = 5;
    int variables[LEN];

    printf("Remplir le tableau suivant de longeur %d :\n", LEN);
    for (size_t i = 0; i < 5; i++)
    {
        printf("tab[%d]:", i);
        scanf("%d", (variables + i));
        fflush(stdin);
        printf("\n");
    }

    displayArrayStats(variables, LEN);
    
    return 0;
}
