#include<stdlib.h>

typedef struct node{
    char data;
    struct node *next;
}node;

typedef struct newnode{
    char c;
    int count;
    struct newnode *next;
}newnode;

void generate(node *head)
{
    node *current=head;
    newnode *newhead=NULL;
    
    while(current!=NULL)
    {
        if(newhead==NULL)
        {
            newhead=malloc(sizeof(newnode));
            newhead->c=current->data;
            newhead->count=1;
        }
        else
        {
            
        }
        current=current->next;
    }
}