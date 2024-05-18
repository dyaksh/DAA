#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V_MAX 100 // Maximum number of vertices in the graph

bool graph[V_MAX][V_MAX]; // Adjacency matrix representation of the graph
int V; // Number of vertices in the graph

void showColors(int color[]) {
    printf("Assigned Colors are:\n");
    for (int i = 0; i < V; i++)
        printf("%d ", color[i]);
    printf("\n");
}

// Check whether putting a color is valid for vertex v
bool isValid(int v, int color[], int c) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

bool graphColoring(int colors, int color[], int vertex) {
    // When all vertices are considered
    if (vertex == V)
        return true;

    for (int col = 1; col <= colors; col++) {
        // Check whether color is valid or not
        if (isValid(vertex, color, col)) {
            color[vertex] = col;
            // Go for additional vertices
            if (graphColoring(colors, color, vertex + 1))
                return true;
            color[vertex] = 0;
        }
    }
    // When no colors can be assigned
    return false;
}

bool checkSolution(int m) {
    // Make color matrix for each vertex
    int *color = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++)
        // Initially set to 0
        color[i] = 0;

    // For vertex 0, check graph coloring
    if (graphColoring(m, color, 0) == false) {
        printf("Solution does not exist.\n");
        free(color);
        return false;
    }

    showColors(color);
    free(color);
    return true;
}

int main() {
    // User input for the number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the adjacency matrix (0/1):\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    // Number of colors
    int colors;
    printf("Enter the number of colors: ");
    scanf("%d", &colors);

    checkSolution(colors);
    return 0;
}
/*
Enter the number of vertices: 4
Enter the adjacency matrix (0/1):
0 1 1 1
1 0 1 0
1 1 0 1
1 0 1 0
Enter the number of colors: 3
*/
