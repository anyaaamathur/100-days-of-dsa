// Day 32 - Question 1: Push and Pop in Stack
// Close
// Problem: Implement push and pop operations on a stack and verify stack operations.

// Input:
// - First line: integer n
// - Second line: n integers to push
// - Third line: integer m (number of pops)

// Output:
// - Print remaining stack elements from top to bottom

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 30 20 10

#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Push
void push(int val) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = val;
}

// Pop
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    top--;
}

// Display from top to bottom
void display() {
    if (top == -1) {
        printf("Stack is empty");
        return;
    }

    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
}

// Main
int main() {
    int n, m, val;

    scanf("%d", &n);

    // Push n elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        push(val);
    }

    // Number of pops
    scanf("%d", &m);

    // Perform pops
    for (int i = 0; i < m; i++) {
        pop();
    }

    // Display remaining stack
    display();

    return 0;
}