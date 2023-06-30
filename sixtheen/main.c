#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

void displayArray(int array[], int length){
    printf("[");
    for (size_t i = 0; i < length; i++)
        printf(" %d", *(array + i));
    printf("]\n");
}

void sortArray(int array[], int length){
    // selection sort
    int s = 0;
    while(s < length){
        int index = s;
        int min = array[s];
        int tmp = array[s];
        for(short j = s; j < length; j++){
            if(array[j] < min){
                min = array[j];
                index = j;
            }
        }
        if(index != s){
            array[s] = min;
            array[index] = tmp;
        }
        s++;
        displayArray(array, length);
    }

}

int main()
{
    const int LEN = 7;
    int values[LEN];
    
    for(int i = 0; i < LEN; i++)
        values[i] = (int)(rand() % (10));

    displayArray(values, LEN);
    sortArray(values, LEN);
    return 0;
}
