// Day 73 - Question 1: First Non-Repeating Character
// Close
// Problem Statement
// Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.

// Input Format
// A single string s.

// Output Format
// Print the first non-repeating character or '$' if none exists.

// Sample Input
// geeksforgeeks

// Sample Output
// f

// Explanation
// The character 'f' occurs only once in the string and appears before any other non-repeating character.

#include <stdio.h>
#include <string.h>

int main() {

    char s[100005];
    scanf("%s", s);

    int freq[26] = {0};

    int n = strlen(s);

    /* Step 1: frequency count */
    for (int i = 0; i < n; i++) {
        freq[s[i] - 'a']++;
    }

    /* Step 2: find first non-repeating */
    for (int i = 0; i < n; i++) {

        if (freq[s[i] - 'a'] == 1) {
            printf("%c", s[i]);
            return 0;
        }
    }

    /* If none found */
    printf("$");

    return 0;
}