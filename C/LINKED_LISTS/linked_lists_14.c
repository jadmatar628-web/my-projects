// delete at any pos
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
    int value;
    int i=0;
    struct node *head=NULL;
    struct node *current;
    while(1)
    {
        printf("Enter data into node #%d: (-1 to stop) ",i+1);
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
    return head;
}
struct node *print(struct node *head)
{
    printf("The list is: ");
    struct node *current=head;
    while(current!=NULL)
    {
        printf("%d ",current->data);
        current=current->next;
    }
    printf("\n");
    return head;
}
struct node *delete(struct node *head, int position)
{
    struct node *current=head;
    int list_length=0;
    while(current!=NULL)
    {
        list_length++;
        current=current->next;
    }
    current=head;
    if(position>list_length || position<=0)
    {
        printf("Position out of bonds.");
        return head;
    }
    else if(position==1)
    {
        struct node *temp=head;
        head=head->next;
        free(temp);
        print(head);
        return head;

    }
    else
    {
        struct node *prev=NULL;
        struct node *current=head;
        int count=1;
        while(count<position)
        {
            count++;
            prev=current;
            current=current->next;//the node to be deleted
        }
        if(current!=NULL)
        prev->next=current->next;
        print(head);
        free(current);
    }
    return head;
}
int main ()
{
    struct node *head=creatlist();
    print(head);
    printf("Enter the position you want to delete: ");
    int pos;
    scanf("%d",&pos);
    head=delete(head,pos);
    while(head!=NULL)
    {
        struct node *temp=head;
        head=head->next;
        free(temp);
    }
    return 0;
}