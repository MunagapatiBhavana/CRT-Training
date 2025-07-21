## 📘 Day 17 CRT – Dynamic Programming
# 🧠 Topics Covered
Why Dynamic Programming?

Overlapping Subproblems and Optimal Substructure

Tabulation (Bottom-Up)

Memoization (Top-Down)

Applications:

Staircase Problem (O(2^n) and O(n))

Coin Change Problem

Cloth Cutting Problem

Longest Increasing Subsequence (O(n²) and O(n log n))

Ways to Translate Numbers (like a decoding problem)


## Why Dynamic Programming?
Dynamic Programming (DP) is an optimization technique used to solve complex problems by breaking them down into simpler subproblems. It avoids redundant calculations by storing and reusing the results of subproblems, thus improving efficiency compared to naive recursive approaches.

## Overlapping Subproblems and Optimal Substructure
Overlapping Subproblems: The problem can be broken into subproblems which are reused multiple times. Instead of solving the same subproblem repeatedly, DP solves each subproblem once and stores the result.

Optimal Substructure: A problem exhibits optimal substructure if its optimal solution can be constructed efficiently from optimal solutions of its subproblems.

## Tabulation (Bottom-Up)
Tabulation is a DP technique where the problem is solved by iteratively filling up a table (usually an array) starting from the smallest subproblems, building up solutions for larger problems until the desired solution is obtained. It avoids recursion and typically uses loops.

## Memoization (Top-Down)
Memoization is a DP technique that solves problems recursively but stores the results of expensive function calls in a cache (usually a hash map or array). When the same inputs occur again, the cached result is returned instead of recomputing it, thus reducing time complexity.

## 📌 1. Boy and Staircase Problem
🔹 Problem:
A boy is standing at the base of a staircase with n steps. He can climb either 1 or 2 steps at a time. Count the number of ways he can reach the top.

🔹 Naive Recursive (O(2ⁿ)):
```
int countWays(int n) {
    if (n <= 1)
        return 1;
    return countWays(n - 1) + countWays(n - 2);
}
```
## 🔹 Optimized DP (O(n)) - Tabulation:
```
int countWaysDP(int n) {
    int dp[n+1];
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
```

## 📌 2. Coin Change Problem
🔹 Problem:
Given coins of different denominations and a total, find how many combinations make up that amount.

🔹 DP Solution:
```
int coinChange(int coins[], int n, int amount) {
    int dp[amount+1];
    for (int i = 0; i <= amount; i++) dp[i] = 0;
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= amount; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    return dp[amount];
}
```
## 📌 3. Cloth Cutting Problem (Rod Cutting Problem)
🔹 Problem:
Given a rod of length n and prices of pieces of different lengths, find max price obtainable.
```
int maxClothProfit(int price[], int n) {
    int dp[n+1];
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        int max_val = -1;
        for (int j = 0; j < i; j++) {
            if (max_val < price[j] + dp[i-j-1])
                max_val = price[j] + dp[i-j-1];
        }
        dp[i] = max_val;
    }

    return dp[n];
}
```
## 📌 4. Longest Increasing Subsequence (LIS)
🔹 O(n²) DP Solution:
```
int LIS(int arr[], int n) {
    int lis[n];
    for (int i = 0; i < n; i++) lis[i] = 1;

    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;

    int max = lis[0];
    for (int i = 1; i < n; i++)
        if (lis[i] > max)
            max = lis[i];

    return max;
}
```
## 📌 5. Ways to Translate Numbers (like decode ways)
🔹 Problem:
Given a string of digits, count how many ways it can be translated (like 1→A, 2→B, ..., 26→Z).

🔹 DP Approach:

```
int numTranslations(char* s) {
    int n = strlen(s);
    if (n == 0 || s[0] == '0') return 0;

    int dp[n+1];
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = 0;
        int oneDigit = s[i-1] - '0';
        int twoDigit = (s[i-2] - '0') * 10 + (s[i-1] - '0');

        if (oneDigit >= 1)
            dp[i] += dp[i-1];
        if (twoDigit >= 10 && twoDigit <= 26)
            dp[i] += dp[i-2];
    }

    return dp[n];
}
```
| Problem           | Brute Force Time | DP Time            | Technique            |
| ----------------- | ---------------- | ------------------ | -------------------- |
| Staircase Problem | O(2ⁿ)            | O(n)               | Tabulation           |
| Coin Change       | -                | O(n × amount)      | DP Nested Loops      |
| Rod Cutting       | -                | O(n²)              | Tabulation           |
| LIS               | O(2ⁿ)            | O(n²) / O(n log n) | Memo + Binary Search |
| Translate Numbers | O(2ⁿ)            | O(n)               | Tabulation           |
