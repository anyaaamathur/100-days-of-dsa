// Day 68 - Question 1: Topological Sort (Kahnâ€™s BFS Algorithm)

// Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

/* Node */
struct Node {
    int data;
    struct Node* next;
};

/* Queue */
int queue[MAX];
int front = 0, rear = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
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

/* Kahn's Algorithm */
void topoSort(int n, struct Node* adj[], int indegree[]) {

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    while (!isEmpty()) {

        int curr = dequeue();
        printf("%d ", curr);

        struct Node* temp = adj[curr];

        while (temp != NULL) {

            indegree[temp->data]--;

            if (indegree[temp->data] == 0) {
                enqueue(temp->data);
            }

            temp = temp->next;
        }
    }
}

/* Main */
int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    int indegree[n];

    for (int i = 0; i < n; i++)
        indegree[i] = 0;

    for (int i = 0; i < m; i++) {

        int u, v;
        scanf("%d %d", &u, &v);

        addEdge(adj, u, v);
        indegree[v]++;
    }

    topoSort(n, adj, indegree);

    return 0;
}