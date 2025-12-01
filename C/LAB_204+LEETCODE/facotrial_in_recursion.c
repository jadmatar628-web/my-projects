#include<stdio.h>
//facotrial in recursion
long long factorial(int n)
{
    if(n==0)
    {
        return 1; //base case
    }
    n=n*factorial(n-1);

    return n;
}
int main()
{
    int n;
    scanf("%d",&n);
    long long fac=factorial(n);
    printf("The facotrial of %d is %llu\n",n,fac);
}