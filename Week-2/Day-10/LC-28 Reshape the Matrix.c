#include <stdlib.h>

int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    int originalRows = matSize;
    int originalCols = matColSize[0];
    int totalElements = originalRows * originalCols;

    // Check if reshape is possible
    if (totalElements != r * c) {
        *returnSize = matSize;
        *returnColumnSizes = (int*)malloc(sizeof(int) * matSize);
        for (int i = 0; i < matSize; i++) {
            (*returnColumnSizes)[i] = matColSize[0];
        }
        return mat;  // Return original matrix
    }

    // Allocate new reshaped matrix
    int** reshaped = (int**)malloc(sizeof(int*) * r);
    *returnColumnSizes = (int*)malloc(sizeof(int) * r);
    for (int i = 0; i < r; i++) {
        reshaped[i] = (int*)malloc(sizeof(int) * c);
        (*returnColumnSizes)[i] = c;
    }

    // Fill the new matrix
    for (int i = 0; i < totalElements; i++) {
        int originalRow = i / originalCols;
        int originalCol = i % originalCols;
        int newRow = i / c;
        int newCol = i % c;
        reshaped[newRow][newCol] = mat[originalRow][originalCol];
    }

    *returnSize = r;
    return reshaped;
}

