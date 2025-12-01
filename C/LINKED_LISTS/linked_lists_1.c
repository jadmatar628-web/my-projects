#include<stdio.h>
#include<stdlib.h>
    struct node
    {
        int data;
        struct node *next; //pointer to the next node
    };
int main()
{
    struct node *head=NULL;
    struct node *second=NULL;
    struct node *third=NULL;

    head=malloc(sizeof(*head));  
    second = malloc(sizeof(*second));
    third = malloc(sizeof(*third));
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