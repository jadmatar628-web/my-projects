#include <stdio.h>
#include <stdlib.h>
#include "STACK.H"

Stack* createStack(int capacity) {
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    if (!stack) return NULL;

    stack->data = (int*) malloc(sizeof(int) * capacity);
    if (!stack->data) {
        free(stack);
        return NULL;
    }

    stack->top = -1;
    stack->capacity = capacity;

    return stack;
}

void destroyStack(Stack *stack) {
    if (!stack) return;
    free(stack->data);
    free(stack);
}

bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

bool isFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

bool push(Stack *stack, int value) {
    if (isFull(stack))
        return false;

    stack->data[++stack->top] = value;
    return true;
}

bool pop(Stack *stack, int *poppedValue) {
    if (isEmpty(stack))
        return false;

    *poppedValue = stack->data[stack->top--];
    return true;
}

bool peek(Stack *stack, int *topValue) {
    if (isEmpty(stack))
        return false;

    *topValue = stack->data[stack->top];
    return true;
}