#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main()
{
    fork();
    printf("Enter how many nodes you want to have: ");
    int node_count;
    scanf("%d",&node_count);
    struct node*head=NULL;
    struct node*current=NULL;
for(int i=0;i<node_count;i++) //start the for loop
{
    struct node *new_node=malloc(sizeof(struct node)); //allocare memory for 1 node at a time, +1 for each iteration 
        printf("Enter the data into node #%d: \n",i+1);
        scanf("%d",&new_node->data);
        new_node->next=NULL;
        if(head==NULL) //filling the node "head" cause it just null at the start
            {
                head=new_node;
                current=head; //pointing with current to head so it can start moving from head itself
            }
        else
            {
                current->next=new_node; //the condition head==NULL is no longer true so this will create a new node each time the loop iterates
                current=new_node; //assign current to the new node;then when the loop starts again current will points to the newly created node=NULL then assign the value to it again and again
        
            }
           
}
 current=head;
for(int i=0;i<node_count;i++)
{
     printf("The data inside node #%d is %d.\n",i+1,current->data);
    current=current->next;
}
}