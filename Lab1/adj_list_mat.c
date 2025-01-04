
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 5  // Define the maximum number of nodes

// Struct for Adjacency List Node
struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

// Struct for Adjacency List
struct AdjList {
    struct AdjListNode* head;
};

// Function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge in the adjacency list
void addEdgeAdjList(struct AdjList* adjList, int src, int dest) {
    // Add an edge from src to dest
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = adjList[src].head;
    adjList[src].head = newNode;

    // If the graph is undirected, add an edge from dest to src as well
    newNode = newAdjListNode(src);
    newNode->next = adjList[dest].head;
    adjList[dest].head = newNode;
}

// Function to print the adjacency list
void printAdjList(struct AdjList* adjList, int nodes) {
    for (int i = 0; i < nodes; i++) {
        struct AdjListNode* temp = adjList[i].head;
        printf("Adjacency list of vertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->dest);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Function to print the adjacency matrix
void printAdjMatrix(int adjMatrix[MAX_NODES][MAX_NODES], int nodes) {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int nodes = MAX_NODES;

    // 1. Adjacency List representation
    struct AdjList* adjList = (struct AdjList*) malloc(nodes * sizeof(struct AdjList));

    // Initialize adjacency list
    for (int i = 0; i < nodes; i++) {
        adjList[i].head = NULL;
    }

    // Add edges to the graph
    addEdgeAdjList(adjList, 0, 1);
    addEdgeAdjList(adjList, 0, 4);
    addEdgeAdjList(adjList, 1, 2);
    addEdgeAdjList(adjList, 1, 3);
    addEdgeAdjList(adjList, 1, 4);
    addEdgeAdjList(adjList, 2, 3);
    addEdgeAdjList(adjList, 3, 4);

    // Print Adjacency List
    printf("Adjacency List Representation:\n");
    printAdjList(adjList, nodes);

    // 2. Adjacency Matrix representation
    int adjMatrix[MAX_NODES][MAX_NODES] = {0};  // Initialize all values to 0

    // Add edges to the adjacency matrix
    adjMatrix[0][1] = adjMatrix[1][0] = 1;
    adjMatrix[0][4] = adjMatrix[4][0] = 1;
    adjMatrix[1][2] = adjMatrix[2][1] = 1;
    adjMatrix[1][3] = adjMatrix[3][1] = 1;
    adjMatrix[1][4] = adjMatrix[4][1] = 1;
    adjMatrix[2][3] = adjMatrix[3][2] = 1;
    adjMatrix[3][4] = adjMatrix[4][3] = 1;

    // Print Adjacency Matrix
    printAdjMatrix(adjMatrix, nodes);

    // Free memory for adjacency list
    for (int i = 0; i < nodes; i++) {
        struct AdjListNode* temp = adjList[i].head;
        while (temp) {
            struct AdjListNode* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(adjList);

    return 0;
}
