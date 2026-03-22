#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct Queue
{
    int *arr;
    int size, capacity, front, rear;
}Queue;

typedef struct Min
{
    Queue *main;
    Queue *helper;
}Min;

Queue *create (int capacity)
{
    Queue *q=malloc(sizeof(Queue));
    q->arr=malloc(sizeof(int) * capacity);
    q->capacity=capacity;
    q->front=0;
    q->rear=-1;
    q->size=0;
    return q;
}

int isEmpty(Queue *q)
{
    return (q->size==0) ? 1:0;
}

int isFull(Queue *t)
{
    return (t->capacity==t->size)?1:0;
}
void dequeu(Min *main)
{
    if(isEmpty(main->main)) return;
    if(main->main->arr[main->main->front]==main->helper->arr[main->helper->front])
    {main->main->front++;
    main->main->size--;
    main->helper->front++;
    main->helper->size--;
    return;}
    main->main->front++;
    main->main->size--;
    return;
}
void removeRear(Queue *q)
{
    if (isEmpty(q)) return;
    q->rear--;
    q->size--;
}
void Enqueu(Queue *main, Queue *helper, int x)
{
    if(isFull(main))
    {
        main->capacity*=2;
        helper->capacity*=2;
        main->arr=realloc(main->arr,sizeof(int)*main->capacity);
        helper->arr=realloc(helper->arr,sizeof(int)*helper->capacity);
        main->rear++;
        main->arr[main->rear]=x;
        main->size++;
        while(!isEmpty(helper) && helper->arr[helper->rear]>x)
        {
            removeRear(helper);
        }
        helper->rear++;
        helper->arr[helper->rear]=x;
        helper->size++;
        return;
    }
        main->rear++;
        main->arr[main->rear]=x;
        main->size++;
        while(!isEmpty(helper) && helper->arr[helper->rear]>x)
        {
            removeRear(helper);
        }
        helper->rear++;
        helper->arr[helper->rear]=x;
        helper->size++;
        return;
}

int getmin(Queue *helper)
{   if(isEmpty(helper)) return INT_MIN;
    return helper->arr[helper->front];
}

int main()
{
    int capacity;
    printf("Enter the capacity of your queue: ");
    scanf("%d", &capacity);

    // Create MinQueue
    Min *q = malloc(sizeof(Min));
    q->main = create(capacity);
    q->helper = create(capacity);

    int n;
    printf("How many elements to insert? ");
    scanf("%d", &n);

    // Enqueue elements properly
    for (int i = 0; i < n; i++)
    {
        int x;
        printf("Enter element #%d: ", i + 1);
        scanf("%d", &x);

        Enqueu(q->main, q->helper, x);
    }

    // Initial minimum
    printf("\nCurrent Min: %d\n", getmin(q->helper));

    // Test dequeue operations
    int d;
    printf("How many dequeues to perform? ");
    scanf("%d", &d);

    for (int i = 0; i < d; i++)
    {
        dequeu(q);

        if (!isEmpty(q->main))
            printf("Min after dequeue %d: %d\n", i + 1, getmin(q->helper));
        else
            printf("Queue is now empty\n");
    }

    return 0;
}



