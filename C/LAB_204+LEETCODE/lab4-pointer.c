#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void array(int *arr, int size1)
{
    for(int i=0;i<size1;i++)
    {
        scanf("%d",arr+i);
    }
}

int main()
{
    printf("Enter the size of your array: ");
    int n;
    scanf("%d",&n);
    int jad[n];
    array(jad,n);
    printf("The array that you entered is: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",*(jad+i));
    }
}