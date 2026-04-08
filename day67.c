#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int vis[MAX];
int stack[MAX];
int top = -1;

void dfs(int node, int V) {
    vis[node] = 1;

    for (int i = 0; i < V; i++) {
        if (adj[node][i] && !vis[i]) {
            dfs(i, V);
        }
    }

    stack[++top] = node;
}

int main() {
    int V = 6;

    for (int i = 0; i < V; i++) {
        vis[i] = 0;
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }

    adj[5][2] = 1;
    adj[5][0] = 1;
    adj[4][0] = 1;
    adj[4][1] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfs(i, V);
        }
    }

    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}