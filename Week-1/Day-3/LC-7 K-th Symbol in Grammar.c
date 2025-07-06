We build a table of n rows (1-indexed). We start by writing 0 in the 1st row. Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.

For example, for n = 3, the 1st row is 0, the 2nd row is 01, and the 3rd row is 0110.
Given two integer n and k, return the kth (1-indexed) symbol in the nth row of a table of n rows.

 

Example 1:

Input: n = 1, k = 1
Output: 0
Explanation: row 1: 0


#include <stdio.h>
#include <math.h>

int depthFirstSearch(int n, int k, int rootVal) {
    if (n == 1) {
        return rootVal;
    }

    int totalNodes = pow(2, n - 1);

    // If target is in the right half
    if (k > totalNodes / 2) {
        int nextRootVal = (rootVal == 0) ? 1 : 0;
        return depthFirstSearch(n - 1, k - totalNodes / 2, nextRootVal);
    }
    // Target is in the left half
    else {
        int nextRootVal = (rootVal == 0) ? 0 : 1;
        return depthFirstSearch(n - 1, k, nextRootVal);
    }
}

int kthGrammar(int n, int k) {
    return depthFirstSearch(n, k, 0);
}


