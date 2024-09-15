#include <stdio.h>
#include <stdbool.h>

#define V 4  // Number of vertices in the graph

// Function to check if the current color assignment is valid for the vertex v
bool isSafe(int v, bool graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c) {
            return false;  // If any adjacent vertex has the same color, return false
        }
    }
    return true;
}

// Recursive utility function to solve the graph coloring problem
bool graphColoringUtil(bool graph[V][V], int m, int color[], int v) {
    // If all vertices are assigned a color, return true
    if (v == V) {
        return true;
    }

    // Try assigning different colors (from 1 to m) to the vertex v
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;  // Assign color c to vertex v

            // Recursively assign colors to the rest of the vertices
            if (graphColoringUtil(graph, m, color, v + 1)) {
                return true;
            }

            color[v] = 0;  // Backtrack if no solution is found
        }
    }

    return false;  // If no valid color assignment is found, return false
}

// Function to solve the graph coloring problem using backtracking
bool graphColoring(bool graph[V][V], int m) {
    int color[V] = {0};  // Initialize all vertices with no color (0)

    // Start from the first vertex (v = 0) and try to solve the problem
    if (!graphColoringUtil(graph, m, color, 0)) {
        printf("Solution does not exist.\n");
        return false;
    }

    // Print the color assignment for each vertex
    printf("Solution exists: Following are the assigned colors:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d --> Color %d\n", i, color[i]);
    }

    return true;
}

int main() {
    // Example adjacency matrix for a graph
    bool graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int m = 3;  // Number of colors

    // Solve the graph coloring problem
    graphColoring(graph, m);

    return 0;
}

