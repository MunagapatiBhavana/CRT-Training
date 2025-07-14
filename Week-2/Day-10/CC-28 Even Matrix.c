#include <stdio.h>
#include <stdlib.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        // Dynamically allocate n x n matrix
        int** mat = (int**)malloc(n * sizeof(int*));
        for (int i = 0; i < n; i++) {
            mat[i] = (int*)malloc(n * sizeof(int));
        }

        int i = 0, count = 0, curr = 1;

        while (count < n) {
            // Left to right
            for (int j = 0; j < n; j++) {
                mat[i][j] = curr++;
            }
            count++;
            i++;
            if (count < n) {
                // Right to left
                for (int j = n - 1; j >= 0; j--) {
                    mat[i][j] = curr++;
                }
                count++;
                i++;
            }
        }

        // Print the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", mat[i][j]);
            }
            printf("\n");
        }

        // Free allocated memory
        for (int i = 0; i < n; i++) {
            free(mat[i]);
        }
        free(mat);
    }

    return 0;
}

