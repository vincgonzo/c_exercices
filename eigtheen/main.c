#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#define ROWS 3
#define COLS 2

void displayMatrice(int* matrice, int row, int col){
    int i, j;
    printf("Matrice values :\n");
    for(i=0; i< row; i++){
        for(j=0; j< col; j++){
            printf("%d ", *(matrice + i*col + j)); // or better: printf("%d ", *matrix++);
        }
        putchar('\n');
    }
    putchar('\n');
}

void matriceAddition(int* matrice1, int* matrice2, int row, int col){
    printf("Result matrix :\n")
    for (size_t i = 0; i < row; i++){
        for (size_t j = 0; j < col; j++)<
            printf("%d ", *(matrice1 + i*col + j) + *(matrice2 + i*col + j));
        putchar('\n');
    }
}


int main()
{
    int matrice1[ROWS][COLS] = {{1, 3}, {1, 0}, {1, 2}};
    int matrice2[ROWS][COLS] = {{0, 0}, {7, 5}, {2, 1}};
    
    displayMatrice(matrice1, ROWS, COLS);
    displayMatrice(matrice2, ROWS, COLS);
    matriceAddition(matrice1, matrice2, ROWS, COLS);

    return 0;
}
