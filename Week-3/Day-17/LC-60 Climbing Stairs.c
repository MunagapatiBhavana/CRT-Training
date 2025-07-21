#include <stdio.h>

int climbStairs(int n) {
    if (n == 1)
        return 1;
    
    int dp[n+1];
    dp[0] = 1;  // 1 way to stand at the base (step 0)
    dp[1] = 1;  // 1 way to reach step 1
    
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    return dp[n];
}
