#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
void main()
{
    if(!fork())
    {
        printf("process #1 A\n");
        wait(NULL);
    }
    if(fork())
    {
        printf("process #2 B\n");
        wait(NULL);
        printf("process #3 C\n");
    }
    else
    {
        printf("process #4 D\n");
    }
}