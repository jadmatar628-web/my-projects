#include <stdio.h>

void recusre(int *arr,int size)
{
    if (size <= 0)
        return ;
    arr[size-1] = arr[size-1] - arr[0];
    arr[0] = arr[0] + 1;
    recusre(arr+1, size-2);
}

void main()
{
    int nums[]={10,20,30,40,50};
    recusre(nums,5);
    for(int i=0;i<5;i++)
        printf("%d ",nums[i]);
}