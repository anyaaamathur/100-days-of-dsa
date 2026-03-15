// Day 42 - Question 1: Reverse a Queue Using Stack
// Close
// Problem Statement:
// Given a queue of integers, reverse the queue using a stack.

// Input Format:
// - First line contains integer N
// - Second line contains N space-separated integers

// Output Format:
// - Print the reversed queue

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 50 40 30 20 10

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

/* Queue */
int queue[MAX];
int front = 0, rear = -1;

/* Stack */
int stack[MAX];
int top = -1;

/* Queue operations */
void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

/* Stack operations */
void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

/* Check empty queue */
int isQueueEmpty(int n) {
    return front > rear;
}

/* Main */
int main() {

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(x);
    }

    /* Step 1: Queue → Stack */
    while (front <= rear) {
        push(dequeue());
    }

    /* Reset queue pointers */
    front = 0;
    rear = -1;

    /* Step 2: Stack → Queue */
    while (top != -1) {
        enqueue(pop());
    }

    /* Output reversed queue */
    for (int i = 0; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}