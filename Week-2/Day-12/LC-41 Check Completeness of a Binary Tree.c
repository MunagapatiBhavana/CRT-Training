#include <stdbool.h>
#include <stdlib.h>

// Definition for a binary tree node.


bool isCompleteTree(struct TreeNode* root) {
    if (!root) return true;

    // Simple queue implementation using array
    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 1000);
    int front = 0, rear = 0;

    queue[rear++] = root;
    bool nullSeen = false;

    while (front < rear) {
        struct TreeNode* current = queue[front++];

        if (current == NULL) {
            nullSeen = true;
        } else {
            if (nullSeen) {
                // Found a non-null node after a null → not complete
                free(queue);
                return false;
            }
            queue[rear++] = current->left;
            queue[rear++] = current->right;
        }
    }

    free(queue);
    return true;
}
