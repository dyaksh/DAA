/*#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100

// Structure to represent a node in the multistage graph
typedef struct {
    int value;
} Node;

// Structure to represent an edge in the multistage graph
typedef struct {
    int weight;
    int destination;
} Edge;

int main() {
    int num_stages;
    printf("Enter the number of stages: ");
    scanf("%d", &num_stages);

    int num_nodes[MAX_NODES];
    for (int i = 0; i < num_stages; i++) {
        printf("Enter the number of nodes in stage %d: ", i + 1);
        scanf("%d", &num_nodes[i]);
    }

    Edge edges[MAX_NODES][MAX_NODES];
    for (int i = 0; i < num_stages - 1; i++) {
        printf("Edges from stage %d to stage %d:\n", i + 1, i + 2);
        for (int j = 0; j < num_nodes[i]; j++) {
            for (int k = 0; k < num_nodes[i + 1]; k++) {
                printf("Enter weight of edge from node %d in stage %d to node %d in stage %d: ",
                       j + 1, i + 1, k + 1, i + 2);
                scanf("%d", &edges[i][j].weight);
                edges[i][j].destination = k;
            }
        }
    }

    // Initialize the multistage graph as an array of nodes
    Node nodes[MAX_NODES];

    // Initialize node values
    for (int i = 0; i < num_stages; i++) {
        for (int j = 0; j < num_nodes[i]; j++) {
            nodes[i * MAX_NODES + j].value = INT_MAX; // Initialize node values to infinity
        }
    }

    // Set the value of the final stage nodes to 0
    for (int i = 0; i < num_nodes[num_stages - 1]; i++) {
        nodes[(num_stages - 1) * MAX_NODES + i].value = 0;
    }

    // Traverse the multistage graph backward to find the optimal values
    for (int i = num_stages - 2; i >= 0; i--) {
        for (int j = 0; j < num_nodes[i]; j++) {
            for (int k = 0; k < num_nodes[i + 1]; k++) {
                int destination = edges[i][j].destination;
                int weight = edges[i][j].weight;
                nodes[i * MAX_NODES + j].value =
                    fmin(nodes[i * MAX_NODES + j].value, weight + nodes[(i + 1) * MAX_NODES + destination].value);
            }
        }
    }

    // Print the optimal values of the nodes in the first stage
    printf("Optimal values of nodes in the first stage:\n");
    for (int i = 0; i < num_nodes[0]; i++) {
        printf("Node %d: %d\n", i + 1, nodes[i].value);
    }

    return 0;
}
*/
#include <stdio.h>
#include <limits.h>

int minFunction(int a, int b) {
    return (a < b) ? a : b;
}

int multistageGraph(int vertex, int graph[vertex][vertex]) {
    int dist[vertex];
    for (int i = 0; i < vertex; i++)
        dist[i] = INT_MAX;

    dist[vertex-1] = 0;

    for (int i = vertex - 2; i >= 0; i--) {
        for (int j = i; j < vertex; j++) {
            if (graph[i][j] != 0) {
                dist[i] = minFunction(dist[i], graph[i][j] + dist[j]);
            }
        }
    }
    return dist[0];
}

//user inputs and multistageGraph() call
int main() {
    int vertex, edgeCount;

    printf("Enter the total vertices of the graph : ");
    scanf("%d", &vertex);
    int G[vertex][vertex];
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            G[i][j] = 0;
        }
    }
    for (int i = 0; i < vertex; i++)
    {
        printf("Total Edges of vertex %d : ", i + 1);
        scanf("%d", &edgeCount);
        for (int j = 0; j < edgeCount; j++)
        {
            int vertexIndex, edgeWeight;
            printf("Enter the vertex number : ");
            scanf("%d", &vertexIndex);
            printf("Enter the edge weight : ");
            scanf("%d", &edgeWeight);
            G[i][vertexIndex - 1] = edgeWeight; // Corrected index
        }

        printf("\n");
    }

    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
            printf("%d ", G[i][j]);
        printf("\n");
    }
    printf("Minimum distance from the first stage to the last stage: %d\n", multistageGraph(vertex, G));

    return 0;
}
