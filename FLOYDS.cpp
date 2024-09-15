#include <stdio.h> 
#include <limits.h> 
#define MAX 100 
#define INF INT_MAX 
// Function to perform Floyd-Warshall algorithm 
void floydWarshall(int graph[MAX][MAX], int n) { 
int dist[MAX][MAX]; 
// Initialize distance matrix 
for (int i = 0; i < n; i++) { 
for (int j = 0; j < n; j++) { 
if (i == j) { 
dist[i][j] = 0; 
} else if (graph[i][j] != 0) { 
dist[i][j] = graph[i][j]; 
} else { 
dist[i][j] = INF; 
} 
} 
} 
// Floyd-Warshall algorithm 
for (int k = 0; k < n; k++) { 
for (int i = 0; i < n; i++) { 
for (int j = 0; j < n; j++) { 
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > 
dist[i][k] + dist[k][j]) { 
                    dist[i][j] = dist[i][k] + dist[k][j]; 
                } 
            } 
        } 
    } 
     
    // Print the distance matrix 
    printf("Shortest distances between every pair of vertices:\n"); 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) { 
            if (dist[i][j] == INF) { 
                printf("INF\t"); 
            } else { 
                printf("%d\t", dist[i][j]); 
            } 
        } 
        printf("\n"); 
    } 
} 
 
int main() { 
    int n; 
     
    // Input: number of vertices 
    printf("Enter the number of vertices: "); 
    scanf("%d", &n); 
 
    int graph[MAX][MAX]; 
     
    // Input: adjacency matrix 
    printf("Enter the adjacency matrix:\n"); 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) { 
            scanf("%d", &graph[i][j]); 
            if (i != j && graph[i][j] == 0) { 
                graph[i][j] = INF; // Treat zero as infinity for nondiagonal elements 
            } 
        } 
    } 
 
    // Perform Floyd-Warshall algorithm 
    floydWarshall(graph, n); 
 
    return 0; 
}
