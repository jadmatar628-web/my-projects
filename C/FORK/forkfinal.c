#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main()
{

int x = 4, y = 7, z = 1;
z = fork ();
if (!z){
        fork();
            z=y- x;
        if (fork ())
x++;
else
y--;
}
else{
z = x + y;
}
printf("%d, %d, %d\n",x,y,z);
}