#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

void displayArray(int array[], int length){
    putchar('[');
    for (size_t i = 0; i < length; i++)
        printf(" %d", *(array + i));
    printf("]\n");
}

void bubbleSort(int array[], int length){
    // bubble sort
    int s = length;
    while(s > 0){
        for(short j = 0; j < length; j++){
            if(j + 1 < length){
                if(array[j + 1] < array[j]){
                    int tmp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = tmp;
                }
            }
        }
        displayArray(array, length);
        s--;
    }

}

int main()
{
    const int LEN = 7;
    int values[LEN];
    
    for(int i = 0; i < LEN; i++)
        values[i] = (int)(rand() % (10));

    displayArray(values, LEN);
    bubbleSort(values, LEN);
    return 0;
}
