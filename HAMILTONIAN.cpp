#include <stdio.h>
#include <stdbool.h>

#define V 5 // Number of vertices in the graph

// Function to check if the vertex v can be added at index pos in the Hamiltonian Cycle
bool isSafe(int graph[V][V], int path[], int pos, int v) {
    // Check if this vertex is an adjacent vertex of the previously added vertex.
    if (graph[path[pos - 1]][v] == 0) {
        return false;
    }
    
    // Check if the vertex has already been included.
    for (int i = 0; i < pos; i++) {
        if (path[i] == v) {
            return false;
        }
    }
    
    return true;
}

// Utility function to print the Hamiltonian Cycle
void printSolution(int path[]) {
    printf("Hamiltonian Cycle exists: ");
    for (int i = 0; i < V; i++) {
        printf("%d ", path[i]);
    }
    printf("%d\n", path[0]); // Print the starting vertex again to make the cycle
}

// Recursive function to solve the Hamiltonian Cycle problem
bool hamCycleUtil(int graph[V][V], int path[], int pos) {
    // Base case: If all vertices are included in the path
    if (pos == V) {
        // And if there is an edge from the last included vertex to the first vertex
        return graph[path[pos - 1]][path[0]] == 1;
    }
    
    // Try different vertices as the next candidate in the path
    for (int v = 1; v < V; v++) {
        if (isSafe(graph, path, pos, v)) {
            path[pos] = v;
            
            // Recur to construct the rest of the path
            if (hamCycleUtil(graph, path, pos + 1)) {
                return true;
            }
            
            // If adding vertex v doesn't lead to a solution, remove it
            path[pos] = -1;
        }
    }
    
    return false;
}

// Function to solve the Hamiltonian Cycle problem using Backtracking
void hamCycle(int graph[V][V]) {
    int path[V];
    
    // Initialize the path array
    for (int i = 0; i < V; i++) {
        path[i] = -1;
    }
    
    // Let the first vertex in the path be 0
    path[0] = 0;
    
    if (!hamCycleUtil(graph, path, 1)) {
        printf("No Hamiltonian Cycle found\n");
    } else {
        printSolution(path);
    }
}

int main() {
    int graph[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };
    
    hamCycle(graph);
    
    return 0;
}
