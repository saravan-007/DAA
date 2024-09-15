#include <stdio.h> 
// Function to compute binomial coefficient C(n, k) 
int binomialCoefficient(int n, int k) { 
// Create a table to store binomial coefficients 
int C[n + 1][k + 1]; 
// Initialize the table 
for (int i = 0; i <= n; i++) { 
for (int j = 0; j <= (i < k ? i : k); j++) { 
if (j == 0 || j == i) { 
C[i][j] = 1;  // Base cases 
} else { 
C[i][j] = C[i - 1][j - 1] + C[i - 1][j];  // Recursive relation 
} 
} 
} 
return C[n][k]; 
} 
int main() { 
int n, k; 
// Input: values for n and k 
printf("Enter the value of n: "); 
scanf("%d", &n); 
printf("Enter the value of k: "); 
scanf("%d", &k); 
// Compute and print the binomial coefficient 
if (k > n || k < 0) { 
printf("Invalid values for n and k.\n"); 
} else { 
printf("C(%d, %d) = %d\n", n, k, binomialCoefficient(n, k)); 
} 
return 0; 
} 
