#include <stdio.h>
#define SIZE 5

// prototypes
void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]);
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]);
void transposeMatrix(int m[SIZE][SIZE], int result[SIZE][SIZE]);
void printMatrix(int m[SIZE][SIZE]);

int main() {
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };
    int result[SIZE][SIZE];

    printf("Added Matrices:\n");
    addMatrices(m1, m2, result);
    printMatrix(result);
    printf("Multiplied Matrices:\n");
    multiplyMatrices(m1, m2, result);
    printMatrix(result);
    printf("Transposed Matrix 1:\n");
    transposeMatrix(m1, result);
    printMatrix(result);
    printf("Transposed Matrix 2:\n");
    transposeMatrix(m2, result);
    printMatrix(result);        
    return 0;
}

void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j]= m1[i][j]+m2[i][j]; // add each cell of matrix and set to result
        }
    }
}

// it is literally impossible to have incompatible dimensions with 1 define statement
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j]= 0; // init result matrix
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += m1[i][k] * m2[k][j]; // multiply matrix of size i*k and k*j and set result equal to i*j (inside 'k' must match)
            }
        }
    }
}

void transposeMatrix(int m[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[j][i] = m[i][j]; // flip rows and cols
        }
    }
}

void printMatrix(int m[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", m[i][j]); // print each cell of matrix
        }
        printf("\n");
    }
    printf("\n");
}