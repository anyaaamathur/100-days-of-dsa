// Day 37 - Question 1: Priority Queue Using Array
// Close
// Problem Statement:
// Implement a Priority Queue using an array. An element with smaller value has higher priority.

// Supported Operations:
// - insert x
// - delete
// - peek

// Input Format:
// - First line contains integer N
// - Next N lines contain operations

// Output Format:
// - Print the deleted or peeked element
// - Print -1 if the queue is empty

// Example:
// Input:
// 5
// insert 30
// insert 10
// insert 20
// delete
// peek

// Output:
// 10
// 20

#include <stdio.h>

#define MAX 100

int pq[MAX];
int size = 0;

// Insert in sorted order (min priority queue)
void insert(int x) {
    int i = size - 1;

    // shift elements to right
    while (i >= 0 && pq[i] > x) {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1] = x;
    size++;
}

// Delete highest priority (smallest element)
void deletePQ() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[0]);

    for (int i = 1; i < size; i++) {
        pq[i - 1] = pq[i];
    }

    size--;
}

// Peek highest priority element
void peek() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[0]);
}

int main() {
    int n;
    scanf("%d", &n);

    char op[10];
    int val;

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (op[0] == 'i') {   // insert
            scanf("%d", &val);
            insert(val);
        }
        else if (op[0] == 'd') {  // delete
            deletePQ();
        }
        else if (op[0] == 'p') {  // peek
            peek();
        }
    }

    return 0;
}