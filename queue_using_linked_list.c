// Day 41 - Question 1: Queue Using Linked List
// Close
// Problem Statement:
// Implement a Queue using a linked list supporting enqueue and dequeue operations.

// Input Format:
// - First line contains integer N
// - Next N lines contain queue operations

// Output Format:
// - Print dequeued elements
// - Print -1 if dequeue is attempted on an empty queue

#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct Node {
    int data;
    struct Node* next;
};

/* Queue structure */
struct Queue {
    struct Node *front, *rear;
};

/* Create new node */
struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    return temp;
}

/* Create queue */
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

/* Enqueue */
void enqueue(struct Queue* q, int val) {
    struct Node* temp = newNode(val);

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

/* Dequeue */
void dequeue(struct Queue* q) {

    if (q->front == NULL) {
        printf("-1\n");
        return;
    }

    struct Node* temp = q->front;
    printf("%d\n", temp->data);

    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}

/* Main */
int main() {

    int n;
    scanf("%d", &n);

    struct Queue* q = createQueue();

    for (int i = 0; i < n; i++) {

        int op;
        scanf("%d", &op);

        if (op == 1) {
            int val;
            scanf("%d", &val);
            enqueue(q, val);
        }
        else if (op == 2) {
            dequeue(q);
        }
    }

    return 0;
}