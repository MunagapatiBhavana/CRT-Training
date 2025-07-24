# 📘 CRT Training – Day 20
# Topics Covered:

Backtracking – Track Record Problem

Introduction to Graph Algorithms

Definitions (22 total)

Degree sequence – Havel-Hakimi Algorithm

DFS, BFS

Finding unreachable nodes

Number of connected components

Max nodes in a single component

# 🔁 Backtracking: Track Record Problem – Word Formation in a Matrix
🧠 Problem Statement:
You're given a 2D matrix of characters (M x N) and a dictionary of valid words. Starting from the top-left cell, your task is to form meaningful words by moving in Right (→), Down (↓), or Diagonal (↘) directions. If no valid word can be formed, backtrack and try a different path.

✅ Constraints:
You can only move in three directions: Right (i, j+1), Down (i+1, j), Diagonal (i+1, j+1)

Words must be present in the given dictionary

You cannot visit the same cell twice in the same path

# 💡 Example Input:
```
Matrix:
S A E
T R P
O G N

Dictionary:
["STAR", "STOP", "STEP", "SAG", "STONE", "SAP", "GEN", "TAP"]
```
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 20
#define MAX_LEN 10
#define ROWS 3
#define COLS 3

// Dictionary of valid words
const char *dictionary[] = {
    "STAR", "STOP", "STEP", "SAG", "STONE", "SAP", "GEN", "TAP"
};
int dict_size = sizeof(dictionary) / sizeof(dictionary[0]);

// The character matrix
char matrix[ROWS][COLS] = {
    {'S', 'A', 'E'},
    {'T', 'R', 'P'},
    {'O', 'G', 'N'}
};

// Check if the word is in the dictionary
bool isValidWord(const char *word) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(dictionary[i], word) == 0)
            return true;
    }
    return false;
}

// Check if cell is within bounds
bool isSafe(int x, int y, bool visited[ROWS][COLS]) {
    return x >= 0 && y >= 0 && x < ROWS && y < COLS && !visited[x][y];
}

// Backtracking function
void searchWord(int x, int y, char word[], int idx, bool visited[ROWS][COLS]) {
    visited[x][y] = true;
    word[idx] = matrix[x][y];
    word[idx + 1] = '\0';

    if (isValidWord(word)) {
        printf("Found Word: %s\n", word);
    }

    // Directions: Right, Down, Diagonal
    int dx[] = {0, 1, 1};
    int dy[] = {1, 0, 1};

    for (int d = 0; d < 3; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (isSafe(nx, ny, visited)) {
            searchWord(nx, ny, word, idx + 1, visited);
        }
    }

    // Backtrack
    visited[x][y] = false;
    word[idx] = '\0';
}

void findWordsInMatrix() {
    bool visited[ROWS][COLS] = {false};
    char word[MAX_LEN];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            searchWord(i, j, word, 0, visited);
        }
    }
}

int main() {
    printf("Words formed from matrix:\n");
    findWordsInMatrix();
    return 0;
}
```

# 📊 Graph Theory – Definitions (22 terms)
```
| Term                         | Definition                                   |
| ---------------------------- | -------------------------------------------- |
| **Graph**                    | A set of vertices (nodes) connected by edges |
| **Order**                    | Number of vertices in a graph                |
| **Size**                     | Number of edges in a graph                   |
| **Degree**                   | Number of edges connected to a vertex        |
| **Indegree**                 | Number of incoming edges to a vertex         |
| **Outdegree**                | Number of outgoing edges from a vertex       |
| **Undirected Graph**         | Edges have no direction                      |
| **Directed Graph (Digraph)** | Edges have direction                         |
| **Weighted Graph**           | Edges have weights (costs)                   |
| **Unweighted Graph**         | Edges have no weights                        |
| **Cyclic Graph**             | Contains at least one cycle                  |
| **Acyclic Graph**            | Contains no cycles                           |
| **Simple Graph**             | No self-loops or multiple edges              |
| **Multi Graph**              | May have multiple edges between same nodes   |
| **Complete Graph (Kn)**      | Each pair of vertices is connected           |
| **Connected Graph**          | Path exists between all node pairs           |
| **Disconnected Graph**       | Not all nodes are reachable                  |
| **Tree**                     | Acyclic connected graph                      |
| **Forest**                   | Collection of disjoint trees                 |
| **Subgraph**                 | A portion of a graph                         |
| **Path**                     | Sequence of vertices connected by edges      |
| **Cycle**                    | Path that starts and ends at same vertex     |
```
# 🧮 Havel-Hakimi Algorithm (Degree Sequence Validation)

✅ Problem:
Given a sequence of degrees, check whether it's possible to construct a simple graph.
```
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to sort array in descending order
void sort_desc(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] < arr[j]) {
                // swap
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Remove all zeros from the sequence
int remove_zeros(int arr[], int n) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0)
            arr[j++] = arr[i];
    }
    return j; // new length
}

