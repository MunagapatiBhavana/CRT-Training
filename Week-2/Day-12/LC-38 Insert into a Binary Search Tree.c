#include <stdio.h>
#include <stdlib.h>



// Create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newnode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (!newnode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newnode->val = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// Insert a value into the BST
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if (!root)
        return createNode(val);
    if (val < root->val)
        root->left = insertIntoBST(root->left, val);
    else
        root->right = insertIntoBST(root->right, val);
    return root;
}
