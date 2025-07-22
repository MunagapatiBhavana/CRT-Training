int lengthOfLIS(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int dp[numsSize];
    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1;  // Each element is an LIS of length 1
    }

    int maxLen = 1;

    for (int i = 1; i < numsSize; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                if (dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
            }
        }
        if (maxLen < dp[i])
            maxLen = dp[i];
    }

    return maxLen;
}
