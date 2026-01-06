//advice for you: always, like ALWAYS write comments nect to your code cause that is the only way to make sure that u totally got the idea of what you have copied from chatgpt 
//subject: reverse a list
//frequency:1 


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
struct node {
    int data;
    struct node *next;
};

int main()
{
    printf("Enter how many nodes you wanna have: ");
    int value;
    scanf("%d",&value);
    struct node *head=NULL;
    struct node *current=NULL;
    for(int i=0;i<value;i++)
    {
        struct node *newnode=malloc(sizeof(struct node));
        newnode->next=NULL; //helps in the prinitng 
        if(head==NULL) //case 1:head is empty
        {
            head=newnode;//head is now equal to "newnode"
            current=newnode;
        }
        else //head is no longer empty
        {
            current->next=newnode;
             current=newnode; 
        }
        printf("Enter data into node #%d: ",i+1);
        scanf("%d",&newnode->data);
    }
    current=head;
    printf("The original list is: ");
    for(int i=0;i<value;i++)
    {
        printf("%d ",current->data);
        current=current->next;
    }
    current=head;
    printf("\nThe reversed list is: ");
    struct node *prev=NULL;
    struct node *next=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
      current = head; // reset to the new head
while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
}
} 