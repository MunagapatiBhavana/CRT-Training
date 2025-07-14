#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 2000


int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

   int** result = (int**)malloc(MAX_NODES * sizeof(int*));
   *returnColumnSizes = (int*)malloc(MAX_NODES * sizeof(int));

    struct TreeNode* queue[MAX_NODES];
    int front = 0, rear = 0;
    int size = 0;

    queue[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front;
        result[size] = (int*)malloc(levelSize * sizeof(int));
        (*returnColumnSizes)[size] = levelSize;

        for (int i = 0; i < levelSize; ++i) {
            struct TreeNode* node = queue[front++];
            result[size][i] = node->val;

            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }

        size++;
    }

    *returnSize = size;
    return result;
}
