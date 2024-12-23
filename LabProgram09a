/*Q9(a) Write a C program to traverse a graph using BFS method*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

void addEdge(int adj[MAX][MAX], int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1; 
}

void bfs(int adj[MAX][MAX], int V, int start) {
    bool visited[MAX] = {false};
    int queue[MAX];
    int front = 0, rear = 0;

    visited[start] = true;
    queue[rear++] = start;

    printf("BFS Traversal: ");
    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < V; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
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
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &start);

    printf("BFS starting from vertex %d:\n", start);
    bfs(adj, V, start);

    return 0;
}


