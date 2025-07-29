#include <stdlib.h>
#include <string.h>

// Helper function to backtrack and generate subsets
void backtrack(int* nums, int numsSize, int** result, int* returnSize, int** columnSizes, int* temp, int start, int tempSize) {
    result[*returnSize] = (int*)malloc(sizeof(int) * tempSize);
    memcpy(result[*returnSize], temp, sizeof(int) * tempSize);
    (*columnSizes)[*returnSize] = tempSize;
    (*returnSize)++;

    for (int i = start; i < numsSize; i++) {
        temp[tempSize] = nums[i];
        backtrack(nums, numsSize, result, returnSize, columnSizes, temp, i + 1, tempSize + 1);
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int maxSubsets = 1 << numsSize;  // 2^n subsets

    int** result = (int**)malloc(sizeof(int*) * maxSubsets);
    *returnColumnSizes = (int*)malloc(sizeof(int) * maxSubsets);
    *returnSize = 0;

    int* temp = (int*)malloc(sizeof(int) * numsSize);  // Temporary array to build subsets

    backtrack(nums, numsSize, result, returnSize, returnColumnSizes, temp, 0, 0);

    free(temp);
    return result;
}
