// Day 34 - Question 1: Evaluate Postfix Expression
// Close
// Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

// Input:
// - Postfix expression with operands and operators

// Output:
// - Print the integer result

// Example:
// Input:
// 2 3 1 * + 9 -

// Output:
// -4

// Explanation:
// Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Stack node
struct Node {
    int data;
    struct Node* next;
};

// Push
void push(struct Node** top, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

// Pop
int pop(struct Node** top) {
    if (*top == NULL)
        return 0;  // safe fallback

    struct Node* temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

// Check operator
int isOperator(char* token) {
    return (strlen(token) == 1 &&
           (token[0] == '+' || token[0] == '-' ||
            token[0] == '*' || token[0] == '/'));
}

// Evaluate postfix
int evaluatePostfix(char* expr) {
    struct Node* stack = NULL;

    char* token = strtok(expr, " \n");  // FIX: handle newline

    while (token != NULL) {

        if (!isOperator(token)) {
            push(&stack, atoi(token));
        }
        else {
            int b = pop(&stack);
            int a = pop(&stack);

            switch (token[0]) {
                case '+': push(&stack, a + b); break;
                case '-': push(&stack, a - b); break;
                case '*': push(&stack, a * b); break;
                case '/': push(&stack, a / b); break;
            }
        }

        token = strtok(NULL, " \n");
    }

    return pop(&stack);
}

// Main
int main() {
    char expr[200];

    fgets(expr, sizeof(expr), stdin);

    int result = evaluatePostfix(expr);

    printf("%d", result);

    return 0;
}