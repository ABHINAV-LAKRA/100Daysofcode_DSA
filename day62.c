#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int vertex;
    struct Node* next;
};

struct Graph
{
    int numVertices;
    struct Node** adjLists;
};

struct Node* createNode(int v)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices)
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));

    for(int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int isDirected)
{
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    if(!isDirected)
    {
        newNode = createNode(src);
        newNode->next = graph->adjLists[dest];
        graph->adjLists[dest] = newNode;
    }
}

void printGraph(struct Graph* graph)
{
    for(int i = 0; i < graph->numVertices; i++)
    {
        struct Node* temp = graph->adjLists[i];
        printf("Vertex %d: ", i);

        while(temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

int main()
{
    int n, m, choice;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    struct Graph* graph = createGraph(n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter 1 for Directed, 0 for Undirected: ");
    scanf("%d", &choice);

    for(int i = 0; i < m; i++)
    {
        int u, v;
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);

        addEdge(graph, u, v, choice);
    }

    printf("\nAdjacency List:\n");
    printGraph(graph);

    return 0;
}