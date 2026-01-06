#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

struct node *new_node();
int main()
{
    struct node *head=NULL;
struct node *second=NULL;
struct node *third=NULL;    
head=malloc(sizeof(struct node));
second=malloc(sizeof(struct node));
third=malloc(sizeof(struct node));
printf("Enter data into node #1: ");
scanf("%d",&head->data);
printf("Enter data into node #2: ");
scanf("%d",&second->data);
printf("Enter data into node #3: ");
scanf("%d",&third->data);

head->next=third;
second->next=third;
third->next=NULL;
   struct node *new=new_node();
   third->next=new;
   printf("Enter data into the newely created node: ");
   scanf("%d",&new->data);
struct node *current=head;
for(int i=0;i<4;i++)
{
    printf("The data inside node #%d is %d.\n",i+1,current->data);
    current=current->next;
}
}
struct node *new_node()
{
    struct node *new=NULL;
    new=malloc(sizeof(struct node));
    new->next=NULL;
    return new;
}