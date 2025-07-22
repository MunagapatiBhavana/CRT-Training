#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int numDecodings(char *s) {
    int n = strlen(s);
    if (n == 0 || s[0] == '0') return 0;

    int *dp = (int *)malloc((n + 1) * sizeof(int));
    dp[0] = 1; // Empty string has 1 way to decode
    dp[1] = 1; // First char is not '0', so one way

    for (int i = 2; i <= n; i++) {
        dp[i] = 0;

        // Check single digit
        if (s[i - 1] != '0') {
            dp[i] += dp[i - 1];
        }

        // Check two digits
        int twoDigit = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
        if (twoDigit >= 10 && twoDigit <= 26) {
            dp[i] += dp[i - 2];
        }
    }

    int result = dp[n];
    free(dp);
    return result;
}


