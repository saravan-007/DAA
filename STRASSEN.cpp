#include <stdio.h>

#define MAX 64  // Adjust this size according to your matrix size needs

// Function to add two matrices
void add(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices
void subtract(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Strassen's recursive multiplication function
void strassen(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int size) {
    if (size == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = size / 2;

    int A11[MAX][MAX], A12[MAX][MAX], A21[MAX][MAX], A22[MAX][MAX];
    int B11[MAX][MAX], B12[MAX][MAX], B21[MAX][MAX], B22[MAX][MAX];
    int M1[MAX][MAX], M2[MAX][MAX], M3[MAX][MAX], M4[MAX][MAX], M5[MAX][MAX], M6[MAX][MAX], M7[MAX][MAX];
    int temp1[MAX][MAX], temp2[MAX][MAX];

    // Divide the matrices A and B into 4 submatrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Compute M1 = (A11 + A22) * (B11 + B22)
    add(A11, A22, temp1, newSize);
    add(B11, B22, temp2, newSize);
    strassen(temp1, temp2, M1, newSize);

    // Compute M2 = (A21 + A22) * B11
    add(A21, A22, temp1, newSize);
    strassen(temp1, B11, M2, newSize);

    // Compute M3 = A11 * (B12 - B22)
    subtract(B12, B22, temp1, newSize);
    strassen(A11, temp1, M3, newSize);

    // Compute M4 = A22 * (B21 - B11)
    subtract(B21, B11, temp1, newSize);
    strassen(A22, temp1, M4, newSize);

    // Compute M5 = (A11 + A12) * B22
    add(A11, A12, temp1, newSize);
    strassen(temp1, B22, M5, newSize);

    // Compute M6 = (A21 - A11) * (B11 + B12)
    subtract(A21, A11, temp1, newSize);
    add(B11, B12, temp2, newSize);
    strassen(temp1, temp2, M6, newSize);

    // Compute M7 = (A12 - A22) * (B21 + B22)
    subtract(A12, A22, temp1, newSize);
    add(B21, B22, temp2, newSize);
    strassen(temp1, temp2, M7, newSize);

    // Combine the results into matrix C
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
            C[i][j + newSize] = M3[i][j] + M5[i][j];
            C[i + newSize][j] = M2[i][j] + M4[i][j];
            C[i + newSize][j + newSize] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
        }
    }
}

// Function to input matrix
void inputMatrix(int matrix[MAX][MAX], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print matrix
void printMatrix(int matrix[MAX][MAX], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int size;
    printf("Enter the size of the matrix (must be a power of 2): ");
    scanf("%d", &size);

    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

    printf("Enter matrix A:\n");
    inputMatrix(A, size);

    printf("Enter matrix B:\n");
    inputMatrix(B, size);

    // Perform Strassen's matrix multiplication
    strassen(A, B, C, size);

    // Print the result
    printf("Resultant matrix C:\n");
    printMatrix(C, size);

    return 0;
}

