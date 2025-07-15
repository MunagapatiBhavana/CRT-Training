int getHeight(struct TreeNode* node) {
    int height = 0;
    while (node) {
        height++;
        node = node->left;
    }
    return height;
}

int countNodes(struct TreeNode* root) {
    if (!root)
        return 0;

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    if (leftHeight == rightHeight) {
        // Left subtree is perfect
        return (1 << leftHeight) + countNodes(root->right);
    } else {
        // Right subtree is perfect
        return (1 << rightHeight) + countNodes(root->left);
    }
}
