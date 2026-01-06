#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;


struct node* reverse(node *head)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(head->next==NULL)
    {
        return head;
    }
   struct node *tail= reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return tail;
}

struct node *creatlist(int n) //create list based on user input
{
    struct node *head=NULL;
    struct node *current=NULL;
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
    printf("The original list is: \n");
    while(current!=NULL)
    {
        printf("%d ",current->data);
        current=current->next; //i++ equiv
    }
    printf("\n");
        return head;
}

int main()
{
    struct node *head=creatlist(5);
    head=reverse(head);
    struct node *current=head;
    while(current!=NULL)
    {
        printf("%d ",current->data);
        current=current->next; //i++ equiv
    }
    printf("\n");
    
}

