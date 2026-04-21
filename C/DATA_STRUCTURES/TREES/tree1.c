#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
}Node;

Node *createnode(int data)
{
    Node *newnode=malloc(sizeof(Node));
    if(newnode==NULL) return NULL;
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

Node * tree()
{
    Node * root=createnode(10);
    root->left=createnode(5);
    root->right=createnode(20);
    return root;
}