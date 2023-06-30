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

void matriceProduct(const int* matrix1, const int* matrix2, int rows1, int cols1, int cols2) {
    printf("Result matrix:\n");
    for (int row = 0; row < rows1; row++) {
        for (int col = 0; col < cols2; col++) {
            int tmp = 0;
            for (int i = 0; i < cols1; i++) {
                tmp += *(matrix1 + row * cols1 + i) * *(matrix2 + i * cols2 + col);
            }
            printf("%d ", tmp);
        }
        putchar('\n');
    }
}


int main()
{
    int matrice1[COLS][ROWS] = {{1, 2, 0}, {4, 3, -1}};
    int matrice2[ROWS][COLS] = {{5, 1}, {2, 3}, {3, 4}};
    
    displayMatrice(matrice1, COLS, ROWS);
    displayMatrice(matrice2, ROWS, COLS);
    matriceProduct(matrice1, matrice2, COLS, ROWS, COLS);

    return 0;
}
