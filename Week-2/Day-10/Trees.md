## 📘 CRT Day 9

🔄 Linear vs Non-Linear Data Structures

| Category       | Linear                           | Non-Linear                                |
| -------------- | -------------------------------- | ----------------------------------------- |
| **Structure**  | Sequential (elements in order)   | Hierarchical or connected in complex ways |
| **Examples**   | Array, Linked List, Stack, Queue | Tree, Graph                               |
| **Memory Use** | Efficient use of memory          | Complex memory usage                      |
| **Traversal**  | One at a time                    | Multiple ways                             |

## ❗ Limitations of Linear Data Structures
Inefficient for representing complex relationships (e.g., parent-child)

Hard to search in some cases (e.g., unsorted arrays)

Not scalable for hierarchical models like file systems, organization charts, etc.

## 🌳 Introduction to Trees
A tree is a non-linear data structure that simulates a hierarchical structure.

Composed of nodes: each node has a value and references to child nodes.

Root: Top node of the tree

Leaf: Node with no children

## 🌱 Types of Trees
General Tree – No restriction on the number of children

Binary Tree – Each node has at most two children

Binary Search Tree (BST) – Left < Root < Right

AVL Tree – Self-balancing BST

Heap Tree – Max-Heap or Min-Heap based on root property

Complete Binary Tree – All levels are full except possibly the last

Full Binary Tree – Every node has 0 or 2 children

Perfect Binary Tree – All internal nodes have 2 children & all leaves at same level

## 🌲 Binary Tree Traversals
1. Inorder Traversal (Left → Root → Right)
Output: Sorted order for BST

Example: inorder(node.left); print(node); inorder(node.right);

2. Preorder Traversal (Root → Left → Right)
Used to create a copy of the tree

Example: print(node); preorder(node.left); preorder(node.right);

3. Postorder Traversal (Left → Right → Root)
Used to delete the tree

Example: postorder(node.left); postorder(node.right); print(node);

4. Level Order Traversal (Breadth-First)
Uses a queue, processes nodes level by level

// Structure of a tree node

struct Node {

    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node

struct Node* createNode(int value) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

## 🔁 Inorder Traversal (Left → Root → Right)

void inorder(struct Node* root) {

    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

## 🔁 Preorder Traversal (Root → Left → Right)

void preorder(struct Node* root) {

    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

## 🔁 Postorder Traversal (Left → Right → Root)

void postorder(struct Node* root) {

    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

        1
       / \
      2   3
     / \
    4   5
Inorder: 4 2 5 1 3

Preorder: 1 2 4 5 3

Postorder: 4 5 2 3 1

## 🧠 Stack vs Heap Memory

| Feature        | Stack                                    | Heap                                        |
| -------------- | ---------------------------------------- | ------------------------------------------- |
| **Memory**     | Static memory allocation                 | Dynamic memory allocation                   |
| **Access**     | Fast (LIFO - Last In First Out)          | Slower (accessed via pointers)              |
| **Size**       | Limited                                  | Larger than stack                           |
| **Usage**      | Used for function calls, local variables | Used for dynamic memory (e.g., malloc in C) |
| **Managed by** | Compiler                                 | Programmer (manual) / Garbage Collector     |
| **Lifetime**   | Short (ends with function call)          | Long (until deallocated manually)           |
