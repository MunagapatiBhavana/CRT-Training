#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char*** result;
int resultCount;
int* columnSizes;

bool isSafe(int* queens, int row, int col) {
    for (int i = 0; i < row; ++i) {
        int prevCol = queens[i];
        if (prevCol == col || abs(prevCol - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void addSolution(int* queens, int n) {
    char** board = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; ++i) {
        board[i] = (char*)malloc((n + 1) * sizeof(char));
        for (int j = 0; j < n; ++j) {
            board[i][j] = (queens[i] == j) ? 'Q' : '.';
        }
        board[i][n] = '\0';
    }
    result[resultCount] = board;
    columnSizes[resultCount] = n;
    resultCount++;
}

void solve(int* queens, int row, int n) {
    if (row == n) {
        addSolution(queens, n);
        return;
    }
    for (int col = 0; col < n; ++col) {
        if (isSafe(queens, row, col)) {
            queens[row] = col;
            solve(queens, row + 1, n);
        }
    }
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    result = (char***)malloc(1000 * sizeof(char**)); // assume max 1000 solutions
    columnSizes = (int*)malloc(1000 * sizeof(int));
    resultCount = 0;

    int* queens = (int*)malloc(n * sizeof(int));
    solve(queens, 0, n);

    *returnSize = resultCount;
    *returnColumnSizes = columnSizes;
    return result;
}
