void gameOfLife(int** board, int boardSize, int* boardColSize) {
    int m = boardSize;
    int n = *boardColSize;
    
    int dirs[8][2] = {{-1, -1}, {-1, 0}, {-1, 1},
                      {0, -1},          {0, 1},
                      {1, -1},  {1, 0}, {1, 1}};
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int liveNeighbors = 0;
            for (int d = 0; d < 8; d++) {
                int ni = i + dirs[d][0];
                int nj = j + dirs[d][1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                    if (board[ni][nj] == 1 || board[ni][nj] == 2)
                        liveNeighbors++;
                }
            }
            
            if (board[i][j] == 1) {
                if (liveNeighbors < 2 || liveNeighbors > 3)
                    board[i][j] = 2;
            } else {
                if (liveNeighbors == 3)
                    board[i][j] = 3;
            }
        }
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 2)
                board[i][j] = 0;
            else if (board[i][j] == 3)
                board[i][j] = 1;
        }
    }
}
