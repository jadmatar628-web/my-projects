#include<stdio.h>
#include<stdlib.h>

int max(int *arr, int size)
{
    int max_el=*arr;
    for(int i=0;i<size;i++)
    {
        if(*(arr+i)>max_el)
        {
            max_el=*(arr+i);
        }
    }
    return max_el;
}

int main()
{
    printf("Enter the size of your array: ");
    int n;
    scanf("%d",&n);
    int *arr=malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",arr+i);
    }

    int res=max(arr,n);
    printf("The max element of your array is %d.",res);
    return 0;
}