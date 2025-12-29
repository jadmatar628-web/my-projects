#include<stdio.h>
#include<stdlib.h>
    struct node
    {
        int data;
        struct node *next; //pointer to the next node
    };
int main()
{

    struct node *head=malloc(sizeof(*head));  
    struct node *second = malloc(sizeof(*second));
    struct node *third = malloc(sizeof(*third));
    head->data=10;
    second->data=40;
    third->data=30;
    head->next=second;
    struct node *current=head;
    second->next=third;
    third->next=NULL;
    while(current!=NULL)
    {
        printf("%d\n",current->data);
        current=current->next;
    }
    free(head);
    free(second);
    free(third);
    return 0;
}