// Day 66 - Question 1: Cycle Detection in Directed Graph

// Problem: Detect cycle in directed graph using DFS and recursion stack.

// Output:
// - YES if cycle exists

#include <stdio.h>
#include <stdlib.h>

/* Node */
struct Node {
    int data;
    struct Node* next;
};

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

/* DFS cycle detection */
int dfs(int v, struct Node* adj[], int visited[], int recStack[]) {

    visited[v] = 1;
    recStack[v] = 1;

    struct Node* temp = adj[v];

    while (temp != NULL) {

        int neigh = temp->data;

        if (!visited[neigh]) {
            if (dfs(neigh, adj, visited, recStack))
                return 1;
        }
        else if (recStack[neigh]) {
            return 1; // cycle found
        }

        temp = temp->next;
    }

    recStack[v] = 0; // backtrack
    return 0;
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

    int visited[n], recStack[n];

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    int cycle = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, recStack)) {
                cycle = 1;
                break;
            }
        }
    }

    if (cycle)
        printf("YES");
    else
        printf("NO");

    return 0;
}