#include<stdio.h>

int main()
{
    int x;
    char c;
    double d;
    printf("Fill 3 variables: \n");
    scanf("%d %c %lf", &x, &c, &d);
    printf("Values enetered %d %c %lf", x, c, d);
}