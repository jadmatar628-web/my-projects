#include "queue.h"
#include <stdlib.h>

int isEmpty(Queue *q)
{
    return q->size == 0;
}

int isFull(Queue *q)
{
    return q->size == q->capacity;
}

void resizeQueue(Queue *q)
{
    int newCapacity = q->capacity * 2;
    int *newArr = malloc(newCapacity * sizeof(int));

    int j = 0;
    for (int i = 0; i < q->size; i++)
    {
        newArr[i] = q->arr[(q->front + i) % q->capacity];
    }

    free(q->arr);
    q->arr = newArr;
    q->capacity = newCapacity;
    q->front = 0;
    q->rear = q->size - 1;
}

void enqueue(Queue *q, int value)
{
    if (isFull(q))
    {
        resizeQueue(q);
    }

    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = value;
    q->size++;
}

void dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        return;
    }

    q->front = (q->front + 1) % q->capacity;
    q->size--;

    if (q->size == 0)
    {
        q->front = 0;
        q->rear = -1;
    }
}

int peek(Queue *q)
{
    if (isEmpty(q))
    {
        return -1;
    }

    return q->arr[q->front];
}