#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *creatlist(int n)
{
    struct node *head=NULL;
    struct node *current;
    for(int i=0;i<n;i++)
    {
        struct node *newnode=malloc(sizeof(struct node));
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
            current=newnode;
        }
        else
        {
            current->next=newnode;
            current=newnode;
        }
        printf("Enter data into node #%d: ",i+1);
        scanf("%d",&newnode->data);
    }
    current=head;
    return head;
}
void delete(struct node *head)
{
    struct node *current=head;
    struct node *prev;
    while(current!=NULL)
    {
        struct node *run=current->next;
        prev=current;
        while(run!=NULL)
        { 
            if(current->data==run->data) //duplicate is found
            {
                struct node *temp=run;
                prev->next=run->next;
                run=run->next;
                free(temp);
            }
            else
            {
                prev=run;
                run=run->next;
            }

        } current=current->next;
    }
}