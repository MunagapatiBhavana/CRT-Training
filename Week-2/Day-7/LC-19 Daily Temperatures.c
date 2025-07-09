#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    *returnSize = temperaturesSize;
    int* result = (int*)calloc(temperaturesSize, sizeof(int));
    int* stack = (int*)malloc(sizeof(int) * temperaturesSize);
    int top = -1;

    for (int i = temperaturesSize - 1; i >= 0; i--) {
        // Pop until we find a warmer temperature
        while (top >= 0 && temperatures[i] >= temperatures[stack[top]]) {
            top--;
        }

        // If stack is not empty, calculate days to wait
        if (top >= 0) {
            result[i] = stack[top] - i;
        } else {
            result[i] = 0;  // No warmer day ahead
        }

        // Push current index onto stack
        stack[++top] = i;
    }

    free(stack);
    return result;
}
