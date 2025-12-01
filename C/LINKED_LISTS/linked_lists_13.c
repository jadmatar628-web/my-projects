//insert at any position
//freq 1

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
    while(1)
    {
        struct node *newnode=malloc(sizeof(struct node));
         printf("Enter data into node #%d: ",i+1);
        scanf("%d",&value);
        if(value==-1)
        {
            break;
        }
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
    return head;
}
struct node *print(struct node *head)
{
    struct node *current=head;
    printf("The list you entered is: \n");
    while(current!=NULL)
    {
        printf("%d ",current->data);
        current=current->next;
    }
    current=head;
    return head;
}
struct node *insertatanyposition(struct node *head,int value,int position)
{
    int count=0;
    struct node *current=head;
    while(current!=NULL)
    {
        count++;
        current=current->next;
    }
current=head;
    if(position==1)
    {
        struct node *newhead=malloc(sizeof(struct node));
        newhead->data=value;
        newhead->next=head;
        print(newhead);
        return newhead;
    }
    else if(position==count+1)
    {
        while(current->next!=NULL)
    {
        current=current->next;
    }
    struct node *tail=malloc(sizeof(struct node));
    current->next=tail;
    tail->data=value;
    tail->next=NULL;
    print(head);
    return head;
    }
    else if(position<=0 || position>count+1)
    {
        printf("Inseration out of bonds");
        return head;
    }
    else
    {
        int count1=1;
        struct node *prev=NULL;
        while(count1<position)
        {
            prev=current;
            current=current->next;
            count1++;
        }
        struct node *newnode=malloc(sizeof(struct node));
        newnode->data=value;
        prev->next=newnode;
        newnode->next=current;
        print(head);
        return head;
    }    
}
int main()
{
    struct node *head=creatlist();
    print(head);
    printf("Enter the position you want to insert at: ");
    int pos;
    scanf("%d",&pos);
    printf("Enter the value you want to insert at pos #%d: \n",pos);
    int value;
    scanf("%d",&value);
    head=insertatanyposition(head,value,pos);
    while(head!=NULL)
    {
        struct node *temp=head;
        head=head->next;
        free(temp);
    }
    return 0;
}