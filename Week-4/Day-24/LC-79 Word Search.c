#include <stdbool.h>
#include <string.h>

bool dfs(char** board, int row, int col, int boardSize, int boardColSize, char* word, int index) {
    if (word[index] == '\0') return true; // Entire word found
    if (row < 0 || row >= boardSize || col < 0 || col >= boardColSize || board[row][col] != word[index])
        return false;

    char temp = board[row][col];
    board[row][col] = '#'; // Mark as visited

    bool found = dfs(board, row + 1, col, boardSize, boardColSize, word, index + 1) ||
                 dfs(board, row - 1, col, boardSize, boardColSize, word, index + 1) ||
                 dfs(board, row, col + 1, boardSize, boardColSize, word, index + 1) ||
                 dfs(board, row, col - 1, boardSize, boardColSize, word, index + 1);

    board[row][col] = temp; // Restore original value
    return found;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            if (dfs(board, i, j, boardSize, boardColSize[i], word, 0))
                return true;
        }
    }
    return false;
}
