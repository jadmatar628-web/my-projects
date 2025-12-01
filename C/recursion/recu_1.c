//sum of digits
//frequency 2


#include<stdio.h>
int sumdigits(int n)
{
    if(n==0)
    {
        return 0;
    }
    n+=n%10;
    return sumdigits(n/10);
}

int main()
{
    printf("Enter a number to sum all of its digits: ");
    int value;
    scanf("%d",&value);
    int sum1=sumdigits(value);
    printf("The sum of all the digits of %d is %d.",value,sum1);
} 