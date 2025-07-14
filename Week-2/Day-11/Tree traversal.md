# 📚 Day 11 - Tree Traversals

Welcome to **Day 11** of our Campus Recruitment Training (CRT) program!  
Today, we focused on core concepts of **binary trees**, traversal techniques, and structural comparisons.

---

## 🗓️ Topics Covered

### 1. ✅ Inorder Traversal Using Stack (Iterative)
- Traverses a binary tree in **Left → Root → Right** order.
- Implemented using an explicit stack instead of recursion.
- Helps understand internal working of recursion with stack memory.

### 2. 🌲 Building Tree from Preorder and Inorder Traversals
- Given:
  - `Preorder`: Root → Left → Right
  - `Inorder`: Left → Root → Right
- We reconstructed the original binary tree using recursive logic.

### 3. ✍️ Drawing the Binary Tree
- Practiced sketching trees based on traversal orders.
- Helped visualize node relationships and hierarchy.

### 4. 🔢 Counting Number of Nodes
- Wrote a function to recursively count:
  - Total nodes in the tree.

### 5. 🌕 Counting Full Nodes
- A **full node** has both left and right children.
- Developed logic to count only those nodes with two children.

### 6. 🔍 Comparing Two Trees
- Checked whether:
  - **Structure** of two trees is the same.
  - **Data** in corresponding nodes is equal.
- Implemented recursive comparison.

---

## 🧠 Key Takeaways
- Binary tree traversals help understand depth-first strategies.
- Tree construction from traversals is essential for many coding interviews.
- Counting nodes helps in tree metrics and evaluation.
- Structural comparison is crucial for checking tree equality.

---


> 📌 Tip: Always draw trees on paper to better understand traversal sequences.

---
## Inorder Traversal Using Stack

// Definition for a binary tree node
struct TreeNode {

    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Stack definition

#define MAX 1000

struct TreeNode* stack[MAX];

int top = -1;

void push(struct TreeNode* node) {

    stack[++top] = node;
}

struct TreeNode* pop() {

    return stack[top--];
}

int isEmpty() {

    return top == -1;
}

// Inorder traversal using stack

void inorderTraversal(struct TreeNode* root) {

    struct TreeNode* current = root;

    while (current != NULL || !isEmpty()) {
        while (current != NULL) {
            push(current);
            current = current->left;
        }

        current = pop();
        printf("%d ", current->val);  // Visit the node

        current = current->right;
    }
}

## Building Tree from Preorder and Inorder Traversals

🧩 Given:

Preorder (Root → Left → Right): 

A, B, D, E, C, F

Inorder (Left → Root → Right):

D, B, E, A, C, F

Step 1:
First element in preorder is A → this is the root.

Step 2:
Find A in inorder:
D, B, E, [A], C, F

→ Left Subtree Inorder: D, B, E
→ Right Subtree Inorder: C, F

Step 3:
Now focus on the left subtree of A.
Next in preorder: B → Root of left subtree.

Find B in left inorder:
D, [B], E

→ Left of B: D
→ Right of B: E

Step 4:
Left child of B: D

(No more children because it doesn't appear again in preorder/inorder)

Right child of B: E

Step 5:
Now build right subtree of A.
Next in preorder: C → right child of A.

In inorder, remaining is:
[C], F → Left: none, Right: F

So, C has no left child, but F is its right child.

        A
       / \
      B   C
     / \    \
    D   E    F
| Traversal Step | Action                                         |
| -------------- | ---------------------------------------------- |
| Preorder Start | A → root                                       |
| Inorder Split  | Left: B subtree, Right: C subtree              |
| Preorder Next  | B → root of left                               |
| Continue       | Recursively assign left/right using order info |
