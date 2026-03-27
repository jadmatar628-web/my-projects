#include<stdio.h>
#include"STACK.H"
#include<stdlib.h>

int compare(int a, int b)
{
    int max;
    if(a>b)
    {
        max=a;
    }
    if(b>a)
    {
        max=b;
    }
    if(a==b)
    {
        max=a;
    }
    return max;
}
int *aestroids(int *arr, int size, int * returnvalue)
{
    Stack *s=createStack(size);
    for(int i=0;i<size;i++)
    {
        int current=arr[i];
        int flag=1;
        while(s->top>=0 && s->data[s->top]>0 && current<0)
        {
            if(abs(s->data[s->top])>abs(current))
            {
                flag=0;
                break;
            }
            if(abs(s->data[s->top])<abs(current))
            {
                pop(s,s->top);
                continue;
            }
            if(abs(s->data[s->top])==abs(current))
            {
                flag=0;
                pop(s,s->top);
                break;
            }
        }
        if(flag) push(s,current);
    }
    returnvalue = s->top + 1;
return s->data;
}