#include <stdio.h>
#include <stdlib.h>

int dfs(int node, int parent, int visited[], int** adj, int* adjSize) {
    visited[node] = 1;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, node, visited, adj, adjSize))
                return 1;
        } else if (neighbor != parent) {
            return 1;
        }
    }

    return 0;
}

int hasCycle(int V, int** adj, int* adjSize) {
    int* visited = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, adj, adjSize)) {
                free(visited);
                return 1;
            }
        }
    }

    free(visited);
    return 0;
}

int main() {
    int V = 5;

    int* adjSize = (int*)malloc(V * sizeof(int));
    int** adj = (int**)malloc(V * sizeof(int*));

    adjSize[0] = 2;
    adj[0] = (int*)malloc(2 * sizeof(int));
    adj[0][0] = 1; adj[0][1] = 2;

    adjSize[1] = 2;
    adj[1] = (int*)malloc(2 * sizeof(int));
    adj[1][0] = 0; adj[1][1] = 2;

    adjSize[2] = 3;
    adj[2] = (int*)malloc(3 * sizeof(int));
    adj[2][0] = 0; adj[2][1] = 1; adj[2][2] = 3;

    adjSize[3] = 2;
    adj[3] = (int*)malloc(2 * sizeof(int));
    adj[3][0] = 2; adj[3][1] = 4;

    adjSize[4] = 1;
    adj[4] = (int*)malloc(1 * sizeof(int));
    adj[4][0] = 3;

    if (hasCycle(V, adj, adjSize))
        printf("Cycle detected\n");
    else
        printf("No cycle\n");

    return 0;
}