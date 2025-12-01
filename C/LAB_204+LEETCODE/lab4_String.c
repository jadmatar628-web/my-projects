#include<stdio.h>
//make my own version of strcpy using pointer arithmetic
void mystrcpy(char *source, char *dest)
{
    char *p=source;
    char *d=dest;
    while(*p!='\0')
    {
        *d=*p;
        d++;
        p++;
    }
    *d='\0';
}


int main()
{
    printf("Enter 2 strings: ");
    char char1[100];
    char char2[100];
    scanf("%s %s",char1,char2);
    printf("Before swapping, %s and %s\n",char1,char2);
    mystrcpy(char1,char2);
    printf("After swapping, %s and %s\n",char1,char2);
}