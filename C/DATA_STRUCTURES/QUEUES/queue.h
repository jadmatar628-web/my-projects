#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue
{
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
}Queue;

void enqueue(Queue *q, int value);
void dequeue(Queue *q);
int peek(Queue *q);
int isEmpty(Queue *q);
int isFull(Queue *q);
#endif