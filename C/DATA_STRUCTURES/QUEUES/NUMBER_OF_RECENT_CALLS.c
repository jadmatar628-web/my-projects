#include"queue.h"
#include<stdlib.h>
Queue *define()
{
    Queue *q=malloc(sizeof(Queue));
    q->size=0;
    q->front=0;
    q->rear=-1;
    q->capacity=10000;
    q->arr=malloc(q->capacity*sizeof(int));
    return q;
}
int ping (int t,Queue *q)
{
    if(!(isFull(q)))
    {
        enqueue(q,t);
    }
    else
    {
        return 1;
    }
    int threshold=t-3000;
    while(!(isEmpty(q)) && q->arr[q->front]<threshold)
    {
        dequeue(q);
    }
    return q->size;
}