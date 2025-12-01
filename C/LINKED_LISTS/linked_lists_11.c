//insert at head
//frequency 1

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *creatlist()
{
    struct node *head=NULL;
    struct node *current=NULL;
    int value;
    int i=0;
    while(10)
    {
        printf("Enter data into node #%d: ",i+1);
        scanf("%d",&value);
        if(value==-1)
    {
        break;
    }
        struct node *newnode=malloc(sizeof(struct node));
        newnode->data=value;
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
        i++;
}

    current=head;
    printf("You entered the following list: \n");
    while(current!=NULL)
    {
        printf("%d ",current->data);
        current=current->next;
    }
    printf("\n");
    return head;
}
struct node* insertAtBeginning(struct node *head, int neww)
{
    struct node *newhead=malloc(sizeof(struct node));
    newhead->data=neww;
    newhead->next=head;
return newhead;
}
int main()
{
    struct node *head=creatlist();
    printf("Enter the new head: ");
    int newh;
    scanf("%d",&newh);
   head=insertAtBeginning(head,newh);
    struct node *Current=head;
    printf("The list with updated head: ");
    while(Current!=NULL)
    {
        printf("%d ",Current->data);
        Current=Current->next;
    }
    while(head!=NULL)
    {
        struct node *temp=head;
        head=head->next;
        free(temp);
    }
    return 0;
}

