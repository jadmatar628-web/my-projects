
#include<stdio.h>
#define MAX 100
#include"STACK.H"
typedef struct Stack{
    int arr[6];
    int top;
} Stack;

void insertatbottom(Stack *s, int value)
{
    if(isEmpty(s))
    {
        push(s,value);
        return;
    }
    int temp=pop(s);
    insertatbottom(s,value);
    push(s,temp);
}

void reverse(Stack *s)
{
    if(isEmpty(s))
    {
        return ;
    }
    int temp=pop(s);  
    reverse(s);  
    insertatbottom(s,temp);
}

int main()
{
printf("Enter an array: \n");
   stack s;
   s.top=-1;
    for(int i=0;i<6;i++)
    {
        int temp;
        scanf("%d",&temp);
        push(&s,temp);
    }
    reverse(&s);
    for(int i=0;i<6;i++)
    {
        printf("%d",&s.data[i]);
    }
}