#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[n][n];
    int indegree[n];
    int i, j;

    for(i = 0; i < n; i++) {
        indegree[i] = 0;
        for(j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    for(i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    int queue[n];
    int front = 0, rear = 0;

    for(i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int topo[n];
    int index = 0;

    while(front < rear) {
        int node = queue[front++];
        topo[index++] = node;

        for(i = 0; i < n; i++) {
            if(adj[node][i] == 1) {
                indegree[i]--;
                if(indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    if(index != n) {
        printf("Cycle detected, topological sort not possible");
    } else {
        for(i = 0; i < n; i++) {
            printf("%d ", topo[i]);
        }
    }

    return 0;
}