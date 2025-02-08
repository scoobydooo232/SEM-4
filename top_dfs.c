#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack[MAX];  
int top = -1;    

void DFS(int v, int adj[MAX][MAX], int visited[MAX], int n) {
    visited[v] = 1;  
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            DFS(i, adj, visited, n);
        }
    }
    
    stack[++top] = v;
}

void topologicalSort(int adj[MAX][MAX], int visited[MAX], int n) {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(i, adj, visited, n);
        }
    }

    printf("Topological Sort: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[n][n];   
    int visited[n];  

    for (int i = 0; i < n; i++) {
        visited[i] = 0;  
    }

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    topologicalSort(adj, visited, n);

    return 0;
    
}






