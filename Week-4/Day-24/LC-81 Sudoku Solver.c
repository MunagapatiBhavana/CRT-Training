#include <stdbool.h>

bool isValid(char** board, int row, int col, char c) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == c) return false;  // Check row
        if (board[i][col] == c) return false;  // Check column
        if (board[3*(row/3) + i/3][3*(col/3) + i%3] == c) return false;  // Check 3x3 box
    }
    return true;
}

bool solve(char** board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == '.') {
                for (char c = '1'; c <= '9'; c++) {
                    if (isValid(board, row, col, c)) {
                        board[row][col] = c;
                        if (solve(board)) return true;
                        board[row][col] = '.'; // backtrack
                    }
                }
                return false;  // No valid digit found
            }
        }
    }
    return true;  // All cells filled
}

void solveSudoku(char** board, int boardSize, int* boardColSize) {
    solve(board);
}
