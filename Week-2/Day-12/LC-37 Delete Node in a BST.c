struct TreeNode* findmax(struct TreeNode* root) {
    if (root == NULL)
        return root;
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (root == NULL)
        return NULL;

    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        
        if (root->left && root->right) {
            struct TreeNode* temp = findmax(root->left); 
            root->val = temp->val;
            root->left = deleteNode(root->left, temp->val); 
        } else {
            struct TreeNode* temp = root;
            if (root->left == NULL)
                root = root->right;
            else if (root->right == NULL)
                root = root->left;
            free(temp);
        }
    }
    return root;
}
