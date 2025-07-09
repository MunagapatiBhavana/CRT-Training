### 📚Day 7 – Stack Data Structure

Welcome to Day 7 of my CRT Training!
Today we focused on the Stack data structure, a fundamental concept in data structures and algorithms.

## 📌 What is a Stack?
A Stack is a abstract linear data structure that follows the LIFO principle — Last In, First Out.
This means the last element added to the stack will be the first one to be removed.

# Key Stack Operations:

| Operation   | Description                                             |
| ----------- | ------------------------------------------------------- |
| `push()`    | Adds an element to the top of the stack                 |
| `pop()`     | Removes the top element from the stack                  |
| `peek()`    | Returns the top element without removing it             |
| `isEmpty()` | Checks if the stack is empty                            |
| `isFull()`  | Checks if the stack is full (in static implementations) |

## 🧠 Why Use Stacks?
Function call management (call stack)

Expression evaluation and syntax parsing

Undo operations in editors

Backtracking problems (mazes, puzzles)

## ⚙️ Stack Implementation in C (Using Arrays)

#include <stdio.h>

#define SIZE 100

int stack[SIZE];

int top = -1;

// Push operation
void push(int value) {

    if (top == SIZE - 1)
        printf("Stack Overflow\n");
    else {
        top++;
        stack[top] = value;
        printf("%d pushed to stack\n", value);
    }
}

// Pop operation
void pop() {

    if (top == -1)
        printf("Stack Underflow\n");
    else {
        printf("%d popped from stack\n", stack[top]);
        top--;
    }
}

// Display stack
void display() {

    if (top == -1)
        printf("Stack is empty\n");
    else {
        printf("Stack elements are: ");
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main() {

    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
    return 0;
}

## 🔧 Stack Using Linked List

#include <stdio.h>

#include <stdlib.h>

// Structure for a stack node
struct Node {

    int data;
    struct Node* next;
};

// Push operation
void push(struct Node** top, int value) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed to stack\n", value);
}

// Pop operation
int pop(struct Node** top) {

    if (*top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = *top;
    int popped = temp->data;
    *top = (*top)->next;
    free(temp);
    return popped;
}

// Peek operation
int peek(struct Node* top) {

    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

// Display stack
void display(struct Node* top) {

    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

// Driver code
int main() {

    struct Node* top = NULL;

    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    display(top);

    printf("Top element is %d\n", peek(top));
    printf("%d popped from stack\n", pop(&top));
    display(top);

    return 0;
}

## 🌐 Real-Time Example of Stack

🔁 Undo Feature in Text Editors

Scenario: In applications like Notepad, MS Word, or VS Code, when you type something and press Ctrl + Z, the last action is undone.

How Stack Works:

Every operation (typing, deleting, formatting) is pushed onto a stack.

When you press Undo, the last operation is popped and reversed.

| Use Case                    | Description                                     |
| --------------------------- | ----------------------------------------------- |
| **Browser History**         | Navigating back is done by popping the last URL |
| **Recursion**               | System stack stores function calls              |
| **Expression Evaluation**   | Infix → Postfix conversion                      |
| **Backtracking Algorithms** | E.g., Maze solving, Sudoku                      |

## 🏁 Conclusion

A stack is a powerful yet simple data structure.

Understanding push() and pop() lays the groundwork for recursion, parsing, and backtracking.

Make sure to also explore linked list-based stack implementations for dynamic memory handling.
