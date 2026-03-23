#include<stdio.h>
#include<stdlib.h>

typedef struct Stack
{
    int *arr;
    int top;
    int capacity;
}Stack;

typedef struct Queue
{
    Stack *input;
    Stack *output;
}Queue;

Stack * createStack(int capacity)
{
    Stack *s;
    s=malloc(sizeof(Stack));
    s->top=-1;
    s->capacity=capacity;
    s->arr=malloc(sizeof(int)*capacity);
    return s;
}

int isEmpty(Stack *s)
{
    return(s->top==-1)?1:0;
}
int isFull(Stack *s)
{
    return(s->top==s->capacity-1)?1:0;
}
void push(Stack *s, int x)
{
    if(isFull(s))
    {
        s->capacity*=2;
        s->arr=realloc(s->arr,s->capacity*sizeof(int));
    }
      s->top++;
    s->arr[s->top]=x;
}

int pop(Stack *s)
{
    if(isEmpty(s))
  {  printf("EMPTY");
    return -1;}
    int val=s->arr[s->top];
    s->top--;
    return val;
}

void enqueue(int x, Queue* q)
{
    push(q->input,x);
}
int dequeue(Queue *q)
{
    if(isEmpty(q->input) && isEmpty(q->output)) return -1;
    if(isEmpty(q->output))
    {
        while(!isEmpty(q->input))
        {
            push(q->output,pop(q->input));
        }
    }
    if(!isEmpty(q->output))
    {  int val=pop(q->output);
      return val;}
      return -1;
}