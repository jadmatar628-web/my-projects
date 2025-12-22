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
    newnode *t=newhead;
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
           newnode *prev=NULL;
           while(t!=NULL)
           {
                if(current->data==t->c)
                {t->count++;
                break;}
                t=t->next;
           }
           
           newnode *created=malloc(sizeof(newnode));
           created->c=current->data;
           created->count=1;
           prev=t;
           t=t->next;
           while(t!=NULL)
           {
            if(created->c>prev->c)
            {
                prev->next=created;
                break;
            }
            if(created->c<newhead->c)
            {
                newhead->c=created->c;
                newhead->count++;
                newhead->next=created;
            }
            prev=t;
            t=t->next;
           }

           
        }
    } current=current->next;
}