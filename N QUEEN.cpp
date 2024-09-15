#include <stdio.h> 
#include <stdbool.h> 
 
#define MAX 20 
 
// Function to print the solution 
void printSolution(int board[MAX][MAX], int N) { 
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < N; j++) { 
            printf(" %d ", board[i][j]); 
        } 
        printf("\n"); 
    } 
    printf("\n"); 
} 
 
// Function to check if a queen can be placed on board[row][col] 
bool isSafe(int board[MAX][MAX], int row, int col, int N) { 
    // Check this column on upper rows 
    for (int i = 0; i < row; i++) { 
        if (board[i][col]) { 
            return false; 
        } 
    } 
 
    // Check upper left diagonal 
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) { 
        if (board[i][j]) { 
            return false; 
        } 
    } 
 
    // Check upper right diagonal 
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) { 
        if (board[i][j]) { 
            return false; 
        } 
    } 
 
    return true; 
} 
 
// Function to solve the N-Queens problem using backtracking 
bool solveNQueens(int board[MAX][MAX], int row, int N) { 
    if (row >= N) { 
        return true; // All queens are placed 
    } 
 
    for (int col = 0; col < N; col++) { 
        if (isSafe(board, row, col, N)) { 
            board[row][col] = 1; // Place queen 
            if (solveNQueens(board, row + 1, N)) { 
                return true; // Recur to place next queen 
            } 
            board[row][col] = 0; // Backtrack 
        } 
    } 
 
    return false; // No solution found 
} 
 
int main() { 
    int N; 
    int board[MAX][MAX] = {0}; // Initialize board to zero 
 
    // Input: number of queens (and size of the board) 
    printf("Enter the number of queens (N): "); 
    scanf("%d", &N); 
 
    // Solve the N-Queens problem 
    if (solveNQueens(board, 0, N)) { 
        printf("One possible solution is:\n"); 
        printSolution(board, N); 
    } else { 
        printf("No solution exists for N = %d\n", N); 
    } 
 
    return 0; 
}
