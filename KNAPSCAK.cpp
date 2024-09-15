#include <stdio.h>

// Structure to represent an item
typedef struct {
    int weight;
    int value;
} Item;

// Function to solve the Knapsack problem using greedy technique
void knapsack(int capacity, Item items[], int n) {
    // Sort items based on value-to-weight ratio in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((double)items[i].value / items[i].weight < (double)items[j].value / items[j].weight) {
                // Swap items[i] and items[j]
                Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    int totalValue = 0;
    printf("Selected items:\n");
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= capacity) {
            capacity -= items[i].weight;
            totalValue += items[i].value;
            printf("Item %d: Weight = %d, Value = %d\n", i + 1, items[i].weight, items[i].value);
        }
    }

    printf("Total value: %d\n", totalValue);
}

int main() {
    int capacity = 10; // Knapsack capacity
    Item items[] = {
        {2, 10}, // Item 1: Weight = 2, Value = 10
        {3, 20}, // Item 2: Weight = 3, Value = 20
        {1, 5},  // Item 3: Weight = 1, Value = 5
        {4, 30}, // Item 4: Weight = 4, Value = 30
        {2, 15}  // Item 5: Weight = 2, Value = 15
    };
    int n = sizeof(items) / sizeof(items[0]);

    knapsack(capacity, items, n);

    return 0;
}
