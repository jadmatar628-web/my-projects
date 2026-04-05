/*
 * @lc app=leetcode id=950 lang=c
 *
 * [950] Reveal Cards In Increasing Order
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct Queue
{
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
}Queue;
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
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
#include<stdlib.h>
int* deckRevealedIncreasing(int* deck, int deckSize, int* returnSize) 
{
    qsort(deck,deckSize,sizeof(int),compare);
Queue *queue=malloc(sizeof(Queue));
queue->size=deckSize;
queue->front=0;
queue->rear=-1;
queue->capacity=deckSize;
queue->arr = malloc(deckSize * sizeof(int));
for(int i=0;i<deckSize;i++)
{
    queue->arr[i]=i;
}
int* Answer = malloc(deckSize * sizeof(int));
for(int i = 0; i < deckSize; i++)
{
    int revealIdx = peek(queue);
    dequeue(queue); 
    Answer[revealIdx] = deck[i];
    if (!isEmpty(queue)) {
        int skipIdx = peek(queue);
        dequeue(queue);
        enqueue(queue, skipIdx);
    }
}
*returnSize = deckSize;
return Answer;
}
// @lc code=end

