#include <stdio.h>

int main() {
    int a[3][4] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12}
    };
    
    int rowStart = 0, rowEnd = 2;
    int colStart = 0, colEnd = 3;

    printf("Spiral Order:\n");

    while (rowStart <= rowEnd && colStart <= colEnd) {
        // Top row
        for (int i = colStart; i <= colEnd; i++) {
            printf("%d ", a[rowStart][i]);
        }
        rowStart++;

        // Right column
        for (int i = rowStart; i <= rowEnd; i++) {
            printf("%d ", a[i][colEnd]);
        }
        colEnd--;

        // Bottom row (if rows remain)
        if (rowStart <= rowEnd) {
            for (int i = colEnd; i >= colStart; i--) {
                printf("%d ", a[rowEnd][i]);
            }
            rowEnd--;
        }

        // Left column (if columns remain)
        if (colStart <= colEnd) {
            for (int i = rowEnd; i >= rowStart; i--) {
                printf("%d ", a[i][colStart]);
            }
            colStart++;
        }
    }

    return 0;
}

output:- 
Spiral Order:
1 2 3 4 8 12 11 10 9 5 6 7
