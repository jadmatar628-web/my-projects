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
        return MAXLEFT;
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

int tree_height_iteratively(Node * root)
{
    Queue q;
    q=createQueue(50);
    enqueue(&q,root);
    int height=-1;
    while(!iSEmpty(&q))
    {
        int level_size=q.size;
        for(int i=0;i<level_size;i++)
        {
        Node *current=dequeue(&q);
            if(current->left!=NULL) enqueue(&q,current->left);
            if(current->right!=NULL) enqueue(&q,current->right);
        }
        height++;
    }
    return height;
}
int isIdentical(Node* t1, Node* t2)
{
    if (t1 == NULL && t2 == NULL) return 1;
    if (t1 == NULL || t2 == NULL) return 0;
    return (t1->data==t2->data && isIdentical(t1->left,t2->left) && isIdentical(t2->left,t2->right));
}

int level_that_has_the_max_sum(Node *root)
{
    Queue q=createQueue(50);
    enqueue(&q,root);
    int bestsum=root->data;
    int bestlevel=0;    
    int level=0;
    {
        while(!iSEmpty(&q))
        {
            int level_size=q.size;
            int current_sum=0;
            for(int i=0;i<level_size;i++)
            {
                Node *current=dequeue(&q);
                current_sum+=current->data;
                if(current->left!=NULL) enqueue(&q,current->left);
                if(current->right!=NULL) enqueue(&q,current->right);
            }
                if(current_sum>bestsum)
                {
                    bestsum=current_sum;
                    bestlevel=level;
                }
                level++;
        }
    } return bestlevel;
}
int diameter_height(Node *root, int *diameter)
{
    if (root == NULL) return -1;

    int left = diameter_height(root->left, diameter);
    int right = diameter_height(root->right, diameter);

    int candidate = left + right + 2;

    if (candidate > *diameter)
        *diameter = candidate;

    return 1 + (left > right ? left : right);
}
int diameter(Node *root)
{
    int d = 0;
    diameter_height(root, &d);
    return d;
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