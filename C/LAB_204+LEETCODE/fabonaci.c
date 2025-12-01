#include<stdio.h>
int fab(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }
    n=n*fab(n-1)+fab(n-2);
}
int main()
{
    printf("Enter a number to calculate its fabonaci: ");
    int n;
    scanf("%d",&n);
    int result=fab(n); 
    printf("The fabonaci of %d is %d\n",n,result);
}