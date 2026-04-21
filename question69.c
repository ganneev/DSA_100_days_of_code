#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

struct Node {
    int vertex, weight;
    struct Node* next;
};

struct Node* adj[MAX];

struct MinHeapNode {
    int v, dist;
};

struct MinHeap {
    int size;
    struct MinHeapNode heap[MAX];
};

void swap(struct MinHeapNode* a, struct MinHeapNode* b) {
    struct MinHeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct MinHeap* h, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < h->size && h->heap[left].dist < h->heap[smallest].dist)
        smallest = left;

    if(right < h->size && h->heap[right].dist < h->heap[smallest].dist)
        smallest = right;

    if(smallest != i) {
        swap(&h->heap[i], &h->heap[smallest]);
        heapify(h, smallest);
    }
}

struct MinHeapNode extractMin(struct MinHeap* h) {
    struct MinHeapNode root = h->heap[0];
    h->heap[0] = h->heap[--h->size];
    heapify(h, 0);
    return root;
}

void insertHeap(struct MinHeap* h, int v, int dist) {
    int i = h->size++;
    h->heap[i].v = v;
    h->heap[i].dist = dist;

    while(i && h->heap[(i-1)/2].dist > h->heap[i].dist) {
        swap(&h->heap[i], &h->heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

void addEdge(int u, int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = u;
    newNode->weight = w;
    newNode->next = adj[v];
    adj[v] = newNode;
}

void dijkstra(int src, int n) {
    int dist[MAX];

    for(int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    struct MinHeap heap;
    heap.size = 0;

    dist[src] = 0;
    insertHeap(&heap, src, 0);

    while(heap.size > 0) {
        struct MinHeapNode minNode = extractMin(&heap);
        int u = minNode.v;

        struct Node* temp = adj[u];
        while(temp) {
            int v = temp->vertex;
            int weight = temp->weight;

            if(dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                insertHeap(&heap, v, dist[v]);
            }

            temp = temp->next;
        }
    }

    for(int i = 0; i < n; i++)
        printf("Distance from %d to %d = %d\n", src, i, dist[i]);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
        adj[i] = NULL;

    int u, v, w;
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int src;
    scanf("%d", &src);

    dijkstra(src, n);

    return 0;
}