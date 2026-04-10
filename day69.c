#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int v, dist;
};

struct MinHeap {
    struct Node heap[MAX];
    int size;
};

void swap(struct Node *a, struct Node *b) {
    struct Node temp = *a;
    *a = *b;
    *b = temp;
}

void push(struct MinHeap *h, int v, int dist) {
    int i = h->size++;
    h->heap[i].v = v;
    h->heap[i].dist = dist;

    while(i > 0) {
        int parent = (i - 1) / 2;
        if(h->heap[parent].dist <= h->heap[i].dist) break;
        swap(&h->heap[parent], &h->heap[i]);
        i = parent;
    }
}

struct Node pop(struct MinHeap *h) {
    struct Node root = h->heap[0];
    h->heap[0] = h->heap[--h->size];

    int i = 0;
    while(1) {
        int left = 2*i + 1, right = 2*i + 2, smallest = i;

        if(left < h->size && h->heap[left].dist < h->heap[smallest].dist)
            smallest = left;
        if(right < h->size && h->heap[right].dist < h->heap[smallest].dist)
            smallest = right;

        if(smallest == i) break;
        swap(&h->heap[i], &h->heap[smallest]);
        i = smallest;
    }
    return root;
}

int isEmpty(struct MinHeap *h) {
    return h->size == 0;
}

struct Edge {
    int to, weight;
};

struct Graph {
    struct Edge adj[MAX][MAX];
    int size[MAX];
};

void addEdge(struct Graph *g, int u, int v, int w) {
    g->adj[u][g->size[u]].to = v;
    g->adj[u][g->size[u]].weight = w;
    g->size[u]++;
}

void dijkstra(struct Graph *g, int V, int src) {
    int dist[MAX];
    for(int i = 0; i < V; i++) dist[i] = 1e9;

    struct MinHeap h;
    h.size = 0;

    dist[src] = 0;
    push(&h, src, 0);

    while(!isEmpty(&h)) {
        struct Node curr = pop(&h);
        int u = curr.v;
        int d = curr.dist;

        if(d > dist[u]) continue;

        for(int i = 0; i < g->size[u]; i++) {
            int v = g->adj[u][i].to;
            int w = g->adj[u][i].weight;

            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(&h, v, dist[v]);
            }
        }
    }

    for(int i = 0; i < V; i++) {
        printf("%d ", dist[i]);
    }
}

int main() {
    int V = 5;
    struct Graph g;

    for(int i = 0; i < V; i++) g.size[i] = 0;

    addEdge(&g, 0, 1, 2);
    addEdge(&g, 0, 2, 4);
    addEdge(&g, 1, 2, 1);
    addEdge(&g, 1, 3, 7);
    addEdge(&g, 2, 4, 3);
    addEdge(&g, 3, 4, 1);

    dijkstra(&g, V, 0);

    return 0;
}