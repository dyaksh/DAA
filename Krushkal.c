#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Function to create a graph with user input
struct Edge* createGraph(int numVertices, int numEdges) {
    struct Edge* graph = (struct Edge*)malloc(numEdges * sizeof(struct Edge));

    // Take input for each edge
    printf("Enter source, destination, and weight of each edge:\n");
    for (int i = 0; i < numEdges; i++) {
        printf("Edge %d:\n", i + 1);
        printf("Source: ");
        scanf("%d", &graph[i].src);
        printf("Destination: ");
        scanf("%d", &graph[i].dest);
        printf("Weight: ");
        scanf("%d", &graph[i].weight);
    }

    return graph;
}

// Function to find the set of an element using path compression
int find(struct Subset subsets[], int i) {
    // Find root and make root as parent of i
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// Function to perform union of two sets using union by rank
void unionSets(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    // Attach smaller rank tree under root of high rank tree
    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        // If ranks are the same, make one as root and increment its rank
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Comparator function to sort edges by weight
int compare(const void* a, const void* b) {
    struct Edge* edge1 = (struct Edge*)a;
    struct Edge* edge2 = (struct Edge*)b;
    return edge1->weight - edge2->weight;
}

// Function to find the minimum spanning tree using Kruskal's algorithm
void kruskalMST(struct Edge* graph, int numVertices, int numEdges) {
    struct Edge* resultMST = (struct Edge*)malloc((numVertices - 1) * sizeof(struct Edge)); // Array to store the result MST
    int e = 0; // Index variable for resultMST
    int i = 0; // Index variable for sorted edges array

    // Sort all the edges in non-decreasing order of their weight
    qsort(graph, numEdges, sizeof(struct Edge), compare);

    // Allocate memory for subsets
    struct Subset* subsets = (struct Subset*)malloc(numVertices * sizeof(struct Subset));

    // Initialize each subset with its parent and rank
    for (int v = 0; v < numVertices; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Keep adding edges to result MST until there are V-1 edges
    while (e < numVertices - 1 && i < numEdges) {
        struct Edge nextEdge = graph[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        // If including this edge doesn't cause a cycle, include it in the result MST
        if (x != y) {
            resultMST[e++] = nextEdge;
            unionSets(subsets, x, y);
        }
    }

    // Print the result MST
    printf("Edges in the Minimum Spanning Tree:\n");
    for (int j = 0; j < e; j++) {
        printf("(%d, %d) -> %d\n", resultMST[j].src, resultMST[j].dest, resultMST[j].weight);
    }

    free(resultMST);
    free(subsets);
}

int main() {
    int numVertices, numEdges;

    // Take input for the number of vertices and edges in the graph
    printf("Enter the number of vertices and edges in the graph: ");
    scanf("%d %d", &numVertices, &numEdges);

    // Create the graph with user input
    struct Edge* graph = createGraph(numVertices, numEdges);

    // Find the Minimum Spanning Tree (MST) using Kruskal's algorithm
    kruskalMST(graph, numVertices, numEdges);

    free(graph); // Free dynamically allocated memory

    return 0;
}
/* sample input
Enter the number of vertices and edges in the graph: 5 7
Enter source, destination, and weight of each edge:
Edge 1:
Source: 0
Destination: 1
Weight: 2
Edge 2:
Source: 0
Destination: 3
Weight: 6
Edge 3:
Source: 1
Destination: 2
Weight: 3
Edge 4:
Source: 1
Destination: 3
Weight: 8
Edge 5:
Source: 1
Destination: 4
Weight: 5
Edge 6:
Source: 2
Destination: 4
Weight: 7
Edge 7:
Source: 3
Destination: 4
Weight: 9

sample output:
Edges in the Minimum Spanning Tree:
(0, 1) -> 2
(1, 2) -> 3
(0, 3) -> 6
(1, 4) -> 5


*/



///another program
/*

#include <stdio.h>
#include<limits.h>

int par[10];
int uni(int i,int j)
{
    if(i!=j)
    {
        par[j]=i;
        return 1;
    }
    return 0;
}
int find(int i)
{
    while(par[i])
    i=par[i];
    return i;
}
void main()
{
    int graph[5][5]={{0,1,7,10,5},
                    {1,0,3,0,0},
                    {7,3,0,4,0},
                    {10,0,4,0,2},
                    {5,0,0,2,0}};
    int min=INT_MAX,minCost=0,ne=0,a,u,b,v,i,j,n=5;
    while(ne<n-1)
    {
        min = INT_MAX;
        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                if(graph[i][j]<min && graph[i][j]!=0)
                {
                    min=graph[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        u=find(u);
        v=find(v);
        if(uni(u,v))
        {
            printf("Edge %d:(%d %d) cost:%d\n",++ne,a,b,min);
            minCost+=min;
        }
        graph[a][b]=graph[b][a]=0;
    }
    printf("Minimum cost:%d\n",minCost);
}
*/
