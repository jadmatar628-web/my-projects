#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
    int id;
    char name[50];
    float gpa;
    struct node *next;
};

struct node *creatlist(int n)
{
    struct node *head=NULL;
    struct node *current=NULL;
       if(n<=0)
    {
        printf("NODES COUNT CANNOT BE <=0.\n");
        exit(1);
    }
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
            printf("Enter the name of student #%d: ",i+1);
            scanf("%s",newnode->name);
            printf("Enter ID of student #%d: ",i+1);
            scanf("%d",&newnode->id);
            printf("Enter GPA of student #%d: ",i+1);
            scanf("%f",&newnode->gpa);
    }
            struct node *temp=head;
            int i=0;
    while(temp!=NULL)
    {
        printf("The name of student #%d is %s. \n",i+1,temp->name);
        printf("The GPA of student #%d is %f. \n",i+1,temp->gpa);
        printf("The ID of student #%d is %d. \n",i+1,temp->id);
        temp=temp->next;
        i++;
    }
   current=head;
   return head;
}

struct node *insertatbig(struct node *head)
{
    struct node *newhead=malloc(sizeof(struct node));
    printf("Enter the name of student #1: ");
            scanf("%s",newhead->name);
            printf("Enter ID of student #1: ");
            scanf("%d",&newhead->id);
            printf("Enter GPA of student #1: ");
            scanf("%f",&newhead->gpa);
    newhead->next=head;
    return newhead;
}

struct node *insertatend(struct node *head)
{
    struct node *current=head;
    struct node *newend=malloc(sizeof(struct node));
    while(current->next!=NULL)
    {
        current=current->next;
        if(current->next==NULL)
        {
            current->next=newend;
            newend->next=NULL;
            printf("Enter the name of the last student: ");
            scanf("%s",newend->name);
            printf("Enter ID of the last student: ");
            scanf("%d",&newend->id);
            printf("Enter GPA of the last student: ");
            scanf("%f",&newend->gpa);
        }
    }
    return head;
}

int main()
{
    printf("Enter how many students do you want to have: ");
    int size;
    scanf("%d",&size);
    struct node *head=creatlist(size);
    struct node *t=insertatend(head);
        struct node *n=insertatbig(head);
}