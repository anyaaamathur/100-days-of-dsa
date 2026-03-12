// Day 39 - Question 1: Min Heap Implementation
// Close
// Problem Statement:
// Implement a Min Heap using an array where the smallest element is always at the root.

// Supported Operations:
// - insert x
// - extractMin
// - peek

// Input Format:
// - First line contains integer N
// - Next N lines contain heap operations

// Output Format:
// - Print results of extractMin and peek
// - Print -1 if operation cannot be performed

// Example:
// Input:
// 6
// insert 40
// insert 10
// insert 30
// peek
// extractMin
// peek

// Output:
// 10
// 10
// 30

#include <stdio.h>

#define MAX 1000

int heap[MAX];
int size = 0;

/* Swap */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Heapify Up */
void heapUp(int i) {
    while (i > 0 && heap[i] < heap[(i - 1) / 2]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

/* Heapify Down */
void heapDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapDown(smallest);
    }
}

/* Insert */
void insert(int x) {
    heap[size] = x;
    heapUp(size);
    size++;
}

/* Peek */
void peek() {
    if (size == 0) {
        printf("-1\n");
        return;
    }
    printf("%d\n", heap[0]);
}

/* Extract Min */
void extractMin() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    printf("%d\n", heap[0]);

    heap[0] = heap[size - 1];
    size--;

    heapDown(0);
}

/* Main */
int main() {
    int n;
    scanf("%d", &n);

    char op[20];
    int val;

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (op[0] == 'i') {
            scanf("%d", &val);
            insert(val);
        }
        else if (op[0] == 'p' && op[1] == 'e') {
            peek();
        }
        else if (op[0] == 'e') {
            extractMin();
        }
    }

    return 0;
}