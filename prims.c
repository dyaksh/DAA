#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent a graph
struct Graph {
    int numVertices;
    int** adjacencyMatrix;
};

// Function to create a graph with user input
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    // Allocate memory for adjacency matrix
    graph->adjacencyMatrix = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjacencyMatrix[i] = (int*)malloc(numVertices * sizeof(int));
    }

    // Initialize adjacency matrix with user input
    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("Weight from vertex %d to vertex %d: ", i, j);
            scanf("%d", &graph->adjacencyMatrix[i][j]);
        }
    }

    return graph;
}

// Function to find the vertex with minimum key value
int minKey(int key[], int mstSet[], int numVertices) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < numVertices; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the constructed MST
void printMST(int parent[], struct Graph* graph) {
    printf("Edge   Weight\n");
    for (int i = 1; i < graph->numVertices; i++) {
        printf("%d - %d    %d \n", parent[i], i, graph->adjacencyMatrix[i][parent[i]]);
    }
}

// Function to find the minimum spanning tree using Prim's algorithm
void primMST(struct Graph* graph) {
    int parent[graph->numVertices]; // Array to store constructed MST
    int key[graph->numVertices];    // Key values used to pick minimum weight edge in cut
    int mstSet[graph->numVertices]; // Array to represent set of vertices not yet included in MST

    // Initialize all keys as INFINITE and mstSet[] as 0
    for (int i = 0; i < graph->numVertices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    // Always include first vertex in MST
    key[0] = 0;
    parent[0] = -1; // First node is always root of MST

    // Construct MST with (V-1) vertices
    for (int count = 0; count < graph->numVertices - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet, graph->numVertices);

        // Add the picked vertex to the MST set
        mstSet[u] = 1;

        // Update key value and parent index of adjacent vertices
        for (int v = 0; v < graph->numVertices; v++) {
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph->adjacencyMatrix[u][v] && mstSet[v] == 0 && graph->adjacencyMatrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph->adjacencyMatrix[u][v];
            }
        }
    }

    // Print the constructed MST
    printMST(parent, graph);
}

int main() {
    int numVertices;

    // Take input for the number of vertices in the graph
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    // Create the graph with user input
    struct Graph* graph = createGraph(numVertices);

    // Find the Minimum Spanning Tree (MST) using Prim's algorithm
    primMST(graph);

    // Free dynamically allocated memory
    for (int i = 0; i < numVertices; i++) {
        free(graph->adjacencyMatrix[i]);
    }
    free(graph->adjacencyMatrix);
    free(graph);

    return 0;
}
