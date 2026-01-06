#include<stdio.h>
int main()

{int sum=0;
    int n=989303;
    printf("n modula 10 is: %d \n",n%10);
    sum+=n;
    printf("The sum of n so far: %d\n",sum);
    n=n/10;
    printf("n/10 of n so far: %d\n",n);}