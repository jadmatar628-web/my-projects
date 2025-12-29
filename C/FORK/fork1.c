#include<stdio.h>
#include<unistd.h>

int main()
{

    int i,x,y,z;
    !fork();
    z=getpid();
    if(!fork){
    x=getpid();}
    if(!fork){ 
    y=getpid();}
    printf("z=%d\n",z);
    printf("x=%d\n",x);
    printf("y=%d\n",y);
    int n[3]={x,y,z};
    int max=n[0];
 for(int i=0;i<3;i++)
 {
    if(n[i]>n[0])
    {
        max=n[i];
    }
    printf("The max is: %d found at index %d\n",max,i);
    
 }
}