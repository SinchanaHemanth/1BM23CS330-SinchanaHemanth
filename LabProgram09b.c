9b 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

void addEdge(int adj[MAX][MAX], int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1; 
}

void dfs(int adj[MAX][MAX], int V, int s, bool visited[MAX]) {
    visited[s] = true;
    printf("%d ", s);

    for (int i = 0; i < V; i++) {
        if (adj[s][i] == 1 && !visited[i]) {
            dfs(adj, V, i, visited);
        }
    }
}

int main() {
    int V, E;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    int adj[MAX][MAX] = {0};

    printf("Enter the edges (u v) for the graph:\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    int start;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &start);

    bool visited[MAX] = {false};

    printf("DFS Traversal starting from vertex %d:\n", start);
    dfs(adj, V, start, visited);

    return 0;
}