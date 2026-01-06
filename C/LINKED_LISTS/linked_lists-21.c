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
void printlist(struct node *head)
{
    struct node *current=head;
    while(current!=NULL)
    {
        printf("%d ",current->data);
        current=current->next;
    }
}

struct node *insert(struct node *head)
{
    struct node *current=head;
    while(current!=NULL)
    {
        if(current->data%2==0)
        {
            struct node *new=malloc(sizeof(struct node));
            struct node *temp=current->next;
            new->next=temp;
            current->next=new;
            new->data=current->data-1; //so it is never an even number
            current=temp;
        }
        else
        {
            current=current->next;
        }
    }
    current=head;
    return head;
}

int main()
{
    printf("Enter nodes count: ");
    int n;
    scanf("%d",&n);
    struct node *head=creatlist(n);
    if(head==NULL)
    {
        printf("Empty list.");
        return 0;
    }
    else
    {
        insert(head);
        printlist(head);
    }
    while(head!=NULL)
    {
        struct node *temp=head->next;
        free(head);
        head=temp;
    }
}