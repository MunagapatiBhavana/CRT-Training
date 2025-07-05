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


