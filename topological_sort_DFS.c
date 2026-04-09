// Day 67 - Question 1: Topological Sort (DFS)

// Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

/* Node */
struct Node {
    int data;
    struct Node* next;
};

/* Stack */
int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

/* Create node */
struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->next = NULL;
    return node;
}

/* Add directed edge */
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

/* DFS */
void dfs(int v, struct Node* adj[], int visited[]) {

    visited[v] = 1;

    struct Node* temp = adj[v];

    while (temp != NULL) {

        if (!visited[temp->data]) {
            dfs(temp->data, adj, visited);
        }

        temp = temp->next;
    }

    push(v); // store after visiting all neighbors
}

/* Main */
int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    int visited[n];

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    /* run DFS for all nodes */
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited);
        }
    }

    /* print stack (topological order) */
    while (top != -1) {
        printf("%d ", pop());
    }

    return 0;
}