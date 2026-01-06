//sort a linked list by swapping values, not pointers
//frq 3

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

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
struct node *sort(struct node *head) //to sort fron biggest to smallest
{
    struct node *current=NULL, *index=NULL;
    int temp;
    for(current=head;current->next!=NULL;current=current->next)
    {
        for(index=current->next;index!=NULL;index=index->next)
        {
            if(index->data>current->data) //just change the sing > to < to reverse the sorting direction
            {
                temp=index->data;
                index->data=current->data;
                current->data=temp;
            }
        }
    }
    current=head;
    printf("The sorted list is: \n");
    while(current!=NULL)
    {
        printf("%d ",current->data);
        current=current->next;
    }
    return head;
}
int main()
{
    printf("How many nodes do you want to have: ");
    int value;
    scanf("%d",&value);
    struct node *head=creatlist(value);
    sort(head);
    return 0;
}