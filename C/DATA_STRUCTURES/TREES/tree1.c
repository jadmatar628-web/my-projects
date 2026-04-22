#include<stdlib.h>
#include<stdio.h>
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

int countnode(Node *root)
{
    if(root==NULL) return 0;
    return 1+countnode(root->left)+countnode(root->right);
}
int main()
{
    Node *tree1=tree();
    preorder(tree1);
    printf("\n");
    inorder(tree1);
    printf("\n");
    postorder(tree1);
    printf("\n");
    printf("%d",countnode(tree1));
}