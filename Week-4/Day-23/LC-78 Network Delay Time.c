#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXN 101
#define INF 0x3f3f3f3f

typedef struct {
    int to, weight;
} Edge;

typedef struct {
    Edge edges[MAXN];
    int edgeCount;
} AdjList;

typedef struct {
    int node, dist;
} HeapNode;

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Min-heap implementation
typedef struct {
    HeapNode heap[MAXN * MAXN];
    int size;
} MinHeap;

void heapifyUp(MinHeap* h, int i) {
    while (i > 0 && h->heap[i].dist < h->heap[(i - 1) / 2].dist) {
        swap(&h->heap[i], &h->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(MinHeap* h, int i) {
    int smallest = i, left = 2 * i + 1, right = 2 * i + 2;

    if (left < h->size && h->heap[left].dist < h->heap[smallest].dist)
        smallest = left;
    if (right < h->size && h->heap[right].dist < h->heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&h->heap[i], &h->heap[smallest]);
        heapifyDown(h, smallest);
    }
}

void push(MinHeap* h, int node, int dist) {
    h->heap[h->size++] = (HeapNode){node, dist};
    heapifyUp(h, h->size - 1);
}

HeapNode pop(MinHeap* h) {
    HeapNode top = h->heap[0];
    h->heap[0] = h->heap[--h->size];
    heapifyDown(h, 0);
    return top;
}

int isEmpty(MinHeap* h) {
    return h->size == 0;
}

// Main function
int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k) {
    AdjList graph[MAXN] = {0};

    // Build the graph
    for (int i = 0; i < timesSize; i++) {
        int u = times[i][0], v = times[i][1], w = times[i][2];
        graph[u].edges[graph[u].edgeCount++] = (Edge){v, w};
    }

    int dist[MAXN];
    for (int i = 1; i <= n; i++) dist[i] = INF;
    dist[k] = 0;

    MinHeap heap = {0};
    push(&heap, k, 0);

    while (!isEmpty(&heap)) {
        HeapNode current = pop(&heap);
        int u = current.node;
        int d = current.dist;

        if (d > dist[u]) continue;

        for (int i = 0; i < graph[u].edgeCount; i++) {
            Edge e = graph[u].edges[i];
            if (dist[e.to] > dist[u] + e.weight) {
                dist[e.to] = dist[u] + e.weight;
                push(&heap, e.to, dist[e.to]);
            }
        }
    }

    int maxTime = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) return -1;
        if (dist[i] > maxTime) maxTime = dist[i];
    }

    return maxTime;
}
