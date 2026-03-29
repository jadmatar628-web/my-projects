#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct Stack
{
    int *arr;
    int top;
    int capacity;
}Stack;

// Create stack with given capacity
Stack* createStack(int capacity);

// Push element onto stack
void push(Stack *stack, int value);

// Pop element from stack
int pop(Stack *stack);

// Peek top element
int peek(Stack *stack);

// Check if empty
int isEmpty(Stack *stack);

// Check if full
int isFull(Stack *stack);

#endif