#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);
    int * arr= (int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        count+=arr[i];
    }
    printf("The sum of all the elements in arr is: %d.\n",count);
    return 0;

}