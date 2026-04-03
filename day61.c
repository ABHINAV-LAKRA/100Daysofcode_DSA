#include <stdio.h>

int main()
{
    int n, m;
    int choice;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[n][n];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            adj[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter 1 for Directed Graph, 2 for Undirected Graph: ");
    scanf("%d", &choice);

    for(int i = 0; i < m; i++)
    {
        int u, v;
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;

        if(choice == 2)
        {
            adj[v][u] = 1;
        }
    }

    printf("\nAdjacency Matrix:\n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}