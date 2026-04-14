// Day 72 - Question 1: First Repeated Character
// Close
// Problem Statement
// Given a string s consisting of lowercase letters, find the first repeated character in the string. A character is considered repeated if it appears more than once, and among all such characters, the one whose second occurrence has the smallest index should be returned.

// Input Format
// A single string s.

// Output Format
// Print the first repeated character. If no character is repeated, print -1.

// Sample Input
// geeksforgeeks

// Sample Output
// e

#include <stdio.h>
#include <string.h>

int main() {

    char s[100005];
    scanf("%s", s);

    int first[26];

    for (int i = 0; i < 26; i++)
        first[i] = -1;

    int minIndex = 1000000000;
    char result = -1;

    int n = strlen(s);

    for (int i = 0; i < n; i++) {

        int idx = s[i] - 'a';

        if (first[idx] == -1) {
            first[idx] = i;
        }
        else {
            if (first[idx] < minIndex) {
                minIndex = first[idx];
                result = s[i];
            }
        }
    }

    if (result == -1)
        printf("-1");
    else
        printf("%c", result);

    return 0;
}