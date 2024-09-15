#include <stdio.h> 
#include <stdlib.h> 
#define MAX 100 
// Structure to represent an edge 
typedef struct { 
int src, dest, weight; 
} Edge; 
// Structure to represent a subset for Union-Find 
typedef struct { 
int parent, rank; 
} Subset; 
// Function to compare two edges based on their weight 
int compareEdges(const void *a, const void *b) { 
Edge *edge1 = (Edge *)a; 
Edge *edge2 = (Edge *)b; 
return edge1->weight - edge2->weight; 
} 
 
// Function to find the parent of a node using path compression 
int find(Subset subsets[], int i) { 
    if (subsets[i].parent != i) { 
        subsets[i].parent = find(subsets, subsets[i].parent); 
    } 
    return subsets[i].parent; 
} 
 
// Function to perform union of two subsets 
void unionSubsets(Subset subsets[], int x, int y) { 
    int xroot = find(subsets, x); 
    int yroot = find(subsets, y); 
 
    if (subsets[xroot].rank < subsets[yroot].rank) { 
        subsets[xroot].parent = yroot; 
    } else if (subsets[xroot].rank > subsets[yroot].rank) { 
        subsets[yroot].parent = xroot; 
    } else { 
        subsets[yroot].parent = xroot; 
        subsets[xroot].rank++; 
    } 
} 
 
 
// Function to perform Kruskal's algorithm 
void kruskal(int vertices, Edge edges[], int e) { 
    Edge result[MAX]; 
    Subset subsets[vertices]; 
 
    // Sort edges by weight 
    qsort(edges, e, sizeof(Edge), compareEdges); 
 
    // Initialize subsets 
    for (int i = 0; i < vertices; i++) { 
        subsets[i].parent = i; 
        subsets[i].rank = 0; 
    } 
 
    int edgeIndex = 0; // Index used to store result edges 
    int i = 0; // Initial index of sorted edges 
 
    while (edgeIndex < vertices - 1 && i < e) { 
        Edge nextEdge = edges[i++]; 
 
        int x = find(subsets, nextEdge.src); 
        int y = find(subsets, nextEdge.dest); 
 
        // If including this edge does not form a cycle 
        if (x != y) { 
            result[edgeIndex++] = nextEdge; 
            unionSubsets(subsets, x, y); 
        } 
    } 
 
    // Print the resulting MST 
    printf("Edges in the Minimum Spanning Tree:\n"); 
    int minimumCost = 0; 
    for (int i = 0; i < edgeIndex; i++) { 
printf("%d -- %d == %d\n", result[i].src, result[i].dest, 
result[i].weight); 
minimumCost += result[i].weight; 
} 
printf("Minimum Cost: %d\n", minimumCost); 
} 
int main() { 
int vertices, edgesCount; 
// Input: Number of vertices and edges 
printf("Enter the number of vertices: "); 
scanf("%d", &vertices); 
printf("Enter the number of edges: "); 
scanf("%d", &edgesCount); 
Edge edges[edgesCount]; 
// Input: Edge details (source, destination, weight) 
printf("Enter the edges (source, destination, weight):\n"); 
for (int i = 0; i < edgesCount; i++) { 
printf("Edge %d - Source: ", i + 1); 
scanf("%d", &edges[i].src); 
printf("Edge %d - Destination: ", i + 1); 
scanf("%d", &edges[i].dest); 
printf("Edge %d - Weight: ", i + 1); 
scanf("%d", &edges[i].weight); 
} 
// Perform Kruskal's algorithm 
kruskal(vertices, edges, edgesCount); 
return 0; 
} 
