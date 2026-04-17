// Day 75 - Question 1: Largest Subarray with Zero Sum
// Close
// Problem Statement
// Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

// Input Format
// An integer array arr[].

// Output Format
// Print the length of the longest subarray with sum equal to zero.

// Sample Input
// 15 -2 2 -8 1 7 10 23

// Sample Output
// 5

// Explanation
// The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

/* Simple hash using arrays (works for typical constraints) */
int hash[MAX * 2];
int offset = MAX;

int main() {

    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < MAX * 2; i++)
        hash[i] = -2;

    int sum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++) {

        sum += arr[i];

        if (sum == 0) {
            if (i + 1 > maxLen)
                maxLen = i + 1;
        }

        if (hash[sum + offset] != -2) {
            int len = i - hash[sum + offset];
            if (len > maxLen)
                maxLen = len;
        }
        else {
            hash[sum + offset] = i;
        }
    }

    printf("%d", maxLen);

    return 0;
}