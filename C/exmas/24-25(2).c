//exercise 3: iterative
#include<stdio.h>
#include<stdlib.h>

typedef struct node
 {
    int data;
    struct node *next;
 } node;

node * creatlist(int n)
{
    node *head=NULL;
    node *current;
    for(int i=0;i<n;i++)
    {
        node *newnode=malloc(sizeof(node));
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
    return head;
}

node *sort (node *head)
{
    node *evenhead=NULL;
    node *eventail=NULL;
    node *oddhead=NULL;
    node *oddtail=NULL;
    node *current=head;

    while(current!=NULL)
    {
        node *nextnode=current->next;
        if(current->data%2==0)
        {
            if(evenhead==NULL)
            {
                evenhead=current;
                eventail=current;
            }
            else
            {
                eventail->next=current;
                eventail=current;
            }
        }
        else
        {
            if(oddhead==NULL)
            {
                oddhead=current;
                oddtail=current;
            }
            else 
            {
                oddtail->next=current;
                oddtail=current;
            }
        }
        current=nextnode;
    }
    if(evenhead!=NULL)
    {
        eventail->next=oddhead;
    }
    if(oddhead!=NULL)
    {
        oddtail->next=NULL;
    }
    return(evenhead!=NULL)?evenhead :oddhead;   
}

int main()
{
    node *head=creatlist(7);
   head= sort(head);
    node *current=head;
    while(current!=NULL)
    {
        printf("%d ",current->data);
        current=current->next;
    }
}
