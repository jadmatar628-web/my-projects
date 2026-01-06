//program to seach value of an integer 

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
                current=newnode;
            }
            else 
            {
                current->next=newnode;
                current=newnode;
            }
            printf("Enter data into node #%d: ",i+1);
            scanf("%d",&newnode->data);
    }
    
    printf("Data in head is: %d.\n",head->data);
    int count=0;
    printf("Enter which value you want to search for: ");
    int search;
    scanf("%d",&search);
current=head;
while(current!=NULL)
        {
        if(current->data==search)
        {   
            if(i==0)
            {
                 printf("%d found at the HEAD position.\n",search);
            }
            else if(i==1)
            {
                 printf("%d found at the 2nd position.\n",search);
            }
            else if(i==2)
            {
                 printf("%d found at the 3rd position.\n",search);
            }
            else 
            {
            printf("%d found at the %dth position.\n",search,i+1);
            }
            break;
        }
        else
        {
            printf("%d not found in the list.\n",search);
            break;
        }
    }
current=head;
while(head!=NULL)
{
    struct node *temp=head;
    head=head->next;
    free(temp);
}
    return 0;
}