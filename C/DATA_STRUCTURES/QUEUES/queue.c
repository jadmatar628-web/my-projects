#include"queue.h"

int isEmpty(Queue *q)
{
    return (q->size==0);
}

int isFull(Queue *q)
{
    return (q->capacity==q->size);
}

void enqueue(Queue *q, int value)
{
    if(isFull(q))
    {
        return ;
    }
    q->rear=(q->rear +1) % q->capacity;
    q->arr[q->rear]=value;
    q->size++;
}
void dequeue(Queue *q)
{
    if(isEmpty(q))
    {
        return ;
    }
    q->front=(q->front +1)%q->capacity;
    q->size--;
}
int peek(Queue *q)
{
    if(isEmpty(q))
    return -1;
    return q->arr[q->front];
}