// Day 71 - Question 1: Hash Table Using Quadratic Probing

// Problem Statement
// Implement a hash table using quadratic probing with formula:

// h(k, i) = (h(k) + i*i) % m

// Input Format
// Same as previous.

// Output Format
// Result of SEARCH operations.

// Sample Input
// 7
// 4
// INSERT 49
// INSERT 56
// SEARCH 49
// SEARCH 15

// Sample Output
// FOUND
// NOT FOUND

// Explanation
// Collisions resolved using i² jumps.

#include <stdio.h>

#define EMPTY -1
#define DELETED -2

int table[1000];
int m;

/* Hash function */
int hash(int key) {
    return key % m;
}

/* Insert using quadratic probing */
void insert(int key) {

    int h = hash(key);

    for (int i = 0; i < m; i++) {

        int idx = (h + i * i) % m;

        if (table[idx] == EMPTY || table[idx] == DELETED) {
            table[idx] = key;
            return;
        }
    }
}

/* Search using quadratic probing */
void search(int key) {

    int h = hash(key);

    for (int i = 0; i < m; i++) {

        int idx = (h + i * i) % m;

        if (table[idx] == EMPTY) {
            printf("NOT FOUND\n");
            return;
        }

        if (table[idx] == key) {
            printf("FOUND\n");
            return;
        }
    }

    printf("NOT FOUND\n");
}

/* Main */
int main() {

    int n;
    scanf("%d", &m);   // table size
    scanf("%d", &n);   // number of operations

    for (int i = 0; i < m; i++)
        table[i] = EMPTY;

    for (int i = 0; i < n; i++) {

        char op[10];
        int key;

        scanf("%s %d", op, &key);

        if (op[0] == 'I') {
            insert(key);
        }
        else if (op[0] == 'S') {
            search(key);
        }
    }

    return 0;
}