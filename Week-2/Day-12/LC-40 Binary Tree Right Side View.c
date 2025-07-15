#include <stdlib.h>
#include <stdio.h>

// Definition for a binary tree node.


// Queue implementation
struct TreeNode** createQueue(int size) {
    return (struct TreeNode**)malloc(sizeof(struct TreeNode*) * size);
}

int* rightSideView(struct TreeNode* root, int* returnSize) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    int* result = (int*)malloc(sizeof(int) * 100); // assuming max 100 levels
    int resIndex = 0;

    struct TreeNode** queue = createQueue(1000);
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front;

        for (int i = 0; i < levelSize; ++i) {
            struct TreeNode* node = queue[front++];

            // If it's the last node in the current level
            if (i == levelSize - 1) {
                result[resIndex++] = node->val;
            }

            if (node->left)
                queue[rear++] = node->left;
            if (node->right)
                queue[rear++] = node->right;
        }
    }

    *returnSize = resIndex;
    return result;
}
