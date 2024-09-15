#include <stdio.h> 
#define MAX 20 
 
// Function to print a subset 
void printSubset(int subset[], int size) { 
    printf("{ "); 
    for (int i = 0; i < size; i++) { 
        printf("%d ", subset[i]); 
    } 
    printf("}\n"); 
} 
 
// Recursive function to find subsets that sum up to the target 
void findSubsets(int arr[], int n, int index, int target, int currentSum, 
int subset[], int subsetSize) { 
    // If we have reached the target sum, print the subset 
    if (currentSum == target) { 
        printSubset(subset, subsetSize); 
        return; 
    } 
     
    // If we have processed all elements or exceeded the target sum, return 
    if (index >= n || currentSum > target) { 
        return; 
    } 
 
    // Include the current element in the subset 
    subset[subsetSize] = arr[index]; 
    findSubsets(arr, n, index + 1, target, currentSum + arr[index], subset, 
subsetSize + 1); 
 
    // Exclude the current element from the subset 
    findSubsets(arr, n, index + 1, target, currentSum, subset, subsetSize); 
} 
 
int main() { 
    int arr[MAX], n, target; 
    int subset[MAX]; 
 
    // Input: number of elements 
    printf("Enter the number of elements: "); 
    scanf("%d", &n); 
 
    // Input: elements of the set 
    printf("Enter the elements:\n"); 
    for (int i = 0; i < n; i++) { 
        scanf("%d", &arr[i]); 
    } 
 
    // Input: target sum 
    printf("Enter the target sum: "); 
    scanf("%d", &target); 
 
    // Find and print all subsets that sum up to the target 
    printf("Subsets that sum up to %d are:\n", target); 
    findSubsets(arr, n, 0, target, 0, subset, 0); 
 
    return 0; 
}
