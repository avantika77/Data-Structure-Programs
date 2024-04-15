#include <stdio.h>
#include <stdbool.h>

#define NMAX 100

// Function to check if a queen can be placed in board[row][col]
bool isSafe(int board[NMAX][NMAX], int row, int col, int N) {
    int i, j;

    // Check this row on left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// Function to solve N Queen's problem using backtracking
bool solveNQueensUtil(int board[NMAX][NMAX], int col, int N) {
    // Base case: If all queens are placed then return true
    if (col >= N)
        return true;

    // Consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < N; i++) {
        // Check if the queen can be placed on board[i][col]
        if (isSafe(board, i, col, N)) {
            // Place this queen in board[i][col]
            board[i][col] = 1;

            // Recur to place rest of the queens
            if (solveNQueensUtil(board, col + 1, N))
                return true;

            // If placing queen in board[i][col] doesn't lead to a solution, then remove queen from board[i][col]
            board[i][col] = 0;
        }
    }

    // If the queen cannot be placed in any row in this column, return false
    return false;
}

// Function to solve N Queen's problem and print the board configuration
void solveNQueens(int N) {
    int board[NMAX][NMAX] = {0};

    if (solveNQueensUtil(board, 0, N)) {
        printf("Solution exists!\n");
        // Print the board configuration
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                printf("%d ", board[i][j]);
            printf("\n");
        }
    } else {
        printf("Solution does not exist!\n");
    }
}

int main() {
    int N;

    printf("Enter the value of N for N Queen's problem: ");
    scanf("%d", &N);

    solveNQueens(N);

    return 0;
}
