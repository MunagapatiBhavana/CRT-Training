# Day21-Graph-Algorithms

## Topics Covered

1. Adjacency List Representation
2. Detect Cycle in Undirected Graph
3. Spanning Tree for Complete Graph
4. Detect Cycle in Directed Graph
5. Prim's Algorithm
6. Kruskal's Algorithm
7. Kirchhoff’s Theorem
8. Dense vs Sparse Graphs
9. Kahn's Algorithm (Topological Sorting)

# 01_adjacency_list.c

```
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int dest;
    struct Node* next;
} Node;

Node* createNode(int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node* adjList[], int u, int v) {
    Node* node = createNode(v);
    node->next = adjList[u];
    adjList[u] = node;
}

void printGraph(Node* adjList[], int V) {
    for (int i = 0; i < V; i++) {
        Node* temp = adjList[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->dest);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int V = 5;
    Node* adjList[5] = {NULL};

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 4);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);

    printGraph(adjList, V);
    return 0;
}
```

# 02_detect_cycle_undirected.c
```
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX], visited[MAX];

bool dfs(int v, int parent, int n) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i]) {
            if (!visited[i]) {
                if (dfs(i, v, n))
                    return true;
            } else if (i != parent)
                return true;
        }
    }
    return false;
}

int main() {
    int n = 5;
    adj[0][1] = adj[1][0] = 1;
    adj[1][2] = adj[2][1] = 1;
    adj[2][3] = adj[3][2] = 1;
    adj[3][4] = adj[4][3] = 1;
    adj[4][1] = adj[1][4] = 1;  // cycle

    if (dfs(0, -1, n))
        printf("Cycle Detected\n");
    else
        printf("No Cycle\n");

    return 0;
}
```
# 03_detect_cycle_directed.c

```
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX], visited[MAX], recStack[MAX];

int dfs(int v, int n) {
    visited[v] = 1;
    recStack[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i]) {
            if (!visited[i] && dfs(i, n))
                return 1;
            else if (recStack[i])
                return 1;
        }
    }

    recStack[v] = 0;
    return 0;
}

int main() {
    int n = 4;
    adj[0][1] = 1;
    adj[1][2] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;  // cycle

    if (dfs(0, n))
        printf("Cycle Detected\n");
    else
        printf("No Cycle\n");

    return 0;
}
```

# 04_spanning_tree_complete_graph.c

```
#include <stdio.h>

int main() {
    int n = 5; // number of vertices in complete graph
    int edges = n * (n - 1) / 2;
    int spanning_tree_edges = n - 1;

    printf("In complete graph with %d vertices:\n", n);
    printf("Total Edges: %d\n", edges);
    printf("Spanning Tree Edges: %d\n", spanning_tree_edges);

    return 0;
}
```

# 05_prims_algorithm.c
```
#include <stdio.h>
#include <limits.h>
#define V 5

int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void primMST(int graph[V][V]) {
    int parent[V], key[V], mstSet[V];

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = 0;

    key[0] = 0; parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);
    return 0;
}
```

# 06_kruskals_algorithm.c

```
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} Edge;

int parent[100];

int find(int i) {
    while (i != parent[i])
        i = parent[i];
    return i;
}

void union_set(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    parent[rootB] = rootA;
}

int cmp(const void* a, const void* b) {
    return ((Edge*)a)->w - ((Edge*)b)->w;
}

int main() {
    int V = 4, E = 5;
    Edge edges[] = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}
    };

    qsort(edges, E, sizeof(Edge), cmp);

    for (int i = 0; i < V; i++) parent[i] = i;

    int cost = 0;
    for (int i = 0; i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if (find(u) != find(v)) {
            printf("Edge %d-%d included with weight %d\n", u, v, w);
            cost += w;
            union_set(u, v);
        }
    }

    printf("Total cost: %d\n", cost);
    return 0;
}
```

# Kirchhoff’s Theorem

Kirchhoff’s Matrix-Tree Theorem provides a method to calculate the number of spanning trees in a connected graph using its Laplacian matrix.

Steps:
1. Create the Laplacian matrix (L = Degree Matrix - Adjacency Matrix).

2. Remove any one row and column.

3. Compute the determinant of the resulting matrix.

# Dense vs Sparse Graphs

- Dense Graph: A graph with edges close to the maximum possible (E ≈ V²)
  
- Sparse Graph: A graph with few edges (E << V²)

## Time Complexities

| Operation           | Adjacency Matrix | Adjacency List |
|---------------------|------------------|----------------|
| Space               | O(V^2)           | O(V + E)       |
| Add Edge            | O(1)             | O(1)           |
| Check Edge Exists   | O(1)             | O(degree)      |

# 09_kahns_algorithm_topo_sort.c

```
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) return;
    queue[++rear] = x;
    if (front == -1) front = 0;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int main() {
    int n = 6, inDegree[6] = {0}, adj[6][6] = {0};

    // Sample DAG
    adj[5][2] = adj[5][0] = 1;
    adj[4][0] = adj[4][1] = 1;
    adj[2][3] = adj[3][1] = 1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (adj[i][j]) inDegree[j]++;

    for (int i = 0; i < n; i++)
        if (inDegree[i] == 0) enqueue(i);

    printf("Topological Order: ");
    while (front <= rear) {
        int node = dequeue();
        printf("%d ", node);
        for (int i = 0; i < n; i++) {
            if (adj[node][i]) {
                inDegree[i]--;
                if (inDegree[i] == 0)
                    enqueue(i);
            }
        }
    }

    return 0;
}
```
