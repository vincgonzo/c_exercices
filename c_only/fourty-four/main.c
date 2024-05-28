#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MIN_VALUE_AUTH 0
#define MAX_VALUE_AUTH 100

// dynamic alloc ex02
void displayArrayPointer(int*, int);
bool verifyCondition(const int);
void clearInputBuffer();

int main()
{
   int nbrValues = 0, tmp = -1, result = 0;
   int* numbers = NULL;
   bool condition = false;

   do
   {
    while(1) {
        printf("Insert values between values 0 <> 100 to create a array\n");
        result = scanf("%d", &tmp);

        // Check if scanf read an integer
        if (result == 1) {
            break; // Exit the loop if input is valid
        } else {
            printf("Invalid input. Please enter an integer.\n");
            fflush(stdin);
            tmp = -1; // not to infinite loop
            break;
        }
    }
    condition = verifyCondition(tmp);
    // printf("condition : %d", condition);
    if(condition){
        nbrValues++;
        // printf("Value of array size now :%d\n", nbrValues);
        numbers = (int*) realloc(numbers, (nbrValues * sizeof(int)));
        *(numbers + nbrValues - 1) = tmp;
    }
    displayArrayPointer(numbers, nbrValues);

   }while(condition);
   
    free(numbers);
   
    return 0;
}

void clearInputBuffer() { // not convince by this gpt solution to dig to
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

bool verifyCondition(const int value){
    return value > MIN_VALUE_AUTH && value < MAX_VALUE_AUTH;
}

void displayArrayPointer(int* array, int size){
    printf("numbers start address %p \n\t[\n", array);
    for (size_t i = 0; i < size; i++)
        printf("\taddress %p -> %d\n", (array + i), *(array + i));
    printf("\t]\n");
}