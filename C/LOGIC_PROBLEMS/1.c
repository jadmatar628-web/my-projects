#include<stdio.h>

void compress(int *arr, int *n)
{
    int *p=arr;
    for(int i=0;i<*n;i++)
    {
        for(int j=i+1;j<*n;j++)
        {
          if(*(p+i)==*(p+j))
          {
            *(p+j)=-1;
          }
        }
    }
}

int main()
{
    int n=6;
    int arr[]={0,2,6,0,4,2};
    compress(arr,&n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}