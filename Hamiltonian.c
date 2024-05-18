#include <stdio.h>
#include <stdbool.h>

#define V 5 // Define the number of vertices

void printSolution(int path[]);

// Utility function to check if the current vertex is adjacent to the previous vertex and if it is already included in the path
bool isSafe(int v, bool graph[V][V], int path[], int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

// A recursive utility function to solve the Hamiltonian Cycle problem
bool hamCycleUtil(bool graph[V][V], int path[], int pos) {
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            if (hamCycleUtil(graph, path, pos + 1) == true)
                return true;

            path[pos] = -1;
        }
    }

    return false;
}

// This function solves the Hamiltonian Cycle problem using backtracking
bool hamCycle(bool graph[V][V]) {
    int path[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0;
    if (hamCycleUtil(graph, path, 1) == false) {
        printf("\nSolution does not exist\n");
        return false;
    }

    printSolution(path);
    return true;
}

// Utility function to print the solution
void printSolution(int path[]) {
    printf("Solution Exists: Following is one Hamiltonian Cycle\n");
    for (int i = 0; i < V; i++)
        printf(" %d ", path[i]);
    printf(" %d \n", path[0]);
}

int main() {
    int vertex;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertex);

    bool graph[vertex][vertex];
    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Print the input adjacency matrix
    printf("\nEntered Adjacency Matrix:\n");
    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    hamCycle(graph);

    return 0;
}


/*
Enter the number of vertices in the graph: 5
Enter the adjacency matrix of the graph:
0 1 0 1 0
1 0 1 1 1
0 1 0 0 1
1 1 0 0 1
0 1 1 1 0

Entered Adjacency Matrix:
0 1 0 1 0
1 0 1 1 1
0 1 0 0 1
1 1 0 0 1
0 1 1 1 0

Solution Exists: Following is one Hamiltonian Cycle
 0  1  2  4  3  0
*/
