//find max and min
//frequency: 1

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

int main()
{
    printf("How many nodes do you want to have: ");
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
            current=newnode;
        }
        else
        {
            current->next=newnode;
            current=newnode;
        }
        printf("Insert data into node #%d: ",i+1);
        scanf("%d",&newnode->data);
    }
    current=head;
int max=head->data;
int min=head->data;
while(current!=NULL)
{
    if(current->data>max)
    {
        max=current->data;
    }
    if(current->data<min)
    {
        min=current->data;
    }
    current=current->next; //i++
}
printf("Max is %d and min is %d.\n",max,min);
current = head;
while(current != NULL)
{
    struct node *temp = current;
    current = current->next;
    free(temp);
}

return 0;
}