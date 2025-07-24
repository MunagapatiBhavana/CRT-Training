#include <stdbool.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)b) - (*(int*)a);  // Sort descending to optimize pruning
}

bool backtrack(int* matchsticks, int matchsticksSize, int* sides, int index, int target) {
    if (index == matchsticksSize) {
        // Check if all sides are equal to target
        return (sides[0] == target && sides[1] == target && sides[2] == target && sides[3] == target);
    }

    for (int i = 0; i < 4; i++) {
        if (sides[i] + matchsticks[index] > target) continue;

        // Choose this side
        sides[i] += matchsticks[index];
        if (backtrack(matchsticks, matchsticksSize, sides, index + 1, target)) {
            return true;
        }
        sides[i] -= matchsticks[index];

        // Optimization: if this side is 0, no need to try other sides (avoid duplicates)
        if (sides[i] == 0) break;
    }

    return false;
}

bool makesquare(int* matchsticks, int matchsticksSize) {
    if (matchsticksSize < 4) return false;

    int sum = 0;
    for (int i = 0; i < matchsticksSize; i++) {
        sum += matchsticks[i];
    }

    if (sum % 4 != 0) return false;
    int target = sum / 4;

    qsort(matchsticks, matchsticksSize, sizeof(int), cmp);

    int sides[4] = {0};
    return backtrack(matchsticks, matchsticksSize, sides, 0, target);
}
