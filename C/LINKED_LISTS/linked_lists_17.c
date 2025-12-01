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

struct node *reverselist(struct node *head)
{
    struct node *prev=NULL;
    struct node *current=head;
    struct node *next=NULL;
    while(current!=NULL)
    {
        //comments are for the 1st iteration
        next=current->next; //we assigned for the node next the value that follows it
        current->next=prev; //now the following node now holds its previous nodes struct
        prev=current; 
        current=next; 
    }
    return prev;

}
void freejad(struct node *head)
{
    struct node *current=head;
    while(head!=NULL)
    {
        struct node *temp=head;
        head=head->next;
        free(temp);
    }
}
int main()
{
    printf("How many nodes do you want to have: ");
    int value;
    scanf("%d",&value);
    struct node *head=creatlist(value);
    printlist(head);
    struct node *list=reverselist(head);
    printlist(list);
    freejad(list);
    return 0;
}
