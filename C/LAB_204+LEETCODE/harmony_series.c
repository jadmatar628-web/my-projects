#include<stdio.h>
float harmony(int n)
{
    if(n==1)
    {
        return 1;
    }
    n=1./n-harmony(n-1);
    return n;
}
int main()
{
    printf("Enter a number:\n");
    int num;
    scanf("%d",&num);
    printf("The harmonly series of %d is: %.2f",num,harmony(num));
}