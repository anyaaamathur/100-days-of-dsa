// Problem: Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.

// Input:
// - First line: integer n representing number of rows and columns
// - Next n lines: n integers each representing the matrix elements

// Output:
// - Print "Identity Matrix" if the matrix satisfies the condition
// - Otherwise, print "Not an Identity Matrix"

// Example:
// Input:
// 3
// 1 0 0
// 0 1 0
// 0 0 1

// Output:
// Identity Matrix

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n][n];

    // Input matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int flag = 1; // assume identity

    // Check condition
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            // diagonal elements must be 1
            if (i == j && a[i][j] != 1) {
                flag = 0;
            }

            // non-diagonal elements must be 0
            if (i != j && a[i][j] != 0) {
                flag = 0;
            }
        }
    }

    if (flag == 1) {
        printf("Identity Matrix\n");
    } else {
        printf("Not an Identity Matrix\n");
    }

    return 0;
}