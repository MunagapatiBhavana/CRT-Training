#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isValid(char* s) {
    int len = strlen(s);
    char *stack = (char*)malloc(len);
    int top = -1;

    for (int i = 0; i < len; i++) {
        char ch = s[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch; // push
        } else {
            if (top == -1) {
                free(stack);
                return false; // unmatched closing bracket
            }

            char topChar = stack[top--]; // pop

            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                free(stack);
                return false; // mismatched pair
            }
        }
    }

    bool isValid = (top == -1);
    free(stack);
    return isValid;
}
