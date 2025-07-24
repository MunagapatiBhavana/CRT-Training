#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX_RESULT 1000

bool isValid(char* s, int start, int len) {
    if (len == 0 || len > 3) return false;

    if (s[start] == '0' && len > 1) return false; // no leading zeros

    int num = 0;
    for (int i = 0; i < len; i++) {
        if (s[start + i] < '0' || s[start + i] > '9') return false;
        num = num * 10 + (s[start + i] - '0');
    }

    return num >= 0 && num <= 255;
}

void backtrack(char* s, int start, int segment, char* currentIP, int curLen, char** result, int* returnSize) {
    if (segment == 4 && s[start] == '\0') {
        currentIP[curLen - 1] = '\0'; // Remove last dot
        result[*returnSize] = strdup(currentIP);
        (*returnSize)++;
        return;
    }

    if (segment >= 4) return;

    for (int len = 1; len <= 3; len++) {
        if (s[start + len - 1] == '\0') break;

        if (isValid(s, start, len)) {
            int oldLen = curLen;
            strncpy(currentIP + curLen, s + start, len);
            curLen += len;
            currentIP[curLen++] = '.';

            backtrack(s, start + len, segment + 1, currentIP, curLen, result, returnSize);

            curLen = oldLen; // backtrack
        }
    }
}

char** restoreIpAddresses(char* s, int* returnSize) {
    char** result = (char**)malloc(MAX_RESULT * sizeof(char*));
    *returnSize = 0;

    int len = strlen(s);
    if (len < 4 || len > 12) return result;

    char* currentIP = (char*)malloc(20); // Max "255.255.255.255\0" = 16 chars, 20 is safe

    backtrack(s, 0, 0, currentIP, 0, result, returnSize);

    free(currentIP);
    return result;
}
