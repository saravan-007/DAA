
#include <stdio.h>

// Function to calculate the optimal cost
int knapsack(int weights[], int values[], int capacity, int n) {
    // Create a table to store results of subproblems
    int dp[n + 1][capacity + 1];

    // Initialize the table
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
        }
    }

    // Fill the table in a bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= capacity; j++) {
            if (weights[i - 1] <= j) {
                dp[i][j] = (values[i - 1] + dp[i - 1][j - weights[i - 1]] > dp[i - 1][j]) ? 
                    values[i - 1] + dp[i - 1][j - weights[i - 1]] : dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Return the optimal cost
    return dp[n][capacity];
}

int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    int weights[n], values[n];
    printf("Enter the weights and values of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &weights[i], &values[i]);
    }

    // Calculate the optimal cost
    int cost = knapsack(weights, values, capacity, n);

    printf("Optimal cost: %d\n", cost);

    return 0;
}


