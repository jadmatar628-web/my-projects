#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct {
    int *data;
    int top;
    int capacity;
} Stack;

// Create stack with given capacity
Stack* createStack(int capacity);

// Free stack memory
void destroyStack(Stack *stack);

// Push element onto stack
bool push(Stack *stack, int value);

// Pop element from stack
bool pop(Stack *stack, int *poppedValue);

// Peek top element
bool peek(Stack *stack, int *topValue);

// Check if empty
bool isEmpty(Stack *stack);

// Check if full
bool isFull(Stack *stack);

#endif