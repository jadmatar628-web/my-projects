//insert at tail
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
struct node* insertAtTail(struct node* head, int value)
{
    struct node *tail=malloc(sizeof(struct node));
    tail->data=value;
    tail->next=NULL;
    struct node *current=head;
    if(head==NULL)
    {
        return tail;
    }
   while(current->next!=NULL)
    {
       current=current->next;
    }
    current->next=tail;
    return head;
}
int main()
{
    struct node *head=creatlist();
    printf("Enter the new tail: \n");
    int newtail;
    scanf("%d",&newtail);
    head=insertAtTail(head,newtail);
    struct node *current=head;
    printf("The extended list with the new tail is: ");
    while(current!=NULL)
    {
        printf("%d ",current->data);
        current=current->next;
    }
    while(head!=NULL)
    {
        struct node *temp=head;
        head=head->next;
        free(temp);
    }
    return 0;  
}