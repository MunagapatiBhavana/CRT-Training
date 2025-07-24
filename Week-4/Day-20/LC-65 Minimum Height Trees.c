#include <stdlib.h>

int* findMinHeightTrees(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    if (n == 1) {
        int* res = (int*)malloc(sizeof(int));
        res[0] = 0;
        *returnSize = 1;
        return res;
    }

    // Step 1: Build degree array and adjacency list using compressed format
    int* degree = (int*)calloc(n, sizeof(int));
    int* adjSize = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < edgesSize; ++i) {
        degree[edges[i][0]]++;
        degree[edges[i][1]]++;
        adjSize[edges[i][0]]++;
        adjSize[edges[i][1]]++;
    }

    // Pre-allocate space for neighbors, total 2 * (n - 1)
    int** adj = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; ++i) {
        adj[i] = (int*)malloc(adjSize[i] * sizeof(int));
        adjSize[i] = 0; // reset to use as index while filling
    }

    // Fill adjacency list
    for (int i = 0; i < edgesSize; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    // Step 2: Initialize leaves
    int* leaves = (int*)malloc(n * sizeof(int));
    int leafCount = 0;
    for (int i = 0; i < n; i++) {
        if (degree[i] == 1) {
            leaves[leafCount++] = i;
        }
    }

    // Step 3: Trim leaves iteratively
    int remaining = n;
    while (remaining > 2) {
        remaining -= leafCount;
        int* newLeaves = (int*)malloc(n * sizeof(int));
        int newLeafCount = 0;

        for (int i = 0; i < leafCount; ++i) {
            int leaf = leaves[i];
            for (int j = 0; j < adjSize[leaf]; ++j) {
                int neighbor = adj[leaf][j];
                degree[neighbor]--;
                if (degree[neighbor] == 1) {
                    newLeaves[newLeafCount++] = neighbor;
                }
            }
        }

        free(leaves);
        leaves = newLeaves;
        leafCount = newLeafCount;
    }

    *returnSize = leafCount;
    return leaves;
}
