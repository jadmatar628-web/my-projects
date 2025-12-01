//search algorithm
// frq 1

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *creatlist(int n)
{
    if(n<=0)
    {
        printf("NODES COUNT CANNOT BE <=0.\n");
        exit(1);
    }
    struct node *head=NULL;
    struct node *current;
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
        printf("Enter data into node #%d: ",i+1);
        scanf("%d",&newnode->data);
    }
    printf("\n");
    current=head;
    printf("You entered a list made of the %d following integers: \n",n);
    while(current!=NULL)
    {
        printf("%d ",current->data);
        current=current->next;
    }
    return head;
}
struct node *search(struct node *head, int key)
{
    struct node* current=head;
    int count=0;
    int found=0;
    while(current!=NULL)
    {
        
        if(current->data==key)
        {
            printf("%d is found in the list into the node #%d.\n",key,count+1);
            found=1;
        }
        current=current->next;
        count++;
    }
    if (!found)
    {
    
    printf("%d is not found in the list.\n",key);}
     return NULL;
}
int main()
{
    printf("Enter how many nodes do you want to have: ");
    int value;
    scanf("%d",&value);
    struct node *head=creatlist(value);
    printf("\n");
    printf("Enter the value you want to search for: ");
    int sear;
    scanf("%d",&sear);
    search(head,sear);
    while(head!=NULL)
    {
        struct node *temp=head;
        head=head->next;
        free(temp);
    }
    return 0;
}