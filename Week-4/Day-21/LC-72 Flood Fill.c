#include <stdlib.h>

void dfs(int** image, int imageSize, int* imageColSize, int r, int c, int originalColor, int newColor) {
    // Boundary check
    if (r < 0 || r >= imageSize || c < 0 || c >= imageColSize[r])
        return;
    // If current cell is not the original color or already newColor, stop
    if (image[r][c] != originalColor || image[r][c] == newColor)
        return;

    // Recolor
    image[r][c] = newColor;

    // Recur in all 4 directions
    dfs(image, imageSize, imageColSize, r + 1, c, originalColor, newColor);
    dfs(image, imageSize, imageColSize, r - 1, c, originalColor, newColor);
    dfs(image, imageSize, imageColSize, r, c + 1, originalColor, newColor);
    dfs(image, imageSize, imageColSize, r, c - 1, originalColor, newColor);
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    int originalColor = image[sr][sc];

    // If the color is the same, no change needed
    if (originalColor != color) {
        dfs(image, imageSize, imageColSize, sr, sc, originalColor, color);
    }

    // Prepare return values
    *returnSize = imageSize;

    *returnColumnSizes = (int*)malloc(sizeof(int) * imageSize);
    for (int i = 0; i < imageSize; i++) {
        (*returnColumnSizes)[i] = imageColSize[i];
    }

    return image;
}
