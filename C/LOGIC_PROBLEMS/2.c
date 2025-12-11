#include<stdio.h>

void extarct_even(int *arr, int *n)
{
    int *p=arr;
    int *write=arr;
    for(int i=0;i<*n;i++)
    {
            if(*p%2==0)
            {
                *write=*p;
                write++;
                p++;
            }
            else
            {
                p++;
            }
    }
    *n=write-arr;
}

int main()
{   int n=10;
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    extarct_even(arr,&n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",*(arr+i));
    }
} 