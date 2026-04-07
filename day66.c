#include <stdio.h>
#include <stdlib.h>

int dfs(int node, int V, int **adj, int *visited, int *pathVisited) {
    visited[node] = 1;
    pathVisited[node] = 1;

    for (int i = 0; i < V; i++) {
        if (adj[node][i]) {
            if (!visited[i]) {
                if (dfs(i, V, adj, visited, pathVisited))
                    return 1;
            } else if (pathVisited[i]) {
                return 1;
            }
        }
    }

    pathVisited[node] = 0;
    return 0;
}

int isCycle(int V, int **adj) {
    int *visited = (int *)calloc(V, sizeof(int));
    int *pathVisited = (int *)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, V, adj, visited, pathVisited))
                return 1;
        }
    }

    return 0;
}

int main() {
    int V = 4;

    int **adj = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        adj[i] = (int *)calloc(V, sizeof(int));
    }

    adj[0][1] = 1;
    adj[1][2] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;

    if (isCycle(V, adj))
        printf("Cycle detected\n");
    else
        printf("No cycle\n");

    return 0;
}