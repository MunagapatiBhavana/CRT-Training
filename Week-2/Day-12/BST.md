 Day 12: Binary Search Trees (BST)

 📅 Topics Covered:
Introduction to Binary Search Tree (BST)

Insertion in BST (Recursive & Iterative)

Deletion in BST

Constructing BST from Postorder Traversal

Lowest Common Ancestor (LCA) – based on Value & Level

Inorder Predecessor & Successor

🌳 1. Binary Search Tree (BST)
A BST is a binary tree in which:

Left child < Parent node

Right child > Parent node

🔧 2. Insertion in BST

✅ Recursive Approach

struct TreeNode* insertBST(struct TreeNode* root, int val) {

    if (root == NULL) {
        struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->val = val;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (val < root->val)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);
    return root;
}

✅ Iterative Approach

struct TreeNode* insertIterative(struct TreeNode* root, int val) {

    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = newNode->right = NULL;

    if (!root) return newNode;

    struct TreeNode* parent = NULL, *curr = root;
    while (curr) {
        parent = curr;
        if (val < curr->val)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (val < parent->val)
        parent->left = newNode;
    else
        parent->right = newNode;

    return root;
}

❌ 3. Deletion in BST

struct TreeNode* findMax(struct TreeNode* root) {

    while (root && root->right)
        root = root->right;
    return root;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (!root) return NULL;

    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (!root->right) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        struct TreeNode* temp = findMax(root->left);
        root->val = temp->val;
        root->left = deleteNode(root->left, temp->val);
    }
    return root;
}

🧩 4. Construct BST from Postorder Traversal
Example: Postorder = [1, 7, 5, 50, 40, 10]

int idx;

struct TreeNode* constructBSTFromPostorderUtil(int post[], int min, int max) {

    if (idx < 0)
        return NULL;

    int val = post[idx];
    if (val < min || val > max)
        return NULL;

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = val;
    idx--;
    root->right = constructBSTFromPostorderUtil(post, val, max);
    root->left = constructBSTFromPostorderUtil(post, min, val);
    return root;
}

struct TreeNode* constructBSTFromPostorder(int post[], int size) {

    idx = size - 1;
    return constructBSTFromPostorderUtil(post, INT_MIN, INT_MAX);
}

🔍 5. Lowest Common Ancestor (LCA)

✅ Based on Value

struct TreeNode* findLCA(struct TreeNode* root, int n1, int n2) {

    if (!root) return NULL;
    if (root->val > n1 && root->val > n2)
        return findLCA(root->left, n1, n2);
    if (root->val < n1 && root->val < n2)
        return findLCA(root->right, n1, n2);
    return root;
}

✅ Based on Level (Depth-first Search)

int findLevel(struct TreeNode* root, int val, int level) {

    if (!root) return -1;
    if (root->val == val) return level;
    int left = findLevel(root->left, val, level + 1);
    if (left != -1) return left;
    return findLevel(root->right, val, level + 1);
}

🔁 6. Inorder Predecessor & Successor

void findPreSuc(struct TreeNode* root, struct TreeNode** pre, struct TreeNode** suc, int key) {
    if (!root) return;

    if (root->val == key) {
        if (root->left) {
            struct TreeNode* tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            *pre = tmp;
        }

        if (root->right) {
            struct TreeNode* tmp = root->right;
            while (tmp->left)
                tmp = tmp->left;
            *suc = tmp;
        }
        return;
    }

    if (key < root->val) {
        *suc = root;
        findPreSuc(root->left, pre, suc, key);
    } else {
        *pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
}

🟦 Inorder Predecessor
The inorder predecessor of a node in a BST is the previous node in the inorder traversal.

It is the largest value node in the left subtree of the given node.

How to find it:

If the node has a left child, go to the rightmost node in its left subtree.

🟩 Inorder Successor
The inorder successor of a node in a BST is the next node in the inorder traversal.

It is the smallest value node in the right subtree of the given node.

How to find it:

If the node has a right child, go to the leftmost node in its right subtree.
