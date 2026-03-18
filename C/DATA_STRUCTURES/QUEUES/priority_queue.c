#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * DATA STRUCTURE DEFINITIONS
 */

// Represents a single task with an ID and a Priority
typedef struct {
    int id;
    int priority;
} Task;

// Standard Node for the internal Queue
typedef struct Node {
    Task data;
    struct Node* next;
} Node;

// Standard FIFO Queue
typedef struct {
    Node *front_node;
    Node *rear_node;
    int size;
} Queue;

/**
 * STANDARD QUEUE IMPLEMENTATION (Provided)
 */

int isEmpty(Queue *q) {
    return (q->size == 0) ? 1 : 0;
}

int enqueue(Queue *q, Task t) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return 0;

    newNode->data = t;
    newNode->next = NULL;

    if (q->rear_node == NULL) {
        q->front_node = q->rear_node = newNode;
    } else {
        q->rear_node->next = newNode;
        q->rear_node = newNode;
    }

    q->size++;
    return 1;
}

int dequeue(Queue *q, Task *t) {
    if (isEmpty(q)) return 0;

    Node* temp = q->front_node;
    *t = temp->data;

    q->front_node = q->front_node->next;
    if (q->front_node == NULL) {
        q->rear_node = NULL;
    }

    free(temp);
    q->size--;
    return 1;
}

int front(Queue *q, Task *t) {
    if (isEmpty(q)) return 0;

    *t = q->front_node->data;
    return 1;
}

/**
 * PRIORITY QUEUE ADT (TO IMPLEMENT)
 */

int enqueuePQ(Queue *q, int id, int pr) 
{
    Task newtask; //initialzing just to fix the type mismatch
    newtask.id=id;
    newtask.priority=pr;
    if(isEmpty(q))
    {
        enqueue(q,newtask);
        return 1;
    }
    Task current;
    int flag=0;
    int n=q->size; 
    for(int i=0;i<n;i++)
    {
        dequeue(q,&current);
        if(current.priority<newtask.priority && !flag)
        {
            enqueue(q,newtask);
            flag=1;
        }
        enqueue(q,current);
    }
    if(!flag)
    {
        enqueue(q,newtask);
    }
    return 1;
}

int dequeuePQ(Queue *q, int *id) {
    if(isEmpty(q))
    {
        return 0;
    }
    Task t;
    dequeue(q,&t);
    *id=t.id;
    return 1;
}   

int frontPQ(Queue *q, int *id) {
    if(isEmpty(q))
    {
        return 0;
    }
    Task t;
    front(q,&t);
    *id=t.id;
    return 1;
}

int isEmptyPQ(Queue *q) {
    if(isEmpty(q))
    {
        return 1;
    }
    return 0;
}

int main() {
    int Q_ops;
    if (scanf("%d", &Q_ops) != 1) return 0;

    Queue internalQueue = {NULL, NULL, 0};

    while (Q_ops--) {
        int type;
        if (scanf("%d", &type) != 1) break;

        if (type == 1) {
            int val, pr;
            scanf("%d %d", &val, &pr);
            enqueuePQ(&internalQueue, val, pr);

        } else if (type == 2) {
            int resultId;
            if (dequeuePQ(&internalQueue, &resultId)) {
                printf("%d\n", resultId);
            } else {
                printf("-1\n");
            }

        } else if (type == 3) {
            int resultId;
            if (frontPQ(&internalQueue, &resultId)) {
                printf("%d\n", resultId);
            } else {
                printf("-1\n");
            }
        }
    }

    return 0;
}