bool havel_hakimi(int arr[], int n) {
    int len = n;

    while (1) {
        // Remove zeros
        len = remove_zeros(arr, len);
        if (len == 0) return true;

        // Sort descending
        sort_desc(arr, len);

        int d = arr[0];

        // Remove the first element
        for (int i = 1; i < len; i++)
            arr[i - 1] = arr[i];
        len--;

        if (d > len) return false;

        for (int i = 0; i < d; i++) {
            arr[i]--;
            if (arr[i] < 0) return false;
        }
    }
}

int main() {
    int seq[] = {4, 3, 3, 3, 3};
    int n = sizeof(seq) / sizeof(seq[0]);

    if (havel_hakimi(seq, n))
        printf("True\n");
    else
        printf("False\n");

    return 0;
}
```


# 🌐 DFS – Depth First Search
🔍 Purpose:
Explore as deep as possible from each node before backtracking.
```
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list representation
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjList[MAX];
int visited[MAX];

void addEdge(int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = adjList[src];
    adjList[src] = newNode;

    // For undirected graph
    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

void DFS(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    Node* temp = adjList[vertex];
    while (temp != NULL) {
        int connectedVertex = temp->vertex;
        if (!visited[connectedVertex]) {
            DFS(connectedVertex);
        }
        temp = temp->next;
    }
}

int main() {
    int vertices = 6;

    for (int i = 0; i < vertices; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 4);
    addEdge(3, 5);

    printf("DFS traversal starting from node 0:\n");
    DFS(0);

    return 0;
}
```


# 🌐 BFS – Breadth First Search
🔍 Purpose:
Explore all neighbors before going deeper.
```
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjList[MAX];
int visited[MAX];

typedef struct Queue {
    int items[MAX];
    int front, rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(Queue* q) {
    return q->rear == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX - 1) return;
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(Queue* q) {
    int item;
    if (isEmpty(q)) return -1;
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

void addEdge(int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = adjList[src];
    adjList[src] = newNode;

    // For undirected graph
    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

void BFS(int startVertex) {
    Queue* q = createQueue();
    visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        Node* temp = adjList[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}

int main() {
    int vertices = 6;

    for (int i = 0; i < vertices; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 4);
    addEdge(3, 5);

    printf("BFS traversal starting from node 0:\n");
    BFS(0);

    return 0;
}
```



# ⏱ Time Complexity:
O(V + E) for adjacency list

O(V²) for adjacency matrix



# 🔎 Connected Components
```void dfs(int vertex) {
    visited[vertex] = 1;
    Node* temp = adjList[vertex];
    while (temp) {
        if (!visited[temp->vertex])
            dfs(temp->vertex);
        temp = temp->next;
    }
}

int countConnectedComponents(int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
            count++;
        }
    }
    return count;
}

int main() {
    int n = 7;
    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    // Sample Graph
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(3, 4);
    addEdge(5, 6);

    int components = countConnectedComponents(n);
    printf("Total Connected Components: %d\n", components);
    return 0;
}
```

# 🚫 Finding Unreachable Nodes from Start Node
```
void dfs_unreachable(int vertex) {
    visited[vertex] = 1;
    Node* temp = adjList[vertex];
    while (temp) {
        if (!visited[temp->vertex])
            dfs_unreachable(temp->vertex);
        temp = temp->next;
    }
}

int main() {
    int n = 6, start = 0;

    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    // Graph example
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(4, 5);

    dfs_unreachable(start);

    printf("Unreachable nodes from node %d:\n", start);
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            printf("%d ", i);
    }
    printf("\n");

    return 0;
}
```

# 📈 Max Nodes in a Single Connected Component
```
int dfs_component_size(int vertex) {
    visited[vertex] = 1;
    int size = 1;

    Node* temp = adjList[vertex];
    while (temp) {
        if (!visited[temp->vertex]) {
            size += dfs_component_size(temp->vertex);
        }
        temp = temp->next;
    }
    return size;
}

int main() {
    int n = 7;
    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(4, 5);
    addEdge(5, 6);

    int maxSize = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int size = dfs_component_size(i);
            if (size > maxSize)
                maxSize = size;
        }
    }

    printf("Max nodes in a single component: %d\n", maxSize);
    return 0;
}
```

# 🔧 Common Structure for above 3 problems: Graph Setup
```
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjList[MAX];
int visited[MAX];

void addEdge(int src, int dest) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = adjList[src];
    adjList[src] = newNode;

    // Undirected graph
    newNode = (Node*) malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}
```

