//exersice to delete a node at a specified user-entered location
//frequency: 3

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
    newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
            current = head;
        }
        else
        {
            current->next=newnode;
            current=newnode;
        }
        printf("Enter data into node #%d: ",i+1);
        scanf("%d",&newnode->data);
    }
    
    printf("The data in head is: %d.\n",head->data);
    printf("You entered:\n");
    current=head;//just for the "for" loop below to start from head
 for(int i=0;i<value;i++)
    {
        printf("%d ",current->data);
        current=current->next;
    }
    int del;
    printf("\nEnter which position you want to delete: ");
    scanf("%d",&del);

if(del==1)
{
    struct node *temp=head;
    head=head->next;
    free(temp);
}
current=head;
if(del>1 && del <value)
{
for(int i=1;i<del-1 && current!=NULL;i++)
{
current=current->next;
}}
if(del>value)
{
    printf("Insertion out of range.\n");
    return 1;
}

    struct node *temp=current->next;
    current->next=temp->next;
    free(temp);

printf("Updated list after deleting the data at postion #%d:\n",del);
current=head;
for(int i=0;i<value-1;i++)
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
