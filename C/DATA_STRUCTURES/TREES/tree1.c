#include<stdlib.h>
#include<stdio.h>
#include"STACK_A.H"
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

int countnode(Node *root)
{
    if(root==NULL) return 0;
    return 1+countnode(root->left)+countnode(root->right);
}

int height(Node *root)
{
    if(root==NULL) return -1;
    int MAXLEFT=1+height(root->left);
    int MAXRIGHT=1+height(root->right);
    if(MAXLEFT>MAXRIGHT) return MAXLEFT;
    if(MAXRIGHT>MAXLEFT) 
    {return MAXRIGHT;
    }
    else
    {
        return 0;
    }
}

int leafcount(Node *root)
{
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL)
    {
        return 1;
    }
    return leafcount(root->left)+leafcount(root->right);
}

void deleteTree(Node* root)
{
    if(root==NULL) return;
    deleteTree(root->right);
    deleteTree(root->left);
    free(root);
}

void reversed_postorder_traversal(Node *root)
{
    Queue q=createQueue(10);
    Stack *s=createStack(10);
    enqueue(&q,root);
    while(!iSEmpty(q))
    {
        Node *curent=dequeue(&q);
        push(s,current);
        if(current->right!=NULL)
        {
            enqueue(&q,current->right);
        }
        if(current->left!=NULL)
        {
            enqueue(&q,current->left);
        }

    }
    while (!isEmptyStack(&s))
{
    Node* curr = pop(&s);
    printf("%d ", curr->data);
}
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
    printf("\n");
    printf("%d",height(tree1));
    printf("\n");
    printf("%d",leafcount(tree1));

}