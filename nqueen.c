#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int *board; // Pointer to store the column position of queens
int N;      // Size of the chessboard

// Function to check if it's safe to place a queen at a given position
bool isSafe(int row, int col) {
    // Check if there's no queen in the same column or diagonal
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == row - i)
            return false;
    }
    return true; // It's safe to place a queen at this position
}

// Function to print the current arrangement of queens on the chessboard
void printSolution() {
    static int solutionCount = 0; // Variable to count the number of solutions found
    solutionCount++;              // Increment solution count for each solution found
    printf("Solution %d:\n", solutionCount); // Print solution number
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i] == j)
                printf("Q "); // Print queen at this position
            else
                printf(". "); // Print empty space
        }
        printf("\n");
    }
    printf("\n");
}

// Recursive function to solve the N-Queens problem
void solveNQueens(int row) {
    if (row == N) {
        // All queens are placed, print the solution
        printSolution();
        // Print positions of queens in the last solution found
        printf("Positions: ");
        for (int i = 0; i < N; i++) {
            printf("(%d,%d) ", i, board[i]);
        }
        printf("\n");
        return;
    }

    // Try placing a queen in each column of the current row
    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row] = col; // Place the queen at this position
            solveNQueens(row + 1); // Recur for the next row
        }
    }
}

int main() {
    printf("Enter the size of the chessboard: ");
    scanf("%d", &N); // Input the size of the chessboard

    // Dynamically allocate memory for the board array based on the size of the chessboard
    board = (int *)malloc(N * sizeof(int));

    // Start solving the N-Queens problem from the first row
    solveNQueens(0);

    // Free dynamically allocated memory before returning
    free(board);

    return 0;
}
