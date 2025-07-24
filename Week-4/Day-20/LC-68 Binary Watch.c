#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Count number of set bits in an integer
int countBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

char** readBinaryWatch(int turnedOn, int* returnSize) {
    // Max possible times are limited by hours * minutes = 12 * 60 = 720
    char** result = (char**)malloc(720 * sizeof(char*));
    *returnSize = 0;

    for (int h = 0; h < 12; h++) {
        for (int m = 0; m < 60; m++) {
            if (countBits(h) + countBits(m) == turnedOn) {
                char timeStr[6]; // max "11:59" + '\0' = 5 chars
                // Format minutes with leading zero if needed
                sprintf(timeStr, "%d:%02d", h, m);
                result[*returnSize] = strdup(timeStr);
                (*returnSize)++;
            }
        }
    }
    return result;
}
