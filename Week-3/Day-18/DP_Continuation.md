## Day-18 DP Continuation

# 🔶 1. Minimum Sum Path in a Matrix (Grid Approach)
✅ Problem:
Given a matrix m x n, find the minimum path sum from the top-left (0, 0) to the bottom-right (m-1, n-1), only moving right or down.

💡 Approach (Bottom-Up DP):
Create a dp[i][j] where each cell stores the minimum sum to reach that cell.

🔁 Recurrence:
```
dp[i][j] = matrix[i][j] + min(dp[i-1][j], dp[i][j-1])
```

Base Case:

dp[0][0] = matrix[0][0]

First row → add left values

First column → add top values

🧠 Example:

```
matrix = [[1,3,1],
          [1,5,1],
          [4,2,1]]
```

Final answer = dp[2][2] = 7

# 🔶 2. 0/1 Knapsack Problem (Using Grid Approach)
✅ Problem:
Given weights and values of n items, choose items to maximize value within a weight W.

💡 Approach (DP Grid):
Let dp[i][w] be the max value using first i items with weight ≤ w

🔁 Recurrence:
```
if wt[i-1] <= w:
    dp[i][w] = max(dp[i-1][w], val[i-1] + dp[i-1][w - wt[i-1]])
else:
    dp[i][w] = dp[i-1][w]
Base: dp[0][w] = 0 (no items)
```
🧠 Example:

val = [60, 100, 120]
wt = [10, 20, 30]
W = 50

Answer = 220

# 🔶 3. Maximum Candies Collected on a Trip
✅ Problem:
Given a matrix where each cell has candies, find max candies collected going from (0, 0) to (n-1, m-1) by only moving right or down.

💡 Same logic as min-sum, but use max:
```
dp[i][j] = matrix[i][j] + max(dp[i-1][j], dp[i][j-1])
```

# 🔶 4. Longest Common Subsequence (LCS)
✅ Problem:
Find the length of the longest subsequence present in both strings.

💡 Approach (DP Table):
Let dp[i][j] be the LCS of first i chars of string A and first j chars of B

🔁 Recurrence:
```
if A[i-1] == B[j-1]:
    dp[i][j] = 1 + dp[i-1][j-1]
else:
    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
```
🧠 Example:

A = "abcde", B = "ace"

Answer = 3 (LCS = "ace")

# 🔶 5. Longest Common Substring
✅ Problem:
Find the length of longest substring (continuous sequence) common in two strings.

💡 Approach:
Same as LCS but only when A[i-1] == B[j-1] you take +1, else reset to 0.

🔁 Recurrence:
```
if A[i-1] == B[j-1]:
    dp[i][j] = 1 + dp[i-1][j-1]
else:
    dp[i][j] = 0
Keep track of max(dp[i][j])
```
🧠 Example:

A = "abcdf", B = "abdf"

Answer = 2 ("ab")

# 🔶 6. Minimum Edit Distance (Levenshtein Distance)
✅ Problem:
Find the minimum number of operations (insert, delete, replace) to convert string A to B.

💡 Approach (DP Table):
dp[i][j] = edit distance between first i chars of A and first j of B

🔁 Recurrence:
```
if A[i-1] == B[j-1]:
    dp[i][j] = dp[i-1][j-1]
else:
    dp[i][j] = 1 + min(dp[i-1][j],    # delete
                       dp[i][j-1],    # insert
                       dp[i-1][j-1])  # replace
```
🧠 Example:

A = "horse", B = "ros"

Answer = 3 (horse → rorse → rose → ros)

| Problem                  | Recurrence Logic                                                        |
| ------------------------ | ----------------------------------------------------------------------- |
| Min Path in Matrix       | `dp[i][j] = a[i][j] + min(dp[i-1][j], dp[i][j-1])`                      |
| 0/1 Knapsack             | `dp[i][w] = max(dp[i-1][w], val[i-1] + dp[i-1][w-wt[i-1]])`             |
| Max Candies              | `dp[i][j] = a[i][j] + max(dp[i-1][j], dp[i][j-1])`                      |
| LCS                      | `dp[i][j] = 1 + dp[i-1][j-1] if match else max(dp[i-1][j], dp[i][j-1])` |
| Longest Common Substring | `dp[i][j] = 1 + dp[i-1][j-1] if match else 0`                           |
| Edit Distance            | `dp[i][j] = 1 + min(insert, delete, replace)`                           |
