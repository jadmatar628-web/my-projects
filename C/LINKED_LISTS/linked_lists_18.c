//find the middle element of a linked list (pointer style)
//freq 1

#include<stdio.h>
#include<stdlib.h>

struct node{
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
struct node *printlist(struct node *head)
{
    struct node *current=head;
    printf("The list is: ");
    while(current!=NULL)
    {
        printf("%d ",current->data);
        current=current->next;
    }
    current=head;
    return head;
}
struct node *findmiddle(struct node *head)
{   
    struct node *current=head;
    struct node *slow=head;
    struct node *fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
struct node *freejad(struct node *head)
{
    struct node *current=head;
    while(current!=NULL)
    {
        struct node *temp=head;
        head=head->next;
        free(temp);
    }
}
int main()
{
    printf("Enter how many nodes do you want to have: ");
    int val;
    scanf("%d",&val);
    struct node *head=creatlist(val);
    printlist(head);
    struct node *middle=findmiddle(head);
    if(head!=NULL)
    {
        printf("The middle of the list is %d.",middle->data);
    }
    else
    {
        printf("The list is empty.");
    }
    return 0;
}