#include<stdio.h>
#include<string.h>

int main()
{
    char char1[100];
    char char2[100];
    scanf("%s%s",char1,char2);
    strcat(char1,char2);
    printf("%s",char1);
} 