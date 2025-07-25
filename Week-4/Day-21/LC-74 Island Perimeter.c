int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    int perimeter = 0;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 1) {
                perimeter += 4;

                // Subtract 2 for each adjacent land cell (top and left)
                if (i > 0 && grid[i - 1][j] == 1)
                    perimeter -= 2;
                if (j > 0 && grid[i][j - 1] == 1)
                    perimeter -= 2;
            }
        }
    }

    return perimeter;
}
