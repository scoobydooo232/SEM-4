#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void topologicalSort(int graph[MAX][MAX], int n) {
    int inDegree[MAX] = {0};
    int stack[MAX], top = -1;
    int i, j;

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(graph[i][j] == 1) {
                inDegree[j]++;
            }
        }
    }

    for(i = 0; i < n; i++) {
        if(inDegree[i] == 0) {
            stack[++top] = i;
        }
    }

    while(top != -1) {
        int node = stack[top--];
        printf("%d ", node);

        for(i = 0; i < n; i++) {
            if(graph[node][i] == 1) {
                inDegree[i]--;
                if(inDegree[i] == 0) {
                    stack[++top] = i;
                }
            }
        }
    }
}

int main() {
    int n, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[MAX][MAX] = {0};
    printf("Enter the adjacency matrix (0 for no edge, 1 for edge):\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Topological Sort: ");
    topologicalSort(graph, n);

    return 0;
}
