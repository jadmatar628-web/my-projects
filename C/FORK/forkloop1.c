#include<unistd.h>
#include<stdio.h>

void main()
{
int i,j=6;
for(i=1;i<j;i++)
{
if(!fork())
break;
else
j-=i;
}
printf("i=%d, j=%d\n",i,j);
}