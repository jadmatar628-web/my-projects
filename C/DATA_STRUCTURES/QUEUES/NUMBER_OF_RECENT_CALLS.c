#include"queue.h"
#include<stdlib.h>

Queue * create(int capacity)
{
    Queue *q=malloc(sizeof(Queue));
    q->arr=malloc(sizeof(capacity));
    q->capacity=capacity;
    q->front=0;
    q->rear=-1;
    return q;
}

int NumberOfRecenetCalls(Queue *q, int t)
{
    enqueue(q,t);
    while(!isEmpty(q) && q->arr[q->front]<t-3000)
    {
        dequeue(q);
    }
    return q->size; 
}