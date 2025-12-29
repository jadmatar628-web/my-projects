#include<stdio.h>
#include<stdlib.h>
//chatgpt did wonders
struct node //chatgpt said i can define my own TYPE and this is how it is done OMG!
{
    int data;
    struct node *next;
};
struct node *move_to_head(struct node *head) //create a new function that moves nodes
{
    struct node *new=NULL; //initilazed a pointer new that is null that points to the struct node
printf("Enter the value of the new head: "); //reading the value
int value;
scanf("%d",&value);
new=malloc(sizeof(struct node)); //reserving space in memory for the new node called "new"
new->data=value; //assiging the value for this new node
new->next=head; //assiging the direction of this new node
return new; //returning the new list (node+value)
}
int main()
{
struct node *head=NULL; //building the three nodes manually
struct node *second=NULL;
struct node *last=NULL;
head=malloc(sizeof(struct node));//reserving memory
second=malloc(sizeof(struct node));
last=malloc(sizeof(struct node));
head->data=4;//assiging values
second->data=5;
last->data=10;
head->next=second; //assiging directions
second->next=last;
last->next=NULL;
head=move_to_head(head);//calling the function and asking the compiler to update the value of head to the new value coming from the function we wrote above
struct node *current=head; //storing the new head in a new list called current
while(current!=NULL)
{
    printf("%d ",current->data);
    current=current->next; //updating the direction of current till it reaches NULL and terminates
}
struct node *temp;
while(head != NULL) { //freeing memory
    temp = head;
    head = head->next;
    free(temp);
}
return 0;
}
