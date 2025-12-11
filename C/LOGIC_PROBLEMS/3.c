#include<stdio.h>

void pair(int *arr, int *n)
{
    int *p=arr;
    int *write=arr;
    for(int i=0;i<*n;i++)
    {
        if(p<arr+n-1)
        {
        if(*(p)==*(p+1)) //if p = the element next to it
        {
            *write=*(p)*2; // p becomes the double of that element
            write++; //write moves one index 
            p=p+2;
        }
        else
        {
            *write=
            p++;
        }
    }
    }
    *n=write-arr; 
}

int main()
{
    int n=6;
    int arr[]={1,1,2,2,3,3};
    pair(arr,&n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",*(arr+i));
    }
}