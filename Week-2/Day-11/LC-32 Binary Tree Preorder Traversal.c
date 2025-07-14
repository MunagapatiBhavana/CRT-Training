/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void preorder(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) return;
    result[(*index)++] = root->val;
    preorder(root->left, result, index);
    preorder(root->right, result, index);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    
    int* result = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;
    preorder(root, result, returnSize);
    return result;
}



