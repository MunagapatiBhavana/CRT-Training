#include <stdlib.h>

// Definition of Node is assumed to be provided
// struct Node {
//     int val;
//     int numNeighbors;
//     struct Node** neighbors;
// };

struct Node* cloneNode(struct Node* node, struct Node** visited) {
    if (!node)
        return NULL;

    // If already cloned, return it
    if (visited[node->val] != NULL)
        return visited[node->val];

    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = node->val;
    newNode->numNeighbors = node->numNeighbors;
    newNode->neighbors = (struct Node**)malloc(sizeof(struct Node*) * node->numNeighbors);

    // Mark this node as visited
    visited[node->val] = newNode;

    // Recursively clone neighbors
    for (int i = 0; i < node->numNeighbors; i++) {
        newNode->neighbors[i] = cloneNode(node->neighbors[i], visited);
    }

    return newNode;
}

struct Node* cloneGraph(struct Node* s) {
    if (!s) return NULL;

    // Map of original val -> cloned node
    // Assuming val is in range 1 to 100
    struct Node* visited[101] = {NULL};

    return cloneNode(s, visited);
}
