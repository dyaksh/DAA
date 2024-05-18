#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

typedef struct {
    int u, v, weight;
} Edge;

void bellmanFord(int vertices, int edges, Edge edgeList[], int start) {
    int distance[vertices];
    for (int i = 0; i < vertices; i++) {
        distance[i] = INF;
    }
    distance[start] = 0;

    for (int i = 1; i <= vertices - 1; i++) {
        for (int j = 0; j < edges; j++) {
            int u = edgeList[j].u;
            int v = edgeList[j].v;
            int weight = edgeList[j].weight;
            if (distance[u] != INF && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (int i = 0; i < edges; i++) {
        int u = edgeList[i].u;
        int v = edgeList[i].v;
        int weight = edgeList[i].weight;
        if (distance[u] != INF && distance[u] + weight < distance[v]) {
            printf("Graph contains a negative-weight cycle\n");
            return;
        }
    }

    printf("Vertex Distance from Source\n");
    for (int i = 0; i < vertices; i++) {
        if (distance[i] == INF) {
            printf("%d \t INF\n", i);
        } else {
            printf("%d \t %d\n", i, distance[i]);
        }
    }
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    Edge edgeList[edges];
    for (int i = 0; i < edges; i++) {
        printf("Enter the details of edge %d (u v weight): ", i + 1);
        scanf("%d %d %d", &edgeList[i].u, &edgeList[i].v, &edgeList[i].weight);
    }

    int start;
    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    bellmanFord(vertices, edges, edgeList, start);

    return 0;
}
/* sample input
Enter the number of vertices: 5
Enter the number of edges: 8
Enter the details of edge 1 (u v weight): 0 1 -1
Enter the details of edge 2 (u v weight): 0 2 4
Enter the details of edge 3 (u v weight): 1 2 3
Enter the details of edge 4 (u v weight): 1 3 2
Enter the details of edge 5 (u v weight): 1 4 2
Enter the details of edge 6 (u v weight): 3 2 5
Enter the details of edge 7 (u v weight): 3 1 1
Enter the details of edge 8 (u v weight): 4 3 -3
Enter the starting vertex: 0

Vertex Distance from Source
0        0
1        -1
2        2
3        -2
4        1

*/

