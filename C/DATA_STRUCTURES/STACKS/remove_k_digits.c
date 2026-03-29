#include<STACK_A.H>

Stack * removeKdigits(int k, int *arr, int size, Stack *s)
{
    for(int i=0;i<size;i++)
    {
        int current=arr[i];
        while(k>0 && !isEmpty(s) && current<s->arr[s->top])
        {
                pop(s);
                k--;
        }
        push(s,current);
    }
    if(k>0)
    {
        for(k;k>0;k--)
        {
            pop(s);
        }
    }
    return s;
}