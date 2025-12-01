#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
printf("Enter how many nodes you want to have: ");
int value;
scanf("%d",&value);
struct node *head=NULL;
struct node *current=NULL;

for(int i=0;i<value;i++)
{
    struct node *newnode=malloc(sizeof(struct node));
    printf("Enter data into node #%d: ",i+1);
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(head==NULL)
    {
    head=newnode;
    current=head;
    }
    else
    {
        current->next=newnode;
        current=newnode;
    }

}
current=head;
printf("Enter the position you want to insert element at: ");
int pos;
scanf("%d",&pos);
printf("Enter the value you want to insert at the %dth postion: ",pos);
int new_value;
scanf("%d",&new_value);
struct node *temp=NULL;
temp=malloc(sizeof(struct node));
if(pos==1)
{
    temp->data=new_value;
    temp->next=head;
    head=temp;
    current=head;
}
else
{
    struct node *current=head;
    for(int i=1;i<pos-1 && current!=NULL;i++)
    {
        current=current->next;
    }

if(current==NULL)
{
    printf("Position out of range.\n");
}
else
{
    temp->next=current->next;
    current->next=temp;
}
}
current=head;
while(current!=NULL)
{
    printf("%d ",current->data);
    current=current->next;
}
}