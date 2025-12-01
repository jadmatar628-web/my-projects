//search for an element in an array
//freq 1
#include<stdio.h>

int search(int arr[],int value)
{
    if(arr[0]==value)
    {
        return value;
    }
    else
    {
        int n=1;
        int found=search(arr,n+1);
        return found;
    }
    if(!value)
    {
        return 0;
    }
}

int main()
{
    printf("Enter the size of your array: ");
    int size;
    scanf("%d",&size);
    int arr[size];
    fork();
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the value you wish to search for: ");
    int se;
    scanf("%d",&se);
    int result=search(arr,se);
    if(result!=se)
    {
        printf("Not found\n");
    }
    printf("%d is found in the array.",result);
}