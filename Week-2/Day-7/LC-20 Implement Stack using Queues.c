
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define Stack structure
typedef struct {
    Node* top;
} MyStack;

// Create a new stack
MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->top = NULL;
    return stack;
}

// Push operation
void myStackPush(MyStack* obj, int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = obj->top;
    obj->top = newNode;
}

// Pop operation
int myStackPop(MyStack* obj) {
    if (obj->top == NULL) return -1; // or handle underflow

    Node* temp = obj->top;
    int value = temp->data;
    obj->top = obj->top->next;
    free(temp);
    return value;
}

// Top operation
int myStackTop(MyStack* obj) {
    if (obj->top == NULL) return -1;
    return obj->top->data;
}

// Check if empty
bool myStackEmpty(MyStack* obj) {
    return obj->top == NULL;
}

// Free the stack
void myStackFree(MyStack* obj) {
    while (!myStackEmpty(obj)) {
        myStackPop(obj);
    }
    free(obj);
}
