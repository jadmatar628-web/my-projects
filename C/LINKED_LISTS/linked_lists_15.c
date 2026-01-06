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
    return head;
}
struct node *print(struct node *head)
{
    struct node *current=head;
    while(current!=NULL)
    {
        printf("%d ",current->data);
        current=current->next;
    }
    current=head;
    return head;
}

struct node *delete(struct node *head, int n)
{
    int found=0;
    while(head!=NULL && head->data==n)
    {
        found=2;
        struct node *temp=head;
        head=head->next;
        free(temp);
    }
    struct node *current=head;
    struct node *prev=NULL;
    while(current!=NULL)
    {
        if(current->data==n)
        {
            found=1;
            struct node *temp=current;
            prev->next=current->next;
            current=current->next;
            free(temp);
        }
        else {
        prev = current;
        current = current->next;
        }
    }
    if(found==0)
    {
        printf("%d is not found in the list.\n",n);
    }

    current=head;
    return head;
}
int main()
{
    printf("Enter how many nodes do you want to have: ");
    int value;
    scanf("%d",&value);
    struct node *head=creatlist(value);
    print(head);
    printf("Enter the value you want to delete: ");
    int value1;
    scanf("%d",&value1);
    head=delete(head,value1);
    print(head);
    return 0;
}