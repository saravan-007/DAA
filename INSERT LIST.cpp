

#include <stdio.h>

// Function to insert an element at a specific position
void insertElement(int arr[], int *size, int capacity, int position, int element) {
    if (*size < capacity) {
        if (position >= 0 && position <= *size) {
            // Shift elements to make space for the new element
            for (int i = *size; i > position; i--) {
                arr[i] = arr[i - 1];
            }
            arr[position] = element;
            (*size)++;
            printf("Element %d inserted at position %d.\n", element, position);
        } else {
            printf("Invalid position.\n");
        }
    } else {
        printf("Array is full. Cannot insert more elements.\n");
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int capacity = 10;
    int arr[capacity];
    int size = 0;

    // Insert elements at specific positions
    insertElement(arr, &size, capacity, 0, 10);
    insertElement(arr, &size, capacity, 1, 20);
    insertElement(arr, &size, capacity, 2, 30);
    insertElement(arr, &size, capacity, 0, 5);  // Insert at position 0

    // Print the array
    printArray(arr, size);

    return 0;
}





