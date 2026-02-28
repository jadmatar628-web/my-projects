#include"STACK.h"


int isStackPermutation(int input[], int output[], int n)
{
    Stack s;
    s.top=-1;
    int i=0;
    int j=0;
    for(i=0;i<n;i++)
    {
        push(&s,input[i]);
        while(!(isEmpty(&s)) && s.data[s.top]==output[j])
        {
            pop(&s);
            j++;
        }
    }
    
    if(isEmpty(&s) && j==n)
    {
        return 1;
    }
    return 0;
}