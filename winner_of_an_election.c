// Day 74 - Question 1: Winner of an Election
// Close
// Problem Statement
// Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

// Input Format
// First line contains an integer n representing number of votes.
// Second line contains n space-separated strings representing candidate names.

// Output Format
// Print the name of the winning candidate followed by the number of votes received.

// Sample Input
// 13
// john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

// Sample Output
// john 4

// Explanation
// Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner.

#include <stdio.h>
#include <string.h>

int main() {

    int n;
    scanf("%d", &n);

    char names[n][50];
    int freq[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
        freq[i] = 0;
    }

    /* Count frequency */
    for (int i = 0; i < n; i++) {

        if (freq[i] == -1) continue;

        int count = 1;

        for (int j = i + 1; j < n; j++) {

            if (strcmp(names[i], names[j]) == 0) {
                count++;
                freq[j] = -1; // mark visited
            }
        }

        freq[i] = count;
    }

    /* Find winner */
    int maxVotes = -1;
    char winner[50] = "";

    for (int i = 0; i < n; i++) {

        if (freq[i] == -1) continue;

        if (freq[i] > maxVotes) {
            maxVotes = freq[i];
            strcpy(winner, names[i]);
        }
        else if (freq[i] == maxVotes) {
            if (strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }

    printf("%s %d", winner, maxVotes);

    return 0;
}