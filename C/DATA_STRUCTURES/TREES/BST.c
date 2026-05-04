#include<stdlib.h>
#include<stdio.h>
#include"../STACKS/STACK_A.H"
#include "../QUEUES/queue.h"

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
    root->left->left=createnode(54);
    root->left->left->left=createnode(56);
    root->right=createnode(20);
    root->right->left=createnode(120);
    return root;
}

void inorder(Node *root)
{
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void preorder (Node *root)
{
    if(root==NULL) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node * root)
{
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
  
}


int search_BST(Node *root, int value)
{
    if(root==NULL) return 0;
    if(root->data==value) return 1;
    if(root->data>value) return search_BST(root->left,value);
    else return search_BST(root->right,value);
}