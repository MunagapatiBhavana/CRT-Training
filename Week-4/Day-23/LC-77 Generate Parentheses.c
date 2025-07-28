#define INITIAL_CAPACITY 100

char** generateParenthesis(int n, int* returnSize) {
    int capacity = INITIAL_CAPACITY;
    *returnSize = 0;
    char** result = (char**)malloc(capacity * sizeof(char*));
    char* current = (char*)malloc((2 * n + 1) * sizeof(char));

    void backtrack(int pos, int open, int close) {
        if (pos == 2 * n) {
            current[pos] = '\0';
            if (*returnSize == capacity) {
                capacity *= 2;
                result = realloc(result, capacity * sizeof(char*));
            }
            result[(*returnSize)++] = strdup(current);
            return;
        }

        if (open < n) {
            current[pos] = '(';
            backtrack(pos + 1, open + 1, close);
        }
        if (close < open) {
            current[pos] = ')';
            backtrack(pos + 1, open, close + 1);
        }
    }

    backtrack(0, 0, 0);
    free(current);
    return result;
}
