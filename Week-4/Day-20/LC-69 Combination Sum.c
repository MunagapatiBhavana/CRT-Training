#include <stdlib.h>
#include <string.h>

#define MAX_COMBINATIONS 150
#define MAX_COMBINATION_LEN 40

// Helper function for backtracking
void backtrack(int* candidates, int candidatesSize, int target, int start,
               int* current, int currentSize,
               int** results, int* returnSize, int* returnColumnSizes) {
    if (target == 0) {
        // Found a valid combination, copy it to results
        int* combination = (int*)malloc(currentSize * sizeof(int));
        memcpy(combination, current, currentSize * sizeof(int));
        results[*returnSize] = combination;
        returnColumnSizes[*returnSize] = currentSize;
        (*returnSize)++;
        return;
    }

    if (target < 0) return; // no valid combination

    for (int i = start; i < candidatesSize; i++) {
        // Choose candidates[i]
        current[currentSize] = candidates[i];
        backtrack(candidates, candidatesSize, target - candidates[i], i,
                  current, currentSize + 1,
                  results, returnSize, returnColumnSizes);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(MAX_COMBINATIONS * sizeof(int));
    int** results = (int**)malloc(MAX_COMBINATIONS * sizeof(int*));
    int* current = (int*)malloc(MAX_COMBINATION_LEN * sizeof(int));

    backtrack(candidates, candidatesSize, target, 0,
              current, 0, results, returnSize, *returnColumnSizes);

    free(current);
    return results;
}
