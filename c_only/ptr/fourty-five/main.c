#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MIN_VALUE_AUTH 4
#define MAX_VALUE_AUTH 10
// Define the matrix struct
typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

// Function to create a matrix
Matrix createMatrix(int rows, int cols) {
    Matrix matrix;
    matrix.rows = rows;
    matrix.cols = cols;

    // Allocate memory for rows
    matrix.data = (int **)malloc(rows * sizeof(int *));
    if (matrix.data == NULL) {
        fprintf(stderr, "Memory allocation failed for rows.\n");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for columns in each row
    for (int i = 0; i < rows; i++) {
        matrix.data[i] = (int *)malloc(cols * sizeof(int));
        if (matrix.data[i] == NULL) {
            fprintf(stderr, "Memory allocation failed for columns in row %d.\n", i);
            exit(EXIT_FAILURE);
        }
    }
    for (size_t i = 0; i < rows; i++)
        for (size_t k = 0; k < cols; k++)
            matrix.data[i][k] = (i == k)? 1 : 0; 

    return matrix;
}

// Function to free the allocated memory
void freeMatrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
    matrix->data = NULL;
}

// Function to print the matrix
void printMatrix(const Matrix *matrix) {
    printf("Matrix:\n");
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;

    // Get number of rows and columns from user
    do {
        printf("Enter the number of rows (%d to %d): ", MIN_VALUE_AUTH, MAX_VALUE_AUTH);
        scanf("%d", &rows);
    } while (rows < MIN_VALUE_AUTH || rows > MAX_VALUE_AUTH);
    cols = rows;

    // Create and initialize the matrix
    Matrix matrix = createMatrix(rows, cols);

    // Print the matrix
    printMatrix(&matrix);

    // Free the allocated memory
    freeMatrix(&matrix);

    return 0;
}